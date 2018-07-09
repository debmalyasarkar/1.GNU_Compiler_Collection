/* Program to demonstrate the runtime linkage of a function */

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
  char *ptr;
  void *handle;

/* Step 1 : Declare Function Pointer */
  int (*fnptr)(int,int);
  printf("Start of %s function\n",__func__);
  getchar();

/* Step 2 : Request Link Loader to Load Specified Library
            and attach it to our address space */
  handle = dlopen("./libinit.so", RTLD_NOW);
  if(NULL == handle)
  {
    printf("Failed to Load Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Loading Success\n");
  getchar();

/* Step 3 : Lookup for the address of the required function */
  fnptr = dlsym(handle, "add");
  if(NULL == fnptr)
  {
    printf("Failed to Lookup Address of Shared Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Shared Object Address Lookup Success\n");
  getchar();

/* Step 4 : Invoke function through function pointer - Indirect Call */
  printf("Sum %d\n",(fnptr)(12,10));
  getchar();
  
/* Step 5 : Request Link Loader to Unload Library */
  if(0 != dlclose(handle))
  {
    printf("Failed to Unload Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Unloading Success\n");
  getchar();
  return 0;
}
