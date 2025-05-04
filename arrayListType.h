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

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
    return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
    return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
    return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
    return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print()const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";
    cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual(int location, const elemType& item) const
{
    if (location < 0 || location >= length)
    {
        cout << "The location of the item to be removed it out of range." << endl;
        return false;
    }
    else
        return (list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be removed it out of range." << endl;
    else
    {
        for (int i = location; i < length - 1;; i++)
            list[i] = list[i + 1];
        length--;
    }
}

template <class elemType>
void arrayListType<elemType>::retrieveAt(int location, elemType& retItem) const
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be retrieved it out of range." << endl;
    else
        retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
}

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size <= 0)
    {
        cout << "The array size must be positive. Creating an array of the size 100. " << endl;
    }
    else
        maxSize = size;
    length = 0;

    list = new elemType[maxSize];
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=(const arrayListType<elemType& otherList)
{
    if (this != &otherList)
    {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.length;

        list = new elemType[maxSize];

        for (int i = 0; i < length; i++)
            list[i] = otherList.list[1]
    }
    return *this;
}

#endif
