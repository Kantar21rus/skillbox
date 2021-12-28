#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>
#include <cstdlib>


std::mutex order;
std::mutex issuingOrder;
int orders = 0;
int issuingOrders = 0;
bool endProgram = false;

void waiter()
{
    int countOrders = 0;
    while(!endProgram)
    {
        int timeWait = std::rand()% 5 + 5;
        std::this_thread::sleep_for(std::chrono::seconds(timeWait));
        order.lock();
        orders++;
        countOrders++;
        std::cout << "Total orders accepted: " << countOrders << "\n";
        order.unlock();
    }
}

void kitchen(int *countDish)
{
    int totalCountDish = 0;
    int timeCook = 0;
    while(!endProgram)
    {
        order.lock();
        if (orders > 0)
        {
            orders--;
            order.unlock();
            timeCook = std::rand()% 10 + 5;
            std::this_thread::sleep_for(std::chrono::seconds(timeCook));
            issuingOrder.lock();
            (*countDish)++;
            totalCountDish++;
            std::cout << "Total count dish cooked: " << totalCountDish << "\n";
            issuingOrder.unlock();
        }
        else 
        {
            order.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
}

void courier(int *countDish)
{
    int tmp = 0;
    std::this_thread::sleep_for(std::chrono::seconds(30));
    while(!endProgram)
    {
        issuingOrder.lock();
        tmp = *countDish;
        *countDish = 0;
        issuingOrders += tmp;
        issuingOrder.unlock();
        std::cout << "Deliverd orders: " << issuingOrders << "\n";
        if (issuingOrders >= 10)
        {
            endProgram = true;
            return;
        }        
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
}


int main()
{
    int countDish = 0;
    std::srand(std::time(nullptr));
    std::thread waiterT(waiter);
    std::thread kitchenT(kitchen, &countDish);
    std::thread courierT(courier, &countDish);
    

    waiterT.join();
    kitchenT.join();
    courierT.join();
}

