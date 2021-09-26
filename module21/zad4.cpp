#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>


enum {maxy = 10, maxx = 40};

struct character
{
    int id;
    std::string name;
    int health;
    int armor;
    int damage;
    int posy, posx;
    int atcy, atcx;
    char symbol = 'E';
    bool alive = true;
};


void showfield(char (*field)[maxx])
{
    for (int k=0; k < 81; ++k)
        std::cout << "-";
    std::cout << "\n";
    for (int i=0; i < maxy; ++i)
    {
        std::cout << "|";
        for (int j=0; j < maxx; ++j)
        {
            std::cout << field[i][j] << "|";
        }
        std::cout << "\n";
        for (int k=0; k < 81; ++k)
            std::cout << "-";
        std::cout << "\n";
    
    }
}

void moving(character *pers, int direction)
{
    switch (direction) {
        case 0:
            {
                if (pers->posy != 0)
                    pers->posy -= 1;
                break;
            }
        case 1:
            {
                if (pers->posy != (maxy-1))
                   pers->posy += 1;
                break;
            }
        case 2:
            {
               if (pers->posx != 0)
                  pers->posx -= 1;
               break;
            }
        case 3:
            {
               if (pers->posx != (maxx -1))
                  pers->posx += 1;
            } 
    }
}

void attack(character *att, character *def)
{
    def->armor -= att->damage;
    if (def->armor < 0)
    {
        def->health += def->armor;
        def->armor = 0;
        if (def->health <= 0)
        {
            def->alive = false;
        }
    }
}

void attackPlayer(character *att, character *def, char (*field)[maxx])
{
    def->armor -= att->damage;
    if (def->armor < 0)
    {
        def->health += def->armor;
        def->armor = 0;
        if (def->health <= 0)
        {
            def->alive = false;
            field[def->posy][def->posx] = 'D';
        }
    }
}

void botmov(char (*field)[maxx], character *bot, character *player)
{
    int direction, tmpy, tmpx;
    direction = rand()%4;
    tmpy = bot->posy;
    tmpx = bot->posx;
    field[bot->posy][bot->posx] = ' ';
    moving(bot, direction);
    if (field[bot->posy][bot->posx] == 'P')
    {
        attack(bot, player);
        bot->posy = tmpy;
        bot->posx = tmpx;
    }
    else if (field[bot->posy][bot->posx] != ' ')
    {
        bot->posy = tmpy;
        bot->posx = tmpx;
    }
    field[bot->posy][bot->posx] = bot->symbol;
}

int playmov(char (*field)[maxx], character *player, int direction)
{
    int  tmpy, tmpx;
    tmpy = player->posy;
    tmpx = player->posx;
    moving(player, direction);
    if (field[player->posy][player->posx] == 'E')
    {
        player->atcy = player->posy;
        player->atcx = player->posx;
        player->posy = tmpy;
        player->posx = tmpx;
        return 1;
    }
    field[tmpy][tmpx] = ' ';
    field[player->posy][player->posx] = player->symbol;
    return 0;
}

bool findbot(int posy, int posx, character* bot)
{
    if ((posy == bot->posy) && (posx == bot->posx))
    {
        return true;
    }
    return false;
}

void save_char(std::ofstream& file, character& pers)
{
    int len = pers.name.length();
    file.write((char*)&len, sizeof(len));
    file.write(pers.name.c_str(), len);
    file.write((char*)&pers.health, sizeof(pers.health));
    file.write((char*)&pers.armor, sizeof(pers.armor));
    file.write((char*)&pers.damage, sizeof(pers.damage));
    file.write((char*)&pers.posy, sizeof(pers.posy));
    file.write((char*)&pers.posx, sizeof(pers.posx));
    file.write((char*)&pers.alive, sizeof(pers.alive));
    file.write((char*)&pers.symbol, sizeof(pers.symbol)); 
}

