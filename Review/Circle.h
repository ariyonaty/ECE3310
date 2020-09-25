#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{
public:
    Circle();
    Circle(double width);
    virtual ~Circle();
    double Area();
};

#endif