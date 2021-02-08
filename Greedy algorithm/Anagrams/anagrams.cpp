#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Evaluate(string& A, string& B);

int main()
{
	string A;
	string B;

	getline(cin, A);
	getline(cin, B);


	cout << Evaluate(A, B) << endl;
}


int Evaluate(string& A, string& B)
{
	int answer = 0;

	vector<int> difference(A.size());

	for (size_t i = 0; i < A.size(); ++i)
	{
		for (size_t j = 0; j < B.size(); ++j)
		{
			int diff =  B[j] - A[i];
			difference[j] = (diff >= 0) ? diff : ('Z'- A[i]) + (B[j] - 'A') + 1;
		}

		auto minDifference = min_element(difference.begin(), difference.begin() + B.size());
		auto elementToDelete = B.begin() + (minDifference - difference.begin());

		B.erase(elementToDelete);
		answer += *minDifference;
	}

	return answer;
}
