#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual double Area() = 0;
};

class Circle : public Shape
{
protected:
    double width;

public:
    Circle(double w)
    {
        width = w;
    }
    double Area() override
    {
        return 3.1414 * pow((width / 2), 2);
    }
};

struct Shape2
{
    double length, width;
    Shape2(double l = 1, double w = 1)
    {
        length = l;
        width = w;
    }
    double Area()
    {
        return length * width;
    }

private:
    int id;
};

struct Circle2 : Shape2
{
    Circle2(double width)
    {
        this->width = width;
    }
    double Area()
    {
        return 3.1414 * pow((width / 2), 2);
    }
};

void ShowArea(Shape &shape);

int main()
{
    Circle circle(10);
    ShowArea(circle);

    Circle2 circle2(10);
    std::cout << "Circle Area: " << circle2.Area() << std::endl;

    return 0;
}

void ShowArea(Shape &shape)
{
    std::cout << "Area : " << shape.Area() << std::endl;
}