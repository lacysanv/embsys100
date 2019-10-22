##Homework Assignment 2
1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
a) What is the value of the “counter” from the “Locals” window?
-2147483648
b) What is the value of the “counter” in the “Register” window?
0x80000000
c) Please note if the N and/or V flags are set in the APSR register? Explain why?
N = 1 (the value is negative)
V = 1 (the value is overflow)

2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”
a) What happens to the value of “counter” in the “Locals” window?
0
b) Please note if the N and/or V flags are set in the APSR register? Explain why?
N = 0 (the value is not negative)
V = 0 (the value is not overflow)

3. Change the “counter” variable type in your code to “unsigned”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?
2147483648
b) Please note if the N and/or V flags are set in the APSR register? Explain why?
N = 1 (the value is negative)
V = 1 (the value is overflow)

4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once:
a) What is the value of “counter” in the “Locals” window after incrementing for each value?
0
b) Please note if the N and/or V flags are set in the APSR register? Explain why?
N = 0
V = 0

5. Move the “counter’ variable outside of main (at the top of the file):
a) What is the scope of the variable “counter”?
Global
b) Is it still visible in the “Locals” view?
No
c) In which window view can we track “counter” now?
Auto
d) What is the address of the “counter” variable in memory? 
0x20000000

6. Change the source code to the following, then run the program still in the simulator:
a) What is the value of “counter” at the end of the program (halting at the return 0 statement)
4
b) Explain why the counter value has changed?
Because we were incrementing the value of the address register and not the address.

7. Change the setting of IAR to run the same program on the evaluation board:
a) What is the address where “counter” is stored? 
0x20000000
b) Is the “counter” variable stored in RAM or ROM?
RAM
c) What is the value of “counter” at the end of the program (halting at the return 0
statement).
4