#!/usr/bin/python
"""
Reads the official Unicode case folding listing,
and produces a GPERF dataset for UTF-8, using full
case folding and common mappings.

Case folding listing available at:
http://ftp.unicode.org/Public/UNIDATA/CaseFolding.txt
"""

import sys

def encode_codepoints(s):
  codepoints = (unichr(int(c,16)) for c in s.split(" "))
  return u''.join(codepoints).encode("utf-8")

def escape_string(s):
  contents = (("\\x%02X" % ord(c)) for c in s)
  return '"' + ''.join(contents) + '"'


sys.stdout.write("""
struct case_mapping {
  const char *name;
  const char *value;
  size_t length;
};
%%
""");

while True:
  line = sys.stdin.readline()
  if not line: break

  # 1. PREPROCESS LINE
  # ------------------

  # Remove comment section
  if "#" in line:
    line = line[:line.index("#")]

  # Remove trailing spacing
  line = line.rstrip()

  # Skip line if empty
  if not line: continue


  # 2. PARSE LINE
  # -------------

  # Split in tokens
  tokens = line.split(";")
  if len(tokens) != 4 or len(tokens[3]) > 0:
    raise "Invalid mapping line"

  # Extract mapping type
  type = tokens[1][1:]
  if type not in ("C", "F", "S", "T"):
    raise "Invalid mapping type"

  # Filter C and F
  if type not in ("C", "F"):
    continue

  # Encode key and destination codepoints
  key = encode_codepoints(tokens[0])
  value = encode_codepoints(tokens[2][1:])


  # 3. OUTPUT MAPPING
  # -----------------

  line = ", ".join([escape_string(key), escape_string(value), str(len(value))]) + "\n"
  sys.stdout.write(line)
