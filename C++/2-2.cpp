#include <iostream>

double area(int r)
{
	return 3.14 * r * r;
}

using namespace std;

int main()
{
	int n = 3;
	char c = '#';
	cout << c << 5.5 << '-' << n << "hello" << true << endl;
	cout << "n+5" << n + 5 << '\n';
	cout << "¸éÀûÀº " << area(n);
}
