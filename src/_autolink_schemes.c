/* ANSI-C code produced by gperf version 3.0.4 */
/* Command-line: gperf -L ANSI-C -N hoedown_find_autolink_scheme -l -c -C -E -S 1 --ignore-case -m100 data/autolink_schemes.gperf  */
/* Computed positions: -k'1-3,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

/* maximum key range = 274, duplicates = 0 */

#ifndef GPERF_DOWNCASE
#define GPERF_DOWNCASE 1
static unsigned char gperf_downcase[256] =
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
     15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
     30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
     45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
     60,  61,  62,  63,  64,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106,
    107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
    122,  91,  92,  93,  94,  95,  96,  97,  98,  99, 100, 101, 102, 103, 104,
    105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
    135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
    150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194,
    195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209,
    210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    255
  };
#endif

#ifndef GPERF_CASE_MEMCMP
#define GPERF_CASE_MEMCMP 1
static int
gperf_case_memcmp (register const char *s1, register const char *s2, register unsigned int n)
{
  for (; n > 0;)
    {
      unsigned char c1 = gperf_downcase[(unsigned char)*s1++];
      unsigned char c2 = gperf_downcase[(unsigned char)*s2++];
      if (c1 == c2)
        {
          n--;
          continue;
        }
      return (int)c1 - (int)c2;
    }
  return 0;
}
#endif

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
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296,   7, 296, 296,  12, 296,
       29,   6,   7, 296,  11, 296, 296,   6, 296, 296,
      296, 296, 296, 296, 296,  13,  68,  37,  41,  31,
       96,  45, 108,  12,  27,  27,  73,   9,  64,  59,
        9,   6,  22,   6,  29,  93,  93,   8,  90, 142,
       28, 296, 296, 296, 296, 296, 296,  13,  68,  37,
       41,  31,  96,  45, 108,  12,  27,  27,  73,   9,
       64,  59,   9,   6,  22,   6,  29,  93,  93,   8,
       90, 142,  28, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296, 296, 296, 296, 296,
      296, 296, 296, 296, 296, 296
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
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
const char *
hoedown_find_autolink_scheme (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 164,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 23,
      MIN_HASH_VALUE = 22,
      MAX_HASH_VALUE = 295
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          register const char *resword;

          switch (key - 22)
            {
              case 0:
                if (len == 2)
                  {
                    resword = "ws";
                    goto compare;
                  }
                break;
              case 7:
                if (len == 3)
                  {
                    resword = "wss";
                    goto compare;
                  }
                break;
              case 8:
                if (len == 3)
                  {
                    resword = "sms";
                    goto compare;
                  }
                break;
              case 9:
                if (len == 2)
                  {
                    resword = "aw";
                    goto compare;
                  }
                break;
              case 10:
                if (len == 2)
                  {
                    resword = "im";
                    goto compare;
                  }
                break;
              case 11:
                if (len == 3)
                  {
                    resword = "mms";
                    goto compare;
                  }
                break;
              case 15:
                if (len == 4)
                  {
                    resword = "sips";
                    goto compare;
                  }
                break;
              case 16:
                if (len == 7)
                  {
                    resword = "ms-help";
                    goto compare;
                  }
                break;
              case 17:
                if (len == 3)
                  {
                    resword = "sip";
                    goto compare;
                  }
                break;
              case 19:
                if (len == 4)
                  {
                    resword = "maps";
                    goto compare;
                  }
                break;
              case 20:
                if (len == 3)
                  {
                    resword = "ipp";
                    goto compare;
                  }
                break;
              case 24:
                if (len == 3)
                  {
                    resword = "aim";
                    goto compare;
                  }
                break;
              case 25:
                if (len == 4)
                  {
                    resword = "imap";
                    goto compare;
                  }
                break;
              case 26:
                if (len == 5)
                  {
                    resword = "msrps";
                    goto compare;
                  }
                break;
              case 27:
                if (len == 4)
                  {
                    resword = "aaas";
                    goto compare;
                  }
                break;
              case 28:
                if (len == 4)
                  {
                    resword = "msrp";
                    goto compare;
                  }
                break;
              case 29:
                if (len == 3)
                  {
                    resword = "jms";
                    goto compare;
                  }
                break;
              case 30:
                if (len == 9)
                  {
                    resword = "paparazzi";
                    goto compare;
                  }
                break;
              case 31:
                if (len == 7)
                  {
                    resword = "z39.50s";
                    goto compare;
                  }
                break;
              case 33:
                if (len == 3)
                  {
                    resword = "aaa";
                    goto compare;
                  }
                break;
              case 34:
                if (len == 4)
                  {
                    resword = "iris";
                    goto compare;
                  }
                break;
              case 35:
                if (len == 4)
                  {
                    resword = "mtqp";
                    goto compare;
                  }
                break;
              case 36:
                if (len == 3)
                  {
                    resword = "rmi";
                    goto compare;
                  }
                break;
              case 38:
                if (len == 4)
                  {
                    resword = "itms";
                    goto compare;
                  }
                break;
              case 39:
                if (len == 9)
                  {
                    resword = "iris.xpcs";
                    goto compare;
                  }
                break;
              case 40:
                if (len == 3)
                  {
                    resword = "tip";
                    goto compare;
                  }
                break;
              case 42:
                if (len == 9)
                  {
                    resword = "iris.beep";
                    goto compare;
                  }
                break;
              case 44:
                if (len == 4)
                  {
                    resword = "wtai";
                    goto compare;
                  }
                break;
              case 46:
                if (len == 3)
                  {
                    resword = "res";
                    goto compare;
                  }
                break;
              case 47:
                if (len == 7)
                  {
                    resword = "z39.50r";
                    goto compare;
                  }
                break;
              case 48:
                if (len == 4)
                  {
                    resword = "rtsp";
                    goto compare;
                  }
                break;
              case 49:
                if (len == 3)
                  {
                    resword = "cap";
                    goto compare;
                  }
                break;
              case 50:
                if (len == 4)
                  {
                    resword = "pres";
                    goto compare;
                  }
                break;
              case 51:
                if (len == 4)
                  {
                    resword = "rtmp";
                    goto compare;
                  }
                break;
              case 53:
                if (len == 4)
                  {
                    resword = "icap";
                    goto compare;
                  }
                break;
              case 54:
                if (len == 4)
                  {
                    resword = "acap";
                    goto compare;
                  }
                break;
              case 57:
                if (len == 6)
                  {
                    resword = "market";
                    goto compare;
                  }
                break;
              case 58:
                if (len == 5)
                  {
                    resword = "steam";
                    goto compare;
                  }
                break;
              case 59:
                if (len == 4)
                  {
                    resword = "ircs";
                    goto compare;
                  }
                break;
              case 60:
                if (len == 8)
                  {
                    resword = "iris.lwz";
                    goto compare;
                  }
                break;
              case 61:
                if (len == 3)
                  {
                    resword = "apt";
                    goto compare;
                  }
                break;
              case 62:
                if (len == 7)
                  {
                    resword = "message";
                    goto compare;
                  }
                break;
              case 63:
                if (len == 5)
                  {
                    resword = "sieve";
                    goto compare;
                  }
                break;
              case 64:
                if (len == 4)
                  {
                    resword = "irc6";
                    goto compare;
                  }
                break;
              case 65:
                if (len == 3)
                  {
                    resword = "jar";
                    goto compare;
                  }
                break;
              case 66:
                if (len == 9)
                  {
                    resword = "adiumxtra";
                    goto compare;
                  }
                break;
              case 67:
                if (len == 3)
                  {
                    resword = "pop";
                    goto compare;
                  }
                break;
              case 68:
                if (len == 2)
                  {
                    resword = "ni";
                    goto compare;
                  }
                break;
              case 69:
                if (len == 8)
                  {
                    resword = "iris.xpc";
                    goto compare;
                  }
                break;
              case 70:
                if (len == 4)
                  {
                    resword = "snmp";
                    goto compare;
                  }
                break;
              case 71:
                if (len == 5)
                  {
                    resword = "msnim";
                    goto compare;
                  }
                break;
              case 72:
                if (len == 10)
                  {
                    resword = "soap.beeps";
                    goto compare;
                  }
                break;
              case 74:
                if (len == 9)
                  {
                    resword = "soap.beep";
                    goto compare;
                  }
                break;
              case 75:
                if (len == 7)
                  {
                    resword = "service";
                    goto compare;
                  }
                break;
              case 76:
                if (len == 8)
                  {
                    resword = "resource";
                    goto compare;
                  }
                break;
              case 77:
                if (len == 6)
                  {
                    resword = "mailto";
                    goto compare;
                  }
                break;
              case 78:
                if (len == 4)
                  {
                    resword = "data";
                    goto compare;
                  }
                break;
              case 80:
                if (len == 6)
                  {
                    resword = "magnet";
                    goto compare;
                  }
                break;
              case 84:
                if (len == 3)
                  {
                    resword = "mid";
                    goto compare;
                  }
                break;
              case 85:
                if (len == 6)
                  {
                    resword = "lastfm";
                    goto compare;
                  }
                break;
              case 86:
                if (len == 4)
                  {
                    resword = "palm";
                    goto compare;
                  }
                break;
              case 87:
                if (len == 9)
                  {
                    resword = "teamspeak";
                    goto compare;
                  }
                break;
              case 88:
                if (len == 10)
                  {
                    resword = "attachment";
                    goto compare;
                  }
                break;
              case 89:
                if (len == 3)
                  {
                    resword = "irc";
                    goto compare;
                  }
                break;
              case 90:
                if (len == 8)
                  {
                    resword = "platform";
                    goto compare;
                  }
                break;
              case 91:
                if (len == 4)
                  {
                    resword = "news";
                    goto compare;
                  }
                break;
              case 92:
                if (len == 7)
                  {
                    resword = "session";
                    goto compare;
                  }
                break;
              case 93:
                if (len == 10)
                  {
                    resword = "secondlife";
                    goto compare;
                  }
                break;
              case 94:
                if (len == 4)
                  {
                    resword = "crid";
                    goto compare;
                  }
                break;
              case 95:
                if (len == 6)
                  {
                    resword = "tn3270";
                    goto compare;
                  }
                break;
              case 96:
                if (len == 3)
                  {
                    resword = "git";
                    goto compare;
                  }
                break;
              case 97:
                if (len == 5)
                  {
                    resword = "gtalk";
                    goto compare;
                  }
                break;
              case 98:
                if (len == 3)
                  {
                    resword = "dns";
                    goto compare;
                  }
                break;
              case 99:
                if (len == 4)
                  {
                    resword = "xmpp";
                    goto compare;
                  }
                break;
              case 100:
                if (len == 4)
                  {
                    resword = "coap";
                    goto compare;
                  }
                break;
              case 101:
                if (len == 4)
                  {
                    resword = "dict";
                    goto compare;
                  }
                break;
              case 102:
                if (len == 3)
                  {
                    resword = "afs";
                    goto compare;
                  }
                break;
              case 104:
                if (len == 12)
                  {
                    resword = "gizmoproject";
                    goto compare;
                  }
                break;
              case 105:
                if (len == 3)
                  {
                    resword = "doi";
                    goto compare;
                  }
                break;
              case 108:
                if (len == 3)
                  {
                    resword = "afp";
                    goto compare;
                  }
                break;
              case 110:
                if (len == 4)
                  {
                    resword = "ed2k";
                    goto compare;
                  }
                break;
              case 112:
                if (len == 3)
                  {
                    resword = "cid";
                    goto compare;
                  }
                break;
              case 113:
                if (len == 3)
                  {
                    resword = "tag";
                    goto compare;
                  }
                break;
              case 115:
                if (len == 2)
                  {
                    resword = "gg";
                    goto compare;
                  }
                break;
              case 116:
                if (len == 5)
                  {
                    resword = "ldaps";
                    goto compare;
                  }
                break;
              case 117:
                if (len == 3)
                  {
                    resword = "xri";
                    goto compare;
                  }
                break;
              case 118:
                if (len == 4)
                  {
                    resword = "ldap";
                    goto compare;
                  }
                break;
              case 119:
                if (len == 6)
                  {
                    resword = "gopher";
                    goto compare;
                  }
                break;
              case 121:
                if (len == 7)
                  {
                    resword = "beshare";
                    goto compare;
                  }
                break;
              case 122:
                if (len == 4)
                  {
                    resword = "sftp";
                    goto compare;
                  }
                break;
              case 123:
                if (len == 3)
                  {
                    resword = "cvs";
                    goto compare;
                  }
                break;
              case 124:
                if (len == 3)
                  {
                    resword = "ftp";
                    goto compare;
                  }
                break;
              case 126:
                if (len == 6)
                  {
                    resword = "mumble";
                    goto compare;
                  }
                break;
              case 127:
                if (len == 7)
                  {
                    resword = "mupdate";
                    goto compare;
                  }
                break;
              case 128:
                if (len == 5)
                  {
                    resword = "vemmi";
                    goto compare;
                  }
                break;
              case 130:
                if (len == 3)
                  {
                    resword = "ipn";
                    goto compare;
                  }
                break;
              case 131:
                if (len == 4)
                  {
                    resword = "h323";
                    goto compare;
                  }
                break;
              case 132:
                if (len == 3)
                  {
                    resword = "smb";
                    goto compare;
                  }
                break;
              case 133:
                if (len == 3)
                  {
                    resword = "udp";
                    goto compare;
                  }
                break;
              case 134:
                if (len == 3)
                  {
                    resword = "oid";
                    goto compare;
                  }
                break;
              case 135:
                if (len == 5)
                  {
                    resword = "shttp";
                    goto compare;
                  }
                break;
              case 137:
                if (len == 23)
                  {
                    resword = "com-eventbrite-attendee";
                    goto compare;
                  }
                break;
              case 138:
                if (len == 15)
                  {
                    resword = "opaquelocktoken";
                    goto compare;
                  }
                break;
              case 139:
                if (len == 6)
                  {
                    resword = "things";
                    goto compare;
                  }
                break;
              case 141:
                if (len == 5)
                  {
                    resword = "notes";
                    goto compare;
                  }
                break;
              case 142:
                if (len == 6)
                  {
                    resword = "ut2004";
                    goto compare;
                  }
                break;
              case 143:
                if (len == 2)
                  {
                    resword = "go";
                    goto compare;
                  }
                break;
              case 144:
                if (len == 3)
                  {
                    resword = "hcp";
                    goto compare;
                  }
                break;
              case 145:
                if (len == 4)
                  {
                    resword = "tftp";
                    goto compare;
                  }
                break;
              case 146:
                if (len == 6)
                  {
                    resword = "telnet";
                    goto compare;
                  }
                break;
              case 148:
                if (len == 4)
                  {
                    resword = "nntp";
                    goto compare;
                  }
                break;
              case 150:
                if (len == 10)
                  {
                    resword = "javascript";
                    goto compare;
                  }
                break;
              case 151:
                if (len == 6)
                  {
                    resword = "soldat";
                    goto compare;
                  }
                break;
              case 152:
                if (len == 5)
                  {
                    resword = "about";
                    goto compare;
                  }
                break;
              case 153:
                if (len == 3)
                  {
                    resword = "nfs";
                    goto compare;
                  }
                break;
              case 154:
                if (len == 4)
                  {
                    resword = "icon";
                    goto compare;
                  }
                break;
              case 155:
                if (len == 5)
                  {
                    resword = "https";
                    goto compare;
                  }
                break;
              case 156:
                if (len == 11)
                  {
                    resword = "view-source";
                    goto compare;
                  }
                break;
              case 157:
                if (len == 4)
                  {
                    resword = "http";
                    goto compare;
                  }
                break;
              case 158:
                if (len == 7)
                  {
                    resword = "bitcoin";
                    goto compare;
                  }
                break;
              case 160:
                if (len == 3)
                  {
                    resword = "sgn";
                    goto compare;
                  }
                break;
              case 162:
                if (len == 5)
                  {
                    resword = "ymsgr";
                    goto compare;
                  }
                break;
              case 163:
                if (len == 8)
                  {
                    resword = "facetime";
                    goto compare;
                  }
                break;
              case 164:
                if (len == 6)
                  {
                    resword = "webcal";
                    goto compare;
                  }
                break;
              case 166:
                if (len == 6)
                  {
                    resword = "callto";
                    goto compare;
                  }
                break;
              case 168:
                if (len == 12)
                  {
                    resword = "xmlrpc.beeps";
                    goto compare;
                  }
                break;
              case 169:
                if (len == 11)
                  {
                    resword = "thismessage";
                    goto compare;
                  }
                break;
              case 170:
                if (len == 11)
                  {
                    resword = "xmlrpc.beep";
                    goto compare;
                  }
                break;
              case 174:
                if (len == 7)
                  {
                    resword = "content";
                    goto compare;
                  }
                break;
              case 175:
                if (len == 3)
                  {
                    resword = "geo";
                    goto compare;
                  }
                break;
              case 176:
                if (len == 4)
                  {
                    resword = "psyc";
                    goto compare;
                  }
                break;
              case 178:
                if (len == 6)
                  {
                    resword = "finger";
                    goto compare;
                  }
                break;
              case 179:
                if (len == 3)
                  {
                    resword = "dtn";
                    goto compare;
                  }
                break;
              case 181:
                if (len == 4)
                  {
                    resword = "feed";
                    goto compare;
                  }
                break;
              case 182:
                if (len == 6)
                  {
                    resword = "chrome";
                    goto compare;
                  }
                break;
              case 186:
                if (len == 3)
                  {
                    resword = "iax";
                    goto compare;
                  }
                break;
              case 187:
                if (len == 3)
                  {
                    resword = "tel";
                    goto compare;
                  }
                break;
              case 189:
                if (len == 5)
                  {
                    resword = "skype";
                    goto compare;
                  }
                break;
              case 190:
                if (len == 5)
                  {
                    resword = "rsync";
                    goto compare;
                  }
                break;
              case 194:
                if (len == 4)
                  {
                    resword = "file";
                    goto compare;
                  }
                break;
              case 195:
                if (len == 2)
                  {
                    resword = "tv";
                    goto compare;
                  }
                break;
              case 196:
                if (len == 18)
                  {
                    resword = "dlna-playcontainer";
                    goto compare;
                  }
                break;
              case 201:
                if (len == 7)
                  {
                    resword = "spotify";
                    goto compare;
                  }
                break;
              case 202:
                if (len == 15)
                  {
                    resword = "dlna-playsingle";
                    goto compare;
                  }
                break;
              case 204:
                if (len == 4)
                  {
                    resword = "fish";
                    goto compare;
                  }
                break;
              case 208:
                if (len == 3)
                  {
                    resword = "svn";
                    goto compare;
                  }
                break;
              case 209:
                if (len == 3)
                  {
                    resword = "ssh";
                    goto compare;
                  }
                break;
              case 211:
                if (len == 3)
                  {
                    resword = "mvn";
                    goto compare;
                  }
                break;
              case 212:
                if (len == 5)
                  {
                    resword = "xfire";
                    goto compare;
                  }
                break;
              case 213:
                if (len == 4)
                  {
                    resword = "info";
                    goto compare;
                  }
                break;
              case 215:
                if (len == 5)
                  {
                    resword = "proxy";
                    goto compare;
                  }
                break;
              case 216:
                if (len == 11)
                  {
                    resword = "xcon-userid";
                    goto compare;
                  }
                break;
              case 217:
                if (len == 7)
                  {
                    resword = "wyciwyg";
                    goto compare;
                  }
                break;
              case 221:
                if (len == 3)
                  {
                    resword = "dav";
                    goto compare;
                  }
                break;
              case 222:
                if (len == 7)
                  {
                    resword = "keyparc";
                    goto compare;
                  }
                break;
              case 224:
                if (len == 3)
                  {
                    resword = "urn";
                    goto compare;
                  }
                break;
              case 225:
                if (len == 16)
                  {
                    resword = "chrome-extension";
                    goto compare;
                  }
                break;
              case 232:
                if (len == 4)
                  {
                    resword = "xcon";
                    goto compare;
                  }
                break;
              case 233:
                if (len == 8)
                  {
                    resword = "ventrilo";
                    goto compare;
                  }
                break;
              case 236:
                if (len == 6)
                  {
                    resword = "unreal";
                    goto compare;
                  }
                break;
              case 241:
                if (len == 4)
                  {
                    resword = "bolo";
                    goto compare;
                  }
                break;
              case 251:
                if (len == 3)
                  {
                    resword = "dvb";
                    goto compare;
                  }
                break;
              case 255:
                if (len == 5)
                  {
                    resword = "query";
                    goto compare;
                  }
                break;
              case 273:
                if (len == 3)
                  {
                    resword = "nih";
                    goto compare;
                  }
                break;
            }
          return 0;
        compare:
          if ((((unsigned char)*str ^ (unsigned char)*resword) & ~32) == 0 && !gperf_case_memcmp (str, resword, len))
            return resword;
        }
    }
  return 0;
}
