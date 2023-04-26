#include <iostream>
#include "MySimpleQueue.h"

using namespace std;

int main() {
    auto *queue = new MySimpleQueue<int>();

//    cout << queue->peek() << endl;

    queue->add(10);
    queue->add(11);
    queue->add(12);
    queue->add(13);

    cout << queue->peek() << endl;
    cout << endl;

    for (auto i : *queue)
    {
        cout << i << endl;
    }

    queue->poll();
    cout << endl;

    for (auto i : *queue)
    {
        cout << i << endl;
    }

    queue->clear();
    cout << endl;



    auto *strQueue = new MySimpleQueue<string>();

    strQueue->add("a");
    strQueue->add("b");
    strQueue->add("c");
    strQueue->add("d");

    cout << strQueue->peek() << endl;
    cout << endl;

    auto iterator = MySimpleQueue<string>::Iterator(strQueue->begin());

    while (iterator != strQueue->end())
    {
        cout << *iterator << endl;
        iterator++;
    }

    strQueue->poll();
    cout << endl;

    iterator = MySimpleQueue<string>::Iterator(strQueue->begin());

    while (iterator != strQueue->end())
    {
        cout << *iterator << endl;
        iterator++;
    }

    strQueue->clear();

}
