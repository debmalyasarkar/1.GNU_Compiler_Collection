#include <stdio.h>

void x(void)
{
  printf("In function %s\n",__func__);
}

void y(void)
{
  printf("In function %s\n",__func__);
  /* Some External function from another library */
  b();
}
