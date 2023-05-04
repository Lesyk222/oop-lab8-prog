#pragma once
#include "Exceptions.h"
#include <iostream>

using namespace std;

class CMultiSet
{
private:
    int* values;
    int size;
public:
    CMultiSet(int capacity = 0);
    CMultiSet(const CMultiSet& other);
    CMultiSet(CMultiSet&& other);
    ~CMultiSet();

    int getElement(int index) const;

    int countOfCertainElement(int value) const;
    int cardinality() const;
    int findMax() const;
    int findMin() const;
    void addElement(int temp);
    void deleteElement(int temp);
    void readArray();

    CMultiSet operator+(const CMultiSet& other) const;
    CMultiSet operator-(const CMultiSet& other) const;
    CMultiSet operator/(const CMultiSet& other) const;
    CMultiSet& operator=(const CMultiSet& other);
    CMultiSet& operator=(CMultiSet&& other);
    friend istream& operator>> (istream& input, CMultiSet& other);
    friend ostream& operator<< (ostream& output, const CMultiSet& other);
};