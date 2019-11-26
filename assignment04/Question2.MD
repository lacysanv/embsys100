##2. Create a function with multiple arguments (5 arguments for example) and call that function from within another function. Trace thru the assembler and note:
a. How does the calling function pass the values to the called function?
	Args 1 - 4 are stored in R0 - R3. Arg 5 is stored on the stack
	arg1 - R4
	arg2 - R1
	arg3 - R2
	arg4 - R3
	arg5 - call stack
b. What extra code did the compiler generate before calling the function with the multiple arguments?

	0x800'004a: 0xb5e0         PUSH      {R5-R7, LR}	
	int result = foo(1, 2, 3, 4, 5);
	
c. What extra code did the compiler generate inside the called function with the multiple list of arguments?

	int foo(int a, int b, int c, int d, int e)	
	{	
	foo:	
	   0x800'0040: 0xb410         PUSH      {R4}	
	   0x800'0042: 0x0004         MOVS      R4, R0
	   
d. Any other observations?

	The return value is stored in R0