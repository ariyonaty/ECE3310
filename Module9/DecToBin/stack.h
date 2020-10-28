#pragma once
#include <iostream>

class Stack
{
private:
    struct node
    {
        int data;
        node* next;

        node(int data, node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

public:
    node* stk_top;          // pointer to first node in stack
    int stk_size;           // number of items in stack

    Stack();
    ~Stack();

    bool empty();
    void clear();
    void push(int data);
    void pop();
    void display();         
    void output();          
};

/**
* Constructor
*/
Stack::Stack()
{
    this->stk_top = nullptr;
    this->stk_size = 0;
}

/**
* Deconstructor
*/
Stack::~Stack()
{
    clear();
}

/**
* Checks if stack is empty.
*   
* @return   bool - true if empty; false otherwise
*/
bool Stack::empty()
{
    return (stk_top == nullptr);
}

/**
* Empties the stack
*/
void Stack::clear()
{
    while (stk_top)
    {
        pop();
    }
}

/**
* Pushes data to top of stack.
* 
* @param    data 
*/
void Stack::push(int data)
{
    stk_top = new node(data, stk_top);
    stk_size++;
}

/**
* Pops data from top of stack
*/
void Stack::pop()
{
    if (stk_top == nullptr)
    {
        std::cerr << "Stack is empty." << std::endl;
        return;
    }

    node* tmp = stk_top;
    stk_top = stk_top->next;
    delete tmp;
    stk_size--;
}

/**
* General stack display function.
* Used for debugging purposes.
*/
void Stack::display()
{
    node* ptr = stk_top;

    std::cout << "*********** STACK ***********" << std::endl;

    while (ptr)
    {
        std::cout << "[+] " << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

/**
* Function for binary output
*/
void Stack::output()
{
    node* ptr = stk_top;
    while (ptr)
    {
        std::cout << ptr->data;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
