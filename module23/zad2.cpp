#include <iostream>

#define VAGON_COUNT 10
#define MAX_PASSENGERS 20

 

int main()
{
    int sum = 0;
    int passengers[VAGON_COUNT] = {0};
    for (int i=0; i < VAGON_COUNT; ++i)
    {
        std::cout << "Insert count passengers in vagon " << i << "\n";
        std::cin >> passengers[i];
        if (passengers[i] > MAX_PASSENGERS)
        {
            --i;
            std::cout << "Too many passengers in this vagon!\n";
        } else if (passengers[i] < 0)
        {
            std::cout << "Unbeliveble negative count passengers\n";
            --i;
        } else
        {
            sum += passengers[i];
        }
    }
    int temp;
    for (int i=0; i < VAGON_COUNT - 1; ++i)
    {
        for (int j=0; j < VAGON_COUNT - i -1; ++j)
        {
            if (passengers[j]>passengers[j+1])
            {
                temp = passengers[j];
                passengers[j] = passengers[j+1];
                passengers[j+1] = temp;
            }
        }
    }
    for (int i=VAGON_COUNT - 1; i >= 0; --i)
        std::cout << passengers[i] << "\n";
    std::cout << "All passengers " << sum << "\n";
}

