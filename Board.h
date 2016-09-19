//Board.h
#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Player.h"

using namespace std;

class Board{

	private:
		string flag1, flag2;
		Player* player1;
		Player* player2;
		string boardArray[6][7];
		int changeRow, changeCol, position;
		int countH = 0, countV = 0, countDiP = 0, countDiN = 0;
	
	public:
		
		Board(string, string);
		~Board();
		void print_Board();
		void p1Update();
		void p2Update();
		bool p1WinningGame();
		bool p2WinningGame();
		string returnp1Name();
		string returnp2Name();
		// string getArray(int, int);
		// string getBoard();
		
};

#endif