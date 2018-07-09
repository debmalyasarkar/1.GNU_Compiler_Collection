#include <stdio.h>

void x(void)
{
  static int var;
  printf("In function %s\n",__func__);
  printf("Value is %d\n",++var);
}

