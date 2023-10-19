#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> v{1, 5, 8, 9, 6, 7, 3, 4, 2, 0, 1};
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] == v[i + 1])
		{
			cout << "duplicate found" << endl;
			break;
		}
	}

	return 0;
}