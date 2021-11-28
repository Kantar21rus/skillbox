#include <iostream>

enum {sizeWidth = 80,
    sizeHigth = 50};

class Display
{
    char window[sizeHigth][sizeWidth];
    
    int corH = 0;
    int corW = 0;

    int hight = 10;
    int width = 10;

    public:

    void setZero()
    {
        for (int i=0; i < sizeHigth; ++i)
        {
            for (int j=0; j< sizeWidth; ++j)
            {
                window[i][j] = '0';
            }
        }
    }

    void setOne()
    {
        for (int i=corH; i < (corH + hight); ++i)
        {
            for (int j=corW; j < (corW + width); ++j)
            {
                window[i][j] = '1';
            }
        }
    }
    
    void show()
    {
        for (int i=0; i < sizeHigth; ++i)
        {
            for (int j=0; j< sizeWidth; ++j)
            {
                std::cout << window[i][j];
            }
            std::cout << "\n";
        }
    }

    void resize()
    {
        std::cout << "Insert new hight and width\n";
        std::cin >> hight >> width;
        if (hight <= 0)
            hight = 1;
        if (hight > sizeHigth)
            hight = sizeHigth;
        if (width <= 0)
            width = 1;
        if (width > sizeWidth)
            width = sizeWidth;
    }
    
    void move()
    {
        int vecH, vecW;
        std::cout << "Insert how move window:\n";
        std::cin >> vecH >>vecW;
        corH += vecH;
        if (corH < 0)
            corH = 0;
        if (corH > sizeHigth)
            corH = (sizeHigth - 1);
        corW += vecW;
        if (corW < 0)
            corW = 0;
        if (corW > sizeWidth)
            corW = (sizeWidth - 1);
    }

};

int main()
{
    std::string comand = "";

    Display myDisplay;
    myDisplay.setZero();
    myDisplay.setOne();
    myDisplay.show();

    for (;comand != "close";)
    {
        std::cin >> comand;
        if (comand == "move")
        {
            myDisplay.move();
        }
        else if (comand == "resize")
        {
            myDisplay.resize();
            myDisplay.setZero();
            myDisplay.setOne();
            myDisplay.show();
        }
        else if (comand == "display")
        {
            myDisplay.setZero();
            myDisplay.setOne();
            myDisplay.show();
        }
    }
}
