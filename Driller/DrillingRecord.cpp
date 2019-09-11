#include "DrillingRecord.h"
#include <iomanip>
#include <iostream>
using namespace std;


/*
Method to add num to array and increment the counter
*/
void DrillingRecord::addNum(double num) {
	nums[numCtr] = num;
	numCtr++;
}

/*
Method to add string to array and increment the counter
*/
void DrillingRecord::addString(string string) {
	strings[strCtr] = string;
	strCtr++;
}

/*
Returns the double at the given index
*/

double DrillingRecord::getNum(unsigned int index) const {
	return nums[index];
}

/*
Returns the string at the given index
*/
string DrillingRecord::getString(unsigned int index) const {
	return strings[index];
}

/*
Overloaded ostream operator to create correct output*/
ostream& operator<<(ostream& os, const DrillingRecord& record) {

	for (unsigned int i = 0; i < record.strCtr; i++) {
		os << record.getString(i) << ";";
	}

	for (unsigned int i = 0; i < record.numCtr; i++) {

		if (i == record.numCtr - 1) {
			os << fixed << setprecision(2) << record.getNum(i) << endl;
		}
		else {
			os << fixed << setprecision(2) << record.getNum(i) << ";";
		}

	}

	return os;
}