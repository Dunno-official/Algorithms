#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n = 0;
	cin >> n;

	long long num = powl(2 , (n - 1));

	if (num == 0)
		num = 1;

	cout << 3 * num;
}