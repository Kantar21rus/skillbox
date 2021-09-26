#include <iostream>
#include <cmath>

struct vec
{
    double xs;
    double ys;
    double xf;
    double yf;
};

void add(vec* first, vec* second, vec* res)
{
    if ((second->xs != first->xf) || (second->ys != first->yf))
    {
        int x, y;
        x = second->xs - first->xf;
        y = second->ys - first->yf;
        second->xs = first->xf;
        second->ys = first->yf;
        second->xf -= x;
        second->yf -= y;
    }
    res->xs = first->xs;
    res->ys = first->ys;
    res->xf = second->xf;
    res->yf = second->yf;
    std::cout << "Result vector, x y:\n" << res->xs << " " << res->ys << "\n" << res->xf << " " << res->yf << "\n";
}

void subtract(vec* first, vec* second, vec* res)
{
    if ((second->xs != first->xs) || (second->ys != first->ys))
    {
        int x, y;
        x = second->xs - first->xs;
        y = second->ys - first->ys;
        second->xs = first->xs;
        second->ys = first->ys;
        second->xf -= x;
        second->yf -= y;
    }
    res->xs = first->xf;
    res->ys = first->yf;
    res->xf = second->xf;
    res->yf = second->yf;
    std::cout << "Result vector, x y:\n" << res->xs << " " << res->ys << "\n" << res->xf << " " << res->yf << "\n";
}

double length(vec* first)
{
    double len;
    len = std::sqrt(std::pow((first->xf - first->xs), 2) + std::pow((first->yf - first->ys), 2));
    return len;
}

double scale(vec* first, vec* second)
{
    double a, b, alfa;
    a = length(first);
    b = length(second);
    int x, y;
    x = second->xs - first->xs;
    y = second->ys - first->ys;
    second->xs = first->xs;
    second->ys = first->ys;
    second->xf -= x;
    second->yf -= y;
    if ((first->xf) == (second->xf))
            alfa = a/b;
    else if ((first->xf) > (second->xf))
    {
        first->yf = ((second->xf-first->xs)/(first->xf - first->xs)) * (first->yf-first->ys)+first->ys;
        first->xf = second->xf;
        alfa = (length(first)/length(second));
    }
    else if ((first->xf) < (second->xf))
    {
        second->yf = ((first->xf-second->xs)/(second->xf - second->xs)) * (second->yf-second->ys)+second->ys;
        second->xf = first->xf;
        alfa = (length(first)/length(second));
    }
    return (a*b*alfa);
}

void normalize(vec* first, vec* res)
{
    first->xf -= first->xs;
    first->yf -= first->ys;
    first->xs = 0;
    first->ys = 0;
    res->xf = (first->xf/length(first));
    res->yf = (first->yf/length(first));
    std::cout << "Result vector, x y:\n" << res->xs << " " << res->ys << "\n" << res->xf << " " << res->yf << "\n";
}

int main()
{
    int insert;
    std::cout << "what do you want to do?\n";
    std::cout << "1) add\n";
    std::cout << "2) subtract\n";
    std::cout << "3) scale\n";
    std::cout << "4) length\n";
    std::cout << "5) normalize\n";
    std::cout << "Insert action number: ";
    std::cin >> insert;
    struct vec vecA, vecB;
    struct vec vecRes = {0, 0, 0, 0};
    std::cout << "Insert coordinats for vecA, start x,y and finish x,y: ";
    std::cin >> vecA.xs >> vecA.ys >> vecA.xf >> vecA.yf;
    switch (insert) {
        case 1:
            {
                std::cout << "Insert coordinats for vecB, start x,y and finish x,y: ";
                std::cin >> vecB.xs >> vecB.ys >> vecB.xf >> vecB.yf;
                add(&vecA, &vecB, &vecRes);
                break;
            }
        case 2:
            {
                std::cout << "Insert coordinats for vecB, start x,y and finish x,y: ";
                std::cin >> vecB.xs >> vecB.ys >> vecB.xf >> vecB.yf;
                subtract(&vecA, &vecB, &vecRes);
                break;
            }
        case 3:
            {
                std::cout << "Insert coordinats for vecB, start x,y and finish x,y: ";
                std::cin >> vecB.xs >> vecB.ys >> vecB.xf >> vecB.yf;
                std::cout << scale(&vecA, &vecB) << "\n";
                break;
            }
        case 4:
            {
                std::cout << length(&vecA) << "\n";
                break;
            }
        case 5:
            {
                normalize(&vecA, &vecRes);
            }
    }
}

