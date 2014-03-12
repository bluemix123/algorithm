#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	int hashSize = 13; 
	vector<int> v;
	vector<int> h;
	vector<int> check1;
	vector<int> check2;
	int d = 0;
	int dflag = 0;
	int check = 0;
	int number = 0;
	int flag1 = 0;
	int flag = 1;
	int h1 = 0;
	int h2 = 0;
	int h3 = 0; 
	int p = 0;

		while(p < 13)
		{
			h.push_back(-1);
			p++;
		}


		while(number != -1)
		{
			cin >> number;
			if(number != -1)
			{
				v.push_back(number);

			}
		}

		int length = v.size();
		int i = 0;
		

		while(length !=  0)
		{
			h1 = v[i] % 13;
			//cout << "this is h1 " << h1 << endl;
			h2 = 1 + (v[i] % 11);
			//cout << "this is h2 " << h2 << endl;
			
			if(h[h1] == -1)
				h[h1] = v[i];
			else
			{
				int j = 1;
				h3 = (h1 + j * h2) % 13;
				//cout << "this is h3 " << h3 << endl;
				while(h[h3] !=  -1)
				{
					h3 = (h1 + j * h2) % 13;
					j++;
				}
				h[h3] = v[i];
			}
			i++;
			length--;
		}

		int n = 0;
		while(n < 13)
		{
			if(h[n] == -1)
				cout << endl;
			else
				cout << h[n] << endl; 
			n++;
		}



		while(check != -2)
		{
			cin >> check;
			if(check != -2)
			{
				check1.push_back(check);

			}
		}

		int checksize = check1.size();
		i = 0;
		while(checksize > 0)
		{
			h1 = check1[i] % 13;
			h2 = 1 + (check1[i] % 11);
			int j = 0;
			while(j < 12)
			{
				h3 = (h1 + j * h2) % 13;
				if(check1[i] == h[h3])
				{
					flag1 = 1;
					cout << h3 << endl;
				}

				j++;
			}

			if(flag1 == 0)
				cout << "NOT_FOUND" << endl;

			flag1 = 0;
			i++;
			checksize--;
		}



		while(d != -3)
		{
			cin >> d;
			if(d != -3)
			{
				check2.push_back(d);

			}
		}


		int check2size = check2.size();



		i = 0;
		while(check2size > 0)
		{
			h1 = check2[i] % 13;
			h2 = 1 + (check2[i] % 11);
			int j = 0;
			while(j < 12)
			{
				h3 = (h1 + j * h2) % 13;
				if(check2[i] == h[h3])
				{
					h[h3] = -1;
				}

				j++;
			}
			i++;
			check2size--;
		}


		n = 0;
		while(n < 13)
		{
			if(h[n] == -1)
				cout << endl;
			else
				cout << h[n] << endl; 
			n++;
		}


		check2.clear();
		check1.clear();
		v.clear();
		h.clear();

}
