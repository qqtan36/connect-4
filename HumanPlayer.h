//HumanPlayer.h
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

using namespace std;

class HumanPlayer:public Player{
	
	public:
		void setName(string);
		void playingGame();
};

#endif