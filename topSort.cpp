// Topologically sort a directed graph. Assume graph is strongly connected.
// Your algorithm should be O(n) where n is the number of vertices in the graph

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

const int N = 8;
vector<int> topSort(int A[N][N], int start);

// Helper [DFS] function 
void topsort_helper(int source, stack <int>& s, bool visited[], int A[N][N]);


int main() {
    int A[N][N] = { {0, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, 
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0} };
 
    vector<int> res = topSort(A, 0);
    for (auto v : res) {
        cout << v << " "; // One possibility - 0 3 7 2 5 4 1 6 
    }
    cout << endl;
    return 0;
}

// Returns vertices in topologically sorted order.
// For example, if the vertices represent task dependencies, the topologically sorted order
// indicates the order in which the tasks should be performed
vector<int> topSort(int A[N][N], int start) {
// Your code here...
	
	int i = 0;
	vector <int> store_vector;
	bool visited[N]={false}; 
	stack <int> s;
	
	// DFS topological sorting algorithm, homework 8
	for(i = 0; i < N; i++)
	{
		if(!visited[i])   
		{
			topsort_helper(i, s, visited, A); // call helper
		}
	}
	
	while(!s.empty()) 
	{  
		// topologically store from top to bottom, push first element down
		store_vector.push_back(s.top()); 
		s.pop();
	}
	
	return store_vector; // store in vector and return
}



void topsort_helper(int source, stack <int>& s, bool visited[] , int A[N][N]) {
 
	visited[source] = true;
	int i = 0;
	
	// graph traversing
	for(i = 0; i < N; i++) 
	{
		if(A[source][i])
		{   
			if(!visited[i]) //if a node is not visited then
			topsort_helper(i, s, visited, A); // keep doing until all nodes in graph is visited
		}
	}
	
	s.push(source);// push elenments down from top and store them in a stack
}
