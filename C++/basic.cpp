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
	Color screenColor(255, 0, 0); //screenColor ��ü �����߽��ϴ�.
	
	Color* p; //p�� Color�� �������Դϴ�. �����ͷ� ���������� ���� �ҷ��;߰�����?
	
	
	p = &screenColor; // p�� screenColor�� �ּҸ� ����Ű�� �߽��ϴ�.
	
	p->show(); //���������̱⿡ -> �� ����ؼ� show�� �����߽��ϴ�.
	
	Color colors[3]; //colors�� Color�� �迭�Դϴ�. r, g, b 3������ ���Ҹ� �������� �߽��ϴ�.
	
	p = colors; // p �� colors�� �ּҸ� ����Ű�� �߽��ϴ�.

	
	//p->setColor(255, 0, 0); // p�� ����Ű�� ���� setColor�� �����߽��ϴ�. ���� p�� 1�� �����մϴ�.
	p[0].setColor(255, 0, 0);
	p[1].setColor(0, 255, 0);
	p[2].setColor(0, 0, 255);

	for (int i = 0; i < 3; i++) //for ���� �̿��ؼ� p�� ����Ű�� ���� 3�� ����߽��ϴ�.
	
	p[i].show();
}
/*
r g b ������� red green blue �� ���� �����ؾ���. 

����Լ� Color ���� �ʱ�ȭ�� ���ְ� show�� ���� �� ���� ���

*/