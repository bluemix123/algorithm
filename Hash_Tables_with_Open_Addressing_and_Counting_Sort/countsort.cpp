#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
	vector<int> A;
	vector<int> B;
	vector<int> C;
	int j = 1;
	int k = 0;
	int size;
	int length = 0;
	int number = 1;

	cin >> size; 

	do
	{

		if(size == 0)
			break;

		while(size)
		{
			cin >> number;
			A.push_back(number);
			size--;
		}

		k = A[0];
		for(int i = 0; i < A.size(); i++)
		{
			if(A[i] > k)
			{
				k = A[i];
			}
		}

		//cout << "k = " << k << endl;

		for( int i = 0; i <= k; i++)
		{
			C.push_back(0);
		}
		for(int i = 0; i < A.size(); i++)
		{
			B.push_back(0);
		}

		for(int j = 0; j < A.size(); j++)
		{
			C[ A[j] ] = C[ A[j] ] +1;
		}

		for(int i = 1; i <= k; i++)
		{
			C[i] = C[i] + C[i-1];
		}

		for(int j = (A.size()-1); j >= 0; j--)
		{
			B[ C[ A[j] ] -1 ] = A[j];
			C[ A[j] ] = C[ A[j] ] -1;
		}

		for(int j = 0; j <B.size(); j++)
		{
			cout << B[j] << endl;
		}

		cin >> size;
		A.clear();
		B.clear();
		C.clear();

	}while(size != 0);

}

