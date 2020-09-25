#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
    double height;
    double width;

public:
    static int numOfShapes;

    Shape();
    Shape(double length);
    Shape(double height, double width);

    virtual ~Shape();

    void SetHeight(double height);
    double GetHeight();
    void SetWidth(double width);
    double GetWidth();
    static int GetNumOfShapes();

    virtual double Area();
};

#endif