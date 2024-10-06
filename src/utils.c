void  err_message(char *err_msg)
{
  perror(err_msg);
  exit(EXIT_FAILURE);
}
