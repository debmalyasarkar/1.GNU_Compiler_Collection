#include <stdio.h>

void x(void)
{
  printf("In function 1 %s\n",__func__);
}

void y(void)
{
  printf("In function 1 %s\n",__func__);
  x();
}
