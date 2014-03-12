#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <math.h>

using namespace std;

struct Graph 
{
  list<string> vertices;
  map<pair<string,string>,int> edges;
  void PrintOut(void);
  void AddEdge(string,string,int);
  int FindVertex(string);
  int FindEdgeCost(string vtex1, string vert2);
  int IsReachable(string vtex1, string vert2);
};

void Graph::PrintOut(void) 
{
  list<string>::iterator it;
  map<pair<string,string>,int>::iterator eit;

  for(it=vertices.begin(); it!=vertices.end(); it++)
    cout << *it << endl;

  for ( eit = edges.begin() ; eit != edges.end() ; eit++ ) 
    cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
}

int Graph::FindVertex(string vtex1) 
{
list<string>::iterator thing;
	for(thing=vertices.begin(); thing != vertices.end(); thing++)
	{
		if(*thing == vtex1)
			return 1;
	}

	return 0;

}

void Graph::AddEdge(string vtex1,string vert2,int weight) 
{	
	if(FindVertex(vtex1) && FindVertex(vert2))
	{
		pair<string,string> p = make_pair(vtex1,vert2);
		edges[p] = weight;
	}

}

int Graph::FindEdgeCost(string vtex1, string vert2) 
{
  map<pair<string,string>,int>::iterator it = edges.find(make_pair(vtex1,vert2));
  if(it == edges.end())
    return -1;
  else
    return (*it).second;
}

int Graph::IsReachable(string vtex1, string vert2) 
{
  map<string,string> color;
  map<string,int> A;
  map<string, string> predecessor;
  queue<string> Q;
  list<string>::iterator thing;

	for(thing=vertices.begin(); thing != vertices.end(); thing++)
	{
		color[*thing] = "WHITE";	
		A[*thing] = 99999999;
		predecessor[*thing] = "";
	}

	color[vtex1] = "GRAY";
	A[vtex1] = 0;
	Q.push(vtex1);
	
	map<pair<string, string>,int>::iterator thingTwo;
	while(!Q.empty())
	{
		string u= Q.front();
		Q.pop();
		
		for(thingTwo=edges.begin(); thingTwo != edges.end(); thingTwo++)
		{
			string adjacent;
			if((*thingTwo).first.first == u)
			{
				adjacent =(*thingTwo).first.second; 
				if(color[adjacent] == "WHITE")
				{
					color[adjacent] = "GRAY";	//Gray Nodes 
					A[adjacent] = A[u]+1;
					predecessor[adjacent] = u; 
					Q.push(adjacent);
				}
			}
		}
		color[u]="BLACK";			
	}

	if(A[vert2] != 99999999)
		return A[vert2];

	return -1;
}

int main()
{
  string a,vtex1,vert2;
  int weight,operation;
  Graph G;
  
  cin>>a;
  while(a!="END") 
  {
    G.vertices.push_back(a);
    cin >> a;
  }
  
  cin>>vtex1;
  while(vtex1!="END") 
  {
    cin >> vert2;
    cin >> weight;
    G.AddEdge(vtex1,vert2,weight);
    cin >> vtex1;
  }

  cin >> operation;
  while(operation!=0) 
  {
    if(operation==1) 
	{
      cin >> vtex1;
      cout << G.FindVertex(vtex1) << endl;
    }
    else if(operation==2) 
	{
      cin >> vtex1;
      cin >> vert2;
      cout << G.FindEdgeCost(vtex1,vert2) << endl;
    }
    else if(operation==3) 
	{
      cin >> vtex1;
      cin >> vert2;
      cout << G.IsReachable(vtex1,vert2) << endl;
    }
    cin >> operation;
  }  
}
