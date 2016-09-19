//proj2.cpp
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "SimpleComputerPlayer.h"
#include "HumanPlayer.h"

using namespace std;

int main(int argc, char *argv[])
{
	string flag1 (argv[1]);
	string flag2 (argv[2]);
	
	cout << "Let's Start a Game of Connect 4" << endl;

	Board* board = new Board(flag1,flag2);
	board->print_Board();
	int temp = 0;
	//start the game loop, untill call wins or has 42 steps that fulfill the board
	for(int i = 0; i < 42; i++){
		if( ((i%2) == 0) ){
			board->p1Update();
			temp++;
			if(board->p1WinningGame()){
				cout << board->returnp1Name() << " Connected Four and Wins!" << endl;
				break;
			}
		}else{
			board->p2Update();
			temp++;
			if(board->p2WinningGame()){
				cout << board->returnp2Name() << " Connected Four and Wins!" << endl;
				break;
			}
		}
	}
	//situatiion that has board max.
	if(temp == 42){
		cout << "The board is full, it is a draw!" << endl;
	}

	return 0;
}