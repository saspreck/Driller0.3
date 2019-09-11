#include "DrillingRecordArray.h"


/*
Default constructor for a DrillingRecordArray object
*/
DrillingRecordArray::DrillingRecordArray() {
data = new DrillingRecord[DEFAULT_ARRAY_CAPACITY];
}

/*
Constructor for a DrillingRecordArray object with a given capacity
*/
DrillingRecordArray::DrillingRecordArray(unsigned int capacity) {
	this->capacity = capacity;
	data = new DrillingRecord[capacity];
}

/*
Destructor for DrillingRecordArray, deletes data and assigns it to a null pointer
*/
DrillingRecordArray::~DrillingRecordArray() {
	delete[] data;
	data = nullptr;
}

/*
Method to add a DrillingRecord to the DrillingRecordArray object, doubles the size of the array if necessary
*/
void DrillingRecordArray::add(DrillingRecord record) {

	//checks if the size of the array is equal to the capacity
	if (size >= capacity) {

		//doubles capacity for new array
		int newCapacity = capacity * 2;

		//creates a new drilling record array with updated size
		DrillingRecord* tempRecord = new DrillingRecord[newCapacity];

		//copies data from old array to new one
		for (unsigned int i = 0; i < capacity; i++) {
			tempRecord[i] = data[i];
		}

		//reassigns the pointer and clears the old array
		data = tempRecord;
		//tempRecord = nullptr; 
	}
	
	//puts the given record into the array and increments the size
	data[size] = record;	
	++size;

}

/*
Method to get the record at the given index
*/
DrillingRecord DrillingRecordArray::get(unsigned int index) const {
	return data[index];
}