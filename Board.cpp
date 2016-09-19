//Board.cpp
#include <iostream>
#include <string>
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "SimpleComputerPlayer.h"

using namespace std;
	
	//set board consturctor, declare player1 and player2
	Board::Board(string f1, string f2){
		flag1 = f1;
		flag2 = f2;

		if(f1 == "-h"){
			string name1;
			player1 = new HumanPlayer();
			cout << "Player One, please enter your name: ";
			cin >> name1;
			cout << endl;
			(*player1).setName(name1);
		}
		else if(f1 == "-c"){
			string name1;
			player1 = new SimpleComputerPlayer();
			name1 = "Zoey";
			(*player1).setName(name1);
		}	

		if(f2 == "-h"){
			string name2;
			player2 = new HumanPlayer();
			cout << "Player One, please enter your name: ";
			cin >> name2;
			cout << endl;
			(*player2).setName(name2);
		}else if(f2 == "-c"){
			string name2;
			player2 = new SimpleComputerPlayer();
			name2 = "Zoey";
			(*player2).setName(name2);
		}

		//initialize players based on flags here. in the header file, declare Player objects 
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 7; j++){
				boardArray[i][j] = "_";
			}
		}
	}
	//delete the constructor
	Board::~Board(){
		cout<< "deleted" <<endl;
	}

	//p1's movements, passes to update
	void Board::p1Update(){
		//human's steps
		if(flag1 == "-h"){
			// (*player1).playingGame();				
			cout << player1->getName() << "'s turn, Please enter an integer between 1 and 7: ";
			cin >> position;
			bool place = true;
			for(int i = 5; i >= 0; i--){
				//x row
				if(boardArray[i][position-1] == "_" && place){
					this->boardArray[i][position-1] = "X";//X or O; TODO: set sign function in player.cpp.
					this->changeRow = i;
					this->changeCol = position-1;
					place = false;
				}
			}
		}
		//computer's steps
		else if(flag1 == "-c"){
			//(*player1).playingGame((*player1).getBoard());
			cout << player1->getName() << "'s turn, Please enter an integer between 1 and 7: " << endl;
			for(int i = 0; i < 7; i++){
				for(int j = 5; j >= 0; j--){
					if(boardArray[j][i] == "_"){
						this->boardArray[j][i] = "X";//X or O; TODO: set sign function in player.cpp .
						this->changeRow = j;
						this->changeCol = i;
						j = -1;
						i = 7;
					}
				}
			}
		}
		print_Board();
	}

	//p2's movements, passes to update
	void Board::p2Update(){
		//human's steps
		if(flag2 == "-h"){
			// (*player1).playingGame();				
			cout << player2->getName() << "'s turn, Please enter an integer between 1 and 7: ";
			cin >> position;
			bool place = true;
			for(int i = 5; i >=0; i--){
				//x row
				if(boardArray[i][position-1] == "_" && place){
					boardArray[i][position-1] = "O";//X or O; TODO: set sign function in player.cpp .
					this->changeRow = i;
					this->changeCol = position-1;
					place = false;
				}
			}
		}

		//computer's steps
		else if(flag2 == "-c"){
			//(*player1).playingGame((*player1).getBoard());
			cout << player2->getName() << "'s turn, Please enter an integer between 1 and 7: " << endl;
			for(int i = 0; i < 7; i++){
				for(int j = 5; j >= 0; j--){
					if(boardArray[j][i] == "_"){
						this->boardArray[j][i] = "O";//X or O; TODO: set sign function in player.cpp .
						this->changeRow = j;
						this->changeCol = i;
						j = -1;
						i = 7;
					}
				}
			}
		}
		print_Board();
	}

	//Print board out 
	void Board::print_Board(){
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 7; j++){
				cout << "|";
				cout << boardArray[i][j];
			}
			cout << "|" <<endl;
		}
	}
	//check if p1 wins after every update
	bool Board::p1WinningGame(){
		//H
		//right
		countV = 0; countH = 0; countDiP = 0; countDiN = 0;
		int temp = changeCol;
		for(int i = 6; temp < 6; i--){
			if(boardArray[changeRow][temp+1] == "X"){
				countH++;
			}else{
				break;
			}
			temp++;
		}
		//left
		temp = changeCol;//6
		for(int i = 6; temp > 0; i--){
			if(boardArray[changeRow][temp-1] == "X"){
				countH++;
			}else{
				break;
			}
			temp--;
		}
		if(countH >= 3){
			return true;
		}else{
			return false;
		}

		//Vertical
		if(changeRow < 3){
			if(boardArray[changeRow+1][changeCol] == "X"){
				countV++;
				if(boardArray[changeRow+2][changeCol] == "X"){
					countV++;
					if(boardArray[changeRow+3][changeCol] == "X"){
						countV++;
					}
				}
			}
		}if(countV >= 3){
			return true;
		}else{
			return false;
		}

		//Positive(down&left) 
		//col--, row++
		int tempr = changeRow;
		int tempc = changeCol;
			for(int i = 1; tempc > 0 && tempr < 5; i++){
				if(boardArray[tempr+1][tempc-1] == "X"){
					countDiP++;
				}else{
					break;
				}
				tempr++;
				tempc--;
			}
		//up&right, col++, row--
		tempr = changeRow;
		tempc = changeCol;
			for(int i = 1; tempc < 7 && tempr > 0; i++){
				if(boardArray[changeRow-i][changeCol+i] == "X"){
					countDiP++;
				}else{
					break;
				}
				tempr++;
				tempc--;
			}
		if(countDiP >= 3){
			return true;
		}else{
			return false;
		}

		//Negative(up&left) 
		//col++,row--
		tempr = changeRow;//5
		tempc = changeCol;//0
		// cout << "changeRow: " << changeRow <<endl;
		// cout << "changeCol: " << changeCol <<endl;
			for(int i = 1; tempr > 0 && tempc > 0; i++){
				if(boardArray[changeRow-i][changeCol-i] == "X"){
					countDiN++;
				}else{
					break;
				}
				tempr--;
				tempc--;
			}
		
		//down&right
		tempr = changeRow;//5
		tempc = changeCol;//0
		// cout << "changeRow: " << changeRow <<endl;
		// cout << "changeCol: " << changeCol <<endl;
			for(int i = 1; tempr < 5 && tempc < 6; i++){
				if(boardArray[changeRow+i][changeCol+i] == "X"){
					countDiN++;
				}else{
					break;
				}
				tempr++;
				tempc++;
			}
		if(countDiN >= 3){
			return true;
		}else{
			return false;
		}	
	}
	//check if p2 wins after every update
	bool Board::p2WinningGame(){
		//H
		//right
		countV = 0; countH = 0; countDiP = 0; countDiN = 0;
		int temp = changeCol;
		for(int i = 6; temp < 6; i--){
			if(boardArray[changeRow][temp+1] == "O"){
				countH++;
			}else{
				break;
			}
			temp++;
		}
		//left
		temp = changeCol;
		for(int i = 6; temp > 0; i--){
			if(boardArray[changeRow][temp-1] == "O"){
				countH++;
			}else{
				break;
			}
			temp--;
		}
		if(countH >= 3){
			return true;
		}else{
			return false;
		}

		//Vertical
		if(changeRow < 3){
			if(boardArray[changeRow+1][changeCol] == "O"){
				countV++;
				if(boardArray[changeRow+2][changeCol] == "O"){
					countV++;
					if(boardArray[changeRow+3][changeCol] == "O"){
						countV++;
					}
				}
			}
		}if(countV >= 3){
			return true;
		}else{
			return false;
		}

		//Positive(down&left || ) 
		//col--, row++
		int tempr = changeRow;
		int tempc = changeCol;
			for(int i = 1; tempc > 0 && tempr < 5; i++){
				if(boardArray[tempr+1][tempc-1] == "O"){
					countDiP++;
				}else{
					break;
				}
				tempr++;
				tempc--;
			}
		//up&right, col++, row--
		tempr = changeRow;
		tempc = changeCol;
			for(int i = 1; tempc < 7 && tempr > 0; i++){
				if(boardArray[changeRow-i][changeCol+i] == "O"){
					countDiP++;
				}else{
					break;
				}
				tempr++;
				tempc--;
			}
		if(countDiP >= 3){
			return true;
		}else{
			return false;
		}

		tempr = changeRow;
		tempc = changeCol;
		// cout << "changeRow: " << changeRow <<endl;
		// cout << "changeCol: " << changeCol <<endl;
			for(int i = 1; tempc > 0&&tempr > 0; i++){
				if(boardArray[changeRow-i][changeCol-i] == "O"){
					countDiN++;
				}else{
					break;
				}
				tempr--;
				tempc--;
			}
		
		//down&right
		tempr = changeRow;
		tempc = changeCol;
		// cout << "changeRow: " << changeRow <<endl;
		// cout << "changeCol: " << changeCol <<endl;
			for(int i = 1; tempr < 5 && tempc < 6; i++){
				if(boardArray[changeRow+i][changeCol+i] == "O"){
					countDiN++;
				}else{
					break;
				}
				tempr++;
				tempc++;
			}
		if(countDiN >= 3){
			return true;
		}else{
			return false;
		}
	}
	//return p1's name
	string Board::returnp1Name(){
		return player1->getName();
	}
	//return p2's name
	string Board::returnp2Name(){
		return player2->getName();
	}
