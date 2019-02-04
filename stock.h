#ifndef __stock_h_
#define __stock_h_

#include <stdlib.h>
#include <string.h>

typedef struct stock_t
{
  char *string;
  int length;
} stock_t;

/* Initialization stock function */
void Init( stock_t *st );

/* Add element in the stock end function */
void PushBack( stock_t *st, char c );


#endif /* __stock_h_ */
