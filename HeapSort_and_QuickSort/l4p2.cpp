#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int partition(vector<int> &v,int p,int r)
{
	int x = v[r-1];
	int i = p-1;
	int temp = 0;
	//cout << " i = " << i << endl;
	//cout << " r = " << r << endl;
	for(int j = p; j < r-1; j++)
	{
		//cout << " j = " << j << endl;
		//cout << " x = " << x << endl;
		//cout << " v[j] = " << v[j] << endl;
		if( v[j] <= x)
		{
			i = i +1;
			//cout << " i = " << i << endl;
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}

	temp = v[i+1];
	v[i+1] = v[r-1];
	v[r-1] = temp;

		//for(int h = p; h < r; h++)
		//{
		//cout << "partition h = " << h << " v = " << v[h] << endl;
		//}

	return i+2;
}

void quicksort(vector<int> &v,int p,int r)
{
	if( p < r)
	{
		int q = partition(v, p, r);
		//cout << " after the partition q = " << q << endl;
		//cout << " after the partition p = " << p << endl;
		quicksort(v, p, q-1);
		//cout << "after quicksort q = " << q << endl;
		//cout << " after quicksort p = " << p << endl;
		quicksort(v, q, r);
	}
}

int main()
{
	int number;
	int size;
	vector<int> v;

	cin >> size;

	do
	{
		

		if(size == 0)
		break;

		while(size)
		{
			cin >> number;
			v.push_back(number);
			size--;
		}

		int p = 0;
		int r = v.size();

		quicksort(v, p, r);

		for(int h = p; h < r; h++)
		{
		cout << v[h] << endl;
		}


		v.clear();
		cin >> size;

	}while(size !=0);
}
