#include "include/pipex/h"



void	error_message(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
	//EXIT_FAILURE = 1 エラー終了コードを意味する。
}

void	execute(char *cmd, char **env)
{
	char *s_cmd;
	char *path;

	s_cmd = 
}

void  child(char **argv, int *pipe_fd,  char **envp)
{
  int fd;

  fd = open(argv[1], O_RDONLY);
  dup2(fd, STDIN_FILENO); //STDIN_FILENO = 1;fdが指すファイルを入力として使うぜって意味
  close(fd);
　dup2(pipe_fd[1], STDOUT_FILENO);//標準出力されるところを、向きを変えて、パイプの書き込み端(pipe_fd[1])に出力されるように設定する.
  
}




int main(int argc, char **argv, char **envp)
{
  int pipe_fd[2];
  pid_t pid;

  if (argc != 5)
    error_message(ERR_ARGC);
  if (pipe(d.pipe_fd) < 0)
    error_message(ERR_PIPE);
  d.pid = fork();
  if (d.pid < 0)
    error_message(ERR_FORK);
  else if (d.pid == 0)
  {
	  child;
  }
  else if (d.pid > 0)
  {
	  parent;

  }
}
