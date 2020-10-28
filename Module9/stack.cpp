/**
 * Ari Yonaty
 */

#include <iostream>

class Stack
{
private:
    struct node
    {
        int data;
        node *next;

        node(int data, node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

public:
    node *stk_top; // pointer to first node in stack
    int stk_size;  // number of items in stack

    Stack(/* args */);
    ~Stack();

    int size();
    bool empty();
    void clear();
    int top();
    void push(int data);
    void pop();
    void display();
    void output();
};

Stack::Stack(/* args */)
{
    this->stk_top = nullptr;
    this->stk_size = 0;
}

Stack::~Stack()
{
    clear();
}

bool Stack::empty()
{
    return (stk_top == nullptr);
}

void Stack::clear()
{
    while (stk_top)
    {
        pop();
    }
}

void Stack::push(int data)
{
    stk_top = new node(data, stk_top);
    stk_size++;
}

void Stack::pop()
{
    if (stk_top == nullptr)
    {
        std::cerr << "Stack is empty." << std::endl;
        return;
    }

    node *tmp = stk_top;
    stk_top = stk_top->next;
    delete tmp;
    stk_size--;
}

void Stack::display()
{
    node *ptr = stk_top;

    std::cout << "*********** STACK ***********" << std::endl;

    while (ptr)
    {
        std::cout << "[+] " << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

void Stack::output()
{
    node *ptr = stk_top;
    while (ptr)
    {
        std::cout << ptr->data;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

int main(void)
{
    Stack myStack = Stack();

    int num, remainder;
    std::cout << "*******************************" << std::endl;
    std::cout << "****** Decimal to Binary ******" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cout << "Enter a decimal number: ";

    std::cin >> num;

    while (num > 0)
    {
        remainder = num % 2;
        num = num / 2;
        myStack.push(remainder);
    }

    std::cout << "Binary Equivalent: ";
    myStack.output();

    return 0;
}