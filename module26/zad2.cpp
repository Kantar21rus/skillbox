#include <iostream>
#include <stdio.h>
#include <string>

class PhoneNumber
{    
    std::string number;
    std::string name;

    std::string correctNumber()
    {
        std::string num;
        std::cin >> num;
        if (num.length() == 12 && num[0] == '+' && num[1] == '7' )
        {
            return num;
        }
        else 
        {
            std::cout << "Wrong number!\n";
            num = correctNumber();
        }
        return num;
    }

    public:
    /*
    PhoneNumber(std::string a_name)
    {
       number = setNumber();
       name = a_name;
    } 
*/

    void setNumber()
    {
        std::cout << "Insert number in format: +7??????????\n";
        number = correctNumber();
    }

    void setName()
    {
        std::cout << "Insert contact name: ";
        std::cin >> name;
    }

    std::string getNumber()
    {
       //std::cout << number ;
       return number;
    }

    std::string getName()
    {
        return name;
    }
};

class AddresBook
{
    PhoneNumber adBook[100];
    int countNumber = 0;
    
    public:

    void addPhone()
    {
        adBook[countNumber].setName();
        adBook[countNumber].setNumber();
        ++countNumber;
    }
/*
    void showContact()
    {
        adBook[0].getName();
        adBook[0].getNumber();
    }
*/
    void call(std::string contactName)
    {
        for (int i = 0; i < countNumber; ++i)
        {
            if (contactName == adBook[i].getName())
            {
                std::cout << "CALL " << adBook[i].getNumber() << "\n";
                return;
            }
        }
        std::cout << "Haven't contact with this name\n";
    }

    void callNumber(std::string contactNumber)
    {
        std::cout << "CALL " << contactNumber << "\n";
    }

    void sms(std::string input)
    {
        std::string message = "";
        if (input[0] == '+' && input[1] == '7')
        {
            std::cout << "Insert message for number: " << input << "\n";
            std::cin >> message;
            return;
        }
        else
        {
            for (int i=0; i<countNumber; ++i)
            {
                if (input == adBook[i].getName())
                {
                    std::cout << "Insert message for contact " << adBook[i].getName() << "\n";
                    std::cin >> message;
                    return;
                }
            }
            std::cout << "Haven't contact with this name\n";
        }
    }
};

int main()
{
    AddresBook myBook;
    std::string comand = "";

    for (;comand != "exit";)
    {
        std::cin >> comand;
        if (comand == "add")
        {
            myBook.addPhone();
        }
        else if (comand == "call")
        {
            std::string answer;
            std::cout << "Insert name or number to call: ";
            std::cin >> answer;
            if (answer[0] == '+' && answer[1] == '7')
            {
                myBook.callNumber(answer);
            }
            else
            {
                myBook.call(answer);
            }
        }
        else if (comand == "sms")
        {
            std::string answer;
            std::cout << "Insert name or number to send SMS: ";
            std::cin >> answer;
            myBook.sms(answer);
        }
    }
}
