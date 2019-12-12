#include<iostream>
#include "player.cpp";
#include<conio.h>
#include<string.h>
#include<string>

using namespace std;
							//Array for the board
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
							//Variable Declaration
int option;
int row, column;
char turn;
bool draw = false;
							// function declaration 
void show_Board();
void Start();
void player_turn();
bool game_over();

char symbol_for_player();
void toggle_player();
// ****************************
//			Main Function
// ****************************
int main() {
	string p1, p2;
	char ch1, ch2;
	Player player1, player2;
	Start();
	cout << "Enter Player 1 name : ";
	getline(cin, p1);
	player1.set_name(p1);
	turn = symbol_for_player();
	cout << "Enter Player 2 name : ";
	cin.ignore();
	getline(cin, p2);
	player2.set_name(p2);
	

	while (game_over()) {
		show_Board();
		player_turn();
		/*if (draw==true) {
			cout << endl << "GAME DRAW.....! " << endl;
			break;
		}*/
		game_over();
	}
	system("CLS");
	cout << "\n\n\n\n\n\n\n";
	show_Board();
	if (turn == 'x' && draw == false)
		cout << endl << "Congratulation player 'x' has won the game....!" << endl;
	else if (turn == 'o' && draw == false)
		cout << endl << "Congratulation player 'o' has won the game....!" << endl;
	else
		cout << endl << "GAME DRAW.........! " << endl;
	
	_getch();
	return 0;
}
// ****************************
//		Start Function
// ****************************
void Start() {
	cout << "    _____ _______  _____     _______  ____   _____     _______  ____   _____\n"
		<< "      |      |    |             |    |    | |             |    |    | |\n"
		<< "      |      |    |             |    |----| |             |    |    | |----\n"
		<< "      |   ___|___ |_____        |    |    | |_____        |    |____| |_____\n\n"
		<< "===============================================================================\n";
	show_Board();
}
// ****************************
//		Show Board
// ****************************
void show_Board() {
	cout << "\n\n\n";
	cout << "\t\t\t TURN:   PLAYER[" << turn << "]" << endl;
	cout << "\t\t\t CHOICE of box: " << option << endl << endl;
	cout << "\t     |     |     \n";
	cout << "\t  " << board[0][0] << "  | " << board[0][1] << "   |  " << board[0][2] << " \n";
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n"; 
	cout << "\t  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << " \n";
	cout << "\t_____|_____|_____\n";
	cout << "\t     |     |     \n";
	cout << "\t  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << " \n";
	cout << "\n\n\n";
}
// ****************************
// Function for choice of symbol
// ****************************
char symbol_for_player() {
	char s;
	cout << "Enter the symbol(it can be 'x' or 'o'): ";
	cin >> s;
		if (s != 'x' && s != 'o') {
			cout << "INVALID symbol.....!" << endl;
			cout << "Please enter 'o' or 'x': ";
			symbol_for_player();
		}
		return s;
}
// ****************************
//    Toggle player function
// ****************************
void toggle_player() {
	if (turn == 'x')
		turn = 'o';
	else
		turn = 'x';
}
// ****************************
//  Player Turn Function
// ****************************
void player_turn() {
	if (turn == 'x')
		cout << "PLAYER[x]'s turn: " << endl;
	else if (turn == 'o')
		cout << "PLAYER[o]'s turn: " << endl;
										// taking input from user
	cout << "Enter your Choice: ";
	cin >> option;
										//To check which column needs to be updated
	switch (option) {
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "INVALID mov....! " << endl;
	}
	if (turn == 'x' && board[row][column] != 'x' && board[row][column] != 'o') {
		board[row][column] = 'x';
		toggle_player();  // toggle player
	}
	else if (turn == 'o' && board[row][column] != 'x' && board[row][column] != 'o') {
		board[row][column] = 'o';
		toggle_player();   //toggle player
	}
	else {
		cout << endl << "TAKEN....! " << endl << "Please choose another option:";
		player_turn();
	}
}
// ****************************
//   Game Over Function
// ****************************
bool game_over() {
									// checking the win for row or column
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;

									// checking the win for diagonal
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
		return false;

									// checkin if the game is still continuous
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'x' && board[i][j] != 'o')
				return true;

								// checks if the game is already drawn
	draw = true;
	return false;
}

