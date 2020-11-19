/*
    Ari Yonaty
    Min heap in C++
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>

class minHeap
{
private:
    int size;              // current size  of heap
    int capacity;          // max size of heap
    std::vector<int> heap; // store elements as a vector

    /* Returns the parent index */
    int parent(int i)
    {
        return (i - 2) / 2;
    }
    /* Returns the left child */
    int left(int i)
    {
        return 2 * i + 1;
    }
    /* Returns the right child */
    int right(int i)
    {
        return 2 * i + 2;
    }

public:
    minHeap(int capacity);
    ~minHeap();

    void insert(int k);  // insert key into min heap
    int extractMin();    // extracts the minimum elements
    void heapify(int i); // recursively heapify a sub-tree
    void printHeap();    // print the heap
};

/* Constructor that sets the heap size and capacity */
minHeap::minHeap(int capacity)
{
    size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

/* Deconstructor */
minHeap::~minHeap()
{
}

/* Insert key into the minHeap */
void minHeap::insert(int k)
{
    // make sure there is space in heap
    if (size == capacity)
    {
        std::cout << "Min heap full." << std::endl;
        return;
    }

    size++;

    int i = size - 1; // insert new key at end
    heap[i] = k;

    // Fix main heap property
    // Move elements up until i>= parent or root
    while (i != 0 && heap[parent(i)] > heap[i])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

/* Recursive function to maintain structure */
void minHeap::heapify(int i)
{
    // set initial conditions
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // find smallest element of the three vars
    if ((l < size) && (heap[l] < heap[smallest]))
    {
        smallest = l;
    }
    if ((r < size) && (heap[r] < heap[smallest]))
    {
        smallest = r;
    }

    // If smallest of l or r, continue heapify
    if (smallest != i)
    {
        std::swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

/* Removes the smallest element and fixes the order */
int minHeap::extractMin()
{
    // check if heap is empty
    if (size == 0)
    {
        std::cout << "Empty heap." << std::endl;
        return -1;
    }
    // check if there is 1 element
    else if (size == 1)
    {
        size--;
        return heap[0];
    }
    // regular extraction
    else
    {
        // store the root
        int root = heap[0];

        // maintain heap shape, then order
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        // return min element
        return root;
    }
}

/* Print heap in pretty format */
void minHeap::printHeap()
{
    int power = 0;
    int value = 1;

    for (int i = 0; i < size; i++)
    {
        if (i == value)
        {
            std::cout << std::endl;
            power++;
            value += (1 << power);
        }
        std::cout << heap[i] << "  ";
    }
    std::cout << std::endl;
}

int main(void)
{
    // srand(time(NULL));
    // number of elements for minHeap
    int N = 15;

    // declare heap with space for N elements
    minHeap heap(N);

    // Insert N random numbers
    for (int i = 0; i < N; i++)
    {
        std::cout << "Inserting element " << i + 1 << std::endl;
        heap.insert(rand() % 100);
        heap.printHeap();
        std::cout << std::endl;
    }

    int min = heap.extractMin();
    heap.printHeap();

    return EXIT_SUCCESS;
}