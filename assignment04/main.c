#include "stack.h"
#include <stdio.h>

int numstack[STACKSIZE];

int main()
{
  stackinitialize(numstack);

  printf("Adding values\n");  
  for(int i = 0; i < STACKSIZE; i++)
  {
    stackpush(numstack, i);
  }
  if(stackfull(numstack))
    printf("Stack is full\n");
  else
    printf("Stack is not full\n");
  
  if(stackempty( numstack))
    printf("Stack is empty\n");
  else
    printf("Stack is not empty\n");

  printf("Removing values\n");  
  for(int i = STACKSIZE - 1; i >= 0; i--)
  {
    stackpop(numstack);
  }
  
  if(stackfull(numstack))
    printf("Stack is full\n");
  else
    printf("Stack is not full\n");
  
  if(stackempty( numstack))
    printf("Stack is empty\n");
  else
    printf("Stack is not empty\n");
  
  return 0;
}
