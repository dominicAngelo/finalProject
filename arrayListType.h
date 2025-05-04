#ifndef array_list
#define array_list

template <class elemType>
class arrayListType
{
public:
    const arrayListType<elemType>&
        operators=(const arrayListType<elemType>&);
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const elemType& item) const;
    virtual void insertAt(int location, const elemType& insertItem) = 0;
    virtual void insertEnd(const elemType& insertItem) = 0;
    void removeAt(int location);
    void retrieveAt(int location, const elemType& retItem) const;
    virtual void replaceAt(int location, const elemType& repItem) const = 0;
    void clearList();
    virtual int seqSearch(const elemType& searchItem) const = 0;
    virtual void remove(const elemType& removeItem) = 0;

    arraListType(int size = 100);
    arrayListType (const arrayListType<elemType>& otherList);
    virtual ~arrayListType();

protected:
    elemType *list;
    int length;
    int maxSize;

};
#endif
