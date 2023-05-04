#include "CMultiSet.h"
#include <iostream>

using namespace std;
int main() {
	try {
		CMultiSet arr;
		cout << "Input first multiset " << endl;
		cin >> arr;

		cout << "Output first multiset: ";
		cout << arr;

		cout << "Max: " << arr.findMax() << endl
			<< "Min: " << arr.findMin() << endl
			<< "4: " << arr.countOfCertainElement(4) << endl
			<< "Power: " << arr.cardinality() << endl;

		CMultiSet arr2;
		cout << "Input second multiset " << endl;
		cin >> arr2;

		cout << "Output second multiset: " << arr2;

		cout << "Max: " << arr2.findMax() << endl;
		cout << "Min: " << arr2.findMin() << endl;
		cout << "4: " << arr2.countOfCertainElement(4) << endl;
		cout << "Power: " << arr2.cardinality() << endl;
		cout << "Enter which element u want delete: ";
		int temp;
		cin >> temp;
		arr2.deleteElement(temp);
		cout << "After delete : " << arr2 << endl;

		CMultiSet unions = arr + arr2;
		cout << "Output unions: " << endl;
		cout << unions;

		CMultiSet intersection = arr - arr2;
		cout << "Output intersection: " << endl;
		cout << intersection;

		CMultiSet substraction = arr / arr2;
		cout << "Output substraction: " << endl;
		cout << substraction;
	}
	catch (exception& except) {
		cout << except.what() << endl;
	}
	catch (...) {
		cout << "Error.";
	}
}