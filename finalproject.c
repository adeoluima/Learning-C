#include <stdio.h>
#include <stdlib.h>

#define for_rows for(int x = 0; x < rows; x++)
#define for_columns for(int y = 0; y < columns; y++)
#define NMAX 100

/* main program */

void readBoard(int board[][NMAX], char *filename, int rows, int columns);
int neighbourCount(int rows, int columns, int board[][NMAX], int x, int y);
void Conways(int board[][NMAX], int rows, int columns);
void printBoard(int board[NMAX][NMAX], int rows, int columns);
int column_wrap (int i, int a, int columns);
int row_wrap (int i, int a, int rows);
void randomBoard(int rows, int columns);
int boarderFunc(int board[][NMAX], int rows, int columns, int x, int y);
void initialiseBoard (int board[][NMAX]);

int main(){
    printf("Welcome to the Game Of Life.\n");
    //int cboard[][NMAX] = {0};

    int choice;
    printf("MENU \n Please choose one of the following options for the board:\n (1) Board 1\n (2) Board 2\n (3) Board 3\n (4) Randomly generated for given size\n (5) Custom\n");
    scanf("%i", &choice);
    switch(choice){
        case 1:
            printf("You have chosen the pre-defined Board 1. The size of the board is therefore 10x10.\n");
            static const int rows = 10;
            static const int columns = 10;
               int board1[][NMAX] = {
                   
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,1,1,1,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,1,1,1,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0}
                   
                };
            
            for(int i = 0; i < 20; i++){
                for_rows{
                    for_columns{
                        if (board1[x][y] == 1){
                            printf("#");
                        }
                        else{
                            printf(".");
                        }
                    }
                    printf("\n");
                }
                Conways(board1, rows, columns);
            }
            break;
            
        case 2:
            printf("You have chosen the pre-defined Board 2. The size of the board is therefore 10x10.\n");
            int board2[][NMAX] = {
                
                {0,0,0,0,1,1,1,0,0,0},
                {1,0,0,1,1,0,0,1,1,1},
                {0,0,1,1,1,0,1,0,0,0},
                {0,0,0,0,0,0,0,1,1,0},
                {0,0,1,1,1,0,0,0,0,0},
                {0,0,0,1,0,0,1,0,0,1},
                {1,1,0,0,0,1,0,0,1,0},
                {0,0,1,1,1,1,0,0,1,0},
                {1,0,1,1,0,1,0,0,0,1}
                
            };
            for(int i = 0; i < 20; i++){
                for_rows{
                    for_columns{
                        if (board2[x][y] == 1){
                            printf("#");
                        }
                        else{
                            printf(".");
                        }
                    }
                    printf("\n");
                }
                Conways(board2, rows, columns);
                printf("\e");
            }
            break;
            
        case 3:
            printf("You have chosen the pre-defined Board 3. The size of the board is therefore 10x10.\n");
            int board3[][NMAX] = {
                
                {0,0,1,1,0,1,0,0,0,0},
                {0,0,1,1,0,1,0,1,0,1},
                {0,0,0,0,1,0,1,0,1,1},
                {1,1,0,1,0,0,0,0,0,0},
                {0,0,0,1,0,0,0,1,1,0},
                {0,1,0,1,0,1,1,0,1,0},
                {0,0,0,0,0,0,1,0,0,1},
                {1,1,0,0,0,0,1,0,0,1},
                {0,0,0,0,0,0,1,0,0,0},
                {0,0,0,1,1,0,0,1,0,0}
                
            };
            for(int i = 0; i < 20; i++){
                for_rows{
                    for_columns{
                        if (board3[x][y] == 1){
                            printf("#");
                        }
                        else{
                            printf(".");
                        }
                    }
                    printf("\n");
                }
                Conways(board3, rows, columns);
            }
            break;

        case 4:
            randomBoard(rows, columns);
            break;
            
       /* case 5:
             printf("You have chosen to play with a custom board. Please give the name of the file. In the file, represent 'live' cells by '1' and 'dead' cells by '0'.\n");
            char custom;
            scanf("%s", &custom);
            readBoard(cboard, &custom, rows, columns);
            printf("%i", **cboard);
            for(int i = 0; i < 100; i++){
                printBoard(cboard, rows,columns);
                Conways(cboard, rows, columns);
            }
            
            for(int i = 0; i < 100; i++){
                for_rows{
                    for_columns{
                        if (cboard[x][y] == 1){
                            printf("#");
                        }
                        else{
                            printf(".");
                        }
                    }
                    printf("\n");
                }
                Conways(cboard, rows, columns);
            } */
            
    }
}

