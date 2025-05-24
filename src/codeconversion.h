#ifndef CODECONVERSION_H
#define CODECONVERSION_H

#include <stdint.h>

typedef struct {
  uint32_t utf8;
  uint32_t sjis;
} utf16ToSjis_t;

#ifdef __cplusplus
extern "C" {
#endif
int utf8ToUtf16(const char *utf8, uint16_t *utf16);
int utf16ToSjis(uint16_t utf16, uint16_t *sjis);
#ifdef __cplusplus
}
#endif
extern const utf16ToSjis_t utf16ToSjisTable[7724];
#endif /* CODECONVERSION_H */