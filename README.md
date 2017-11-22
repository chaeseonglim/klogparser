# klogparser
A parser for kernel log(printk) dump binary

This is a parser for kernel log dump binary.

Sometimes a noob will bring a panicked board to you without any symbols or version information and
you still have to find out some clues from it. You may try to dump around kernel's log buffer by very
heuristic ways. This will help you extract right log from that dump file.

Example:
If you dump right area including kernel log, it should be displayed like that.

[756340] tttt: offset=0, center=573000, life=573000, media=2, tty=33, bw=6000, byebyt =0
[112264f] tttt: offset=0, center=733250, life=733250, media=18, tty=33, bw=6000, byebyt =14
[116b5f6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[12f3fb4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[13212db] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2967d38] tttt: offset=0, center=289250, life=289250, media=18, tty=33, bw=6000, byebyt =14
[2ac7be8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[3415edd] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[399f23b] tttt: [AAAA_KK33222] ===== main slush (4)!! ;
[3de71d7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
