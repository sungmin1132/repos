#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
};

int main() {
	Color screenColor(255, 0, 0); //screenColor 객체 생성했습니다.
	
	Color* p; //p는 Color형 포인터입니다. 포인터로 선언했으면 값을 불러와야겠지요?
	
	
	p = &screenColor; // p가 screenColor의 주소를 가리키게 했습니다.
	
	p->show(); //포인터형이기에 -> 를 사용해서 show에 접근했습니다.
	
	Color colors[3]; //colors는 Color형 배열입니다. r, g, b 3가지의 원소를 가지도록 했습니다.
	
	p = colors; // p 가 colors의 주소를 가리키게 했습니다.

	
	//p->setColor(255, 0, 0); // p가 가리키는 곳에 setColor를 적용했습니다. 이후 p는 1씩 증가합니다.
	p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);

	for (int i = 0; i < 3; i++) //for 문을 이용해서 p가 가리키는 곳을 3번 출력했습니다.
	
	p[i].show();
}
/*
r g b 순서대로 red green blue 의 값을 삽입해야함. 

멤버함수 Color 에서 초기화를 해주고 show를 통해 그 값을 출력

*/