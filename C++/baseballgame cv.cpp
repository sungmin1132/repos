#include <iostream> 
#include  <string>
#include  <time.h>

using namespace std;


/*class baseball{

}*/
	
int strike = 0, ball = 0;
int input[3]; // 입력받는 값 저장
int gameCount = 1;//진행되는 카운트를 보기위한
	


int main()
{


	srand((unsigned int)time(0));

	int number[10] = {0};

	//0~9까지의 숫자를 설정
	for (int i = 0; i <= 10; i++)
	{
		number[i] = i ;
	}

	//설정된 숫자를 셔플로 섞어서 중복되지 않는 숫자를 랜덤으로 출력

	int x, y, T;

	for (int i = 0; i < 100; i++)
	{
		x = rand() % 9;
		y = rand() % 9;

		//셔플
		T = number[x];
		number[x] = number[y];
		number[y] = T;
	}
	
	cout << number[0] << number[1]<< number[2] << endl;
	

	
	//사용자 입력받기
	while (true)
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
			break;
			
			cout << "계속하려면 enter키를 누르세요" << endl;
			
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