//SimpleComputerPlayer.h
#ifndef SIMPLECOMPUTERPLAYER_H
#define SIMPLECOMPUTERPLAYER_H
#include <string>
#include "Board.h"

using namespace std;

class SimpleComputerPlayer:public Player{

	public:
		void setName(string);
		void playingGame();
};

#endif