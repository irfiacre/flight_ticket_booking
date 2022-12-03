#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "auth.h"

FILE *users_file;

struct User authorization()
{
    int choice;
    char user_name[60];
    printf("\nChoose \n1. Sign in \n2. Register\n0. Exit \nEnter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter username: ");
        scanf("%s", user_name);
        users_file = fopen("data/users_database.txt", "r");
        int username_found = 0;
        while (!feof(users_file) && username_found == 0)
        {
            fscanf(users_file, "%d\t%s\t%s\t%s\t%d\n", &user.user_id, user.name, user.username, user.city, &user.is_admin);
            if (strcmp(user.username, user_name) == 0)
            {
                username_found = 1;
                break;
            }
        }
        fclose(users_file);

        if (username_found == 1)
        {
            printf("\n ✅ Successful Login \n");
            return user;
        }
        else
        {
            printf("\nWe do not have a user with username: %s \n", user_name);
            authorization();
        }

        break;
    case 2:
        users_file = fopen("data/users_database.txt", "a");
        printf("Enter Your Name: ");
        scanf("%s", user.name);
        printf("Choose username: ");
        scanf("%s", user.username);
        printf("Enter Your city: ");
        scanf("%s", user.city);
        user.user_id = generate_random_nbr(100000);
        user.is_admin = 0;
        fprintf(users_file, "%d\t%s\t%s\t%s\t%d\n", user.user_id, user.name, user.username, user.city, user.is_admin);
        fclose(users_file);
        printf("\n User successfully Registered ✅ \n");
        authorization();
        break;
    case 0:
        printf("\n ============ We are sad to see you go ============ \n");
        exit(0);
        break;
    default:
        printf("\n Invalid choice\n");
        authorization();
        break;
    }

    return user;
}
