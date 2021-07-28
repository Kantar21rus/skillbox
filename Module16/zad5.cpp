#include <iostream>
#include <string>
#include <sstream>

enum shield 
{
    HOUSE = 1,
    OUTLETS = 2,
    LIGHTS_IN = 4,
    LIGHTS_OUT = 8,
    HEAT_HOUSE = 16,
    HEAT_WATER = 32,
    CONDITIONER = 64
};

enum constants 
{
    TEMP_OUT_ON = 0,
    TEMP_OUT_OFF = 5,
    TEMP_IN_HEAT_ON = 22,
    TEMP_IN_COOL_ON = 30,
    TEMP_IN_OFF = 25,
};

int main() {
    int tempOut;
    int tempIn;
    std::string lightOut;
    std::string lightIn;
    int time = 0;
    int brightness[] = {5000, 5000, 5000, 5000, 5000, 5000, 
                        5000, 5000, 5000, 5000, 5000, 5000, 
                        5000, 5000, 5000, 5000, 5000, 4400,
                        3800, 3200, 2700, 2700, 2700, 2700};
    int state = 0;
    for (int i=0; i < 48; ++i) 
    {
        if (i < 24) 
            time = i;
        else 
            time = i - 24;

        std::string input;
        std::stringstream buf, bufout;
        std::getline(std::cin, input);
        buf << input;
        buf >> tempOut >> tempIn >> lightOut >> lightIn;
        bufout << "Time: " << time << ".00\t";
        if (tempOut < TEMP_OUT_ON and !(state & HEAT_WATER))
        {
            state |= HEAT_WATER;
            bufout << "Heat water ON\t";
        }
        else if (tempOut > TEMP_OUT_OFF and (state & HEAT_WATER))
        {
            state &= ~HEAT_WATER;
            bufout << "Heat water OFF\t";
        }
        if (tempIn < TEMP_IN_HEAT_ON and !(state & HEAT_HOUSE))
        {
            state |= HEAT_HOUSE;
            bufout << "Heat house ON\t";
        }
        else if (tempIn >= TEMP_IN_OFF and (state & HEAT_HOUSE))
        {
            state &= ~HEAT_HOUSE;
            bufout << "Heat house OFF\t";
        }
        if (tempIn >= TEMP_IN_COOL_ON and !(state & CONDITIONER))
        {
            state |= CONDITIONER;
            bufout << "Conditioner ON\t";
        }
        else if (tempIn <= TEMP_IN_OFF and (state & CONDITIONER))
        {
            state &= ~CONDITIONER;
            bufout << "Conditioner OFF\t";
        }
        if (lightOut == "yes" and !(state & LIGHTS_OUT) and (time >= 16 or time < 5))
        {
            state |= LIGHTS_OUT;
            bufout << "Lights outside ON\t";
        }
        else if (lightOut == "no" and (state & LIGHTS_OUT))
        {
            state &= ~LIGHTS_OUT;
            bufout << "Lights outside OFF\t";
        }
        else if ( (state & LIGHTS_OUT) and ( time >= 5 and time < 16))
        {
            state &= ~LIGHTS_OUT;
            bufout << "Lights outside OFF\t";
        }
        if (lightIn == "on" and !(state & LIGHTS_IN) )
        {
            state |= LIGHTS_IN;
            bufout << "Lights in house ON\t";
        }
        else if (lightIn == "off" and (state & LIGHTS_IN))
        {
            state &= ~LIGHTS_IN;
            bufout << "Lights in house OFF\t";
        }
        if (state & LIGHTS_IN)
            bufout << "brightness " << brightness[time] <<"K\t";

        std::cout << bufout.str() << "\n";
    }
}   
