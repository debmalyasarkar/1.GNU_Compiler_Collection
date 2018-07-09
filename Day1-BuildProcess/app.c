#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("In main function\r\n");
  printf("PID %d\r\n",getpid());
  return 0;
}
