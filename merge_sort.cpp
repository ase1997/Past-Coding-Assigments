#include <iostream>
#include <vector>

using namespace std;

int numinv;

void mergeSort(vector<int>& numvec, int left, int right);
int merge(vector<int>& numvec , int left, int mid, int right);

int countInv(vector<int>& numvec) {
    numinv = 0;
    mergeSort(numvec, 0, numvec.size());
    cout << "Sorted output: ";
    for (auto ele : numvec)
	    cout << ele << " ";
	cout << endl;
    return numinv;
    
}

//Sorts the input vector and returns the number of inversions in that vector
void mergeSort(vector<int>& numvec, int left, int right)
{
	// Your code here

	if(left + 1 < right)
	{
    	int mid = (left + right) / 2; // mid is the start of the next array
        mergeSort(numvec, left, mid);
        mergeSort(numvec, mid, right);
        numinv = numinv + merge(numvec, left, mid, right);
    }
}

int merge(vector<int>& numvec , int left, int mid, int right)
{
	// Your code here
	
	vector<int> temp = numvec; //Copy the vector to tmeporary vector to make the changes to the original one
 	
	int invCount = 0; 
    int i = left;
    int j = mid;
    int k = left;
    
    while ((i <= mid - 1) && (j < right)) 
	{ 
        if (temp[i] <= temp[j]) 
		{ 
            numvec[k++] = temp[i++]; 
        } 
        else 
		{ 
            numvec[k++] = temp[j++];
            invCount += (mid - i);  // remaining elements are inverted
        }
    }
    
    // copy remaining elements back to original array
    while (i <= mid - 1)
	{
        numvec[k++] = temp[i++]; 
    }
  
    while (j < right) 
	{
        numvec[k++] = temp[j++]; 
    }
  
    return invCount;
}
