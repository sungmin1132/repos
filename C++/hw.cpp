using namespace std;
#include <iostream>
//MyIntStack ���ÿ� ������ �� �ִ� ������ �ִ� ������ 10�̴�.
class MyIntStack {
	int p[10]; // �ִ� 10���� ���� ���� 
	int tos = 0; // ������ ����⸦ ����Ű�� �ε��� 
public:
	MyIntStack() {};
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ���� 
	bool pop(int& n); // ���Ͽ� n�� ����. ������ ��� ������ false, �ƴϸ� true ���� 
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
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}