/*void readBoard(int board[][NMAX], char *filename, int rows, int columns){
    FILE    *f;
    char    s[NMAX];
    
    f = fopen (filename, "r");
    while(f == NULL){
        printf("File could not be found.\n");
        return;
    }
    
    for_rows{
        fgets(s, NMAX, f);
        for_columns{
            board[x][y] = s[y] == 1;
        }
    }
    fclose(f);
}*/

void randomBoard(int rows, int columns){
   // int row, column;
    
    printf("What is the width of the board?\n");
    scanf("%i", &columns);
    while(columns <=0){
        printf("Number of columns must be greater than zero. What is the board width?\n");
        scanf("%i", &columns);
    }
    printf("What is the height of the board?\n");
    scanf("%i", &rows);
    while(rows <=0){
        printf("Number of rows must be greater than zero. What is the board height?\n");
        scanf("%i", &rows);
    }
    rows += 2;
    columns += 2; // accounts for a border around the cells
    
    // create and initialise the board
    int board[rows][columns], random[rows][columns];
    for_rows for_columns{{
        board[x][y] = 0;
    }}
    printf("What is the probability of a cell being live?\n");
    float per=0.0f;
    scanf("%f", &per);
    //printf("%f", per);
    // generate a random number between 0 and 100
    for_rows{
        for_columns{
            random[x][y] = rand() % 100 + 1;

            if (random[x][y] <= per){
                board[x][y] = 1;
            }
            else{
                board[x][y] = 0;
            } // form a border of 0's around the board
            
            board[0][y] =0;
            board[x][0] =0;
            board[rows-1][y] = 0;
            board[x][columns-1] = 0;
        }
    }

    
            for_rows{
                for_columns{
                    if (board[x][y] == 1){
                        printf("#");
                    }
                    else{
                        printf(".");
                    }
                }
                printf("\n");
            }
     for(int i = 0; i < 20; i++){
     //printBoard(board, rows,columns);
     Conways(board, rows, columns);
}
}

int neighbourCount(int rows, int columns, int board[][NMAX], int x, int y){
    int nCount = 0;
     //for_rows for_columns{{

        // iterate around neighbourhood for each cell
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                // if neighbouring cell is live, add one to the count
                /*char element = board[i+x][j+y];
                if (element == 1){
                    nCount ++;
                }*/
                nCount += board[x+i][y+j] ;
               /* if (i || j){
                    if (board[row_wrap(x,i,rows)][column_wrap(y,j,columns)] == 1){
                    nCount++;
                    }
                }*/
                
            }
        }
    
       // if current cell is live, subtract one from the count as it shouldn't add to the count
       nCount -= board[x][y];
     // }}
    
    return nCount;
}

void Conways(int board[][NMAX], int rows, int columns){
    int nextBoard[rows][columns];
    for_rows for_columns{{
        int count = neighbourCount(rows, columns, board, x, y);
        
        // stasis - if live neighbours is 2, element remains the same
        if(count == 2){
            nextBoard[x][y] = board[x][y];
        }
        
        // birth - if there are 3 live neighbours, cell comes to life
        if(count == 3){
            nextBoard[x][y] = 1;
        }
        
        // death - cell dies from overpopulation (more than 4 live neighbours) or lonliness (1 or fewer live neighbours)
        if(count < 2 || count >= 4){
            nextBoard[x][y] = 0;
        }
        
        // maintain border
        nextBoard[0][y] =0;
        nextBoard[x][0] =0;
        nextBoard[rows-1][y] = 0;
        nextBoard[x][columns-1] = 0;
    }}
    for_rows for_columns{{
        // for each cell, let the old = the new
        board[x][y] = nextBoard[x][y];
    }}

    printf("\n");
    for_rows{
        for_columns{
            if (board[x][y] == 1){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}

// NOTES
/*
 * File input was attempted
 * The printing of the board[x][y] array could not be done in a function (would not compile for an unknow reason, hence why it has been repeated in main)
 *
 */
 
