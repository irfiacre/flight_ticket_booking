#include <stdio.h>

int generate_random_nbr(int ranger)
{
    int lower = 1, upper = 700, count = 1;
    srand(time(0));
    return ranger + ((rand() % (upper - lower + 1)) + lower);
}

void load_default_users()
{
    FILE *users_file;
    users_file = fopen("data/users_database.txt", "w");
    fprintf(users_file, "%d\t%s\t%s\t%s\t%s\t%d\n", 100000, "Default", "Admin", "dadmin", "Kanombe", 1);
    fprintf(users_file, "%d\t%s\t%s\t%s\t%s\t%d\n", 100001, "Default", "User", "duser", "Bugesera", 0);
    fclose(users_file);
}