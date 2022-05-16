#include <iostream>
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


bool placePiece(char board[][3], int location, char playerChar, bool robot){
  
  while(location > 9 || location < 1){
    cout << "Please select a number that is present on the board between 1 and 9" << endl;
    cin >> location;
  }                                     // NOTE: NEED TO IMPLIMENT LOOP FOR PLACING A PIECE THAT ALREADY HAS SOMETHING IN IT ...done...
  if(location < 4){
    if(board[0][location-1] != '\0' ){
        if(!robot){
            cout << "Please enter new number. Location occupied.";
        }
        return 0;
    }
   board[0][location-1] = playerChar;
   return 1;
  }
  else if(location < 7){
    if(board[1][location-4] != '\0'){
        if(!robot){
            cout << "Please enter new number. Location occupied.";
        }
        return 0;
    }
    board[1][location-4] =playerChar;
    return 1;
  }
  else{
    if(board[2][location-7] !='\0'){
        if(!robot){
            cout << "Please enter new number. Location occupied.";
        }
        return 0;        
    }
    board[2][location-7] = playerChar;
    return 1;
  }
}
char printPiece(char board[][3], int location){
      
  if(location < 4){
     return board[0][location-1];
  }
  else if(location < 7){
      return board[1][location-4];
    }
  else{
    return board[2][location-7];
    }
}
bool checkDiagonalRight(char board[][3]){
    if(board[0][2] == '\0' || board[2][0] == '\0'){
      return 0;
}
  	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return 1;
    }	    

    return 0;

}
bool checkDiagonalLeft(char board[][3]){              
    if(board[0][0] == '\0' || board[2][2] == '\0'){
      return 0;
}
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return 1; 	
    }
    
    return 0;
}
bool checkVertical(char board[][3]){
	for (int i = 0; i < 3; i++){
    if(board[0][i] == '\0'){
      continue;
    }
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return 1;
        }
    }
    return 0;
}
bool checkHorizontal(char board[][3]){
	for (int i = 0; i < 3; i++){
	  if(board[i][0] == '\0') {
	    continue;
	  }
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
        }
    }
    return 0;
}
bool checkBoard(char board[][3]){
  if(checkHorizontal(board)||checkVertical(board)||checkDiagonalLeft(board)
  ||checkDiagonalRight(board)){
    return 1;
  }
  else{
    return 0;
  }
}
void printBoard(char board[][3]){
  int counter = 1; // counter for numbering the play table
  cout << endl;
for(int i = 0; i < 3; i++){
	for(int j = 0; j < 3; j++){
    	if(board[i][j] != '\0'){ 
    	  cout << board[i][j];
	    }
	    else{
	      cout << counter;  // outputs number if the board has something other than \0
	    }
        if (j < 2){
        	cout << " | ";
        }
      counter++;
    }
 if(i < 2)
 	cout << endl << "--+---+---"  << endl;
}
}

int main() {
  int playerSelection = 0;
  char board[3][3] = {{'\0','\0','\0'},
	  			      {'\0','\0','\0'},
                      {'\0','\0','\0'}};

  int numOfPlayers = 0;
  int turn = 0;
  cout <<"Welcome to the game of tic-tac-toe place 3 pieces in a row in order to win."<< endl;
  while(numOfPlayers > 2 || numOfPlayers < 1){
    cout << "Are there 1 or 2 players?" << endl;
    cin >> numOfPlayers;
    printBoard(board);
  }
  switch (numOfPlayers) {
  case 1:               // NEED TO IMPLIMENT SOME TIME OF CPU OPPONENT ...Very simple but done...
    cout << endl << "Single player" << endl;
    while(!checkBoard(board)){
      cout<<"Where would you like to place a piece?"<<endl;
      cin >> playerSelection;
      while(!placePiece(board, playerSelection, 'X',0)){ //
          cin >> playerSelection;
      }
      cout << endl;
      turn++;
      if(turn >= 8){         
        cout << "It's a tie";
        return 0;
      }
      if(!checkBoard(board)){
         srand (time(NULL));
         playerSelection = rand() % 8 + 1;
         while(!placePiece(board, playerSelection, 'O',1)){
            playerSelection = rand() % 8 + 1;
         }
      }
      printBoard(board);
      cout << endl;
      turn++;
      
      } 
    cout << printPiece(board, playerSelection) <<" is the winner!";
    break;
  case 2:
    cout << endl << "Two players" << endl;
    char player1 = 'X'; // player1 assigned x
    char player2 = 'O'; // player2 assigned o 
    while(!checkBoard(board)){
      cout<<"Player 1: Where would you like to place a piece?"<<endl;
      cin >> playerSelection;
      while(!placePiece(board, playerSelection, player1, 0)){ 
          cin >> playerSelection;
      }
      printBoard(board);
      cout << endl;
      if(turn >= 8){                // Added Tie  
        cout << "It's a tie";
        return 0;
        }
      turn++; // counts for check after 9 turns
      if(!checkBoard(board)){
        cout<<"Player 2: Where would you like to place a piece?"<<endl;
        cin >> playerSelection;
        while(!placePiece(board, playerSelection, player2, 0)){
          cin >> playerSelection;
      }
        printBoard(board);
        cout << endl;
        turn++;
        }
    }
    cout << printPiece(board, playerSelection) <<" is the winner!";
    break; 
    }
    
  }
