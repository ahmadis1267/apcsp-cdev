#include <stdio.h>
#include <string.h>

// student structure
//struct Student...

struct Student {
  char firstName[50];
  char lastName[50];
  int age;
  int id;
};


void printStudent(struct Student* student) 
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %d\n", student->id);
}

void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++) {
    printf("\n------- student -------\n");
    printStudent(students + i);
  }
}

int main()
{

  // an array of students
  //xxx students;
  struct Student students[100];

  char input[256];

  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit: ");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
    struct Student newStudent;
    
    printf("\n First name: ");
    fgets(input, 256, stdin); 
    sscanf(input, "%s", &(newStudent.firstName));

    printf("\n Last name: ");
    fgets(input, 256, stdin); 
    sscanf(input, "%s", &(newStudent.lastName));
    
    printf("\n Enter age: ");
    while (1) 
    { 
	fgets(input, 256, stdin); 
	if (sscanf(input, "%d", &(newStudent.age)) == 1) break; 
	printf("Not a valid age - try again!\n");
    }
    
    printf("\n Enter id: ");
    while (1) 
    { 
        fgets(input, 256, stdin); 
        if (sscanf(input, "%d", &(newStudent.id)) == 1) break;
        printf("Not a valid student ID - try again!\n"); 
    }

      students[numStudents] = newStudent;
      numStudents++;
    }
  }
   
  printf("\nGoodbye!\n");
}
