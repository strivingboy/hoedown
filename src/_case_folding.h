/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -L ANSI-C -N find_case_mapping -l -c -C -E -S 1 -t -m100 data/case_folding.gperf  */
/* Computed positions: -k'1-2,$' */

#line 2 "data/case_folding.gperf"
struct case_mapping {
  const char *name;
  const char *value;
  size_t length;
};
/* maximum key range = 2756, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757,   86,   81,   76,   72,   70,
        56,   54,   53,   51,   49,   41,   40,   39,   36,   35,
        31,   24,   19,   18,   14,    6,    4,    3,    2,    1,
         0, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 1455,  672,
        59, 1286,  196, 1230, 1125,  565, 1510, 1097, 1263, 1011,
       867, 1344, 1316,  988,   49, 1100,  548, 1379,  273, 1238,
       504,  916, 1015,   27,  158,  170,  306,  655,   87,  100,
       936,  633,  712,  642,  792,  590,  853,    0,   15,  159,
       122,  225,  416,  395,  444,  744,   10,  164,  179,  361,
         6,   26, 1559,  238, 1187,  451,  902,  610, 1077,  721,
       116, 1108,   57, 1314,    4,  108,  383,  126,  690,   63,
        77,  141, 1080,  826,   55,  278,  651,    2,    1,   87,
         0,  227,  180,    3,  583, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757,    5,   68, 2757, 2757, 2757,
      2757, 2757, 2757, 2757,    4, 2757, 2757, 2757, 2757,  233,
         2, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757,
      2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757, 2757
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[1]+23];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}

#ifdef __GNUC__
__inline
#if defined __GNUC_STDC_INLINE__ || defined __GNUC_GNU_INLINE__
__attribute__ ((__gnu_inline__))
#endif
#endif
const struct case_mapping *
find_case_mapping (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 1180,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 4,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 2756
    };

  static const struct case_mapping wordlist[] =
    {
#line 33 "data/case_folding.gperf"
      {"Z", "\x7A", 1},
#line 32 "data/case_folding.gperf"
      {"Y", "\x79", 1},
#line 31 "data/case_folding.gperf"
      {"X", "\x78", 1},
#line 1155 "data/case_folding.gperf"
      {"\360\220\220\247", "\xF0\x90\x91\x8F", 4},
#line 30 "data/case_folding.gperf"
      {"W", "\x77", 1},
#line 29 "data/case_folding.gperf"
      {"V", "\x76", 1},
#line 755 "data/case_folding.gperf"
      {"\341\276\247", "\xE1\xBD\xA7\xCE\xB9", 5},
#line 28 "data/case_folding.gperf"
      {"U", "\x75", 1},
#line 658 "data/case_folding.gperf"
      {"\341\273\264", "\xE1\xBB\xB5", 3},
#line 592 "data/case_folding.gperf"
      {"\341\271\264", "\xE1\xB9\xB5", 3},
#line 560 "data/case_folding.gperf"
      {"\341\270\264", "\xE1\xB8\xB5", 3},
#line 766 "data/case_folding.gperf"
      {"\341\276\264", "\xCE\xAC\xCE\xB9", 4},
#line 656 "data/case_folding.gperf"
      {"\341\273\260", "\xE1\xBB\xB1", 3},
#line 590 "data/case_folding.gperf"
      {"\341\271\260", "\xE1\xB9\xB1", 3},
#line 558 "data/case_folding.gperf"
      {"\341\270\260", "\xE1\xB8\xB1", 3},
#line 1163 "data/case_folding.gperf"
      {"\360\221\242\247", "\xF0\x91\xA3\x87", 4},
#line 652 "data/case_folding.gperf"
      {"\341\273\250", "\xE1\xBB\xA9", 3},
#line 586 "data/case_folding.gperf"
      {"\341\271\250", "\xE1\xB9\xA9", 3},
#line 554 "data/case_folding.gperf"
      {"\341\270\250", "\xE1\xB8\xA9", 3},
#line 756 "data/case_folding.gperf"
      {"\341\276\250", "\xE1\xBD\xA0\xCE\xB9", 5},
#line 1176 "data/case_folding.gperf"
      {"\360\221\242\264", "\xF0\x91\xA3\x94", 4},
#line 1046 "data/case_folding.gperf"
      {"\352\235\250", "\xEA\x9D\xA9", 3},
#line 27 "data/case_folding.gperf"
      {"T", "\x74", 1},
#line 1172 "data/case_folding.gperf"
      {"\360\221\242\260", "\xF0\x91\xA3\x90", 4},
#line 995 "data/case_folding.gperf"
      {"\352\231\250", "\xEA\x99\xA9", 3},
#line 1141 "data/case_folding.gperf"
      {"\360\220\220\231", "\xF0\x90\x91\x81", 4},
#line 501 "data/case_folding.gperf"
      {"\341\202\247", "\xE2\xB4\x87", 3},
#line 1164 "data/case_folding.gperf"
      {"\360\221\242\250", "\xF0\x91\xA3\x88", 4},
#line 26 "data/case_folding.gperf"
      {"S", "\x73", 1},
#line 741 "data/case_folding.gperf"
      {"\341\276\231", "\xE1\xBC\xA1\xCE\xB9", 5},
#line 25 "data/case_folding.gperf"
      {"R", "\x72", 1},
#line 332 "data/case_folding.gperf"
      {"\320\231", "\xD0\xB9", 2},
#line 514 "data/case_folding.gperf"
      {"\341\202\264", "\xE2\xB4\x94", 3},
#line 1076 "data/case_folding.gperf"
      {"\352\236\260", "\xCA\x9E", 2},
#line 510 "data/case_folding.gperf"
      {"\341\202\260", "\xE2\xB4\x90", 3},
#line 1177 "data/case_folding.gperf"
      {"\360\221\242\265", "\xF0\x91\xA3\x95", 4},
#line 1071 "data/case_folding.gperf"
      {"\352\236\250", "\xEA\x9E\xA9", 3},
#line 24 "data/case_folding.gperf"
      {"Q", "\x71", 1},
#line 502 "data/case_folding.gperf"
      {"\341\202\250", "\xE2\xB4\x88", 3},
#line 375 "data/case_folding.gperf"
      {"\322\220", "\xD2\x91", 2},
#line 323 "data/case_folding.gperf"
      {"\320\220", "\xD0\xB0", 2},
#line 281 "data/case_folding.gperf"
      {"\317\220", "\xCE\xB2", 2},
#line 486 "data/case_folding.gperf"
      {"\325\220", "\xD6\x80", 2},
#line 1132 "data/case_folding.gperf"
      {"\360\220\220\220", "\xF0\x90\x90\xB8", 4},
#line 640 "data/case_folding.gperf"
      {"\341\273\220", "\xE1\xBB\x91", 3},
#line 574 "data/case_folding.gperf"
      {"\341\271\220", "\xE1\xB9\x91", 3},
#line 542 "data/case_folding.gperf"
      {"\341\270\220", "\xE1\xB8\x91", 3},
#line 732 "data/case_folding.gperf"
      {"\341\276\220", "\xE1\xBC\xA0\xCE\xB9", 5},
#line 515 "data/case_folding.gperf"
      {"\341\202\265", "\xE2\xB4\x95", 3},
#line 1034 "data/case_folding.gperf"
      {"\352\235\220", "\xEA\x9D\x91", 3},
#line 23 "data/case_folding.gperf"
      {"P", "\x70", 1},
#line 1118 "data/case_folding.gperf"
      {"\360\220\220\202", "\xF0\x90\x90\xAA", 4},
#line 983 "data/case_folding.gperf"
      {"\352\231\220", "\xEA\x99\x91", 3},
#line 633 "data/case_folding.gperf"
      {"\341\273\202", "\xE1\xBB\x83", 3},
#line 567 "data/case_folding.gperf"
      {"\341\271\202", "\xE1\xB9\x83", 3},
#line 535 "data/case_folding.gperf"
      {"\341\270\202", "\xE1\xB8\x83", 3},
#line 718 "data/case_folding.gperf"
      {"\341\276\202", "\xE1\xBC\x82\xCE\xB9", 5},
#line 22 "data/case_folding.gperf"
      {"O", "\x6F", 1},
#line 1027 "data/case_folding.gperf"
      {"\352\235\202", "\xEA\x9D\x83", 3},
#line 21 "data/case_folding.gperf"
      {"N", "\x6E", 1},
#line 391 "data/case_folding.gperf"
      {"\322\260", "\xD2\xB1", 2},
#line 976 "data/case_folding.gperf"
      {"\352\231\202", "\xEA\x99\x83", 3},
#line 297 "data/case_folding.gperf"
      {"\317\260", "\xCE\xBA", 2},
#line 20 "data/case_folding.gperf"
      {"M", "\x6D", 1},
#line 19 "data/case_folding.gperf"
      {"L", "\x6C", 1},
#line 1060 "data/case_folding.gperf"
      {"\352\236\220", "\xEA\x9E\x91", 3},
#line 18 "data/case_folding.gperf"
      {"K", "\x6B", 1},
#line 300 "data/case_folding.gperf"
      {"\317\265", "\xCE\xB5", 2},
#line 34 "data/case_folding.gperf"
      {"\302\265", "\xCE\xBC", 2},
#line 309 "data/case_folding.gperf"
      {"\320\202", "\xD1\x92", 2},
#line 279 "data/case_folding.gperf"
      {"\317\202", "\xCF\x83", 2},
#line 472 "data/case_folding.gperf"
      {"\325\202", "\xD5\xB2", 2},
#line 1055 "data/case_folding.gperf"
      {"\352\236\202", "\xEA\x9E\x83", 3},
#line 1146 "data/case_folding.gperf"
      {"\360\220\220\236", "\xF0\x90\x91\x86", 4},
#line 647 "data/case_folding.gperf"
      {"\341\273\236", "\xE1\xBB\x9F", 3},
#line 581 "data/case_folding.gperf"
      {"\341\271\236", "\xE1\xB9\x9F", 3},
#line 549 "data/case_folding.gperf"
      {"\341\270\236", "\xE1\xB8\x9F", 3},
#line 746 "data/case_folding.gperf"
      {"\341\276\236", "\xE1\xBC\xA6\xCE\xB9", 5},
#line 17 "data/case_folding.gperf"
      {"J", "\x6A", 1},
#line 1041 "data/case_folding.gperf"
      {"\352\235\236", "\xEA\x9D\x9F", 3},
#line 626 "data/case_folding.gperf"
      {"\341\272\264", "\xE1\xBA\xB5", 3},
#line 179 "data/case_folding.gperf"
      {"\307\231", "\xC7\x9A", 2},
#line 16 "data/case_folding.gperf"
      {"I", "\x69", 1},
#line 990 "data/case_folding.gperf"
      {"\352\231\236", "\xEA\x99\x9F", 3},
#line 624 "data/case_folding.gperf"
      {"\341\272\260", "\xE1\xBA\xB1", 3},
#line 1147 "data/case_folding.gperf"
      {"\360\220\220\237", "\xF0\x90\x91\x87", 4},
#line 15 "data/case_folding.gperf"
      {"H", "\x68", 1},
#line 14 "data/case_folding.gperf"
      {"G", "\x67", 1},
#line 620 "data/case_folding.gperf"
      {"\341\272\250", "\xE1\xBA\xA9", 3},
#line 747 "data/case_folding.gperf"
      {"\341\276\237", "\xE1\xBC\xA7\xCE\xB9", 5},
#line 13 "data/case_folding.gperf"
      {"F", "\x66", 1},
#line 382 "data/case_folding.gperf"
      {"\322\236", "\xD2\x9F", 2},
#line 337 "data/case_folding.gperf"
      {"\320\236", "\xD0\xBE", 2},
#line 288 "data/case_folding.gperf"
      {"\317\236", "\xCF\x9F", 2},
#line 346 "data/case_folding.gperf"
      {"\320\247", "\xD1\x87", 2},
#line 1066 "data/case_folding.gperf"
      {"\352\236\236", "\xEA\x9E\x9F", 3},
#line 398 "data/case_folding.gperf"
      {"\322\276", "\xD2\xBF", 2},
#line 612 "data/case_folding.gperf"
      {"\341\272\231", "\x79\xCC\x8A", 3},
#line 305 "data/case_folding.gperf"
      {"\317\276", "\xCD\xBC", 2},
#line 663 "data/case_folding.gperf"
      {"\341\273\276", "\xE1\xBB\xBF", 3},
#line 597 "data/case_folding.gperf"
      {"\341\271\276", "\xE1\xB9\xBF", 3},
#line 565 "data/case_folding.gperf"
      {"\341\270\276", "\xE1\xB8\xBF", 3},
#line 774 "data/case_folding.gperf"
      {"\341\276\276", "\xCE\xB9", 2},
#line 208 "data/case_folding.gperf"
      {"\310\220", "\xC8\x91", 2},
#line 1053 "data/case_folding.gperf"
      {"\352\235\276", "\xEA\x9D\xBF", 3},
#line 653 "data/case_folding.gperf"
      {"\341\273\252", "\xE1\xBB\xAB", 3},
#line 587 "data/case_folding.gperf"
      {"\341\271\252", "\xE1\xB9\xAB", 3},
#line 555 "data/case_folding.gperf"
      {"\341\270\252", "\xE1\xB8\xAB", 3},
#line 758 "data/case_folding.gperf"
      {"\341\276\252", "\xE1\xBD\xA2\xCE\xB9", 5},
#line 899 "data/case_folding.gperf"
      {"\342\260\247", "\xE2\xB1\x97", 3},
#line 1047 "data/case_folding.gperf"
      {"\352\235\252", "\xEA\x9D\xAB", 3},
#line 1186 "data/case_folding.gperf"
      {"\360\221\242\276", "\xF0\x91\xA3\x9E", 4},
#line 190 "data/case_folding.gperf"
      {"\307\260", "\x6A\xCC\x8C", 3},
#line 996 "data/case_folding.gperf"
      {"\352\231\252", "\xEA\x99\xAB", 3},
#line 12 "data/case_folding.gperf"
      {"E", "\x65", 1},
#line 1166 "data/case_folding.gperf"
      {"\360\221\242\252", "\xF0\x91\xA3\x8A", 4},
#line 606 "data/case_folding.gperf"
      {"\341\272\220", "\xE1\xBA\x91", 3},
#line 11 "data/case_folding.gperf"
      {"D", "\x64", 1},
#line 59 "data/case_folding.gperf"
      {"\303\231", "\xC3\xB9", 2},
#line 911 "data/case_folding.gperf"
      {"\342\261\247", "\xE2\xB1\xA8", 3},
#line 900 "data/case_folding.gperf"
      {"\342\260\250", "\xE2\xB1\x98", 3},
#line 524 "data/case_folding.gperf"
      {"\341\202\276", "\xE2\xB4\x9E", 3},
#line 224 "data/case_folding.gperf"
      {"\310\260", "\xC8\xB1", 2},
#line 10 "data/case_folding.gperf"
      {"C", "\x63", 1},
#line 599 "data/case_folding.gperf"
      {"\341\272\202", "\xE1\xBA\x83", 3},
#line 1072 "data/case_folding.gperf"
      {"\352\236\252", "\xC9\xA6", 2},
#line 504 "data/case_folding.gperf"
      {"\341\202\252", "\xE2\xB4\x8A", 3},
#line 917 "data/case_folding.gperf"
      {"\342\261\260", "\xC9\x92", 2},
#line 51 "data/case_folding.gperf"
      {"\303\220", "\xC3\xB0", 2},
#line 885 "data/case_folding.gperf"
      {"\342\260\231", "\xE2\xB1\x89", 3},
#line 363 "data/case_folding.gperf"
      {"\321\260", "\xD1\xB1", 2},
#line 9 "data/case_folding.gperf"
      {"B", "\x62", 1},
#line 1142 "data/case_folding.gperf"
      {"\360\220\220\232", "\xF0\x90\x91\x82", 4},
#line 201 "data/case_folding.gperf"
      {"\310\202", "\xC8\x83", 2},
#line 645 "data/case_folding.gperf"
      {"\341\273\232", "\xE1\xBB\x9B", 3},
#line 579 "data/case_folding.gperf"
      {"\341\271\232", "\xE1\xB9\x9B", 3},
#line 547 "data/case_folding.gperf"
      {"\341\270\232", "\xE1\xB8\x9B", 3},
#line 742 "data/case_folding.gperf"
      {"\341\276\232", "\xE1\xBC\xA2\xCE\xB9", 5},
#line 757 "data/case_folding.gperf"
      {"\341\276\251", "\xE1\xBD\xA1\xCE\xB9", 5},
#line 1039 "data/case_folding.gperf"
      {"\352\235\232", "\xEA\x9D\x9B", 3},
#line 8 "data/case_folding.gperf"
      {"A", "\x61", 1},
#line 919 "data/case_folding.gperf"
      {"\342\261\265", "\xE2\xB1\xB6", 3},
#line 988 "data/case_folding.gperf"
      {"\352\231\232", "\xEA\x99\x9B", 3},
#line 1143 "data/case_folding.gperf"
      {"\360\220\220\233", "\xF0\x90\x91\x83", 4},
#line 106 "data/case_folding.gperf"
      {"\305\220", "\xC5\x91", 2},
#line 181 "data/case_folding.gperf"
      {"\307\236", "\xC7\x9F", 2},
#line 1165 "data/case_folding.gperf"
      {"\360\221\242\251", "\xF0\x91\xA3\x89", 4},
#line 743 "data/case_folding.gperf"
      {"\341\276\233", "\xE1\xBC\xA3\xCE\xB9", 5},
#line 615 "data/case_folding.gperf"
      {"\341\272\236", "\x73\x73", 2},
#line 876 "data/case_folding.gperf"
      {"\342\260\220", "\xE2\xB1\x80", 3},
#line 199 "data/case_folding.gperf"
      {"\307\276", "\xC7\xBF", 2},
#line 1173 "data/case_folding.gperf"
      {"\360\221\242\261", "\xF0\x91\xA3\x91", 4},
#line 657 "data/case_folding.gperf"
      {"\341\273\262", "\xE1\xBB\xB3", 3},
#line 591 "data/case_folding.gperf"
      {"\341\271\262", "\xE1\xB9\xB3", 3},
#line 559 "data/case_folding.gperf"
      {"\341\270\262", "\xE1\xB8\xB3", 3},
#line 764 "data/case_folding.gperf"
      {"\341\276\262", "\xE1\xBD\xB0\xCE\xB9", 5},
#line 1064 "data/case_folding.gperf"
      {"\352\236\232", "\xEA\x9E\x9B", 3},
#line 215 "data/case_folding.gperf"
      {"\310\236", "\xC8\x9F", 2},
#line 862 "data/case_folding.gperf"
      {"\342\260\202", "\xE2\xB0\xB2", 3},
#line 503 "data/case_folding.gperf"
      {"\341\202\251", "\xE2\xB4\x89", 3},
#line 37 "data/case_folding.gperf"
      {"\303\202", "\xC3\xA2", 2},
#line 1077 "data/case_folding.gperf"
      {"\352\236\261", "\xCA\x87", 2},
#line 229 "data/case_folding.gperf"
      {"\310\276", "\xE2\xB1\xA6", 3},
#line 511 "data/case_folding.gperf"
      {"\341\202\261", "\xE2\xB4\x91", 3},
#line 1174 "data/case_folding.gperf"
      {"\360\221\242\262", "\xF0\x91\xA3\x92", 4},
#line 122 "data/case_folding.gperf"
      {"\305\260", "\xC5\xB1", 2},
#line 1120 "data/case_folding.gperf"
      {"\360\220\220\204", "\xF0\x90\x90\xAC", 4},
#line 708 "data/case_folding.gperf"
      {"\341\275\250", "\xE1\xBD\xA0", 3},
#line 634 "data/case_folding.gperf"
      {"\341\273\204", "\xE1\xBB\x85", 3},
#line 568 "data/case_folding.gperf"
      {"\341\271\204", "\xE1\xB9\x85", 3},
#line 536 "data/case_folding.gperf"
      {"\341\270\204", "\xE1\xB8\x85", 3},
#line 720 "data/case_folding.gperf"
      {"\341\276\204", "\xE1\xBC\x84\xCE\xB9", 5},
#line 370 "data/case_folding.gperf"
      {"\321\276", "\xD1\xBF", 2},
#line 1028 "data/case_folding.gperf"
      {"\352\235\204", "\xEA\x9D\x85", 3},
#line 631 "data/case_folding.gperf"
      {"\341\272\276", "\xE1\xBA\xBF", 3},
#line 977 "data/case_folding.gperf"
      {"\352\231\204", "\xEA\x99\x85", 3},
#line 512 "data/case_folding.gperf"
      {"\341\202\262", "\xE2\xB4\x92", 3},
#line 704 "data/case_folding.gperf"
      {"\341\275\231", "\xE1\xBD\x91", 3},
#line 621 "data/case_folding.gperf"
      {"\341\272\252", "\xE1\xBA\xAB", 3},
#line 948 "data/case_folding.gperf"
      {"\342\262\264", "\xE2\xB2\xB5", 3},
#line 348 "data/case_folding.gperf"
      {"\320\251", "\xD1\x89", 2},
#line 1006 "data/case_folding.gperf"
      {"\352\232\220", "\xEA\x9A\x91", 3},
#line 890 "data/case_folding.gperf"
      {"\342\260\236", "\xE2\xB1\x8E", 3},
#line 946 "data/case_folding.gperf"
      {"\342\262\260", "\xE2\xB2\xB1", 3},
#line 64 "data/case_folding.gperf"
      {"\303\236", "\xC3\xBE", 2},
#line 528 "data/case_folding.gperf"
      {"\341\203\202", "\xE2\xB4\xA2", 3},
#line 942 "data/case_folding.gperf"
      {"\342\262\250", "\xE2\xB2\xA9", 3},
#line 1056 "data/case_folding.gperf"
      {"\352\236\204", "\xEA\x9E\x85", 3},
#line 999 "data/case_folding.gperf"
      {"\352\232\202", "\xEA\x9A\x83", 3},
#line 439 "data/case_folding.gperf"
      {"\324\220", "\xD4\x91", 2},
#line 350 "data/case_folding.gperf"
      {"\320\253", "\xD1\x8B", 2},
#line 891 "data/case_folding.gperf"
      {"\342\260\237", "\xE2\xB1\x8F", 3},
#line 759 "data/case_folding.gperf"
      {"\341\276\253", "\xE1\xBD\xA3\xCE\xB9", 5},
#line 700 "data/case_folding.gperf"
      {"\341\275\220", "\xCF\x85\xCC\x93", 4},
#line 113 "data/case_folding.gperf"
      {"\305\236", "\xC5\x9F", 2},
#line 298 "data/case_folding.gperf"
      {"\317\261", "\xCF\x81", 2},
#line 1167 "data/case_folding.gperf"
      {"\360\221\242\253", "\xF0\x91\xA3\x8B", 4},
#line 768 "data/case_folding.gperf"
      {"\341\276\267", "\xCE\xB1\xCD\x82\xCE\xB9", 6},
#line 678 "data/case_folding.gperf"
      {"\341\274\250", "\xE1\xBC\xA0", 3},
#line 846 "data/case_folding.gperf"
      {"\342\223\202", "\xE2\x93\x9C", 3},
#line 613 "data/case_folding.gperf"
      {"\341\272\232", "\x61\xCA\xBE", 3},
#line 902 "data/case_folding.gperf"
      {"\342\260\252", "\xE2\xB1\x9A", 3},
#line 1073 "data/case_folding.gperf"
      {"\352\236\253", "\xC9\x9C", 2},
#line 1179 "data/case_folding.gperf"
      {"\360\221\242\267", "\xF0\x91\xA3\x97", 4},
#line 505 "data/case_folding.gperf"
      {"\341\202\253", "\xE2\xB4\x8B", 3},
#line 930 "data/case_folding.gperf"
      {"\342\262\220", "\xE2\xB2\x91", 3},
#line 673 "data/case_folding.gperf"
      {"\341\274\231", "\xE1\xBC\x91", 3},
#line 459 "data/case_folding.gperf"
      {"\324\265", "\xD5\xA5", 2},
#line 920 "data/case_folding.gperf"
      {"\342\261\276", "\xC8\xBF", 2},
#line 614 "data/case_folding.gperf"
      {"\341\272\233", "\xE1\xB9\xA1", 3},
#line 432 "data/case_folding.gperf"
      {"\324\202", "\xD4\x83", 2},
#line 923 "data/case_folding.gperf"
      {"\342\262\202", "\xE2\xB2\x83", 3},
#line 517 "data/case_folding.gperf"
      {"\341\202\267", "\xE2\xB4\x97", 3},
#line 625 "data/case_folding.gperf"
      {"\341\272\262", "\xE1\xBA\xB3", 3},
#line 407 "data/case_folding.gperf"
      {"\323\220", "\xD3\x91", 2},
#line 1136 "data/case_folding.gperf"
      {"\360\220\220\224", "\xF0\x90\x90\xBC", 4},
#line 642 "data/case_folding.gperf"
      {"\341\273\224", "\xE1\xBB\x95", 3},
#line 576 "data/case_folding.gperf"
      {"\341\271\224", "\xE1\xB9\x95", 3},
#line 544 "data/case_folding.gperf"
      {"\341\270\224", "\xE1\xB8\x95", 3},
#line 736 "data/case_folding.gperf"
      {"\341\276\224", "\xE1\xBC\xA4\xCE\xB9", 5},
#line 1036 "data/case_folding.gperf"
      {"\352\235\224", "\xEA\x9D\x95", 3},
#line 707 "data/case_folding.gperf"
      {"\341\275\237", "\xE1\xBD\x97", 3},
#line 985 "data/case_folding.gperf"
      {"\352\231\224", "\xEA\x99\x95", 3},
#line 600 "data/case_folding.gperf"
      {"\341\272\204", "\xE1\xBA\x85", 3},
#line 886 "data/case_folding.gperf"
      {"\342\260\232", "\xE2\xB1\x8A", 3},
#line 901 "data/case_folding.gperf"
      {"\342\260\251", "\xE2\xB1\x99", 3},
#line 446 "data/case_folding.gperf"
      {"\324\236", "\xD4\x9F", 2},
#line 937 "data/case_folding.gperf"
      {"\342\262\236", "\xE2\xB2\x9F", 3},
#line 468 "data/case_folding.gperf"
      {"\324\276", "\xD5\xAE", 2},
#line 423 "data/case_folding.gperf"
      {"\323\260", "\xD3\xB1", 2},
#line 887 "data/case_folding.gperf"
      {"\342\260\233", "\xE2\xB1\x8B", 3},
#line 191 "data/case_folding.gperf"
      {"\307\261", "\xC7\xB3", 2},
#line 912 "data/case_folding.gperf"
      {"\342\261\251", "\xE2\xB1\xAA", 3},
#line 710 "data/case_folding.gperf"
      {"\341\275\252", "\xE1\xBD\xA2", 3},
#line 1144 "data/case_folding.gperf"
      {"\360\220\220\234", "\xF0\x90\x91\x84", 4},
#line 646 "data/case_folding.gperf"
      {"\341\273\234", "\xE1\xBB\x9D", 3},
#line 580 "data/case_folding.gperf"
      {"\341\271\234", "\xE1\xB9\x9D", 3},
#line 548 "data/case_folding.gperf"
      {"\341\270\234", "\xE1\xB8\x9D", 3},
#line 744 "data/case_folding.gperf"
      {"\341\276\234", "\xE1\xBC\xA4\xCE\xB9", 5},
#line 1040 "data/case_folding.gperf"
      {"\352\235\234", "\xEA\x9D\x9D", 3},
#line 392 "data/case_folding.gperf"
      {"\322\262", "\xD2\xB3", 2},
#line 989 "data/case_folding.gperf"
      {"\352\231\234", "\xEA\x99\x9D", 3},
#line 380 "data/case_folding.gperf"
      {"\322\232", "\xD2\x9B", 2},
#line 333 "data/case_folding.gperf"
      {"\320\232", "\xD0\xBA", 2},
#line 286 "data/case_folding.gperf"
      {"\317\232", "\xCF\x9B", 2},
#line 918 "data/case_folding.gperf"
      {"\342\261\262", "\xE2\xB1\xB3", 3},
#line 953 "data/case_folding.gperf"
      {"\342\262\276", "\xE2\xB2\xBF", 3},
#line 1011 "data/case_folding.gperf"
      {"\352\232\232", "\xEA\x9A\x9B", 3},
#line 864 "data/case_folding.gperf"
      {"\342\260\204", "\xE2\xB0\xB4", 3},
#line 943 "data/case_folding.gperf"
      {"\342\262\252", "\xE2\xB2\xAB", 3},
#line 1065 "data/case_folding.gperf"
      {"\352\236\234", "\xEA\x9E\x9D", 3},
#line 414 "data/case_folding.gperf"
      {"\323\236", "\xD3\x9F", 2},
#line 842 "data/case_folding.gperf"
      {"\342\222\276", "\xE2\x93\x98", 3},
#line 709 "data/case_folding.gperf"
      {"\341\275\251", "\xE1\xBD\xA1", 3},
#line 430 "data/case_folding.gperf"
      {"\323\276", "\xD3\xBF", 2},
#line 692 "data/case_folding.gperf"
      {"\341\274\276", "\xE1\xBC\xB6", 3},
#line 334 "data/case_folding.gperf"
      {"\320\233", "\xD0\xBB", 2},
#line 240 "data/case_folding.gperf"
      {"\315\260", "\xCD\xB1", 2},
#line 680 "data/case_folding.gperf"
      {"\341\274\252", "\xE1\xBC\xA2", 3},
#line 705 "data/case_folding.gperf"
      {"\341\275\233", "\xE1\xBD\x93", 3},
#line 903 "data/case_folding.gperf"
      {"\342\260\253", "\xE2\xB1\x9B", 3},
#line 530 "data/case_folding.gperf"
      {"\341\203\204", "\xE2\xB4\xA4", 3},
#line 814 "data/case_folding.gperf"
      {"\342\204\252", "\x6B", 1},
#line 1000 "data/case_folding.gperf"
      {"\352\232\204", "\xEA\x9A\x85", 3},
#line 608 "data/case_folding.gperf"
      {"\341\272\224", "\xE1\xBA\x95", 3},
#line 311 "data/case_folding.gperf"
      {"\320\204", "\xD1\x94", 2},
#line 935 "data/case_folding.gperf"
      {"\342\262\232", "\xE2\xB2\x9B", 3},
#line 474 "data/case_folding.gperf"
      {"\325\204", "\xD5\xB4", 2},
#line 765 "data/case_folding.gperf"
      {"\341\276\263", "\xCE\xB1\xCE\xB9", 4},
#line 913 "data/case_folding.gperf"
      {"\342\261\253", "\xE2\xB1\xAC", 3},
#line 1020 "data/case_folding.gperf"
      {"\352\234\264", "\xEA\x9C\xB5", 3},
#line 824 "data/case_folding.gperf"
      {"\342\205\247", "\xE2\x85\xB7", 3},
#line 1175 "data/case_folding.gperf"
      {"\360\221\242\263", "\xF0\x91\xA3\x93", 4},
#line 1015 "data/case_folding.gperf"
      {"\352\234\250", "\xEA\x9C\xA9", 3},
#line 192 "data/case_folding.gperf"
      {"\307\262", "\xC7\xB3", 2},
#line 848 "data/case_folding.gperf"
      {"\342\223\204", "\xE2\x93\x9E", 3},
#line 947 "data/case_folding.gperf"
      {"\342\262\262", "\xE2\xB2\xB3", 3},
#line 825 "data/case_folding.gperf"
      {"\342\205\250", "\xE2\x85\xB8", 3},
#line 674 "data/case_folding.gperf"
      {"\341\274\232", "\xE1\xBC\x92", 3},
#line 679 "data/case_folding.gperf"
      {"\341\274\251", "\xE1\xBC\xA1", 3},
#line 513 "data/case_folding.gperf"
      {"\341\202\263", "\xE2\xB4\x93", 3},
#line 225 "data/case_folding.gperf"
      {"\310\262", "\xC8\xB3", 2},
#line 213 "data/case_folding.gperf"
      {"\310\232", "\xC8\x9B", 2},
#line 1080 "data/case_folding.gperf"
      {"\357\254\202", "\x66\x6C", 2},
#line 675 "data/case_folding.gperf"
      {"\341\274\233", "\xE1\xBC\x93", 3},
#line 761 "data/case_folding.gperf"
      {"\341\276\255", "\xE1\xBD\xA5\xCE\xB9", 5},
#line 880 "data/case_folding.gperf"
      {"\342\260\224", "\xE2\xB1\x84", 3},
#line 924 "data/case_folding.gperf"
      {"\342\262\204", "\xE2\xB2\x85", 3},
#line 364 "data/case_folding.gperf"
      {"\321\262", "\xD1\xB3", 2},
#line 711 "data/case_folding.gperf"
      {"\341\275\253", "\xE1\xBD\xA3", 3},
#line 180 "data/case_folding.gperf"
      {"\307\233", "\xC7\x9C", 2},
#line 1169 "data/case_folding.gperf"
      {"\360\221\242\255", "\xF0\x91\xA3\x8D", 4},
#line 816 "data/case_folding.gperf"
      {"\342\204\262", "\xE2\x85\x8E", 3},
#line 455 "data/case_folding.gperf"
      {"\324\261", "\xD5\xA1", 2},
#line 654 "data/case_folding.gperf"
      {"\341\273\254", "\xE1\xBB\xAD", 3},
#line 588 "data/case_folding.gperf"
      {"\341\271\254", "\xE1\xB9\xAD", 3},
#line 556 "data/case_folding.gperf"
      {"\341\270\254", "\xE1\xB8\xAD", 3},
#line 760 "data/case_folding.gperf"
      {"\341\276\254", "\xE1\xBD\xA4\xCE\xB9", 5},
#line 1075 "data/case_folding.gperf"
      {"\352\236\255", "\xC9\xAC", 2},
#line 1048 "data/case_folding.gperf"
      {"\352\235\254", "\xEA\x9D\xAD", 3},
#line 507 "data/case_folding.gperf"
      {"\341\202\255", "\xE2\xB4\x8D", 3},
#line 167 "data/case_folding.gperf"
      {"\307\204", "\xC7\x86", 2},
#line 60 "data/case_folding.gperf"
      {"\303\232", "\xC3\xBA", 2},
#line 997 "data/case_folding.gperf"
      {"\352\231\254", "\xEA\x99\xAD", 3},
#line 74 "data/case_folding.gperf"
      {"\304\220", "\xC4\x91", 2},
#line 1168 "data/case_folding.gperf"
      {"\360\221\242\254", "\xF0\x91\xA3\x8C", 4},
#line 888 "data/case_folding.gperf"
      {"\342\260\234", "\xE2\xB1\x8C", 3},
#line 1008 "data/case_folding.gperf"
      {"\352\232\224", "\xEA\x9A\x95", 3},
#line 202 "data/case_folding.gperf"
      {"\310\204", "\xC8\x85", 2},
#line 123 "data/case_folding.gperf"
      {"\305\262", "\xC5\xB3", 2},
#line 1074 "data/case_folding.gperf"
      {"\352\236\254", "\xC9\xA1", 2},
#line 111 "data/case_folding.gperf"
      {"\305\232", "\xC5\x9B", 2},
#line 506 "data/case_folding.gperf"
      {"\341\202\254", "\xE2\xB4\x8C", 3},
#line 655 "data/case_folding.gperf"
      {"\341\273\256", "\xE1\xBB\xAF", 3},
#line 589 "data/case_folding.gperf"
      {"\341\271\256", "\xE1\xB9\xAF", 3},
#line 557 "data/case_folding.gperf"
      {"\341\270\256", "\xE1\xB8\xAF", 3},
#line 762 "data/case_folding.gperf"
      {"\341\276\256", "\xE1\xBD\xA6\xCE\xB9", 5},
#line 302 "data/case_folding.gperf"
      {"\317\271", "\xCF\xB2", 2},
#line 1049 "data/case_folding.gperf"
      {"\352\235\256", "\xEA\x9D\xAF", 3},
#line 90 "data/case_folding.gperf"
      {"\304\260", "\x69\xCC\x87", 3},
#line 61 "data/case_folding.gperf"
      {"\303\233", "\xC3\xBB", 2},
#line 681 "data/case_folding.gperf"
      {"\341\274\253", "\xE1\xBC\xA3", 3},
#line 702 "data/case_folding.gperf"
      {"\341\275\224", "\xCF\x85\xCC\x93\xCC\x81", 6},
#line 770 "data/case_folding.gperf"
      {"\341\276\271", "\xE1\xBE\xB1", 3},
#line 1096 "data/case_folding.gperf"
      {"\357\274\247", "\xEF\xBD\x87", 3},
#line 1050 "data/case_folding.gperf"
      {"\352\235\271", "\xEA\x9D\xBA", 3},
#line 1170 "data/case_folding.gperf"
      {"\360\221\242\256", "\xF0\x91\xA3\x8E", 4},
#line 815 "data/case_folding.gperf"
      {"\342\204\253", "\xC3\xA5", 2},
#line 835 "data/case_folding.gperf"
      {"\342\222\267", "\xE2\x93\x91", 3},
#line 1109 "data/case_folding.gperf"
      {"\357\274\264", "\xEF\xBD\x94", 3},
#line 67 "data/case_folding.gperf"
      {"\304\202", "\xC4\x83", 2},
#line 1181 "data/case_folding.gperf"
      {"\360\221\242\271", "\xF0\x91\xA3\x99", 4},
#line 1105 "data/case_folding.gperf"
      {"\357\274\260", "\xEF\xBD\x90", 3},
#line 39 "data/case_folding.gperf"
      {"\303\204", "\xC3\xA4", 2},
#line 1097 "data/case_folding.gperf"
      {"\357\274\250", "\xEF\xBD\x88", 3},
#line 508 "data/case_folding.gperf"
      {"\341\202\256", "\xE2\xB4\x8E", 3},
#line 1025 "data/case_folding.gperf"
      {"\352\234\276", "\xEA\x9C\xBF", 3},
#line 932 "data/case_folding.gperf"
      {"\342\262\224", "\xE2\xB2\x95", 3},
#line 519 "data/case_folding.gperf"
      {"\341\202\271", "\xE2\xB4\x99", 3},
#line 1110 "data/case_folding.gperf"
      {"\357\274\265", "\xEF\xBD\x95", 3},
#line 1016 "data/case_folding.gperf"
      {"\352\234\252", "\xEA\x9C\xAB", 3},
#line 81 "data/case_folding.gperf"
      {"\304\236", "\xC4\x9F", 2},
#line 827 "data/case_folding.gperf"
      {"\342\205\252", "\xE2\x85\xBA", 3},
#line 377 "data/case_folding.gperf"
      {"\322\224", "\xD2\x95", 2},
#line 327 "data/case_folding.gperf"
      {"\320\224", "\xD0\xB4", 2},
#line 456 "data/case_folding.gperf"
      {"\324\262", "\xD5\xA2", 2},
#line 490 "data/case_folding.gperf"
      {"\325\224", "\xD6\x84", 2},
#line 444 "data/case_folding.gperf"
      {"\324\232", "\xD4\x9B", 2},
#line 232 "data/case_folding.gperf"
      {"\311\204", "\xCA\x89", 2},
#line 1138 "data/case_folding.gperf"
      {"\360\220\220\226", "\xF0\x90\x90\xBE", 4},
#line 622 "data/case_folding.gperf"
      {"\341\272\254", "\xE1\xBA\xAD", 3},
#line 643 "data/case_folding.gperf"
      {"\341\273\226", "\xE1\xBB\x97", 3},
#line 577 "data/case_folding.gperf"
      {"\341\271\226", "\xE1\xB9\x97", 3},
#line 545 "data/case_folding.gperf"
      {"\341\270\226", "\xE1\xB8\x97", 3},
#line 738 "data/case_folding.gperf"
      {"\341\276\226", "\xE1\xBC\xA6\xCE\xB9", 5},
#line 1037 "data/case_folding.gperf"
      {"\352\235\226", "\xEA\x9D\x97", 3},
#line 936 "data/case_folding.gperf"
      {"\342\262\234", "\xE2\xB2\x9D", 3},
#line 986 "data/case_folding.gperf"
      {"\352\231\226", "\xEA\x99\x97", 3},
#line 389 "data/case_folding.gperf"
      {"\322\254", "\xD2\xAD", 2},
#line 351 "data/case_folding.gperf"
      {"\320\254", "\xD1\x8C", 2},
#line 295 "data/case_folding.gperf"
      {"\317\254", "\xCF\xAD", 2},
#line 905 "data/case_folding.gperf"
      {"\342\260\255", "\xE2\xB1\x9D", 3},
#line 826 "data/case_folding.gperf"
      {"\342\205\251", "\xE2\x85\xB9", 3},
#line 1062 "data/case_folding.gperf"
      {"\352\236\226", "\xEA\x9E\x97", 3},
#line 623 "data/case_folding.gperf"
      {"\341\272\256", "\xE1\xBA\xAF", 3},
#line 1082 "data/case_folding.gperf"
      {"\357\254\204", "\x66\x66\x6C", 3},
#line 676 "data/case_folding.gperf"
      {"\341\274\234", "\xE1\xBC\x94", 3},
#line 914 "data/case_folding.gperf"
      {"\342\261\255", "\xC9\x91", 2},
#line 1019 "data/case_folding.gperf"
      {"\352\234\262", "\xEA\x9C\xB3", 3},
#line 433 "data/case_folding.gperf"
      {"\324\204", "\xD4\x85", 2},
#line 424 "data/case_folding.gperf"
      {"\323\262", "\xD3\xB3", 2},
#line 904 "data/case_folding.gperf"
      {"\342\260\254", "\xE2\xB1\x9C", 3},
#line 412 "data/case_folding.gperf"
      {"\323\232", "\xD3\x9B", 2},
#line 1134 "data/case_folding.gperf"
      {"\360\220\220\222", "\xF0\x90\x90\xBA", 4},
#line 641 "data/case_folding.gperf"
      {"\341\273\222", "\xE1\xBB\x93", 3},
#line 575 "data/case_folding.gperf"
      {"\341\271\222", "\xE1\xB9\x93", 3},
#line 543 "data/case_folding.gperf"
      {"\341\270\222", "\xE1\xB8\x93", 3},
#line 734 "data/case_folding.gperf"
      {"\341\276\222", "\xE1\xBC\xA2\xCE\xB9", 5},
#line 1035 "data/case_folding.gperf"
      {"\352\235\222", "\xEA\x9D\x93", 3},
#line 984 "data/case_folding.gperf"
      {"\352\231\222", "\xEA\x99\x93", 3},
#line 1123 "data/case_folding.gperf"
      {"\360\220\220\207", "\xF0\x90\x90\xAF", 4},
#line 390 "data/case_folding.gperf"
      {"\322\256", "\xD2\xAF", 2},
#line 353 "data/case_folding.gperf"
      {"\320\256", "\xD1\x8E", 2},
#line 296 "data/case_folding.gperf"
      {"\317\256", "\xCF\xAF", 2},
#line 723 "data/case_folding.gperf"
      {"\341\276\207", "\xE1\xBC\x87\xCE\xB9", 5},
#line 210 "data/case_folding.gperf"
      {"\310\224", "\xC8\x95", 2},
#line 906 "data/case_folding.gperf"
      {"\342\260\256", "\xE2\xB1\x9E", 3},
#line 127 "data/case_folding.gperf"
      {"\305\271", "\xC5\xBA", 2},
#line 1061 "data/case_folding.gperf"
      {"\352\236\222", "\xEA\x9E\x93", 3},
#line 713 "data/case_folding.gperf"
      {"\341\275\255", "\xE1\xBD\xA5", 3},
#line 1099 "data/case_folding.gperf"
      {"\357\274\252", "\xEF\xBD\x8A", 3},
#line 188 "data/case_folding.gperf"
      {"\307\254", "\xC7\xAD", 2},
#line 797 "data/case_folding.gperf"
      {"\341\277\247", "\xCF\x85\xCC\x88\xCD\x82", 6},
#line 915 "data/case_folding.gperf"
      {"\342\261\256", "\xC9\xB1", 2},
#line 1153 "data/case_folding.gperf"
      {"\360\220\220\245", "\xF0\x90\x91\x8D", 4},
#line 805 "data/case_folding.gperf"
      {"\341\277\264", "\xCF\x8E\xCE\xB9", 4},
#line 609 "data/case_folding.gperf"
      {"\341\272\226", "\x68\xCC\xB1", 3},
#line 241 "data/case_folding.gperf"
      {"\315\262", "\xCD\xB3", 2},
#line 753 "data/case_folding.gperf"
      {"\341\276\245", "\xE1\xBD\xA5\xCE\xB9", 5},
#line 828 "data/case_folding.gperf"
      {"\342\205\253", "\xE2\x85\xBB", 3},
#line 222 "data/case_folding.gperf"
      {"\310\254", "\xC8\xAD", 2},
#line 712 "data/case_folding.gperf"
      {"\341\275\254", "\xE1\xBD\xA4", 3},
#line 798 "data/case_folding.gperf"
      {"\341\277\250", "\xE1\xBF\xA0", 3},
#line 55 "data/case_folding.gperf"
      {"\303\224", "\xC3\xB4", 2},
#line 1161 "data/case_folding.gperf"
      {"\360\221\242\245", "\xF0\x91\xA3\x85", 4},
#line 361 "data/case_folding.gperf"
      {"\321\254", "\xD1\xAD", 2},
#line 1086 "data/case_folding.gperf"
      {"\357\254\224", "\xD5\xB4\xD5\xA5", 4},
#line 790 "data/case_folding.gperf"
      {"\341\277\231", "\xE1\xBF\x91", 3},
#line 772 "data/case_folding.gperf"
      {"\341\276\273", "\xE1\xBD\xB1", 3},
#line 1098 "data/case_folding.gperf"
      {"\357\274\251", "\xEF\xBD\x89", 3},
#line 1051 "data/case_folding.gperf"
      {"\352\235\273", "\xEA\x9D\xBC", 3},
#line 499 "data/case_folding.gperf"
      {"\341\202\245", "\xE2\xB4\x85", 3},
#line 108 "data/case_folding.gperf"
      {"\305\224", "\xC5\x95", 2},
#line 1106 "data/case_folding.gperf"
      {"\357\274\261", "\xEF\xBD\x91", 3},
#line 944 "data/case_folding.gperf"
      {"\342\262\254", "\xE2\xB2\xAD", 3},
#line 683 "data/case_folding.gperf"
      {"\341\274\255", "\xE1\xBC\xA5", 3},
#line 1183 "data/case_folding.gperf"
      {"\360\221\242\273", "\xF0\x91\xA3\x9B", 4},
#line 714 "data/case_folding.gperf"
      {"\341\275\256", "\xE1\xBD\xA6", 3},
#line 463 "data/case_folding.gperf"
      {"\324\271", "\xD5\xA9", 2},
#line 189 "data/case_folding.gperf"
      {"\307\256", "\xC7\xAF", 2},
#line 882 "data/case_folding.gperf"
      {"\342\260\226", "\xE2\xB1\x86", 3},
#line 1149 "data/case_folding.gperf"
      {"\360\220\220\241", "\xF0\x90\x91\x89", 4},
#line 1107 "data/case_folding.gperf"
      {"\357\274\262", "\xEF\xBD\x92", 3},
#line 607 "data/case_folding.gperf"
      {"\341\272\222", "\xE1\xBA\x93", 3},
#line 749 "data/case_folding.gperf"
      {"\341\276\241", "\xE1\xBD\xA1\xCE\xB9", 5},
#line 521 "data/case_folding.gperf"
      {"\341\202\273", "\xE2\xB4\x9B", 3},
#line 1151 "data/case_folding.gperf"
      {"\360\220\220\243", "\xF0\x90\x91\x8B", 4},
#line 223 "data/case_folding.gperf"
      {"\310\256", "\xC8\xAF", 2},
#line 775 "data/case_folding.gperf"
      {"\341\277\202", "\xE1\xBD\xB4\xCE\xB9", 5},
#line 682 "data/case_folding.gperf"
      {"\341\274\254", "\xE1\xBC\xA4", 3},
#line 120 "data/case_folding.gperf"
      {"\305\254", "\xC5\xAD", 2},
#line 751 "data/case_folding.gperf"
      {"\341\276\243", "\xE1\xBD\xA3\xCE\xB9", 5},
#line 1157 "data/case_folding.gperf"
      {"\360\221\242\241", "\xF0\x91\xA3\x81", 4},
#line 314 "data/case_folding.gperf"
      {"\320\207", "\xD1\x97", 2},
#line 945 "data/case_folding.gperf"
      {"\342\262\256", "\xE2\xB2\xAF", 3},
#line 477 "data/case_folding.gperf"
      {"\325\207", "\xD5\xB7", 2},
#line 362 "data/case_folding.gperf"
      {"\321\256", "\xD1\xAF", 2},
#line 1145 "data/case_folding.gperf"
      {"\360\220\220\235", "\xF0\x90\x91\x85", 4},
#line 1159 "data/case_folding.gperf"
      {"\360\221\242\243", "\xF0\x91\xA3\x83", 4},
#line 336 "data/case_folding.gperf"
      {"\320\235", "\xD0\xBD", 2},
#line 745 "data/case_folding.gperf"
      {"\341\276\235", "\xE1\xBC\xA5\xCE\xB9", 5},
#line 495 "data/case_folding.gperf"
      {"\341\202\241", "\xE2\xB4\x81", 3},
#line 381 "data/case_folding.gperf"
      {"\322\234", "\xD2\x9D", 2},
#line 335 "data/case_folding.gperf"
      {"\320\234", "\xD0\xBC", 2},
#line 287 "data/case_folding.gperf"
      {"\317\234", "\xCF\x9D", 2},
#line 1009 "data/case_folding.gperf"
      {"\352\232\226", "\xEA\x9A\x97", 3},
#line 497 "data/case_folding.gperf"
      {"\341\202\243", "\xE2\xB4\x83", 3},
#line 1117 "data/case_folding.gperf"
      {"\360\220\220\201", "\xF0\x90\x90\xA9", 4},
#line 684 "data/case_folding.gperf"
      {"\341\274\256", "\xE1\xBC\xA6", 3},
#line 441 "data/case_folding.gperf"
      {"\324\224", "\xD4\x95", 2},
#line 837 "data/case_folding.gperf"
      {"\342\222\271", "\xE2\x93\x93", 3},
#line 878 "data/case_folding.gperf"
      {"\342\260\222", "\xE2\xB1\x82", 3},
#line 717 "data/case_folding.gperf"
      {"\341\276\201", "\xE1\xBC\x81\xCE\xB9", 5},
#line 687 "data/case_folding.gperf"
      {"\341\274\271", "\xE1\xBC\xB1", 3},
#line 1100 "data/case_folding.gperf"
      {"\357\274\253", "\xEF\xBD\x8B", 3},
#line 227 "data/case_folding.gperf"
      {"\310\273", "\xC8\xBC", 2},
#line 260 "data/case_folding.gperf"
      {"\316\231", "\xCE\xB9", 2},
#line 703 "data/case_folding.gperf"
      {"\341\275\226", "\xCF\x85\xCC\x93\xCD\x82", 6},
#line 121 "data/case_folding.gperf"
      {"\305\256", "\xC5\xAF", 2},
#line 867 "data/case_folding.gperf"
      {"\342\260\207", "\xE2\xB0\xB7", 3},
#line 1112 "data/case_folding.gperf"
      {"\357\274\267", "\xEF\xBD\x97", 3},
#line 251 "data/case_folding.gperf"
      {"\316\220", "\xCE\xB9\xCC\x88\xCC\x81", 6},
#line 91 "data/case_folding.gperf"
      {"\304\262", "\xC4\xB3", 2},
#line 453 "data/case_folding.gperf"
      {"\324\254", "\xD4\xAD", 2},
#line 79 "data/case_folding.gperf"
      {"\304\232", "\xC4\x9B", 2},
#line 376 "data/case_folding.gperf"
      {"\322\222", "\xD2\x93", 2},
#line 325 "data/case_folding.gperf"
      {"\320\222", "\xD0\xB2", 2},
#line 488 "data/case_folding.gperf"
      {"\325\222", "\xD6\x82", 2},
#line 800 "data/case_folding.gperf"
      {"\341\277\252", "\xE1\xBD\xBA", 3},
#line 933 "data/case_folding.gperf"
      {"\342\262\226", "\xE2\xB2\x97", 3},
#line 169 "data/case_folding.gperf"
      {"\307\207", "\xC7\x89", 2},
#line 1150 "data/case_folding.gperf"
      {"\360\220\220\242", "\xF0\x90\x91\x8A", 4},
#line 1007 "data/case_folding.gperf"
      {"\352\232\222", "\xEA\x9A\x93", 3},
#line 649 "data/case_folding.gperf"
      {"\341\273\242", "\xE1\xBB\xA3", 3},
#line 583 "data/case_folding.gperf"
      {"\341\271\242", "\xE1\xB9\xA3", 3},
#line 551 "data/case_folding.gperf"
      {"\341\270\242", "\xE1\xB8\xA3", 3},
#line 750 "data/case_folding.gperf"
      {"\341\276\242", "\xE1\xBD\xA2\xCE\xB9", 5},
#line 897 "data/case_folding.gperf"
      {"\342\260\245", "\xE2\xB1\x95", 3},
#line 1043 "data/case_folding.gperf"
      {"\352\235\242", "\xEA\x9D\xA3", 3},
#line 278 "data/case_folding.gperf"
      {"\316\260", "\xCF\x85\xCC\x88\xCC\x81", 6},
#line 409 "data/case_folding.gperf"
      {"\323\224", "\xD3\x95", 2},
#line 992 "data/case_folding.gperf"
      {"\352\231\242", "\xEA\x99\xA3", 3},
#line 532 "data/case_folding.gperf"
      {"\341\203\207", "\xE2\xB4\xA7", 3},
#line 1158 "data/case_folding.gperf"
      {"\360\221\242\242", "\xF0\x91\xA3\x82", 4},
#line 1052 "data/case_folding.gperf"
      {"\352\235\275", "\xE1\xB5\xB9", 3},
#line 701 "data/case_folding.gperf"
      {"\341\275\222", "\xCF\x85\xCC\x93\xCC\x80", 6},
#line 128 "data/case_folding.gperf"
      {"\305\273", "\xC5\xBC", 2},
#line 141 "data/case_folding.gperf"
      {"\306\220", "\xC9\x9B", 2},
#line 1185 "data/case_folding.gperf"
      {"\360\221\242\275", "\xF0\x91\xA3\x9D", 4},
#line 1068 "data/case_folding.gperf"
      {"\352\236\242", "\xEA\x9E\xA3", 3},
#line 214 "data/case_folding.gperf"
      {"\310\234", "\xC8\x9D", 2},
#line 496 "data/case_folding.gperf"
      {"\341\202\242", "\xE2\xB4\x82", 3},
#line 791 "data/case_folding.gperf"
      {"\341\277\232", "\xE1\xBD\xB6", 3},
#line 799 "data/case_folding.gperf"
      {"\341\277\251", "\xE1\xBF\xA1", 3},
#line 68 "data/case_folding.gperf"
      {"\304\204", "\xC4\x85", 2},
#line 454 "data/case_folding.gperf"
      {"\324\256", "\xD4\xAF", 2},
#line 421 "data/case_folding.gperf"
      {"\323\254", "\xD3\xAD", 2},
#line 763 "data/case_folding.gperf"
      {"\341\276\257", "\xE1\xBD\xA7\xCE\xB9", 5},
#line 523 "data/case_folding.gperf"
      {"\341\202\275", "\xE2\xB4\x9D", 3},
#line 851 "data/case_folding.gperf"
      {"\342\223\207", "\xE2\x93\xA1", 3},
#line 931 "data/case_folding.gperf"
      {"\342\262\222", "\xE2\xB2\x93", 3},
#line 792 "data/case_folding.gperf"
      {"\341\277\233", "\xE1\xBD\xB7", 3},
#line 42 "data/case_folding.gperf"
      {"\303\207", "\xC3\xA7", 2},
#line 1171 "data/case_folding.gperf"
      {"\360\221\242\257", "\xF0\x91\xA3\x8F", 4},
#line 265 "data/case_folding.gperf"
      {"\316\236", "\xCE\xBE", 2},
#line 893 "data/case_folding.gperf"
      {"\342\260\241", "\xE2\xB1\x91", 3},
#line 273 "data/case_folding.gperf"
      {"\316\247", "\xCF\x87", 2},
#line 803 "data/case_folding.gperf"
      {"\341\277\262", "\xE1\xBD\xBC\xCE\xB9", 5},
#line 63 "data/case_folding.gperf"
      {"\303\235", "\xC3\xBD", 2},
#line 830 "data/case_folding.gperf"
      {"\342\205\255", "\xE2\x85\xBD", 3},
#line 163 "data/case_folding.gperf"
      {"\306\265", "\xC6\xB6", 2},
#line 895 "data/case_folding.gperf"
      {"\342\260\243", "\xE2\xB1\x93", 3},
#line 62 "data/case_folding.gperf"
      {"\303\234", "\xC3\xBC", 2},
#line 132 "data/case_folding.gperf"
      {"\306\202", "\xC6\x83", 2},
#line 509 "data/case_folding.gperf"
      {"\341\202\257", "\xE2\xB4\x8F", 3},
#line 101 "data/case_folding.gperf"
      {"\305\207", "\xC5\x88", 2},
#line 352 "data/case_folding.gperf"
      {"\320\255", "\xD1\x8D", 2},
#line 1017 "data/case_folding.gperf"
      {"\352\234\254", "\xEA\x9C\xAD", 3},
#line 209 "data/case_folding.gperf"
      {"\310\222", "\xC8\x93", 2},
#line 777 "data/case_folding.gperf"
      {"\341\277\204", "\xCE\xAE\xCE\xB9", 4},
#line 889 "data/case_folding.gperf"
      {"\342\260\235", "\xE2\xB1\x8D", 3},
#line 909 "data/case_folding.gperf"
      {"\342\261\243", "\xE1\xB5\xBD", 3},
#line 465 "data/case_folding.gperf"
      {"\324\273", "\xD5\xAB", 2},
#line 829 "data/case_folding.gperf"
      {"\342\205\254", "\xE2\x85\xBC", 3},
#line 112 "data/case_folding.gperf"
      {"\305\234", "\xC5\x9D", 2},
#line 1152 "data/case_folding.gperf"
      {"\360\220\220\244", "\xF0\x90\x91\x8C", 4},
#line 422 "data/case_folding.gperf"
      {"\323\256", "\xD3\xAF", 2},
#line 650 "data/case_folding.gperf"
      {"\341\273\244", "\xE1\xBB\xA5", 3},
#line 584 "data/case_folding.gperf"
      {"\341\271\244", "\xE1\xB9\xA5", 3},
#line 552 "data/case_folding.gperf"
      {"\341\270\244", "\xE1\xB8\xA5", 3},
#line 752 "data/case_folding.gperf"
      {"\341\276\244", "\xE1\xBD\xA4\xCE\xB9", 5},
#line 1044 "data/case_folding.gperf"
      {"\352\235\244", "\xEA\x9D\xA5", 3},
#line 861 "data/case_folding.gperf"
      {"\342\260\201", "\xE2\xB0\xB1", 3},
#line 617 "data/case_folding.gperf"
      {"\341\272\242", "\xE1\xBA\xA3", 3},
#line 155 "data/case_folding.gperf"
      {"\306\247", "\xC6\xA8", 2},
#line 993 "data/case_folding.gperf"
      {"\352\231\244", "\xEA\x99\xA5", 3},
#line 1018 "data/case_folding.gperf"
      {"\352\234\256", "\xEA\x9C\xAF", 3},
#line 1160 "data/case_folding.gperf"
      {"\360\221\242\244", "\xF0\x91\xA3\x84", 4},
#line 801 "data/case_folding.gperf"
      {"\341\277\253", "\xE1\xBD\xBB", 3},
#line 53 "data/case_folding.gperf"
      {"\303\222", "\xC3\xB2", 2},
#line 831 "data/case_folding.gperf"
      {"\342\205\256", "\xE2\x85\xBE", 3},
#line 1108 "data/case_folding.gperf"
      {"\357\274\263", "\xEF\xBD\x93", 3},
#line 1069 "data/case_folding.gperf"
      {"\352\236\244", "\xEA\x9E\xA5", 3},
#line 498 "data/case_folding.gperf"
      {"\341\202\244", "\xE2\xB4\x84", 3},
#line 807 "data/case_folding.gperf"
      {"\341\277\267", "\xCF\x89\xCD\x82\xCE\xB9", 6},
#line 393 "data/case_folding.gperf"
      {"\322\264", "\xD2\xB5", 2},
#line 107 "data/case_folding.gperf"
      {"\305\222", "\xC5\x93", 2},
#line 299 "data/case_folding.gperf"
      {"\317\264", "\xCE\xB8", 2},
#line 94 "data/case_folding.gperf"
      {"\304\271", "\xC4\xBA", 2},
#line 527 "data/case_folding.gperf"
      {"\341\203\201", "\xE2\xB4\xA1", 3},
#line 839 "data/case_folding.gperf"
      {"\342\222\273", "\xE2\x93\x95", 3},
#line 706 "data/case_folding.gperf"
      {"\341\275\235", "\xE1\xBD\x95", 3},
#line 689 "data/case_folding.gperf"
      {"\341\274\273", "\xE1\xBC\xB3", 3},
#line 894 "data/case_folding.gperf"
      {"\342\260\242", "\xE2\xB1\x92", 3},
#line 1088 "data/case_folding.gperf"
      {"\357\254\226", "\xD5\xBE\xD5\xB6", 4},
#line 445 "data/case_folding.gperf"
      {"\324\234", "\xD4\x9D", 2},
#line 1102 "data/case_folding.gperf"
      {"\357\274\255", "\xEF\xBD\x8D", 3},
#line 1154 "data/case_folding.gperf"
      {"\360\220\220\246", "\xF0\x90\x91\x8E", 4},
#line 908 "data/case_folding.gperf"
      {"\342\261\242", "\xC9\xAB", 2},
#line 651 "data/case_folding.gperf"
      {"\341\273\246", "\xE1\xBB\xA7", 3},
#line 585 "data/case_folding.gperf"
      {"\341\271\246", "\xE1\xB9\xA7", 3},
#line 553 "data/case_folding.gperf"
      {"\341\270\246", "\xE1\xB8\xA7", 3},
#line 754 "data/case_folding.gperf"
      {"\341\276\246", "\xE1\xBD\xA6\xCE\xB9", 5},
#line 845 "data/case_folding.gperf"
      {"\342\223\201", "\xE2\x93\x9B", 3},
#line 1045 "data/case_folding.gperf"
      {"\352\235\246", "\xEA\x9D\xA7", 3},
#line 275 "data/case_folding.gperf"
      {"\316\251", "\xCF\x89", 2},
#line 994 "data/case_folding.gperf"
      {"\352\231\246", "\xEA\x99\xA7", 3},
#line 1128 "data/case_folding.gperf"
      {"\360\220\220\214", "\xF0\x90\x90\xB4", 4},
#line 1162 "data/case_folding.gperf"
      {"\360\221\242\246", "\xF0\x91\xA3\x86", 4},
#line 638 "data/case_folding.gperf"
      {"\341\273\214", "\xE1\xBB\x8D", 3},
#line 572 "data/case_folding.gperf"
      {"\341\271\214", "\xE1\xB9\x8D", 3},
#line 540 "data/case_folding.gperf"
      {"\341\270\214", "\xE1\xB8\x8D", 3},
#line 728 "data/case_folding.gperf"
      {"\341\276\214", "\xE1\xBC\x84\xCE\xB9", 5},
#line 1101 "data/case_folding.gperf"
      {"\357\274\254", "\xEF\xBD\x8C", 3},
#line 1032 "data/case_folding.gperf"
      {"\352\235\214", "\xEA\x9D\x8D", 3},
#line 403 "data/case_folding.gperf"
      {"\323\207", "\xD3\x88", 2},
#line 277 "data/case_folding.gperf"
      {"\316\253", "\xCF\x8B", 2},
#line 76 "data/case_folding.gperf"
      {"\304\224", "\xC4\x95", 2},
#line 981 "data/case_folding.gperf"
      {"\352\231\214", "\xEA\x99\x8D", 3},
#line 1070 "data/case_folding.gperf"
      {"\352\236\246", "\xEA\x9E\xA7", 3},
#line 618 "data/case_folding.gperf"
      {"\341\272\244", "\xE1\xBA\xA5", 3},
#line 500 "data/case_folding.gperf"
      {"\341\202\246", "\xE2\xB4\x86", 3},
#line 440 "data/case_folding.gperf"
      {"\324\222", "\xD4\x93", 2},
#line 677 "data/case_folding.gperf"
      {"\341\274\235", "\xE1\xBC\x95", 3},
#line 916 "data/case_folding.gperf"
      {"\342\261\257", "\xC9\x90", 2},
#line 301 "data/case_folding.gperf"
      {"\317\267", "\xCF\xB8", 2},
#line 413 "data/case_folding.gperf"
      {"\323\234", "\xD3\x9D", 2},
#line 193 "data/case_folding.gperf"
      {"\307\264", "\xC7\xB5", 2},
#line 378 "data/case_folding.gperf"
      {"\322\226", "\xD2\x97", 2},
#line 329 "data/case_folding.gperf"
      {"\320\226", "\xD0\xB6", 2},
#line 284 "data/case_folding.gperf"
      {"\317\226", "\xCF\x80", 2},
#line 492 "data/case_folding.gperf"
      {"\325\226", "\xD6\x86", 2},
#line 304 "data/case_folding.gperf"
      {"\317\275", "\xCD\xBB", 2},
#line 1103 "data/case_folding.gperf"
      {"\357\274\256", "\xEF\xBD\x8E", 3},
#line 156 "data/case_folding.gperf"
      {"\306\251", "\xCA\x83", 2},
#line 88 "data/case_folding.gperf"
      {"\304\254", "\xC4\xAD", 2},
#line 661 "data/case_folding.gperf"
      {"\341\273\272", "\xE1\xBB\xBB", 3},
#line 595 "data/case_folding.gperf"
      {"\341\271\272", "\xE1\xB9\xBB", 3},
#line 563 "data/case_folding.gperf"
      {"\341\270\272", "\xE1\xB8\xBB", 3},
#line 771 "data/case_folding.gperf"
      {"\341\276\272", "\xE1\xBD\xB0", 3},
#line 1114 "data/case_folding.gperf"
      {"\357\274\271", "\xEF\xBD\x99", 3},
#line 365 "data/case_folding.gperf"
      {"\321\264", "\xD1\xB5", 2},
#line 1139 "data/case_folding.gperf"
      {"\360\220\220\227", "\xF0\x90\x90\xBF", 4},
#line 1182 "data/case_folding.gperf"
      {"\360\221\242\272", "\xF0\x91\xA3\x9A", 4},
#line 939 "data/case_folding.gperf"
      {"\342\262\242", "\xE2\xB2\xA3", 3},
#line 896 "data/case_folding.gperf"
      {"\342\260\244", "\xE2\xB1\x94", 3},
#line 739 "data/case_folding.gperf"
      {"\341\276\227", "\xE1\xBC\xA7\xCE\xB9", 5},
#line 715 "data/case_folding.gperf"
      {"\341\275\257", "\xE1\xBD\xA7", 3},
#line 160 "data/case_folding.gperf"
      {"\306\261", "\xCA\x8A", 2},
#line 408 "data/case_folding.gperf"
      {"\323\222", "\xD3\x93", 2},
#line 520 "data/case_folding.gperf"
      {"\341\202\272", "\xE2\xB4\x9A", 3},
#line 910 "data/case_folding.gperf"
      {"\342\261\244", "\xC9\xBD", 2},
#line 1148 "data/case_folding.gperf"
      {"\360\220\220\240", "\xF0\x90\x91\x88", 4},
#line 648 "data/case_folding.gperf"
      {"\341\273\240", "\xE1\xBB\xA1", 3},
#line 582 "data/case_folding.gperf"
      {"\341\271\240", "\xE1\xB9\xA1", 3},
#line 550 "data/case_folding.gperf"
      {"\341\270\240", "\xE1\xB8\xA1", 3},
#line 748 "data/case_folding.gperf"
      {"\341\276\240", "\xE1\xBD\xA0\xCE\xB9", 5},
#line 619 "data/case_folding.gperf"
      {"\341\272\246", "\xE1\xBA\xA7", 3},
#line 1042 "data/case_folding.gperf"
      {"\352\235\240", "\xEA\x9D\xA1", 3},
#line 841 "data/case_folding.gperf"
      {"\342\222\275", "\xE2\x93\x97", 3},
#line 804 "data/case_folding.gperf"
      {"\341\277\263", "\xCF\x89\xCE\xB9", 4},
#line 991 "data/case_folding.gperf"
      {"\352\231\240", "\xEA\x99\xA1", 3},
#line 195 "data/case_folding.gperf"
      {"\307\267", "\xC6\xBF", 2},
#line 89 "data/case_folding.gperf"
      {"\304\256", "\xC4\xAF", 2},
#line 691 "data/case_folding.gperf"
      {"\341\274\275", "\xE1\xBC\xB5", 3},
#line 1156 "data/case_folding.gperf"
      {"\360\221\242\240", "\xF0\x91\xA3\x80", 4},
#line 124 "data/case_folding.gperf"
      {"\305\264", "\xC5\xB5", 2},
#line 604 "data/case_folding.gperf"
      {"\341\272\214", "\xE1\xBA\x8D", 3},
#line 822 "data/case_folding.gperf"
      {"\342\205\245", "\xE2\x85\xB5", 3},
#line 1067 "data/case_folding.gperf"
      {"\352\236\240", "\xEA\x9E\xA1", 3},
#line 494 "data/case_folding.gperf"
      {"\341\202\240", "\xE2\xB4\x80", 3},
#line 261 "data/case_folding.gperf"
      {"\316\232", "\xCE\xBA", 2},
#line 211 "data/case_folding.gperf"
      {"\310\226", "\xC8\x97", 2},
#line 685 "data/case_folding.gperf"
      {"\341\274\257", "\xE1\xBC\xA7", 3},
#line 228 "data/case_folding.gperf"
      {"\310\275", "\xC6\x9A", 2},
#line 898 "data/case_folding.gperf"
      {"\342\260\246", "\xE2\xB1\x96", 3},
#line 396 "data/case_folding.gperf"
      {"\322\272", "\xD2\xBB", 2},
#line 303 "data/case_folding.gperf"
      {"\317\272", "\xCF\xBB", 2},
#line 1131 "data/case_folding.gperf"
      {"\360\220\220\217", "\xF0\x90\x90\xB7", 4},
#line 95 "data/case_folding.gperf"
      {"\304\273", "\xC4\xBC", 2},
#line 629 "data/case_folding.gperf"
      {"\341\272\272", "\xE1\xBA\xBB", 3},
#line 731 "data/case_folding.gperf"
      {"\341\276\217", "\xE1\xBC\x87\xCE\xB9", 5},
#line 872 "data/case_folding.gperf"
      {"\342\260\214", "\xE2\xB0\xBC", 3},
#line 262 "data/case_folding.gperf"
      {"\316\233", "\xCE\xBB", 2},
#line 940 "data/case_folding.gperf"
      {"\342\262\244", "\xE2\xB2\xA5", 3},
#line 802 "data/case_folding.gperf"
      {"\341\277\254", "\xE1\xBF\xA5", 3},
#line 57 "data/case_folding.gperf"
      {"\303\226", "\xC3\xB6", 2},
#line 818 "data/case_folding.gperf"
      {"\342\205\241", "\xE2\x85\xB1", 3},
#line 610 "data/case_folding.gperf"
      {"\341\272\227", "\x74\xCC\x88", 3},
#line 161 "data/case_folding.gperf"
      {"\306\262", "\xCA\x8B", 2},
#line 458 "data/case_folding.gperf"
      {"\324\264", "\xD5\xA4", 2},
#line 1079 "data/case_folding.gperf"
      {"\357\254\201", "\x66\x69", 2},
#line 1127 "data/case_folding.gperf"
      {"\360\220\220\213", "\xF0\x90\x90\xB3", 4},
#line 820 "data/case_folding.gperf"
      {"\342\205\243", "\xE2\x85\xB3", 3},
#line 1140 "data/case_folding.gperf"
      {"\360\220\220\230", "\xF0\x90\x91\x80", 4},
#line 727 "data/case_folding.gperf"
      {"\341\276\213", "\xE1\xBC\x83\xCE\xB9", 5},
#line 644 "data/case_folding.gperf"
      {"\341\273\230", "\xE1\xBB\x99", 3},
#line 578 "data/case_folding.gperf"
      {"\341\271\230", "\xE1\xB9\x99", 3},
#line 546 "data/case_folding.gperf"
      {"\341\270\230", "\xE1\xB8\x99", 3},
#line 740 "data/case_folding.gperf"
      {"\341\276\230", "\xE1\xBC\xA0\xCE\xB9", 5},
#line 109 "data/case_folding.gperf"
      {"\305\226", "\xC5\x97", 2},
#line 1038 "data/case_folding.gperf"
      {"\352\235\230", "\xEA\x9D\x99", 3},
#line 129 "data/case_folding.gperf"
      {"\305\275", "\xC5\xBE", 2},
#line 616 "data/case_folding.gperf"
      {"\341\272\240", "\xE1\xBA\xA1", 3},
#line 987 "data/case_folding.gperf"
      {"\352\231\230", "\xEA\x99\x99", 3},
#line 1004 "data/case_folding.gperf"
      {"\352\232\214", "\xEA\x9A\x8D", 3},
#line 809 "data/case_folding.gperf"
      {"\341\277\271", "\xE1\xBD\xB9", 3},
#line 1058 "data/case_folding.gperf"
      {"\352\236\213", "\xEA\x9E\x8C", 3},
#line 1063 "data/case_folding.gperf"
      {"\352\236\230", "\xEA\x9E\x99", 3},
#line 883 "data/case_folding.gperf"
      {"\342\260\227", "\xE2\xB1\x87", 3},
#line 80 "data/case_folding.gperf"
      {"\304\234", "\xC4\x9D", 2},
#line 1094 "data/case_folding.gperf"
      {"\357\274\245", "\xEF\xBD\x85", 3},
#line 197 "data/case_folding.gperf"
      {"\307\272", "\xC7\xBB", 2},
#line 698 "data/case_folding.gperf"
      {"\341\275\214", "\xE1\xBD\x84", 3},
#line 133 "data/case_folding.gperf"
      {"\306\204", "\xC6\x85", 2},
#line 856 "data/case_folding.gperf"
      {"\342\223\214", "\xE2\x93\xA6", 3},
#line 425 "data/case_folding.gperf"
      {"\323\264", "\xD3\xB5", 2},
#line 941 "data/case_folding.gperf"
      {"\342\262\246", "\xE2\xB2\xA7", 3},
#line 226 "data/case_folding.gperf"
      {"\310\272", "\xE2\xB1\xA5", 3},
#line 892 "data/case_folding.gperf"
      {"\342\260\240", "\xE2\xB1\x90", 3},
#line 461 "data/case_folding.gperf"
      {"\324\267", "\xD5\xA7", 2},
#line 368 "data/case_folding.gperf"
      {"\321\272", "\xD1\xBB", 2},
#line 928 "data/case_folding.gperf"
      {"\342\262\214", "\xE2\xB2\x8D", 3},
#line 1012 "data/case_folding.gperf"
      {"\352\234\242", "\xEA\x9C\xA3", 3},
#line 442 "data/case_folding.gperf"
      {"\324\226", "\xD4\x97", 2},
#line 467 "data/case_folding.gperf"
      {"\324\275", "\xD5\xAD", 2},
#line 907 "data/case_folding.gperf"
      {"\342\261\240", "\xE2\xB1\xA1", 3},
#line 662 "data/case_folding.gperf"
      {"\341\273\274", "\xE1\xBB\xBD", 3},
#line 596 "data/case_folding.gperf"
      {"\341\271\274", "\xE1\xB9\xBD", 3},
#line 564 "data/case_folding.gperf"
      {"\341\270\274", "\xE1\xB8\xBD", 3},
#line 773 "data/case_folding.gperf"
      {"\341\276\274", "\xCE\xB1\xCE\xB9", 4},
#line 819 "data/case_folding.gperf"
      {"\342\205\242", "\xE2\x85\xB2", 3},
#line 75 "data/case_folding.gperf"
      {"\304\222", "\xC4\x93", 2},
#line 813 "data/case_folding.gperf"
      {"\342\204\246", "\xCF\x89", 2},
#line 787 "data/case_folding.gperf"
      {"\341\277\226", "\xCE\xB9\xCD\x82", 4},
#line 1090 "data/case_folding.gperf"
      {"\357\274\241", "\xEF\xBD\x81", 3},
#line 1184 "data/case_folding.gperf"
      {"\360\221\242\274", "\xF0\x91\xA3\x9C", 4},
#line 668 "data/case_folding.gperf"
      {"\341\274\214", "\xE1\xBC\x84", 3},
#line 1125 "data/case_folding.gperf"
      {"\360\220\220\211", "\xF0\x90\x90\xB1", 4},
#line 1092 "data/case_folding.gperf"
      {"\357\274\243", "\xEF\xBD\x83", 3},
#line 1133 "data/case_folding.gperf"
      {"\360\220\220\221", "\xF0\x90\x90\xB9", 4},
#line 725 "data/case_folding.gperf"
      {"\341\276\211", "\xE1\xBC\x81\xCE\xB9", 5},
#line 611 "data/case_folding.gperf"
      {"\341\272\230", "\x77\xCC\x8A", 3},
#line 733 "data/case_folding.gperf"
      {"\341\276\221", "\xE1\xBC\xA1\xCE\xB9", 5},
#line 522 "data/case_folding.gperf"
      {"\341\202\274", "\xE2\xB4\x9C", 3},
#line 951 "data/case_folding.gperf"
      {"\342\262\272", "\xE2\xB2\xBB", 3},
#line 324 "data/case_folding.gperf"
      {"\320\221", "\xD0\xB1", 2},
#line 282 "data/case_folding.gperf"
      {"\317\221", "\xCE\xB8", 2},
#line 487 "data/case_folding.gperf"
      {"\325\221", "\xD6\x81", 2},
#line 832 "data/case_folding.gperf"
      {"\342\205\257", "\xE2\x85\xBF", 3},
#line 875 "data/case_folding.gperf"
      {"\342\260\217", "\xE2\xB0\xBF", 3},
#line 387 "data/case_folding.gperf"
      {"\322\250", "\xD2\xA9", 2},
#line 347 "data/case_folding.gperf"
      {"\320\250", "\xD1\x88", 2},
#line 293 "data/case_folding.gperf"
      {"\317\250", "\xCF\xA9", 2},
#line 410 "data/case_folding.gperf"
      {"\323\226", "\xD3\x97", 2},
#line 1187 "data/case_folding.gperf"
      {"\360\221\242\277", "\xF0\x91\xA3\x9F", 4},
#line 1122 "data/case_folding.gperf"
      {"\360\220\220\206", "\xF0\x90\x90\xAE", 4},
#line 838 "data/case_folding.gperf"
      {"\342\222\272", "\xE2\x93\x94", 3},
#line 635 "data/case_folding.gperf"
      {"\341\273\206", "\xE1\xBB\x87", 3},
#line 569 "data/case_folding.gperf"
      {"\341\271\206", "\xE1\xB9\x87", 3},
#line 537 "data/case_folding.gperf"
      {"\341\270\206", "\xE1\xB8\x87", 3},
#line 722 "data/case_folding.gperf"
      {"\341\276\206", "\xE1\xBC\x86\xCE\xB9", 5},
#line 688 "data/case_folding.gperf"
      {"\341\274\272", "\xE1\xBC\xB2", 3},
#line 1029 "data/case_folding.gperf"
      {"\352\235\206", "\xEA\x9D\x87", 3},
#line 785 "data/case_folding.gperf"
      {"\341\277\222", "\xCE\xB9\xCC\x88\xCC\x80", 6},
#line 978 "data/case_folding.gperf"
      {"\352\231\206", "\xEA\x99\x87", 3},
#line 525 "data/case_folding.gperf"
      {"\341\202\277", "\xE2\xB4\x9F", 3},
#line 871 "data/case_folding.gperf"
      {"\342\260\213", "\xE2\xB0\xBB", 3},
#line 938 "data/case_folding.gperf"
      {"\342\262\240", "\xE2\xB2\xA1", 3},
#line 884 "data/case_folding.gperf"
      {"\342\260\230", "\xE2\xB1\x88", 3},
#line 255 "data/case_folding.gperf"
      {"\316\224", "\xCE\xB4", 2},
#line 779 "data/case_folding.gperf"
      {"\341\277\207", "\xCE\xB7\xCD\x82\xCE\xB9", 6},
#line 1057 "data/case_folding.gperf"
      {"\352\236\206", "\xEA\x9E\x87", 3},
#line 1013 "data/case_folding.gperf"
      {"\352\234\244", "\xEA\x9C\xA5", 3},
#line 384 "data/case_folding.gperf"
      {"\322\242", "\xD2\xA3", 2},
#line 341 "data/case_folding.gperf"
      {"\320\242", "\xD1\x82", 2},
#line 290 "data/case_folding.gperf"
      {"\317\242", "\xCF\xA3", 2},
#line 821 "data/case_folding.gperf"
      {"\342\205\244", "\xE2\x85\xB4", 3},
#line 464 "data/case_folding.gperf"
      {"\324\272", "\xD5\xAA", 2},
#line 630 "data/case_folding.gperf"
      {"\341\272\274", "\xE1\xBA\xBD", 3},
#line 1091 "data/case_folding.gperf"
      {"\357\274\242", "\xEF\xBD\x82", 3},
#line 383 "data/case_folding.gperf"
      {"\322\240", "\xD2\xA1", 2},
#line 339 "data/case_folding.gperf"
      {"\320\240", "\xD1\x80", 2},
#line 289 "data/case_folding.gperf"
      {"\317\240", "\xCF\xA1", 2},
#line 175 "data/case_folding.gperf"
      {"\307\221", "\xC7\x92", 2},
#line 859 "data/case_folding.gperf"
      {"\342\223\217", "\xE2\x93\xA9", 3},
#line 1010 "data/case_folding.gperf"
      {"\352\232\230", "\xEA\x9A\x99", 3},
#line 186 "data/case_folding.gperf"
      {"\307\250", "\xC7\xA9", 2},
#line 144 "data/case_folding.gperf"
      {"\306\224", "\xC9\xA3", 2},
#line 395 "data/case_folding.gperf"
      {"\322\270", "\xD2\xB9", 2},
#line 660 "data/case_folding.gperf"
      {"\341\273\270", "\xE1\xBB\xB9", 3},
#line 594 "data/case_folding.gperf"
      {"\341\271\270", "\xE1\xB9\xB9", 3},
#line 562 "data/case_folding.gperf"
      {"\341\270\270", "\xE1\xB8\xB9", 3},
#line 769 "data/case_folding.gperf"
      {"\341\276\270", "\xE1\xBE\xB0", 3},
#line 697 "data/case_folding.gperf"
      {"\341\275\213", "\xE1\xBD\x83", 3},
#line 962 "data/case_folding.gperf"
      {"\342\263\220", "\xE2\xB3\x91", 3},
#line 811 "data/case_folding.gperf"
      {"\341\277\273", "\xE1\xBD\xBD", 3},
#line 220 "data/case_folding.gperf"
      {"\310\250", "\xC8\xA9", 2},
#line 855 "data/case_folding.gperf"
      {"\342\223\213", "\xE2\x93\xA5", 3},
#line 1104 "data/case_folding.gperf"
      {"\357\274\257", "\xEF\xBD\x8F", 3},
#line 1180 "data/case_folding.gperf"
      {"\360\221\242\270", "\xF0\x91\xA3\x98", 4},
#line 955 "data/case_folding.gperf"
      {"\342\263\202", "\xE2\xB3\x83", 3},
#line 359 "data/case_folding.gperf"
      {"\321\250", "\xD1\xA9", 2},
#line 157 "data/case_folding.gperf"
      {"\306\254", "\xC6\xAD", 2},
#line 92 "data/case_folding.gperf"
      {"\304\264", "\xC4\xB5", 2},
#line 428 "data/case_folding.gperf"
      {"\323\272", "\xD3\xBB", 2},
#line 601 "data/case_folding.gperf"
      {"\341\272\206", "\xE1\xBA\x87", 3},
#line 1014 "data/case_folding.gperf"
      {"\352\234\246", "\xEA\x9C\xA7", 3},
#line 518 "data/case_folding.gperf"
      {"\341\202\270", "\xE2\xB4\x98", 3},
#line 671 "data/case_folding.gperf"
      {"\341\274\217", "\xE1\xBC\x87", 3},
#line 52 "data/case_folding.gperf"
      {"\303\221", "\xC3\xB1", 2},
#line 934 "data/case_folding.gperf"
      {"\342\262\230", "\xE2\xB2\x99", 3},
#line 183 "data/case_folding.gperf"
      {"\307\242", "\xC7\xA3", 2},
#line 823 "data/case_folding.gperf"
      {"\342\205\246", "\xE2\x85\xB6", 3},
#line 869 "data/case_folding.gperf"
      {"\342\260\211", "\xE2\xB0\xB9", 3},
#line 794 "data/case_folding.gperf"
      {"\341\277\243", "\xCF\x85\xCC\x88\xCC\x81", 6},
#line 877 "data/case_folding.gperf"
      {"\342\260\221", "\xE2\xB1\x81", 3},
#line 1121 "data/case_folding.gperf"
      {"\360\220\220\205", "\xF0\x90\x90\xAD", 4},
#line 493 "data/case_folding.gperf"
      {"\326\207", "\xD5\xA5\xD6\x82", 4},
#line 969 "data/case_folding.gperf"
      {"\342\263\236", "\xE2\xB3\x9F", 3},
#line 182 "data/case_folding.gperf"
      {"\307\240", "\xC7\xA1", 2},
#line 721 "data/case_folding.gperf"
      {"\341\276\205", "\xE1\xBC\x85\xCE\xB9", 5},
#line 217 "data/case_folding.gperf"
      {"\310\242", "\xC8\xA3", 2},
#line 1137 "data/case_folding.gperf"
      {"\360\220\220\225", "\xF0\x90\x90\xBD", 4},
#line 667 "data/case_folding.gperf"
      {"\341\274\213", "\xE1\xBC\x83", 3},
#line 737 "data/case_folding.gperf"
      {"\341\276\225", "\xE1\xBC\xA5\xCE\xB9", 5},
#line 672 "data/case_folding.gperf"
      {"\341\274\230", "\xE1\xBC\x90", 3},
#line 118 "data/case_folding.gperf"
      {"\305\250", "\xC5\xA9", 2},
#line 356 "data/case_folding.gperf"
      {"\321\242", "\xD1\xA3", 2},
#line 216 "data/case_folding.gperf"
      {"\310\240", "\xC6\x9E", 2},
#line 196 "data/case_folding.gperf"
      {"\307\270", "\xC7\xB9", 2},
#line 1093 "data/case_folding.gperf"
      {"\357\274\244", "\xEF\xBD\x84", 3},
#line 921 "data/case_folding.gperf"
      {"\342\261\277", "\xC9\x80", 2},
#line 866 "data/case_folding.gperf"
      {"\342\260\206", "\xE2\xB0\xB6", 3},
#line 1089 "data/case_folding.gperf"
      {"\357\254\227", "\xD5\xB4\xD5\xAD", 4},
#line 158 "data/case_folding.gperf"
      {"\306\256", "\xCA\x88", 2},
#line 355 "data/case_folding.gperf"
      {"\321\240", "\xD1\xA1", 2},
#line 1126 "data/case_folding.gperf"
      {"\360\220\220\212", "\xF0\x90\x90\xB2", 4},
#line 1023 "data/case_folding.gperf"
      {"\352\234\272", "\xEA\x9C\xBB", 3},
#line 637 "data/case_folding.gperf"
      {"\341\273\212", "\xE1\xBB\x8B", 3},
#line 571 "data/case_folding.gperf"
      {"\341\271\212", "\xE1\xB9\x8B", 3},
#line 539 "data/case_folding.gperf"
      {"\341\270\212", "\xE1\xB8\x8B", 3},
#line 726 "data/case_folding.gperf"
      {"\341\276\212", "\xE1\xBC\x82\xCE\xB9", 5},
#line 1031 "data/case_folding.gperf"
      {"\352\235\212", "\xEA\x9D\x8B", 3},
#line 367 "data/case_folding.gperf"
      {"\321\270", "\xD1\xB9", 2},
#line 980 "data/case_folding.gperf"
      {"\352\231\212", "\xEA\x99\x8B", 3},
#line 628 "data/case_folding.gperf"
      {"\341\272\270", "\xE1\xBA\xB9", 3},
#line 77 "data/case_folding.gperf"
      {"\304\226", "\xC4\x97", 2},
#line 695 "data/case_folding.gperf"
      {"\341\275\211", "\xE1\xBD\x81", 3},
#line 96 "data/case_folding.gperf"
      {"\304\275", "\xC4\xBE", 2},
#line 952 "data/case_folding.gperf"
      {"\342\262\274", "\xE2\xB2\xBD", 3},
#line 853 "data/case_folding.gperf"
      {"\342\223\211", "\xE2\x93\xA3", 3},
#line 115 "data/case_folding.gperf"
      {"\305\242", "\xC5\xA3", 2},
#line 1119 "data/case_folding.gperf"
      {"\360\220\220\203", "\xF0\x90\x90\xAB", 4},
#line 1001 "data/case_folding.gperf"
      {"\352\232\206", "\xEA\x9A\x87", 3},
#line 719 "data/case_folding.gperf"
      {"\341\276\203", "\xE1\xBC\x83\xCE\xB9", 5},
#line 114 "data/case_folding.gperf"
      {"\305\240", "\xC5\xA1", 2},
#line 793 "data/case_folding.gperf"
      {"\341\277\242", "\xCF\x85\xCC\x88\xCC\x80", 6},
#line 451 "data/case_folding.gperf"
      {"\324\250", "\xD4\xA9", 2},
#line 397 "data/case_folding.gperf"
      {"\322\274", "\xD2\xBD", 2},
#line 840 "data/case_folding.gperf"
      {"\342\222\274", "\xE2\x93\x96", 3},
#line 967 "data/case_folding.gperf"
      {"\342\263\232", "\xE2\xB3\x9B", 3},
#line 690 "data/case_folding.gperf"
      {"\341\274\274", "\xE1\xBC\xB4", 3},
#line 817 "data/case_folding.gperf"
      {"\342\205\240", "\xE2\x85\xB0", 3},
#line 264 "data/case_folding.gperf"
      {"\316\235", "\xCE\xBD", 2},
#line 1095 "data/case_folding.gperf"
      {"\357\274\246", "\xEF\xBD\x86", 3},
#line 126 "data/case_folding.gperf"
      {"\305\270", "\xC3\xBF", 2},
#line 850 "data/case_folding.gperf"
      {"\342\223\206", "\xE2\x93\xA0", 3},
#line 263 "data/case_folding.gperf"
      {"\316\234", "\xCE\xBC", 2},
#line 1130 "data/case_folding.gperf"
      {"\360\220\220\216", "\xF0\x90\x90\xB6", 4},
#line 639 "data/case_folding.gperf"
      {"\341\273\216", "\xE1\xBB\x8F", 3},
#line 573 "data/case_folding.gperf"
      {"\341\271\216", "\xE1\xB9\x8F", 3},
#line 541 "data/case_folding.gperf"
      {"\341\270\216", "\xE1\xB8\x8F", 3},
#line 730 "data/case_folding.gperf"
      {"\341\276\216", "\xE1\xBC\x86\xCE\xB9", 5},
#line 1033 "data/case_folding.gperf"
      {"\352\235\216", "\xEA\x9D\x8F", 3},
#line 974 "data/case_folding.gperf"
      {"\342\263\262", "\xE2\xB3\xB3", 3},
#line 665 "data/case_folding.gperf"
      {"\341\274\211", "\xE1\xBC\x81", 3},
#line 982 "data/case_folding.gperf"
      {"\352\231\216", "\xEA\x99\x8F", 3},
#line 925 "data/case_folding.gperf"
      {"\342\262\206", "\xE2\xB2\x87", 3},
#line 843 "data/case_folding.gperf"
      {"\342\222\277", "\xE2\x93\x99", 3},
#line 693 "data/case_folding.gperf"
      {"\341\274\277", "\xE1\xBC\xB7", 3},
#line 135 "data/case_folding.gperf"
      {"\306\207", "\xC6\x88", 2},
#line 448 "data/case_folding.gperf"
      {"\324\242", "\xD4\xA3", 2},
#line 956 "data/case_folding.gperf"
      {"\342\263\204", "\xE2\xB3\x85", 3},
#line 1129 "data/case_folding.gperf"
      {"\360\220\220\215", "\xF0\x90\x90\xB5", 4},
#line 419 "data/case_folding.gperf"
      {"\323\250", "\xD3\xA9", 2},
#line 149 "data/case_folding.gperf"
      {"\306\235", "\xC9\xB2", 2},
#line 729 "data/case_folding.gperf"
      {"\341\276\215", "\xE1\xBC\x85\xCE\xB9", 5},
#line 447 "data/case_folding.gperf"
      {"\324\240", "\xD4\xA1", 2},
#line 603 "data/case_folding.gperf"
      {"\341\272\212", "\xE1\xBA\x8B", 3},
#line 148 "data/case_folding.gperf"
      {"\306\234", "\xC9\xAF", 2},
#line 253 "data/case_folding.gperf"
      {"\316\222", "\xCE\xB2", 2},
#line 330 "data/case_folding.gperf"
      {"\320\227", "\xD0\xB7", 2},
#line 865 "data/case_folding.gperf"
      {"\342\260\205", "\xE2\xB0\xB5", 3},
#line 1115 "data/case_folding.gperf"
      {"\357\274\272", "\xEF\xBD\x9A", 3},
#line 198 "data/case_folding.gperf"
      {"\307\274", "\xC7\xBD", 2},
#line 462 "data/case_folding.gperf"
      {"\324\270", "\xD5\xA8", 2},
#line 881 "data/case_folding.gperf"
      {"\342\260\225", "\xE2\xB1\x85", 3},
#line 972 "data/case_folding.gperf"
      {"\342\263\253", "\xE2\xB3\xAC", 3},
#line 1059 "data/case_folding.gperf"
      {"\352\236\215", "\xC9\xA5", 2},
#line 795 "data/case_folding.gperf"
      {"\341\277\244", "\xCF\x81\xCC\x93", 4},
#line 1135 "data/case_folding.gperf"
      {"\360\220\220\223", "\xF0\x90\x90\xBB", 4},
#line 735 "data/case_folding.gperf"
      {"\341\276\223", "\xE1\xBC\xA3\xCE\xB9", 5},
#line 416 "data/case_folding.gperf"
      {"\323\242", "\xD3\xA3", 2},
#line 369 "data/case_folding.gperf"
      {"\321\274", "\xD1\xBD", 2},
#line 531 "data/case_folding.gperf"
      {"\341\203\205", "\xE2\xB4\xA5", 3},
#line 870 "data/case_folding.gperf"
      {"\342\260\212", "\xE2\xB0\xBA", 3},
#line 950 "data/case_folding.gperf"
      {"\342\262\270", "\xE2\xB2\xB9", 3},
#line 415 "data/case_folding.gperf"
      {"\323\240", "\xD3\xA1", 2},
#line 385 "data/case_folding.gperf"
      {"\322\244", "\xD2\xA5", 2},
#line 343 "data/case_folding.gperf"
      {"\320\244", "\xD1\x84", 2},
#line 291 "data/case_folding.gperf"
      {"\317\244", "\xCF\xA5", 2},
#line 605 "data/case_folding.gperf"
      {"\341\272\216", "\xE1\xBA\x8F", 3},
#line 836 "data/case_folding.gperf"
      {"\342\222\270", "\xE2\x93\x92", 3},
#line 427 "data/case_folding.gperf"
      {"\323\270", "\xD3\xB9", 2},
#line 863 "data/case_folding.gperf"
      {"\342\260\203", "\xE2\xB0\xB3", 3},
#line 686 "data/case_folding.gperf"
      {"\341\274\270", "\xE1\xBC\xB0", 3},
#line 849 "data/case_folding.gperf"
      {"\342\223\205", "\xE2\x93\x9F", 3},
#line 964 "data/case_folding.gperf"
      {"\342\263\224", "\xE2\xB3\x95", 3},
#line 178 "data/case_folding.gperf"
      {"\307\227", "\xC7\x98", 2},
#line 1003 "data/case_folding.gperf"
      {"\352\232\212", "\xEA\x9A\x8B", 3},
#line 354 "data/case_folding.gperf"
      {"\320\257", "\xD1\x8F", 2},
#line 388 "data/case_folding.gperf"
      {"\322\252", "\xD2\xAB", 2},
#line 349 "data/case_folding.gperf"
      {"\320\252", "\xD1\x8A", 2},
#line 294 "data/case_folding.gperf"
      {"\317\252", "\xCF\xAB", 2},
#line 796 "data/case_folding.gperf"
      {"\341\277\246", "\xCF\x85\xCD\x82", 4},
#line 1024 "data/case_folding.gperf"
      {"\352\234\274", "\xEA\x9C\xBD", 3},
#line 310 "data/case_folding.gperf"
      {"\320\203", "\xD1\x93", 2},
#line 473 "data/case_folding.gperf"
      {"\325\203", "\xD5\xB3", 2},
#line 874 "data/case_folding.gperf"
      {"\342\260\216", "\xE2\xB0\xBE", 3},
#line 696 "data/case_folding.gperf"
      {"\341\275\212", "\xE1\xBD\x82", 3},
#line 529 "data/case_folding.gperf"
      {"\341\203\203", "\xE2\xB4\xA3", 3},
#line 854 "data/case_folding.gperf"
      {"\342\223\212", "\xE2\x93\xA4", 3},
#line 968 "data/case_folding.gperf"
      {"\342\263\234", "\xE2\xB3\x9D", 3},
#line 784 "data/case_folding.gperf"
      {"\341\277\214", "\xCE\xB7\xCE\xB9", 4},
#line 1116 "data/case_folding.gperf"
      {"\360\220\220\200", "\xF0\x90\x90\xA8", 4},
#line 632 "data/case_folding.gperf"
      {"\341\273\200", "\xE1\xBB\x81", 3},
#line 566 "data/case_folding.gperf"
      {"\341\271\200", "\xE1\xB9\x81", 3},
#line 534 "data/case_folding.gperf"
      {"\341\270\200", "\xE1\xB8\x81", 3},
#line 716 "data/case_folding.gperf"
      {"\341\276\200", "\xE1\xBC\x80\xCE\xB9", 5},
#line 184 "data/case_folding.gperf"
      {"\307\244", "\xC7\xA5", 2},
#line 1026 "data/case_folding.gperf"
      {"\352\235\200", "\xEA\x9D\x81", 3},
#line 1084 "data/case_folding.gperf"
      {"\357\254\206", "\x73\x74", 2},
#line 975 "data/case_folding.gperf"
      {"\352\231\200", "\xEA\x99\x81", 3},
#line 927 "data/case_folding.gperf"
      {"\342\262\212", "\xE2\xB2\x8B", 3},
#line 873 "data/case_folding.gperf"
      {"\342\260\215", "\xE2\xB0\xBD", 3},
#line 847 "data/case_folding.gperf"
      {"\342\223\203", "\xE2\x93\x9D", 3},
#line 218 "data/case_folding.gperf"
      {"\310\244", "\xC8\xA5", 2},
#line 466 "data/case_folding.gperf"
      {"\324\274", "\xD5\xAC", 2},
#line 1005 "data/case_folding.gperf"
      {"\352\232\216", "\xEA\x9A\x8F", 3},
#line 1054 "data/case_folding.gperf"
      {"\352\236\200", "\xEA\x9E\x81", 3},
#line 357 "data/case_folding.gperf"
      {"\321\244", "\xD1\xA5", 2},
#line 810 "data/case_folding.gperf"
      {"\341\277\272", "\xE1\xBD\xBC", 3},
#line 666 "data/case_folding.gperf"
      {"\341\274\212", "\xE1\xBC\x82", 3},
#line 187 "data/case_folding.gperf"
      {"\307\252", "\xC7\xAB", 2},
#line 326 "data/case_folding.gperf"
      {"\320\223", "\xD0\xB3", 2},
#line 489 "data/case_folding.gperf"
      {"\325\223", "\xD6\x83", 2},
#line 788 "data/case_folding.gperf"
      {"\341\277\227", "\xCE\xB9\xCC\x88\xCD\x82", 6},
#line 86 "data/case_folding.gperf"
      {"\304\250", "\xC4\xA9", 2},
#line 858 "data/case_folding.gperf"
      {"\342\223\216", "\xE2\x93\xA8", 3},
#line 533 "data/case_folding.gperf"
      {"\341\203\215", "\xE2\xB4\xAD", 3},
#line 373 "data/case_folding.gperf"
      {"\322\214", "\xD2\x8D", 2},
#line 319 "data/case_folding.gperf"
      {"\320\214", "\xD1\x9C", 2},
#line 879 "data/case_folding.gperf"
      {"\342\260\223", "\xE2\xB1\x83", 3},
#line 482 "data/case_folding.gperf"
      {"\325\214", "\xD5\xBC", 2},
#line 221 "data/case_folding.gperf"
      {"\310\252", "\xC8\xAB", 2},
#line 1124 "data/case_folding.gperf"
      {"\360\220\220\210", "\xF0\x90\x90\xB0", 4},
#line 636 "data/case_folding.gperf"
      {"\341\273\210", "\xE1\xBB\x89", 3},
#line 570 "data/case_folding.gperf"
      {"\341\271\210", "\xE1\xB9\x89", 3},
#line 538 "data/case_folding.gperf"
      {"\341\270\210", "\xE1\xB8\x89", 3},
#line 724 "data/case_folding.gperf"
      {"\341\276\210", "\xE1\xBC\x80\xCE\xB9", 5},
#line 1030 "data/case_folding.gperf"
      {"\352\235\210", "\xEA\x9D\x89", 3},
#line 360 "data/case_folding.gperf"
      {"\321\252", "\xD1\xAB", 2},
#line 979 "data/case_folding.gperf"
      {"\352\231\210", "\xEA\x99\x89", 3},
#line 929 "data/case_folding.gperf"
      {"\342\262\216", "\xE2\xB2\x8F", 3},
#line 116 "data/case_folding.gperf"
      {"\305\244", "\xC5\xA5", 2},
#line 699 "data/case_folding.gperf"
      {"\341\275\215", "\xE1\xBD\x85", 3},
#line 429 "data/case_folding.gperf"
      {"\323\274", "\xD3\xBD", 2},
#line 857 "data/case_folding.gperf"
      {"\342\223\215", "\xE2\x93\xA7", 3},
#line 312 "data/case_folding.gperf"
      {"\320\205", "\xD1\x95", 2},
#line 475 "data/case_folding.gperf"
      {"\325\205", "\xD5\xB5", 2},
#line 973 "data/case_folding.gperf"
      {"\342\263\255", "\xE2\xB3\xAE", 3},
#line 342 "data/case_folding.gperf"
      {"\320\243", "\xD1\x83", 2},
#line 83 "data/case_folding.gperf"
      {"\304\242", "\xC4\xA3", 2},
#line 598 "data/case_folding.gperf"
      {"\341\272\200", "\xE1\xBA\x81", 3},
#line 670 "data/case_folding.gperf"
      {"\341\274\216", "\xE1\xBC\x86", 3},
#line 257 "data/case_folding.gperf"
      {"\316\226", "\xCE\xB6", 2},
#line 38 "data/case_folding.gperf"
      {"\303\203", "\xC3\xA3", 2},
#line 1022 "data/case_folding.gperf"
      {"\352\234\270", "\xEA\x9C\xB9", 3},
#line 82 "data/case_folding.gperf"
      {"\304\240", "\xC4\xA1", 2},
#line 119 "data/case_folding.gperf"
      {"\305\252", "\xC5\xAB", 2},
#line 176 "data/case_folding.gperf"
      {"\307\223", "\xC7\x94", 2},
#line 659 "data/case_folding.gperf"
      {"\341\273\266", "\xE1\xBB\xB7", 3},
#line 593 "data/case_folding.gperf"
      {"\341\271\266", "\xE1\xB9\xB7", 3},
#line 561 "data/case_folding.gperf"
      {"\341\270\266", "\xE1\xB8\xB7", 3},
#line 767 "data/case_folding.gperf"
      {"\341\276\266", "\xCE\xB1\xCD\x82", 4},
#line 99 "data/case_folding.gperf"
      {"\305\203", "\xC5\x84", 2},
#line 1083 "data/case_folding.gperf"
      {"\357\254\205", "\x73\x74", 2},
#line 386 "data/case_folding.gperf"
      {"\322\246", "\xD2\xA7", 2},
#line 345 "data/case_folding.gperf"
      {"\320\246", "\xD1\x86", 2},
#line 292 "data/case_folding.gperf"
      {"\317\246", "\xCF\xA7", 2},
#line 669 "data/case_folding.gperf"
      {"\341\274\215", "\xE1\xBC\x85", 3},
#line 1178 "data/case_folding.gperf"
      {"\360\221\242\266", "\xF0\x91\xA3\x96", 4},
#line 164 "data/case_folding.gperf"
      {"\306\267", "\xCA\x92", 2},
#line 1087 "data/case_folding.gperf"
      {"\357\254\225", "\xD5\xB4\xD5\xAB", 4},
#line 449 "data/case_folding.gperf"
      {"\324\244", "\xD4\xA5", 2},
#line 231 "data/case_folding.gperf"
      {"\311\203", "\xC6\x80", 2},
#line 206 "data/case_folding.gperf"
      {"\310\214", "\xC8\x8D", 2},
#line 860 "data/case_folding.gperf"
      {"\342\260\200", "\xE2\xB0\xB0", 3},
#line 145 "data/case_folding.gperf"
      {"\306\226", "\xC9\xA9", 2},
#line 516 "data/case_folding.gperf"
      {"\341\202\266", "\xE2\xB4\x96", 3},
#line 168 "data/case_folding.gperf"
      {"\307\205", "\xC7\x86", 2},
#line 783 "data/case_folding.gperf"
      {"\341\277\213", "\xE1\xBD\xB5", 3},
#line 602 "data/case_folding.gperf"
      {"\341\272\210", "\xE1\xBA\x89", 3},
#line 789 "data/case_folding.gperf"
      {"\341\277\230", "\xE1\xBF\x90", 3},
#line 54 "data/case_folding.gperf"
      {"\303\223", "\xC3\xB3", 2},
#line 315 "data/case_folding.gperf"
      {"\320\210", "\xD1\x98", 2},
#line 478 "data/case_folding.gperf"
      {"\325\210", "\xD5\xB8", 2},
#line 452 "data/case_folding.gperf"
      {"\324\252", "\xD4\xAB", 2},
#line 47 "data/case_folding.gperf"
      {"\303\214", "\xC3\xAC", 2},
#line 526 "data/case_folding.gperf"
      {"\341\203\200", "\xE2\xB4\xA0", 3},
#line 457 "data/case_folding.gperf"
      {"\324\263", "\xD5\xA3", 2},
#line 998 "data/case_folding.gperf"
      {"\352\232\200", "\xEA\x9A\x81", 3},
#line 1081 "data/case_folding.gperf"
      {"\357\254\203", "\x66\x66\x69", 3},
#line 417 "data/case_folding.gperf"
      {"\323\244", "\xD3\xA5", 2},
#line 104 "data/case_folding.gperf"
      {"\305\214", "\xC5\x8D", 2},
#line 185 "data/case_folding.gperf"
      {"\307\246", "\xC7\xA7", 2},
#line 868 "data/case_folding.gperf"
      {"\342\260\210", "\xE2\xB0\xB8", 3},
#line 40 "data/case_folding.gperf"
      {"\303\205", "\xC3\xA5", 2},
#line 844 "data/case_folding.gperf"
      {"\342\223\200", "\xE2\x93\x9A", 3},
#line 1113 "data/case_folding.gperf"
      {"\357\274\270", "\xEF\xBD\x98", 3},
#line 237 "data/case_folding.gperf"
      {"\311\214", "\xC9\x8D", 2},
#line 219 "data/case_folding.gperf"
      {"\310\246", "\xC8\xA7", 2},
#line 627 "data/case_folding.gperf"
      {"\341\272\266", "\xE1\xBA\xB7", 3},
#line 965 "data/case_folding.gperf"
      {"\342\263\226", "\xE2\xB3\x97", 3},
#line 328 "data/case_folding.gperf"
      {"\320\225", "\xD0\xB5", 2},
#line 283 "data/case_folding.gperf"
      {"\317\225", "\xCF\x86", 2},
#line 491 "data/case_folding.gperf"
      {"\325\225", "\xD6\x85", 2},
#line 338 "data/case_folding.gperf"
      {"\320\237", "\xD0\xBF", 2},
#line 358 "data/case_folding.gperf"
      {"\321\246", "\xD1\xA7", 2},
#line 100 "data/case_folding.gperf"
      {"\305\205", "\xC5\x86", 2},
#line 420 "data/case_folding.gperf"
      {"\323\252", "\xD3\xAB", 2},
#line 922 "data/case_folding.gperf"
      {"\342\262\200", "\xE2\xB2\x81", 3},
#line 812 "data/case_folding.gperf"
      {"\341\277\274", "\xCF\x89\xCE\xB9", 4},
#line 344 "data/case_folding.gperf"
      {"\320\245", "\xD1\x85", 2},
#line 401 "data/case_folding.gperf"
      {"\323\203", "\xD3\x84", 2},
#line 170 "data/case_folding.gperf"
      {"\307\210", "\xC7\x89", 2},
#line 233 "data/case_folding.gperf"
      {"\311\205", "\xCA\x8C", 2},
#line 1002 "data/case_folding.gperf"
      {"\352\232\210", "\xEA\x9A\x89", 3},
#line 781 "data/case_folding.gperf"
      {"\341\277\211", "\xE1\xBD\xB3", 3},
#line 204 "data/case_folding.gperf"
      {"\310\210", "\xC8\x89", 2},
#line 308 "data/case_folding.gperf"
      {"\320\201", "\xD1\x91", 2},
#line 437 "data/case_folding.gperf"
      {"\324\214", "\xD4\x8D", 2},
#line 471 "data/case_folding.gperf"
      {"\325\201", "\xD5\xB1", 2},
#line 306 "data/case_folding.gperf"
      {"\317\277", "\xCD\xBD", 2},
#line 694 "data/case_folding.gperf"
      {"\341\275\210", "\xE1\xBD\x80", 3},
#line 963 "data/case_folding.gperf"
      {"\342\263\222", "\xE2\xB3\x93", 3},
#line 117 "data/case_folding.gperf"
      {"\305\246", "\xC5\xA7", 2},
#line 852 "data/case_folding.gperf"
      {"\342\223\210", "\xE2\x93\xA2", 3},
#line 778 "data/case_folding.gperf"
      {"\341\277\206", "\xCE\xB7\xCD\x82", 4},
#line 177 "data/case_folding.gperf"
      {"\307\225", "\xC7\x96", 2},
#line 43 "data/case_folding.gperf"
      {"\303\210", "\xC3\xA8", 2},
#line 926 "data/case_folding.gperf"
      {"\342\262\210", "\xE2\xB2\x89", 3},
#line 1085 "data/case_folding.gperf"
      {"\357\254\223", "\xD5\xB4\xD5\xB6", 4},
#line 318 "data/case_folding.gperf"
      {"\320\213", "\xD1\x9B", 2},
#line 481 "data/case_folding.gperf"
      {"\325\213", "\xD5\xBB", 2},
#line 664 "data/case_folding.gperf"
      {"\341\274\210", "\xE1\xBC\x80", 3},
#line 235 "data/case_folding.gperf"
      {"\311\210", "\xC9\x89", 2},
#line 450 "data/case_folding.gperf"
      {"\324\246", "\xD4\xA7", 2},
#line 379 "data/case_folding.gperf"
      {"\322\230", "\xD2\x99", 2},
#line 331 "data/case_folding.gperf"
      {"\320\230", "\xD0\xB8", 2},
#line 285 "data/case_folding.gperf"
      {"\317\230", "\xCF\x99", 2},
#line 56 "data/case_folding.gperf"
      {"\303\225", "\xC3\xB5", 2},
#line 402 "data/case_folding.gperf"
      {"\323\205", "\xD3\x86", 2},
#line 252 "data/case_folding.gperf"
      {"\316\221", "\xCE\xB1", 2},
#line 65 "data/case_folding.gperf"
      {"\303\237", "\x73\x73", 2},
#line 949 "data/case_folding.gperf"
      {"\342\262\266", "\xE2\xB2\xB7", 3},
#line 274 "data/case_folding.gperf"
      {"\316\250", "\xCF\x88", 2},
#line 808 "data/case_folding.gperf"
      {"\341\277\270", "\xE1\xBD\xB8", 3},
#line 313 "data/case_folding.gperf"
      {"\320\206", "\xD1\x96", 2},
#line 476 "data/case_folding.gperf"
      {"\325\206", "\xD5\xB6", 2},
#line 84 "data/case_folding.gperf"
      {"\304\244", "\xC4\xA5", 2},
#line 172 "data/case_folding.gperf"
      {"\307\213", "\xC7\x8C", 2},
#line 834 "data/case_folding.gperf"
      {"\342\222\266", "\xE2\x93\x90", 3},
#line 435 "data/case_folding.gperf"
      {"\324\210", "\xD4\x89", 2},
#line 36 "data/case_folding.gperf"
      {"\303\201", "\xC3\xA1", 2},
#line 1078 "data/case_folding.gperf"
      {"\357\254\200", "\x66\x66", 2},
#line 418 "data/case_folding.gperf"
      {"\323\246", "\xD3\xA7", 2},
#line 142 "data/case_folding.gperf"
      {"\306\221", "\xC6\x92", 2},
#line 98 "data/case_folding.gperf"
      {"\305\201", "\xC5\x82", 2},
#line 239 "data/case_folding.gperf"
      {"\315\205", "\xCE\xB9", 2},
#line 130 "data/case_folding.gperf"
      {"\305\277", "\x73", 1},
#line 87 "data/case_folding.gperf"
      {"\304\252", "\xC4\xAB", 2},
#line 340 "data/case_folding.gperf"
      {"\320\241", "\xD1\x81", 2},
#line 267 "data/case_folding.gperf"
      {"\316\240", "\xCF\x80", 2},
#line 230 "data/case_folding.gperf"
      {"\311\201", "\xC9\x82", 2},
#line 46 "data/case_folding.gperf"
      {"\303\213", "\xC3\xAB", 2},
#line 212 "data/case_folding.gperf"
      {"\310\230", "\xC8\x99", 2},
#line 394 "data/case_folding.gperf"
      {"\322\266", "\xD2\xB7", 2},
#line 322 "data/case_folding.gperf"
      {"\320\217", "\xD1\x9F", 2},
#line 280 "data/case_folding.gperf"
      {"\317\217", "\xCF\x97", 2},
#line 485 "data/case_folding.gperf"
      {"\325\217", "\xD5\xBF", 2},
#line 782 "data/case_folding.gperf"
      {"\341\277\212", "\xE1\xBD\xB4", 3},
#line 152 "data/case_folding.gperf"
      {"\306\242", "\xC6\xA3", 2},
#line 203 "data/case_folding.gperf"
      {"\310\206", "\xC8\x87", 2},
#line 971 "data/case_folding.gperf"
      {"\342\263\242", "\xE2\xB3\xA3", 3},
#line 151 "data/case_folding.gperf"
      {"\306\240", "\xC6\xA1", 2},
#line 58 "data/case_folding.gperf"
      {"\303\230", "\xC3\xB8", 2},
#line 469 "data/case_folding.gperf"
      {"\324\277", "\xD5\xAF", 2},
#line 776 "data/case_folding.gperf"
      {"\341\277\203", "\xCE\xB7\xCE\xB9", 4},
#line 165 "data/case_folding.gperf"
      {"\306\270", "\xC6\xB9", 2},
#line 110 "data/case_folding.gperf"
      {"\305\230", "\xC5\x99", 2},
#line 41 "data/case_folding.gperf"
      {"\303\206", "\xC3\xA6", 2},
#line 72 "data/case_folding.gperf"
      {"\304\214", "\xC4\x8D", 2},
#line 372 "data/case_folding.gperf"
      {"\322\212", "\xD2\x8B", 2},
#line 317 "data/case_folding.gperf"
      {"\320\212", "\xD1\x9A", 2},
#line 480 "data/case_folding.gperf"
      {"\325\212", "\xD5\xBA", 2},
#line 194 "data/case_folding.gperf"
      {"\307\266", "\xC6\x95", 2},
#line 174 "data/case_folding.gperf"
      {"\307\217", "\xC7\x90", 2},
#line 374 "data/case_folding.gperf"
      {"\322\216", "\xD2\x8F", 2},
#line 321 "data/case_folding.gperf"
      {"\320\216", "\xD1\x9E", 2},
#line 484 "data/case_folding.gperf"
      {"\325\216", "\xD5\xBE", 2},
#line 400 "data/case_folding.gperf"
      {"\323\201", "\xD3\x82", 2},
#line 234 "data/case_folding.gperf"
      {"\311\206", "\xC9\x87", 2},
#line 366 "data/case_folding.gperf"
      {"\321\266", "\xD1\xB7", 2},
#line 1021 "data/case_folding.gperf"
      {"\352\234\266", "\xEA\x9C\xB7", 3},
#line 443 "data/case_folding.gperf"
      {"\324\230", "\xD4\x99", 2},
#line 50 "data/case_folding.gperf"
      {"\303\217", "\xC3\xAF", 2},
#line 405 "data/case_folding.gperf"
      {"\323\213", "\xD3\x8C", 2},
#line 85 "data/case_folding.gperf"
      {"\304\246", "\xC4\xA7", 2},
#line 171 "data/case_folding.gperf"
      {"\307\212", "\xC7\x8C", 2},
#line 434 "data/case_folding.gperf"
      {"\324\206", "\xD4\x87", 2},
#line 125 "data/case_folding.gperf"
      {"\305\266", "\xC5\xB7", 2},
#line 786 "data/case_folding.gperf"
      {"\341\277\223", "\xCE\xB9\xCC\x88\xCC\x81", 6},
#line 243 "data/case_folding.gperf"
      {"\315\277", "\xCF\xB3", 2},
#line 205 "data/case_folding.gperf"
      {"\310\212", "\xC8\x8B", 2},
#line 207 "data/case_folding.gperf"
      {"\310\216", "\xC8\x8F", 2},
#line 411 "data/case_folding.gperf"
      {"\323\230", "\xD3\x99", 2},
#line 70 "data/case_folding.gperf"
      {"\304\210", "\xC4\x89", 2},
#line 166 "data/case_folding.gperf"
      {"\306\274", "\xC6\xBD", 2},
#line 45 "data/case_folding.gperf"
      {"\303\212", "\xC3\xAA", 2},
#line 833 "data/case_folding.gperf"
      {"\342\206\203", "\xE2\x86\x84", 3},
#line 258 "data/case_folding.gperf"
      {"\316\227", "\xCE\xB7", 2},
#line 49 "data/case_folding.gperf"
      {"\303\216", "\xC3\xAE", 2},
#line 960 "data/case_folding.gperf"
      {"\342\263\214", "\xE2\xB3\x8D", 3},
#line 460 "data/case_folding.gperf"
      {"\324\266", "\xD5\xA6", 2},
#line 1111 "data/case_folding.gperf"
      {"\357\274\266", "\xEF\xBD\x96", 3},
#line 103 "data/case_folding.gperf"
      {"\305\212", "\xC5\x8B", 2},
#line 105 "data/case_folding.gperf"
      {"\305\216", "\xC5\x8F", 2},
#line 316 "data/case_folding.gperf"
      {"\320\211", "\xD1\x99", 2},
#line 479 "data/case_folding.gperf"
      {"\325\211", "\xD5\xB9", 2},
#line 236 "data/case_folding.gperf"
      {"\311\212", "\xC9\x8B", 2},
#line 238 "data/case_folding.gperf"
      {"\311\216", "\xC9\x8F", 2},
#line 146 "data/case_folding.gperf"
      {"\306\227", "\xC9\xA8", 2},
#line 270 "data/case_folding.gperf"
      {"\316\244", "\xCF\x84", 2},
#line 426 "data/case_folding.gperf"
      {"\323\266", "\xD3\xB7", 2},
#line 97 "data/case_folding.gperf"
      {"\304\277", "\xC5\x80", 2},
#line 436 "data/case_folding.gperf"
      {"\324\212", "\xD4\x8B", 2},
#line 970 "data/case_folding.gperf"
      {"\342\263\240", "\xE2\xB3\xA1", 3},
#line 438 "data/case_folding.gperf"
      {"\324\216", "\xD4\x8F", 2},
#line 276 "data/case_folding.gperf"
      {"\316\252", "\xCF\x8A", 2},
#line 153 "data/case_folding.gperf"
      {"\306\244", "\xC6\xA5", 2},
#line 780 "data/case_folding.gperf"
      {"\341\277\210", "\xE1\xBD\xB2", 3},
#line 242 "data/case_folding.gperf"
      {"\315\266", "\xCD\xB7", 2},
#line 159 "data/case_folding.gperf"
      {"\306\257", "\xC6\xB0", 2},
#line 162 "data/case_folding.gperf"
      {"\306\263", "\xC6\xB4", 2},
#line 320 "data/case_folding.gperf"
      {"\320\215", "\xD1\x9D", 2},
#line 483 "data/case_folding.gperf"
      {"\325\215", "\xD5\xBD", 2},
#line 44 "data/case_folding.gperf"
      {"\303\211", "\xC3\xA9", 2},
#line 78 "data/case_folding.gperf"
      {"\304\230", "\xC4\x99", 2},
#line 806 "data/case_folding.gperf"
      {"\341\277\266", "\xCF\x89\xCD\x82", 4},
#line 254 "data/case_folding.gperf"
      {"\316\223", "\xCE\xB3", 2},
#line 102 "data/case_folding.gperf"
      {"\305\211", "\xCA\xBC\x6E", 3},
#line 248 "data/case_folding.gperf"
      {"\316\214", "\xCF\x8C", 2},
#line 69 "data/case_folding.gperf"
      {"\304\206", "\xC4\x87", 2},
#line 966 "data/case_folding.gperf"
      {"\342\263\230", "\xE2\xB3\x99", 3},
#line 143 "data/case_folding.gperf"
      {"\306\223", "\xC9\xA0", 2},
#line 269 "data/case_folding.gperf"
      {"\316\243", "\xCF\x83", 2},
#line 173 "data/case_folding.gperf"
      {"\307\215", "\xC7\x8E", 2},
#line 93 "data/case_folding.gperf"
      {"\304\266", "\xC4\xB7", 2},
#line 272 "data/case_folding.gperf"
      {"\316\246", "\xCF\x86", 2},
#line 48 "data/case_folding.gperf"
      {"\303\215", "\xC3\xAD", 2},
#line 404 "data/case_folding.gperf"
      {"\323\211", "\xD3\x8A", 2},
#line 245 "data/case_folding.gperf"
      {"\316\210", "\xCE\xAD", 2},
#line 154 "data/case_folding.gperf"
      {"\306\246", "\xCA\x80", 2},
#line 957 "data/case_folding.gperf"
      {"\342\263\206", "\xE2\xB3\x87", 3},
#line 71 "data/case_folding.gperf"
      {"\304\212", "\xC4\x8B", 2},
#line 73 "data/case_folding.gperf"
      {"\304\216", "\xC4\x8F", 2},
#line 256 "data/case_folding.gperf"
      {"\316\225", "\xCE\xB5", 2},
#line 266 "data/case_folding.gperf"
      {"\316\237", "\xCE\xBF", 2},
#line 271 "data/case_folding.gperf"
      {"\316\245", "\xCF\x85", 2},
#line 150 "data/case_folding.gperf"
      {"\306\237", "\xC9\xB5", 2},
#line 406 "data/case_folding.gperf"
      {"\323\215", "\xD3\x8E", 2},
#line 371 "data/case_folding.gperf"
      {"\322\200", "\xD2\x81", 2},
#line 307 "data/case_folding.gperf"
      {"\320\200", "\xD1\x90", 2},
#line 470 "data/case_folding.gperf"
      {"\325\200", "\xD5\xB0", 2},
#line 131 "data/case_folding.gperf"
      {"\306\201", "\xC9\x93", 2},
#line 259 "data/case_folding.gperf"
      {"\316\230", "\xCE\xB8", 2},
#line 959 "data/case_folding.gperf"
      {"\342\263\212", "\xE2\xB3\x8B", 3},
#line 138 "data/case_folding.gperf"
      {"\306\213", "\xC6\x8C", 2},
#line 244 "data/case_folding.gperf"
      {"\316\206", "\xCE\xAC", 2},
#line 200 "data/case_folding.gperf"
      {"\310\200", "\xC8\x81", 2},
#line 147 "data/case_folding.gperf"
      {"\306\230", "\xC6\x99", 2},
#line 961 "data/case_folding.gperf"
      {"\342\263\216", "\xE2\xB3\x8F", 3},
#line 134 "data/case_folding.gperf"
      {"\306\206", "\xC9\x94", 2},
#line 268 "data/case_folding.gperf"
      {"\316\241", "\xCF\x81", 2},
#line 35 "data/case_folding.gperf"
      {"\303\200", "\xC3\xA0", 2},
#line 250 "data/case_folding.gperf"
      {"\316\217", "\xCF\x8E", 2},
#line 140 "data/case_folding.gperf"
      {"\306\217", "\xC9\x99", 2},
#line 247 "data/case_folding.gperf"
      {"\316\212", "\xCE\xAF", 2},
#line 431 "data/case_folding.gperf"
      {"\324\200", "\xD4\x81", 2},
#line 249 "data/case_folding.gperf"
      {"\316\216", "\xCF\x8D", 2},
#line 137 "data/case_folding.gperf"
      {"\306\212", "\xC9\x97", 2},
#line 139 "data/case_folding.gperf"
      {"\306\216", "\xC7\x9D", 2},
#line 399 "data/case_folding.gperf"
      {"\323\200", "\xD3\x8F", 2},
#line 954 "data/case_folding.gperf"
      {"\342\263\200", "\xE2\xB3\x81", 3},
#line 958 "data/case_folding.gperf"
      {"\342\263\210", "\xE2\xB3\x89", 3},
#line 246 "data/case_folding.gperf"
      {"\316\211", "\xCE\xAE", 2},
#line 136 "data/case_folding.gperf"
      {"\306\211", "\xC9\x96", 2},
#line 66 "data/case_folding.gperf"
      {"\304\200", "\xC4\x81", 2}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          register const struct case_mapping *resword;

          switch (key - 1)
            {
              case 0:
                if (len == 1)
                  {
                    resword = &wordlist[0];
                    goto compare;
                  }
                break;
              case 2:
                if (len == 1)
                  {
                    resword = &wordlist[1];
                    goto compare;
                  }
                break;
              case 4:
                if (len == 1)
                  {
                    resword = &wordlist[2];
                    goto compare;
                  }
                break;
              case 5:
                if (len == 4)
                  {
                    resword = &wordlist[3];
                    goto compare;
                  }
                break;
              case 6:
                if (len == 1)
                  {
                    resword = &wordlist[4];
                    goto compare;
                  }
                break;
              case 8:
                if (len == 1)
                  {
                    resword = &wordlist[5];
                    goto compare;
                  }
                break;
              case 10:
                if (len == 3)
                  {
                    resword = &wordlist[6];
                    goto compare;
                  }
                break;
              case 12:
                if (len == 1)
                  {
                    resword = &wordlist[7];
                    goto compare;
                  }
                break;
              case 13:
                if (len == 3)
                  {
                    resword = &wordlist[8];
                    goto compare;
                  }
                break;
              case 14:
                if (len == 3)
                  {
                    resword = &wordlist[9];
                    goto compare;
                  }
                break;
              case 15:
                if (len == 3)
                  {
                    resword = &wordlist[10];
                    goto compare;
                  }
                break;
              case 16:
                if (len == 3)
                  {
                    resword = &wordlist[11];
                    goto compare;
                  }
                break;
              case 17:
                if (len == 3)
                  {
                    resword = &wordlist[12];
                    goto compare;
                  }
                break;
              case 18:
                if (len == 3)
                  {
                    resword = &wordlist[13];
                    goto compare;
                  }
                break;
              case 19:
                if (len == 3)
                  {
                    resword = &wordlist[14];
                    goto compare;
                  }
                break;
              case 20:
                if (len == 4)
                  {
                    resword = &wordlist[15];
                    goto compare;
                  }
                break;
              case 22:
                if (len == 3)
                  {
                    resword = &wordlist[16];
                    goto compare;
                  }
                break;
              case 23:
                if (len == 3)
                  {
                    resword = &wordlist[17];
                    goto compare;
                  }
                break;
              case 24:
                if (len == 3)
                  {
                    resword = &wordlist[18];
                    goto compare;
                  }
                break;
              case 25:
                if (len == 3)
                  {
                    resword = &wordlist[19];
                    goto compare;
                  }
                break;
              case 26:
                if (len == 4)
                  {
                    resword = &wordlist[20];
                    goto compare;
                  }
                break;
              case 27:
                if (len == 3)
                  {
                    resword = &wordlist[21];
                    goto compare;
                  }
                break;
              case 28:
                if (len == 1)
                  {
                    resword = &wordlist[22];
                    goto compare;
                  }
                break;
              case 30:
                if (len == 4)
                  {
                    resword = &wordlist[23];
                    goto compare;
                  }
                break;
              case 31:
                if (len == 3)
                  {
                    resword = &wordlist[24];
                    goto compare;
                  }
                break;
              case 32:
                if (len == 4)
                  {
                    resword = &wordlist[25];
                    goto compare;
                  }
                break;
              case 34:
                if (len == 3)
                  {
                    resword = &wordlist[26];
                    goto compare;
                  }
                break;
              case 35:
                if (len == 4)
                  {
                    resword = &wordlist[27];
                    goto compare;
                  }
                break;
              case 36:
                if (len == 1)
                  {
                    resword = &wordlist[28];
                    goto compare;
                  }
                break;
              case 37:
                if (len == 3)
                  {
                    resword = &wordlist[29];
                    goto compare;
                  }
                break;
              case 38:
                if (len == 1)
                  {
                    resword = &wordlist[30];
                    goto compare;
                  }
                break;
              case 39:
                if (len == 2)
                  {
                    resword = &wordlist[31];
                    goto compare;
                  }
                break;
              case 40:
                if (len == 3)
                  {
                    resword = &wordlist[32];
                    goto compare;
                  }
                break;
              case 42:
                if (len == 3)
                  {
                    resword = &wordlist[33];
                    goto compare;
                  }
                break;
              case 44:
                if (len == 3)
                  {
                    resword = &wordlist[34];
                    goto compare;
                  }
                break;
              case 46:
                if (len == 4)
                  {
                    resword = &wordlist[35];
                    goto compare;
                  }
                break;
              case 47:
                if (len == 3)
                  {
                    resword = &wordlist[36];
                    goto compare;
                  }
                break;
              case 48:
                if (len == 1)
                  {
                    resword = &wordlist[37];
                    goto compare;
                  }
                break;
              case 49:
                if (len == 3)
                  {
                    resword = &wordlist[38];
                    goto compare;
                  }
                break;
              case 50:
                if (len == 2)
                  {
                    resword = &wordlist[39];
                    goto compare;
                  }
                break;
              case 51:
                if (len == 2)
                  {
                    resword = &wordlist[40];
                    goto compare;
                  }
                break;
              case 52:
                if (len == 2)
                  {
                    resword = &wordlist[41];
                    goto compare;
                  }
                break;
              case 53:
                if (len == 2)
                  {
                    resword = &wordlist[42];
                    goto compare;
                  }
                break;
              case 54:
                if (len == 4)
                  {
                    resword = &wordlist[43];
                    goto compare;
                  }
                break;
              case 56:
                if (len == 3)
                  {
                    resword = &wordlist[44];
                    goto compare;
                  }
                break;
              case 57:
                if (len == 3)
                  {
                    resword = &wordlist[45];
                    goto compare;
                  }
                break;
              case 58:
                if (len == 3)
                  {
                    resword = &wordlist[46];
                    goto compare;
                  }
                break;
              case 59:
                if (len == 3)
                  {
                    resword = &wordlist[47];
                    goto compare;
                  }
                break;
              case 60:
                if (len == 3)
                  {
                    resword = &wordlist[48];
                    goto compare;
                  }
                break;
              case 61:
                if (len == 3)
                  {
                    resword = &wordlist[49];
                    goto compare;
                  }
                break;
              case 62:
                if (len == 1)
                  {
                    resword = &wordlist[50];
                    goto compare;
                  }
                break;
              case 64:
                if (len == 4)
                  {
                    resword = &wordlist[51];
                    goto compare;
                  }
                break;
              case 65:
                if (len == 3)
                  {
                    resword = &wordlist[52];
                    goto compare;
                  }
                break;
              case 66:
                if (len == 3)
                  {
                    resword = &wordlist[53];
                    goto compare;
                  }
                break;
              case 67:
                if (len == 3)
                  {
                    resword = &wordlist[54];
                    goto compare;
                  }
                break;
              case 68:
                if (len == 3)
                  {
                    resword = &wordlist[55];
                    goto compare;
                  }
                break;
              case 69:
                if (len == 3)
                  {
                    resword = &wordlist[56];
                    goto compare;
                  }
                break;
              case 70:
                if (len == 1)
                  {
                    resword = &wordlist[57];
                    goto compare;
                  }
                break;
              case 71:
                if (len == 3)
                  {
                    resword = &wordlist[58];
                    goto compare;
                  }
                break;
              case 72:
                if (len == 1)
                  {
                    resword = &wordlist[59];
                    goto compare;
                  }
                break;
              case 74:
                if (len == 2)
                  {
                    resword = &wordlist[60];
                    goto compare;
                  }
                break;
              case 75:
                if (len == 3)
                  {
                    resword = &wordlist[61];
                    goto compare;
                  }
                break;
              case 76:
                if (len == 2)
                  {
                    resword = &wordlist[62];
                    goto compare;
                  }
                break;
              case 78:
                if (len == 1)
                  {
                    resword = &wordlist[63];
                    goto compare;
                  }
                break;
              case 80:
                if (len == 1)
                  {
                    resword = &wordlist[64];
                    goto compare;
                  }
                break;
              case 81:
                if (len == 3)
                  {
                    resword = &wordlist[65];
                    goto compare;
                  }
                break;
              case 82:
                if (len == 1)
                  {
                    resword = &wordlist[66];
                    goto compare;
                  }
                break;
              case 84:
                if (len == 2)
                  {
                    resword = &wordlist[67];
                    goto compare;
                  }
                break;
              case 86:
                if (len == 2)
                  {
                    resword = &wordlist[68];
                    goto compare;
                  }
                break;
              case 88:
                if (len == 2)
                  {
                    resword = &wordlist[69];
                    goto compare;
                  }
                break;
              case 89:
                if (len == 2)
                  {
                    resword = &wordlist[70];
                    goto compare;
                  }
                break;
              case 90:
                if (len == 2)
                  {
                    resword = &wordlist[71];
                    goto compare;
                  }
                break;
              case 91:
                if (len == 3)
                  {
                    resword = &wordlist[72];
                    goto compare;
                  }
                break;
              case 92:
                if (len == 4)
                  {
                    resword = &wordlist[73];
                    goto compare;
                  }
                break;
              case 94:
                if (len == 3)
                  {
                    resword = &wordlist[74];
                    goto compare;
                  }
                break;
              case 95:
                if (len == 3)
                  {
                    resword = &wordlist[75];
                    goto compare;
                  }
                break;
              case 96:
                if (len == 3)
                  {
                    resword = &wordlist[76];
                    goto compare;
                  }
                break;
              case 97:
                if (len == 3)
                  {
                    resword = &wordlist[77];
                    goto compare;
                  }
                break;
              case 98:
                if (len == 1)
                  {
                    resword = &wordlist[78];
                    goto compare;
                  }
                break;
              case 99:
                if (len == 3)
                  {
                    resword = &wordlist[79];
                    goto compare;
                  }
                break;
              case 100:
                if (len == 3)
                  {
                    resword = &wordlist[80];
                    goto compare;
                  }
                break;
              case 101:
                if (len == 2)
                  {
                    resword = &wordlist[81];
                    goto compare;
                  }
                break;
              case 102:
                if (len == 1)
                  {
                    resword = &wordlist[82];
                    goto compare;
                  }
                break;
              case 103:
                if (len == 3)
                  {
                    resword = &wordlist[83];
                    goto compare;
                  }
                break;
              case 104:
                if (len == 3)
                  {
                    resword = &wordlist[84];
                    goto compare;
                  }
                break;
              case 105:
                if (len == 4)
                  {
                    resword = &wordlist[85];
                    goto compare;
                  }
                break;
              case 106:
                if (len == 1)
                  {
                    resword = &wordlist[86];
                    goto compare;
                  }
                break;
              case 108:
                if (len == 1)
                  {
                    resword = &wordlist[87];
                    goto compare;
                  }
                break;
              case 109:
                if (len == 3)
                  {
                    resword = &wordlist[88];
                    goto compare;
                  }
                break;
              case 110:
                if (len == 3)
                  {
                    resword = &wordlist[89];
                    goto compare;
                  }
                break;
              case 112:
                if (len == 1)
                  {
                    resword = &wordlist[90];
                    goto compare;
                  }
                break;
              case 114:
                if (len == 2)
                  {
                    resword = &wordlist[91];
                    goto compare;
                  }
                break;
              case 115:
                if (len == 2)
                  {
                    resword = &wordlist[92];
                    goto compare;
                  }
                break;
              case 116:
                if (len == 2)
                  {
                    resword = &wordlist[93];
                    goto compare;
                  }
                break;
              case 118:
                if (len == 2)
                  {
                    resword = &wordlist[94];
                    goto compare;
                  }
                break;
              case 119:
                if (len == 3)
                  {
                    resword = &wordlist[95];
                    goto compare;
                  }
                break;
              case 120:
                if (len == 2)
                  {
                    resword = &wordlist[96];
                    goto compare;
                  }
                break;
              case 121:
                if (len == 3)
                  {
                    resword = &wordlist[97];
                    goto compare;
                  }
                break;
              case 122:
                if (len == 2)
                  {
                    resword = &wordlist[98];
                    goto compare;
                  }
                break;
              case 123:
                if (len == 3)
                  {
                    resword = &wordlist[99];
                    goto compare;
                  }
                break;
              case 124:
                if (len == 3)
                  {
                    resword = &wordlist[100];
                    goto compare;
                  }
                break;
              case 125:
                if (len == 3)
                  {
                    resword = &wordlist[101];
                    goto compare;
                  }
                break;
              case 126:
                if (len == 3)
                  {
                    resword = &wordlist[102];
                    goto compare;
                  }
                break;
              case 127:
                if (len == 2)
                  {
                    resword = &wordlist[103];
                    goto compare;
                  }
                break;
              case 128:
                if (len == 3)
                  {
                    resword = &wordlist[104];
                    goto compare;
                  }
                break;
              case 129:
                if (len == 3)
                  {
                    resword = &wordlist[105];
                    goto compare;
                  }
                break;
              case 130:
                if (len == 3)
                  {
                    resword = &wordlist[106];
                    goto compare;
                  }
                break;
              case 131:
                if (len == 3)
                  {
                    resword = &wordlist[107];
                    goto compare;
                  }
                break;
              case 132:
                if (len == 3)
                  {
                    resword = &wordlist[108];
                    goto compare;
                  }
                break;
              case 133:
                if (len == 3)
                  {
                    resword = &wordlist[109];
                    goto compare;
                  }
                break;
              case 134:
                if (len == 3)
                  {
                    resword = &wordlist[110];
                    goto compare;
                  }
                break;
              case 136:
                if (len == 4)
                  {
                    resword = &wordlist[111];
                    goto compare;
                  }
                break;
              case 137:
                if (len == 2)
                  {
                    resword = &wordlist[112];
                    goto compare;
                  }
                break;
              case 138:
                if (len == 3)
                  {
                    resword = &wordlist[113];
                    goto compare;
                  }
                break;
              case 140:
                if (len == 1)
                  {
                    resword = &wordlist[114];
                    goto compare;
                  }
                break;
              case 142:
                if (len == 4)
                  {
                    resword = &wordlist[115];
                    goto compare;
                  }
                break;
              case 143:
                if (len == 3)
                  {
                    resword = &wordlist[116];
                    goto compare;
                  }
                break;
              case 144:
                if (len == 1)
                  {
                    resword = &wordlist[117];
                    goto compare;
                  }
                break;
              case 146:
                if (len == 2)
                  {
                    resword = &wordlist[118];
                    goto compare;
                  }
                break;
              case 147:
                if (len == 3)
                  {
                    resword = &wordlist[119];
                    goto compare;
                  }
                break;
              case 148:
                if (len == 3)
                  {
                    resword = &wordlist[120];
                    goto compare;
                  }
                break;
              case 150:
                if (len == 3)
                  {
                    resword = &wordlist[121];
                    goto compare;
                  }
                break;
              case 151:
                if (len == 2)
                  {
                    resword = &wordlist[122];
                    goto compare;
                  }
                break;
              case 152:
                if (len == 1)
                  {
                    resword = &wordlist[123];
                    goto compare;
                  }
                break;
              case 153:
                if (len == 3)
                  {
                    resword = &wordlist[124];
                    goto compare;
                  }
                break;
              case 154:
                if (len == 3)
                  {
                    resword = &wordlist[125];
                    goto compare;
                  }
                break;
              case 156:
                if (len == 3)
                  {
                    resword = &wordlist[126];
                    goto compare;
                  }
                break;
              case 157:
                if (len == 3)
                  {
                    resword = &wordlist[127];
                    goto compare;
                  }
                break;
              case 158:
                if (len == 2)
                  {
                    resword = &wordlist[128];
                    goto compare;
                  }
                break;
              case 160:
                if (len == 3)
                  {
                    resword = &wordlist[129];
                    goto compare;
                  }
                break;
              case 161:
                if (len == 2)
                  {
                    resword = &wordlist[130];
                    goto compare;
                  }
                break;
              case 162:
                if (len == 1)
                  {
                    resword = &wordlist[131];
                    goto compare;
                  }
                break;
              case 163:
                if (len == 4)
                  {
                    resword = &wordlist[132];
                    goto compare;
                  }
                break;
              case 164:
                if (len == 2)
                  {
                    resword = &wordlist[133];
                    goto compare;
                  }
                break;
              case 165:
                if (len == 3)
                  {
                    resword = &wordlist[134];
                    goto compare;
                  }
                break;
              case 166:
                if (len == 3)
                  {
                    resword = &wordlist[135];
                    goto compare;
                  }
                break;
              case 167:
                if (len == 3)
                  {
                    resword = &wordlist[136];
                    goto compare;
                  }
                break;
              case 168:
                if (len == 3)
                  {
                    resword = &wordlist[137];
                    goto compare;
                  }
                break;
              case 169:
                if (len == 3)
                  {
                    resword = &wordlist[138];
                    goto compare;
                  }
                break;
              case 170:
                if (len == 3)
                  {
                    resword = &wordlist[139];
                    goto compare;
                  }
                break;
              case 172:
                if (len == 1)
                  {
                    resword = &wordlist[140];
                    goto compare;
                  }
                break;
              case 173:
                if (len == 3)
                  {
                    resword = &wordlist[141];
                    goto compare;
                  }
                break;
              case 174:
                if (len == 3)
                  {
                    resword = &wordlist[142];
                    goto compare;
                  }
                break;
              case 175:
                if (len == 4)
                  {
                    resword = &wordlist[143];
                    goto compare;
                  }
                break;
              case 176:
                if (len == 2)
                  {
                    resword = &wordlist[144];
                    goto compare;
                  }
                break;
              case 177:
                if (len == 2)
                  {
                    resword = &wordlist[145];
                    goto compare;
                  }
                break;
              case 179:
                if (len == 4)
                  {
                    resword = &wordlist[146];
                    goto compare;
                  }
                break;
              case 180:
                if (len == 3)
                  {
                    resword = &wordlist[147];
                    goto compare;
                  }
                break;
              case 181:
                if (len == 3)
                  {
                    resword = &wordlist[148];
                    goto compare;
                  }
                break;
              case 182:
                if (len == 3)
                  {
                    resword = &wordlist[149];
                    goto compare;
                  }
                break;
              case 183:
                if (len == 2)
                  {
                    resword = &wordlist[150];
                    goto compare;
                  }
                break;
              case 184:
                if (len == 4)
                  {
                    resword = &wordlist[151];
                    goto compare;
                  }
                break;
              case 186:
                if (len == 3)
                  {
                    resword = &wordlist[152];
                    goto compare;
                  }
                break;
              case 187:
                if (len == 3)
                  {
                    resword = &wordlist[153];
                    goto compare;
                  }
                break;
              case 188:
                if (len == 3)
                  {
                    resword = &wordlist[154];
                    goto compare;
                  }
                break;
              case 189:
                if (len == 3)
                  {
                    resword = &wordlist[155];
                    goto compare;
                  }
                break;
              case 190:
                if (len == 3)
                  {
                    resword = &wordlist[156];
                    goto compare;
                  }
                break;
              case 191:
                if (len == 2)
                  {
                    resword = &wordlist[157];
                    goto compare;
                  }
                break;
              case 192:
                if (len == 3)
                  {
                    resword = &wordlist[158];
                    goto compare;
                  }
                break;
              case 193:
                if (len == 3)
                  {
                    resword = &wordlist[159];
                    goto compare;
                  }
                break;
              case 195:
                if (len == 2)
                  {
                    resword = &wordlist[160];
                    goto compare;
                  }
                break;
              case 196:
                if (len == 3)
                  {
                    resword = &wordlist[161];
                    goto compare;
                  }
                break;
              case 197:
                if (len == 2)
                  {
                    resword = &wordlist[162];
                    goto compare;
                  }
                break;
              case 198:
                if (len == 3)
                  {
                    resword = &wordlist[163];
                    goto compare;
                  }
                break;
              case 199:
                if (len == 4)
                  {
                    resword = &wordlist[164];
                    goto compare;
                  }
                break;
              case 200:
                if (len == 2)
                  {
                    resword = &wordlist[165];
                    goto compare;
                  }
                break;
              case 201:
                if (len == 4)
                  {
                    resword = &wordlist[166];
                    goto compare;
                  }
                break;
              case 202:
                if (len == 3)
                  {
                    resword = &wordlist[167];
                    goto compare;
                  }
                break;
              case 203:
                if (len == 3)
                  {
                    resword = &wordlist[168];
                    goto compare;
                  }
                break;
              case 204:
                if (len == 3)
                  {
                    resword = &wordlist[169];
                    goto compare;
                  }
                break;
              case 205:
                if (len == 3)
                  {
                    resword = &wordlist[170];
                    goto compare;
                  }
                break;
              case 206:
                if (len == 3)
                  {
                    resword = &wordlist[171];
                    goto compare;
                  }
                break;
              case 207:
                if (len == 2)
                  {
                    resword = &wordlist[172];
                    goto compare;
                  }
                break;
              case 208:
                if (len == 3)
                  {
                    resword = &wordlist[173];
                    goto compare;
                  }
                break;
              case 210:
                if (len == 3)
                  {
                    resword = &wordlist[174];
                    goto compare;
                  }
                break;
              case 212:
                if (len == 3)
                  {
                    resword = &wordlist[175];
                    goto compare;
                  }
                break;
              case 213:
                if (len == 3)
                  {
                    resword = &wordlist[176];
                    goto compare;
                  }
                break;
              case 214:
                if (len == 3)
                  {
                    resword = &wordlist[177];
                    goto compare;
                  }
                break;
              case 216:
                if (len == 3)
                  {
                    resword = &wordlist[178];
                    goto compare;
                  }
                break;
              case 217:
                if (len == 3)
                  {
                    resword = &wordlist[179];
                    goto compare;
                  }
                break;
              case 218:
                if (len == 2)
                  {
                    resword = &wordlist[180];
                    goto compare;
                  }
                break;
              case 219:
                if (len == 3)
                  {
                    resword = &wordlist[181];
                    goto compare;
                  }
                break;
              case 220:
                if (len == 3)
                  {
                    resword = &wordlist[182];
                    goto compare;
                  }
                break;
              case 221:
                if (len == 3)
                  {
                    resword = &wordlist[183];
                    goto compare;
                  }
                break;
              case 222:
                if (len == 2)
                  {
                    resword = &wordlist[184];
                    goto compare;
                  }
                break;
              case 224:
                if (len == 3)
                  {
                    resword = &wordlist[185];
                    goto compare;
                  }
                break;
              case 226:
                if (len == 3)
                  {
                    resword = &wordlist[186];
                    goto compare;
                  }
                break;
              case 228:
                if (len == 3)
                  {
                    resword = &wordlist[187];
                    goto compare;
                  }
                break;
              case 229:
                if (len == 3)
                  {
                    resword = &wordlist[188];
                    goto compare;
                  }
                break;
              case 230:
                if (len == 2)
                  {
                    resword = &wordlist[189];
                    goto compare;
                  }
                break;
              case 231:
                if (len == 2)
                  {
                    resword = &wordlist[190];
                    goto compare;
                  }
                break;
              case 233:
                if (len == 3)
                  {
                    resword = &wordlist[191];
                    goto compare;
                  }
                break;
              case 235:
                if (len == 3)
                  {
                    resword = &wordlist[192];
                    goto compare;
                  }
                break;
              case 236:
                if (len == 3)
                  {
                    resword = &wordlist[193];
                    goto compare;
                  }
                break;
              case 240:
                if (len == 2)
                  {
                    resword = &wordlist[194];
                    goto compare;
                  }
                break;
              case 244:
                if (len == 2)
                  {
                    resword = &wordlist[195];
                    goto compare;
                  }
                break;
              case 245:
                if (len == 4)
                  {
                    resword = &wordlist[196];
                    goto compare;
                  }
                break;
              case 248:
                if (len == 3)
                  {
                    resword = &wordlist[197];
                    goto compare;
                  }
                break;
              case 249:
                if (len == 3)
                  {
                    resword = &wordlist[198];
                    goto compare;
                  }
                break;
              case 251:
                if (len == 3)
                  {
                    resword = &wordlist[199];
                    goto compare;
                  }
                break;
              case 252:
                if (len == 3)
                  {
                    resword = &wordlist[200];
                    goto compare;
                  }
                break;
              case 255:
                if (len == 3)
                  {
                    resword = &wordlist[201];
                    goto compare;
                  }
                break;
              case 257:
                if (len == 3)
                  {
                    resword = &wordlist[202];
                    goto compare;
                  }
                break;
              case 258:
                if (len == 4)
                  {
                    resword = &wordlist[203];
                    goto compare;
                  }
                break;
              case 259:
                if (len == 3)
                  {
                    resword = &wordlist[204];
                    goto compare;
                  }
                break;
              case 260:
                if (len == 3)
                  {
                    resword = &wordlist[205];
                    goto compare;
                  }
                break;
              case 261:
                if (len == 3)
                  {
                    resword = &wordlist[206];
                    goto compare;
                  }
                break;
              case 262:
                if (len == 2)
                  {
                    resword = &wordlist[207];
                    goto compare;
                  }
                break;
              case 263:
                if (len == 3)
                  {
                    resword = &wordlist[208];
                    goto compare;
                  }
                break;
              case 264:
                if (len == 3)
                  {
                    resword = &wordlist[209];
                    goto compare;
                  }
                break;
              case 267:
                if (len == 2)
                  {
                    resword = &wordlist[210];
                    goto compare;
                  }
                break;
              case 270:
                if (len == 3)
                  {
                    resword = &wordlist[211];
                    goto compare;
                  }
                break;
              case 272:
                if (len == 3)
                  {
                    resword = &wordlist[212];
                    goto compare;
                  }
                break;
              case 273:
                if (len == 3)
                  {
                    resword = &wordlist[213];
                    goto compare;
                  }
                break;
              case 277:
                if (len == 2)
                  {
                    resword = &wordlist[214];
                    goto compare;
                  }
                break;
              case 278:
                if (len == 4)
                  {
                    resword = &wordlist[215];
                    goto compare;
                  }
                break;
              case 280:
                if (len == 3)
                  {
                    resword = &wordlist[216];
                    goto compare;
                  }
                break;
              case 281:
                if (len == 3)
                  {
                    resword = &wordlist[217];
                    goto compare;
                  }
                break;
              case 282:
                if (len == 3)
                  {
                    resword = &wordlist[218];
                    goto compare;
                  }
                break;
              case 283:
                if (len == 3)
                  {
                    resword = &wordlist[219];
                    goto compare;
                  }
                break;
              case 285:
                if (len == 3)
                  {
                    resword = &wordlist[220];
                    goto compare;
                  }
                break;
              case 287:
                if (len == 3)
                  {
                    resword = &wordlist[221];
                    goto compare;
                  }
                break;
              case 289:
                if (len == 3)
                  {
                    resword = &wordlist[222];
                    goto compare;
                  }
                break;
              case 290:
                if (len == 3)
                  {
                    resword = &wordlist[223];
                    goto compare;
                  }
                break;
              case 291:
                if (len == 3)
                  {
                    resword = &wordlist[224];
                    goto compare;
                  }
                break;
              case 292:
                if (len == 3)
                  {
                    resword = &wordlist[225];
                    goto compare;
                  }
                break;
              case 294:
                if (len == 2)
                  {
                    resword = &wordlist[226];
                    goto compare;
                  }
                break;
              case 298:
                if (len == 3)
                  {
                    resword = &wordlist[227];
                    goto compare;
                  }
                break;
              case 300:
                if (len == 2)
                  {
                    resword = &wordlist[228];
                    goto compare;
                  }
                break;
              case 301:
                if (len == 2)
                  {
                    resword = &wordlist[229];
                    goto compare;
                  }
                break;
              case 303:
                if (len == 3)
                  {
                    resword = &wordlist[230];
                    goto compare;
                  }
                break;
              case 305:
                if (len == 2)
                  {
                    resword = &wordlist[231];
                    goto compare;
                  }
                break;
              case 306:
                if (len == 3)
                  {
                    resword = &wordlist[232];
                    goto compare;
                  }
                break;
              case 309:
                if (len == 3)
                  {
                    resword = &wordlist[233];
                    goto compare;
                  }
                break;
              case 311:
                if (len == 4)
                  {
                    resword = &wordlist[234];
                    goto compare;
                  }
                break;
              case 313:
                if (len == 3)
                  {
                    resword = &wordlist[235];
                    goto compare;
                  }
                break;
              case 314:
                if (len == 3)
                  {
                    resword = &wordlist[236];
                    goto compare;
                  }
                break;
              case 315:
                if (len == 3)
                  {
                    resword = &wordlist[237];
                    goto compare;
                  }
                break;
              case 316:
                if (len == 3)
                  {
                    resword = &wordlist[238];
                    goto compare;
                  }
                break;
              case 318:
                if (len == 3)
                  {
                    resword = &wordlist[239];
                    goto compare;
                  }
                break;
              case 321:
                if (len == 2)
                  {
                    resword = &wordlist[240];
                    goto compare;
                  }
                break;
              case 322:
                if (len == 3)
                  {
                    resword = &wordlist[241];
                    goto compare;
                  }
                break;
              case 323:
                if (len == 2)
                  {
                    resword = &wordlist[242];
                    goto compare;
                  }
                break;
              case 324:
                if (len == 2)
                  {
                    resword = &wordlist[243];
                    goto compare;
                  }
                break;
              case 325:
                if (len == 2)
                  {
                    resword = &wordlist[244];
                    goto compare;
                  }
                break;
              case 326:
                if (len == 3)
                  {
                    resword = &wordlist[245];
                    goto compare;
                  }
                break;
              case 327:
                if (len == 3)
                  {
                    resword = &wordlist[246];
                    goto compare;
                  }
                break;
              case 328:
                if (len == 3)
                  {
                    resword = &wordlist[247];
                    goto compare;
                  }
                break;
              case 329:
                if (len == 3)
                  {
                    resword = &wordlist[248];
                    goto compare;
                  }
                break;
              case 333:
                if (len == 3)
                  {
                    resword = &wordlist[249];
                    goto compare;
                  }
                break;
              case 338:
                if (len == 3)
                  {
                    resword = &wordlist[250];
                    goto compare;
                  }
                break;
              case 341:
                if (len == 2)
                  {
                    resword = &wordlist[251];
                    goto compare;
                  }
                break;
              case 345:
                if (len == 3)
                  {
                    resword = &wordlist[252];
                    goto compare;
                  }
                break;
              case 346:
                if (len == 3)
                  {
                    resword = &wordlist[253];
                    goto compare;
                  }
                break;
              case 347:
                if (len == 2)
                  {
                    resword = &wordlist[254];
                    goto compare;
                  }
                break;
              case 350:
                if (len == 3)
                  {
                    resword = &wordlist[255];
                    goto compare;
                  }
                break;
              case 351:
                if (len == 2)
                  {
                    resword = &wordlist[256];
                    goto compare;
                  }
                break;
              case 352:
                if (len == 2)
                  {
                    resword = &wordlist[257];
                    goto compare;
                  }
                break;
              case 356:
                if (len == 3)
                  {
                    resword = &wordlist[258];
                    goto compare;
                  }
                break;
              case 357:
                if (len == 3)
                  {
                    resword = &wordlist[259];
                    goto compare;
                  }
                break;
              case 358:
                if (len == 3)
                  {
                    resword = &wordlist[260];
                    goto compare;
                  }
                break;
              case 361:
                if (len == 3)
                  {
                    resword = &wordlist[261];
                    goto compare;
                  }
                break;
              case 362:
                if (len == 3)
                  {
                    resword = &wordlist[262];
                    goto compare;
                  }
                break;
              case 366:
                if (len == 3)
                  {
                    resword = &wordlist[263];
                    goto compare;
                  }
                break;
              case 367:
                if (len == 3)
                  {
                    resword = &wordlist[264];
                    goto compare;
                  }
                break;
              case 368:
                if (len == 2)
                  {
                    resword = &wordlist[265];
                    goto compare;
                  }
                break;
              case 369:
                if (len == 3)
                  {
                    resword = &wordlist[266];
                    goto compare;
                  }
                break;
              case 370:
                if (len == 2)
                  {
                    resword = &wordlist[267];
                    goto compare;
                  }
                break;
              case 371:
                if (len == 3)
                  {
                    resword = &wordlist[268];
                    goto compare;
                  }
                break;
              case 372:
                if (len == 3)
                  {
                    resword = &wordlist[269];
                    goto compare;
                  }
                break;
              case 373:
                if (len == 3)
                  {
                    resword = &wordlist[270];
                    goto compare;
                  }
                break;
              case 376:
                if (len == 3)
                  {
                    resword = &wordlist[271];
                    goto compare;
                  }
                break;
              case 381:
                if (len == 4)
                  {
                    resword = &wordlist[272];
                    goto compare;
                  }
                break;
              case 382:
                if (len == 3)
                  {
                    resword = &wordlist[273];
                    goto compare;
                  }
                break;
              case 384:
                if (len == 2)
                  {
                    resword = &wordlist[274];
                    goto compare;
                  }
                break;
              case 388:
                if (len == 3)
                  {
                    resword = &wordlist[275];
                    goto compare;
                  }
                break;
              case 390:
                if (len == 3)
                  {
                    resword = &wordlist[276];
                    goto compare;
                  }
                break;
              case 391:
                if (len == 3)
                  {
                    resword = &wordlist[277];
                    goto compare;
                  }
                break;
              case 392:
                if (len == 3)
                  {
                    resword = &wordlist[278];
                    goto compare;
                  }
                break;
              case 393:
                if (len == 3)
                  {
                    resword = &wordlist[279];
                    goto compare;
                  }
                break;
              case 395:
                if (len == 3)
                  {
                    resword = &wordlist[280];
                    goto compare;
                  }
                break;
              case 398:
                if (len == 2)
                  {
                    resword = &wordlist[281];
                    goto compare;
                  }
                break;
              case 400:
                if (len == 2)
                  {
                    resword = &wordlist[282];
                    goto compare;
                  }
                break;
              case 402:
                if (len == 3)
                  {
                    resword = &wordlist[283];
                    goto compare;
                  }
                break;
              case 404:
                if (len == 3)
                  {
                    resword = &wordlist[284];
                    goto compare;
                  }
                break;
              case 405:
                if (len == 3)
                  {
                    resword = &wordlist[285];
                    goto compare;
                  }
                break;
              case 406:
                if (len == 3)
                  {
                    resword = &wordlist[286];
                    goto compare;
                  }
                break;
              case 407:
                if (len == 3)
                  {
                    resword = &wordlist[287];
                    goto compare;
                  }
                break;
              case 408:
                if (len == 2)
                  {
                    resword = &wordlist[288];
                    goto compare;
                  }
                break;
              case 412:
                if (len == 3)
                  {
                    resword = &wordlist[289];
                    goto compare;
                  }
                break;
              case 413:
                if (len == 2)
                  {
                    resword = &wordlist[290];
                    goto compare;
                  }
                break;
              case 415:
                if (len == 4)
                  {
                    resword = &wordlist[291];
                    goto compare;
                  }
                break;
              case 419:
                if (len == 3)
                  {
                    resword = &wordlist[292];
                    goto compare;
                  }
                break;
              case 422:
                if (len == 2)
                  {
                    resword = &wordlist[293];
                    goto compare;
                  }
                break;
              case 423:
                if (len == 3)
                  {
                    resword = &wordlist[294];
                    goto compare;
                  }
                break;
              case 424:
                if (len == 3)
                  {
                    resword = &wordlist[295];
                    goto compare;
                  }
                break;
              case 425:
                if (len == 3)
                  {
                    resword = &wordlist[296];
                    goto compare;
                  }
                break;
              case 426:
                if (len == 3)
                  {
                    resword = &wordlist[297];
                    goto compare;
                  }
                break;
              case 427:
                if (len == 3)
                  {
                    resword = &wordlist[298];
                    goto compare;
                  }
                break;
              case 428:
                if (len == 3)
                  {
                    resword = &wordlist[299];
                    goto compare;
                  }
                break;
              case 429:
                if (len == 3)
                  {
                    resword = &wordlist[300];
                    goto compare;
                  }
                break;
              case 430:
                if (len == 2)
                  {
                    resword = &wordlist[301];
                    goto compare;
                  }
                break;
              case 431:
                if (len == 2)
                  {
                    resword = &wordlist[302];
                    goto compare;
                  }
                break;
              case 432:
                if (len == 3)
                  {
                    resword = &wordlist[303];
                    goto compare;
                  }
                break;
              case 433:
                if (len == 2)
                  {
                    resword = &wordlist[304];
                    goto compare;
                  }
                break;
              case 436:
                if (len == 4)
                  {
                    resword = &wordlist[305];
                    goto compare;
                  }
                break;
              case 439:
                if (len == 3)
                  {
                    resword = &wordlist[306];
                    goto compare;
                  }
                break;
              case 443:
                if (len == 3)
                  {
                    resword = &wordlist[307];
                    goto compare;
                  }
                break;
              case 444:
                if (len == 2)
                  {
                    resword = &wordlist[308];
                    goto compare;
                  }
                break;
              case 447:
                if (len == 2)
                  {
                    resword = &wordlist[309];
                    goto compare;
                  }
                break;
              case 448:
                if (len == 3)
                  {
                    resword = &wordlist[310];
                    goto compare;
                  }
                break;
              case 449:
                if (len == 2)
                  {
                    resword = &wordlist[311];
                    goto compare;
                  }
                break;
              case 450:
                if (len == 3)
                  {
                    resword = &wordlist[312];
                    goto compare;
                  }
                break;
              case 451:
                if (len == 3)
                  {
                    resword = &wordlist[313];
                    goto compare;
                  }
                break;
              case 452:
                if (len == 3)
                  {
                    resword = &wordlist[314];
                    goto compare;
                  }
                break;
              case 453:
                if (len == 3)
                  {
                    resword = &wordlist[315];
                    goto compare;
                  }
                break;
              case 454:
                if (len == 3)
                  {
                    resword = &wordlist[316];
                    goto compare;
                  }
                break;
              case 455:
                if (len == 2)
                  {
                    resword = &wordlist[317];
                    goto compare;
                  }
                break;
              case 456:
                if (len == 3)
                  {
                    resword = &wordlist[318];
                    goto compare;
                  }
                break;
              case 457:
                if (len == 2)
                  {
                    resword = &wordlist[319];
                    goto compare;
                  }
                break;
              case 458:
                if (len == 2)
                  {
                    resword = &wordlist[320];
                    goto compare;
                  }
                break;
              case 459:
                if (len == 3)
                  {
                    resword = &wordlist[321];
                    goto compare;
                  }
                break;
              case 460:
                if (len == 3)
                  {
                    resword = &wordlist[322];
                    goto compare;
                  }
                break;
              case 461:
                if (len == 3)
                  {
                    resword = &wordlist[323];
                    goto compare;
                  }
                break;
              case 462:
                if (len == 3)
                  {
                    resword = &wordlist[324];
                    goto compare;
                  }
                break;
              case 463:
                if (len == 3)
                  {
                    resword = &wordlist[325];
                    goto compare;
                  }
                break;
              case 464:
                if (len == 4)
                  {
                    resword = &wordlist[326];
                    goto compare;
                  }
                break;
              case 465:
                if (len == 3)
                  {
                    resword = &wordlist[327];
                    goto compare;
                  }
                break;
              case 467:
                if (len == 3)
                  {
                    resword = &wordlist[328];
                    goto compare;
                  }
                break;
              case 468:
                if (len == 3)
                  {
                    resword = &wordlist[329];
                    goto compare;
                  }
                break;
              case 470:
                if (len == 2)
                  {
                    resword = &wordlist[330];
                    goto compare;
                  }
                break;
              case 471:
                if (len == 4)
                  {
                    resword = &wordlist[331];
                    goto compare;
                  }
                break;
              case 472:
                if (len == 3)
                  {
                    resword = &wordlist[332];
                    goto compare;
                  }
                break;
              case 475:
                if (len == 2)
                  {
                    resword = &wordlist[333];
                    goto compare;
                  }
                break;
              case 477:
                if (len == 3)
                  {
                    resword = &wordlist[334];
                    goto compare;
                  }
                break;
              case 478:
                if (len == 3)
                  {
                    resword = &wordlist[335];
                    goto compare;
                  }
                break;
              case 483:
                if (len == 3)
                  {
                    resword = &wordlist[336];
                    goto compare;
                  }
                break;
              case 484:
                if (len == 3)
                  {
                    resword = &wordlist[337];
                    goto compare;
                  }
                break;
              case 485:
                if (len == 3)
                  {
                    resword = &wordlist[338];
                    goto compare;
                  }
                break;
              case 488:
                if (len == 3)
                  {
                    resword = &wordlist[339];
                    goto compare;
                  }
                break;
              case 489:
                if (len == 3)
                  {
                    resword = &wordlist[340];
                    goto compare;
                  }
                break;
              case 497:
                if (len == 2)
                  {
                    resword = &wordlist[341];
                    goto compare;
                  }
                break;
              case 498:
                if (len == 3)
                  {
                    resword = &wordlist[342];
                    goto compare;
                  }
                break;
              case 499:
                if (len == 2)
                  {
                    resword = &wordlist[343];
                    goto compare;
                  }
                break;
              case 500:
                if (len == 2)
                  {
                    resword = &wordlist[344];
                    goto compare;
                  }
                break;
              case 501:
                if (len == 2)
                  {
                    resword = &wordlist[345];
                    goto compare;
                  }
                break;
              case 502:
                if (len == 2)
                  {
                    resword = &wordlist[346];
                    goto compare;
                  }
                break;
              case 503:
                if (len == 2)
                  {
                    resword = &wordlist[347];
                    goto compare;
                  }
                break;
              case 508:
                if (len == 2)
                  {
                    resword = &wordlist[348];
                    goto compare;
                  }
                break;
              case 509:
                if (len == 4)
                  {
                    resword = &wordlist[349];
                    goto compare;
                  }
                break;
              case 510:
                if (len == 3)
                  {
                    resword = &wordlist[350];
                    goto compare;
                  }
                break;
              case 511:
                if (len == 3)
                  {
                    resword = &wordlist[351];
                    goto compare;
                  }
                break;
              case 512:
                if (len == 3)
                  {
                    resword = &wordlist[352];
                    goto compare;
                  }
                break;
              case 513:
                if (len == 3)
                  {
                    resword = &wordlist[353];
                    goto compare;
                  }
                break;
              case 514:
                if (len == 3)
                  {
                    resword = &wordlist[354];
                    goto compare;
                  }
                break;
              case 516:
                if (len == 3)
                  {
                    resword = &wordlist[355];
                    goto compare;
                  }
                break;
              case 517:
                if (len == 3)
                  {
                    resword = &wordlist[356];
                    goto compare;
                  }
                break;
              case 520:
                if (len == 3)
                  {
                    resword = &wordlist[357];
                    goto compare;
                  }
                break;
              case 525:
                if (len == 2)
                  {
                    resword = &wordlist[358];
                    goto compare;
                  }
                break;
              case 526:
                if (len == 2)
                  {
                    resword = &wordlist[359];
                    goto compare;
                  }
                break;
              case 527:
                if (len == 2)
                  {
                    resword = &wordlist[360];
                    goto compare;
                  }
                break;
              case 528:
                if (len == 3)
                  {
                    resword = &wordlist[361];
                    goto compare;
                  }
                break;
              case 535:
                if (len == 3)
                  {
                    resword = &wordlist[362];
                    goto compare;
                  }
                break;
              case 536:
                if (len == 3)
                  {
                    resword = &wordlist[363];
                    goto compare;
                  }
                break;
              case 538:
                if (len == 3)
                  {
                    resword = &wordlist[364];
                    goto compare;
                  }
                break;
              case 539:
                if (len == 3)
                  {
                    resword = &wordlist[365];
                    goto compare;
                  }
                break;
              case 540:
                if (len == 3)
                  {
                    resword = &wordlist[366];
                    goto compare;
                  }
                break;
              case 542:
                if (len == 3)
                  {
                    resword = &wordlist[367];
                    goto compare;
                  }
                break;
              case 546:
                if (len == 3)
                  {
                    resword = &wordlist[368];
                    goto compare;
                  }
                break;
              case 547:
                if (len == 2)
                  {
                    resword = &wordlist[369];
                    goto compare;
                  }
                break;
              case 548:
                if (len == 2)
                  {
                    resword = &wordlist[370];
                    goto compare;
                  }
                break;
              case 549:
                if (len == 3)
                  {
                    resword = &wordlist[371];
                    goto compare;
                  }
                break;
              case 550:
                if (len == 2)
                  {
                    resword = &wordlist[372];
                    goto compare;
                  }
                break;
              case 553:
                if (len == 4)
                  {
                    resword = &wordlist[373];
                    goto compare;
                  }
                break;
              case 555:
                if (len == 3)
                  {
                    resword = &wordlist[374];
                    goto compare;
                  }
                break;
              case 556:
                if (len == 3)
                  {
                    resword = &wordlist[375];
                    goto compare;
                  }
                break;
              case 557:
                if (len == 3)
                  {
                    resword = &wordlist[376];
                    goto compare;
                  }
                break;
              case 558:
                if (len == 3)
                  {
                    resword = &wordlist[377];
                    goto compare;
                  }
                break;
              case 560:
                if (len == 3)
                  {
                    resword = &wordlist[378];
                    goto compare;
                  }
                break;
              case 564:
                if (len == 3)
                  {
                    resword = &wordlist[379];
                    goto compare;
                  }
                break;
              case 570:
                if (len == 4)
                  {
                    resword = &wordlist[380];
                    goto compare;
                  }
                break;
              case 571:
                if (len == 2)
                  {
                    resword = &wordlist[381];
                    goto compare;
                  }
                break;
              case 572:
                if (len == 2)
                  {
                    resword = &wordlist[382];
                    goto compare;
                  }
                break;
              case 573:
                if (len == 2)
                  {
                    resword = &wordlist[383];
                    goto compare;
                  }
                break;
              case 575:
                if (len == 3)
                  {
                    resword = &wordlist[384];
                    goto compare;
                  }
                break;
              case 576:
                if (len == 2)
                  {
                    resword = &wordlist[385];
                    goto compare;
                  }
                break;
              case 577:
                if (len == 3)
                  {
                    resword = &wordlist[386];
                    goto compare;
                  }
                break;
              case 579:
                if (len == 2)
                  {
                    resword = &wordlist[387];
                    goto compare;
                  }
                break;
              case 580:
                if (len == 3)
                  {
                    resword = &wordlist[388];
                    goto compare;
                  }
                break;
              case 582:
                if (len == 3)
                  {
                    resword = &wordlist[389];
                    goto compare;
                  }
                break;
              case 584:
                if (len == 3)
                  {
                    resword = &wordlist[390];
                    goto compare;
                  }
                break;
              case 588:
                if (len == 2)
                  {
                    resword = &wordlist[391];
                    goto compare;
                  }
                break;
              case 590:
                if (len == 3)
                  {
                    resword = &wordlist[392];
                    goto compare;
                  }
                break;
              case 591:
                if (len == 3)
                  {
                    resword = &wordlist[393];
                    goto compare;
                  }
                break;
              case 595:
                if (len == 4)
                  {
                    resword = &wordlist[394];
                    goto compare;
                  }
                break;
              case 596:
                if (len == 3)
                  {
                    resword = &wordlist[395];
                    goto compare;
                  }
                break;
              case 598:
                if (len == 3)
                  {
                    resword = &wordlist[396];
                    goto compare;
                  }
                break;
              case 599:
                if (len == 2)
                  {
                    resword = &wordlist[397];
                    goto compare;
                  }
                break;
              case 600:
                if (len == 3)
                  {
                    resword = &wordlist[398];
                    goto compare;
                  }
                break;
              case 601:
                if (len == 3)
                  {
                    resword = &wordlist[399];
                    goto compare;
                  }
                break;
              case 602:
                if (len == 2)
                  {
                    resword = &wordlist[400];
                    goto compare;
                  }
                break;
              case 603:
                if (len == 3)
                  {
                    resword = &wordlist[401];
                    goto compare;
                  }
                break;
              case 605:
                if (len == 3)
                  {
                    resword = &wordlist[402];
                    goto compare;
                  }
                break;
              case 607:
                if (len == 2)
                  {
                    resword = &wordlist[403];
                    goto compare;
                  }
                break;
              case 610:
                if (len == 4)
                  {
                    resword = &wordlist[404];
                    goto compare;
                  }
                break;
              case 612:
                if (len == 2)
                  {
                    resword = &wordlist[405];
                    goto compare;
                  }
                break;
              case 616:
                if (len == 3)
                  {
                    resword = &wordlist[406];
                    goto compare;
                  }
                break;
              case 617:
                if (len == 3)
                  {
                    resword = &wordlist[407];
                    goto compare;
                  }
                break;
              case 620:
                if (len == 3)
                  {
                    resword = &wordlist[408];
                    goto compare;
                  }
                break;
              case 621:
                if (len == 3)
                  {
                    resword = &wordlist[409];
                    goto compare;
                  }
                break;
              case 622:
                if (len == 3)
                  {
                    resword = &wordlist[410];
                    goto compare;
                  }
                break;
              case 624:
                if (len == 3)
                  {
                    resword = &wordlist[411];
                    goto compare;
                  }
                break;
              case 625:
                if (len == 2)
                  {
                    resword = &wordlist[412];
                    goto compare;
                  }
                break;
              case 626:
                if (len == 3)
                  {
                    resword = &wordlist[413];
                    goto compare;
                  }
                break;
              case 627:
                if (len == 3)
                  {
                    resword = &wordlist[414];
                    goto compare;
                  }
                break;
              case 629:
                if (len == 3)
                  {
                    resword = &wordlist[415];
                    goto compare;
                  }
                break;
              case 630:
                if (len == 4)
                  {
                    resword = &wordlist[416];
                    goto compare;
                  }
                break;
              case 631:
                if (len == 3)
                  {
                    resword = &wordlist[417];
                    goto compare;
                  }
                break;
              case 633:
                if (len == 2)
                  {
                    resword = &wordlist[418];
                    goto compare;
                  }
                break;
              case 634:
                if (len == 2)
                  {
                    resword = &wordlist[419];
                    goto compare;
                  }
                break;
              case 637:
                if (len == 3)
                  {
                    resword = &wordlist[420];
                    goto compare;
                  }
                break;
              case 638:
                if (len == 4)
                  {
                    resword = &wordlist[421];
                    goto compare;
                  }
                break;
              case 641:
                if (len == 3)
                  {
                    resword = &wordlist[422];
                    goto compare;
                  }
                break;
              case 642:
                if (len == 3)
                  {
                    resword = &wordlist[423];
                    goto compare;
                  }
                break;
              case 643:
                if (len == 3)
                  {
                    resword = &wordlist[424];
                    goto compare;
                  }
                break;
              case 644:
                if (len == 3)
                  {
                    resword = &wordlist[425];
                    goto compare;
                  }
                break;
              case 647:
                if (len == 4)
                  {
                    resword = &wordlist[426];
                    goto compare;
                  }
                break;
              case 648:
                if (len == 2)
                  {
                    resword = &wordlist[427];
                    goto compare;
                  }
                break;
              case 649:
                if (len == 3)
                  {
                    resword = &wordlist[428];
                    goto compare;
                  }
                break;
              case 650:
                if (len == 3)
                  {
                    resword = &wordlist[429];
                    goto compare;
                  }
                break;
              case 651:
                if (len == 2)
                  {
                    resword = &wordlist[430];
                    goto compare;
                  }
                break;
              case 652:
                if (len == 3)
                  {
                    resword = &wordlist[431];
                    goto compare;
                  }
                break;
              case 653:
                if (len == 4)
                  {
                    resword = &wordlist[432];
                    goto compare;
                  }
                break;
              case 654:
                if (len == 2)
                  {
                    resword = &wordlist[433];
                    goto compare;
                  }
                break;
              case 655:
                if (len == 3)
                  {
                    resword = &wordlist[434];
                    goto compare;
                  }
                break;
              case 656:
                if (len == 2)
                  {
                    resword = &wordlist[435];
                    goto compare;
                  }
                break;
              case 658:
                if (len == 2)
                  {
                    resword = &wordlist[436];
                    goto compare;
                  }
                break;
              case 660:
                if (len == 4)
                  {
                    resword = &wordlist[437];
                    goto compare;
                  }
                break;
              case 662:
                if (len == 4)
                  {
                    resword = &wordlist[438];
                    goto compare;
                  }
                break;
              case 663:
                if (len == 2)
                  {
                    resword = &wordlist[439];
                    goto compare;
                  }
                break;
              case 665:
                if (len == 3)
                  {
                    resword = &wordlist[440];
                    goto compare;
                  }
                break;
              case 667:
                if (len == 3)
                  {
                    resword = &wordlist[441];
                    goto compare;
                  }
                break;
              case 668:
                if (len == 2)
                  {
                    resword = &wordlist[442];
                    goto compare;
                  }
                break;
              case 669:
                if (len == 2)
                  {
                    resword = &wordlist[443];
                    goto compare;
                  }
                break;
              case 670:
                if (len == 2)
                  {
                    resword = &wordlist[444];
                    goto compare;
                  }
                break;
              case 674:
                if (len == 3)
                  {
                    resword = &wordlist[445];
                    goto compare;
                  }
                break;
              case 676:
                if (len == 3)
                  {
                    resword = &wordlist[446];
                    goto compare;
                  }
                break;
              case 677:
                if (len == 4)
                  {
                    resword = &wordlist[447];
                    goto compare;
                  }
                break;
              case 678:
                if (len == 3)
                  {
                    resword = &wordlist[448];
                    goto compare;
                  }
                break;
              case 679:
                if (len == 2)
                  {
                    resword = &wordlist[449];
                    goto compare;
                  }
                break;
              case 680:
                if (len == 3)
                  {
                    resword = &wordlist[450];
                    goto compare;
                  }
                break;
              case 681:
                if (len == 3)
                  {
                    resword = &wordlist[451];
                    goto compare;
                  }
                break;
              case 682:
                if (len == 3)
                  {
                    resword = &wordlist[452];
                    goto compare;
                  }
                break;
              case 685:
                if (len == 3)
                  {
                    resword = &wordlist[453];
                    goto compare;
                  }
                break;
              case 687:
                if (len == 3)
                  {
                    resword = &wordlist[454];
                    goto compare;
                  }
                break;
              case 688:
                if (len == 2)
                  {
                    resword = &wordlist[455];
                    goto compare;
                  }
                break;
              case 689:
                if (len == 2)
                  {
                    resword = &wordlist[456];
                    goto compare;
                  }
                break;
              case 691:
                if (len == 3)
                  {
                    resword = &wordlist[457];
                    goto compare;
                  }
                break;
              case 697:
                if (len == 2)
                  {
                    resword = &wordlist[458];
                    goto compare;
                  }
                break;
              case 698:
                if (len == 3)
                  {
                    resword = &wordlist[459];
                    goto compare;
                  }
                break;
              case 700:
                if (len == 3)
                  {
                    resword = &wordlist[460];
                    goto compare;
                  }
                break;
              case 701:
                if (len == 2)
                  {
                    resword = &wordlist[461];
                    goto compare;
                  }
                break;
              case 704:
                if (len == 2)
                  {
                    resword = &wordlist[462];
                    goto compare;
                  }
                break;
              case 705:
                if (len == 2)
                  {
                    resword = &wordlist[463];
                    goto compare;
                  }
                break;
              case 706:
                if (len == 2)
                  {
                    resword = &wordlist[464];
                    goto compare;
                  }
                break;
              case 708:
                if (len == 2)
                  {
                    resword = &wordlist[465];
                    goto compare;
                  }
                break;
              case 709:
                if (len == 2)
                  {
                    resword = &wordlist[466];
                    goto compare;
                  }
                break;
              case 711:
                if (len == 2)
                  {
                    resword = &wordlist[467];
                    goto compare;
                  }
                break;
              case 712:
                if (len == 3)
                  {
                    resword = &wordlist[468];
                    goto compare;
                  }
                break;
              case 715:
                if (len == 3)
                  {
                    resword = &wordlist[469];
                    goto compare;
                  }
                break;
              case 716:
                if (len == 2)
                  {
                    resword = &wordlist[470];
                    goto compare;
                  }
                break;
              case 717:
                if (len == 4)
                  {
                    resword = &wordlist[471];
                    goto compare;
                  }
                break;
              case 718:
                if (len == 3)
                  {
                    resword = &wordlist[472];
                    goto compare;
                  }
                break;
              case 719:
                if (len == 3)
                  {
                    resword = &wordlist[473];
                    goto compare;
                  }
                break;
              case 720:
                if (len == 3)
                  {
                    resword = &wordlist[474];
                    goto compare;
                  }
                break;
              case 721:
                if (len == 3)
                  {
                    resword = &wordlist[475];
                    goto compare;
                  }
                break;
              case 722:
                if (len == 3)
                  {
                    resword = &wordlist[476];
                    goto compare;
                  }
                break;
              case 723:
                if (len == 3)
                  {
                    resword = &wordlist[477];
                    goto compare;
                  }
                break;
              case 724:
                if (len == 3)
                  {
                    resword = &wordlist[478];
                    goto compare;
                  }
                break;
              case 725:
                if (len == 2)
                  {
                    resword = &wordlist[479];
                    goto compare;
                  }
                break;
              case 726:
                if (len == 2)
                  {
                    resword = &wordlist[480];
                    goto compare;
                  }
                break;
              case 728:
                if (len == 3)
                  {
                    resword = &wordlist[481];
                    goto compare;
                  }
                break;
              case 730:
                if (len == 3)
                  {
                    resword = &wordlist[482];
                    goto compare;
                  }
                break;
              case 732:
                if (len == 4)
                  {
                    resword = &wordlist[483];
                    goto compare;
                  }
                break;
              case 733:
                if (len == 3)
                  {
                    resword = &wordlist[484];
                    goto compare;
                  }
                break;
              case 735:
                if (len == 3)
                  {
                    resword = &wordlist[485];
                    goto compare;
                  }
                break;
              case 737:
                if (len == 2)
                  {
                    resword = &wordlist[486];
                    goto compare;
                  }
                break;
              case 740:
                if (len == 2)
                  {
                    resword = &wordlist[487];
                    goto compare;
                  }
                break;
              case 741:
                if (len == 4)
                  {
                    resword = &wordlist[488];
                    goto compare;
                  }
                break;
              case 744:
                if (len == 3)
                  {
                    resword = &wordlist[489];
                    goto compare;
                  }
                break;
              case 745:
                if (len == 2)
                  {
                    resword = &wordlist[490];
                    goto compare;
                  }
                break;
              case 746:
                if (len == 3)
                  {
                    resword = &wordlist[491];
                    goto compare;
                  }
                break;
              case 748:
                if (len == 3)
                  {
                    resword = &wordlist[492];
                    goto compare;
                  }
                break;
              case 749:
                if (len == 3)
                  {
                    resword = &wordlist[493];
                    goto compare;
                  }
                break;
              case 750:
                if (len == 2)
                  {
                    resword = &wordlist[494];
                    goto compare;
                  }
                break;
              case 751:
                if (len == 2)
                  {
                    resword = &wordlist[495];
                    goto compare;
                  }
                break;
              case 752:
                if (len == 2)
                  {
                    resword = &wordlist[496];
                    goto compare;
                  }
                break;
              case 754:
                if (len == 3)
                  {
                    resword = &wordlist[497];
                    goto compare;
                  }
                break;
              case 755:
                if (len == 3)
                  {
                    resword = &wordlist[498];
                    goto compare;
                  }
                break;
              case 757:
                if (len == 3)
                  {
                    resword = &wordlist[499];
                    goto compare;
                  }
                break;
              case 759:
                if (len == 3)
                  {
                    resword = &wordlist[500];
                    goto compare;
                  }
                break;
              case 760:
                if (len == 3)
                  {
                    resword = &wordlist[501];
                    goto compare;
                  }
                break;
              case 761:
                if (len == 2)
                  {
                    resword = &wordlist[502];
                    goto compare;
                  }
                break;
              case 764:
                if (len == 4)
                  {
                    resword = &wordlist[503];
                    goto compare;
                  }
                break;
              case 765:
                if (len == 2)
                  {
                    resword = &wordlist[504];
                    goto compare;
                  }
                break;
              case 766:
                if (len == 3)
                  {
                    resword = &wordlist[505];
                    goto compare;
                  }
                break;
              case 768:
                if (len == 2)
                  {
                    resword = &wordlist[506];
                    goto compare;
                  }
                break;
              case 769:
                if (len == 3)
                  {
                    resword = &wordlist[507];
                    goto compare;
                  }
                break;
              case 770:
                if (len == 2)
                  {
                    resword = &wordlist[508];
                    goto compare;
                  }
                break;
              case 771:
                if (len == 3)
                  {
                    resword = &wordlist[509];
                    goto compare;
                  }
                break;
              case 772:
                if (len == 2)
                  {
                    resword = &wordlist[510];
                    goto compare;
                  }
                break;
              case 775:
                if (len == 3)
                  {
                    resword = &wordlist[511];
                    goto compare;
                  }
                break;
              case 776:
                if (len == 2)
                  {
                    resword = &wordlist[512];
                    goto compare;
                  }
                break;
              case 777:
                if (len == 2)
                  {
                    resword = &wordlist[513];
                    goto compare;
                  }
                break;
              case 778:
                if (len == 3)
                  {
                    resword = &wordlist[514];
                    goto compare;
                  }
                break;
              case 779:
                if (len == 2)
                  {
                    resword = &wordlist[515];
                    goto compare;
                  }
                break;
              case 780:
                if (len == 2)
                  {
                    resword = &wordlist[516];
                    goto compare;
                  }
                break;
              case 783:
                if (len == 3)
                  {
                    resword = &wordlist[517];
                    goto compare;
                  }
                break;
              case 785:
                if (len == 2)
                  {
                    resword = &wordlist[518];
                    goto compare;
                  }
                break;
              case 786:
                if (len == 3)
                  {
                    resword = &wordlist[519];
                    goto compare;
                  }
                break;
              case 788:
                if (len == 3)
                  {
                    resword = &wordlist[520];
                    goto compare;
                  }
                break;
              case 789:
                if (len == 3)
                  {
                    resword = &wordlist[521];
                    goto compare;
                  }
                break;
              case 791:
                if (len == 2)
                  {
                    resword = &wordlist[522];
                    goto compare;
                  }
                break;
              case 792:
                if (len == 3)
                  {
                    resword = &wordlist[523];
                    goto compare;
                  }
                break;
              case 794:
                if (len == 2)
                  {
                    resword = &wordlist[524];
                    goto compare;
                  }
                break;
              case 797:
                if (len == 4)
                  {
                    resword = &wordlist[525];
                    goto compare;
                  }
                break;
              case 798:
                if (len == 2)
                  {
                    resword = &wordlist[526];
                    goto compare;
                  }
                break;
              case 799:
                if (len == 3)
                  {
                    resword = &wordlist[527];
                    goto compare;
                  }
                break;
              case 800:
                if (len == 3)
                  {
                    resword = &wordlist[528];
                    goto compare;
                  }
                break;
              case 801:
                if (len == 3)
                  {
                    resword = &wordlist[529];
                    goto compare;
                  }
                break;
              case 802:
                if (len == 3)
                  {
                    resword = &wordlist[530];
                    goto compare;
                  }
                break;
              case 804:
                if (len == 3)
                  {
                    resword = &wordlist[531];
                    goto compare;
                  }
                break;
              case 805:
                if (len == 3)
                  {
                    resword = &wordlist[532];
                    goto compare;
                  }
                break;
              case 806:
                if (len == 3)
                  {
                    resword = &wordlist[533];
                    goto compare;
                  }
                break;
              case 807:
                if (len == 2)
                  {
                    resword = &wordlist[534];
                    goto compare;
                  }
                break;
              case 808:
                if (len == 3)
                  {
                    resword = &wordlist[535];
                    goto compare;
                  }
                break;
              case 811:
                if (len == 3)
                  {
                    resword = &wordlist[536];
                    goto compare;
                  }
                break;
              case 812:
                if (len == 4)
                  {
                    resword = &wordlist[537];
                    goto compare;
                  }
                break;
              case 815:
                if (len == 3)
                  {
                    resword = &wordlist[538];
                    goto compare;
                  }
                break;
              case 816:
                if (len == 2)
                  {
                    resword = &wordlist[539];
                    goto compare;
                  }
                break;
              case 820:
                if (len == 3)
                  {
                    resword = &wordlist[540];
                    goto compare;
                  }
                break;
              case 823:
                if (len == 3)
                  {
                    resword = &wordlist[541];
                    goto compare;
                  }
                break;
              case 824:
                if (len == 3)
                  {
                    resword = &wordlist[542];
                    goto compare;
                  }
                break;
              case 826:
                if (len == 3)
                  {
                    resword = &wordlist[543];
                    goto compare;
                  }
                break;
              case 828:
                if (len == 3)
                  {
                    resword = &wordlist[544];
                    goto compare;
                  }
                break;
              case 833:
                if (len == 2)
                  {
                    resword = &wordlist[545];
                    goto compare;
                  }
                break;
              case 834:
                if (len == 2)
                  {
                    resword = &wordlist[546];
                    goto compare;
                  }
                break;
              case 835:
                if (len == 2)
                  {
                    resword = &wordlist[547];
                    goto compare;
                  }
                break;
              case 836:
                if (len == 2)
                  {
                    resword = &wordlist[548];
                    goto compare;
                  }
                break;
              case 837:
                if (len == 3)
                  {
                    resword = &wordlist[549];
                    goto compare;
                  }
                break;
              case 839:
                if (len == 3)
                  {
                    resword = &wordlist[550];
                    goto compare;
                  }
                break;
              case 842:
                if (len == 3)
                  {
                    resword = &wordlist[551];
                    goto compare;
                  }
                break;
              case 844:
                if (len == 3)
                  {
                    resword = &wordlist[552];
                    goto compare;
                  }
                break;
              case 845:
                if (len == 3)
                  {
                    resword = &wordlist[553];
                    goto compare;
                  }
                break;
              case 847:
                if (len == 3)
                  {
                    resword = &wordlist[554];
                    goto compare;
                  }
                break;
              case 848:
                if (len == 2)
                  {
                    resword = &wordlist[555];
                    goto compare;
                  }
                break;
              case 857:
                if (len == 3)
                  {
                    resword = &wordlist[556];
                    goto compare;
                  }
                break;
              case 858:
                if (len == 4)
                  {
                    resword = &wordlist[557];
                    goto compare;
                  }
                break;
              case 859:
                if (len == 3)
                  {
                    resword = &wordlist[558];
                    goto compare;
                  }
                break;
              case 860:
                if (len == 3)
                  {
                    resword = &wordlist[559];
                    goto compare;
                  }
                break;
              case 861:
                if (len == 3)
                  {
                    resword = &wordlist[560];
                    goto compare;
                  }
                break;
              case 862:
                if (len == 3)
                  {
                    resword = &wordlist[561];
                    goto compare;
                  }
                break;
              case 863:
                if (len == 3)
                  {
                    resword = &wordlist[562];
                    goto compare;
                  }
                break;
              case 864:
                if (len == 3)
                  {
                    resword = &wordlist[563];
                    goto compare;
                  }
                break;
              case 865:
                if (len == 3)
                  {
                    resword = &wordlist[564];
                    goto compare;
                  }
                break;
              case 868:
                if (len == 2)
                  {
                    resword = &wordlist[565];
                    goto compare;
                  }
                break;
              case 869:
                if (len == 3)
                  {
                    resword = &wordlist[566];
                    goto compare;
                  }
                break;
              case 872:
                if (len == 4)
                  {
                    resword = &wordlist[567];
                    goto compare;
                  }
                break;
              case 873:
                if (len == 4)
                  {
                    resword = &wordlist[568];
                    goto compare;
                  }
                break;
              case 874:
                if (len == 3)
                  {
                    resword = &wordlist[569];
                    goto compare;
                  }
                break;
              case 875:
                if (len == 3)
                  {
                    resword = &wordlist[570];
                    goto compare;
                  }
                break;
              case 876:
                if (len == 3)
                  {
                    resword = &wordlist[571];
                    goto compare;
                  }
                break;
              case 877:
                if (len == 3)
                  {
                    resword = &wordlist[572];
                    goto compare;
                  }
                break;
              case 878:
                if (len == 3)
                  {
                    resword = &wordlist[573];
                    goto compare;
                  }
                break;
              case 879:
                if (len == 3)
                  {
                    resword = &wordlist[574];
                    goto compare;
                  }
                break;
              case 880:
                if (len == 2)
                  {
                    resword = &wordlist[575];
                    goto compare;
                  }
                break;
              case 881:
                if (len == 2)
                  {
                    resword = &wordlist[576];
                    goto compare;
                  }
                break;
              case 882:
                if (len == 2)
                  {
                    resword = &wordlist[577];
                    goto compare;
                  }
                break;
              case 883:
                if (len == 3)
                  {
                    resword = &wordlist[578];
                    goto compare;
                  }
                break;
              case 885:
                if (len == 3)
                  {
                    resword = &wordlist[579];
                    goto compare;
                  }
                break;
              case 886:
                if (len == 3)
                  {
                    resword = &wordlist[580];
                    goto compare;
                  }
                break;
              case 887:
                if (len == 3)
                  {
                    resword = &wordlist[581];
                    goto compare;
                  }
                break;
              case 888:
                if (len == 2)
                  {
                    resword = &wordlist[582];
                    goto compare;
                  }
                break;
              case 889:
                if (len == 3)
                  {
                    resword = &wordlist[583];
                    goto compare;
                  }
                break;
              case 891:
                if (len == 3)
                  {
                    resword = &wordlist[584];
                    goto compare;
                  }
                break;
              case 892:
                if (len == 2)
                  {
                    resword = &wordlist[585];
                    goto compare;
                  }
                break;
              case 895:
                if (len == 2)
                  {
                    resword = &wordlist[586];
                    goto compare;
                  }
                break;
              case 896:
                if (len == 2)
                  {
                    resword = &wordlist[587];
                    goto compare;
                  }
                break;
              case 900:
                if (len == 2)
                  {
                    resword = &wordlist[588];
                    goto compare;
                  }
                break;
              case 901:
                if (len == 2)
                  {
                    resword = &wordlist[589];
                    goto compare;
                  }
                break;
              case 902:
                if (len == 2)
                  {
                    resword = &wordlist[590];
                    goto compare;
                  }
                break;
              case 903:
                if (len == 2)
                  {
                    resword = &wordlist[591];
                    goto compare;
                  }
                break;
              case 904:
                if (len == 2)
                  {
                    resword = &wordlist[592];
                    goto compare;
                  }
                break;
              case 906:
                if (len == 3)
                  {
                    resword = &wordlist[593];
                    goto compare;
                  }
                break;
              case 907:
                if (len == 2)
                  {
                    resword = &wordlist[594];
                    goto compare;
                  }
                break;
              case 908:
                if (len == 2)
                  {
                    resword = &wordlist[595];
                    goto compare;
                  }
                break;
              case 909:
                if (len == 3)
                  {
                    resword = &wordlist[596];
                    goto compare;
                  }
                break;
              case 910:
                if (len == 3)
                  {
                    resword = &wordlist[597];
                    goto compare;
                  }
                break;
              case 911:
                if (len == 3)
                  {
                    resword = &wordlist[598];
                    goto compare;
                  }
                break;
              case 912:
                if (len == 3)
                  {
                    resword = &wordlist[599];
                    goto compare;
                  }
                break;
              case 913:
                if (len == 3)
                  {
                    resword = &wordlist[600];
                    goto compare;
                  }
                break;
              case 920:
                if (len == 2)
                  {
                    resword = &wordlist[601];
                    goto compare;
                  }
                break;
              case 921:
                if (len == 4)
                  {
                    resword = &wordlist[602];
                    goto compare;
                  }
                break;
              case 922:
                if (len == 4)
                  {
                    resword = &wordlist[603];
                    goto compare;
                  }
                break;
              case 923:
                if (len == 3)
                  {
                    resword = &wordlist[604];
                    goto compare;
                  }
                break;
              case 925:
                if (len == 3)
                  {
                    resword = &wordlist[605];
                    goto compare;
                  }
                break;
              case 926:
                if (len == 3)
                  {
                    resword = &wordlist[606];
                    goto compare;
                  }
                break;
              case 931:
                if (len == 3)
                  {
                    resword = &wordlist[607];
                    goto compare;
                  }
                break;
              case 932:
                if (len == 2)
                  {
                    resword = &wordlist[608];
                    goto compare;
                  }
                break;
              case 935:
                if (len == 2)
                  {
                    resword = &wordlist[609];
                    goto compare;
                  }
                break;
              case 936:
                if (len == 3)
                  {
                    resword = &wordlist[610];
                    goto compare;
                  }
                break;
              case 939:
                if (len == 3)
                  {
                    resword = &wordlist[611];
                    goto compare;
                  }
                break;
              case 941:
                if (len == 4)
                  {
                    resword = &wordlist[612];
                    goto compare;
                  }
                break;
              case 943:
                if (len == 3)
                  {
                    resword = &wordlist[613];
                    goto compare;
                  }
                break;
              case 944:
                if (len == 3)
                  {
                    resword = &wordlist[614];
                    goto compare;
                  }
                break;
              case 945:
                if (len == 3)
                  {
                    resword = &wordlist[615];
                    goto compare;
                  }
                break;
              case 946:
                if (len == 3)
                  {
                    resword = &wordlist[616];
                    goto compare;
                  }
                break;
              case 947:
                if (len == 3)
                  {
                    resword = &wordlist[617];
                    goto compare;
                  }
                break;
              case 948:
                if (len == 3)
                  {
                    resword = &wordlist[618];
                    goto compare;
                  }
                break;
              case 950:
                if (len == 3)
                  {
                    resword = &wordlist[619];
                    goto compare;
                  }
                break;
              case 951:
                if (len == 3)
                  {
                    resword = &wordlist[620];
                    goto compare;
                  }
                break;
              case 952:
                if (len == 3)
                  {
                    resword = &wordlist[621];
                    goto compare;
                  }
                break;
              case 953:
                if (len == 2)
                  {
                    resword = &wordlist[622];
                    goto compare;
                  }
                break;
              case 954:
                if (len == 2)
                  {
                    resword = &wordlist[623];
                    goto compare;
                  }
                break;
              case 955:
                if (len == 3)
                  {
                    resword = &wordlist[624];
                    goto compare;
                  }
                break;
              case 956:
                if (len == 4)
                  {
                    resword = &wordlist[625];
                    goto compare;
                  }
                break;
              case 959:
                if (len == 2)
                  {
                    resword = &wordlist[626];
                    goto compare;
                  }
                break;
              case 961:
                if (len == 3)
                  {
                    resword = &wordlist[627];
                    goto compare;
                  }
                break;
              case 966:
                if (len == 3)
                  {
                    resword = &wordlist[628];
                    goto compare;
                  }
                break;
              case 968:
                if (len == 3)
                  {
                    resword = &wordlist[629];
                    goto compare;
                  }
                break;
              case 970:
                if (len == 3)
                  {
                    resword = &wordlist[630];
                    goto compare;
                  }
                break;
              case 974:
                if (len == 2)
                  {
                    resword = &wordlist[631];
                    goto compare;
                  }
                break;
              case 977:
                if (len == 2)
                  {
                    resword = &wordlist[632];
                    goto compare;
                  }
                break;
              case 978:
                if (len == 3)
                  {
                    resword = &wordlist[633];
                    goto compare;
                  }
                break;
              case 979:
                if (len == 2)
                  {
                    resword = &wordlist[634];
                    goto compare;
                  }
                break;
              case 986:
                if (len == 3)
                  {
                    resword = &wordlist[635];
                    goto compare;
                  }
                break;
              case 990:
                if (len == 2)
                  {
                    resword = &wordlist[636];
                    goto compare;
                  }
                break;
              case 992:
                if (len == 2)
                  {
                    resword = &wordlist[637];
                    goto compare;
                  }
                break;
              case 993:
                if (len == 4)
                  {
                    resword = &wordlist[638];
                    goto compare;
                  }
                break;
              case 994:
                if (len == 2)
                  {
                    resword = &wordlist[639];
                    goto compare;
                  }
                break;
              case 996:
                if (len == 3)
                  {
                    resword = &wordlist[640];
                    goto compare;
                  }
                break;
              case 998:
                if (len == 3)
                  {
                    resword = &wordlist[641];
                    goto compare;
                  }
                break;
              case 1000:
                if (len == 3)
                  {
                    resword = &wordlist[642];
                    goto compare;
                  }
                break;
              case 1001:
                if (len == 2)
                  {
                    resword = &wordlist[643];
                    goto compare;
                  }
                break;
              case 1003:
                if (len == 3)
                  {
                    resword = &wordlist[644];
                    goto compare;
                  }
                break;
              case 1006:
                if (len == 3)
                  {
                    resword = &wordlist[645];
                    goto compare;
                  }
                break;
              case 1008:
                if (len == 2)
                  {
                    resword = &wordlist[646];
                    goto compare;
                  }
                break;
              case 1009:
                if (len == 3)
                  {
                    resword = &wordlist[647];
                    goto compare;
                  }
                break;
              case 1010:
                if (len == 3)
                  {
                    resword = &wordlist[648];
                    goto compare;
                  }
                break;
              case 1011:
                if (len == 2)
                  {
                    resword = &wordlist[649];
                    goto compare;
                  }
                break;
              case 1013:
                if (len == 2)
                  {
                    resword = &wordlist[650];
                    goto compare;
                  }
                break;
              case 1015:
                if (len == 3)
                  {
                    resword = &wordlist[651];
                    goto compare;
                  }
                break;
              case 1016:
                if (len == 4)
                  {
                    resword = &wordlist[652];
                    goto compare;
                  }
                break;
              case 1018:
                if (len == 3)
                  {
                    resword = &wordlist[653];
                    goto compare;
                  }
                break;
              case 1020:
                if (len == 4)
                  {
                    resword = &wordlist[654];
                    goto compare;
                  }
                break;
              case 1021:
                if (len == 3)
                  {
                    resword = &wordlist[655];
                    goto compare;
                  }
                break;
              case 1022:
                if (len == 3)
                  {
                    resword = &wordlist[656];
                    goto compare;
                  }
                break;
              case 1023:
                if (len == 3)
                  {
                    resword = &wordlist[657];
                    goto compare;
                  }
                break;
              case 1024:
                if (len == 3)
                  {
                    resword = &wordlist[658];
                    goto compare;
                  }
                break;
              case 1025:
                if (len == 3)
                  {
                    resword = &wordlist[659];
                    goto compare;
                  }
                break;
              case 1026:
                if (len == 2)
                  {
                    resword = &wordlist[660];
                    goto compare;
                  }
                break;
              case 1027:
                if (len == 3)
                  {
                    resword = &wordlist[661];
                    goto compare;
                  }
                break;
              case 1028:
                if (len == 2)
                  {
                    resword = &wordlist[662];
                    goto compare;
                  }
                break;
              case 1030:
                if (len == 3)
                  {
                    resword = &wordlist[663];
                    goto compare;
                  }
                break;
              case 1031:
                if (len == 3)
                  {
                    resword = &wordlist[664];
                    goto compare;
                  }
                break;
              case 1037:
                if (len == 3)
                  {
                    resword = &wordlist[665];
                    goto compare;
                  }
                break;
              case 1041:
                if (len == 3)
                  {
                    resword = &wordlist[666];
                    goto compare;
                  }
                break;
              case 1043:
                if (len == 3)
                  {
                    resword = &wordlist[667];
                    goto compare;
                  }
                break;
              case 1047:
                if (len == 3)
                  {
                    resword = &wordlist[668];
                    goto compare;
                  }
                break;
              case 1049:
                if (len == 3)
                  {
                    resword = &wordlist[669];
                    goto compare;
                  }
                break;
              case 1051:
                if (len == 2)
                  {
                    resword = &wordlist[670];
                    goto compare;
                  }
                break;
              case 1052:
                if (len == 3)
                  {
                    resword = &wordlist[671];
                    goto compare;
                  }
                break;
              case 1053:
                if (len == 2)
                  {
                    resword = &wordlist[672];
                    goto compare;
                  }
                break;
              case 1054:
                if (len == 3)
                  {
                    resword = &wordlist[673];
                    goto compare;
                  }
                break;
              case 1057:
                if (len == 2)
                  {
                    resword = &wordlist[674];
                    goto compare;
                  }
                break;
              case 1059:
                if (len == 3)
                  {
                    resword = &wordlist[675];
                    goto compare;
                  }
                break;
              case 1060:
                if (len == 2)
                  {
                    resword = &wordlist[676];
                    goto compare;
                  }
                break;
              case 1064:
                if (len == 3)
                  {
                    resword = &wordlist[677];
                    goto compare;
                  }
                break;
              case 1067:
                if (len == 2)
                  {
                    resword = &wordlist[678];
                    goto compare;
                  }
                break;
              case 1069:
                if (len == 3)
                  {
                    resword = &wordlist[679];
                    goto compare;
                  }
                break;
              case 1070:
                if (len == 2)
                  {
                    resword = &wordlist[680];
                    goto compare;
                  }
                break;
              case 1077:
                if (len == 2)
                  {
                    resword = &wordlist[681];
                    goto compare;
                  }
                break;
              case 1078:
                if (len == 3)
                  {
                    resword = &wordlist[682];
                    goto compare;
                  }
                break;
              case 1079:
                if (len == 3)
                  {
                    resword = &wordlist[683];
                    goto compare;
                  }
                break;
              case 1080:
                if (len == 2)
                  {
                    resword = &wordlist[684];
                    goto compare;
                  }
                break;
              case 1082:
                if (len == 2)
                  {
                    resword = &wordlist[685];
                    goto compare;
                  }
                break;
              case 1083:
                if (len == 3)
                  {
                    resword = &wordlist[686];
                    goto compare;
                  }
                break;
              case 1084:
                if (len == 3)
                  {
                    resword = &wordlist[687];
                    goto compare;
                  }
                break;
              case 1085:
                if (len == 3)
                  {
                    resword = &wordlist[688];
                    goto compare;
                  }
                break;
              case 1086:
                if (len == 3)
                  {
                    resword = &wordlist[689];
                    goto compare;
                  }
                break;
              case 1087:
                if (len == 3)
                  {
                    resword = &wordlist[690];
                    goto compare;
                  }
                break;
              case 1088:
                if (len == 3)
                  {
                    resword = &wordlist[691];
                    goto compare;
                  }
                break;
              case 1091:
                if (len == 2)
                  {
                    resword = &wordlist[692];
                    goto compare;
                  }
                break;
              case 1093:
                if (len == 3)
                  {
                    resword = &wordlist[693];
                    goto compare;
                  }
                break;
              case 1094:
                if (len == 3)
                  {
                    resword = &wordlist[694];
                    goto compare;
                  }
                break;
              case 1095:
                if (len == 3)
                  {
                    resword = &wordlist[695];
                    goto compare;
                  }
                break;
              case 1097:
                if (len == 4)
                  {
                    resword = &wordlist[696];
                    goto compare;
                  }
                break;
              case 1101:
                if (len == 3)
                  {
                    resword = &wordlist[697];
                    goto compare;
                  }
                break;
              case 1102:
                if (len == 4)
                  {
                    resword = &wordlist[698];
                    goto compare;
                  }
                break;
              case 1104:
                if (len == 3)
                  {
                    resword = &wordlist[699];
                    goto compare;
                  }
                break;
              case 1105:
                if (len == 4)
                  {
                    resword = &wordlist[700];
                    goto compare;
                  }
                break;
              case 1107:
                if (len == 3)
                  {
                    resword = &wordlist[701];
                    goto compare;
                  }
                break;
              case 1109:
                if (len == 3)
                  {
                    resword = &wordlist[702];
                    goto compare;
                  }
                break;
              case 1110:
                if (len == 3)
                  {
                    resword = &wordlist[703];
                    goto compare;
                  }
                break;
              case 1111:
                if (len == 3)
                  {
                    resword = &wordlist[704];
                    goto compare;
                  }
                break;
              case 1113:
                if (len == 3)
                  {
                    resword = &wordlist[705];
                    goto compare;
                  }
                break;
              case 1117:
                if (len == 2)
                  {
                    resword = &wordlist[706];
                    goto compare;
                  }
                break;
              case 1118:
                if (len == 2)
                  {
                    resword = &wordlist[707];
                    goto compare;
                  }
                break;
              case 1119:
                if (len == 2)
                  {
                    resword = &wordlist[708];
                    goto compare;
                  }
                break;
              case 1120:
                if (len == 3)
                  {
                    resword = &wordlist[709];
                    goto compare;
                  }
                break;
              case 1121:
                if (len == 3)
                  {
                    resword = &wordlist[710];
                    goto compare;
                  }
                break;
              case 1124:
                if (len == 2)
                  {
                    resword = &wordlist[711];
                    goto compare;
                  }
                break;
              case 1125:
                if (len == 2)
                  {
                    resword = &wordlist[712];
                    goto compare;
                  }
                break;
              case 1126:
                if (len == 2)
                  {
                    resword = &wordlist[713];
                    goto compare;
                  }
                break;
              case 1127:
                if (len == 2)
                  {
                    resword = &wordlist[714];
                    goto compare;
                  }
                break;
              case 1128:
                if (len == 4)
                  {
                    resword = &wordlist[715];
                    goto compare;
                  }
                break;
              case 1130:
                if (len == 4)
                  {
                    resword = &wordlist[716];
                    goto compare;
                  }
                break;
              case 1131:
                if (len == 3)
                  {
                    resword = &wordlist[717];
                    goto compare;
                  }
                break;
              case 1132:
                if (len == 3)
                  {
                    resword = &wordlist[718];
                    goto compare;
                  }
                break;
              case 1133:
                if (len == 3)
                  {
                    resword = &wordlist[719];
                    goto compare;
                  }
                break;
              case 1134:
                if (len == 3)
                  {
                    resword = &wordlist[720];
                    goto compare;
                  }
                break;
              case 1135:
                if (len == 3)
                  {
                    resword = &wordlist[721];
                    goto compare;
                  }
                break;
              case 1136:
                if (len == 3)
                  {
                    resword = &wordlist[722];
                    goto compare;
                  }
                break;
              case 1137:
                if (len == 3)
                  {
                    resword = &wordlist[723];
                    goto compare;
                  }
                break;
              case 1138:
                if (len == 3)
                  {
                    resword = &wordlist[724];
                    goto compare;
                  }
                break;
              case 1141:
                if (len == 3)
                  {
                    resword = &wordlist[725];
                    goto compare;
                  }
                break;
              case 1142:
                if (len == 3)
                  {
                    resword = &wordlist[726];
                    goto compare;
                  }
                break;
              case 1144:
                if (len == 3)
                  {
                    resword = &wordlist[727];
                    goto compare;
                  }
                break;
              case 1147:
                if (len == 3)
                  {
                    resword = &wordlist[728];
                    goto compare;
                  }
                break;
              case 1148:
                if (len == 3)
                  {
                    resword = &wordlist[729];
                    goto compare;
                  }
                break;
              case 1150:
                if (len == 2)
                  {
                    resword = &wordlist[730];
                    goto compare;
                  }
                break;
              case 1155:
                if (len == 3)
                  {
                    resword = &wordlist[731];
                    goto compare;
                  }
                break;
              case 1157:
                if (len == 3)
                  {
                    resword = &wordlist[732];
                    goto compare;
                  }
                break;
              case 1159:
                if (len == 3)
                  {
                    resword = &wordlist[733];
                    goto compare;
                  }
                break;
              case 1164:
                if (len == 2)
                  {
                    resword = &wordlist[734];
                    goto compare;
                  }
                break;
              case 1165:
                if (len == 2)
                  {
                    resword = &wordlist[735];
                    goto compare;
                  }
                break;
              case 1166:
                if (len == 2)
                  {
                    resword = &wordlist[736];
                    goto compare;
                  }
                break;
              case 1168:
                if (len == 3)
                  {
                    resword = &wordlist[737];
                    goto compare;
                  }
                break;
              case 1170:
                if (len == 2)
                  {
                    resword = &wordlist[738];
                    goto compare;
                  }
                break;
              case 1171:
                if (len == 3)
                  {
                    resword = &wordlist[739];
                    goto compare;
                  }
                break;
              case 1174:
                if (len == 3)
                  {
                    resword = &wordlist[740];
                    goto compare;
                  }
                break;
              case 1175:
                if (len == 2)
                  {
                    resword = &wordlist[741];
                    goto compare;
                  }
                break;
              case 1176:
                if (len == 2)
                  {
                    resword = &wordlist[742];
                    goto compare;
                  }
                break;
              case 1177:
                if (len == 2)
                  {
                    resword = &wordlist[743];
                    goto compare;
                  }
                break;
              case 1179:
                if (len == 2)
                  {
                    resword = &wordlist[744];
                    goto compare;
                  }
                break;
              case 1180:
                if (len == 3)
                  {
                    resword = &wordlist[745];
                    goto compare;
                  }
                break;
              case 1185:
                if (len == 3)
                  {
                    resword = &wordlist[746];
                    goto compare;
                  }
                break;
              case 1187:
                if (len == 2)
                  {
                    resword = &wordlist[747];
                    goto compare;
                  }
                break;
              case 1189:
                if (len == 2)
                  {
                    resword = &wordlist[748];
                    goto compare;
                  }
                break;
              case 1190:
                if (len == 2)
                  {
                    resword = &wordlist[749];
                    goto compare;
                  }
                break;
              case 1194:
                if (len == 3)
                  {
                    resword = &wordlist[750];
                    goto compare;
                  }
                break;
              case 1195:
                if (len == 3)
                  {
                    resword = &wordlist[751];
                    goto compare;
                  }
                break;
              case 1196:
                if (len == 3)
                  {
                    resword = &wordlist[752];
                    goto compare;
                  }
                break;
              case 1197:
                if (len == 3)
                  {
                    resword = &wordlist[753];
                    goto compare;
                  }
                break;
              case 1198:
                if (len == 3)
                  {
                    resword = &wordlist[754];
                    goto compare;
                  }
                break;
              case 1199:
                if (len == 3)
                  {
                    resword = &wordlist[755];
                    goto compare;
                  }
                break;
              case 1200:
                if (len == 3)
                  {
                    resword = &wordlist[756];
                    goto compare;
                  }
                break;
              case 1201:
                if (len == 2)
                  {
                    resword = &wordlist[757];
                    goto compare;
                  }
                break;
              case 1203:
                if (len == 3)
                  {
                    resword = &wordlist[758];
                    goto compare;
                  }
                break;
              case 1206:
                if (len == 3)
                  {
                    resword = &wordlist[759];
                    goto compare;
                  }
                break;
              case 1207:
                if (len == 4)
                  {
                    resword = &wordlist[760];
                    goto compare;
                  }
                break;
              case 1209:
                if (len == 3)
                  {
                    resword = &wordlist[761];
                    goto compare;
                  }
                break;
              case 1211:
                if (len == 2)
                  {
                    resword = &wordlist[762];
                    goto compare;
                  }
                break;
              case 1215:
                if (len == 2)
                  {
                    resword = &wordlist[763];
                    goto compare;
                  }
                break;
              case 1216:
                if (len == 2)
                  {
                    resword = &wordlist[764];
                    goto compare;
                  }
                break;
              case 1217:
                if (len == 2)
                  {
                    resword = &wordlist[765];
                    goto compare;
                  }
                break;
              case 1219:
                if (len == 3)
                  {
                    resword = &wordlist[766];
                    goto compare;
                  }
                break;
              case 1220:
                if (len == 3)
                  {
                    resword = &wordlist[767];
                    goto compare;
                  }
                break;
              case 1221:
                if (len == 3)
                  {
                    resword = &wordlist[768];
                    goto compare;
                  }
                break;
              case 1222:
                if (len == 3)
                  {
                    resword = &wordlist[769];
                    goto compare;
                  }
                break;
              case 1224:
                if (len == 2)
                  {
                    resword = &wordlist[770];
                    goto compare;
                  }
                break;
              case 1226:
                if (len == 3)
                  {
                    resword = &wordlist[771];
                    goto compare;
                  }
                break;
              case 1227:
                if (len == 2)
                  {
                    resword = &wordlist[772];
                    goto compare;
                  }
                break;
              case 1229:
                if (len == 3)
                  {
                    resword = &wordlist[773];
                    goto compare;
                  }
                break;
              case 1230:
                if (len == 3)
                  {
                    resword = &wordlist[774];
                    goto compare;
                  }
                break;
              case 1232:
                if (len == 3)
                  {
                    resword = &wordlist[775];
                    goto compare;
                  }
                break;
              case 1233:
                if (len == 3)
                  {
                    resword = &wordlist[776];
                    goto compare;
                  }
                break;
              case 1235:
                if (len == 4)
                  {
                    resword = &wordlist[777];
                    goto compare;
                  }
                break;
              case 1236:
                if (len == 2)
                  {
                    resword = &wordlist[778];
                    goto compare;
                  }
                break;
              case 1237:
                if (len == 3)
                  {
                    resword = &wordlist[779];
                    goto compare;
                  }
                break;
              case 1238:
                if (len == 2)
                  {
                    resword = &wordlist[780];
                    goto compare;
                  }
                break;
              case 1240:
                if (len == 3)
                  {
                    resword = &wordlist[781];
                    goto compare;
                  }
                break;
              case 1241:
                if (len == 2)
                  {
                    resword = &wordlist[782];
                    goto compare;
                  }
                break;
              case 1243:
                if (len == 4)
                  {
                    resword = &wordlist[783];
                    goto compare;
                  }
                break;
              case 1245:
                if (len == 3)
                  {
                    resword = &wordlist[784];
                    goto compare;
                  }
                break;
              case 1248:
                if (len == 3)
                  {
                    resword = &wordlist[785];
                    goto compare;
                  }
                break;
              case 1249:
                if (len == 3)
                  {
                    resword = &wordlist[786];
                    goto compare;
                  }
                break;
              case 1250:
                if (len == 2)
                  {
                    resword = &wordlist[787];
                    goto compare;
                  }
                break;
              case 1251:
                if (len == 2)
                  {
                    resword = &wordlist[788];
                    goto compare;
                  }
                break;
              case 1252:
                if (len == 2)
                  {
                    resword = &wordlist[789];
                    goto compare;
                  }
                break;
              case 1253:
                if (len == 2)
                  {
                    resword = &wordlist[790];
                    goto compare;
                  }
                break;
              case 1254:
                if (len == 3)
                  {
                    resword = &wordlist[791];
                    goto compare;
                  }
                break;
              case 1255:
                if (len == 3)
                  {
                    resword = &wordlist[792];
                    goto compare;
                  }
                break;
              case 1258:
                if (len == 3)
                  {
                    resword = &wordlist[793];
                    goto compare;
                  }
                break;
              case 1259:
                if (len == 3)
                  {
                    resword = &wordlist[794];
                    goto compare;
                  }
                break;
              case 1261:
                if (len == 2)
                  {
                    resword = &wordlist[795];
                    goto compare;
                  }
                break;
              case 1262:
                if (len == 2)
                  {
                    resword = &wordlist[796];
                    goto compare;
                  }
                break;
              case 1268:
                if (len == 4)
                  {
                    resword = &wordlist[797];
                    goto compare;
                  }
                break;
              case 1269:
                if (len == 3)
                  {
                    resword = &wordlist[798];
                    goto compare;
                  }
                break;
              case 1270:
                if (len == 3)
                  {
                    resword = &wordlist[799];
                    goto compare;
                  }
                break;
              case 1271:
                if (len == 3)
                  {
                    resword = &wordlist[800];
                    goto compare;
                  }
                break;
              case 1272:
                if (len == 3)
                  {
                    resword = &wordlist[801];
                    goto compare;
                  }
                break;
              case 1273:
                if (len == 3)
                  {
                    resword = &wordlist[802];
                    goto compare;
                  }
                break;
              case 1275:
                if (len == 3)
                  {
                    resword = &wordlist[803];
                    goto compare;
                  }
                break;
              case 1277:
                if (len == 2)
                  {
                    resword = &wordlist[804];
                    goto compare;
                  }
                break;
              case 1279:
                if (len == 3)
                  {
                    resword = &wordlist[805];
                    goto compare;
                  }
                break;
              case 1281:
                if (len == 3)
                  {
                    resword = &wordlist[806];
                    goto compare;
                  }
                break;
              case 1283:
                if (len == 2)
                  {
                    resword = &wordlist[807];
                    goto compare;
                  }
                break;
              case 1284:
                if (len == 3)
                  {
                    resword = &wordlist[808];
                    goto compare;
                  }
                break;
              case 1285:
                if (len == 2)
                  {
                    resword = &wordlist[809];
                    goto compare;
                  }
                break;
              case 1288:
                if (len == 3)
                  {
                    resword = &wordlist[810];
                    goto compare;
                  }
                break;
              case 1289:
                if (len == 3)
                  {
                    resword = &wordlist[811];
                    goto compare;
                  }
                break;
              case 1290:
                if (len == 2)
                  {
                    resword = &wordlist[812];
                    goto compare;
                  }
                break;
              case 1291:
                if (len == 4)
                  {
                    resword = &wordlist[813];
                    goto compare;
                  }
                break;
              case 1295:
                if (len == 3)
                  {
                    resword = &wordlist[814];
                    goto compare;
                  }
                break;
              case 1296:
                if (len == 3)
                  {
                    resword = &wordlist[815];
                    goto compare;
                  }
                break;
              case 1301:
                if (len == 2)
                  {
                    resword = &wordlist[816];
                    goto compare;
                  }
                break;
              case 1302:
                if (len == 3)
                  {
                    resword = &wordlist[817];
                    goto compare;
                  }
                break;
              case 1304:
                if (len == 2)
                  {
                    resword = &wordlist[818];
                    goto compare;
                  }
                break;
              case 1305:
                if (len == 2)
                  {
                    resword = &wordlist[819];
                    goto compare;
                  }
                break;
              case 1306:
                if (len == 3)
                  {
                    resword = &wordlist[820];
                    goto compare;
                  }
                break;
              case 1308:
                if (len == 3)
                  {
                    resword = &wordlist[821];
                    goto compare;
                  }
                break;
              case 1311:
                if (len == 3)
                  {
                    resword = &wordlist[822];
                    goto compare;
                  }
                break;
              case 1312:
                if (len == 3)
                  {
                    resword = &wordlist[823];
                    goto compare;
                  }
                break;
              case 1313:
                if (len == 2)
                  {
                    resword = &wordlist[824];
                    goto compare;
                  }
                break;
              case 1315:
                if (len == 3)
                  {
                    resword = &wordlist[825];
                    goto compare;
                  }
                break;
              case 1316:
                if (len == 2)
                  {
                    resword = &wordlist[826];
                    goto compare;
                  }
                break;
              case 1317:
                if (len == 3)
                  {
                    resword = &wordlist[827];
                    goto compare;
                  }
                break;
              case 1319:
                if (len == 2)
                  {
                    resword = &wordlist[828];
                    goto compare;
                  }
                break;
              case 1321:
                if (len == 4)
                  {
                    resword = &wordlist[829];
                    goto compare;
                  }
                break;
              case 1323:
                if (len == 3)
                  {
                    resword = &wordlist[830];
                    goto compare;
                  }
                break;
              case 1324:
                if (len == 3)
                  {
                    resword = &wordlist[831];
                    goto compare;
                  }
                break;
              case 1325:
                if (len == 3)
                  {
                    resword = &wordlist[832];
                    goto compare;
                  }
                break;
              case 1326:
                if (len == 3)
                  {
                    resword = &wordlist[833];
                    goto compare;
                  }
                break;
              case 1328:
                if (len == 3)
                  {
                    resword = &wordlist[834];
                    goto compare;
                  }
                break;
              case 1329:
                if (len == 3)
                  {
                    resword = &wordlist[835];
                    goto compare;
                  }
                break;
              case 1331:
                if (len == 3)
                  {
                    resword = &wordlist[836];
                    goto compare;
                  }
                break;
              case 1332:
                if (len == 3)
                  {
                    resword = &wordlist[837];
                    goto compare;
                  }
                break;
              case 1336:
                if (len == 3)
                  {
                    resword = &wordlist[838];
                    goto compare;
                  }
                break;
              case 1337:
                if (len == 3)
                  {
                    resword = &wordlist[839];
                    goto compare;
                  }
                break;
              case 1342:
                if (len == 3)
                  {
                    resword = &wordlist[840];
                    goto compare;
                  }
                break;
              case 1343:
                if (len == 2)
                  {
                    resword = &wordlist[841];
                    goto compare;
                  }
                break;
              case 1344:
                if (len == 2)
                  {
                    resword = &wordlist[842];
                    goto compare;
                  }
                break;
              case 1346:
                if (len == 3)
                  {
                    resword = &wordlist[843];
                    goto compare;
                  }
                break;
              case 1349:
                if (len == 4)
                  {
                    resword = &wordlist[844];
                    goto compare;
                  }
                break;
              case 1351:
                if (len == 2)
                  {
                    resword = &wordlist[845];
                    goto compare;
                  }
                break;
              case 1352:
                if (len == 2)
                  {
                    resword = &wordlist[846];
                    goto compare;
                  }
                break;
              case 1354:
                if (len == 3)
                  {
                    resword = &wordlist[847];
                    goto compare;
                  }
                break;
              case 1355:
                if (len == 2)
                  {
                    resword = &wordlist[848];
                    goto compare;
                  }
                break;
              case 1357:
                if (len == 3)
                  {
                    resword = &wordlist[849];
                    goto compare;
                  }
                break;
              case 1358:
                if (len == 2)
                  {
                    resword = &wordlist[850];
                    goto compare;
                  }
                break;
              case 1359:
                if (len == 2)
                  {
                    resword = &wordlist[851];
                    goto compare;
                  }
                break;
              case 1362:
                if (len == 2)
                  {
                    resword = &wordlist[852];
                    goto compare;
                  }
                break;
              case 1363:
                if (len == 3)
                  {
                    resword = &wordlist[853];
                    goto compare;
                  }
                break;
              case 1364:
                if (len == 3)
                  {
                    resword = &wordlist[854];
                    goto compare;
                  }
                break;
              case 1368:
                if (len == 2)
                  {
                    resword = &wordlist[855];
                    goto compare;
                  }
                break;
              case 1370:
                if (len == 2)
                  {
                    resword = &wordlist[856];
                    goto compare;
                  }
                break;
              case 1371:
                if (len == 3)
                  {
                    resword = &wordlist[857];
                    goto compare;
                  }
                break;
              case 1375:
                if (len == 3)
                  {
                    resword = &wordlist[858];
                    goto compare;
                  }
                break;
              case 1376:
                if (len == 3)
                  {
                    resword = &wordlist[859];
                    goto compare;
                  }
                break;
              case 1382:
                if (len == 3)
                  {
                    resword = &wordlist[860];
                    goto compare;
                  }
                break;
              case 1384:
                if (len == 4)
                  {
                    resword = &wordlist[861];
                    goto compare;
                  }
                break;
              case 1389:
                if (len == 3)
                  {
                    resword = &wordlist[862];
                    goto compare;
                  }
                break;
              case 1391:
                if (len == 2)
                  {
                    resword = &wordlist[863];
                    goto compare;
                  }
                break;
              case 1392:
                if (len == 2)
                  {
                    resword = &wordlist[864];
                    goto compare;
                  }
                break;
              case 1395:
                if (len == 3)
                  {
                    resword = &wordlist[865];
                    goto compare;
                  }
                break;
              case 1396:
                if (len == 3)
                  {
                    resword = &wordlist[866];
                    goto compare;
                  }
                break;
              case 1398:
                if (len == 3)
                  {
                    resword = &wordlist[867];
                    goto compare;
                  }
                break;
              case 1402:
                if (len == 2)
                  {
                    resword = &wordlist[868];
                    goto compare;
                  }
                break;
              case 1403:
                if (len == 2)
                  {
                    resword = &wordlist[869];
                    goto compare;
                  }
                break;
              case 1404:
                if (len == 2)
                  {
                    resword = &wordlist[870];
                    goto compare;
                  }
                break;
              case 1405:
                if (len == 2)
                  {
                    resword = &wordlist[871];
                    goto compare;
                  }
                break;
              case 1410:
                if (len == 3)
                  {
                    resword = &wordlist[872];
                    goto compare;
                  }
                break;
              case 1416:
                if (len == 3)
                  {
                    resword = &wordlist[873];
                    goto compare;
                  }
                break;
              case 1417:
                if (len == 2)
                  {
                    resword = &wordlist[874];
                    goto compare;
                  }
                break;
              case 1419:
                if (len == 3)
                  {
                    resword = &wordlist[875];
                    goto compare;
                  }
                break;
              case 1421:
                if (len == 3)
                  {
                    resword = &wordlist[876];
                    goto compare;
                  }
                break;
              case 1422:
                if (len == 3)
                  {
                    resword = &wordlist[877];
                    goto compare;
                  }
                break;
              case 1423:
                if (len == 3)
                  {
                    resword = &wordlist[878];
                    goto compare;
                  }
                break;
              case 1424:
                if (len == 2)
                  {
                    resword = &wordlist[879];
                    goto compare;
                  }
                break;
              case 1433:
                if (len == 3)
                  {
                    resword = &wordlist[880];
                    goto compare;
                  }
                break;
              case 1436:
                if (len == 2)
                  {
                    resword = &wordlist[881];
                    goto compare;
                  }
                break;
              case 1437:
                if (len == 2)
                  {
                    resword = &wordlist[882];
                    goto compare;
                  }
                break;
              case 1438:
                if (len == 2)
                  {
                    resword = &wordlist[883];
                    goto compare;
                  }
                break;
              case 1439:
                if (len == 2)
                  {
                    resword = &wordlist[884];
                    goto compare;
                  }
                break;
              case 1443:
                if (len == 3)
                  {
                    resword = &wordlist[885];
                    goto compare;
                  }
                break;
              case 1444:
                if (len == 3)
                  {
                    resword = &wordlist[886];
                    goto compare;
                  }
                break;
              case 1446:
                if (len == 2)
                  {
                    resword = &wordlist[887];
                    goto compare;
                  }
                break;
              case 1448:
                if (len == 2)
                  {
                    resword = &wordlist[888];
                    goto compare;
                  }
                break;
              case 1449:
                if (len == 3)
                  {
                    resword = &wordlist[889];
                    goto compare;
                  }
                break;
              case 1450:
                if (len == 3)
                  {
                    resword = &wordlist[890];
                    goto compare;
                  }
                break;
              case 1451:
                if (len == 3)
                  {
                    resword = &wordlist[891];
                    goto compare;
                  }
                break;
              case 1455:
                if (len == 3)
                  {
                    resword = &wordlist[892];
                    goto compare;
                  }
                break;
              case 1456:
                if (len == 3)
                  {
                    resword = &wordlist[893];
                    goto compare;
                  }
                break;
              case 1457:
                if (len == 3)
                  {
                    resword = &wordlist[894];
                    goto compare;
                  }
                break;
              case 1460:
                if (len == 4)
                  {
                    resword = &wordlist[895];
                    goto compare;
                  }
                break;
              case 1462:
                if (len == 3)
                  {
                    resword = &wordlist[896];
                    goto compare;
                  }
                break;
              case 1463:
                if (len == 3)
                  {
                    resword = &wordlist[897];
                    goto compare;
                  }
                break;
              case 1464:
                if (len == 3)
                  {
                    resword = &wordlist[898];
                    goto compare;
                  }
                break;
              case 1465:
                if (len == 3)
                  {
                    resword = &wordlist[899];
                    goto compare;
                  }
                break;
              case 1466:
                if (len == 2)
                  {
                    resword = &wordlist[900];
                    goto compare;
                  }
                break;
              case 1467:
                if (len == 3)
                  {
                    resword = &wordlist[901];
                    goto compare;
                  }
                break;
              case 1468:
                if (len == 3)
                  {
                    resword = &wordlist[902];
                    goto compare;
                  }
                break;
              case 1471:
                if (len == 3)
                  {
                    resword = &wordlist[903];
                    goto compare;
                  }
                break;
              case 1474:
                if (len == 3)
                  {
                    resword = &wordlist[904];
                    goto compare;
                  }
                break;
              case 1477:
                if (len == 3)
                  {
                    resword = &wordlist[905];
                    goto compare;
                  }
                break;
              case 1478:
                if (len == 3)
                  {
                    resword = &wordlist[906];
                    goto compare;
                  }
                break;
              case 1480:
                if (len == 2)
                  {
                    resword = &wordlist[907];
                    goto compare;
                  }
                break;
              case 1485:
                if (len == 2)
                  {
                    resword = &wordlist[908];
                    goto compare;
                  }
                break;
              case 1486:
                if (len == 3)
                  {
                    resword = &wordlist[909];
                    goto compare;
                  }
                break;
              case 1487:
                if (len == 3)
                  {
                    resword = &wordlist[910];
                    goto compare;
                  }
                break;
              case 1490:
                if (len == 2)
                  {
                    resword = &wordlist[911];
                    goto compare;
                  }
                break;
              case 1492:
                if (len == 3)
                  {
                    resword = &wordlist[912];
                    goto compare;
                  }
                break;
              case 1497:
                if (len == 3)
                  {
                    resword = &wordlist[913];
                    goto compare;
                  }
                break;
              case 1500:
                if (len == 2)
                  {
                    resword = &wordlist[914];
                    goto compare;
                  }
                break;
              case 1503:
                if (len == 2)
                  {
                    resword = &wordlist[915];
                    goto compare;
                  }
                break;
              case 1505:
                if (len == 2)
                  {
                    resword = &wordlist[916];
                    goto compare;
                  }
                break;
              case 1506:
                if (len == 3)
                  {
                    resword = &wordlist[917];
                    goto compare;
                  }
                break;
              case 1507:
                if (len == 2)
                  {
                    resword = &wordlist[918];
                    goto compare;
                  }
                break;
              case 1508:
                if (len == 3)
                  {
                    resword = &wordlist[919];
                    goto compare;
                  }
                break;
              case 1509:
                if (len == 3)
                  {
                    resword = &wordlist[920];
                    goto compare;
                  }
                break;
              case 1510:
                if (len == 2)
                  {
                    resword = &wordlist[921];
                    goto compare;
                  }
                break;
              case 1511:
                if (len == 2)
                  {
                    resword = &wordlist[922];
                    goto compare;
                  }
                break;
              case 1512:
                if (len == 3)
                  {
                    resword = &wordlist[923];
                    goto compare;
                  }
                break;
              case 1513:
                if (len == 2)
                  {
                    resword = &wordlist[924];
                    goto compare;
                  }
                break;
              case 1514:
                if (len == 2)
                  {
                    resword = &wordlist[925];
                    goto compare;
                  }
                break;
              case 1515:
                if (len == 4)
                  {
                    resword = &wordlist[926];
                    goto compare;
                  }
                break;
              case 1517:
                if (len == 3)
                  {
                    resword = &wordlist[927];
                    goto compare;
                  }
                break;
              case 1518:
                if (len == 3)
                  {
                    resword = &wordlist[928];
                    goto compare;
                  }
                break;
              case 1519:
                if (len == 3)
                  {
                    resword = &wordlist[929];
                    goto compare;
                  }
                break;
              case 1520:
                if (len == 3)
                  {
                    resword = &wordlist[930];
                    goto compare;
                  }
                break;
              case 1522:
                if (len == 3)
                  {
                    resword = &wordlist[931];
                    goto compare;
                  }
                break;
              case 1524:
                if (len == 2)
                  {
                    resword = &wordlist[932];
                    goto compare;
                  }
                break;
              case 1526:
                if (len == 3)
                  {
                    resword = &wordlist[933];
                    goto compare;
                  }
                break;
              case 1527:
                if (len == 3)
                  {
                    resword = &wordlist[934];
                    goto compare;
                  }
                break;
              case 1529:
                if (len == 2)
                  {
                    resword = &wordlist[935];
                    goto compare;
                  }
                break;
              case 1531:
                if (len == 3)
                  {
                    resword = &wordlist[936];
                    goto compare;
                  }
                break;
              case 1532:
                if (len == 2)
                  {
                    resword = &wordlist[937];
                    goto compare;
                  }
                break;
              case 1536:
                if (len == 3)
                  {
                    resword = &wordlist[938];
                    goto compare;
                  }
                break;
              case 1538:
                if (len == 2)
                  {
                    resword = &wordlist[939];
                    goto compare;
                  }
                break;
              case 1540:
                if (len == 2)
                  {
                    resword = &wordlist[940];
                    goto compare;
                  }
                break;
              case 1545:
                if (len == 3)
                  {
                    resword = &wordlist[941];
                    goto compare;
                  }
                break;
              case 1546:
                if (len == 2)
                  {
                    resword = &wordlist[942];
                    goto compare;
                  }
                break;
              case 1547:
                if (len == 2)
                  {
                    resword = &wordlist[943];
                    goto compare;
                  }
                break;
              case 1549:
                if (len == 3)
                  {
                    resword = &wordlist[944];
                    goto compare;
                  }
                break;
              case 1550:
                if (len == 3)
                  {
                    resword = &wordlist[945];
                    goto compare;
                  }
                break;
              case 1551:
                if (len == 2)
                  {
                    resword = &wordlist[946];
                    goto compare;
                  }
                break;
              case 1553:
                if (len == 2)
                  {
                    resword = &wordlist[947];
                    goto compare;
                  }
                break;
              case 1554:
                if (len == 3)
                  {
                    resword = &wordlist[948];
                    goto compare;
                  }
                break;
              case 1558:
                if (len == 2)
                  {
                    resword = &wordlist[949];
                    goto compare;
                  }
                break;
              case 1563:
                if (len == 2)
                  {
                    resword = &wordlist[950];
                    goto compare;
                  }
                break;
              case 1565:
                if (len == 2)
                  {
                    resword = &wordlist[951];
                    goto compare;
                  }
                break;
              case 1566:
                if (len == 3)
                  {
                    resword = &wordlist[952];
                    goto compare;
                  }
                break;
              case 1567:
                if (len == 3)
                  {
                    resword = &wordlist[953];
                    goto compare;
                  }
                break;
              case 1568:
                if (len == 3)
                  {
                    resword = &wordlist[954];
                    goto compare;
                  }
                break;
              case 1569:
                if (len == 3)
                  {
                    resword = &wordlist[955];
                    goto compare;
                  }
                break;
              case 1571:
                if (len == 2)
                  {
                    resword = &wordlist[956];
                    goto compare;
                  }
                break;
              case 1573:
                if (len == 3)
                  {
                    resword = &wordlist[957];
                    goto compare;
                  }
                break;
              case 1575:
                if (len == 2)
                  {
                    resword = &wordlist[958];
                    goto compare;
                  }
                break;
              case 1576:
                if (len == 2)
                  {
                    resword = &wordlist[959];
                    goto compare;
                  }
                break;
              case 1577:
                if (len == 2)
                  {
                    resword = &wordlist[960];
                    goto compare;
                  }
                break;
              case 1578:
                if (len == 3)
                  {
                    resword = &wordlist[961];
                    goto compare;
                  }
                break;
              case 1579:
                if (len == 4)
                  {
                    resword = &wordlist[962];
                    goto compare;
                  }
                break;
              case 1580:
                if (len == 2)
                  {
                    resword = &wordlist[963];
                    goto compare;
                  }
                break;
              case 1581:
                if (len == 3)
                  {
                    resword = &wordlist[964];
                    goto compare;
                  }
                break;
              case 1583:
                if (len == 2)
                  {
                    resword = &wordlist[965];
                    goto compare;
                  }
                break;
              case 1586:
                if (len == 2)
                  {
                    resword = &wordlist[966];
                    goto compare;
                  }
                break;
              case 1587:
                if (len == 2)
                  {
                    resword = &wordlist[967];
                    goto compare;
                  }
                break;
              case 1588:
                if (len == 3)
                  {
                    resword = &wordlist[968];
                    goto compare;
                  }
                break;
              case 1590:
                if (len == 2)
                  {
                    resword = &wordlist[969];
                    goto compare;
                  }
                break;
              case 1593:
                if (len == 3)
                  {
                    resword = &wordlist[970];
                    goto compare;
                  }
                break;
              case 1600:
                if (len == 2)
                  {
                    resword = &wordlist[971];
                    goto compare;
                  }
                break;
              case 1601:
                if (len == 3)
                  {
                    resword = &wordlist[972];
                    goto compare;
                  }
                break;
              case 1604:
                if (len == 3)
                  {
                    resword = &wordlist[973];
                    goto compare;
                  }
                break;
              case 1605:
                if (len == 3)
                  {
                    resword = &wordlist[974];
                    goto compare;
                  }
                break;
              case 1610:
                if (len == 2)
                  {
                    resword = &wordlist[975];
                    goto compare;
                  }
                break;
              case 1612:
                if (len == 2)
                  {
                    resword = &wordlist[976];
                    goto compare;
                  }
                break;
              case 1614:
                if (len == 2)
                  {
                    resword = &wordlist[977];
                    goto compare;
                  }
                break;
              case 1617:
                if (len == 2)
                  {
                    resword = &wordlist[978];
                    goto compare;
                  }
                break;
              case 1618:
                if (len == 2)
                  {
                    resword = &wordlist[979];
                    goto compare;
                  }
                break;
              case 1620:
                if (len == 3)
                  {
                    resword = &wordlist[980];
                    goto compare;
                  }
                break;
              case 1622:
                if (len == 2)
                  {
                    resword = &wordlist[981];
                    goto compare;
                  }
                break;
              case 1625:
                if (len == 3)
                  {
                    resword = &wordlist[982];
                    goto compare;
                  }
                break;
              case 1629:
                if (len == 3)
                  {
                    resword = &wordlist[983];
                    goto compare;
                  }
                break;
              case 1630:
                if (len == 2)
                  {
                    resword = &wordlist[984];
                    goto compare;
                  }
                break;
              case 1636:
                if (len == 2)
                  {
                    resword = &wordlist[985];
                    goto compare;
                  }
                break;
              case 1638:
                if (len == 2)
                  {
                    resword = &wordlist[986];
                    goto compare;
                  }
                break;
              case 1643:
                if (len == 3)
                  {
                    resword = &wordlist[987];
                    goto compare;
                  }
                break;
              case 1645:
                if (len == 2)
                  {
                    resword = &wordlist[988];
                    goto compare;
                  }
                break;
              case 1647:
                if (len == 3)
                  {
                    resword = &wordlist[989];
                    goto compare;
                  }
                break;
              case 1649:
                if (len == 3)
                  {
                    resword = &wordlist[990];
                    goto compare;
                  }
                break;
              case 1651:
                if (len == 2)
                  {
                    resword = &wordlist[991];
                    goto compare;
                  }
                break;
              case 1652:
                if (len == 2)
                  {
                    resword = &wordlist[992];
                    goto compare;
                  }
                break;
              case 1653:
                if (len == 3)
                  {
                    resword = &wordlist[993];
                    goto compare;
                  }
                break;
              case 1654:
                if (len == 3)
                  {
                    resword = &wordlist[994];
                    goto compare;
                  }
                break;
              case 1656:
                if (len == 2)
                  {
                    resword = &wordlist[995];
                    goto compare;
                  }
                break;
              case 1657:
                if (len == 2)
                  {
                    resword = &wordlist[996];
                    goto compare;
                  }
                break;
              case 1658:
                if (len == 2)
                  {
                    resword = &wordlist[997];
                    goto compare;
                  }
                break;
              case 1661:
                if (len == 2)
                  {
                    resword = &wordlist[998];
                    goto compare;
                  }
                break;
              case 1662:
                if (len == 2)
                  {
                    resword = &wordlist[999];
                    goto compare;
                  }
                break;
              case 1663:
                if (len == 2)
                  {
                    resword = &wordlist[1000];
                    goto compare;
                  }
                break;
              case 1664:
                if (len == 2)
                  {
                    resword = &wordlist[1001];
                    goto compare;
                  }
                break;
              case 1666:
                if (len == 3)
                  {
                    resword = &wordlist[1002];
                    goto compare;
                  }
                break;
              case 1667:
                if (len == 3)
                  {
                    resword = &wordlist[1003];
                    goto compare;
                  }
                break;
              case 1669:
                if (len == 2)
                  {
                    resword = &wordlist[1004];
                    goto compare;
                  }
                break;
              case 1672:
                if (len == 2)
                  {
                    resword = &wordlist[1005];
                    goto compare;
                  }
                break;
              case 1674:
                if (len == 2)
                  {
                    resword = &wordlist[1006];
                    goto compare;
                  }
                break;
              case 1678:
                if (len == 2)
                  {
                    resword = &wordlist[1007];
                    goto compare;
                  }
                break;
              case 1680:
                if (len == 3)
                  {
                    resword = &wordlist[1008];
                    goto compare;
                  }
                break;
              case 1687:
                if (len == 3)
                  {
                    resword = &wordlist[1009];
                    goto compare;
                  }
                break;
              case 1688:
                if (len == 2)
                  {
                    resword = &wordlist[1010];
                    goto compare;
                  }
                break;
              case 1689:
                if (len == 2)
                  {
                    resword = &wordlist[1011];
                    goto compare;
                  }
                break;
              case 1690:
                if (len == 2)
                  {
                    resword = &wordlist[1012];
                    goto compare;
                  }
                break;
              case 1691:
                if (len == 2)
                  {
                    resword = &wordlist[1013];
                    goto compare;
                  }
                break;
              case 1694:
                if (len == 2)
                  {
                    resword = &wordlist[1014];
                    goto compare;
                  }
                break;
              case 1697:
                if (len == 3)
                  {
                    resword = &wordlist[1015];
                    goto compare;
                  }
                break;
              case 1698:
                if (len == 3)
                  {
                    resword = &wordlist[1016];
                    goto compare;
                  }
                break;
              case 1701:
                if (len == 2)
                  {
                    resword = &wordlist[1017];
                    goto compare;
                  }
                break;
              case 1702:
                if (len == 3)
                  {
                    resword = &wordlist[1018];
                    goto compare;
                  }
                break;
              case 1715:
                if (len == 3)
                  {
                    resword = &wordlist[1019];
                    goto compare;
                  }
                break;
              case 1718:
                if (len == 2)
                  {
                    resword = &wordlist[1020];
                    goto compare;
                  }
                break;
              case 1719:
                if (len == 2)
                  {
                    resword = &wordlist[1021];
                    goto compare;
                  }
                break;
              case 1721:
                if (len == 3)
                  {
                    resword = &wordlist[1022];
                    goto compare;
                  }
                break;
              case 1722:
                if (len == 3)
                  {
                    resword = &wordlist[1023];
                    goto compare;
                  }
                break;
              case 1725:
                if (len == 2)
                  {
                    resword = &wordlist[1024];
                    goto compare;
                  }
                break;
              case 1727:
                if (len == 2)
                  {
                    resword = &wordlist[1025];
                    goto compare;
                  }
                break;
              case 1744:
                if (len == 3)
                  {
                    resword = &wordlist[1026];
                    goto compare;
                  }
                break;
              case 1752:
                if (len == 2)
                  {
                    resword = &wordlist[1027];
                    goto compare;
                  }
                break;
              case 1755:
                if (len == 2)
                  {
                    resword = &wordlist[1028];
                    goto compare;
                  }
                break;
              case 1760:
                if (len == 2)
                  {
                    resword = &wordlist[1029];
                    goto compare;
                  }
                break;
              case 1761:
                if (len == 2)
                  {
                    resword = &wordlist[1030];
                    goto compare;
                  }
                break;
              case 1762:
                if (len == 2)
                  {
                    resword = &wordlist[1031];
                    goto compare;
                  }
                break;
              case 1763:
                if (len == 2)
                  {
                    resword = &wordlist[1032];
                    goto compare;
                  }
                break;
              case 1764:
                if (len == 2)
                  {
                    resword = &wordlist[1033];
                    goto compare;
                  }
                break;
              case 1767:
                if (len == 2)
                  {
                    resword = &wordlist[1034];
                    goto compare;
                  }
                break;
              case 1768:
                if (len == 2)
                  {
                    resword = &wordlist[1035];
                    goto compare;
                  }
                break;
              case 1770:
                if (len == 3)
                  {
                    resword = &wordlist[1036];
                    goto compare;
                  }
                break;
              case 1775:
                if (len == 2)
                  {
                    resword = &wordlist[1037];
                    goto compare;
                  }
                break;
              case 1777:
                if (len == 3)
                  {
                    resword = &wordlist[1038];
                    goto compare;
                  }
                break;
              case 1782:
                if (len == 2)
                  {
                    resword = &wordlist[1039];
                    goto compare;
                  }
                break;
              case 1784:
                if (len == 2)
                  {
                    resword = &wordlist[1040];
                    goto compare;
                  }
                break;
              case 1786:
                if (len == 2)
                  {
                    resword = &wordlist[1041];
                    goto compare;
                  }
                break;
              case 1787:
                if (len == 2)
                  {
                    resword = &wordlist[1042];
                    goto compare;
                  }
                break;
              case 1788:
                if (len == 3)
                  {
                    resword = &wordlist[1043];
                    goto compare;
                  }
                break;
              case 1791:
                if (len == 2)
                  {
                    resword = &wordlist[1044];
                    goto compare;
                  }
                break;
              case 1796:
                if (len == 2)
                  {
                    resword = &wordlist[1045];
                    goto compare;
                  }
                break;
              case 1798:
                if (len == 3)
                  {
                    resword = &wordlist[1046];
                    goto compare;
                  }
                break;
              case 1802:
                if (len == 2)
                  {
                    resword = &wordlist[1047];
                    goto compare;
                  }
                break;
              case 1806:
                if (len == 2)
                  {
                    resword = &wordlist[1048];
                    goto compare;
                  }
                break;
              case 1814:
                if (len == 2)
                  {
                    resword = &wordlist[1049];
                    goto compare;
                  }
                break;
              case 1815:
                if (len == 2)
                  {
                    resword = &wordlist[1050];
                    goto compare;
                  }
                break;
              case 1818:
                if (len == 2)
                  {
                    resword = &wordlist[1051];
                    goto compare;
                  }
                break;
              case 1820:
                if (len == 2)
                  {
                    resword = &wordlist[1052];
                    goto compare;
                  }
                break;
              case 1822:
                if (len == 2)
                  {
                    resword = &wordlist[1053];
                    goto compare;
                  }
                break;
              case 1826:
                if (len == 2)
                  {
                    resword = &wordlist[1054];
                    goto compare;
                  }
                break;
              case 1829:
                if (len == 2)
                  {
                    resword = &wordlist[1055];
                    goto compare;
                  }
                break;
              case 1832:
                if (len == 2)
                  {
                    resword = &wordlist[1056];
                    goto compare;
                  }
                break;
              case 1837:
                if (len == 2)
                  {
                    resword = &wordlist[1057];
                    goto compare;
                  }
                break;
              case 1838:
                if (len == 2)
                  {
                    resword = &wordlist[1058];
                    goto compare;
                  }
                break;
              case 1843:
                if (len == 2)
                  {
                    resword = &wordlist[1059];
                    goto compare;
                  }
                break;
              case 1844:
                if (len == 2)
                  {
                    resword = &wordlist[1060];
                    goto compare;
                  }
                break;
              case 1845:
                if (len == 2)
                  {
                    resword = &wordlist[1061];
                    goto compare;
                  }
                break;
              case 1853:
                if (len == 3)
                  {
                    resword = &wordlist[1062];
                    goto compare;
                  }
                break;
              case 1854:
                if (len == 2)
                  {
                    resword = &wordlist[1063];
                    goto compare;
                  }
                break;
              case 1858:
                if (len == 2)
                  {
                    resword = &wordlist[1064];
                    goto compare;
                  }
                break;
              case 1862:
                if (len == 3)
                  {
                    resword = &wordlist[1065];
                    goto compare;
                  }
                break;
              case 1865:
                if (len == 2)
                  {
                    resword = &wordlist[1066];
                    goto compare;
                  }
                break;
              case 1868:
                if (len == 2)
                  {
                    resword = &wordlist[1067];
                    goto compare;
                  }
                break;
              case 1872:
                if (len == 2)
                  {
                    resword = &wordlist[1068];
                    goto compare;
                  }
                break;
              case 1876:
                if (len == 3)
                  {
                    resword = &wordlist[1069];
                    goto compare;
                  }
                break;
              case 1880:
                if (len == 2)
                  {
                    resword = &wordlist[1070];
                    goto compare;
                  }
                break;
              case 1886:
                if (len == 2)
                  {
                    resword = &wordlist[1071];
                    goto compare;
                  }
                break;
              case 1889:
                if (len == 2)
                  {
                    resword = &wordlist[1072];
                    goto compare;
                  }
                break;
              case 1893:
                if (len == 2)
                  {
                    resword = &wordlist[1073];
                    goto compare;
                  }
                break;
              case 1897:
                if (len == 2)
                  {
                    resword = &wordlist[1074];
                    goto compare;
                  }
                break;
              case 1898:
                if (len == 2)
                  {
                    resword = &wordlist[1075];
                    goto compare;
                  }
                break;
              case 1900:
                if (len == 2)
                  {
                    resword = &wordlist[1076];
                    goto compare;
                  }
                break;
              case 1901:
                if (len == 2)
                  {
                    resword = &wordlist[1077];
                    goto compare;
                  }
                break;
              case 1905:
                if (len == 2)
                  {
                    resword = &wordlist[1078];
                    goto compare;
                  }
                break;
              case 1907:
                if (len == 2)
                  {
                    resword = &wordlist[1079];
                    goto compare;
                  }
                break;
              case 1908:
                if (len == 2)
                  {
                    resword = &wordlist[1080];
                    goto compare;
                  }
                break;
              case 1910:
                if (len == 2)
                  {
                    resword = &wordlist[1081];
                    goto compare;
                  }
                break;
              case 1915:
                if (len == 2)
                  {
                    resword = &wordlist[1082];
                    goto compare;
                  }
                break;
              case 1922:
                if (len == 2)
                  {
                    resword = &wordlist[1083];
                    goto compare;
                  }
                break;
              case 1925:
                if (len == 2)
                  {
                    resword = &wordlist[1084];
                    goto compare;
                  }
                break;
              case 1926:
                if (len == 3)
                  {
                    resword = &wordlist[1085];
                    goto compare;
                  }
                break;
              case 1940:
                if (len == 2)
                  {
                    resword = &wordlist[1086];
                    goto compare;
                  }
                break;
              case 1950:
                if (len == 2)
                  {
                    resword = &wordlist[1087];
                    goto compare;
                  }
                break;
              case 1951:
                if (len == 2)
                  {
                    resword = &wordlist[1088];
                    goto compare;
                  }
                break;
              case 1958:
                if (len == 2)
                  {
                    resword = &wordlist[1089];
                    goto compare;
                  }
                break;
              case 1960:
                if (len == 2)
                  {
                    resword = &wordlist[1090];
                    goto compare;
                  }
                break;
              case 1961:
                if (len == 2)
                  {
                    resword = &wordlist[1091];
                    goto compare;
                  }
                break;
              case 1964:
                if (len == 2)
                  {
                    resword = &wordlist[1092];
                    goto compare;
                  }
                break;
              case 1969:
                if (len == 3)
                  {
                    resword = &wordlist[1093];
                    goto compare;
                  }
                break;
              case 1970:
                if (len == 2)
                  {
                    resword = &wordlist[1094];
                    goto compare;
                  }
                break;
              case 1974:
                if (len == 2)
                  {
                    resword = &wordlist[1095];
                    goto compare;
                  }
                break;
              case 1984:
                if (len == 2)
                  {
                    resword = &wordlist[1096];
                    goto compare;
                  }
                break;
              case 1987:
                if (len == 2)
                  {
                    resword = &wordlist[1097];
                    goto compare;
                  }
                break;
              case 1994:
                if (len == 2)
                  {
                    resword = &wordlist[1098];
                    goto compare;
                  }
                break;
              case 1995:
                if (len == 2)
                  {
                    resword = &wordlist[1099];
                    goto compare;
                  }
                break;
              case 2005:
                if (len == 2)
                  {
                    resword = &wordlist[1100];
                    goto compare;
                  }
                break;
              case 2011:
                if (len == 3)
                  {
                    resword = &wordlist[1101];
                    goto compare;
                  }
                break;
              case 2012:
                if (len == 2)
                  {
                    resword = &wordlist[1102];
                    goto compare;
                  }
                break;
              case 2015:
                if (len == 2)
                  {
                    resword = &wordlist[1103];
                    goto compare;
                  }
                break;
              case 2017:
                if (len == 3)
                  {
                    resword = &wordlist[1104];
                    goto compare;
                  }
                break;
              case 2018:
                if (len == 2)
                  {
                    resword = &wordlist[1105];
                    goto compare;
                  }
                break;
              case 2021:
                if (len == 3)
                  {
                    resword = &wordlist[1106];
                    goto compare;
                  }
                break;
              case 2023:
                if (len == 2)
                  {
                    resword = &wordlist[1107];
                    goto compare;
                  }
                break;
              case 2033:
                if (len == 2)
                  {
                    resword = &wordlist[1108];
                    goto compare;
                  }
                break;
              case 2035:
                if (len == 2)
                  {
                    resword = &wordlist[1109];
                    goto compare;
                  }
                break;
              case 2037:
                if (len == 2)
                  {
                    resword = &wordlist[1110];
                    goto compare;
                  }
                break;
              case 2038:
                if (len == 2)
                  {
                    resword = &wordlist[1111];
                    goto compare;
                  }
                break;
              case 2048:
                if (len == 2)
                  {
                    resword = &wordlist[1112];
                    goto compare;
                  }
                break;
              case 2051:
                if (len == 2)
                  {
                    resword = &wordlist[1113];
                    goto compare;
                  }
                break;
              case 2054:
                if (len == 2)
                  {
                    resword = &wordlist[1114];
                    goto compare;
                  }
                break;
              case 2065:
                if (len == 2)
                  {
                    resword = &wordlist[1115];
                    goto compare;
                  }
                break;
              case 2075:
                if (len == 2)
                  {
                    resword = &wordlist[1116];
                    goto compare;
                  }
                break;
              case 2077:
                if (len == 2)
                  {
                    resword = &wordlist[1117];
                    goto compare;
                  }
                break;
              case 2086:
                if (len == 3)
                  {
                    resword = &wordlist[1118];
                    goto compare;
                  }
                break;
              case 2087:
                if (len == 2)
                  {
                    resword = &wordlist[1119];
                    goto compare;
                  }
                break;
              case 2088:
                if (len == 2)
                  {
                    resword = &wordlist[1120];
                    goto compare;
                  }
                break;
              case 2093:
                if (len == 2)
                  {
                    resword = &wordlist[1121];
                    goto compare;
                  }
                break;
              case 2100:
                if (len == 3)
                  {
                    resword = &wordlist[1122];
                    goto compare;
                  }
                break;
              case 2116:
                if (len == 2)
                  {
                    resword = &wordlist[1123];
                    goto compare;
                  }
                break;
              case 2125:
                if (len == 2)
                  {
                    resword = &wordlist[1124];
                    goto compare;
                  }
                break;
              case 2132:
                if (len == 2)
                  {
                    resword = &wordlist[1125];
                    goto compare;
                  }
                break;
              case 2138:
                if (len == 2)
                  {
                    resword = &wordlist[1126];
                    goto compare;
                  }
                break;
              case 2140:
                if (len == 2)
                  {
                    resword = &wordlist[1127];
                    goto compare;
                  }
                break;
              case 2142:
                if (len == 2)
                  {
                    resword = &wordlist[1128];
                    goto compare;
                  }
                break;
              case 2143:
                if (len == 2)
                  {
                    resword = &wordlist[1129];
                    goto compare;
                  }
                break;
              case 2149:
                if (len == 3)
                  {
                    resword = &wordlist[1130];
                    goto compare;
                  }
                break;
              case 2153:
                if (len == 2)
                  {
                    resword = &wordlist[1131];
                    goto compare;
                  }
                break;
              case 2160:
                if (len == 2)
                  {
                    resword = &wordlist[1132];
                    goto compare;
                  }
                break;
              case 2161:
                if (len == 2)
                  {
                    resword = &wordlist[1133];
                    goto compare;
                  }
                break;
              case 2164:
                if (len == 2)
                  {
                    resword = &wordlist[1134];
                    goto compare;
                  }
                break;
              case 2165:
                if (len == 3)
                  {
                    resword = &wordlist[1135];
                    goto compare;
                  }
                break;
              case 2192:
                if (len == 2)
                  {
                    resword = &wordlist[1136];
                    goto compare;
                  }
                break;
              case 2196:
                if (len == 2)
                  {
                    resword = &wordlist[1137];
                    goto compare;
                  }
                break;
              case 2200:
                if (len == 2)
                  {
                    resword = &wordlist[1138];
                    goto compare;
                  }
                break;
              case 2221:
                if (len == 2)
                  {
                    resword = &wordlist[1139];
                    goto compare;
                  }
                break;
              case 2226:
                if (len == 2)
                  {
                    resword = &wordlist[1140];
                    goto compare;
                  }
                break;
              case 2245:
                if (len == 2)
                  {
                    resword = &wordlist[1141];
                    goto compare;
                  }
                break;
              case 2261:
                if (len == 2)
                  {
                    resword = &wordlist[1142];
                    goto compare;
                  }
                break;
              case 2262:
                if (len == 2)
                  {
                    resword = &wordlist[1143];
                    goto compare;
                  }
                break;
              case 2265:
                if (len == 2)
                  {
                    resword = &wordlist[1144];
                    goto compare;
                  }
                break;
              case 2275:
                if (len == 3)
                  {
                    resword = &wordlist[1145];
                    goto compare;
                  }
                break;
              case 2280:
                if (len == 2)
                  {
                    resword = &wordlist[1146];
                    goto compare;
                  }
                break;
              case 2290:
                if (len == 2)
                  {
                    resword = &wordlist[1147];
                    goto compare;
                  }
                break;
              case 2306:
                if (len == 2)
                  {
                    resword = &wordlist[1148];
                    goto compare;
                  }
                break;
              case 2311:
                if (len == 2)
                  {
                    resword = &wordlist[1149];
                    goto compare;
                  }
                break;
              case 2319:
                if (len == 2)
                  {
                    resword = &wordlist[1150];
                    goto compare;
                  }
                break;
              case 2350:
                if (len == 2)
                  {
                    resword = &wordlist[1151];
                    goto compare;
                  }
                break;
              case 2364:
                if (len == 2)
                  {
                    resword = &wordlist[1152];
                    goto compare;
                  }
                break;
              case 2372:
                if (len == 2)
                  {
                    resword = &wordlist[1153];
                    goto compare;
                  }
                break;
              case 2373:
                if (len == 2)
                  {
                    resword = &wordlist[1154];
                    goto compare;
                  }
                break;
              case 2375:
                if (len == 2)
                  {
                    resword = &wordlist[1155];
                    goto compare;
                  }
                break;
              case 2378:
                if (len == 2)
                  {
                    resword = &wordlist[1156];
                    goto compare;
                  }
                break;
              case 2411:
                if (len == 2)
                  {
                    resword = &wordlist[1157];
                    goto compare;
                  }
                break;
              case 2413:
                if (len == 3)
                  {
                    resword = &wordlist[1158];
                    goto compare;
                  }
                break;
              case 2414:
                if (len == 2)
                  {
                    resword = &wordlist[1159];
                    goto compare;
                  }
                break;
              case 2432:
                if (len == 2)
                  {
                    resword = &wordlist[1160];
                    goto compare;
                  }
                break;
              case 2449:
                if (len == 2)
                  {
                    resword = &wordlist[1161];
                    goto compare;
                  }
                break;
              case 2450:
                if (len == 2)
                  {
                    resword = &wordlist[1162];
                    goto compare;
                  }
                break;
              case 2466:
                if (len == 3)
                  {
                    resword = &wordlist[1163];
                    goto compare;
                  }
                break;
              case 2471:
                if (len == 2)
                  {
                    resword = &wordlist[1164];
                    goto compare;
                  }
                break;
              case 2472:
                if (len == 2)
                  {
                    resword = &wordlist[1165];
                    goto compare;
                  }
                break;
              case 2480:
                if (len == 2)
                  {
                    resword = &wordlist[1166];
                    goto compare;
                  }
                break;
              case 2493:
                if (len == 2)
                  {
                    resword = &wordlist[1167];
                    goto compare;
                  }
                break;
              case 2532:
                if (len == 2)
                  {
                    resword = &wordlist[1168];
                    goto compare;
                  }
                break;
              case 2548:
                if (len == 2)
                  {
                    resword = &wordlist[1169];
                    goto compare;
                  }
                break;
              case 2552:
                if (len == 2)
                  {
                    resword = &wordlist[1170];
                    goto compare;
                  }
                break;
              case 2558:
                if (len == 2)
                  {
                    resword = &wordlist[1171];
                    goto compare;
                  }
                break;
              case 2587:
                if (len == 2)
                  {
                    resword = &wordlist[1172];
                    goto compare;
                  }
                break;
              case 2597:
                if (len == 2)
                  {
                    resword = &wordlist[1173];
                    goto compare;
                  }
                break;
              case 2599:
                if (len == 2)
                  {
                    resword = &wordlist[1174];
                    goto compare;
                  }
                break;
              case 2605:
                if (len == 3)
                  {
                    resword = &wordlist[1175];
                    goto compare;
                  }
                break;
              case 2660:
                if (len == 3)
                  {
                    resword = &wordlist[1176];
                    goto compare;
                  }
                break;
              case 2685:
                if (len == 2)
                  {
                    resword = &wordlist[1177];
                    goto compare;
                  }
                break;
              case 2724:
                if (len == 2)
                  {
                    resword = &wordlist[1178];
                    goto compare;
                  }
                break;
              case 2755:
                if (len == 2)
                  {
                    resword = &wordlist[1179];
                    goto compare;
                  }
                break;
            }
          return 0;
        compare:
          {
            register const char *s = resword->name;

            if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
              return resword;
          }
        }
    }
  return 0;
}
