#include <stdio.h>
#include <ctype.h>

#include "stock.h"

#define MAX 300

void main( void )
{
  FILE *F;
  char name[MAX], *str/*, c*/;
  int lenght, max_l = 0, i, d_group = 0, d_len = -1;

  /*   console
  
  stock_t st;

  Init(&st);

  scanf("%c", &c);
  while (c != '\n')
  {
    PushBack(&st, c);
    scanf("%c", &c);
  }

  */

  scanf("%s", &name);

  if ((F = fopen(name, "rt")) == NULL)
    return;

  fseek(F, 0, SEEK_END);
  lenght = ftell(F);
  fseek(F, 0, SEEK_SET);
  lenght++;

  str = malloc(lenght * sizeof(char));

  fgets(str, lenght, F);

  fclose(F);

  for (i = 0; i < lenght - 1; i++)
  {
    if (isdigit(str[i]))
      if (d_group)
        d_len++;
      else
      {
        if (d_len > max_l)
          max_l = d_len;
        d_group = 1;
        d_len = 1;
      }
    else if (d_group)
      d_group = 0;
  }

  if (d_group && d_len > max_l)
    max_l = d_len;

  printf("%i", max_l);
}
