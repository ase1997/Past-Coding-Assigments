#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// Helper function to print queue for debugging 

template<typename T> void printQueue(T& q) {
    T q_copy(q);
    while(!q_copy.empty()) {
        cout << q_copy.top() << " ";
        q_copy.pop();
    }
    cout << endl;
}
 

vector<int> findMedian(vector<int>& data) {
    priority_queue<int> max_heap; // STL Max-heap
    priority_queue<int, vector<int>, greater<int> > min_heap; // STL Min-heap
    
    vector<int> res;
    
    // Your code here 
    // Please comment out any debugging print outs
    
    if(data.size()==0) // if no data is in vector
       return res;
      
   res.push_back(data[0]);
   max_heap.push(data[0]);
  
   for(int i=1;i<data.size();i++)
   {
       if(max_heap.size() >= min_heap.size())
       {
           int maxQTop = max_heap.top();
           if(maxQTop > data[i])
           {
               max_heap.pop(); // remove top of maxHeap
               min_heap.push(maxQTop); // add MaxHeap top value into minHeap
               max_heap.push(data[i]); // add data[i] in maxHeap
           }
           else
               min_heap.push(data[i]); // simply add data[i] into minHeap
       }
       else
       {
           int minQTop = min_heap.top();
           if(minQTop < data[i])
           {
               min_heap.pop(); // remove top of minHeap
               max_heap.push(minQTop); // add minHeap top value into maxHeap
               min_heap.push(data[i]); // add data[i] in minHeap
           }
           else
               max_heap.push(data[i]); // simply add data[i] into maxHeap
       }
       if(max_heap.size() == min_heap.size() )
           res.push_back((max_heap.top() + min_heap.top())/2); // if maxHeap and minHeap size is same then do average
       // else whose size is greater then take top of that Heap
       else if(max_heap.size() > min_heap.size())
           res.push_back(max_heap.top());
       else
           res.push_back(min_heap.top());
   }
    
    return res;
}

