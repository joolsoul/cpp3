//
// Created by Ivan on 20.04.2023.
//

#ifndef CPP3_MYSIMPLEQUEUE_H
#define CPP3_MYSIMPLEQUEUE_H
#include <stdexcept>
#include <sstream>

using namespace std;


template <class T>
class MySimpleQueue
{
public:
    class QueueNode
    {
    public:
        QueueNode(T val):val(val) {};
        QueueNode(QueueNode *nextNode, T val) : nextNode(nextNode), val(val) {};

        QueueNode *nextNode = nullptr;
        T val;
    };

//public:
//    struct Iterator
//    {
//        using iterator_category = std::forward_iterator_tag;
//        using difference_type = std::ptrdiff_t;
//        using node_t = QueueNode;
//        using node_ptr = QueueNode *;
//        using node_ref = QueueNode &;
//        using type_ptr = T *;
//        using type_ref = T &;
//
//        Iterator(node_ptr ptr) : nPtr(ptr) {}
//
//        Iterator operator++()
//        {
//            nPtr = nPtr->nextNode;
//            return *this;
//        }
//
//        Iterator operator++(int)
//        {
//            Iterator stash = *this;
//            nPtr = nPtr->nextNode;
//            return stash;
//        }
//
//        type_ref operator*() const
//        {
//            return nPtr->val;
//        }
//
//        type_ptr operator->()
//        {
//            return &(nPtr->val);
//        }
//
//        bool operator==(const Iterator &other)
//        {
//            return nPtr == other.nPtr;
//        }
//
//        bool operator!=(const Iterator &other)
//        {
//            return nPtr != other.nPtr;
//        }
//
//    private:
//        node_ptr nPtr;
//    };

private:
    QueueNode *head = nullptr;
    QueueNode *tail = head;
    int size = 0;

public:
    MySimpleQueue(){};

    ~MySimpleQueue() {};

    bool add(T value)
    {
        QueueNode *newNode = new QueueNode(value);
        if (this->isEmpty())
        {
            this->head = newNode;
            this->tail = this->head;
        } else
        {
            this->tail->nextNode = newNode;
            this->tail = newNode;
        }
        size++;
        return true;
    }

    T peek()
    {
        if(this->isEmpty())
        {
            throw invalid_argument("Queue is empty!");
        }
        return this->head->val;
    }

    T poll()
    {
        if(this->isEmpty())
        {
            throw invalid_argument("Queue is empty!");
        }

        T value = this->head->val;

        QueueNode *currentHead = this->head;
        this->head = currentHead->nextNode;
        delete currentHead;

        size--;

        return value;
    }

    void clear()
    {
        QueueNode *nPtr = this->head;
        while (nPtr != nullptr)
        {
            QueueNode *nextPtr = nPtr->nextNode;
            delete nPtr;
            nPtr = nextPtr;
        }
        this->tail = nullptr;
        this->head = this->tail;
        this->size = 0;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

//    Iterator begin() { return Iterator(this->head); }
//    Iterator end() { return Iterator(nullptr); }
};

#endif //CPP3_MYSIMPLEQUEUE_H
