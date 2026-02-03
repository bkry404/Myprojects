
#include <iostream>
#include <utility>
using namespace std;
struct dirc {
    const int index;
    char move = ' '; // Initialize move to a space character
};


void updateMove(int playerMove, dirc board[], int prev) {
    if (board[playerMove - 1].index != prev) {
        if (board[playerMove - 1].move == ' ') {
            board[playerMove - 1].move = 'X';
        }
        else {
            cout << "Taken\n";
        }
    }else {
          cout << "You already played here\n";
    }
}
void printBoard(const dirc board[]) {
    for (int i = 0; i < 9; ++i) {
        cout << " " << board[i].move << " |";
        if ((i + 1) % 3 == 0) cout << "\n";
    }
}
void print() {
    cout << " 1 " << "|" << " 2 " << "|" << " 3 " << '\n';
    cout << " 4 " << "|" << " 5 " << "|" << " 6 " << '\n';
    cout << " 7 " << "|" << " 8 " << "|" << " 9 " << '\n';
}
void compMove(dirc arr[]) {
    srand(time(0));
    int compMoveI = rand() % 9;
    // Fix: Use a constant for array size since sizeof(arr) gives pointer size here
    const int arrSize = 9;
    for (int i = 0; i < arrSize; i++) {
        if (arr[compMoveI].move != 'X' && arr[compMoveI].move != 'O') {
            arr[compMoveI].move = 'O';
            return;
        }
        // Try next cell if randomly chosen one is occupied
        compMoveI = (compMoveI + 1) % arrSize;
    }
}
bool compare(dirc arr[]) {
   static int Tiecount = 0;
    if (arr[0].move == 'X' && arr[3].move == 'X' && arr[6].move == 'X' ||
        arr[1].move == 'X' && arr[4].move == 'X' && arr[7].move == 'X' ||
        arr[2].move == 'X' && arr[5].move == 'X' && arr[8].move == 'X') {
        cout << "You Win" << '\n'; // rows
       return false;
    }
    else if (arr[0].move == 'X' && arr[1].move == 'X' && arr[2].move == 'X' ||
              arr[3].move == 'X' && arr[4].move == 'X' && arr[5].move == 'X' ||
              arr[6].move == 'X' && arr[7].move == 'X' && arr[8].move == 'X') {
        cout << "You Win" << '\n'; // Columns
        return false;
    }
     else if (arr[0].move == 'X' && arr[4].move == 'X' && arr[8].move == 'X' ||
         arr[2].move == 'X' && arr[4].move == 'X' && arr[6].move == 'X'
         ) {
        cout << "You Win" << '\n';
        return false;
        
    }else if (arr[0].move == 'O' && arr[3].move == 'O' && arr[6].move == 'O' ||
        arr[1].move == 'O' && arr[4].move == 'O' && arr[7].move == 'O' ||
        arr[2].move == 'O' && arr[5].move == 'O' && arr[8].move == 'O') {
        cout << "You lost" << '\n'; // rows
        return false;
        
    }else if (arr[0].move == 'O' && arr[1].move == 'O' && arr[2].move == 'O' ||
        arr[3].move == 'O' && arr[4].move == 'O' && arr[5].move == 'O' ||
        arr[6].move == 'O' && arr[7].move == 'O' && arr[8].move == 'O') {
        cout << "You lost" << '\n'; // Columns
        return false;
        
    }else if (arr[0].move == 'O' && arr[4].move == 'O' && arr[8].move == 'O' ||
        arr[2].move == 'O' && arr[4].move == 'O' && arr[6].move == 'O'
        ) {
        cout << "You lost" << '\n';
        return false;
    }
    else {
       
        if (Tiecount == 5) {
            cout << "Tie" << '\n';
            return false;
        }
        Tiecount++;
        return true;
    }
}
   int main(){


    print();
    int playerMove;
    dirc arr[9] =  {
    {1, ' '}, {2, ' '}, {3, ' '},
    {4, ' '}, {5, ' '}, {6, ' '},
    {7, ' '}, {8, ' '}, {9, ' '}
    };
    bool running = true;
    int prevmove = 0;
    do {
        do {
            cout << "Enter number to display Move: ";
            cin >> playerMove;
            cout << "You played:" << endl;
            updateMove(playerMove, arr, prevmove); printBoard(arr);
        } while (arr[playerMove - 1].move != 'X' || arr[playerMove - 1].index == prevmove);
        prevmove = playerMove;
        cout << "Computer played: " << endl;
        compMove(arr); 
        printBoard(arr);
       running =  compare(arr);
    } while(running);
    return 0;
}