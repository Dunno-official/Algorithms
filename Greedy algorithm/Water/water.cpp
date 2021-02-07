#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Input(int& n, int& k, vector<int>& canisters);
int Evaluate(int& k, vector<int>& canisters);


int main()
{	
	int n;
	int k;
	vector<int> canisters;

	Input(n, k, canisters);

	bool impossible = any_of(canisters.begin(), canisters.end(), [&k](int& el)
	{
		return el > k;
	});

	
	if (impossible)
	{
		cout << "Impossible";
	}

	else
	{
		cout << Evaluate(k, canisters);
	}

	return 0;
}


void Input(int& n, int& k, vector<int>& canisters)
{
	cin >> n;
	cin >> k;

	canisters.resize(n);

	for (int i = 0; i < n; ++i)
	{
		//cin >> canisters[i];
		canisters[i] = rand() % k;
	}
}


int Evaluate(int& k, vector<int>& canisters)
{
	int answer = 0;

	sort(canisters.rbegin(), canisters.rend());

	for (size_t i = 0; i < canisters.size(); ++i)
	{
		for (int j = canisters.size() - 1; j > canisters.size() / 2; --j)
		{
			if (i == canisters.size() - 1)
				j = canisters.size() - 2;

			if (canisters[i] + canisters[j] <= k)
			{
				canisters.erase(canisters.begin() + j);
				break;
			}
		}

		++answer;
	}

	return answer;
}

/*
for (const auto& x : canisters)
		cout << x << " ";
	cout << endl;
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

void Input(int& n, int& k, vector<int>& canisters);
string Evaluate(int& k, vector<int>& canisters);


int main()
{
	int n;
	int k;

	vector<int> canisters;

	Input(n, k, canisters);

	bool impossible = any_of(canisters.begin(), canisters.end(), [&k](int& el)
	{
		return el > k;
	});


	string answer = impossible ? "Impossible" : Evaluate(k , canisters);
	cout << answer << endl;

	return 0;
}


void Input(int& n, int& k, vector<int>& canisters)
{
	cin >> n;
	cin >> k;

	canisters.resize(n);

	for (int i = 0 ; i < n; ++i)
	{
		cin >> canisters[i];
	}
}


string Evaluate(int& k, vector<int>& canisters)
{
	int answer = 0;

	sort(canisters.rbegin(), canisters.rend());

	while (answer < canisters.size() - 1)
	{
		for (int j = answer + 1; j < canisters.size(); ++j)
		{
			if (canisters[answer] + canisters[j] <= k)
			{
				canisters.erase(canisters.begin() + j);
				break;
			}
		}
		answer++;
	}

	return to_string(answer + 1);
}


*/