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
	// �Է¹޴� �� ����
	int gameCount = 1;//����Ǵ� ī��Ʈ�� ��������

public: //playgame �Լ��� public���� �����ؼ� main���� �����ϵ��� ��

	void playGame();


};


void baseball::playGame() //playGame �Լ����� 
{

	srand((unsigned int)time(0));

	int number[10] = { 0 };

	//0~9������ ���ڸ� ����
	
	for (int i = 0; i <= 9; i++)
	{
		number[i] = i;
	}

	//3������ �������� 

	int x, y, T;

	for (int i = 0; i < 100; i++)
	{
		x = rand() % 9;
		y = rand() % 9;

		
		T = number[x];
		number[x] = number[y];
		number[y] = T;
	}

	/*cout << number[0] << number[1] << number[2] << endl; //������ number �迭�� ����*/



	while (true) {

		{
			cout << gameCount << " ȸ" << endl;
			cout << "0 ~ 9 �� ������ 3���� �Է��ϼ���\n";
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
				cout << "���ڸ� ��� ������ϴ�." << endl;
				cout << "������ " << number[0] << "\t" << number[1] << "\t" << number[2] << " �Դϴ�" << endl;
				
				cout << "����Ϸ��� enterŰ�� �������� or " << endl;
				
				if (_kbhit()) { //enter Ű �Է� �� �����
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
				cout << " strike : " << strike << "��" << " / " << "ball : " << ball << "��" << endl;
			}

			gameCount++;
		}
	}

	
};


int main()
{
	baseball game;

	game.playGame(); //Ŭ�������� playgame �ҷ�����

    //����� �Է¹ޱ�


}