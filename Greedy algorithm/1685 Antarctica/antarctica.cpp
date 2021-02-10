#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

void Input(vector<pair<int, int>>& stations, int& n);
int Evaluate(vector<pair<int, int>>& stations);


int main()
{
	srand(7);
	int n;
	vector<pair<int, int>> stations;

	Input(stations, n);

	cout << Evaluate(stations);
}


void Input(vector<pair<int, int>>& stations, int& n)
{
	cin >> n;

	stations.resize(n);

	for (auto& station : stations)
	{
		cin >> station.first;
		cin >> station.second;
		/*station.first = rand() % 10;
		station.second = rand() % 10;*/
	}
}


int Evaluate(vector<pair<int, int>>& stations)
{
	vector<int> connection(stations.size()); // connectivity: quick find algorithm

	for (size_t i = 0; i < connection.size(); ++i)
		connection[i] = i;

	
	for (size_t i = 0; i < stations.size(); ++i)
	{
		int a_x = stations[i].first;
		int a_y = stations[i].second;

		for (size_t j = i + 1; j < stations.size(); ++j)
		{
			int x = stations[j].first;
			int y = stations[j].second;

			if (abs(a_x - x) <= 1 && abs(a_y - y) <= 1) // stations are connected
			{
				int temp = connection[i];

				if (temp == connection[j])
					continue;

				for (size_t k = 0; k < connection.size(); ++k) // connectivity: quick find algorithm
				{
					if (connection[k] == temp)
					{
						connection[k] = connection[j];
					}
				}
			}
		}
	}

	sort(connection.begin(), connection.end());
	auto last = unique(connection.begin(), connection.end());
	

	return last - connection.begin();
}


/*
cout << endl;
	for (auto& station : stations)
	{
		cout << station.first << " " << station.second << endl;
	}
	cout << endl;


	cout << a_x << " " << a_y << "             " << x << " " << y << endl;
*/