void load_char(std::ifstream& file, character& pers)
{
    int len;
    file.read((char*)&len, sizeof(len));
    pers.name.resize(len);
    file.read((char*)pers.name.c_str(), len);
    file.read((char*)&pers.health, sizeof(pers.health));
    file.read((char*)&pers.armor, sizeof(pers.armor));
    file.read((char*)&pers.damage, sizeof(pers.damage));
    file.read((char*)&pers.posy, sizeof(pers.posy));
    file.read((char*)&pers.posx, sizeof(pers.posx));
    file.read((char*)&pers.alive, sizeof(pers.alive));
    file.read((char*)&pers.symbol, sizeof(pers.symbol)); 
}

int main()
{
    //initializing the game field
    char field[maxy][maxx];
    for (int i=0; i < maxy; ++i)
    {
        for (int j=0; j < maxx; ++j)
        {
            field[i][j] = ' ';
        }
    }
    //initializing characters
    std::srand(std::time(nullptr));
    character enemy[5];
    for (int i=0; i < 5; ++i)
    {
        enemy[i].id = i;
        enemy[i].name = "Enemy #" + std::to_string(i);
        enemy[i].health = (std::rand() % 100) + 50;
        enemy[i].armor = std::rand() % 50;
        enemy[i].damage = (std::rand() % 15) + 15;
        enemy[i].posy = std::rand() % maxy;
        enemy[i].posx = std::rand() % maxx;
        field[enemy[i].posy][enemy[i].posx] = enemy[i].symbol;
    }
    character player;
    player.id = -1;
    std::cout << "Insert nickname: ";
    std::cin >> player.name;
    std::cout << "Insert health, armor and damage: ";
    std::cin >> player.health >> player.armor >> player.damage;
    player.symbol = 'P';
    player.posy = std::rand() % maxy;
    player.posx = std::rand() % maxx;
    field[player.posy][player.posx] = player.symbol;

    //game 
    bool game = true;
    int turnNumber = 0;
    showfield(field);
    while (game)
    {
        ++turnNumber;
        int enemyturn = 0;
        std::string action;
        std::cout << "\t\t\t\tTurn #" << turnNumber << "\n";
        std::cin >> action;
        if (action == "w")
        {
            if (playmov(field, &player, 0))
            {
                for(int i=0; i<5; ++i)
                {
                    if (findbot(player.atcy, player.atcx, &enemy[i]))
                        attackPlayer(&player, &enemy[i], field);
                }
            }
        }
        else if (action == "s")
        {
            if (playmov(field, &player, 1))
            {
                for(int i=0; i<5; ++i)
                {
                    if (findbot(player.atcy, player.atcx, &enemy[i]))
                        attackPlayer(&player, &enemy[i], field);
                }
            }
        }
        else if (action == "a")
        {
            if (playmov(field, &player, 2))
            {
                for(int i=0; i<5; ++i)
                {
                    if (findbot(player.atcy, player.atcx, &enemy[i]))
                        attackPlayer(&player, &enemy[i], field);
                }
            }
        }
        else if (action == "d")
        {
            if (playmov(field, &player, 3))
            {
                for(int i=0; i<5; ++i)
                {
                    if (findbot(player.atcy, player.atcx, &enemy[i]))
                        attackPlayer(&player, &enemy[i], field);
                }
            }
        }
        else if (action == "save")
        {
            std::ofstream file("save.bin", std::ios::binary);
            save_char(file, player);            
            for (int i=0; i<5; ++i)
                save_char(file, enemy[i]);
            file.close();
            continue;
        }
        else if (action == "load")
        {
            for (int i=0; i < maxy; ++i)
            {
                for (int j=0; j < maxx; ++j)
                {
                    field[i][j] = ' ';
                }
            }
            std::ifstream file("save.bin", std::ios::binary);
            load_char(file, player);            
            for (int i=0; i<5; ++i)
                load_char(file, enemy[i]);
            file.close();
            continue;
        }
        for (int i = 0; i < 5; ++i)
        {
            if (enemy[i].alive)
            {
                ++enemyturn;
                botmov(field, &enemy[i], &player);
            }
        }
        
        showfield(field);
        if (enemyturn == 0)
        {
            std::cout << "-------------------------YOU WIN!------------------------------\n";
            game = false;
        }
        if (!player.alive)
        {
            std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxYOU LOSE!xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            game = false;

        }
    }
}
