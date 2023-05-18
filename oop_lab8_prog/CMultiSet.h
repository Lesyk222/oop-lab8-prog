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
    CMultiSet(CMultiSet&& other) noexcept;
    ~CMultiSet();

    int getElement(int index) const noexcept;

    int countOfCertainElement(int value) const noexcept;
    int cardinality() const noexcept;
    int findMax() const;
    int findMin() const;
    void addElement(int temp);
    void deleteElement(int temp);
    void readArray();

    CMultiSet operator+(const CMultiSet& other) const noexcept;
    CMultiSet operator-(const CMultiSet& other) const noexcept;
    CMultiSet operator/(const CMultiSet& other) const noexcept;
    CMultiSet& operator=(const CMultiSet& other);
    CMultiSet& operator=(CMultiSet&& other) noexcept;
    friend istream& operator>> (istream& input, CMultiSet& other) noexcept;
    friend ostream& operator<< (ostream& output, const CMultiSet& other);
};