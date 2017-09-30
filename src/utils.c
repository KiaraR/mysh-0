#include "utils.h"
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
  //char *str = strdup(command);
  char *p = strtok(command, " \n\t");
  
  while(p != NULL) {
    argv[*argc++] = p;
    p = strtok(NULL," ");
  }
  
  for(int i=0;i<*argc;i++)
    fprintf(stdin,"%s",argv);
}
