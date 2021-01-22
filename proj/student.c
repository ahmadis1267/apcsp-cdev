//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
 Student* addStudent =  (Student*)malloc(sizeof(Student));
 addStudent->firstName = (char*) malloc((strlen(fname)+1)*sizeof(char));
 addStudent->lastName = (char*) malloc((strlen(lname)+1)*sizeof(char));
 strcpy(addStudent->firstName, fname);
 strcpy(addStudent->lastName, lname);
 addStudent->age = age;
 addStudent->id = id; 

 students[numStudents] = addStudent;
 numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
 free(student->firstName);
 free(student->lastName);
 free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
 for (int i = 0; i < numStudents; i++){
	deleteStudent(students[i]);
 	students[i] = 0;
 }
 numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
 FILE* fp; 
 
 fp = fopen(STUFILE,"w");

 char buff[256];

 if (fp){
	for (int i = 0; i < numStudents; i++){

		Student* st = students[i];

		sprintf(buff, "%s %s %d %ld", st->firstName, st->lastName, st->age, st->id);

		if (key != 0) {
			caesarEncrypt(buff, key);
		}

		fprintf(fp, "%s\n", buff);
		printf("saving: %s\n", buff);
	}
	printf("saved %d students\n", numStudents);
	fclose(fp);
 }
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory

 if (numStudents > 0) {
        deleteStudents();
 }

 FILE* fp;

 fp = fopen(STUFILE,"r");

 char fnameBuff[256];
 char lnameBuff[256];
 char ageBuff[256];
 char idBuff[256];

 int age;
 long int id;

 if (fp) { 
	while (1) {

		if(fscanf(fp, "%s %s %s %s", fnameBuff, lnameBuff, ageBuff, idBuff) == 4) {
			if (key != 0) {
				caesarDecrypt(fnameBuff, key);
				caesarDecrypt(lnameBuff, key);
				caesarDecrypt(ageBuff, key);
				caesarDecrypt(idBuff, key);
			}

                        sscanf(ageBuff, "%d", &age);
                        sscanf(idBuff, "%ld", &id);

			createStudent(fnameBuff, lnameBuff, age, id);
		}
		else {
			break;
		}
	}

        printf("loaded %d students\n", numStudents);
        fclose(fp);
 }



}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




