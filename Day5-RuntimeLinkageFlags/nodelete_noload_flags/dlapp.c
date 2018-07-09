/* Program to demonstrate the runtime linkage of a function 
   with reload functionality */

/* Without RTLD_NODELETE and RTLD_NOLOAD Flags the function
   does not retain value of variable and reloads completely */

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

/* Step 2 : Request Link Loader to Load Specified Library
            and attach it to our address space */
/* RTLD_NODELETE - Do not unload the shared object during dlclose(). 
   Consequently, the object's static variables are not reinitialized 
   if the object is reloaded with dlopen() at a later time. */

  handle = dlopen("./libinit.so", RTLD_NOW | RTLD_NODELETE);
  if(NULL == handle)
  {
    printf("Failed to Load Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Loading Success\n");
  getchar();

/* Step 3 : Lookup for the address of the required function
            This function has dependency so we load libdep.so */
  fnptr = dlsym(handle, "x");
  if(NULL == fnptr)
  {
    printf("Failed to Lookup Address of Shared Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Shared Object Address Lookup Success\n");
  getchar();

/* Step 4 : Invoke function through function pointer - Indirect Call */
  (fnptr)();
  getchar();
  
/* Step 5 : Request Link Loader to Unload Library */
  if(0 != dlclose(handle))
  {
    printf("Failed to Unload Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Unloading Success\n");
  getchar();

/* Step 6 : Request Link Loader to Reload Specified Library
            and attach it to our address space */
/* RTLD_NOLOAD - Don't load the shared object.  This can be used 
   to test if the object is already resident (dlopen() returns NULL
   if it is not, or  the object's handle if it is resident) */
  handle = dlopen("./libinit.so", RTLD_NOW | RTLD_NOLOAD);
  if(NULL == handle)
  {
    printf("Failed to Load Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Reloading Success\n");
  getchar();

/* Step 7 : Lookup for the address of the required function
            This function has dependency so we load libdep.so */
  fnptr = dlsym(handle, "x");
  if(NULL == fnptr)
  {
    printf("Failed to Lookup Address of Shared Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Shared Object Address Lookup Success\n");
  getchar();

/* Step 8 : Invoke function through function pointer - Indirect Call */
  (fnptr)();
  getchar();
  
/* Step 9 : Request Link Loader to Unload Library */
  if(0 != dlclose(handle))
  {
    printf("Failed to Unload Library\n");
    exit(EXIT_FAILURE);
  }
  printf("Unloading Success\n");
  getchar();

  return 0;
}
