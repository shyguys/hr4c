#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "lib.h"

const char PROG[] = "hr4c";
const char USAGE[] = "usage: hr4c [-h] [-p] [-i STR] [-l INT] [-o STR] [title]";
const char HELP[] =
    "usage: hr4c [-h] [-p] [-i STR] [-l INT] [-o STR] [title]\n"
    "\n"
    "positional arguments:\n"
    "  title               title to insert in center\n"
    "\n"
    "options:\n"
    "  -h, --help          show this help message and exit\n"
    "  -p, --as-paragraph  print two horizontal rules, BEGIN and END\n"
    "\n"
    "style proprties:\n"
    "  -i, --inner STR     inner character (default: -)\n"
    "  -l, --length INT    total character length (default: 80)\n"
    "  -o, --outer STR     outer character(s) (default: #)";

int main(int argc, char **argv) {
  int opt;
  bool asParagraph = false;
  char inner = '-';
  unsigned int length = 80;
  char outer[256] = "//";

  while ((opt = getopt(argc, argv, "hpi:l:o:")) != -1) {
    switch (opt) {
    case 'h':
      printf("%s\n", HELP);
      return 0;
    case 'p':
      asParagraph = true;
      break;
    case 'i':
      inner = optarg[0];
      break;
    case 'l':
      if (!strToUint(&length, optarg)) {
        fprintf(stderr, "%s: invalid int value '%s' -- l\n%s\n", PROG, optarg,
                USAGE);
        return 1;
      }
      break;
    case 'o':
      strStrip(outer, optarg);
      break;
    case ':':
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    case '?':
      fprintf(stderr, "%s\n", USAGE);
      return 1;
    }
  }
  char *title = argv[optind];

  int ok = 1;
  if (asParagraph) {
    ok = printAsParagraph(length, outer, inner, title);
  } else if (title != NULL) {
    ok = printTitled(length, outer, inner, title);
  } else {
    ok = printUntitled(length, outer, inner);
  }

  return !ok;
}
