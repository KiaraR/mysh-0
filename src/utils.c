#include "utils.h"
#include <string.h>

void mysh_parse_command(char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  char *str;
  strcpy(command,str);
  char *p = strtok(str, " \n\t");
  
  while(p != NULL) {
    *argv[*argc++] = p;
    p = strtok(NULL," ");
  }
  
  for(int i=0;i<*argc;i++)
    printf("%s", *argv[i]);
}
