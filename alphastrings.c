#include <stdio.h>
#include <string.h>


int main()
{
 
 char stringOne[27] = "";

 for (int i = 0; i < 26; i++){
 stringOne[i] = 'a' + i;
 }

 char stringTwo[] = "abcdefghijklmnopqrstuvwxyz";

 if (strcmp(stringOne, stringTwo) == 0)
 {
  printf("String 1 and 2 are identical\n");
 }
 else
 {
  printf("String 1 and 2 are different\n");
 }

 for (int i = 0; i < 26; i++){
 stringOne[i] = 'A' + i;
 }

 if (strcmp(stringOne, stringTwo) == 0){
  printf("String 1 and 2 are identical\n");
 }
 else
 {
  printf("String 1 and 2 are different\n");
 }

 char stringThree[54];

 strcpy(stringThree, stringOne);
 strcat(stringThree, stringTwo);

 printf("String 1 looks like: %s\n", stringOne);
 printf("String 2 looks like: %s\n", stringTwo);
 printf("String 3 looks like: %s\n", stringThree);

}
