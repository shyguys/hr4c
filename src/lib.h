#ifndef HR4C_LIB_H
#define HR4C_LIB_H

int chrRepeat(char *out, char chr, unsigned int n);

int strToUint(unsigned int *out, char *str);

int strInspect(char *str);

int strStrip(char *out, char *str);

int printUntitled(unsigned int length, char *outer, char inner);

int printTitled(unsigned int length, char *outer, char inner, char *title);

int printAsParagraph(unsigned int length, char *outer, char inner, char *title);

#endif // HR4C_LIB_H
