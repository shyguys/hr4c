#include "lib.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Repeats a character `n` times.
// Parameters:
// - `char * out`: result will be written here (overwrite).
// - `char chr`: character to repeat.
// - `unsigned int n`: repitition amount.
// Returns:
// - Always `1 (success)`.
int chrRepeat(char *out, char chr, unsigned int n) {
  for (int i = 0; i < n; i++) {
    out[i] = chr;
  }
  out[n] = '\0';
  return 1;
}

// Converts a string to an unsigned int.
// Parameters:
// - `unsigned int * out`: result will be written here (overwrite). 0 on error.
// - `char * str`: the string to convert.
// Returns:
// - `0 (error)` if the string could not be converted, `1 (success)` otherwise.
int strToUint(unsigned int *out, char *str) {
  *out = 0;

  if (*str == '\0') {
    return 0;
  }

  for (int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) {
      *out = 0;
      return 0;
    }
    *out += (str[i] - '0') * pow(10, strlen(str) - 1 - i);
  }

  return 1;
}

// Inspects a string by printing information to stdout.
// Parameters:
// - `char * str`: the string to inspect.
// Returns:
// - Always `1 (success)`.
int strInspect(char *str) {
  printf("content : '%s'\n", str);
  printf("pointer : %p\n", str);
  printf("length  : %lu\n", strlen(str));
  for (int i = 0; i < strlen(str); i++) {
    printf("  '%c' at %p\n", str[i], (void *)&str[i]);
  }
  return 1;
}

// Strips a string of leading and trailing whitespaces.
// Parameters:
// - `char * out`: result will be written here (overwrite).
// - `char * str`: the string to strip.
// Returns:
// - Always `1 (success)`.
int strStrip(char *out, char *str) {
  while (isspace((unsigned char)*str))
    str++;
  char *end = str + strlen(str) - 1;
  while (isspace((unsigned char)*end))
    end--;
  end[1] = '\0';
  memmove(out, str, strlen(str) + 1);
  return 1;
}

int printUntitled(unsigned int length, char *outer, char inner) {
  int spareLength = length - strlen(outer) * 2 - 2;
  if (spareLength < 1) {
    fprintf(stderr, "[ERROR] length insufficient, %d more required\n",
            1 - spareLength);
    return 0;
  }
  char innerRepeated[spareLength + 1];
  chrRepeat(innerRepeated, inner, spareLength);
  printf("%s %s %s\n", outer, innerRepeated, outer);
  return 1;
}

int printTitled(unsigned int length, char *outer, char inner, char *title) {
  int spareLength = length - strlen(outer) * 2 - strlen(title) - 4;
  if (spareLength < 2) {
    fprintf(stderr, "[ERROR] length insufficient, %d more required\n",
            2 - spareLength);
    return 0;
  }
  int rightSpareLength = spareLength / 2;
  int leftSpareLength = spareLength - rightSpareLength;
  char leftInnerRepeated[leftSpareLength + 1];
  char rigthInnerRepeated[rightSpareLength + 1];
  chrRepeat(leftInnerRepeated, inner, leftSpareLength);
  chrRepeat(rigthInnerRepeated, inner, rightSpareLength);
  printf("%s %s %s %s %s\n", outer, leftInnerRepeated, title,
         rigthInnerRepeated, outer);
  return 1;
}

int printAsParagraph(unsigned int length, char *outer, char inner,
                     char *title) {
  char begin[256] = "BEGIN";
  char end[256] = "END";
  if (title != NULL) {
    strcat(begin, " ");
    strcat(begin, title);
    strcat(end, " ");
    strcat(end, title);
  }
  printTitled(length, outer, inner, begin);
  printTitled(length, outer, inner, end);
  return 1;
}
