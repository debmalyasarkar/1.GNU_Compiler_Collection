/* Program to demonstrate the runtime linkage of a function 
   and usage of the RTLD_DEEPBIND Flag */

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main()
{
  char *ptr;
  void *handle;
  void *handle1;

/* Step 1 : Declare Function Pointer */
  void (*fnptr)(void);
  printf("Start of %s function\n",__func__);
  getchar();

/* Step 2 : Requesting dependent library to be loaded first */
/* Shares all of its symbols as global */
  handle1 = dlopen("./libdep.so", RTLD_NOW | RTLD_GLOBAL);
  if(NULL == handle1)
  {
    printf("Failed to Load Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Loading Success\n");
  getchar();

/* Step 3 : Request Link Loader to Load Specified Library
            and attach it to our address space */
/* If RTLD_DEEPBIND is specified, the objects does not use the
   global symbols from other libraries. Instead it uses the local
   symbols to resolve dependencies */
/* If RTLD_DEEPBIND is not specified, the shared object does not 
   use local symbols and uses the global symbols instead. */
  handle = dlopen("./libinit.so", RTLD_NOW | RTLD_DEEPBIND);
  if(NULL == handle)
  {
    printf("Failed to Load Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Loading Success\n");
  getchar();

/* Step 4 : Lookup for the address of the required function */
  fnptr = dlsym(handle, "y");
  if(NULL == fnptr)
  {
    printf("Failed to Lookup Address of Shared Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Shared Object Address Lookup Success\n");
  getchar();

/* Step 5 : Invoke function through function pointer - Indirect Call */
  (fnptr)();
  getchar();
  
/* Step 6 : Request Link Loader to Unload Library */
  if(0 != dlclose(handle))
  {
    printf("Failed to Unload Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Unloading Success\n");
  getchar();
  return 0;
}

