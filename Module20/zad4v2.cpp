#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>

enum {countbill = 1000};

enum bill {onehungred = 100, twohungred = 200, fivehungred = 500, onethousand = 1000, twothousand = 2000, fivethousand = 5000};

void intToStr ( int number, char string[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        string[size-1-i] = number%10 + 48;
        number /=10;
    }
}

bool checkWithdrow(int money)
{
    if ( money%100 != 0)
        return false;
    return true;
}

int rdb (int fd)
{
    int rdbill;
    char buffer[4] = {0};
    read(fd, &buffer, 4);
    if (buffer[3] == '\n')
    {
        rdbill = 100 * (buffer[0] - 48);
    }
    else
    {
        rdbill = 1000 * ( buffer[0] - 48);
        lseek(fd, 1, SEEK_CUR);
    }
    return rdbill;
}

void readbill(int fd, int array[])
{   
    int rdbill;
    for (int i = 0; i < countbill; ++i)
    {
        char buffer[4] = {0};
        read(fd, &buffer, 4);
        if (buffer[3] == '\n')
        {
            rdbill = 100 * (buffer[0] - 48);
        }
        else
        {
            rdbill = 1000 * ( buffer[0] - 48);
            lseek(fd, 1, SEEK_CUR);
        }
        array[i] = rdbill;
    }
}

void writebill(int fd, int array[])
{
    char bill3[3] = {0};
    char bill4[4] = {0};
    char nl = '\n';
    for (int i = 0; i < (countbill); ++i)
    {
        if (array[i] >= 1000) 
        {
            intToStr(array[i], bill4, 4);
            write(fd, &bill4, sizeof(bill4));
            write(fd, &nl, sizeof(char));
            for (int j=0; j < 4 ; ++j)
                bill4[j] = 0;
        }
        else if (array[i] < 1000 && array[i] >0)
        {
            intToStr(array[i], bill3, 3);
            write(fd, &bill3, sizeof(bill3));
            write(fd, &nl, sizeof(char));
            for (int j=0; j < 3 ; ++j)
                bill3[j] = 0;
        }
    }
}

void parcingmoney(int money, int array[])
{
    if (money / 5000 > 0)
    {
        array[0] += money/5000;
        money %= 5000;
    }
    if (money / 2000 > 0)
    {
        array[1] += money/2000;
        money %= 2000;
    }
    if (money /1000 > 0)
    {
        array[2] += money/1000;
        money %= 1000;
    }
    if (money / 500 > 0)
    {
        array[3] += money/500;
        money %= 500;
    }
    if (money / 200 > 0)
    {
        array[4] += money/200;
        money %= 200;
    }
    if (money /100 > 0)
    {
        array[5] += money/100;
        money %= 100;
    }
}

void parcingATM(int denomination[], int billsInATM[])
{
    for (int i = 0; i < countbill; ++i)
    {
        switch (billsInATM[i]) 
        {
            case onehungred:
                {
                    ++denomination[5];
                    break;
                }
            case twohungred:
                {
                    ++denomination[4];
                    break;
                }
            case fivehungred:
                {
                    ++denomination[3];
                    break;
                }
            case onethousand:
                {
                    ++denomination[2];
                    break;
                }
            case twothousand:
                {
                    ++denomination[1];
                    break;
                }
            case fivethousand:
                {
                    ++denomination[0];
                    break;
                }
            case 0:
                {
                    break;
                }

        }
    }
}

bool checkdenom(int denomination[], int denominationtake[])
{
    for (int i=0; i<6; ++i)
    {
        if (denomination[i]-denominationtake[i] < 0)
            return false;
    }
    return true;
}

void takemoney(int billsInATM[], int denominationtake[], int bills[])
{
    for (int i=0; i < 6; ++i)
    {
        for(int j=0; j < denominationtake[i]; ++j)
        {
            for (int k=0; k < countbill; ++k)
            {
                if (billsInATM[k] == bills[i])
                {
                    billsInATM[k] = 0;
                    break;
                }
            }
        }
    }
}

int main()
{
    char mode[2];
    int fd;
    int bill;
    int bills[] = {5000, 2000, 1000, 500, 200, 100};
    int denomination[6] = {0};
    int billsInATM[countbill] = {0};
    char greetings[] = "If you collector insert '+'\nIf you want withdraw money insert '-'\n";
    write(1, &greetings, strlen(greetings));
    read(0, &mode, 2);
    if (mode[0] == '+')
    {
        std::srand(std::time(nullptr));
        fd = open("ATM2", (O_RDWR | O_CREAT | O_TRUNC), 0666);
        for (int i = 0 ; i < countbill; ++i)
        {
            bill = std::rand() % 6;
            billsInATM[i] = bills[bill];
        }
        writebill(fd, billsInATM);
        close(fd);
    }
    else if (mode[0] == '-')
    {
        fd = open("ATM2", O_RDWR);
        int money = 0;
        int denominationtake[6] = {0};
        readbill(fd, billsInATM);
        parcingATM(denomination, billsInATM);
        close(fd);
        fd = open("ATM2", (O_RDWR | O_CREAT | O_TRUNC), 0666);
        char withdraw[10] = {0}; 
        char howMoney[] = "How much money do you want to withdraw?\n";
        write(1, howMoney, strlen(howMoney));
        read(0, &withdraw, sizeof(withdraw));
        money = atoi(withdraw);
        parcingmoney(money, denominationtake);
        if (!checkWithdrow(money))
        {
            char errormes[] = "You can't withdrow this amount of money\n";
            write(1, errormes, strlen(errormes));
            return 1;
        }
        if (checkdenom(denomination, denominationtake))
        {
            takemoney(billsInATM, denominationtake, bills);
            writebill(fd, billsInATM);
        }
        else 
        {
            char errormes2[] = "ATM haven't need bills\n";
            write(1, errormes2, strlen(errormes2));
        }
        close(fd);
    }
}
