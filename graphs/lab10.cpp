#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
	bool test1 = FindVertex(vert1);
	bool test2 = FindVertex(vert2);
	if(test1 == true && test2 == true)
	{
		edges.insert(make_pair(make_pair(vert1, vert2), weight));
	}
}

bool Graph::FindVertex(string vert1) {
	list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;

	int flag = 0;
	for(it=vertices.begin(); it!=vertices.end(); it++) {
        if(vert1 == *it)
		{
			return true;
			flag = 1;
		}
    }

	if(flag == 0)
		return false;


}

int Graph::FindEdgeCost(string vert1, string vert2) {
	return 0;
}

int Graph::IsReachable(string vert1, string vert2) {
	return 0;
}

int main() {
    Graph G;
	string e = "END";
	string temp; 
	string f, t;
	int w;
	//vector<string> from;
	//vector<string> to;
	//vector<int> weight;
	do
	{
		cin >> temp;
		if(temp != e)
		{
			G.vertices.push_back(temp);
		}

	}while(temp != e);

	do
	{
		cin >> f;
		if(f != e)
		{
			cin  >> t >> w;
			G.AddEdge(f,t,w);
		}
	}while(f != e);

	G.PrintOut();

	// Graph::PrintOut();
}

