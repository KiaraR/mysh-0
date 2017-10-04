#include <string.h>
#include <unistd.h>
#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int do_cd(int argc, char** argv) {  
if (!validate_cd_argv(argc, argv))
    return -1;
else if(argc==1) return chdir("~");
return chdir(argv[1]);
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char* dir;
  if(dir = getcwd(NULL, BUFSIZ)) {
    printf("%s\n", dir);
    free(dir);
    return 0;
  } else return -1;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc>2||!strcmp(argv[0],"cd")) return 0;
  return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc>1||strcmp(argv[0],"pwd")) return 0;
   return 1;
}
