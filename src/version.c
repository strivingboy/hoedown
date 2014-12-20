#include "version.h"

void hoedown_version(int *major, int *minor, int *revision) {
  *major = HOEDOWN_VERSION_MAJOR;
  *minor = HOEDOWN_VERSION_MINOR;
  *revision = HOEDOWN_VERSION_REVISION;
}

void hoedown_commonmark_version(int *major, int *minor, int *revision) {
  *major = HOEDOWN_COMMONMARK_VERSION_MAJOR;
  *minor = HOEDOWN_COMMONMARK_VERSION_MINOR;
  *revision = HOEDOWN_COMMONMARK_VERSION_REVISION;
}
