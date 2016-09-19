//Player.cpp
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;
	
	string Player::getName(){
		return name;
	}

	string Player::getSign(){
		return sign;
	}

	int Player::getPosition(){
		return position;
	}

	void Player::setName(string s){
		name = s;
	}

	void Player::playingGame(){
		//DO-NOTHING
	}

	// void Player::playingGame(Board){
	// 	//DO-NOTHING
	// }

	void Player::setSign(string s){
		sign = s;
	}
