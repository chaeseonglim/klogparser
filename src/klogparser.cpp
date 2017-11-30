#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
 * The printk log buffer consists of a chain of concatenated variable
 * length records. Every record starts with a record header, containing
 * the overall length of the record.
 *
 * The heads to the first and last entry in the buffer, as well as the
 * sequence numbers of these entries are maintained when messages are
 * stored.
 *
 * If the heads indicate available messages, the length in the header
 * tells the start next message. A length == 0 for the next message
 * indicates a wrap-around to the beginning of the buffer.
 *
 * Every record carries the monotonic timestamp in microseconds, as well as
 * the standard userspace syslog level and syslog facility. The usual
 * kernel messages use LOG_KERN; userspace-injected messages always carry
 * a matching syslog facility, by default LOG_USER. The origin of every
 * message can be reliably determined that way.
 *
 * The human readable log message directly follows the message header. The
 * length of the message text is stored in the header, the stored message
 * is not terminated.
 *
 * Optionally, a message can carry a dictionary of properties (key/value pairs),
 * to provide userspace with a machine-readable message context.
 *
 * Examples for well-defined, commonly used property names are:
 *   DEVICE=b12:8               device identifier
 *                                b12:8         block dev_t
 *                                c127:3        char dev_t
 *                                n8            netdev ifindex
 *                                +sound:card0  subsystem:devname
 *   SUBSYSTEM=pci              driver-core subsystem name
 *
 * Valid characters in property names are [a-zA-Z0-9.-_]. The plain text value
 * follows directly after a '=' character. Every property is terminated by
 * a '\0' character. The last property is not terminated.
 *
 * Example of a message structure:
 *   0000  ff 8f 00 00 00 00 00 00      monotonic time in nsec
 *   0008  34 00                        record is 52 bytes long
 *   000a        0b 00                  text is 11 bytes long
 *   000c              1f 00            dictionary is 23 bytes long
 *   000e                    03 00      LOG_KERN (facility) LOG_ERR (level)
 *   0010  69 74 27 73 20 61 20 6c      "it's a l"
 *         69 6e 65                     "ine"
 *   001b           44 45 56 49 43      "DEVIC"
 *         45 3d 62 38 3a 32 00 44      "E=b8:2\0D"
 *         52 49 56 45 52 3d 62 75      "RIVER=bu"
 *         67                           "g"
 *   0032     00 00 00                  padding to next message header
 *
 * The 'struct printk_log' buffer header must never be directly exported to
 * userspace, it is a kernel-private implementation detail that might
 * need to be changed in the future, when the requirements change.
 *
 * /dev/kmsg exports the structured data in the following line format:
 *   "<level>,<sequnum>,<timestamp>,<contflag>[,additional_values, ... ];<message text>\n"
 *
 * Users of the export format should ignore possible additional values
 * separated by ',', and find the message after the ';' character.
 *
 * The optional key/value pairs are attached as continuation lines starting
 * with a space character and terminated by a newline. All possible
 * non-prinatable characters are escaped in the "\xff" notation.
 */

enum log_flags {
    LOG_NOCONS  = 1,    /* already flushed, do not print to console */
    LOG_NEWLINE = 2,    /* text ended with a newline */
    LOG_PREFIX  = 4,    /* text started with a prefix */
    LOG_CONT    = 8,    /* text is a fragment of a continuation line */
};

typedef unsigned long long u64;
typedef unsigned short u16;
typedef unsigned char u8;

struct printk_log {
    u64 ts_nsec;        /* timestamp in nanoseconds */
    u16 len;        /* length of entire record */
    u16 text_len;       /* length of text buffer */
    u16 dict_len;       /* length of dictionary buffer */
    u8 facility;        /* syslog facility */
    u8 flags:5;     /* internal record flags */
    u8 level:3;     /* syslog level */
} __attribute__((packed)) ;

const unsigned int HEADER_END[] = {
    0x82000000,
    0xC6000000,
    0x86000000,
    0x66000000,
    0xC2000000 };

void usage(void)
{
    puts ("a.out [filename] {start} {begin}");
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        usage ();
        return -1;
    }

    FILE* fp = fopen (argv[1], "rb");
    if (fp == NULL)
    {
        fprintf (stderr, "failed to open file! %s\n", argv[1]);
        return -1;
    }

    int start_offset = 0;
    if (argc > 2)
    {
        int len = strlen (argv[2]);
        if (len > 2 && argv[2][0] == '0' && argv[2][1] == 'x')
            start_offset = strtol (argv[2] + 2, NULL, 16);
        else
            start_offset = atoi (argv[2]);
        printf ("start: %d\n", start_offset);
    }

    fseek (fp, 0, SEEK_END);
    unsigned int fsize = ftell (fp);
    fseek (fp, start_offset, SEEK_SET);

    int bufsize = fsize - start_offset;

    vector<char> buffer(bufsize, 0);
    unordered_set<unsigned int> end_markers;

    for (int i = 0; i < sizeof(HEADER_END)/sizeof(unsigned int); ++i)
        end_markers.insert (HEADER_END[i]);

    if (fread (&buffer[0], bufsize, 1, fp) != 1)
    {
        fprintf (stderr, "failed to read file! %x\n", ferror(fp));
        return -1;
    }

    map<unsigned long long, string> logs;
    unsigned int begin = 0, cur = 0;
    int hdr_dt_cnt = 0;
    while (cur < buffer.size())
    {
        unsigned int word = *((unsigned int*)&buffer[cur]);

        /*
        if (word == HEADER_BEGIN1 || word == HEADER_BEGIN2)
        {
            hdr_dt_cnt = 1;
        }
        else
        */
        if (end_markers.count (word) && hdr_dt_cnt == 0)
        {
			int n = sizeof(printk_log) - sizeof(word);
			if (cur > n && begin + n < cur)
			{
				unsigned long long timestamp =
					*((unsigned long long*)&buffer[cur - n]);
				string log;
				log += "[";
				log += to_string(cur);
				log += "] ";
				log.insert (log.end(), buffer.begin() + begin,
					buffer.begin() + cur - n + 1);
				begin = cur + 4;
				logs[timestamp] = log;
			}

            hdr_dt_cnt = 0;
        }
        else if (hdr_dt_cnt == 1)
            hdr_dt_cnt ++;
        else if (hdr_dt_cnt > 0)
            hdr_dt_cnt = 0;

        cur += 4;
    }

    for (auto iter: logs)
        printf ("[%llx] %s\n", iter.first, iter.second.c_str());

    fclose (fp);

    return 0;
}
