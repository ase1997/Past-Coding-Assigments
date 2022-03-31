// Find the number of connected components of an undirected graph
// Your algorithm should be of O(n) where n is the number of vertices in the graph


#include <iostream>


using namespace std;

const int N = 6;
int numConnectedComponents(int A[N][N]);


int main() {
    int A[N][N] = { {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 1, 0, 0, 0, 0} };
    cout << numConnectedComponents(A) << endl; // Should output 3
}


int numConnectedComponents(int A[N][N]) {
    // Your code here...
    
	int i = 0;
	int m = 0; // row
	int n = 0 ;// column 
	int c=0;
	
   	for(i = 0; i < N*N; i++)
   	{
   		int m = i / N; // split 2d array to get row
   		int n = i % N; // split 2d array to get column
   			if (A[m][n] == 1)
   			{
   				c++;
			}
	}


   	c = c / 2; // 2d array / 2
   	
   return c; // returns c
    
}
