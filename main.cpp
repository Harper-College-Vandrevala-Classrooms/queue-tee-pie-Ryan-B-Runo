#include <string>
#include <array>
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Cutie {
    virtual string description() = 0;     // All cuties need to have a description of what makes them cute.
    virtual int cuteness_rating() = 0; // All cuties get a cuteness rating out of ten.
};

class Puppy : public Cutie {
    string description() override{
        return "Puppy";
    }
    int cuteness_rating() override {
        return 11;
    }
};

class Kitty : public Cutie {
    string description() override {
        return "Kitty";
    }
    int cuteness_rating() override {
        return 10;
    }
};

class Marmoset : public Cutie {
    string description() override {
        return "Marmoset";
    }
    int cuteness_rating() override {
        return 9;
    }
};

class QueueTees {
    int queueSize = 0;
    array<Cutie*, MAX_SIZE> queue;

    public:
    QueueTees(): queue() {
        queueSize = 0;
    }

    void enqueue(Cutie *item) {
        if (queueSize != MAX_SIZE) {
            queue[queueSize] = item;
            queueSize++;
        }else {
            cout << "queue is full" << endl;
        }
    }
    Cutie* dequeue() {
        if (queueSize != 0) {
            queueSize--;
            Cutie* item = queue[queueSize];
            return item;
        }else {
            cout << "queue is empty" << endl;
        }
    }
    int size() {
        return queueSize;
    }

};

int main() {
    // Create a bunch of objects that conform to the Cutie interface
    Puppy puppy;
    Kitty kitty;
    Marmoset marmoset;

    // Create a queue data structure
    QueueTees queue;

    // The size of the queue should equal zero since there are no objects in it
    queue.size();

    // Add the cuties to the queue
    queue.enqueue(&puppy);
    queue.enqueue(&kitty);
    queue.enqueue(&marmoset);

    cout << "Puppy: " << &puppy << endl;
    cout << "Kitty: " << &kitty << endl;
    cout << "Marmoset: " << &marmoset << endl;

    // The size of the queue should equal three since there are three objects in it
    cout << queue.size() << endl;

    // The first dequeue should return the puppy
    cout << queue.dequeue() << endl;;

    // The second dequeue should return the kitty
    cout << queue.dequeue() << endl;;

    // The first dequeue should return the pygmy marmoset
    cout << queue.dequeue() << endl;

    return 0;
}