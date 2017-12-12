#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> vecInt;
	vector<int>::iterator it;

	for (size_t i = 0; i < 5; ++i)
	{
		vecInt.push_back(i);
	}

	it = vecInt.begin();
	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < vecInt.size(); ++j)
		{
			if (i == vecInt.at(j))
			{
				cout << "Here is a member: " << i << endl;
			}
		}
	}

	int a;
	cin >> a;

	return 0;
}