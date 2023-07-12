//#include <iostream>
//#include <stdlib.h>
//#include <conio.h>
//#include <stdio.h>
//#include <dos.h>
//#include <windows.h>
//using namespace std;
//void gotoxy(int x, int y);
//
//void gotoxy(int x, int y)
//{
//	COORD pos = {x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//
//void Display(char[8][8]);
//void Display(char Board[8][8])
//{
//	int i;
//	for (i = 0; i < 8; i++)
//	{
//		cout << "  +---+---+---+---+---+---+---+---+" << endl;
//		cout << i + 1 << " | " << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " | " << Board[i][3] << " | " << Board[i][4] << " | " << Board[i][5] << " | " << Board[i][6] << " | " << Board[i][7] << " |" << endl;
//	}
//	cout << "  +---+---+---+---+---+---+---+---+" << endl;
//	cout << "    A   B   C   D   E   F   G   H  " << endl;
//}
//void main()
//{
//Intro:
//	randomize();
//	int i, j, W, Done, Melon = 0;
//	char A, B, pos[2], X, Y, Board[8][8];
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//			Board[i][j] = ' ';
//	}
//	cout << "\t\t\t" << "WELCOME TO OTHELLO GAME !!!!!!" << "\n\n";
//	cout << "The Rules are as usual:" << endl << endl;
//	cout << "In the End, Player which will have more tokens than its Opponent Wins the Game" << "\n\n";
//	cout << " !    @    #    $    %    ^    &    *    (    )    /    -    +    = " << endl << endl;
//	delay(3000);
//	cout << "Enter Your Token Symbol: "; cin >> A;
//	cout << "Enter Opponent's Token Symbol: "; cin >> B;
//	if (A == B)
//	{
//		cout << endl << "\t\t" << "LOL !!! Both the Tokens are Same........";
//		delay(1000);
//		goto Intro;
//	}
//	char tICK = A;
//	char Tick = B;
//	char* Quote[5] = { "AND","THE","GAME","STARTS","NOW !!!" };
//	for (i = 0; i < 5; i++)
//	{
//		cout << "\n\n" << "\t\t\t" << Quote[i] << "  ";
//		delay(500);
//	}
//	delay(1000);
//	Board[3][3] = A; Board[3][4] = B;
//	Board[4][3] = B; Board[4][4] = A;
//start:
//	Display(Board);
//	A = tICK;
//	cout << endl << "Your (" << A << ") Turn........";
//	delay(1000);
//	cout << endl << "Enter Position: ( Like A1, G6, C3 etc. ) "; gets(pos);
//	cout << endl;
//	if (pos[0] == 'A')
//		X = 0;
//	else if (pos[0] == 'B')
//		X = 1;
//	else if (pos[0] == 'C')
//		X = 2;
//	else if (pos[0] == 'D')
//		X = 3;
//	else if (pos[0] == 'E')
//		X = 4;
//	else if (pos[0] == 'F')
//		X = 5;
//	else if (pos[0] == 'G')
//		X = 6;
//	else if (pos[0] == 'H')
//		X = 7;
//	else
//	{
//		cout << "Enter Again...";
//		delay(500);
//		goto start;
//	}
//	if (pos[1] == '1')
//		Y = 0;
//	else if (pos[1] == '2')
//		Y = 1;
//	else if (pos[1] == '3')
//		Y = 2;
//	else if (pos[1] == '4')
//		Y = 3;
//	else if (pos[1] == '5')
//		Y = 4;
//	else if (pos[1] == '6')
//		Y = 5;
//	else if (pos[1] == '7')
//		Y = 6;
//	else if (pos[1] == '8')
//		Y = 7;
//	else
//	{
//		cout << "Enter Again...";
//		delay(500);
//		goto start;
//	}
//	if (Board[Y][X] != ' ')
//	{
//		cout << "Enter Again...";
//		delay(500);
//		goto start;
//	}
//	Board[Y][X] = A;
//	B = Tick;
//	// Left Check 
//	for (j = X - 1; j >= 0; j--)
//	{
//		if (Board[Y][j] == B)
//			Board[Y][j] = A;
//		else
//			break;
//	}
//	if (Board[Y][j] != A)
//	{
//		for (j = X - 1; j >= 0; j--)
//		{
//			if (Board[Y][j] == A)
//				Board[Y][j] = B;
//			else
//				break;
//		}
//	}
//	// Right Check 
//	for (j = X + 1; j < 8; j++)
//	{
//		if (Board[Y][j] == B)
//			Board[Y][j] = A;
//		else
//			break;
//	}
//	if (Board[Y][j] != A)
//	{
//		for (j = X + 1; j < 8; j++)
//		{
//			if (Board[Y][j] == A)
//				Board[Y][j] = B;
//			else
//				break;
//		}
//	}
//	// Up Check 
//	for (i = Y - 1; i >= 0; i--)
//	{
//		if (Board[i][X] == B)
//			Board[i][X] = A;
//		else
//			break;
//	}
//	if (Board[i][X] != A)
//	{
//		for (i = Y - 1; i >= 0; i--)
//		{
//			if (Board[i][X] == A)
//				Board[i][X] = B;
//			else
//				break;
//		}
//	}
//	// Down Check 
//	for (i = Y + 1; i < 8; i++)
//	{
//		if (Board[i][X] == B)
//			Board[i][X] = A;
//		else
//			break;
//	}
//	if (Board[i][X] != A)
//	{
//		for (i = Y + 1; i < 8; i++)
//		{
//			if (Board[i][X] == A)
//				Board[i][X] = B;
//			else
//				break;
//		}
//	}
//	// UL Diagonal Check 
//	i = Y - 1; j = X - 1;
//	while (i >= 0 && j >= 0)
//	{
//		if (Board[i][j] == B)
//			Board[i][j] = A;
//		else
//			break;
//		i--; j--;
//	}
//	if (Board[i][j] != A)
//	{
//		i = Y - 1; j = X - 1;
//		while (i >= 0 && j >= 0)
//		{
//			if (Board[i][j] == A)
//				Board[i][j] = B;
//			else
//				break;
//			i--; j--;
//		}
//	}
//	// UR Diagonal Check 
//	i = Y - 1; j = X + 1;
//	while (i >= 0 && j < 8)
//	{
//		if (Board[i][j] == B)
//			Board[i][j] = A;
//		else
//			break;
//		i--; j++;
//	}
//	if (Board[i][j] != A)
//	{
//		i = Y - 1; j = X + 1;
//		while (i >= 0 && j < 8)
//		{
//			if (Board[i][j] == A)
//				Board[i][j] = B;
//			else
//				break;
//			i--; j++;
//		}
//	}
//	// DL Diagonal Check 
//	i = Y + 1; j = X - 1;
//	while (i < 8 && j >= 0)
//	{
//		if (Board[i][j] == B)
//			Board[i][j] = A;
//		else
//			break;
//		i++; j--;
//	}
//	if (Board[i][j] != A)
//	{
//		i = Y + 1; j = X - 1;
//		while (i < 8 && j >= 0)
//		{
//			if (Board[i][j] == A)
//				Board[i][j] = B;
//			else
//				break;
//			i++; j--;
//		}
//	}
//	// DR Diagonal Check 
//	i = Y + 1; j = X + 1;
//	while (i < 8 && j < 8)
//	{
//		if (Board[i][j] == B)
//			Board[i][j] = A;
//		else
//			break;
//		i++; j++;
//	}
//	if (Board[i][j] != A)
//	{
//		i = Y + 1; j = X + 1;
//		while (i < 8 && j < 8)
//		{
//			if (Board[i][j] == A)
//				Board[i][j] = B;
//			else
//				break;
//			i++; j++;
//		}
//	}
//	Display(Board);
//	delay(500);
//	Done = 1;
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			if (Board[i][j] == ' ')
//				Done = 0;
//		}
//	}
//	if (Done == 1)
//		goto end;
//	/*                                */
//	cout << endl << "Opponent's (" << B << ") Turn........";
//	delay(1000);
//again:
//	X = random(8);
//	Y = random(8);
//	W = 0;
//	if (Board[Y][X] != ' ')
//		goto again;
//	if (Board[Y + 1][X] == A)
//		W++;
//	if (Board[Y][X + 1] == A)
//		W++;
//	if (Board[Y + 1][X + 1] == A)
//		W++;
//	if (Board[Y - 1][X] == A)
//		W++;
//	if (Board[Y][X - 1] == A)
//		W++;
//	if (Board[Y - 1][X - 1] == A)
//		W++;
//	if (Board[Y + 1][X - 1] == A)
//		W++;
//	if (Board[Y - 1][X + 1] == A)
//		W++;
//	if (W == 0 && Melon < 15)
//		goto again;
//	Board[Y][X] = B;
//	Melon++;
//	// Left Check 
//	for (j = X - 1; j >= 0; j--)
//	{
//		if (Board[Y][j] == A)
//			Board[Y][j] = B;
//		else
//			break;
//	}
//	if (Board[Y][j] != B)
//	{
//		for (j = X - 1; j >= 0; j--)
//		{
//			if (Board[Y][j] == B)
//				Board[Y][j] = A;
//			else
//				break;
//		}
//	}
//	// Right Check 
//	for (j = X + 1; j < 8; j++)
//	{
//		if (Board[Y][j] == A)
//			Board[Y][j] = B;
//		else
//			break;
//	}
//	if (Board[Y][j] != B)
//	{
//		for (j = X + 1; j < 8; j++)
//		{
//			if (Board[Y][j] == B)
//				Board[Y][j] = A;
//			else
//				break;
//		}
//	}
//	// Up Check 
//	for (i = Y - 1; i >= 0; i--)
//	{
//		if (Board[i][X] == A)
//			Board[i][X] = B;
//		else
//			break;
//	}
//	if (Board[i][X] != B)
//	{
//		for (i = Y - 1; i >= 0; i--)
//		{
//			if (Board[i][X] == B)
//				Board[i][X] = A;
//			else
//				break;
//		}
//	}
//	// Down Check 
//	for (i = Y + 1; i < 8; i++)
//	{
//		if (Board[i][X] == A)
//			Board[i][X] = B;
//		else
//			break;
//	}
//	if (Board[i][X] != B)
//	{
//		for (i = Y + 1; i < 8; i++)
//		{
//			if (Board[i][X] == B)
//				Board[i][X] = A;
//			else
//				break;
//		}
//	}
//	// UL Diagonal Check 
//	i = Y - 1; j = X - 1;
//	while (i >= 0 && j >= 0)
//	{
//		if (Board[i][j] == A)
//			Board[i][j] = B;
//		else
//			break;
//		i--; j--;
//	}
//	if (Board[i][j] != B)
//	{
//		i = Y - 1; j = X - 1;
//		while (i >= 0 && j >= 0)
//		{
//			if (Board[i][j] == B)
//				Board[i][j] = A;
//			else
//				break;
//			i--; j--;
//		}
//	}
//	// UR Diagonal Check 
//	i = Y - 1; j = X + 1;
//	while (i >= 0 && j < 8)
//	{
//		if (Board[i][j] == A)
//			Board[i][j] = B;
//		else
//			break;
//		i--; j++;
//	}
//	if (Board[i][j] != B)
//	{
//		i = Y - 1; j = X + 1;
//		while (i >= 0 && j < 8)
//		{
//			if (Board[i][j] == B)
//				Board[i][j] = A;
//			else
//				break;
//			i--; j++;
//		}
//	}
//	// DL Diagonal Check 
//	i = Y + 1; j = X - 1;
//	while (i < 8 && j >= 0)
//	{
//		if (Board[i][j] == A)
//			Board[i][j] = B;
//		else
//			break;
//		i++; j--;
//	}
//	if (Board[i][j] != B)
//	{
//		i = Y + 1; j = X - 1;
//		while (i < 8 && j >= 0)
//		{
//			if (Board[i][j] == B)
//				Board[i][j] = A;
//			else
//				break;
//			i++; j--;
//		}
//	}
//	// DR Diagonal Check 
//	i = Y; j = X;
//	while (i < 8 && j < 8)
//	{
//		if (Board[i][j] == A)
//			Board[i][j] = B;
//		else
//			break;
//		i++; j++;
//	}
//	if (Board[i][j] != B)
//	{
//		i = Y; j = X;
//		while (i < 8 && j < 8)
//		{
//			if (Board[i][j] == B)
//				Board[i][j] = A;
//			else
//				break;
//			i++; j++;
//		}
//	}
//	Display(Board);
//	delay(500);
//	Done = 1;
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			if (Board[i][j] == ' ')
//				Done = 0;
//		}
//	}
//	if (Done == 1)
//		goto end;
//	goto start;
//end:
//	cout << endl;
//	delay(1000);
//	int Pla = 0, Opp = 0;
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			if (Board[i][j] == A)
//				Pla++;
//			if (Board[i][j] == B)
//				Opp++;
//		}
//	}
//	clrscr();
//	if (Pla > Opp)
//	{
//		gotoxy(30, 10);
//		cout << "YOU WON THE GAME !!!!!!";
//	}
//	if (Pla < Opp)
//	{
//		gotoxy(30, 10);
//		cout << "OPPONENT WON THE GAME !!!!!!";
//	}
//	if (Pla == Opp)
//	{
//		gotoxy(30, 10);
//		cout << "IT IS A DRAW !!!!!!";
//	}
//	getch();
//}