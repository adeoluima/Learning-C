//
//  assignment2.c
//  assignment2
//
//  Created by Ima Coker on 26/10/2018.
//  Copyright © 2018 Ima Coker. All rights reserved.
//

#include <stdio.h>
#define NMAX 100

void create_array(int inums[NMAX], int ans);
int add_function(int inums[NMAX], int nsum, int ans);

int main(){
    /*code for my assessment 2*/
    
    printf("MENU\n");
    int inums[NMAX] = {0}, ans, nsum;
    printf("Would you like to sum a series of odd or even integer numbers? Please input 1 for even numbers or 2 for odd numbers. \n");
    scanf("%i", &ans);
    
    /* input may only be 1 or 2*/
    while(1){
        if (ans == 1 ||ans == 2){
            break;
        }
        printf("Please choose either option 1 or option 2.\n");
        scanf("%i", &ans);
        break;
    }
    
    /*since NMAX is 100, the max value of nsum is 50*/
    printf("How many numbers will be added? \n");
    scanf("%i", &nsum);
    while(1){
    if (nsum > NMAX/2){
        printf("You may only calculate sums from 0 up to 100. How many numbers would you like to add?");
        scanf("%i", &nsum);
    }
        break;
    };
    
    
    create_array(inums, ans);
    add_function(inums, nsum, ans);
    return 0;

}


void create_array(int inums[NMAX], int ans){
    int esum = 0, osum = 0, i = 0;
    while(i < NMAX){
        switch(ans){
            case 1:
                for(int j = 0; j < NMAX ; j+=2){
                    esum += j;
                    inums[j] = esum;
                    i++;
                }
                break;
            case 2:
                for(int k = 0; k < NMAX; k+=2){
                    osum += k;
                    inums[k] = osum;
                    i++;
                }
                break;
        }
    }
}

int add_function(int inums[NMAX], int nsum, int ans){
    int i = 0, even_sum = 0, odd_sum = 0;
    for (i = 1; i <= 2*nsum; i++){
        if (i % 2 == 0)
            even_sum += i;
        else
            odd_sum += i;
    }
    
    if (ans == 1)
        printf("The sum of even numbers from 0 to %i is %i.\n",2*nsum, even_sum);
    else
        printf("The sum of odd numbers from 0 to %i is %i.\n",2*nsum, odd_sum);
    return 0;
}

// TEST FOR INCORRECT INPUTS //
/*
MENU
Would you like to sum a series of odd or even integer numbers? Please input 1 for even numbers or 2 for odd numbers.
5
Please choose either option 1 or option 2.
2
How many numbers will be added?
60
You may only calculate sums from 0 up to 100. How many numbers would you like to add?40
The sum of odd numbers from 0 to 80 is 1600.
Program ended with exit code: 0
 */


// TEST FOR FIRST 10 ODD INTEGER NUMBERS //
/*
 MENU
 Would you like to sum a series of odd or even integer numbers? Please input 1 for even numbers or 2 for odd numbers.
 2
 How many numbers will be added?
 10
 The sum of odd numbers from 0 to 20 is 100.
 Program ended with exit code: 0
*/
// TRUE AS 10*10 = 100 //

// TEST FOR FIRST 10 EVEN INTEGER NUMBERS //
/*
 MENU
 Would you like to sum a series of odd or even integer numbers? Please input 1 for even numbers or 2 for odd numbers.
 1
 How many numbers will be added?
 10
 The sum of even numbers from 0 to 20 is 110.
 Program ended with exit code: 0
 */
// TRUE AS 10*11 = 110 //

