//SimpleComputerPlayer.cpp
#include <iostream>
#include <string>
#include "Player.h"
#include "SimpleComputerPlayer.h"
#include "Board.h"

using namespace std;

	void SimpleComputerPlayer::setName(string s){
		 name = s;
	}

	void SimpleComputerPlayer::playingGame(){
		getName();
		cout << "'s turn, Please enter an integer between 1 and 7: ";

		// for(int i = 0; i < 7; i++){
		// 	for(int j = 0; j < 6; j++){
		// 		if(board[i][j] == "_"){
		// 			position = i;
		// 		}
		// 	}
		// }
	}
	