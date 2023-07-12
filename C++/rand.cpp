#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;


class Num {
public:
	int a;
	int b;
	int c;
	int random(int a,int b,int c);
};

int Num::random(int a,int b,int c){
	
	srand(time(NULL));
	
	int a = rand() % 9 + 1;
	int b = rand() % 9 + 1;
	int c = rand() % 9 + 1;
	return a, b, c;
	}


int main()
{
}
