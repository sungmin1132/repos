using namespace std;
#include <iostream>
//MyIntStack 스택에 저장할 수 있는 정수의 최대 개수는 10이다.
class MyIntStack {
	int p[10]; // 최대 10개의 정수 저장 
	int tos = 0; // 스택의 꼭대기를 가리키는 인덱스 
public:
	MyIntStack() {};
	bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴 
	bool pop(int& n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴 
};

bool MyIntStack::push(int n)
{
	p[n] = n;
	if (n >= 10) {
		tos = n;
		return false;
	}
	else return true;
}
bool MyIntStack::pop(int& n)
{
	n = tos;
	tos--;
	if (tos < 0) return false;
	else return true;
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}