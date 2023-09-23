#ifndef LIB_H
#define LIB_H

int chrRepeat(char *out, char chr, int n);

int uintOfStr(unsigned int *out, char *str);

int strInspect(char *str);

int strStrip(char *out, char *str);

int printAsParagraph(int length, char *outer, char inner, char *title);

int printTitled(int length, char *outer, char inner, char *title);

int printUntitled(int length, char *outer, char inner);

#endif
