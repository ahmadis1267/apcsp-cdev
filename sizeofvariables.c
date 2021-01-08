#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 's';
  
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));

  float c = 6.121;
  
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  double d = 61.214;
  
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int e = 71;
  
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));

  short int f = 3;
  
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));

}

