//CPP program for Knight's Tour Problem
/*This solution below is the one solution, there can be many solutions also
In this question the Knight is at first block initially (0, 0)
We are using BackTracking to solve this problem
i/p will be the knight at particular position
o/p will be to find all the moves on chess board i.e.
 
0  59  38  33  30  17   8  63 
37  34  31  60   9  62  29  16 
58   1  36  39  32  27  18   7 
35  48  41  26  61  10  15  28 
42  57   2  49  40  23   6  19 
47  50  45  54  25  20  11  14 
56  43  52   3  22  13  24   5 
51  46  55  44  53   4  21  12 
*/

#include <iostream>
using namespace std;

#define N 8;

int solveKnightTourUtil(int x, int y, int moves, int sol[N][N], int xMove[], int yMove[]);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
bool isSafe(int x, int y, int sol[N][N]){
    
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1 )
}

/* A utility function to print
solution matrix sol[N][N] */
void displaySolution(int sol[N][N]){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<" "<<sol[i][j]<<endl;
        }
        cout<<endl;
    }
}

int solveKnightTour(){
    //initialize the solution matrix
    int sol[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sol[i][j] = -1;
        }
    }

    /*xMove[] and yMove[] define next move of Knight.
    xMove[] is for the next value of x coordinates
    yMove[] is for the next value of y coordinates
    i.e. to get these value, subtract or add to current 
    coordinates inorder to reach the required coordinates.
    order of these coordinates can be anything but the 
    index should be same of corresponding x and y*/

    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    //suppose the Knight is at first block
    sol[0][0] = 0;

    //Now start from the (0, 0) and explore all the blocks
    if(solveKnightTourUtil(0, 0, 1, sol, xMove, yMove) == 0){
        cout<<"Solution doesn not exist"<<endl;
        return(0);
    }
    else{
        displaySolution(sol);
    }
    return(1);
}

/* A utility function to solve the knight tour problem */
int solveKnightTourUtil(int x, int y, int moves, int sol[N][N], int xMove[N], int yMove[N]){
    
    int next_x, int next_y;
    
    /*if knight will make the all 64 moves then return*/
    if(moves == N*N)
        return (1);
    
    /*Try all the next moves from the current coordinates*/
    for(int k=0; k<8; k++){
        next_x = x + xMove[k];
        next_y = y + yMove[k];

        //checking the position is safe or not
        if(isSafe(next_x, next_y, sol)){
            sol[next_x][next_y] = moves;
            if(solveKnightTourUtil(next_x, next_y, moves + 1, sol, xMove, yMove) == 1){
                return 1;
            }
            else{
                //backtracking
                sol[next_x][next_y] = -1;
            }
        }
    }
    return(0);
}

int main(){

    solveKnightTour();
    return(0);
}
