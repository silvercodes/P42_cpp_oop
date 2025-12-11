#include <iostream>

// QUEUE
// FIFO (First In First Out)
// Можно реализовать на
//      Static array
//      Dynamic array
//      Linked List
//      TwoLinkedList
//      ....
// Виды очередей
//      1. Простая очередь
//      2. Кольцевая очередь
//      3. Очередь с приоритетами
//          3.1 С приоритетным исключением
//          3.2 С приоритетным включением


class Queue
{
private:
    static const int DEFAULT_STEP = 5;

    int count;
    int* arr;
    int capacity;
    int step;

    void reallocateMemory()
    {
        if (this->arr == nullptr)
        {
            this->arr = new int[this->step];
            this->capacity = step;
            
            return;
        }

        this->capacity = this->count + this->step;

        int* temp = new int[this->capacity];
        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] this->arr;
        this->arr = temp;
    }

    bool isNotAllocated()
    {
        return this->arr == nullptr;
    }

public:
    Queue():
        count{},
        arr{nullptr},
        capacity{},
        step{Queue::DEFAULT_STEP}
    { }

    Queue(const Queue& obj) :
        count{ obj.count },
        arr{ new int[obj.capacity] },
        capacity{ obj.capacity },
        step{ obj.step }
    {
        for (int i{}; i < this->count; ++i)
            arr[i] = obj.arr[i];
    }

    void enqueue(int val)
    {
        if (this->isFull() || this->isNotAllocated())
            this->reallocateMemory();

        this->arr[this->count] = val;

        ++count;
    }

    int dequeue()
    {
        if (!this->isEmpty())
        {
            int val = arr[0];

            for (int i{}; i < count - 1; ++i)
                arr[i] = arr[i + 1];

            --this->count;

            return val;
        }

        return -1;      // This is Kostil
    }

    bool isEmpty() const
    {
        return this->count < 1 || this->arr == nullptr;
    }

    bool isFull() const
    {
        return this->count == this->capacity;
    }

    void render()
    {
        std::cout << "capacity = " << this->capacity << '\n';
        std::cout << "count = " << this->count << '\n';
        std::cout << "arr: ";
        for (int i{}; i < this->count; ++i)
            std::cout << arr[i] << ' ';
        std::cout << "\n\n";
    }

    ~Queue()
    {
        if (!this->isNotAllocated())
            delete[] this->arr;
    }

};

int main()
{
    Queue a{};
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(7);
    a.render();

    std::cout << a.dequeue() << '\n';
    a.render();

    Queue b{ a };
    b.render();
}


