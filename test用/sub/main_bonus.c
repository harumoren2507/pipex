#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
  if (argc != 5)//なぜ5? 
  {
    fprintf(stderr, "使用方法: %s [入力ファイル] コマンド1 [コマンド２...] [出力ファイル]\n", argv[0]);
    exit(1);
  }
  char *input_file = argv[1];
  char *output_file = argv[argc - 1];
  int cmd_count = argc - 3;
  char **commonds = &argv[2];
  return (0);
}

