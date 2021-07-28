#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main() {
    char integers[100];
    char fractionals[100];
    int integeri;
    double fractionald;
    int size;
    printf("Input integer part: ");
    scanf("%s", integers);
    printf("Input fraction part: ");
    scanf("%s", fractionals);
    size = strlen(fractionals);
    integeri = atoi(integers);
    fractionald = atof(fractionals)/(std::pow(10,size));
    fractionald +=integeri;
    printf("%lf \n", fractionald);
}

