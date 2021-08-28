#include <iostream>
#include <fstream>
#include <sstream>

void readQ (int pos)
{
    char buffer1[10];
    std::stringstream helper;
    std::stringstream output;
    std::string directory;
    helper << "questions/q" << pos << ".txt";
    helper >> directory; 
    std::ifstream file;
    file.open(directory, std::ios::binary);
    while(!file.eof())
    {
         file.read(buffer1, sizeof(buffer1));
         for (int i=0; i<10 and buffer1[i]!='\0'; ++i)
         {
            if (buffer1[i] != EOF)
            {
                output << buffer1[i];
            }
            else if (buffer1[i] == EOF)
            {
                output << '\n' << '\0';
                break;
            }
            buffer1[i] = '\0';
         }
    }
    file.close();
    std::cout << output.str();
}

bool readA (int pos)
{
    std::string answer = "";
    std::string rightAnswer = "";
    std::cout << "Please, insert the answer in one word, it is allowed to use lowercase letters and numbers:\n";
    std::cin >> answer;
    std::stringstream helper;
    std::string directory;
    helper << "answers/a" << pos << ".txt";
    helper >> directory; 
    std::ifstream file;
    file.open(directory);
    if (file.is_open())
    {
        file >> rightAnswer;
        file.close();
        if (rightAnswer == answer)
        {
            std::cout << "Currect Answer! Score goes to the Experts!\n";
            return true;
        }
        std::cout << "Wronge Answer! Score goes to the viewer!\nCurrent answer: " << rightAnswer << "\n";
    }
    else
        std::cout << "File not open\n";
    return false;
}

void callfunc(int pos, int* scZ, int* scW, bool openQA[])
{
    openQA[pos-1] = true;
    for (int i=0; i<13; ++i)
        std::cout << openQA[i] << " " ;
    std::cout << "\n";
    readQ(pos);
    (readA(pos) ? ++(*scZ) : ++(*scW));
    std::cout << "It was questions: " << pos << "\nExperts score: " << *scZ << "\nViewer score: " << *scW << "\n";
}


int main()
{
    int scoreZnat = 0;
    int scoreWatch = 0;
    int position = 1;
    bool haveWinner = false;
    int offset = 0;
    bool openQA[13];
    for (int i=0; i < 13; ++i)
        openQA[i] = false;

    std::cout << "Game start /// start position on Question 1\n";
    callfunc(position, &scoreZnat, &scoreWatch, openQA);

    for (int i = 0; i < 12 && !haveWinner; ++i)
    {
        std::cout << "Input offset: ";
        std::cin >> offset;
        position = (position + offset) % 13;
        if (position == 0)
            position = 13;
        while (openQA[position-1])
        {
            ++position;
            if (position == 14)
                position = 1;
        }
        callfunc(position, &scoreZnat, &scoreWatch, openQA);
        if (scoreZnat == 6)
        {
            std::cout << "And Experts win this game!!!\n";
            haveWinner = true;
        }
        if (scoreWatch == 6)
        {
            std::cout << "And Viewers win this game!!!\n";
            haveWinner = true;
        }
    }
  }
