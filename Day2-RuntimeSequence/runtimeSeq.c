/* Program to show the sequence of execution of appplication with runtime */
/* Compile with -nostartfiles flag to tell linker not to use standard runtime */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void _start(void);
void _fini(void);

/* Application Functions */
int sub_function(void)
{
  printf("Running %s\n",__func__);
  return 0;
}

int main(void)
{
  printf("Running %s\n",__func__);
  printf("PID : %d\n",getpid());
  sub_function();
}

/* Runtime Functions */
void _start(void)
{
  printf("Running %s\n",__func__);

  /* Run Application - Starting Point */
  /* The name of the application can also be changed */ 
  main();

  /* Register _fini() to be executed on exit */
  /* Causes Segmentation Fault if exit() is not called */
  if(0 != atexit(_fini))
  {
    printf("Cannot Set Exit Function\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}

void _fini(void)
{
  printf("Running %s\n",__func__);
}

