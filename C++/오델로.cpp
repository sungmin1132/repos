#include<iostream>
#include <string>
using namespace std;

class com;

class Othello {
	friend class com;
public:
	char board[8][8];
	bool search(int x, int y, int stone, int dir);// for human
	bool go[8][8];

	bool search_com(int x, int y, int dir); // for computer
	bool go_com[8][8];
	
	void board_map();
	
	void change(int stone);
	void search_com_change(int a, int b);

};

class com {
	Othello draw;
public:
	int boardscore[8][8] = { {5,1,3,3,3,3,1,5}, {1,1,2,2,2,2,1,1}, {3,2,4,4,4,4,2,3}, {3,2,4,4,4,4,2,3}
	, {3,2,4,4,4,4,2,3}, {3,2,4,4,4,4,2,3} , {1,1,2,2,2,2,1,1}, {5,1,3,3,3,3,1,5} }; //가중치 설정
	bool putsearch(int boardscore[8][8], int x, int y, int dir);
	bool go_com[8][8];
	void put(int boardscore[8][8], int i, int j);
};


bool com::putsearch(int boardscore[8][8], int x, int y, int dir) {
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 };// 8방향 탐색을 위한 배열
	int dy[8] = { 0,1,-1,1,-1,0,1,-1 };
	
	bool valid = false;
	int xx = x;
	int yy = y;
	go_com[xx][yy] = true;
	for (int j = 0; j < 8; j++)
	{
		xx += dx[dir];
		yy += dy[dir];

		if (xx < 0 || xx >= 7 || yy < 0 || yy >= 7)
			break;
		if (go_com[xx][yy] || boardscore[xx][yy] == ' ' || boardscore[xx][yy] == '+')
		{
			break;
		}
		if (j == 0 && boardscore[xx][yy] == 'O')
		{
			break;
		}
		if (boardscore[xx][yy] == 'O') {
			valid = true;
			break;
		}
		go_com[xx][yy] = true;
	}
	return valid;
}

void com::put(int board[8][8], int i, int j) {

	if (board[i][j] == ' ') 
	board[i][j] = 'O';
	
}

void Othello::board_map() // 맵 그리기
{

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '0')
				board[i][j] = 'O';
			else if (board[i][j] == '1')
				board[i][j] = 'X';
		}
		cout << "  |---|---|---|---|---|---|---|---|" << endl;
		cout << i + 1 << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << board[i][3] << " | "
			<< board[i][4] << " | " << board[i][5] << " | " << board[i][6] << " | " << board[i][7] << " | " << endl;
	}
	cout << "  +---+---+---+---+---+---+---+---+" << endl;
	cout << "    1   2   3   4   5   6   7   8" << endl;
}

void Othello::change(int stone) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (stone % 2 == 1 && go[i][j]) board[i][j] = 'X';
			else if (stone % 2 == 0 && go_com[i][j]) board[i][j] = 'O';
		}
	}
}



bool Othello::search(int x, int y, int stone, int dir) {
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 };// 8방향 탐색을 위한 배열
	int dy[8] = { 0,1,-1,1,-1,0,1,-1 };
	int n, m;
	int nx = x;
	int ny = y;
	
	bool valid = false;
	go[nx][ny] = true;
	com puter;
	if (stone % 2 == 1) {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				nx += dx[dir];
				ny += dy[dir];

				if (nx < 0 || ny >= 7 || nx < 0 || ny >= 7)
					break;
				if (go[nx][ny] || board[nx][ny] == '.')
				
					break;

				if (board[nx][ny] == 'X')
				{
					valid = true;
					break;
				}
				go[nx][ny] = true;
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++) {
				nx += dx[dir];
				ny += dy[dir];

				if (nx < 0 || nx >= 7 || nx < 0 || ny >= 7)
					break;
				if (go[nx][ny] || board[nx][ny] == '.')
					break;

				if (board[nx][ny] == 'O')
				{
					valid = true;
					break;
				}
				go[nx][ny] = true;
			}
		}
	}
	return valid;
}

bool Othello::search_com(int a, int b, int dir) {
	int da[8] = { 1,1,1,0,0,-1,-1,-1 };// 8방향 탐색을 위한 배열
	int db[8] = { 0,1,-1,1,-1,0,1,-1 };
	int aa = a;
	int bb = b;
	bool valid = false;
	go_com[aa][bb] = true;

	for (int j = 0; j < 8; j++)
	{
		aa += da[dir];
		bb += db[dir];

		if (aa< 0 || aa >= 7 || bb < 0 || bb >= 7)
			break;
		if (go_com[aa][bb] || board[aa][bb] == ' ' || board[aa][bb] == '+')
		{
			break;
		}
		if (j == 0 && board[aa][bb] == 'X')
		{
			break;
		}
		if (board[aa][bb] == 'X') {
			valid = true;
			break;
		}
		go_com[aa][bb] = true;
	}
	return valid;
}


void Othello::search_com_change(int a, int b) {
	if (board[a][b] == ' ') board[a][b] = '+';
}


//void ai::search_com() {
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 8; j++) {
//			if (go[i][j]) board[i][j] = '+';
//		}
//	}
//}

int main()
{
	
	Othello draw;
	com puter;


	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			draw.board[i][j] = ' ';
	}
	draw.board[3][3] = 'O';
	draw.board[3][4] = 'X';
	draw.board[4][3] = 'X';
	draw.board[4][4] = 'O'; //보드 초기화

	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			for (j = 0; j < 8; j++) {
				memset(draw.go_com, false, sizeof(draw.go_com));
				if (draw.search_com(a, b, j)) {
					draw.search_com_change(a, b);
				}
			}
		}
	}
	draw.board_map();//초기 맵 그리기

	for (i = 1; i <= 100; i++)
	{
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				if (draw.board[a][b] == '+')
					draw.board[a][b] = ' ';
			}
		}
		int x, y;
		cout << "행과 열을 입력 : " << endl;
		cin >> x >> y;
		for (j = 0; j < 8; j++) {
			memset(draw.go, false, sizeof(draw.go));
			if (draw.search(x - 1, y - 1, i, j)) {
				if (i % 2 == 1) {
					draw.change(i);
				}
				else {
					cout << "유효한 값이 아님!" << endl;
				}
			}
		}
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				for (j = 0; j < 8; j++) {
					if (puter.boardscore[a][b] == '+')
						puter.boardscore[a][b] = 'O';
					memset(puter.go_com, false, sizeof(puter.go_com));
					if (draw.search_com(a, b, j)) {
						draw.search_com_change(a, b);
					}
				}
			}
		}
		system("cls");
		draw.board_map();
	}
}