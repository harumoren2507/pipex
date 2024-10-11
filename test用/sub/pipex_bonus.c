
void error_exit(char *message)
{
  perror(message);
  exit(1);
}

int open_input_file(const char *filename)
{
  int fd;
  fd = open(filename, O_RDONLY);
  if (fd == -1)
  {
    perror("open");
  }
  return (0);
}

int open_output_file(const char *filename)
{
  ind fd;

  fd = open(filename);
  if (fd == -1)
  {
    perror("open");
  }
  return (0);
}


void  execute_commond(char *commond, char **envp)
{
  char *args[];
  args = {"/bin/sh", "-c", commond, NULL};
  execve("/bin/sh", args, envp);
  error_exit("execve");
}

void run_pipe(char *input_file, char *output_file, int cmd_count)
{
  int fd[2];
  int infile_fd;
  pid_t pid;
  int i;

  infile_fd = 0;
  i = 0;

  infile_fd = open(input_file, O_RDONLY);
  if (infile_fd < 0)
    error_exit("open input");

  while (i < cmd_count)
  {
    if (pipe(fd) == -1)
      error_exit("pipe");

    pid = fork();
    if (pid = -1)
      error_exit("fork");
  }

  if (pid == 0)//子プロセス
  {
    close(fd[0]);

    if (i == 0)//最初のコマンドの場合
      dup2(infile_fd, SIDIN_FILENO);
      //STDIN_FILENO = 0
    else 
      dup2(prev_fd, STDIN_FILENO);

    //標準出力の設定

    if (i == cmd_count - 1)
    {
      int out_fd = open(output_file, O_WEONLY | O_CREAT | O_TRUNC, 0644);
      if (out_fd < 0)
        error_exit("open output");
      dup2(out_fd, STDOUT_FILENO);
      close(out_fd);
    }
    else 
      dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    close(infile_fd);
  }
}
