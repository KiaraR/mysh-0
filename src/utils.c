#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int i=0;

  (*argv) = (char**)malloc(sizeof(char**)*50);
  (*argv)[i]=(char*)malloc(sizeof(char*)*50);
  char *str = (char*)malloc(sizeof(char)*strlen(command));
  
  //str = (char*)command;
  strcpy(str,command);
  char* p;//=(char*)malloc(sizeof(char)*strlen(str));
  p = strtok(str, "' ',\t,\n");

  //empty command
  if(p==NULL){
    (*argc)=1;
    strcpy((*argv)[0],"");
    return;
  }

  while(p!=NULL) {
//    (*argv)[i++] = p;
      strcpy((*argv)[i],p);
      (*argv)[++i] = (char*)malloc(sizeof(char)*50);
    p = strtok(NULL,"' ',\t,\n");
  }
  *argc = i;
  free(str);
}
