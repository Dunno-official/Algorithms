#include <iostream>

using namespace std;

int Evaluate(int n);

int main()
{
	int n;
	cin >> n;

	cout << Evaluate(n) << endl;

	return 0;
}


int Evaluate(int n)
{
	int fn[3] = { 2 , 4 , 7 };
	int fn_x = 0;

	for (int i = 3; i < n; ++i)
	{
		fn_x = (fn[0] + fn[1] + fn[2]) % 12345;

		fn[0] = fn[1];
		fn[1] = fn[2];
		fn[2] = fn_x;
	}

	return (n > 3) ? fn_x : fn[n - 1];
}
