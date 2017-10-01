#include "utils.h"
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  char *str = (char*)command;
  char *p = strtok(str, " \n\t");
  
  while(p != NULL) {
    *argv[*argc++] = p;
    p = strtok(NULL," ");
  }
}
