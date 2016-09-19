	Board::Board(string flag1, flag2){
		this.flag1 = flag1;
		this.flag2 = flag2;

		if(flag1 == "-h"){
			string name1;
			player1 = new HumanPlayer();
			cout << "Player One, please enter your name: ";
			cin >> name1;
			cout << endl;
			(*player1).setName(name1);
		}
		else if(flag1 == "-c"){
			player1 = new SimpleComputerPlayer();
		}	

		if(flag2 == "-h"){
			string name2;
			//HumanPlayer p1 = (HumanPlayer*) &player1;
			player2 = new HumanPlayer();
			//HumanPlayer p1;
			//player1 = p1;
			cout << "Player One, please enter your name: ";
			cin >> name2;
			cout << endl;
			(*player2).setName(name2);
		}else{
			//SimpleComputerPlayer p1 = (SimpleComputerPlayer*) &player1;
			// player1 = SimpleComputerPlayer p1;
			player2 = new SimpleComputerPlayer();
		}


		//initialize players based on flags here. in the header file, declare Player objects 
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 7; j++){
				boardArray[i][j] = "_";
			}
		}
	}

	
void Board::p1Update(){
	//p1's movements
		//human's steps
		if(flag1 == "-h"){
			(*player1).playingGame();
			int x = (*player1).getPosition();
			for(int i = 6; i > 0; i--){
				//x row
				if(boardArray[x-1][i] == "_"){
					boardArray[x-1][i] == "X";//X or O; TODO: set sign function in player.cpp .
					this->changeRow = x-1;
					this->changeCol = i;
				}
			}
		}

		//computer's steps
		else if(flag1 == "-c"){
				//(*player1).playingGame((*player1).getBoard());
			player1->getName();
			cout << "'s turn, Please enter an integer between 1 and 7: ";
			for(int i = 0; i < 7; i++){
				for(int j = 6; j > 0; j--){
					if(boardArray[i][j] == "_"){
						boardArray[i][j] == "X";//X or O; TODO: set sign function in player.cpp .
						this->changeRow = i-1;
						this->changeCol = j;
					}
				}
			}
		}
		print_Board();
		p1WinningGame();
	}