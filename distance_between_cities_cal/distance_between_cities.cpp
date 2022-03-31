/*
Khoa Dang Do
Dr. Arun Ravindran
ECGR 2104 - 01
06 April 2017
*/

#include <iostream>
#include <string>
#include <fstream> // open, read, write, close file
#include <vector>
#include <sstream>
#include <cmath>   // use trig
#include <algorithm> 
#include <iomanip>   // show decimals

using namespace std;

// global constants, coordiantes in rads
const double eR = 3959.0;
const double pi = 3.14159265359;
const double clt_la = (pi*35.2060)/180.0;
const double clt_lo = (pi*-80.8290)/180.0;

struct City
{
	double x; // lattitude
	double y; // longtitude
	string city_state;
	double distance;
};

double dist_cal (double lat, double lon); // calculate distance between Charlotte and CITY
bool compare (City* a, City* b); // which distance is greater

int main ()
{
	string str, token;
	vector<string> temp; // vector to store values from breakin down a string line in the txt file
	vector<City*> cities; // store values of city_state, lattitude, longtitude, and distance
	
	// open txt file to extract inputs
	ifstream fileReader; 
	fileReader.open("cities.txt"); 
	// open txt file to write outputs to
	ofstream fileOutput;
	fileOutput.open("dist_clt.txt"); 

	while (getline(fileReader, str)) // extract all string lines in cities.txt
	{
		// paurse the string into elements
		stringstream ss(str);
		while (getline(ss,token,','))
		{
			temp.push_back(token);
		}
		
		// store values into vector
		City *c = new City;
		c->city_state = temp[0] + ',' + temp[1];
		c->x = stof(temp[2]);
		c->y = stof(temp[3]);
		temp.clear();
		c->distance = dist_cal (c->x, c->y); // function called to calculate distance
		cities.push_back(c);
	}
	
	sort(cities.begin(), cities.end(), compare); // arrange cities in increasing order by distance from Charlotte
	
	// write outputs to dist_clt.txt
	for (int i = 0; i < cities.size(); i++)
	{
		fileOutput << cities[i]->city_state << " " << cities[i]->distance << endl;
	}
	
	// delete vector
	for (int i = 0; i < cities.size(); i++)
	{
		delete cities[i];
	}
	
	// close both txt files
	fileReader.close (); 
	fileOutput.close();
	
return 0;
}

double dist_cal (double lat, double lon)
{
	lat = lat*pi / 180;
	lon = lon*pi / 180;
	double dLA = lat - clt_la;
	double dLO = lon - clt_lo;
	double a = pow(sin(dLA/2.0),2) + (cos(clt_la) * cos(lat) * pow(sin(dLO/2.0),2));
	double c = 2 * atan2(sqrt(a), sqrt(1.0-a));
	double d = eR * c;
	
	return d;
}

bool compare (City* a, City* b)
{
	return (a->distance < b->distance);
}

