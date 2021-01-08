#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);

  int change = a;
  a = c;
  c = change;
  printf("a is equal to %d and c is equal to %d\n", a, c);
}
