#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Evaluate(vector<int>& bills, int n);

int main()
{
	int n;
	vector<int> bills = { 10 , 20 , 50 , 100 , 200 , 500 };

	cin >> n;

	if (to_string(n).back() != '0')
	{
		cout << -1 << endl;
	}

	else
	{
		cout << Evaluate(bills, n);
	}
}


int Evaluate(vector<int>& bills, int n)
{
	int answer = 0;
	int maxBill = 5;

	while (n != 0)
	{
		if (n >= bills[maxBill])
		{
			n -= bills[maxBill];
			answer++;
		}

		else
		{
			maxBill--;
		}
	}

	return answer;
}
