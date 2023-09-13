#include <iostream>
#include "UndirectedGraph.hpp"

using namespace std;

int main(){
    int t,n,m;
    int route_count=0;
    
    cin >> t ;
    for(int i=0; i<t; i++)
    {
		cin >> n >> m;
		UndirectedGraph* graph = new UndirectedGraph(n);
		/* store the values to your own data structure */
		for (int k=0; k<m; k++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			graph->AddEdge(v1, v2); 
		}
		/* execute your algorithm for each test */
		/* store result (shortest route) of each test in route_count */
		route_count = graph->ShortestPath();
		cout << route_count<<endl;
		delete graph;
    }

}
