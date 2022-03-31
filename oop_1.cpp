/* Khoa Dang Do
   Dr. Arun Ravindran
   ECGR 2104 - 001
   02/05/2017 */

#include <iostream>
#include <string>
#include <sstream> // converts int to string

using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

class Date
{
	public:
		Date (string d_ate); // initialize data
		Date (); // default constructor, date 1/1/1990
		string printDate (); // returns and print dates in string type format mm/dd/yyyy)
		int getYear (); // gets and returns year
	private:
		// 3 private data members
		int month;
		int day;
		int year;
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

class DriversLicense
{
	public:
		DriversLicense (); // default constructor, name unknown, dob 1/1/1900, address unknown, gender unknown, exp 1/1/1900
		DriversLicense (string dName, string dDate);	// <---constructo only sets name and dob, others unknown
		DriversLicense (string driversN, string driversDOB, string driversA, char driversG, string expiryD); // 5 argument constructors
		void printLicenseInfo(); // displaying method
		int yearsToExpiry (int exp); // number of years to expire
	private:
		// 5 private data members
		string name;
		Date dateOfBirth;
		string address;
		char gender;
		Date expiryDate;
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

int main ()
{
	DriversLicense my_license1, my_license3("Superman", "01/01/1000");
    my_license1.printLicenseInfo(); // Prints the 5 data members on separate lines
    cout << endl;
    my_license3.printLicenseInfo();
    cout << endl;
    DriversLicense my_license2("Charlie Brown", "01/01/1980", "9201 University City Blvd. Charlotte NC 28223", 'M', "01/01/2020");
    my_license2.printLicenseInfo();
    cout << endl;
    cout << "Years to expiry " << my_license2.yearsToExpiry(2017);
	
return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

Date::Date()
{
	month = 1;
	day = 1;
	year = 1990; 
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

Date::Date (string d_ate)
{
	// 1 way to convert string numb to int (William): x[th.char] - '0';
	int x, y, z;
	x = d_ate[1] - '0';
	y = d_ate[4] - '0';
	z = (d_ate[6] -'0')*1000 + (d_ate[7] - '0')*100 + (d_ate[8] - '0')*10 + (d_ate[9] - '0');
	
	month = x;
	day = y;
	year = z;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

string Date::printDate()
{
	string line = "/";
	
	//1 of the ways to convert int to string that supports this version of DevC++, to_string does not work (support DevC++) in this case
	// self-note: try to remove std:: and leave stringstream.... to see if it still works
	std::stringstream ssM;
	ssM << month;
	std::string strM;
	ssM >> strM;
	
	std::stringstream ssD;
	ssD << day;
	std::string strD;
	ssD >> strD;
	
	std::stringstream ssY;
	ssY << year;
	std::string strY;
	ssY >> strY;
	
return (strM + line + strD + line + strY);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

int Date::getYear ()
{
    return (year);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

int DriversLicense::yearsToExpiry (int exp)
{
	int yearS;
    
	yearS = (expiryDate.getYear () - exp);
    return (yearS);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

DriversLicense::DriversLicense ()
{
	name = "unknown";
	dateOfBirth = Date ("01/01/1900");
	address = "unknown";
	gender = 'u';
	expiryDate = Date ("01/01/1900");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

DriversLicense::DriversLicense (string dName, string dDate)
{
	name = dName;
	dateOfBirth = Date (dDate); // self-note: Date(value); not Date value;
	address = "unknown";
	gender = 'u';
	expiryDate = Date ("01/01/1900");
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

DriversLicense::DriversLicense (string driversN, string driversDOB, string driversA, char driversG, string expiryD)
{
	name = driversN;
	dateOfBirth = Date(driversDOB);
	address = driversA;
	gender = driversG;
	expiryDate = Date(expiryD);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/

void DriversLicense::printLicenseInfo ()
{
	cout << name << endl;
	cout << dateOfBirth.printDate(); // self-note: try to print this separately to see if it works and works properly
	cout << endl;
	cout << address << endl;
	cout << gender << endl;
	cout << expiryDate.printDate();// this as well
	cout << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------/


