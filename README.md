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
[3e567da] * BT is active, apply coex RF and PD CR settingsr?MK
[3e74b6a] O18 AVS avs info valid o18_avsinfo[ab0032]
[3f822a4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[40b0a4a] tttt: [AAAA_KK33222] ===== main slush (4)!! J
[423244f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[468bfa4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 987000]
[4a3af23] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4aeb7c9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 453000]
[4c5a86b] tttt: [AAAA_KK33222] ===== main slush (4)!! k
[4dc345b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4ddfc67] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[5654a76] tttt: offset=0, center=187250, life=187250, media=18, tty=33, bw=6000, byebyt =14
[58fa5eb] tttt: offset=0, center=607250, life=607250, media=18, tty=33, bw=6000, byebyt =14
[60865b7] tttt: offset=0, center=993000, life=993000, media=2, tty=33, bw=6000, byebyt =0
[64373f2] tttt: offset=0, center=895250, life=895250, media=18, tty=33, bw=6000, byebyt =14
[649e116] tttt: offset=0, center=459000, life=459000, media=2, tty=33, bw=6000, byebyt =0
[65fff41] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 339000]
[68eb78b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[6c96ea3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6e3db41] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[7b8feb9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 225000]
[7f41b29] tttt: offset=0, center=345000, life=345000, media=2, tty=33, bw=6000, byebyt =0
[7f49b33] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8581106] tttt: offset=0, center=451250, life=451250, media=18, tty=33, bw=6000, byebyt =14
[85de813] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 79000]
[88d1c37] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[93bc5d6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[9544f1b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[966c09e] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[968a3bc] tttt: offset=0, center=231000, life=231000, media=2, tty=33, bw=6000, byebyt =0
[9d8d7c6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 771000]
[9f421c3] tttt: offset=0, center=85000, life=85000, media=2, tty=33, bw=6000, byebyt =0
[a09d405] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[a5e4e67] tttt: [AAAA_KK33222] ===== main slush (4)!! g
[abaaa9d] tttt: offset=0, center=739250, life=739250, media=18, tty=33, bw=6000, byebyt =14
[adae7f8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[af52e46] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b1282b2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b541cb2] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 657000]
[b6fd7c7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[b719d04] tttt: offset=0, center=777000, life=777000, media=2, tty=33, bw=6000, byebyt =0
[b84a3df] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[bf00f5c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 885000]
[c3040c7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c44ba04] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 573000]
[c5a68ef] tttt: offset=0, center=295250, life=295250, media=18, tty=33, bw=6000, byebyt =14
[c75607b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c8680db] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[cd774d7] tttt: offset=0, center=485000, life=485000, media=1, tty=16, bw=6000, byebyt =0
[ceef9dd] tttt: offset=0, center=663000, life=663000, media=2, tty=33, bw=6000, byebyt =0
[d14751d] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[d942843] tttt: [AAAA_KK33222] ===== main slush (4)!! ??u
"
[da4e6c3] tttt: offset=0, center=891000, life=891000, media=2, tty=33, bw=6000, byebyt =0
[dab2bc1] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[dba32b3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[dd311f3] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[de2b4c0] tttt: offset=0, center=579000, life=579000, media=2, tty=33, bw=6000, byebyt =0
[e6229f9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e7afb69] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e900327] tttt: [AAAA_KK33222] ===== main slush (4)!! '
[f1211b7] tttt: offset=0, center=193250, life=193250, media=18, tty=33, bw=6000, byebyt =14
[f3ffddf] tttt: offset=0, center=613250, life=613250, media=18, tty=33, bw=6000, byebyt =14
[fd77075] tttt: [AAAA_KK33222] ===== main slush (4)!! ?gL>
[fe18242] tttt: offset=0, center=901250, life=901250, media=18, tty=33, bw=6000, byebyt =14
[1015c687] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1095208b] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[10b0cc73] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1100263c] tttt: [AAAA_KK33222] ===== main slush (4)!! <
[11fa6aa3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[120df256] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 459000]
[121d8e97] tttt: offset=0, center=457250, life=457250, media=18, tty=33, bw=6000, byebyt =14
[123c8a0d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[12eccbc2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1304d743] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 993000]
[13051e9e] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[133e4165] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[13aa3280] tttt: offset=0, center=465000, life=465000, media=2, tty=33, bw=6000, byebyt =0
[13b99d18] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 345000]
[13e753c9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[1470ac01] tttt: offset=0, center=745250, life=745250, media=18, tty=33, bw=6000, byebyt =14
[1495e566] tttt: [AAAA_KK33222] ===== main slush (4)!! f
[14a2239e] tttt: offset=0, center=999000, life=999000, media=2, tty=33, bw=6000, byebyt =0
[14b38268] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[152ef9cf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 231000]
[154dd1ff] tttt: offset=0, center=351000, life=351000, media=2, tty=33, bw=6000, byebyt =0
[15698c7c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[15be6184] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 85000]
[15f18c33] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[16199c74] tttt: offset=0, center=301250, life=301250, media=18, tty=33, bw=6000, byebyt =14
[16c91af2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[16d0a4fd] tttt: offset=0, center=237000, life=237000, media=2, tty=33, bw=6000, byebyt =0
[1736a23a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 777000]
[1743ee49] tttt: [AAAA_KK33222] ===== main slush (4)!! ??&"
[175d1700] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1767f8e3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1768c298] tttt: offset=0, center=177000, life=177000, media=2, tty=33, bw=6000, byebyt =0
[1769b823] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[1780a2b5] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1809db34] tttt: [AAAA_KK33222] ===== main slush (4)!! 4
[18227210] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[18725acd] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[18bd30c5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 663000]
[18c61552] tttt: offset=0, center=199250, life=199250, media=18, tty=33, bw=6000, byebyt =14
[18d17a21] tttt: offset=0, center=783000, life=783000, media=2, tty=33, bw=6000, byebyt =0
[18e4ce70] tttt: offset=0, center=619250, life=619250, media=18, tty=33, bw=6000, byebyt =14
[18ec02b4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[18f2fcf7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[198e4bbe] tttt: offset=0, center=907250, life=907250, media=18, tty=33, bw=6000, byebyt =14
[19a78f5e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 579000]
[19d8be06] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[19ee9314] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[1a5140f9] tttt: offset=0, center=669000, life=669000, media=2, tty=33, bw=6000, byebyt =0
[1a51b3df] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1a6def53] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1a8e9a90] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1aa1590a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 891000]
[1adc9e1e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[1b3ebdc5] tttt: offset=0, center=585000, life=585000, media=2, tty=33, bw=6000, byebyt =0
[1bdadacb] tttt: offset=0, center=463250, life=463250, media=18, tty=33, bw=6000, byebyt =14
[1befac01] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[1c446b1a] tttt: offset=0, center=897000, life=897000, media=2, tty=33, bw=6000, byebyt =0
[1c94bf79] tttt: [AAAA_KK33222] ===== main slush (4)!! y
[1cac7aae] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1d7633c8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1e11dcbd] tttt: offset=0, center=751250, life=751250, media=18, tty=33, bw=6000, byebyt =14
[1e25b3bd] tttt: [LGDT3307] [NORMAL] [VBYBY] Start AAAJob [COST : 485000]
[1e44d015] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[1e5c9de4] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[1e5f8561] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[1f71168c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 465000]
[1fa2bf4c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[1fd256f3] tttt: offset=0, center=307250, life=307250, media=18, tty=33, bw=6000, byebyt =14
[209a3bcc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[20f7b04b] tttt: [AAAA_KK33222] ===== main slush (4)!! K
[210d684f] tttt: [AAAA_KK33222] ===== main slush (4)!! O
[210e49fb] tttt: offset=0, center=471000, life=471000, media=2, tty=33, bw=6000, byebyt =0
[211240ef] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[211ba00b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 351000]
[2126610b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[214bbb53] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[219b5389] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 999000]
[21b9054a] tttt: [AAAA_KK33222] ===== main slush (4)!! J
[21d181fe] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[227e5dc5] tttt: offset=0, center=205250, life=205250, media=18, tty=33, bw=6000, byebyt =14
[22974391] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 237000]
[22998a3b] tttt: offset=0, center=625250, life=625250, media=18, tty=33, bw=6000, byebyt =14
[22b06d03] tttt: offset=0, center=357000, life=357000, media=2, tty=33, bw=6000, byebyt =0
[22d1aea6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[22f9a9f3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[231f5a93] * BT is inactive, restore coex RF and PD CR settings?
[2335c3bd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 177000]
[233e6b3c] tttt: offset=0, center=913250, life=913250, media=18, tty=33, bw=6000, byebyt =14
[2366d394] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[23fcbc6a] tttt: [AAAA_KK33222] ===== main slush (4)!! j
[24196c06] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[24366b9e] tttt: offset=0, center=243000, life=243000, media=2, tty=33, bw=6000, byebyt =0
[2497341d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 783000]
[24c9342a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[24d696e4] tttt: offset=0, center=183000, life=183000, media=2, tty=33, bw=6000, byebyt =0
[25851bd2] tttt: offset=0, center=469250, life=469250, media=18, tty=33, bw=6000, byebyt =14
[25cfd325] tttt: [AAAA_KK33222] ===== main slush (4)!! %
[261e7907] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 669000]
[262e44f1] tttt: offset=0, center=789000, life=789000, media=2, tty=33, bw=6000, byebyt =0
[263116ed] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2649cb2a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[26515e20] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[270577a7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 585000]
[2736fbd0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[2755011a] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[278a828b] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[27b5ade6] tttt: offset=0, center=757250, life=757250, media=18, tty=33, bw=6000, byebyt =14
[27bc1dc9] tttt: offset=0, center=675000, life=675000, media=2, tty=33, bw=6000, byebyt =0
[27f553a8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[280bdf4c] tttt: [AAAA_KK33222] ===== main slush (4)!! L
[28259360] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[28a3a3ed] tttt: offset=0, center=591000, life=591000, media=2, tty=33, bw=6000, byebyt =0
[29410f04] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 897000]
[294c1e83] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[297d05c5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[298cfeb4] tttt: offset=0, center=313250, life=313250, media=18, tty=33, bw=6000, byebyt =14
[2ab35ae7] tttt: [AAAA_KK33222] ===== main slush (4)!! ]'"
[2ac4b7c8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2acc0f38] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[2adab69a] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2add8278] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[2ae08194] tttt: offset=0, center=903000, life=903000, media=2, tty=33, bw=6000, byebyt =0
[2b6670f6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2b7f7782] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[2ba00c75] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 471000]
[2bc7f8fc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2bcf1307] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[2c324f34] tttt: offset=0, center=211250, life=211250, media=18, tty=33, bw=6000, byebyt =14
[2c49ec2b] tttt: offset=0, center=631250, life=631250, media=18, tty=33, bw=6000, byebyt =14
[2ce5a6f6] tttt: offset=0, center=919250, life=919250, media=18, tty=33, bw=6000, byebyt =14
[2d4259d8] tttt: offset=0, center=477000, life=477000, media=2, tty=33, bw=6000, byebyt =0
[2df8094a] tttt: [AAAA_KK33222] ===== main slush (4)!! J
[2e139c74] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[2e784eb4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 357000]
[2ea652fd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[2f26db9a] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[2f308928] tttt: [AAAA_KK33222] ===== main slush (4)!! (
[2f8029eb] tttt: offset=0, center=475250, life=475250, media=18, tty=33, bw=6000, byebyt =14
[2fdf4f5c] tttt: [AAAA_KK33222] ===== main slush (4)!! \
[2ff7aab4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[2ffd2055] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 243000]
[30142f21] tttt: offset=0, center=363000, life=363000, media=2, tty=33, bw=6000, byebyt =0
[3035a9ea] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[309d003e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 183000]
[30cc854b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3163ed83] tttt: offset=0, center=763250, life=763250, media=18, tty=33, bw=6000, byebyt =14
[31861635] tttt: [AAAA_KK33222] ===== main slush (4)!! 5
[31a34798] tttt: offset=0, center=249000, life=249000, media=2, tty=33, bw=6000, byebyt =0
[31a834fa] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[31c3b419] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[31f2ef30] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 789000]
[32269fce] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3245c05b] tttt: offset=0, center=189000, life=189000, media=2, tty=33, bw=6000, byebyt =0
[332fadda] tttt: offset=0, center=319250, life=319250, media=18, tty=33, bw=6000, byebyt =14
[333254bb] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[33810489] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 675000]
[338e31dc] tttt: offset=0, center=795000, life=795000, media=2, tty=33, bw=6000, byebyt =0
[33b156d7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[346e60a4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 591000]
[346fc55f] tttt: [AAAA_KK33222] ===== main slush (4)!! _
[347915ec] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[348a59a0] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[34932258] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[349f88ce] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[34c27166] tttt: [AAAA_KK33222] ===== main slush (4)!! f
[3512c3ef] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[3525f13f] tttt: offset=0, center=681000, life=681000, media=2, tty=33, bw=6000, byebyt =0
[352b4bd3] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[35644269] tttt: [AAAA_KK33222] ===== main slush (4)!! i
[35f11992] tttt: offset=0, center=121250, life=121250, media=18, tty=33, bw=6000, byebyt =14
[35f973a1] tttt: offset=0, center=637250, life=637250, media=18, tty=33, bw=6000, byebyt =14
[360d220b] tttt: offset=0, center=597000, life=597000, media=2, tty=33, bw=6000, byebyt =0
[36981a23] tttt: offset=0, center=925250, life=925250, media=18, tty=33, bw=6000, byebyt =14
[36aa009b] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[37cdcf19] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 477000]
[37d711dc] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 903000]
[37e09b34] tttt: [AAAA_KK33222] ===== main slush (4)!! 4
[37fac330] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[37fc6869] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[38130b6a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[384e5fff] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[3931b47f] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[3961c8f8] tttt: offset=0, center=481250, life=481250, media=18, tty=33, bw=6000, byebyt =14
[3963644f] tttt: offset=0, center=483000, life=483000, media=2, tty=33, bw=6000, byebyt =0
[3980a9b4] tttt: offset=0, center=909000, life=909000, media=2, tty=33, bw=6000, byebyt =0
[398a3017] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[39a35ce3] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[3b114229] tttt: offset=0, center=769250, life=769250, media=18, tty=33, bw=6000, byebyt =14
[3b4fabc5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[3b610763] tttt: [AAAA_KK33222] ===== main slush (4)!! c
[3b6318dc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[3b7b8b25] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[3bd9c09c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 363000]
[3c0683df] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3ce2a734] tttt: offset=0, center=325250, life=325250, media=18, tty=33, bw=6000, byebyt =14
[3d698db1] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 249000]
[3d747c7f] tttt: offset=0, center=369000, life=369000, media=2, tty=33, bw=6000, byebyt =0
[3da4b32a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3dd8266e] tttt: [AAAA_KK33222] ===== main slush (4)!! n
[3e0b2753] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 189000]
[3e1dda50] tttt: [AAAA_KK33222] ===== main slush (4)!! P
[3e2f5e2d] tttt: [AAAA_KK33222] ===== main slush (4)!! -
[3e367e3d] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[3e3c6bef] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3e49bb96] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[3ecaf81a] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[3ee42639] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[3f0ad87a] tttt: offset=0, center=255000, life=255000, media=2, tty=33, bw=6000, byebyt =0
[3f50c036] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 795000]
[3f832897] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[3fa3ede9] tttt: offset=0, center=195000, life=195000, media=2, tty=33, bw=6000, byebyt =0
[3fa9f6e9] tttt: offset=0, center=643250, life=643250, media=18, tty=33, bw=6000, byebyt =14
[3fb2f821] tttt: offset=0, center=127250, life=127250, media=18, tty=33, bw=6000, byebyt =14
[4050975c] tttt: offset=0, center=931250, life=931250, media=18, tty=33, bw=6000, byebyt =14
[409252c6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[40f36fde] tttt: offset=0, center=801000, life=801000, media=2, tty=33, bw=6000, byebyt =0
[40f85fef] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 681000]
[41395cac] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[41b5751e] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[41d09544] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[41d8df08] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 597000]
[420a275f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4228f51b] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[42a92975] tttt: offset=0, center=687000, life=687000, media=2, tty=33, bw=6000, byebyt =0
[42c32e48] tttt: [AAAA_KK33222] ===== main slush (4)!! H
[4336dc32] tttt: offset=0, center=487250, life=487250, media=18, tty=33, bw=6000, byebyt =14
[4340efe6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[4358bc03] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[4371685c] tttt: offset=0, center=603000, life=603000, media=2, tty=33, bw=6000, byebyt =0
[43f66243] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 483000]
[44119c6b] tttt: [AAAA_KK33222] ===== main slush (4)!! k
[4427a8cf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[44bf1fe2] tttt: offset=0, center=775250, life=775250, media=18, tty=33, bw=6000, byebyt =14
[450d518a] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[4527a8cb] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[45428906] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[458e7da0] tttt: offset=0, center=489000, life=489000, media=2, tty=33, bw=6000, byebyt =0
[45cbd61d] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[467e8056] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 909000]
[468e1733] tttt: offset=0, center=331250, life=331250, media=18, tty=33, bw=6000, byebyt =14
[4696bf44] tttt: [AAAA_KK33222] ===== main slush (4)!! D
[46bb2dae] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[477a6e15] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[47caf8d4] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[47e4b66a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[47f50628] tttt: [AAAA_KK33222] ===== main slush (4)!! (
[4810f6b8] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[48224a17] tttt: offset=0, center=915000, life=915000, media=2, tty=33, bw=6000, byebyt =0
[48752013] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[488db9c2] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[49394750] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 369000]
[4951f565] tttt: offset=0, center=91250, life=91250, media=18, tty=33, bw=6000, byebyt =14
[49679dbf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[497f2f4e] tttt: offset=0, center=133250, life=133250, media=18, tty=33, bw=6000, byebyt =14
[49f4ae47] tttt: offset=0, center=937250, life=937250, media=18, tty=33, bw=6000, byebyt =14
[4acea549] tttt: offset=0, center=375000, life=375000, media=2, tty=33, bw=6000, byebyt =0
[4ad04e42] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 255000]
[4b0b98b9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4b6968ec] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 195000]
[4b93b3f6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4b95996c] tttt: [AAAA_KK33222] ===== main slush (4)!! l
[4bc4646e] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[4c71a57a] tttt: [AAAA_KK33222] ===== main slush (4)!! z
[4c72abbf] tttt: offset=0, center=261000, life=261000, media=2, tty=33, bw=6000, byebyt =0
[4cb86d72] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 801000]
[4ce49ef8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[4ce6797b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4cf940cb] tttt: offset=0, center=201000, life=201000, media=2, tty=33, bw=6000, byebyt =0
[4cfd1add] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[4d305fec] tttt: offset=0, center=493250, life=493250, media=18, tty=33, bw=6000, byebyt =14
[4deca3f2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[4e50bc00] tttt: offset=0, center=807000, life=807000, media=2, tty=33, bw=6000, byebyt =0
[4e70c63d] tttt: offset=0, center=781250, life=781250, media=18, tty=33, bw=6000, byebyt =14
[4e749944] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 687000]
[4ea2d6f6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4eb58fac] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[4ecee434] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[4f3ebead] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 603000]
[4f6e5903] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[4f908879] tttt: [AAAA_KK33222] ===== main slush (4)!! y
[500e438f] tttt: offset=0, center=693000, life=693000, media=2, tty=33, bw=6000, byebyt =0
[50171c92] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[5020596e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 489000]
[503b94b0] tttt: offset=0, center=337250, life=337250, media=18, tty=33, bw=6000, byebyt =14
[5052a72c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[50d2e6b1] tttt: offset=0, center=609000, life=609000, media=2, tty=33, bw=6000, byebyt =0
[516e5a9b] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[51826c02] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[519b6008] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[51b9d299] tttt: offset=0, center=495000, life=495000, media=2, tty=33, bw=6000, byebyt =0
[51c2803f] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[51dd2ac1] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[521358ec] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[522be0e4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[530020ac] tttt: offset=0, center=97250, life=97250, media=18, tty=33, bw=6000, byebyt =14
[532fbaf8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[534b3385] tttt: offset=0, center=139250, life=139250, media=18, tty=33, bw=6000, byebyt =14
[53924bdd] tttt: offset=0, center=943250, life=943250, media=18, tty=33, bw=6000, byebyt =14
[53f76e83] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[54de5b67] tttt: [AAAA_KK33222] ===== main slush (4)!! g
[5518b566] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 915000]
[5553cc7d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[5589ca9e] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[55b90b53] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[5692fc28] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 375000]
[569f40a5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[56b69f0c] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[56b9e307] tttt: offset=0, center=921000, life=921000, media=2, tty=33, bw=6000, byebyt =0
[56c1b269] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[571fedad] tttt: offset=0, center=499250, life=499250, media=18, tty=33, bw=6000, byebyt =14
[5823aaac] tttt: offset=0, center=787250, life=787250, media=18, tty=33, bw=6000, byebyt =14
[5828ccdf] tttt: offset=0, center=381000, life=381000, media=2, tty=33, bw=6000, byebyt =0
[58395855] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 261000]
[58659008] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[5873d6a0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[587fe8b9] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[58be1993] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 201000]
[595624fd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[59e4bb3d] tttt: offset=0, center=267000, life=267000, media=2, tty=33, bw=6000, byebyt =0
[59ed7fee] tttt: offset=0, center=343250, life=343250, media=18, tty=33, bw=6000, byebyt =14
[5a14e5a8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 807000]
[5a446c5d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[5ac32df4] tttt: offset=0, center=207000, life=207000, media=2, tty=33, bw=6000, byebyt =0
[5b08e07c] tttt: [AAAA_KK33222] ===== main slush (4)!! |
[5b23e253] tttt: [AAAA_KK33222] ===== main slush (4)!! S
[5b3e84a5] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[5b46a7d2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[5b77de17] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[5b916138] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[5bab0c2b] tttt: offset=0, center=813000, life=813000, media=2, tty=33, bw=6000, byebyt =0
[5bb73cf1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[5bcf2a84] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[5bd78084] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 693000]
[5c0c8f3c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[5c9d8732] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 609000]
[5ca62de1] tttt: offset=0, center=103250, life=103250, media=18, tty=33, bw=6000, byebyt =14
[5ccf488d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[5cff207f] tttt: offset=0, center=145250, life=145250, media=18, tty=33, bw=6000, byebyt =14
[5d094caf] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[5d357d57] tttt: offset=0, center=949250, life=949250, media=18, tty=33, bw=6000, byebyt =14
[5d734fcb] tttt: offset=0, center=699000, life=699000, media=2, tty=33, bw=6000, byebyt =0
[5d84aec8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 495000]
[5db3f771] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[5debbf78] tttt: [AAAA_KK33222] ===== main slush (4)!! x
[5e3c0b9e] tttt: offset=0, center=615000, life=615000, media=2, tty=33, bw=6000, byebyt =0
[5eca4fa9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[5f198e0e] tttt: offset=0, center=501000, life=501000, media=2, tty=33, bw=6000, byebyt =0
[5f6c7d60] tttt: [AAAA_KK33222] ===== main slush (4)!! `
[5f918891] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[60570074] tttt: [AAAA_KK33222] ===== main slush (4)!! t
[606f6447] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6092260c] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[60fd7db4] tttt: offset=0, center=505250, life=505250, media=18, tty=33, bw=6000, byebyt =14
[6159c221] tttt: [AAAA_KK33222] ===== main slush (4)!! !
[61d58e02] tttt: offset=0, center=793250, life=793250, media=18, tty=33, bw=6000, byebyt =14
[62186773] tttt: [AAAA_KK33222] ===== main slush (4)!! s
[6232f4a8] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[623f19c2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[63a06850] tttt: offset=0, center=349250, life=349250, media=18, tty=33, bw=6000, byebyt =14
[63b19228] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 921000]
[63ee5f5c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 381000]
[63ef4cbc] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[641cbe04] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[64d29c89] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[64ee08e5] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[652e6cef] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[65475292] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[655635ef] tttt: offset=0, center=927000, life=927000, media=2, tty=33, bw=6000, byebyt =0
[655968fa] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6571dd56] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[65845b6f] tttt: offset=0, center=387000, life=387000, media=2, tty=33, bw=6000, byebyt =0
[65b25460] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 267000]
[65ec7dc7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[665ae222] tttt: offset=0, center=109250, life=109250, media=18, tty=33, bw=6000, byebyt =14
[66936b7c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 207000]
[66ae008b] tttt: offset=0, center=151250, life=151250, media=18, tty=33, bw=6000, byebyt =14
[66c47483] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[66d540d7] tttt: offset=0, center=955250, life=955250, media=18, tty=33, bw=6000, byebyt =14
[675a413d] tttt: offset=0, center=273000, life=273000, media=2, tty=33, bw=6000, byebyt =0
[67716da1] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 813000]
[67a1e99f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[6829f3fd] tttt: offset=0, center=213000, life=213000, media=2, tty=33, bw=6000, byebyt =0
[68a262c1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6908e55c] tttt: offset=0, center=819000, life=819000, media=2, tty=33, bw=6000, byebyt =0
[693b09df] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 699000]
[693bf950] tttt: [AAAA_KK33222] ===== main slush (4)!! P
[69614d35] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[696990b3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[69a55271] tttt: [AAAA_KK33222] ===== main slush (4)!! q
[69fa3d55] tttt: [AAAA_KK33222] ===== main slush (4)!! U
[6a00a7d5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 615000]
[6a13d860] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6a333aaf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[6a784d6e] tttt: [AAAA_KK33222] ===== main slush (4)!! n
[6acc26a1] tttt: offset=0, center=511250, life=511250, media=18, tty=33, bw=6000, byebyt =14
[6ad05ecf] tttt: offset=0, center=705000, life=705000, media=2, tty=33, bw=6000, byebyt =0
[6ae54d64] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 501000]
[6b1597e7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[6b4e8a53] tttt: [AAAA_KK33222] ===== main slush (4)!! S
[6b790c9b] tttt: offset=0, center=799250, life=799250, media=18, tty=33, bw=6000, byebyt =14
[6b99fd27] tttt: offset=0, center=621000, life=621000, media=2, tty=33, bw=6000, byebyt =0
[6bd0ea9c] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6bed395f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6c274cbe] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6c7bbb1b] tttt: offset=0, center=507000, life=507000, media=2, tty=33, bw=6000, byebyt =0
[6d5a5ce4] tttt: offset=0, center=355250, life=355250, media=18, tty=33, bw=6000, byebyt =14
[6df04aff] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6e7f279e] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6e985a6f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6ebef443] tttt: [AAAA_KK33222] ===== main slush (4)!! C
[6edb3bb4] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6ef3e00a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6efd91e9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[6f17e445] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[6fa108a4] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[700538c8] tttt: offset=0, center=115250, life=115250, media=18, tty=33, bw=6000, byebyt =14
[7060e82d] tttt: offset=0, center=157250, life=157250, media=18, tty=33, bw=6000, byebyt =14
[707def3a] tttt: offset=0, center=961250, life=961250, media=18, tty=33, bw=6000, byebyt =14
[714910a6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 387000]
[71783931] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[724cf861] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 927000]
[72880827] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[72e63360] tttt: offset=0, center=393000, life=393000, media=2, tty=33, bw=6000, byebyt =0
[72fa9a77] tttt: [AAAA_KK33222] ===== main slush (4)!! w
[73156ada] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[731fc4ee] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 273000]
[7359a2f3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[73a1aff7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[73ba67c6] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[73eea03a] tttt: offset=0, center=933000, life=933000, media=2, tty=33, bw=6000, byebyt =0
[73f54d12] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 213000]
[742de8dd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[747ba3a3] tttt: offset=0, center=517250, life=517250, media=18, tty=33, bw=6000, byebyt =14
[74c773b4] tttt: offset=0, center=279000, life=279000, media=2, tty=33, bw=6000, byebyt =0
[74cd746b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 819000]
[74f9dc42] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[752634c4] tttt: offset=0, center=805250, life=805250, media=18, tty=33, bw=6000, byebyt =14
[75899580] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[759ab746] tttt: offset=0, center=123000, life=123000, media=2, tty=33, bw=6000, byebyt =0
[75a22202] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[760c3ad5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[76609602] tttt: offset=0, center=825000, life=825000, media=2, tty=33, bw=6000, byebyt =0
[769a9859] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 705000]
[76cbd90d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[770f1614] tttt: offset=0, center=361250, life=361250, media=18, tty=33, bw=6000, byebyt =14
[7767177a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 621000]
[77989aaa] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[77e646f0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[782da916] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[78306c05] tttt: offset=0, center=711000, life=711000, media=2, tty=33, bw=6000, byebyt =0
[783e0ede] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[78469965] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[78485812] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 507000]
[788ac0fb] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[789dfe1c] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[78b269d1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[78b6d10b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[78b97dce] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[78cf7636] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[78ffb36d] tttt: offset=0, center=627000, life=627000, media=2, tty=33, bw=6000, byebyt =0
[797ea119] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[79ae61ec] tttt: offset=0, center=649250, life=649250, media=18, tty=33, bw=6000, byebyt =14
[79fafecf] tttt: offset=0, center=513000, life=513000, media=2, tty=33, bw=6000, byebyt =0
[7a22c344] tttt: offset=0, center=163250, life=163250, media=18, tty=33, bw=6000, byebyt =14
[7a35a18f] tttt: offset=0, center=967250, life=967250, media=18, tty=33, bw=6000, byebyt =14
[7b4ea30b] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[7c1dd0ab] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[7ca8869c] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[7cc1ab48] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[7d1ca707] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[7d5eaeb7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[7d778c9e] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[7e27b1f4] tttt: offset=0, center=523250, life=523250, media=18, tty=33, bw=6000, byebyt =14
[7eb3fc37] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 393000]
[7ede5f07] tttt: offset=0, center=811250, life=811250, media=18, tty=33, bw=6000, byebyt =14
[7ee4e286] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[7f3bea83] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[7f569dae] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[8051cc4c] tttt: offset=0, center=399000, life=399000, media=2, tty=33, bw=6000, byebyt =0
[808d8926] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 279000]
[80bd0432] tttt: offset=0, center=367250, life=367250, media=18, tty=33, bw=6000, byebyt =14
[80c0133e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[80e4a0aa] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 933000]
[81237695] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8161b81a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 123000]
[819cc830] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[81d25abc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[81ec1470] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[82254ee9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 825000]
[82297416] tttt: offset=0, center=285000, life=285000, media=2, tty=33, bw=6000, byebyt =0
[8253f253] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8271c811] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[8276f79e] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[828a79cc] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[828fc24b] tttt: offset=0, center=939000, life=939000, media=2, tty=33, bw=6000, byebyt =0
[8290a1ee] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[830bd7d1] tttt: offset=0, center=129000, life=129000, media=2, tty=33, bw=6000, byebyt =0
[8359388c] tttt: offset=0, center=655250, life=655250, media=18, tty=33, bw=6000, byebyt =14
[83765f2f] tttt: [AAAA_KK33222] ===== main slush (4)!! /
[83c16f64] tttt: offset=0, center=831000, life=831000, media=2, tty=33, bw=6000, byebyt =0
[83f58b09] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 711000]
[83f6cafe] tttt: offset=0, center=169250, life=169250, media=18, tty=33, bw=6000, byebyt =14
[83f86ab1] tttt: offset=0, center=973250, life=973250, media=18, tty=33, bw=6000, byebyt =14
[84267296] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[84c47203] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 627000]
[84f54ed4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[854e7d39] tttt: [AAAA_KK33222] ===== main slush (4)!! 9
[858d6546] tttt: offset=0, center=717000, life=717000, media=2, tty=33, bw=6000, byebyt =0
[85c34b09] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 513000]
[860354f0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[863091f1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[865820da] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[865da312] tttt: offset=0, center=633000, life=633000, media=2, tty=33, bw=6000, byebyt =0
[86733dd3] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[86e0cd93] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[86e204f3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[8712a6ff] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[872be25b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[876c4f87] tttt: offset=0, center=519000, life=519000, media=2, tty=33, bw=6000, byebyt =0
[87e00163] tttt: offset=0, center=529250, life=529250, media=18, tty=33, bw=6000, byebyt =14
[88906309] tttt: offset=0, center=817250, life=817250, media=18, tty=33, bw=6000, byebyt =14
[88b2b7dc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[88e22588] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[88fb94c7] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[897be852] tttt: [AAAA_KK33222] ===== main slush (4)!! R
[8a623a53] tttt: offset=0, center=373250, life=373250, media=18, tty=33, bw=6000, byebyt =14
[8a8e91ab] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[8b8d8272] tttt: [AAAA_KK33222] ===== main slush (4)!! r
[8ba6a493] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[8c17bf05] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[8c1e355b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 399000]
[8c21bb3f] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[8c30437f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[8c3c5a78] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[8c4c65bc] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8d126666] tttt: offset=0, center=661250, life=661250, media=18, tty=33, bw=6000, byebyt =14
[8d95e93e] tttt: offset=0, center=979250, life=979250, media=18, tty=33, bw=6000, byebyt =14
[8da1df82] tttt: offset=0, center=217250, life=217250, media=18, tty=33, bw=6000, byebyt =14
[8db14199] tttt: offset=0, center=405000, life=405000, media=2, tty=33, bw=6000, byebyt =0
[8df61bf6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 285000]
[8e243966] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8ed772f3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 129000]
[8f1342f0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8f879cb5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 939000]
[8f890f54] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 831000]
[8f8bde78] tttt: offset=0, center=291000, life=291000, media=2, tty=33, bw=6000, byebyt =0
[8fba7160] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[8fc13055] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[90208952] tttt: [AAAA_KK33222] ===== main slush (4)!! R
[9038ce91] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[90803cc0] tttt: offset=0, center=135000, life=135000, media=2, tty=33, bw=6000, byebyt =0
[90cb60cd] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[90d619f8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[90e3b916] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9127c1ea] tttt: offset=0, center=837000, life=837000, media=2, tty=33, bw=6000, byebyt =0
[91281d00] tttt: offset=0, center=945000, life=945000, media=2, tty=33, bw=6000, byebyt =0
[915c1006] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 717000]
[918faa09] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[919de65e] ,??2
[922353b9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 633000]
[924f5f18] tttt: offset=0, center=823250, life=823250, media=18, tty=33, bw=6000, byebyt =14
[9253ad18] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9287cd05] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[92a2c787] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[92aa6ba1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[92f6c991] tttt: offset=0, center=723000, life=723000, media=2, tty=33, bw=6000, byebyt =0
[933617ce] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 519000]
[9371bf40] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[939fe605] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[93c7719a] tttt: offset=0, center=639000, life=639000, media=2, tty=33, bw=6000, byebyt =0
[940fb1c1] tttt: offset=0, center=379250, life=379250, media=18, tty=33, bw=6000, byebyt =14
[944f8a79] tttt: [AAAA_KK33222] ===== main slush (4)!! y
[94dcbaab] tttt: offset=0, center=525000, life=525000, media=2, tty=33, bw=6000, byebyt =0
[95377e9f] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[95528a5f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[95781fec] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[95bb9a20] tttt: [AAAA_KK33222] ===== main slush (4)!!
[95d4368d] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[95f453e8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[960fc616] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9615f58f] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[96be8b03] tttt: offset=0, center=667250, life=667250, media=18, tty=33, bw=6000, byebyt =14
[96e5b6d9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[973a0bd3] tttt: offset=0, center=985250, life=985250, media=18, tty=33, bw=6000, byebyt =14
[977c3489] tttt: offset=0, center=223250, life=223250, media=18, tty=33, bw=6000, byebyt =14
[98025a2d] tttt: [AAAA_KK33222] ===== main slush (4)!! -
[997ca127] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 405000]
[99ac61dc] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[99c960be] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[99e38716] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9a6ebf2f] tttt: [AAAA_KK33222] ===== main slush (4)!! /
[9a87fa3f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9b17894b] tttt: offset=0, center=411000, life=411000, media=2, tty=33, bw=6000, byebyt =0
[9b4abbb0] tttt: offset=0, center=541250, life=541250, media=18, tty=33, bw=6000, byebyt =14
[9b530d85] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 291000]
[9b83240c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9bee6c2f] tttt: offset=0, center=829250, life=829250, media=18, tty=33, bw=6000, byebyt =14
[9c39de76] tttt: [AAAA_KK33222] ===== main slush (4)!! v
[9c461ad7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 135000]
[9c53c7c9] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9c813921] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9cebc8a5] tttt: offset=0, center=297000, life=297000, media=2, tty=33, bw=6000, byebyt =0
[9cf685cc] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 837000]
[9d27d833] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9dc1259f] tttt: offset=0, center=385250, life=385250, media=18, tty=33, bw=6000, byebyt =14
[9de82733] tttt: offset=0, center=141000, life=141000, media=2, tty=33, bw=6000, byebyt =0
[9e1f5cd3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 945000]
[9e365d6a] tttt: [AAAA_KK33222] ===== main slush (4)!! j
[9e5d4480] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9e9dfe75] tttt: offset=0, center=843000, life=843000, media=2, tty=33, bw=6000, byebyt =0
[9ebd1133] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 723000]
[9ee74634] tttt: [AAAA_KK33222] ===== main slush (4)!! 4
[9ef14a80] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9effcd76] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9f6924c5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[9f8234bf] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[9f8c75ed] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 639000]
[9fb3664c] tttt: [AAAA_KK33222] ===== main slush (4)!! L
[9fbd64a8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[9fcb0482] tttt: offset=0, center=951000, life=951000, media=2, tty=33, bw=6000, byebyt =0
[9fcc177b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a0108822] tttt: [AAAA_KK33222] ===== main slush (4)!! "
[a0574118] tttt: offset=0, center=729000, life=729000, media=2, tty=33, bw=6000, byebyt =0
[a06c981f] tttt: offset=0, center=673250, life=673250, media=18, tty=33, bw=6000, byebyt =14
[a0a9e211] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 525000]
[a0e63761] tttt: offset=0, center=991250, life=991250, media=18, tty=33, bw=6000, byebyt =14
[a0f05415] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[a105901a] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[a12aaa49] tttt: offset=0, center=645000, life=645000, media=2, tty=33, bw=6000, byebyt =0
[a134e6d9] tttt: offset=0, center=229250, life=229250, media=18, tty=33, bw=6000, byebyt =14
[a1bb7c5a] tttt: [AAAA_KK33222] ===== main slush (4)!! Z
[a256e96e] tttt: offset=0, center=531000, life=531000, media=2, tty=33, bw=6000, byebyt =0
[a378ab68] tttt: [AAAA_KK33222] ===== main slush (4)!! h
[a37c3c1f] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[a396ca94] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a411dfda] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a4183aab] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a42b312b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a4497e73] tttt: [AAAA_KK33222] ===== main slush (4)!! s
[a4fcb113] tttt: offset=0, center=547250, life=547250, media=18, tty=33, bw=6000, byebyt =14
[a57db55e] tttt: [AAAA_KK33222] ===== main slush (4)!! ^
[a5a148e8] tttt: offset=0, center=835250, life=835250, media=18, tty=33, bw=6000, byebyt =14
[a5e7aca8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a6026e80] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a6dcdd33] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 411000]
[a70c7023] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[a76867b8] tttt: offset=0, center=391250, life=391250, media=18, tty=33, bw=6000, byebyt =14
[a87aa389] tttt: offset=0, center=417000, life=417000, media=2, tty=33, bw=6000, byebyt =0
[a88fdbb1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a8a8d4a5] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a8b85e4a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 297000]
[a8e75bdd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[a90c57ce] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a924fc06] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a96160a0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[a97c7e3b] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[a9af5793] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 141000]
[a9e93925] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[aa152cb4] tttt: offset=0, center=679250, life=679250, media=18, tty=33, bw=6000, byebyt =14
[aa507347] tttt: offset=0, center=303000, life=303000, media=2, tty=33, bw=6000, byebyt =0
[aa614633] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 843000]
[aa942f02] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[aa972ad1] tttt: offset=0, center=997250, life=997250, media=18, tty=33, bw=6000, byebyt =14
[aae1db56] tttt: offset=0, center=235250, life=235250, media=18, tty=33, bw=6000, byebyt =14
[ab4f905a] tttt: offset=0, center=147000, life=147000, media=2, tty=33, bw=6000, byebyt =0
[ab9f2920] tttt: [AAAA_KK33222] ===== main slush (4)!!
[abed2e1b] tttt: [LGDT3307] [NORMAL] [VBYBY] End AAAJob [SYSTEM : LOCL] [GREEN : 2]
[ac01b92d] tttt: offset=0, center=849000, life=849000, media=2, tty=33, bw=6000, byebyt =0
[ac244022] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 729000]
[ac56d679] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[acbfaf30] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 951000]
[acefa9a4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 645000]
[acfbf24b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ad1e10e7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ad34fe28] tttt: [AAAA_KK33222] ===== main slush (4)!! (
[ad4d55f8] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ad6f2a34] tttt: [AAAA_KK33222] ===== main slush (4)!! 4
[adbb04e8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[adbde721] tttt: offset=0, center=735000, life=735000, media=2, tty=33, bw=6000, byebyt =0
[add39307] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ae2666dd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 531000]
[ae62f25a] tttt: offset=0, center=957000, life=957000, media=2, tty=33, bw=6000, byebyt =0
[ae641ddf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ae6dce9d] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ae90647c] tttt: offset=0, center=93000, life=93000, media=2, tty=33, bw=6000, byebyt =0
[aeb3afe0] tttt: offset=0, center=553250, life=553250, media=18, tty=33, bw=6000, byebyt =14
[af2777d1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[af416bcb] tttt: offset=0, center=841250, life=841250, media=18, tty=33, bw=6000, byebyt =14
[af8e8a42] tttt: [AAAA_KK33222] ===== main slush (4)!! B
[afa83008] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[afcb6374] tttt: offset=0, center=537000, life=537000, media=2, tty=33, bw=6000, byebyt =0
[b0e29173] tttt: [AAAA_KK33222] ===== main slush (4)!! s
[b113e375] tttt: offset=0, center=397250, life=397250, media=18, tty=33, bw=6000, byebyt =14
[b1b519db] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b2479db0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b260ef20] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b2b2c348] tttt: [AAAA_KK33222] ===== main slush (4)!! H
[b2b76f15] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[b2f094d7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b3077ef1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b3201d24] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b3c6f71f] tttt: offset=0, center=685250, life=685250, media=18, tty=33, bw=6000, byebyt =14
[b446ef4d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 417000]
[b477d6da] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[b484246a] tttt: offset=0, center=241250, life=241250, media=18, tty=33, bw=6000, byebyt =14
[b53bb62f] O18 AVS cpu_sidd[161:191|221][50mA:NORMAL] core_sidd[103:130:160][171mA:FFAST] cpu[1.00]V[GPIO 9[1] 10[0]] core[0.85]V[regul] chip[22b0]
[b5e64653] tttt: offset=0, center=423000, life=423000, media=2, tty=33, bw=6000, byebyt =0
[b615debf] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 303000]
[b647ca42] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[b6a3bbc4] tttt: offset=0, center=73250, life=73250, media=18, tty=33, bw=6000, byebyt =14
[b6e1ecc0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b6fa7e08] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b7150844] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 147000]
[b74f2a30] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[b76c81a7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[b785bb2d] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b7af36ab] tttt: offset=0, center=309000, life=309000, media=2, tty=33, bw=6000, byebyt =0
[b7cdddb3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 849000]
[b801c41e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[b8606044] tttt: offset=0, center=559250, life=559250, media=18, tty=33, bw=6000, byebyt =14
[b8bcea04] tttt: offset=0, center=153000, life=153000, media=2, tty=33, bw=6000, byebyt =0
[b8f1612a] tttt: offset=0, center=847250, life=847250, media=18, tty=33, bw=6000, byebyt =14
[b9052823] tttt: [AAAA_KK33222] ===== main slush (4)!! #
[b9350500] tttt: [AAAA_KK33222] ===== main slush (4)!!
[b9505019] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[b975b22d] tttt: offset=0, center=855000, life=855000, media=2, tty=33, bw=6000, byebyt =0
[b98a8317] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 735000]
[b9bba481] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ba5cd6e1] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 93000]
[ba8ee020] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[bab6d0c5] tttt: offset=0, center=403250, life=403250, media=18, tty=33, bw=6000, byebyt =14
[bacd96de] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[bb29171d] tttt: offset=0, center=741000, life=741000, media=2, tty=33, bw=6000, byebyt =0
[bb58b561] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 957000]
[bb909a12] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[bb97cdf5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 537000]
[bbc6c523] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[bbe178b3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[bbed534d] tttt: [AAAA_KK33222] ===== main slush (4)!! M
[bc06ede9] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[bc37d5f5] tttt: offset=0, center=99000, life=99000, media=2, tty=33, bw=6000, byebyt =0
[bc941e54] tttt: [AAAA_KK33222] ===== main slush (4)!! T
[bcbb47f4] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[bcd54a14] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[bcf79c4d] tttt: offset=0, center=963000, life=963000, media=2, tty=33, bw=6000, byebyt =0
[bd341456] tttt: offset=0, center=543000, life=543000, media=2, tty=33, bw=6000, byebyt =0
[bd6c241d] tttt: offset=0, center=691250, life=691250, media=18, tty=33, bw=6000, byebyt =14
[be41f965] tttt: offset=0, center=247250, life=247250, media=18, tty=33, bw=6000, byebyt =14
[be46f2bc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[becdc9bc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?W??!
[bee3bea7] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[bf5672eb] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c0530202] tttt: offset=0, center=55250, life=55250, media=18, tty=33, bw=6000, byebyt =14
[c058ac0e] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[c0852cab] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c09dfadf] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c1115f29] tttt: [AAAA_KK33222] ===== main slush (4)!! )
[c12a8e3a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c14d6696] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c1abf893] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 423000]
[c1dcf2bb] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c211a17e] tttt: offset=0, center=565250, life=565250, media=18, tty=33, bw=6000, byebyt =14
[c294be94] tttt: offset=0, center=853250, life=853250, media=18, tty=33, bw=6000, byebyt =14
[c2d5f38b] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c2ef8190] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c34a612d] tttt: offset=0, center=429000, life=429000, media=2, tty=33, bw=6000, byebyt =0
[c37410cb] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 309000]
[c3a1c1d8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c4627e11] tttt: offset=0, center=409250, life=409250, media=18, tty=33, bw=6000, byebyt =14
[c488eec2] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 153000]
[c4ae15d8] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c4c31f25] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c508d796] tttt: offset=0, center=315000, life=315000, media=2, tty=33, bw=6000, byebyt =0
[c53a8d26] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 855000]
[c57499dd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c59125b0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c5aad627] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c5e1f853] tttt: offset=0, center=75000, life=75000, media=2, tty=33, bw=6000, byebyt =0
[c62a293a] tttt: offset=0, center=159000, life=159000, media=2, tty=33, bw=6000, byebyt =0
[c66f755d] tttt: [AAAA_KK33222] ===== main slush (4)!! ]
[c67a7a72] tttt: [AAAA_KK33222] ===== main slush (4)!! r
[c6940c23] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c6e11f0b] tttt: offset=0, center=861000, life=861000, media=2, tty=33, bw=6000, byebyt =0
[c6ee3a0a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 741000]
[c71158fb] tttt: offset=0, center=697250, life=697250, media=18, tty=33, bw=6000, byebyt =14
[c71c6148] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c7f986cc] tttt: offset=0, center=253250, life=253250, media=18, tty=33, bw=6000, byebyt =14
[c814290a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 99000]
[c82d8caf] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[c843ffd8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c87c9f81] tttt: [AAAA_KK33222] ===== main slush (4)!! ??_?!
[c8878fe9] tttt: offset=0, center=747000, life=747000, media=2, tty=33, bw=6000, byebyt =0
[c8eda4aa] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[c90362ee] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 543000]
[c9086c87] tttt: [AAAA_KK33222] ===== main slush (3)!! ?
[c93577c7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[c950915b] tttt: [AAAA_KK33222] ===== main slush (4)!! [
[c9b10353] tttt: offset=0, center=105000, life=105000, media=2, tty=33, bw=6000, byebyt =0
[c9f4eac0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 963000]
[ca0799ef] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ca3001a0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ca3a50f1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ca50e572] tttt: offset=0, center=61250, life=61250, media=18, tty=33, bw=6000, byebyt =14
[ca52acd6] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ca99721b] tttt: offset=0, center=549000, life=549000, media=2, tty=33, bw=6000, byebyt =0
[cabdb572] tttt: [AAAA_KK33222] ===== main slush (4)!! r
[cad6a410] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[cb96f7d2] tttt: offset=0, center=969000, life=969000, media=2, tty=33, bw=6000, byebyt =0
[cba5c847] tttt: [AAAA_KK33222] ===== main slush (4)!! G
[cbb80ce7] tttt: offset=0, center=571250, life=571250, media=18, tty=33, bw=6000, byebyt =14
[cc43870d] tttt: offset=0, center=859250, life=859250, media=18, tty=33, bw=6000, byebyt =14
[cc885cd0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[cca2ba99] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ccd4d705] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[cdf2d762] tttt: [AAAA_KK33222] ===== main slush (4)!! b
[ce0992e3] tttt: offset=0, center=415250, life=415250, media=18, tty=33, bw=6000, byebyt =14
[cf16d627] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 429000]
[cf40c9ad] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[cf47e59e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[cf5a0fa2] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[cfed3cd6] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d03bb856] tttt: [AAAA_KK33222] ===== main slush (4)!! V
[d0545c7f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d0ae80e2] tttt: offset=0, center=435000, life=435000, media=2, tty=33, bw=6000, byebyt =0
[d0c38b35] tttt: offset=0, center=703250, life=703250, media=18, tty=33, bw=6000, byebyt =14
[d0d61239] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 315000]
[d106028f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d1beb75c] tttt: offset=0, center=259250, life=259250, media=18, tty=33, bw=6000, byebyt =14
[d1f80691] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 159000]
[d208c7d8] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 75000]
[d233b808] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d238338b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d27b0e4d] tttt: offset=0, center=321000, life=321000, media=2, tty=33, bw=6000, byebyt =0
[d27e26fb] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d298d564] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d2afcaf5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 861000]
[d2e8b7ad] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d39c74e5] tttt: offset=0, center=165000, life=165000, media=2, tty=33, bw=6000, byebyt =0
[d3a72843] tttt: offset=0, center=57000, life=57000, media=2, tty=33, bw=6000, byebyt =0
[d3cca424] tttt: [AAAA_KK33222] ===== main slush (4)!! $
[d3dba742] tttt: [AAAA_KK33222] ===== main slush (4)!! B
[d3f3d4fd] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d4033b02] tttt: offset=0, center=67250, life=67250, media=18, tty=33, bw=6000, byebyt =14
[d44f90f4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 747000]
[d450f08e] tttt: offset=0, center=867000, life=867000, media=2, tty=33, bw=6000, byebyt =0
[d468053b] tttt: [AAAA_KK33222] ===== main slush (4)!! ;
[d480c328] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d4812549] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d5597da8] tttt: offset=0, center=577250, life=577250, media=18, tty=33, bw=6000, byebyt =14
[d57d74ca] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 105000]
[d59d8b8d] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d5bb3d1e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d5e71e4a] tttt: offset=0, center=753000, life=753000, media=2, tty=33, bw=6000, byebyt =0
[d5eec3b1] tttt: offset=0, center=865250, life=865250, media=18, tty=33, bw=6000, byebyt =14
[d63caef5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d655999c] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d69a9d67] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 549000]
[d6c0623d] tttt: [AAAA_KK33222] ===== main slush (4)!! =
[d6c6a9ff] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d6d071cd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d727358d] tttt: offset=0, center=111000, life=111000, media=2, tty=33, bw=6000, byebyt =0
[d76eedad] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d7c16967] tttt: offset=0, center=421250, life=421250, media=18, tty=33, bw=6000, byebyt =14
[d8378455] tttt: offset=0, center=555000, life=555000, media=2, tty=33, bw=6000, byebyt =0
[d8933484] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 969000]
[d8c98d7f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[d8e78ef9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[d900758f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[d905c56e] tttt: [AAAA_KK33222] ===== main slush (4)!! n
[da0494d3] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[da1effa6] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[da304992] tttt: offset=0, center=975000, life=975000, media=2, tty=33, bw=6000, byebyt =0
[da498cd7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[da66ad3d] tttt: offset=0, center=709250, life=709250, media=18, tty=33, bw=6000, byebyt =14
[db599780] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[db8c3a9b] tttt: offset=0, center=265250, life=265250, media=18, tty=33, bw=6000, byebyt =14
[dc44f69c] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[dc5a1f15] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[dc739dac] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 435000]
[dca4f6a5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[dd7a1ad7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[dd92791f] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ddc82501] tttt: offset=0, center=77250, life=77250, media=18, tty=33, bw=6000, byebyt =14
[de123821] tttt: offset=0, center=441000, life=441000, media=2, tty=33, bw=6000, byebyt =0
[de15278d] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[de2f7ee2] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[de4575c5] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 321000]
[de74a62f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[de8606f9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[def7fef3] tttt: offset=0, center=583250, life=583250, media=18, tty=33, bw=6000, byebyt =14
[df6921a0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 165000]
[df7019c1] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 57000]
[df96448c] tttt: offset=0, center=871250, life=871250, media=18, tty=33, bw=6000, byebyt =14
[dfa20dfd] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[dfa662c6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[dfdbe551] tttt: offset=0, center=327000, life=327000, media=2, tty=33, bw=6000, byebyt =0
[dfefae81] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e00bde64] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e0177965] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 867000]
[e05286fa] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[e109f0cf] tttt: offset=0, center=63000, life=63000, media=2, tty=33, bw=6000, byebyt =0
[e1182435] tttt: offset=0, center=171000, life=171000, media=2, tty=33, bw=6000, byebyt =0
[e13507a0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e1721165] tttt: offset=0, center=427250, life=427250, media=18, tty=33, bw=6000, byebyt =14
[e1ad4e72] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 753000]
[e1b7c166] tttt: offset=0, center=873000, life=873000, media=2, tty=33, bw=6000, byebyt =0
[e1def092] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[e2863a59] tttt: [AAAA_KK33222] ===== main slush (4)!! Y
[e29e8f33] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e2f0959f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 111000]
[e2fa51fc] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e330a4d9] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[e34c5a9f] tttt: offset=0, center=759000, life=759000, media=2, tty=33, bw=6000, byebyt =0
[e3c295be] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e3df49da] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e4016a15] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 555000]
[e4050e5b] tttt: offset=0, center=715250, life=715250, media=18, tty=33, bw=6000, byebyt =14
[e428b20d] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[e4344cdb] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[e43cc242] tttt: [AAAA_KK33222] ===== main slush (4)!! B
[e4b221bf] tttt: offset=0, center=117000, life=117000, media=2, tty=33, bw=6000, byebyt =0
[e5433c4a] tttt: offset=0, center=271250, life=271250, media=18, tty=33, bw=6000, byebyt =14
[e5a70ae5] tttt: offset=0, center=561000, life=561000, media=2, tty=33, bw=6000, byebyt =0
[e606e9f2] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e60e2ccf] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e66b1ea0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e6769783] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e726a6c5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e72becae] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 975000]
[e73fd281] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e76729ab] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[e7865814] * BT is active, apply coex RF and PD CR settings??J
[e7c3c6bb] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e7d45a15] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[e7dbf96a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e7e40fe7] tttt: offset=0, center=83250, life=83250, media=18, tty=33, bw=6000, byebyt =14
[e8abfdff] tttt: offset=0, center=589250, life=589250, media=18, tty=33, bw=6000, byebyt =14
[e8cbaec0] tttt: offset=0, center=981000, life=981000, media=2, tty=33, bw=6000, byebyt =0
[e8ccf670] tttt: [AAAA_KK33222] ===== main slush (4)!! p
[e9468c63] tttt: offset=0, center=877250, life=877250, media=18, tty=33, bw=6000, byebyt =14
[e9a6f6a8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[e9c12fc4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[e9dcc5a7] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 441000]
[ea0c4e0e] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[eb287749] tttt: offset=0, center=433250, life=433250, media=18, tty=33, bw=6000, byebyt =14
[eb861fc4] tttt: offset=0, center=447000, life=447000, media=2, tty=33, bw=6000, byebyt =0
[eba2026b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 327000]
[ebd1ecb2] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ec3514ee] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ec4e67c4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[ecd92bea] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 63000]
[ece34e3d] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 171000]
[ed0a56f0] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ed1ea0c6] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ed215eb7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ed39c57a] tttt: offset=0, center=333000, life=333000, media=2, tty=33, bw=6000, byebyt =0
[ed8b48a5] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[eda63216] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[edb229de] tttt: offset=0, center=721250, life=721250, media=18, tty=33, bw=6000, byebyt =14
[ee71e340] tttt: offset=0, center=69000, life=69000, media=2, tty=33, bw=6000, byebyt =0
[ee856d6c] tttt: offset=0, center=219000, life=219000, media=2, tty=33, bw=6000, byebyt =0
[eea48555] tttt: [AAAA_KK33222] ===== main slush (4)!! U
[eeacda49] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 873000]
[eee667da] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ef1092fd] tttt: offset=0, center=277250, life=277250, media=18, tty=33, bw=6000, byebyt =14
[ef1268ce] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 759000]
[ef45b8ef] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f0217184] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f0374ec1] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f04d86f7] tttt: offset=0, center=879000, life=879000, media=2, tty=33, bw=6000, byebyt =0
[f058c062] tttt: [AAAA_KK33222] ===== main slush (4)!! b
[f07bb6d4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 117000]
[f0acebcc] tttt: offset=0, center=765000, life=765000, media=2, tty=33, bw=6000, byebyt =0
[f0bc3f08] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f0c78a9a] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f0df85d3] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f16a69a9] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f17430c2] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 561000]
[f1827953] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f19aaf33] tttt: [AAAA_KK33222] ===== main slush (4)!! 3
[f1a379d9] tttt: offset=0, center=175250, life=175250, media=18, tty=33, bw=6000, byebyt =14
[f1a77922] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f1aa047d] tttt: [AAAA_KK33222] ===== main slush (4)!! }
[f230b9ee] tttt: offset=0, center=651000, life=651000, media=2, tty=33, bw=6000, byebyt =0
[f24617d8] tttt: offset=0, center=595250, life=595250, media=18, tty=33, bw=6000, byebyt =14
[f2ed01b9] tttt: offset=0, center=883250, life=883250, media=18, tty=33, bw=6000, byebyt =14
[f30da62d] tttt: offset=0, center=567000, life=567000, media=2, tty=33, bw=6000, byebyt =0
[f35244fa] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f36cc050] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f3d1a467] tttt: [AAAA_KK33222] ===== main slush (4)!! g
[f49e1c18] tttt: [AAAA_KK33222] ===== main slush (4)!! 
[f4da4c88] tttt: offset=0, center=439250, life=439250, media=18, tty=33, bw=6000, byebyt =14
[f54f80fe] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f5d3662b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 981000]
[f5dbca3a] tttt: [AAAA_KK33222] ===== main slush (4)!! :
[f5f41fd4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f60cc14a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f62bc37a] tttt: [AAAA_KK33222] ===== main slush (4)!! z
[f74a6bcf] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[f74b4c66] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 447000]
[f75fd304] tttt: offset=0, center=727250, life=727250, media=18, tty=33, bw=6000, byebyt =14
[f764ae9a] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[f772b916] tttt: offset=0, center=987000, life=987000, media=2, tty=33, bw=6000, byebyt =0
[f77e6a28] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f8cf5507] tttt: offset=0, center=283250, life=283250, media=18, tty=33, bw=6000, byebyt =14
[f8e972b6] tttt: offset=0, center=453000, life=453000, media=2, tty=33, bw=6000, byebyt =0
[f900766c] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 333000]
[f9320c60] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[f9cf92c8] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fa3be4e1] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[fa5652ff] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 69000]
[fa5b8624] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 219000]
[fa64d254] tttt: [AAAA_KK33222] ===== main slush (4)!! T
[fa806925] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[fa8b641b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[fa9a5c6a] tttt: offset=0, center=339000, life=339000, media=2, tty=33, bw=6000, byebyt =0
[fb0b0184] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[fb1215d7] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fb2ae7c5] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[fbab6b73] tttt: offset=0, center=181250, life=181250, media=18, tty=33, bw=6000, byebyt =14
[fbc23af1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fbe6cc02] tttt: offset=0, center=601250, life=601250, media=18, tty=33, bw=6000, byebyt =14
[fbf289f3] tttt: offset=0, center=225000, life=225000, media=2, tty=33, bw=6000, byebyt =0
[fc07a89d] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fc77474e] tttt: offset=0, center=79000, life=79000, media=2, tty=33, bw=6000, byebyt =0
[fc79913a] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 765000]
[fc97ffed] tttt: offset=0, center=889250, life=889250, media=18, tty=33, bw=6000, byebyt =14
[fcab2705] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[fd0373d1] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fd1d521d] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE
[fd4664e4] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 879000]
[fd7d3f36] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[fdb8dd8a] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[fdf75154] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 651000]
[fe136fb8] tttt: offset=0, center=771000, life=771000, media=2, tty=33, bw=6000, byebyt =0
[fe2549a3] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[fe893036] tttt: offset=0, center=445250, life=445250, media=18, tty=33, bw=6000, byebyt =14
[fed6ba4b] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] Start AAAJob [COST : 567000]
[fee8965d] tttt: offset=0, center=885000, life=885000, media=2, tty=33, bw=6000, byebyt =0
[ff08039f] tttt: [LGDT3307] [DUMMY/LIFE] [VBYBY] End AAAJob [SYSTEM : FAIL] [GREEN : 3]
[ff103eec] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ff8c36f0] tttt: offset=0, center=657000, life=657000, media=2, tty=33, bw=6000, byebyt =0
[ff8d36e0] tttt: [AAAA_KK33222] ===== main slush (4)!! ?
[ff94d865] tttt: [AAAA_KK33222] ===== main slush (4)!! e
[ffa559e4] tttt: garbage_si2178b_atv_KPI, fail to SOMEONE

