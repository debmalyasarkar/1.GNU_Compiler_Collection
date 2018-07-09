#include <stdio.h>

void a(void)
{
  printf("In function %s\n",__func__);
}

void b(void)
{
  printf("In function %s\n",__func__);
}
