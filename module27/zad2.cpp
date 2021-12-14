#include <iostream>
#include <cmath>

class Figur
{
    public:
        double corX = 0;
        double corY = 0;
        std::string color = "None";

};

class Circle: public Figur
{

    double radius = 0;
    public:
    
    Circle()
    {
        std::cout << "Insert start coordinats X and Y:\n";
        std::cin >> corX >> corY;
        std::cout << "Insert radius: ";
        std::cin >> radius;
    }
    
    void calculateSquare()
    {
        std::cout << "Circle square: " << 3.14 * radius * radius << "\n";
    }

    void describingRectangle()
    {
        std::cout << "Describing rectangle, hight: " << radius*2 << ", width: " << radius*2 << "\n";
    }
};

class Square: public Figur
{
    double edge = 0;

    public:

    Square()
    {
        std::cout << "Insert start coordinats X and Y:\n";
        std::cin >> corX >> corY;
        std::cout << "Insert edge: ";
        std::cin >> edge;
    }

    void calculateSquare()
    {
        std::cout << "Square area: " << edge * edge << "\n";
    }

    void describingRectangle()
    {
        std::cout << "Describing rectangle, hight: " << edge << ", width: " << edge << "\n";
    }
};

class Triangle: public Figur
{
    double edge = 0;
    public:

    Triangle()
    {
        std::cout << "Insert start coordinats X and Y:\n";
        std::cin >> corX >> corY;
        std::cout << "Insert edge: ";
        std::cin >> edge;
    }

    void calculateSquare()
    {
        std::cout << "Triangle area: " << (std::sqrt(3) * 0.25 * edge * edge) << "\n";
    }

    void describingRectangle()
    {
        std::cout << "Describing rectangle, hight: " << (edge * sqrt(3) * 0.5) << ", width: " << edge << "\n";
    }
}; 

class Rectangle: public Figur
{
    double hight = 0;
    double width = 0;
    public:

    Rectangle()
    {
        std::cout << "Insert start coordinats X and Y:\n";
        std::cin >> corX >> corY;
        std::cout << "Insert hight and width: ";
        std::cin >> hight >> width;
    }

    void calculateSquare()
    {
        std::cout << "Rectangle area: " << (hight * width) << "\n";
    }

    void describingRectangle()
    {
        std::cout << "Describing rectangle, hight: " << hight << ", width: " << width << "\n";
    }
};


int main()
{
    std::string comand = "";
    std::cout << "Insert figure:\n";
    while (comand != "exit")
    {
        std::cin >> comand;
        if (comand == "circle")
        {
            Circle myCircle;
            myCircle.calculateSquare();
            myCircle.describingRectangle();
        }
        else if (comand == "square")
        {
            Square mySquare;
            mySquare.calculateSquare();
            mySquare.describingRectangle();
        }
        else if (comand == "triangle")
        {
            Triangle myTriangle;
            myTriangle.calculateSquare();
            myTriangle.describingRectangle();
        }
        else if (comand == "rectangle")
        {
            Rectangle myRectangle;
            myRectangle.calculateSquare();
            myRectangle.describingRectangle();
        } 
    }
}
