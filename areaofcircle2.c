#include <stdio.h>
#include <math.h>

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
return (M_PI * radius * radius);
}

int main(int argc, char* argv[], float lower, float higher) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  char input[256];
  if(argc == 3) {
     if (sscanf(argv[1], "%f", &lower) != 1) {
      printf("First argument must be a float number!\n");
     }
     if (sscanf(argv[2], "%d", &higher) != 1) {
      printf("Second argument must be an float number!\n");
     }
 }
 else {
  printf("\nInput lower: ");
  while (1)
  {     
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &lower) == 1) break;
    printf("Not a valid radius, must be float!\n");
   } 

  printf("\nInput higher: ");
    while (1)
    {
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &higher) == 1) break;
    printf("Not a valid radius, must be float!\n");
    }
 }

 if ((lower < 0 || higher < 0) && (lower < higher)) {
  printf("\nInput lower: ");
  while (1)
  {     
    fgets(input, 256, stdin);
    if (sscanf(input, "%f", &lower) == 1) break;
    printf("Not a valid radius, must be float!\n");
   } 

  printf("\nInput higher: ");
  while (1)
  {
  fgets(input, 256, stdin);
  if (sscanf(input, "%f", &higher) == 1) break;
  printf("Not a valid radius, must be float!\n");
  }
 }

  printf("calculating area of circle starting at %f, and ending at %f\n", lower, higher);

  // add your code below to call areaOfCircle function with values between
  // start and end
  float reps;
  reps = higher - lower;
  
  for (int i = 0; i < reps; i++)
  {   
   double areaFunction = areaOfCircle(lower + i);
   printf("Area of circle for radius of %f is %f\n", lower + i, areaFunction);
  }

}

