#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long long Evaluate(vector<int>& bills, string& n);

int main()
{
	string n;
	vector<int> bills = { 1 , 5 , 10 , 20 };

	getline(cin, n);

	cout << Evaluate(bills, n) << endl;
}


unsigned long long Evaluate(vector<int>& bills, string& n)
{
	unsigned long long _100 = 0;
	int elseBills = 0;

	int delimeter = (n.size() == 1) ? 1 : 2;
	int decimalNumber = stoi(n.substr(n.size() - delimeter, delimeter));
	int maxBill = 3;

	if (n.size() >= 3)
	{
		_100 = stoull(n.substr(0, n.size() - 2));
	}

	while (decimalNumber != 0)
	{
		if (decimalNumber >= bills[maxBill])
		{
			decimalNumber -= bills[maxBill];
			elseBills++;
		}

		else
		{
			maxBill--;
		}
	}

	return _100 + elseBills;
}
