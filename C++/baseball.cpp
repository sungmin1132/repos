#include <iostream> 
#include  <string>
#include  <time.h>
#include <conio.h>

using namespace std;


class baseball {

private:
	char c;
	int strike;
	int ball;
	int input[3];
	int number[10] = { 0 };
	// 입력받는 값 저장
	int gameCount = 1;//진행되는 카운트를 보기위한

public: //playgame 함수는 public으로 선언해서 main에서 접근하도록 함

	void playGame();


};


void baseball::playGame() //playGame 함수생성 
{

	srand((unsigned int)time(0));

	int number[10] = { 0 };

	//0~9까지의 숫자를 설정
	
	for (int i = 0; i <= 9; i++)
	{
		number[i] = i;
	}

	//3가지의 난수생성 

	int x, y, T;

	for (int i = 0; i < 100; i++)
	{
		x = rand() % 9;
		y = rand() % 9;

		
		T = number[x];
		number[x] = number[y];
		number[y] = T;
	}

	/*cout << number[0] << number[1] << number[2] << endl; //난수를 number 배열에 저장*/



	while (true) {

		{
			cout << gameCount << " 회" << endl;
			cout << "0 ~ 9 의 숫자중 3개를 입력하세요\n";
			cin >> input[0] >> input[1] >> input[2];

			strike = ball = 0;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (number[i] == input[j])

					{
						if (i == j)
						{
							strike++;
						}
						else
						{
							ball++;
						}

						break;
					}
				}
			}

			if (strike == 3)
			{
				cout << "숫자를 모두 맞췄습니다." << endl;
				cout << "정답은 " << number[0] << "\t" << number[1] << "\t" << number[2] << " 입니다" << endl;
				
				cout << "계속하려면 enter키를 누르세요 or " << endl;
				
				if (_kbhit()) { //enter 키 입력 시 재실행
					c = _getch();
					if (c == 13) {
						return playGame();
					}
				}

				break;
				

			}
			else if (strike == 0 && ball == 0)
			{
				cout << "Out" << endl;
			}
			else
			{
				cout << " strike : " << strike << "점" << " / " << "ball : " << ball << "점" << endl;
			}

			gameCount++;
		}
	}

	
};


int main()
{
	baseball game;

	game.playGame(); //클래스에서 playgame 불러오기

    //사용자 입력받기


}