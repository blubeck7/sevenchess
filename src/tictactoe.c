#include <stdio.h>
#include <stdlib.h>

#define EMPTY '\0'
#define X 'x'
#define O 'o'

struct move_t {
	int x;
	int y;
};


void display_board(char board[3][3]);
int check_board(char board[3][3]); 
struct move_t get_player_move(void);
struct move_t get_comp_move(char board[3][3]); 
void update_board(char board[3][3], struct move_t move, char turn);


int main(void)
{
	char player;
	char c;
	char turn = X;
	struct move_t move;
	char board[3][3] = {
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY}};

	printf("Please choose X's or O's. X's go first.\n");
	printf("Enter 'X' or 'O': ");
	while (scanf("%c", &c) == EOF)
		printf("Enter X or O: ");
	if (c == 'X' || c == 'x')
		player = X; 
	else
		player = O;

	printf("You are: %c\n\n", c);

	display_board(board);
	while (!check_board(board)) {
		if (turn == player)
			move = get_player_move();
		else
			move = get_comp_move(board); 
		update_board(board, move, turn);
		display_board(board);
		if (turn == X)
			turn = O;
		else
			turn = X;
	}

	return 0;
}


void display_board(char board[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == EMPTY)
				printf(" ");
			else
				printf("%c", board[i][j]);

			if (j == 0 || j == 1)
				printf("|");
			else
				printf("\n");
		}
		if (i == 0 || i == 1)
			printf("-----\n");
	}
	printf("\n");

	return;
}


int check_board(char board[3][3])
{
	int i;

	/* check rows */
	for (i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] &&
		    board[i][0] != EMPTY)
			return 1;

	/* check columns */
	for (i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] &&
		    board[0][i] != EMPTY)
			return 1;

	/* check diags */
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] &&
	    board[0][0] != EMPTY)
		return 1;

	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] &&
	    board[0][2] != EMPTY)
		return 1;

	return 0;
}


struct move_t get_player_move(void)
{
	struct move_t move;
	char in[2];
	
	printf("Player please enter your move in the form xy: ");
	while (scanf("%s", in) == EOF) {
		printf("Invalid input\n");
		printf("Player please enter your move in the form xy: ");
	}

	move.x = atoi(in) / 10;
	move.y = atoi(in) % 10;
	printf("x=%d, y=%d\n", move.x, move.y);

	return move;
}


struct move_t get_comp_move(char board[3][3])
{ 
	struct move_t move;

	move.x = 2;
	move.y = 1;

	return move;
}


void update_board(char board[3][3], struct move_t move, char turn)
{
	board[move.x][move.y] = turn;
	
	return;
}	




