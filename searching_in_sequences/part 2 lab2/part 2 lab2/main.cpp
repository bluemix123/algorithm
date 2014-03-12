#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
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
		int left = 0;
		int right = myvector.size()-1;
		int mid;

		
		
		while ( left <= right)
		{
			mid = (((right + left))/ 2); 
			if (myvector[mid] == length)
			{
				cout << mid << endl;
				fail = 0;
				break;
			}
			else if ( right == left )
			{
				cout << -1 << endl;
				fail = 0;
				break;
			}
			else if (myvector[mid] > length)
				right = mid-1;
			else if (myvector[mid] < length)
				left = mid +1;
		}

		if (fail)
		{
			cout << -1 << endl;
		}

		
		myvector.clear();
		
		fail = 0;
		

		cin >> size;
	} while (size != 0);

	return 3;

}