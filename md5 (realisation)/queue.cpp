#include <iostream>
#include <exception>

template <class Type>
class queue
{
private:

    struct unitQueue
    {
        unitQueue() :key(0x0), link(nullptr)
        {};

        Type key;
        unitQueue* link;
    };
    size_t sizeQueue;
    unitQueue* front, * tail;

public:

    // function-constructor
    queue()
    {
        front = nullptr;
        tail = nullptr;
        sizeQueue = NULL;
    };

    // function-destructor
    ~queue()
    {
        if (sizeQueue)
        {
            unitQueue* temp = front;
            while (front != nullptr)
            {
                front = front->link;
                delete temp;
                temp = front;
            }
        }
    };

    // function add element
    void enqueue(Type key)
    {
        if (front != nullptr)
        {
            unitQueue* temp;
            temp = new unitQueue;
            tail->link = temp;
            tail = temp;
            tail->key = key;
        }
        else
        {
            front = new unitQueue;
            tail = front;
            front->key = key;
        }
        sizeQueue++;
    };

    // function delete and return element
    Type dequeue()
    {
        if (front != nullptr)
        {
            Type tempKey = front->key;
            unitQueue* temp = front;
            front = front->link;
            delete temp;
            sizeQueue--;
            return tempKey;
        }
        else
            throw std::out_of_range("Achtung! Die Warteschlange ist leer!");
    };

    // function return first element
    Type peek() {
        if (sizeQueue)
            return front->key;
        else
            throw std::out_of_range("Achtung! Die Warteschlange ist leer!");
    };

    // function return size of queue
    size_t get_size()
    {
        return sizeQueue;
    };
};
