#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Merge(vector<int> &v, int n, int p, int q , int r)
{

	int t = q-p +1;  //length of the left vector
	int y = r-q;    // length of the right vector
	vector<int> left;
	vector<int> right;

	left.clear();
	right.clear();

	for (int n = 0; n <t; n++) // left vector
	{
	left.push_back(v[p+n]);
	}
		left.push_back(2147483647);


	for (int n = 0; n <y; n++) //right vector
	{
	right.push_back(v[q+n+1]);
	}
		right.push_back(2147483647);

	int i = 0,j=0; //combine left and right
	for (int n = p; n <=r; n++)
	{
		if (left[i] < right[j])
		{
			v[n]=left[i];
			i++;
		}
		else
		{
			v[n] = right[j];
			j++;
		}
	}
	left.clear();
	right.clear();
}

void MergeSort(vector<int> &v, int n, int p , int r)
{
	if (p < r) //check to get out
	{
	int q = (int)floor((p+r)/2);
	MergeSort(v,n,p, q);
	MergeSort(v,n,q+1,r);
	Merge(v,n,p,q,r);
	}
}
int main () {
	int length = 0; 
	int p = 0;
	int i = 0;
	int s = 0;
	int count= 0;

	vector<int> v;
	p = 0;
	cin >> length; 

	if(length!=0)
	do {
	i = 0;
	length--;
	while (i <= length )
	{
	cin >> s;
	v.push_back(s);
	i++;
	}
	s = v.size();
	MergeSort(v,s, p, length);
	for (int j=0 ;j <s; j ++)
	{
		cout << v[j] << endl;
	}
	v.clear();
	cin >> length;
	}while(length!=0);
} 
