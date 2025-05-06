#ifndef ordered_list
#define ordered_list
#include "arrayListType.h"

template <class elemType>
class orderedArrayListType : public arrayListType<elemType>
{
public:
    void inserAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void replaceAt(int location, const elemType& repItem);
    int seqSearch(const elemType& searchItem) const;
    void insert(const elemType& insertItem);
    void remove(const elemType& removeItem);

    orderedArrayListType(int size = 100);
};

template <class elemType>
void orderedArrayListType<elemType>::inserAt(int location, const elemType& insertItem)
{
    if (location < 0 || location >= maxSize)
        cout << "The position of the item to be inserted is out of range." << endl;
    else if (length >= maxSize)
        cout << "Cannot insert in a full list. " << endl;
    else
    {
        for (int i = length; i > location; i--)
            list[i] = list[i - 1];
        list[location] = insertItem;
        length++;
    }
}

template <class elemType>
void orderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (length >= maxSize)
        cout << "Cannot insert in a full list." << endl;
    else
    {
        list[length] = insertItem;
        length++
    }
}

template <class elemType>
int orderedArrayListType<elemType>::seqSearch(const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == searchItem)
        {
            found = true;
            break;
        }
    if (found)
        return loc;
    else
        return -1;
}

template <class elemType>
void orderedArrayListType<elemType>::insert(const elemType& insertItem)
{
    if (length == 0)
        list[length++] = insertItem;
    else if (length == maxSize)
        cout << "Cannot insert in a full list." << endl;
    else
    {
        int loc;
        bool found = false;
        for (loc = 0; loc < length; loc++)
        {
            if (list[loc] == insertItem)
                {
                    found = true;
                    break;
                }
        }
        for (int i = length; i = loc; i--)
            list[i] = list[i - 1];
            list[loc] = insertItem;
            length++;
    }
}

template <class elemType>
void orderedArrayListType<elemType>::remove(const elemType& removeItem)
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

template <class elemType>
void orderedArrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be replaced is out of range." << endl;
    else
        list[location] = repItem;
}

template <class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size) :arrayListType<elemType>(size)
{

}

#endif
