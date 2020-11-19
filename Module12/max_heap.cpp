#include <iostream>
#include <vector>

class MaxHeap
{
private:
    int _size{};
    std::vector<int> vect = {-1};

    int p(int i)
    {
        return i >> 1; // i / 2
    };
    int l(int i)
    {
        return i << 1; // i * 2
    };
    int r(int i)
    {
        return (i << 1) + 1; // i * 2 + 1
    };

public:

    bool isEmpty() const
    {
        return _size == 0;
    };

    int getMax() const
    {
        return vect[1];
    };

    int extractMax();
    void insertItem(int val);
    void shiftUp(int i);
    void shiftDown(int i);

    void display();
};

void MaxHeap::display()
{
    for (auto &&i : vect)
    {   
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::insertItem(int val)
{
    if (_size + 1 >= vect.size())
    {
        vect.push_back(0);
    }
    vect[++_size] = val;
    shiftUp(_size);
    return;
}

void MaxHeap::shiftUp(int i)
{
    if (i > _size)
        return;
    if (i == 1)
        return;

    if (vect[i] > vect[p(i)])
    {
        std::swap(vect[p(i)], vect[i]);
    }
    shiftUp(p(i));
}

void MaxHeap::shiftDown(int i)
{
    if (i > _size)
        return;

    int swapId = i;

    if (l(i) <= _size && vect[i] < vect[l(i)])
    {
        swapId = l(i);
    }

    if (r(i) <= _size && vect[i] < vect[r(i)])
    {
        swapId = r(i);
    }

    if (swapId != i)
    {
        std::swap(vect[i], vect[swapId]);
        shiftDown(swapId);
    }
    return;
}

int MaxHeap::extractMax()
{
    int maxNum = vect[1];

    std::swap(vect[1], vect[_size--]);
    shiftDown(1);
    return maxNum;
}

int main(void)
{
    MaxHeap *PriorityQueue = new MaxHeap();

    PriorityQueue->insertItem(10);
    PriorityQueue->insertItem(120);
    PriorityQueue->insertItem(34);
    PriorityQueue->insertItem(41);
    PriorityQueue->insertItem(5);

    PriorityQueue->display();
    
    std::cout << PriorityQueue->getMax() << std::endl;
    PriorityQueue->extractMax();
    std::cout << PriorityQueue->getMax() << std::endl;

    PriorityQueue->display();

    return EXIT_SUCCESS;
}