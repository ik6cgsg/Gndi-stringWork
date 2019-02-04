#include "stock.h"

/* Initialization stock function */
void Init( stock_t *st )
{
  st->length = 1;
  st->string = malloc(st->length * sizeof(char));
  memset(st->string, '\0', sizeof(st->string));
} /* End of 'Init' function */

/* Add element in the stock end function */
void PushBack( stock_t *st, char c )
{
  char *str_tmp;

  st->length++;
  str_tmp = (char *)malloc(st->length * sizeof(char));

  strncpy(str_tmp, st->string, st->length - 2);
  st->string = (char *)malloc(st->length * sizeof(char));

  strncpy(st->string, str_tmp, st->length - 2);
  st->string[st->length - 2] = c;
  st->string[st->length - 1] = '\0';
} /* End of 'PushBack' function */
