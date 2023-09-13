#include <queue>
#include <vector>
#include <climits>

using namespace std;

class UndirectedGraph
{
private:
    vector <vector<int>> adj; //list of adjacent nodes
    int Vertices; //no. of vertices
    int start = INT_MAX; 
    
public:
    UndirectedGraph(int vertices);
    void AddEdge(int vert1, int vert2);
    int ShortestPath();
};
