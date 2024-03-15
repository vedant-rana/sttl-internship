
#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &A, int i, int j)
{

	if (i == A.size())
	{
		return 0;
	}

	int mn;
	mn = A[i][j] + min(helper(A, i + 1, j), helper(A, i + 1, j + 1));

	return mn;
}

int minSumPath(vector<vector<int>> &A)
{
	return helper(A, 0, 0);
}

int main()
{
	vector<vector<int>> A{{2},
						  {3, 9},
						  {1, 6, 7}};
	cout << minSumPath(A) << endl;
	return 0;
}
