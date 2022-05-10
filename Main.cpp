#include <iostream>
using namespace std;

void placePiece(char board[][3], int location, char playerChar){
  while(location > 9 || location < 1){
    cout << "Please select a number that is present on the board between 1 and 9" << endl;
    cin >> location;
  }
  if(location < 4){
    board[0][location-1] = playerChar; // If location is less than 4 -1 to set in array
  }
  else if(location < 7){
    board[1][location-4] = playerChar; // If
  }
  else{
    board[2][location-7] = playerChar;
  }

}
bool checkDiagonalRight(char board[][3]){
    if(board[0][2] == '\0' || board[2][0] == '\0'){
      return 0;
}
  	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    	cout << endl << board[0][2] << " is the winner right corner diagonal"; 
        return 1;
    }	    
    
    cout << "Nothing happened";
    
    return 0;

}
bool checkDiagonalLeft(char board[][3]){
    if(board[0][0] == '\0' || board[2][2] == '\0'){
      return 0;
}
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    	cout << endl << board[2][2] << " is the winner left corner diagonal"; 
		
		return 1; 	
    }
    cout << "Nothing happened";
    
    return 0;
}
bool checkVertical(char board[][3]){
	for (int i = 0; i < 3; i++){
    if(board[0][i] == '\0'){
      continue;
    }
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
        	cout << endl << board[2][i] << " is the winner, Veritcal win " << 1+i << "column";
            return 1;
        }
    }
}
bool checkHorizontal(char board[][3]){
	for (int i = 0; i < 3; i++){
	  if(board[i][0] == '\0') {
	    continue;
	  }
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
        	cout << endl << board[i][3] << " is the winner Horizontal win row " << 1 + i << endl;
            return 1;
        }
    }
}
void checkBoard(char board[][3]){
  checkHorizontal(board);
  checkVertical(board);
  checkDiagonalLeft(board);
  checkDiagonalRight(board);
}

void printBoard(char board[][3]){
  int counter = 1; // counter for numbering the play table
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
char board[3][3] = {{'\0','\0','\0'},
				          	{'\0','\0','\0'},
                    {'\0','\0','\0'}};
printBoard(board);
// placePiece(board, selection ,playerChar)
checkBoard(board);
          
}
