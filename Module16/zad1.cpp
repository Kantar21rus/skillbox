#include <iostream>
#include <cstdio>


int main() {
    double speed = 0;
    double delta;
    do 
    {
        printf("Input speed delta: ");
        scanf("%lf", &delta);
        speed += delta;
        printf("Current speed: %.1lf \n", speed);
        if (speed < -0.01) 
        {
            printf("Speed wasn't negativ, and so you've stoped\n");
            return 0;
        }
        else if ( speed > 150) 
        {
            printf("Too Fast, please slow down!\n");
        }
    } while (!(speed > (-0.01) and speed < 0.01));

}
