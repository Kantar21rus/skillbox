#include <iostream>
#include <vector>

struct room
{
    bool be = false;
    int square = 0;
};

struct floor
{
    room bedroom;
    room kitchen;
    room bathroom;
    room kidsroom;
    room livingroom;
    double height = 0;
    bool be = false;
    bool roomstatus[5] = {bedroom.be, kitchen.be, bathroom.be, kidsroom.be, livingroom.be};
};

struct livingHouse
{
    floor first, second, third;
    bool floorstatus[3] = { first.be, second.be, third.be};
    bool bake = false;
    bool be = true;
};

struct build
{
    std::string name;
    bool be =false;
    int square = 0;
};

struct area
{
    livingHouse home ;
    build bathhouse ;
    build garage ;
    build barn ;
    int areasquare;
    bool buildstatus[4] = {home.be, bathhouse.be, garage.be, barn.be};
};

int main()
{
    int countArea = 0;
    int allsquare = 0;
    int insert = 0;
    double insertf;
    std::string answer;
    std::cout << "How many areas in this village?\n";
    std::cin >> countArea;
    std::vector<area> areas(countArea);
    for (int i=0; i < countArea; ++i)
    {
        int floors = 0;
        int floorsq = 0;
        int housesq = 0;
        std::cout << "In area#" << i << ":\n";
        std::cout << "How many floor in house? ";
        std::cin >> floors;
        for (int j=0; j < floors; ++j)
        {
            areas[i].home.floorstatus[j] = true;
        }
        if (areas[i].home.floorstatus[0])
        {
            std::cout << "have 1 floor\n";
            std::cout << "what is the height of the floor\n";
            std::cin >> insertf;
            areas[i].home.first.height = insertf;
            std::cout << "--------what rooms are on this floor?---------\n";
            std::cout << "have bedroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.first.roomstatus[0] = true;
                areas[i].home.first.bedroom.square = insert;
                allsquare += insert;   
            }
            std::cout << "have kitchen? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.first.roomstatus[1] = true;
                areas[i].home.first.kitchen.square = insert;   
                allsquare += insert;
            }
            std::cout << "have bathroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.first.roomstatus[2] = true;
                areas[i].home.first.bathroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have kidsroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.first.roomstatus[3] = true;
                areas[i].home.first.kidsroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have livingroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.first.roomstatus[4] = true;
                areas[i].home.first.livingroom.square = insert;   
                allsquare += insert;
            }
        }
        if (areas[i].home.floorstatus[1])
        {
            std::cout << "have 2 floor\n";
            std::cout << "what is the height of the floor\n";
            std::cin >> insertf;
            areas[i].home.second.height = insertf;
            std::cout << "--------what rooms are on this floor?---------\n";
            std::cout << "have bedroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.second.roomstatus[0] = true;
                areas[i].home.second.bedroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have kitchen? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.second.roomstatus[1] = true;
                areas[i].home.second.kitchen.square = insert;   
                allsquare += insert;
            }
            std::cout << "have bathroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.second.roomstatus[2] = true;
                areas[i].home.second.bathroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have kidsroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.second.roomstatus[3] = true;
                areas[i].home.second.kidsroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have livingroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.second.roomstatus[4] = true;
                areas[i].home.second.livingroom.square = insert;   
                allsquare += insert;
            }
        }
        if (areas[i].home.floorstatus[2])
        {
            std::cout << "have 3 floor\n";
            std::cout << "what is the height of the floor\n";
            std::cin >> insertf;
            areas[i].home.third.height = insertf;
            std::cout << "--------what rooms are on this floor?---------\n";
            std::cout << "have bedroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.third.roomstatus[0] = true;
                areas[i].home.third.bedroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have kitchen? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.third.roomstatus[1] = true;
                areas[i].home.third.kitchen.square = insert;   
                allsquare += insert;
            }
            std::cout << "have bathroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.third.roomstatus[2] = true;
                areas[i].home.third.bathroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have kidsroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.third.roomstatus[3] = true;
                areas[i].home.third.kidsroom.square = insert;   
                allsquare += insert;
            }
            std::cout << "have livingroom? + or -\n";
            std::cin >> answer;
            if (answer == "+")
            {
                std::cout << "what square: ";
                std::cin >> insert;
                areas[i].home.third.roomstatus[4] = true;
                areas[i].home.third.livingroom.square = insert;   
                allsquare += insert;
            }
        }
        std::cout << "have bathhouse? + or - : ";
        std::cin >> answer;
        if (answer == "+")
        {
            areas[i].bathhouse.be = true;
            std::cout << "What square? ";
            std::cin >> areas[i].bathhouse.square;
            allsquare += areas[i].bathhouse.square;
        }
        std::cout << "have garage? + or - :";
        std::cin >> answer;
        if (answer == "+")
        {
            areas[i].garage.be = true;
            std::cout << "What square? ";
            std::cin >> areas[i].garage.square;
            allsquare += areas[i].garage.square;
        }
        std::cout << "have barn? + or - :";
        std::cin >> answer;
        if (answer == "+")
        {
            areas[i].barn.be = true;
            std::cout << "What square? ";
            std::cin >> areas[i].barn.square;
            allsquare += areas[i].barn.square;
        }
        std::cout << "----------------------------------------\n";
    }

    std::cout << "Total square " << allsquare << "\n";
}
