#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"

/*
  Repeats a character n times.

  Returns:
    Always 1 (success).
*/
int chrRepeat(char *out, char chr, int n)
{
  for (int i = 0; i < n; i++)
  {
    out[i] = chr;
  }
  out[n] = '\0';
  return 1;
}

/*
  Converts a string to an (unsigned) int. String must be greater than 0.

  Returns:
    0 (error) if the string is not a positive number, 1 (success) otherwise.
*/
int uintOfStr(unsigned int *out, char *str)
{
  *out = 0;

  if (*str == '\0')
  {
    return 0;
  }

  for (int i = 0; i < strlen(str); i++)
  {
    if (!isdigit(str[i]))
    {
      *out = 0;
      return 0;
    }
    *out += (str[i] - '0') * pow(10, strlen(str) - 1 - i);
  }

  return 1;
}

/*
  Inspects a string by printing information to stdout.

  Returns:
    Always 1 (success).
*/
int strInspect(char *str)
{
  printf("content : '%s'\n", str);
  printf("pointer : %p\n", str);
  printf("length  : %lu\n", strlen(str));
  for (int i = 0; i < strlen(str); i++)
  {
    printf("  '%c' at %p\n", str[i], (void *)&str[i]);
  }
  return 1;
}

/*
  Strips a string of leading and trailing whitespaces.

  Returns:
    Always 1 (success).
*/
int strStrip(char *out, char *str)
{
  while (isspace((unsigned char)*str))
    str++;
  char *end = str + strlen(str) - 1;
  while (isspace((unsigned char)*end))
    end--;
  end[1] = '\0';
  memmove(out, str, strlen(str) + 1);
  return 1;
}

int printAsParagraph(int length, char *outer, char inner, char *title)
{
  char begin[256] = "BEGIN";
  char end[256] = "END";
  if (title != NULL)
  {
    strcat(begin, " ");
    strcat(begin, title);
    strcat(end, " ");
    strcat(end, title);
  }
  printTitled(length, outer, inner, begin);
  printTitled(length, outer, inner, end);
  return 1;
}

int printTitled(int length, char *outer, char inner, char *title)
{
  int spareLength = length - strlen(outer) * 2 - strlen(title) - 4;
  if (spareLength < 2)
  {
    fprintf(stderr, "[ERROR] length insufficient, %d more required\n", 2 - spareLength);
    return 0;
  }
  int rightSpareLength = spareLength / 2;
  int leftSpareLength = spareLength - rightSpareLength;
  char leftInnerRepeated[leftSpareLength + 1];
  char rigthInnerRepeated[rightSpareLength + 1];
  chrRepeat(leftInnerRepeated, inner, leftSpareLength);
  chrRepeat(rigthInnerRepeated, inner, rightSpareLength);
  printf("%s %s %s %s %s\n", outer, leftInnerRepeated, title, rigthInnerRepeated, outer);
  return 1;
}

int printUntitled(int length, char *outer, char inner)
{
  int spareLength = length - strlen(outer) * 2 - 2;
  if (spareLength < 1)
  {
    fprintf(stderr, "[ERROR] length insufficient, %d more required\n", 1 - spareLength);
    return 0;
  }
  char innerRepeated[spareLength];
  chrRepeat(innerRepeated, inner, spareLength);
  printf("%s %s %s\n", outer, innerRepeated, outer);
  return 1;
}
