#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const unsigned int HEADER_BEGIN[] = {
    0x00000021,
    0x00000024 };
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

    map<unsigned int, string> logs;
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
			if (cur > 12 && begin + 12 < cur)
			{
				unsigned int timestamp = *((unsigned int*)&buffer[cur-12]);
				string log(buffer.begin() + begin, buffer.begin() + cur - 12 + 1);
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
        printf ("[%x] %s\n", iter.first, iter.second.c_str());

    fclose (fp);

    return 0;
}
