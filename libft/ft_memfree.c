#include "libft.h"

void  ft_memfree(void *ptr)
{
  if (!ptr)
    return ;
  free(ptr);
  ptr = NULL;
}
