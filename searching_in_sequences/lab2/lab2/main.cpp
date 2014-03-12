#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main ()
{
	int number;
	int size;
	int length;
	vector<int> myvector;

	cin >> size;

	do
	{
		if(size == 0)
		break;

		cin >> length;
		while(size)
		{
			cin >> number;
			myvector.push_back(number);
			size--;
		}

		int fail = 1;
		while (fail) 
		{
		for (int i = 0; i< myvector.size(); i++) 
		{
		if(myvector[i] == length)
		{
		cout << i << endl;
		break;
		}
		if(i == myvector.size()-1)
		{
		cout << -1 << endl;
		break;
		}
		}


	
		myvector.clear();
		fail = 0;
		}

		cin >> size;
	} while (size != 0);

}