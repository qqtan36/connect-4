//Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player{

	protected:
		string name;
		int position;
		string sign;

	public:
		string getName();
		void setName(string);
		int getPosition();
		void playingGame();
		//void playingGame(Board);
		void setSign(string);
		string getSign();
};

#endif