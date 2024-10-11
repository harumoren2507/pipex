#ifndef PIPEX_H
 #define PIPEX_H

/*--------------------Library--------------------*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"


/*--------------------Macro--------------------*/

#define ERR_ARGC "Invaild number of Arguments"
#define ERR_PIPE "Failed to open pipe"
#define ERR_FORK "Failed to forking"
#define ERR_CMD "Commond not found"
#define ERR_DUP "Error: dup2 failed"
#define ERR_EXECVE "Error: Command execution failed"
#define BUFFER_SIZE 1024
/*--------------------Struct--------------------*/


#endif

