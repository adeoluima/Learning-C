//
//  main.c
//  assess_3
//
//  Created by Ima Coker on 19/11/2018.
//  Copyright © 2018 Ima Coker. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 60
#define number 15 ///use capitals here

// define the variables in the structure - dates included so code could be adapted to print dates of assignments also.
typedef struct student{
    char name[NMAX];
    int age;
    int mark1;
    int mark2;
    int mark3;
    int mark4;
    int mark5;///use an array here
    int markTotal;
    char date1;
    char date2;
    char date3;
    char date4;
    char date5;///use an array here
    char grade;
} Student;

void indata(Student *student);
void final_mark(Student *student, char *ggrade);
float retrieve(Student *student, char ggrade);
///need function comment here
int main(){
    char ggrade;
    int count;
    printf("How many grades do you wish to view?");
    scanf("%i", &count);
    // retrieve function will run count times

    // allocate space for structure
    Student *student = NULL;
    student = (Student *)malloc(number * sizeof(Student));//need to check if malloc has allocated memory correctly by testing if the pointer is still NULL

    indata(student);
    // pass the address of ggrade to final_mark
    final_mark(student, &ggrade);
    for(int i = 0; i < count; i++){
        // pass the value of ggrade to retrieve
        retrieve(student, ggrade); ///this function returns the grade but you dont use it. make the function a void if you dont need a return
    }
    return 0;
}

///need function comment here
void indata(Student *student){
    FILE *infile;
    infile = fopen("/Users/imacoker/Documents/THE CLOUD/UNIVERSITY WORK/YEAR TWO/SCIENTIFIC PROGRAMMING/assessments/assess_3/assess_3/assessment3.txt", "r");
    if(infile == NULL){
        printf("The file could not be read");///terminate program if you fail to open the file as the program cannot work if it does not open.
    }

    // convert student[0].age to sting as the value is 'Age'
    // Same treatment would be applied to dates if required.
    char* Age;
    asprintf (&Age, "%i", student[0].age);
    free(Age); ///what is the purpose of lines 69-71

    for(int i = 0; i < number; i++){
        fscanf(infile, "%s %d %d %d %d %d %d", student[i].name, &student[i].age, &student[i].mark1, &student[i].mark2, &student[i].mark3, &student[i].mark4, &student[i].mark5);
    }
    fclose(infile);
}
///need function comment here
void final_mark(Student *student, char *ggrade){
    // options for grade

    // from 7 as 0-6 was taken by dates (could not find a way to change this)
    for(int i = 7; i < number; i++){
        student[i].markTotal = student[i].mark1 + student[i].mark2 + student[i].mark3 + student[i].mark4 + student[i].mark5;
 ///need the average grade here
        // this does not work because for loop replaces ggrade value everytime. I ran out of time but would put ggrade in the structure and save for each value
        // tried, however error 'Incompatible pointer to integer conversion assigning to 'char' from 'char [4]'' could not be debugged.

        int  a = student[i].markTotal;
        if (a >= 350 ){
            ggrade = "1st";
        }
        if (a >= 300){
            ggrade = "2:1";
        }
        if (a >= 250){
            ggrade = "2:2";
        }
        if (a >= 40){
            ggrade = "3rd";
        }
        else {
            ggrade = "Fail";
        }
    }
}
///need function comment here
float retrieve(Student *student, char ggrade){
    char name[NMAX];
    printf("Who's grades do you wish to view? (First name only)? \n");///question asks that you pass the required name to the function as an arguement from main.
    scanf("%s", name);

    for(int i = 0; i < number; i++){
        if(strcmp(name, student[i].name)==0){
            final_mark(student, &ggrade); ///rather that calcuate the final mark you should merely look it up here
            //student[i].markTotal = student[i].mark1 + student[i].mark2 + student[i].mark3 + student[i].mark4 + student[i].mark5;
            printf("%s's total mark is %d. The grade awarded is a %c.\n", student[i].name, student[i].markTotal, ggrade);

        } /* This else part would always run if executed for some reason...
           else {
            printf("Name not found.\n");
            return -1;
        } */

        /* idea for sanity check - did not work
         should be in a while loop
         else {
            printf("The name could not be found. Please enter another name.\n");
            printf("Who's grades do you wish to view? (First name only)? \n");
            scanf("%s", name);
        } */
    }

    return ggrade;

}

// output of code//
/*
 How many grades do you wish to view?2
 Who's grades do you wish to view? (First name only)?
 lili
 Who's grades do you wish to view? (First name only)?
 John
 221

 John's total mark is 221. The grade awarded is a .
 Program ended with exit code: 0
 */
