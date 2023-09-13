#include <iostream>
#include "UndirectedGraph.hpp"

using namespace std;

UndirectedGraph::UndirectedGraph(int vertices)
{
    Vertices = vertices;
    adj.resize(Vertices + 1);
}

void UndirectedGraph::AddEdge(int vert1, int vert2)
{
    int temp = min(vert1, vert2);
    start = (temp < start) ? temp : start; //smallest node becomes the start 
    adj[vert1].push_back(vert2); //add vertex 2 to vertex 1's list and viceversa
    adj[vert2].push_back(vert1); 
}

//BFS algorithm inspired by www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
int UndirectedGraph::ShortestPath()
{
    vector<bool> visited(Vertices + 1);
    vector<int> distance(Vertices + 1);
    for (int i=1; i <= Vertices; i++)
    {
        visited[i] = false;
        distance[i] = 0;
    }
    
    int end = start;
    queue<int> queue;
    
    distance[start] = 0;
    visited[start] = true;
    queue.push(start);
    while (!queue.empty())
    {
        int parent = queue.front();
        end = (parent > end) ? parent : end; //store largest number in end
        queue.pop();
        
		//loop through adjacent vertices of the dequeued vertex (parent)
        for (int j: adj[parent]) 
        {	//if adjacent has not been visited, mark visited and enqueue it
            if (!visited[j])
            {
                visited[j] = true;
                distance[j] = distance[parent] + 1;
                queue.push(j);
            }
        }
    }
    
    return distance[end];
}
