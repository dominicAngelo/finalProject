#include <iostream>
#include "arrayListType.h"

using namespace std;

bool orderedArrayListType::isEmpty() const
{
    return (length == 0);
}

bool orderedArrayListType::isFull() const
{
    return (length == maxSize);
}

int orderedArrayListType::listSize() const
{
    return length;
}

int orderedArrayListType::maxListSize() const
{
    return maxSize;
}

void orderedArrayListType::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

bool orderedArrayListType::isItemAtEqual(int location, int item)const
{
    if (location < 0 || location >= length)
    {
        cout << "The location of the item to be removed " << "is out of range." << endl;
        return false;
    }
    else
        return (list[location] == item);
}

void orderedArrayListType::insertAt(int location, int insertItem)
{
    if (location < 0 || location >= maxSize)
        cout << "The position of the item to be inserted is out of range." << endl;
    else if (length >= maxSize)
        cout << "Cannot insert in a full list." << endl;
    else
    {
        for (int i = length; i>location; i--)
            list[i] = list[i-1];

            list[location] = insertItem;

            length++;
    }

void orderedArrayListType::insertEnd(int insertItem)
{
    if (length >= maxSize)
        cout << "Cannot insert in a full list." << endl;
    else
    {
        list[length] = insertItem;
        length++;
    }
}


void orderedArrayListType::removeAt(int location)
{
    if (location <0 || location >= length)
        cout << "The location of the item to be removed " << "is out of range." << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];
        length--;
    }
}

void orderedArrayListType::insert(int insertItem)
{
    if (length == 0)
        list[length++]=insertItem;
    else if (length == maxSize)
        cout << "Cannot insert in a full list." <<endl;
    else
    {
        int loc;

        bool found = false;
        for (loc = 0; loc < length; loc ++)
        {
            if (list[loc] == insertItem)
            {
                found = true;
                break;
            }
        }
    }
}

void orderedArrayListType::replaceAt(int location, int repItem)
{
    if (location < 0 || location >= length)
            cout << "The location of the item to be replaced is out of range." << endl;
    else
        list[location] = repItem;
}

int orderedArrayListType::seqSearch(int searchItem) const
{
    int loc;
    bool found = false;

    loc = 0;

    while (loc < length && !found)
        if (list[loc] == searchItem)
            found = true;
        else
            loc++;

        if (found)
            return loc;
        else
            return -1;
}

void orderedArrayListType::remove(int removeItem)
{
    int loc;
    if (length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);
            if (loc != -1)
                removeAt(loc);
            else
                cout << "The item to be deleted is not in the list." << endl;
    }
}

void orderedArrayListType::retrieveAt(int location, int& retItem) const
    {
        if (location <0 || location >= length)
            cout << "The location of the item to be removed " << "is out of range." << endl;
        else
            retItem = list[location];
    }

void orderedArrayListType::clearList()
    {
        length = 0;
    }

orderedArrayListType::orderedArrayListType(int size)
    {
        if (size <= 0)
        {
            cout << "The array size must be positive. Creating " << "an array of the size 100." << endl;

            maxSize = 100;
        }
        else
            maxSize = size;
        length = 0;

        list = new int[maxSize];
    }
orderedArrayListType::~orderedArrayListType()
{
    delete [] list;
}

orderedArrayListType::orderedArrayListType(const orderedArrayListType& otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;

    list = new int[maxSize];

    for (int j = 0; j < length; j++)
        list [j] = otherList.list[j];
}

