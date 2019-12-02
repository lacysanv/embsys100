#ifndef __INCL_STACK__
#define __INCL_STACK__
#define STACKSIZE 10
void stackinitialize(int *);
int stackpush(int *, int);
int stackpop(int * );
int stackempty(int * );
int stackfull();

#endif