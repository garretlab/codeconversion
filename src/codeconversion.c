#include "codeconversion.h"

int utf8ToUtf16(const char *utf8, uint16_t *utf16) {
  if (((uint8_t)*utf8 & 0x80) == 0) {
    *utf16 = *utf8 & 0x7f;
    return 1;
  } else if (((uint8_t)*utf8 & 0xe0) == 0xc0) {
    *utf16 = (*utf8 & 0x1f) << 6 | (*(utf8 + 1) & 0x3f);
    return 2;
  } else if (((uint8_t)*utf8 & 0xf0) == 0xe0) {
    *utf16 = (*utf8 & 0x0f) << 12 | (*(utf8 + 1) & 0x3f) << 6 | (*(utf8 + 2) & 0x3f);
    return 3;
  } else if (((uint8_t)*utf8 & 0xf0) == 0xf0) {
    *utf16 = 0x25a1;
    return 4;
  }
  return 0;
}

int utf16ToSjis(uint16_t utf16, uint16_t *sjis) {
  int left = 0;
  int right = sizeof(utf16ToSjisTable) / sizeof(utf16ToSjisTable[0]);
  int middle;

  while (left <= right) {
    middle = (left + right) / 2;
    if (utf16ToSjisTable[middle].utf8 == utf16) {
      *sjis = utf16ToSjisTable[middle].sjis;
      return 1;
    } else if (utf16ToSjisTable[middle].utf8 < utf16) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return 0;
}