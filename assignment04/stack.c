#include <stdio.h>
#include "stack.h"


int *stackwriteptr = NULL;
int *stackmaxptr = NULL;

void stackinitialize(int *stackptr)
{
  for(int i= 0; i< STACKSIZE; i++)
  {
    stackptr[i] = 0;   
  }
  stackwriteptr = stackptr;
  stackmaxptr = &stackptr[STACKSIZE -1];
}

int stackpush(int *stackptr, int val)
{
  if(stackfull())
    return 1;
  //write value into current memory address
  *stackwriteptr = val;
  
  //increment point to next location - ready to write the next value
  stackwriteptr++;
  return 0;
  
}
int stackpop(int *stackptr)
{
  if(stackempty(stackptr))
    return 1;
  
  stackwriteptr--;
  int tempval = *stackwriteptr;
  
  //zero out the write pointer - this is important for the stackfull() func
  *stackwriteptr = 0;
  
  return tempval;
  
}

int stackempty(int *stackptr)
{
  if(stackptr == stackwriteptr)
    return 1;
  else
    return 0;
  
  
}
int stackfull()
{
  //if there's a value in the Max spot, it's full
  if(*stackmaxptr)
    return 1;
  else
    return 0; 
}
