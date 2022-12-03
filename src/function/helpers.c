#include<stdio.h>

int generate_random_nbr(int ranger)
{
    int lower = 1, upper = 700, count = 1;
    srand(time(0));
    return ranger + ((rand() % (upper - lower + 1)) + lower);
}
