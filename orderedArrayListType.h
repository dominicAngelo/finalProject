#ifndef ordered_list
#define ordered_list

template <class elemType>

class orderedArrayListType: public arrayListType
{
public:
    const orderedArrayListType<elemType>&
        operator=(const orderedArrayListType<elemType>&);

    bool isEmpty() const;
    bool isFull() const;
    int listSize() const; 
    int maxListSize() const; 
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    virtual void insertAt(int location, const elemType& insertItem);
    virtual void insertEnd(const elemType& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, const elemType& retItem) const;
    virtual void replaceAt(int location, int repItem);
    void clearList();
    virtual int seqSearch(const elemType& searchItem) const;
    void insert(int insertItem);
    virtual void remove(const elemType& removeItem);
    orderedArrayListType(int size = 100);
    orderedArrayListType (const orderedArrayListType<elemType>& otherList);
    virtual ~orderedArrayListType();

protected:
    elemType *list;
    int length;
    int maxSize;

};

#include "orderedArrayListType.cpp"
//This is so I don't have to rewrite the entire thing into here

#endif
