#include "CMultiSet.h"
#include <iostream>

using namespace std;

CMultiSet::CMultiSet(int capacity)
	: values(nullptr) {
	this->size = capacity;
	values = new int[size];
	if (!values) {
		throw CBadAlloc();
	}
}

CMultiSet::CMultiSet(const CMultiSet& other) {
	size = other.size;
	values = new int[size];
	for (int i = 0; i < size; i++) {
		values[i] = other.values[i];
	}
}

CMultiSet::CMultiSet(CMultiSet&& other) {
	size = other.size;
	values = other.values;
	other.size = 0;
	other.values = nullptr;
}

CMultiSet::~CMultiSet() {
	delete[] values;
}

int CMultiSet::getElement(int index) const {
	return values[index];
}

int CMultiSet::countOfCertainElement(int value) const {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (values[i] == value)
			count++;
	}
	return count;
}

int CMultiSet::cardinality() const {
	return size;
}

int CMultiSet::findMax() const {
	if (size == 0) {
		throw CBadMaxMin();
	}
	else {
		int max = values[0];
		for (int i = 0; i < size; i++) {
			if (values[i] > max) {
				max = values[i];
			}
		}
		return max;
	}
}

int CMultiSet::findMin() const {
	if (size == 0) {
		throw CBadMaxMin();
	}
	else {
		int min = values[0];
		for (int i = 0; i < size; i++) {
			if (values[i] < min) {
				min = values[i];
			}
		}
		return min;
	}
}

void CMultiSet::addElement(int temp) {
	size++;
	int* newValues = new int[size];
	if (!newValues) {
		throw CBadAlloc();
	}
	for (int i = 0; i < size; i++) {
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
	values[size - 1] = temp;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (values[j] > values[j + 1]) {
				int temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

void CMultiSet::deleteElement(int temp) {
	if ((temp > size) || temp < 1) {
		throw CBadDelete();
	}
	temp--;
	size--;
	for (int i = temp; i < size; i++) {
		values[i] = values[i + 1];
	}
	int* newValues = new int[size];
	if (!newValues) {
		throw CBadAlloc();
	}
	for (int i = 0; i < size; i++) {
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
}

void CMultiSet::readArray() {
	int count;
	cout << "Enter count: ";
	if (!(cin >> count)) {
		throw CBadInput();
	}
	for (int i = 0; i < count; i++) {
		int value;
		cout << "Enter " << i + 1 << " value: ";
		if (!(cin >> value)) {
			throw CBadInput();
		}
		addElement(value);
	}
}

CMultiSet CMultiSet::operator+(const CMultiSet& other) const {
	CMultiSet multiSet(0);
	for (int i = 0; i < size; i++) {
		multiSet.addElement(values[i]);
	}
	for (int i = 0; i < other.cardinality(); i++) {
		multiSet.addElement(other.values[i]);
	}
	return multiSet;
}

CMultiSet CMultiSet::operator-(const CMultiSet& other) const {
	CMultiSet multiSet(0);
	int currentElement;
	for (int i = 0; i < size; i++) {
		int currentElement = values[i];
		bool isContains = false;
		for (int j = 0; j < other.size; j++) {
			if (currentElement == other.values[i]) {
				isContains = true;
				break;
			}
		}
		if (isContains) {
			multiSet.addElement(currentElement);
		}
	}
	return multiSet;
}

CMultiSet CMultiSet::operator/(const CMultiSet& other) const {
	CMultiSet multiSet(0);
	int currentElement;
	for (int i = 0; i < size; i++) {
		int currentElement = values[i];
		bool isContains = false;
		for (int j = 0; j < other.size; j++) {
			if (currentElement == other.values[i]) {
				isContains = true;
				break;
			}
		}
		if (!isContains) {
			multiSet.addElement(currentElement);
		}
	}
	return multiSet;
}

CMultiSet& CMultiSet::operator=(const CMultiSet& other) {
	size = other.size;
	values = new int[size];
	for (int i = 0; i < size; i++) {
		values[i] = other.values[i];
	}
	return *this;
}

CMultiSet& CMultiSet::operator=(CMultiSet&& other) {
	size = other.size;
	values = other.values;
	other.size = 0;
	other.values = nullptr;
	return *this;
}

istream& operator>> (istream& input, CMultiSet& other) {
	other.readArray();
	return input;
}

ostream& operator<< (ostream& output, const CMultiSet& other) {
	for (int i = 0; i < other.size; i++) {
		output << other.values[i] << " ";
	}
	output << endl;
	return output;
}