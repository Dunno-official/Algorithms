#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void Input(int& n, int& g, int& h, vector<pair<int, int>>& squad);
int EvaluatePower(int& g, int& h, vector<pair<int, int>>& squad);


int main()
{
	vector<pair<int, int>> squad;
	int n, g, h;

	Input(n, g, h, squad);
	int64_t answer = (n >= g + h) ? EvaluatePower(g , h , squad) : -1;
	cout << answer << endl;
}


void Input(int& n, int& g, int& h, vector<pair<int, int>>& squad)
{
	cin >> n;
	cin >> g;
	cin >> h;

	squad.resize(n);

	for (auto& ork : squad)
	{
		cin >> ork.first;
		cin >> ork.second;
		/*ork.first = rand() % 3;
		ork.second = rand() % 3;;*/
	}
}


int EvaluatePower(int& g, int& h, vector<pair<int, int>>& squad)
{
	int64_t answer = 0;
	int freeSoldiers = squad.size() - g - h;

	sort(squad.begin(), squad.end(), [](pair<int, int>& ork1, pair<int, int>& ork2)
	{
		return max(ork1.first , ork1.second) > max(ork2.first, ork2.second);
	});

	size_t it = 0;

	while (freeSoldiers > 0)
	{
		for (int i = it; i < (freeSoldiers + it); ++i)
		{
			if (squad[i].first >= squad[i].second)
			{
				answer += squad[i].first;
				g--;
			}

			else
			{
				answer += squad[i].second;
				h--;
			}
		}

		it = freeSoldiers + it;
		freeSoldiers = (squad.size() - it) - max(g , 0) - max(h , 0);
	}


	for (size_t i = it; i < squad.size(); ++i)
	{
		if (squad[i].first >= squad[i].second)
		{
			if (g > 0)
			{
				answer += squad[i].first;
				g--;
			}

			else if (h > 0)
			{
				answer += squad[i].second;
				h--;
			}

			else
			{
				answer += squad[i].first;
			}
		}

		else
		{
			if (h > 0)
			{
				answer += squad[i].second;
				h--;
			}

			else if (g > 0)
			{
				answer += squad[i].first;
				g--;
			}

			else
			{
				answer += squad[i].second;
			}
		}
	}

	/*cout << endl;
	for (const auto& x : squad)
		cout << x.first << " " << x.second << endl;
	cout << endl;*/

	return answer;
}

	

