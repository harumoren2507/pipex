#include "../include/pipex.h"

void  err_message(char *err_msg)
{
  perror(err_msg);
  exit(EXIT_FAILURE);
}

int 	open_file(char *file, int stdin_or_stdout)
{
	int fd;

	if (stdin_or_stdout == 0)
		fd = open(file, O_RDONLY, 0777);
	if (stdin_or_stdout == 1)
		fd = open(file, O_RDONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}
/*
char *get_path(char *cmd, char **env)
{
	//
	//
}
*/
int main(void)
{
	int input_fd;
	int output_fd;
	char buffer[100];
	ssize_t bytes_read, bytes_written;
	
	//入力ファイルのテスト
	input_fd = open_file("test_input.txt", 0);
	printf("入力ファイルopen: fd = %d\n", input_fd);
	bytes_read = read(input_fd, buffer, sizeof(buffer) - 1);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("読み取った内容; %s\n", buffer);
	}
	close(input_fd);

	//出力ファイルのテスト
	
	output_fd = open_file("test_output.txt", 1);
	printf("出力ファイルopen: fd = %d\n", output_fd);

	char *message = "これはテストメッセージです\n";
	bytes_written = write(output_fd, message, strlen(message));
	printf("書き込んだバイト数; %zd\n", bytes_written);
	close(output_fd);

	input_fd = open_file("/non_existent_directory/test.txt", 0);
	return (0);
}
