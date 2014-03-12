#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main ()
{
	int number;
	int size;
	int length;
	vector<int> v;
	int key = 0;
	int i = 0;
	cin >> size;

	do
	{
		if(size == 0)
		break;

		length = size; 

		while(size)
		{
			cin >> number;
			v.push_back(number);
			size--;
		}

		//cout << "length " << length << endl;

		if(length == 1)
			cout << v[0] << endl;

		if(length > 1)
		{
			for( int j = 1; j < length; j++)
			{
				key = v[j];
				i = j - 1;
				while(i >= 0 && v[i] > key)
				{
					v[i+1] = v[i];
					i = i-1;
				}
				v[i+1] = key;
			}

			for(int j = 0; j < length; j++)
			{
				cout << v[j] << endl;
			}
		}
		
		v.clear();
		cin >> size;

	}while(size !=0);

}
