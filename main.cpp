#include <iostream>
#include "MySimpleQueue.h"

using namespace std;

int main() {
    auto *queue = new MySimpleQueue<int>();

    queue->add(10);
    queue->add(11);
    queue->add(12);
    queue->add(13);

    cout << queue->peek() << endl;

    for (auto i : *queue)
    {
        cout << i << endl;
    }

    queue->poll();

    queue->clear();


}
