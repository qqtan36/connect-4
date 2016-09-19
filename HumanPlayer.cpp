//HumanPlayer.cpp
#include <iostream>
#include <string>
#include "Player.h"
#include "HumanPlayer.h"

using namespace std;

	void HumanPlayer::setName(string s){
		name = s;
	}

	void HumanPlayer::playingGame(){
		
		getName();
		cout << "'s turn, Please enter an integer between 1 and 7: ";
		cin >> position;
	}