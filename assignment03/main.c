#define RCC_BASE 0x40023800
#define RCC_AHB1ENR (*((unsigned int*)(RCC_BASE + 0x30)))

#define GPIOA_BASE 0x40020000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define GPIOA (1<<5)


#define DOT 1
#define DASH 2
#define END 0


int A[] = {DOT, DASH, END};
int B[] = {DASH, DOT, DOT, DOT, END};
int C[] = {DASH, DOT, DASH, DOT, END};
int L[] = {DOT, DASH, DOT, DOT, END};
int Y[] = {DASH, DOT, DASH, DASH, END};

int DisplayDOT()
{
  volatile int counter=0;
  
  GPIOA_ODR |= GPIOA;
  while (counter < 500000)
  {
    counter++;
  }
  counter = 0;
  GPIOA_ODR &= ~GPIOA;
  while (counter < 500000)
  {
    counter++;
  }
  return 0;
}

//DisplayDASH for 3 times longer than DOT
int DisplayDASH()
{
  volatile int counter=0;
  GPIOA_ODR |= GPIOA;

  while (counter < 1500000)
  {
    counter++;
  }
  counter = 0;
  GPIOA_ODR &= ~GPIOA;
    while (counter < 500000)
  {
    counter++;
  }
  return 0;
}

int main()
{
    
   RCC_AHB1ENR |= 0x1;
   GPIOA_MODER |= 0x400;

  int i = 0;
  while(L[i])
  {
    if(L[i++] == 2)
      DisplayDASH();      
    else 
      DisplayDOT();
   }
  i=0;
  while(A[i])
  {
    if(A[i++] == 2)
      DisplayDASH();      
    else 
      DisplayDOT();
   }
  i=0;
  while(C[i])
  {
    if(C[i++] == 2)
      DisplayDASH();      
    else 
      DisplayDOT();
  }
  i=0;
  while(Y[i])
  {
    if(Y[i++] == 2)
      DisplayDASH();      
    else 
      DisplayDOT();
  }
  
  return 0;
}
