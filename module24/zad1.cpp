#include <iostream>
#include <ctime>
#include <iomanip>

struct task
{
    std::string name;
    std::time_t startTime;
    std::time_t finishTime;
    double timeSpend;
    bool work = false;
};

int main()
{
    struct task tasks[100];
    std::string input = "";
    for(int i=0 ;input != "exit";)
    {
        std::cin >> input;
        if (input == "begin")
        {
            if (i != 0 and tasks[i-1].work == true)
            {
                tasks[i-1].work = false;
                tasks[i-1].finishTime = std::time(nullptr);
                tasks[i-1].timeSpend = std::difftime(tasks[i-1].finishTime, tasks[i-1].startTime);
            }
            std::cout << "Insert task name: ";
            std::cin >> tasks[i].name;
            tasks[i].startTime = std::time(nullptr);
            tasks[i].work = true;
            ++i;
        }
        else if (input == "end")
        {
            if (tasks[i-1].work == true)
            {
                tasks[i-1].work = false;
                tasks[i-1].finishTime = std::time(nullptr);
                tasks[i-1].timeSpend = std::difftime(tasks[i-1].finishTime, tasks[i-1].startTime);
            }
        }
        else if (input == "status")
        {
            for (int j=0; j < i; ++j)
            {
                if (!tasks[j].work)
                    std::cout << tasks[j].name << " " << tasks[j].timeSpend << "\n";
                if (tasks[j].work)
                    std::cout << tasks[j].name <<  "\n";
            }
        }
    }
}
