#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void max_heapify(vector<int> &v, int i, int heap_size)
{
	int l = 2*i;
	//cout << "left " << l << endl;
	int r = 2*i+1;
	//cout << "right " << r << endl;

	//cout << "heap size " << heap_size << endl;

	int largest = 0;
	if( (l <= heap_size) && (v[l] > v[i]))
		largest = l;
	else
		largest = i;
	if( (r <= heap_size) && (v[r] > v[largest]))
		largest = r;
	if(largest != i)
	{
		int temp = v[i];
		//cout << "temp " << temp << endl;
		v[i] = v[largest];
		//cout << "i = " << i << " v[i] = " << v[i] << endl;
		v[largest] = temp;
		//cout << "largest = " << largest << " v[largest] = " << v[largest] << endl;

		max_heapify(v, largest, heap_size);
	}

}

void build_max_heap(vector<int> &v)
{
	int length = v.size();
	int heap_size = length-1;

	for (int i = floor((heap_size/2) + 0.5); i > 0; i--)
	{
		//cout << "i in the build-max-heap " << i << endl;
		max_heapify(v, i, heap_size);
	}
}


int main()
{
	int number;
	int size;
	int length;
	vector<int> v;
	vector<int> n;

	cin >> size;

	do
	{
		

		if(size == 0)
		break;

		length = size; 

		v.push_back(777);

		while(size)
		{
			cin >> number;
			v.push_back(number);
			size--;
		}

		int heap_size = v.size() - 1; 

		build_max_heap(v);

		//for(int i = 1; i <= length; i++)
		//{
		//	cout << v[i] << endl;
		//}

		for (int i = length; i > 0; i--)
		{
			n.push_back(v[1]);
			v[1] = v[i];
			//cout << " main i = " << i << endl;
			//cout << "exchange v[1] = " << v[1] << endl;
			heap_size = heap_size-1;
			max_heapify(v, 1, heap_size);
		}

		int length_n = n.size();

		//cout << "n = " << length_n << endl;

		for(int i = length_n-1; i >= 0; i--)
		{
			//cout << " i = " << i << endl;
			cout << n[i] << endl;
		}

		v.clear();
		n.clear();
		cin >> size;

	}while(size !=0);
}
