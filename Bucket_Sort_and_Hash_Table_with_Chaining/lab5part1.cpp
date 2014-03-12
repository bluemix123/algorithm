#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	int bucketSize; 
	int number = 0;
	int h;
	int j = 0;
	int i = 0;
	int check = 0; 
	int flag = 1;
	int d = 0;
	vector<int> check1;

	cin >> bucketSize;

	do{
	vector< vector<double> > bucket(bucketSize);

	while(number != -1)
	{
		cin >> number;
		if(number != -1)
		{
		h = number % bucketSize;
		bucket[h].insert(bucket[h].begin(), number);
		}
	}

	for(i = 0; i < bucketSize; i++)
	{
		for(j = 0; j < bucket[i].size() ;j++)
		{
			cout << bucket[i] [j] << "->";
		}
		cout << endl;
	}



	while(check != -2)
	{
		cin >> check;
		if(check != -2)
		{
			flag = 1;
			int r = check % bucketSize;
			for(i = 0; i < bucket(r).size(); i++)
			{
					if(bucket [r] [i] == check)
					{
						
						cout << r << "," << i << endl;
						flag = 0;
					}
				
			}

			if(flag == 1)
			{
				cout << "NOT_FOUND" << endl;
			}
		}
	}

	while(d != -3)
	{
		cin >> d;
		if(d != -3)
		{
			int r = d % bucketSize;
			for(i = 0; i < bucket(r).size(); i++)
			{
					if(bucket [r] [i] == d)
					{
						bucket[i].erase(bucket[i].begin()+i);
					}
			}

		}
	}


	for(i = 0; i < bucketSize; i++)
	{
		for(j = 0; j < bucket[i].size() ;j++)
		{
			cout << bucket[i] [j] << "->";
		}
		cout << endl;
	}


	}while(d != -3);
	
}
