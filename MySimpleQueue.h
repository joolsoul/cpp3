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


public:
    class Iterator : public iterator<output_iterator_tag, QueueNode, ptrdiff_t, QueueNode *, QueueNode &>
    {
        private:
            QueueNode* nodePtr;

        public:
            Iterator(QueueNode* nodePtr) : nodePtr(nodePtr) {}

        Iterator operator++()
        {
            nodePtr = nodePtr->nextNode;
            return *this;
        }

        Iterator operator++(int)
        {
            nodePtr = nodePtr->nextNode;
            return *this;
        }

        T& operator*() const
        {
            return nodePtr->val;
        }

        T* operator->()
        {
            return &(nodePtr->val);
        }

        bool operator==(const Iterator &other)
        {
            return nodePtr == other.nodePtr;
        }

        bool operator!=(const Iterator &other)
        {
            return nodePtr != other.nodePtr;
        }
    };

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

    Iterator begin() { return Iterator(this->head); }
    Iterator end() { return Iterator(nullptr); }
};

#endif //CPP3_MYSIMPLEQUEUE_H
