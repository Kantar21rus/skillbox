#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>


class Music
{
    std::time_t duration;
    std::time_t timeCreat;

    void showDateCreat()
    {
        std::tm* creatTime;
        creatTime = std::localtime(&timeCreat);
        std::cout << std::asctime(creatTime);
    } 

    public:

    std::string songName;
    int id;

    bool play(bool whatPlay[])
    {
        if (!whatPlay[id])
        {
            for(int i=0; i < 5; ++i)
                whatPlay[i] = false;
            whatPlay[id] = true;
            std::tm* creatTime;
            creatTime = std::localtime(&timeCreat);
            std::cout << "Song: " << songName << "\nSong was creat on you device: " << std::put_time(creatTime, "%Y:%m:%d")  << "\nTime duration: " << duration << " sec\n";
            return true;
        }
        return false;
    }

    void setSongName()
    {
        std::cin >> songName;
    }

    void setDate()
    {
        timeCreat = std::time(nullptr);
    }

    void setDuration()
    {
        std::cin >> duration;
    }
};

int main()
{
    bool whatPlay[5] = {false};
    bool songPlay = false;
    bool songPause = false;
    bool songStop = false;
    std::srand(std::time(nullptr));
    std::string comand = "";
    Music song[5];
    for (int i=0; i < 5; i++)
    {
        song[i].id = i;
        song[i].setSongName();
        song[i].setDate();
        song[i].setDuration();
        std::cout << "song " << i << " insert\n";
    }
    std::cout << "Player start work!\n";
    for(;comand != "exit";)
    {
        comand = "";
        std::cin >> comand;
        if (comand == "play")
        {
            std::string findSong;
            std::cout << "Insert song name: ";
            std::cin >> findSong;
            for (int i=0; i < 5; ++i)
            {
                if (song[i].songName == findSong)
                {
                    song[i].play(whatPlay);
                    songPlay = true;
                    songPause = false;
                    songStop = false;
                }
            }
        }
        else if (comand == "pause")
        {
            if (songPlay && !songPause)
            {
                songPlay = false;
                songPause = true;
                songStop = false;
                std::cout << "The song is paused\n";
            }

        }
        else if (comand == "next")
        {
            int i = (std::rand()%5);
            std::cout << "rand " << i << "\n";
            song[i].play(whatPlay);
            songPlay = true;
            songPause = false;
            songStop = false;
        }
        else if (comand == "stop")
        {
            if (songPlay && !songStop)
            {
                songPlay = false;
                songStop = true;
                songPause = false;
                std::cout << "The song is stoped\n";
            }
        }        
    }
}
