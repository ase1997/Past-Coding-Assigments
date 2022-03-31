/* Khoa Dang Do
   Dr. Arun Ravindran
   ECGR 2104-01
   01/29/2017 */
   

/* Counter class */

#include <iostream>


using std::cout;
using std::endl;

class CounterType {
    // Write the declaration for the class
    public:
    	//mutators
		void setCount (int newNum); //get value assigned in main to newNum
		void incCount(); 
		void decCount();
		//accessor
		int getCount();
	private: //give the user to access to this variable
		int initial_num;
    

};

int main()
{
    CounterType ctr;
    ctr.setCount(1); // Set count to 1
    cout << ctr.getCount() << endl; // Outputs count
    ctr.incCount(); // Increments count
    cout << ctr.getCount() << endl; // Verify increment worked correctly
    ctr.decCount(); // Decrement count
    ctr.decCount(); // Decrement count
    cout << ctr.getCount() << endl; // Verify decrement worked correctly
    ctr.decCount(); // Decrement count // Should print Invalid Operation
    return 0;

}

void CounterType::setCount (int newNum)
{
	initial_num = newNum;
}

int CounterType::getCount()
{
	return initial_num;
}

void CounterType::incCount()
{
	initial_num++;
	if (initial_num <0) //check negative value
	{
		cout << "Invalid Operation";
	}
}

void CounterType::decCount()
{
	initial_num--;
	if (initial_num <0) //value
	{
		cout << "Invalid Operation";
	}
}

