#include <iostream>
#include <stdexcept>

template <class T>
class Stack
{
private:
    struct Node
    {
        T info;
        Node *next;
    };
    Node *Top;
    size_t list_size;
public:
    Stack() //constructor of the stack
    {
        Top = NULL;
        list_size = NULL;
    };
    //constructor of the stack with size 'size' and value 'element'
    Stack(size_t size, T element)
    {
        Top = NULL;
        list_size = NULL;
        int counter = 0;
        while (counter < size)
        {
            push(element);
            counter++;
        }

    }
    ~Stack() //destructor of the stack
    {
        Node *current;
        while (Top != 0)
        {
            current = Top;
            Top = Top->next;
            delete current;
        }

    };

    void push(T data) //ads new element to the stack
    {
        Node *current;
        current = new Node;
        current->info = data;
        list_size++;
        if (Top == NULL)
        {
            Top = current;
            Top->next = 0;

        }
        else
        {

            current->next = Top;
            Top = current;
        }
    };

    T pop() //deletes top element
    {
        T data_head;
        if (list_size != 0)
        {
            Node *current;
            current = Top;
            Top = Top->next;
            list_size--;
            data_head = current->info;
            delete current;
            return data_head;
        }
        else throw std::out_of_range("Error!Out of range!");

    };
    T peek() //returns top element
    {
        if (Top!= NULL)
            return Top->info;
        else throw std::out_of_range("Error!Out of range!");
    };
    size_t get_size() //returns list's size
    {
        return list_size;
    };
};