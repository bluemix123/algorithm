#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
int main()
{
	int l = 0;
	int number = 0;
	vector<int> p;
	
	cin >> l;
	do{
		int n = l; 
		//cout << "n " << n << endl;
		while(l != -1)
			{
				cin >> number;
				p.push_back(number);
				l--;
			}

	    int** m = new int*[n];
	    int** s = new int*[n-1];
	    //cout << " n = " << n << endl;
	    int i, j, k, L, q;
	 
	   
	 
	    // cost is zero when multiplying one matrix.
	    for (i = 0; i < n; i++)
	    {
		m[i] = new int [n];
		//cout << "this is i in " << i << endl;
		m[i][i] = 0;
	    }

		for(int x = 0; x < n-1; x++)
		{
		s[x] = new int [n];
		}

	    // L is chain length.  
	    for (L=2; L<=n; L++)   
	    {

		//cout <<"L = " << L << endl;
		for (i=0; i<n-L+1; i++)
	       {
		//cout << "i = " << i << endl;
		    j = i+L-1;
		//cout << "j = " << j << endl;
		    m[i][j] = 2147483647;
		    for (k=i; k<=j-1; k++)
		    {
			//cout << "k = " << k << endl;
		        // q = cost/scalar multiplications
		        q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
			//cout <<"q = " << q << endl;
		        if (q < m[i][j])
			{
		            m[i][j] = q;
			    s[i][j] = k;
			}	
		    }
		}
	    }

	    cout << m[0][n-1] << endl;


		cin >> l; 

		for(int y = 0; y<n; y++)
		{
			delete [] m[y];
		}
		delete [] m; 


		p.clear();
	
	}while( l != 0);

    return 0;
}
