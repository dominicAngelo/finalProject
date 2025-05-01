#include "arrayListType.h"

class orderedArrayListType: public arrayListType
{
public:
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const; 
    int maxListSize() const; 
    void print() const;
    bool isItemAtEqual(int location, int item) const;
    void insertAt(int location, int insertItem);
    void insertEnd(int insertItem);
    void removeAt(int location);
    void retrieveAt(int location, int& retItem) const;
    void replaceAt(int location, int repItem);
    void clearList();
    int seqSearch(int searchItem) const;
    void insert(int insertItem);
    void remove(int removeItem);
    orderedArrayListType(int size = 100);
    orderedArrayListType (const orderedArrayListType& otherList);
    virtual ~orderedArrayListType();

protected:
    int *list;
    int length;
    int maxSize;

};
