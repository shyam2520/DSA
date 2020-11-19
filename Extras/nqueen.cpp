
#include <iostream>
#include <cstring>
using namespace std;

 

char mat[8][8];

 

// Function to check if two queens threaten each other or not
bool isSafe( int r, int c, int N)
{
    // return false if two queens share the same column
    for (int i = 0; i < r; i++)
        if (mat[i][c] == 'Q')
            return false;

 

    // return false if two queens share the same \ diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j] == 'Q')
            return false;

 

    // return false if two queens share the same / diagonal
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
        if (mat[i][j] == 'Q')
            return false;

 

    return true;
}

 

void nQueen(int r, int N)
{
    // if N queens are placed successfully, print the solution
    if (r == N)
    {
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        
        return;
    }

 

    // place Queen at every square in current row r
    // and recur for each valid movement    
    for (int i = 0; i < N; i++) 
    {
        // if no two queens threaten each other
        if (isSafe(r, i, N)) 
        {
            // place queen on current square
            mat[r][i] = 'Q';

 

            // recur for next row
            nQueen(r + 1, N);

 

            // backtrack and remove queen from current square
            mat[r][i] = '-';
        }
    }
}

 

int main()
{
    // mat[][] keeps track of position of Queens in current configuration

 


    // initalize mat[][] by '-'
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            mat[i][j]='-';
        }
    }

 

    nQueen(0, N);

 

    return 0;
}