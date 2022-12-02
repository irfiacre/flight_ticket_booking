#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct FlightTicket
{
    int id;
    int user_id;
    char traveler_name[200];
    char origin[200];
    char destination[200];
    int flight_type;
    char note[100];
};
struct User
{
    int user_id;
    char name[200];
    char username[60];
    char city[200];
    int is_admin;
} user;

int generate_id(int ranger)
{
    int lower = 1, upper = 700, count = 1;
    srand(time(0));
    return ranger + ((rand() % (upper - lower + 1)) + lower);
}

void book_flight_ticket()
{
    struct FlightTicket ft;
    FILE *ptr;
    ptr = fopen("../src/database.txt", "a");
    ft.id = generate_id(9000000);
    ft.user_id = user.user_id;
    strcpy(ft.traveler_name, user.name);
    strcpy(ft.origin, user.city);
    printf("\nEnter Destination: ");
    scanf("%s", ft.destination);
    printf("\nChoose Flight Type ( 1.Business 2.Economic ) \nEnter choice: ");
    scanf("%d", &ft.flight_type);
    printf("\nAnything we should be aware of: ");
    scanf("%s", ft.note);
    fprintf(
        ptr,
        "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
        ft.id, ft.user_id, ft.traveler_name, ft.origin, ft.destination, ft.flight_type, ft.note);
    fclose(ptr);
    printf("\n ✅ Flick Ticket Booked \n");
};

void display_flight_tickets()
{
    struct FlightTicket display_ft;
    FILE *p;
    p = fopen("database.txt", "r");
    printf("\nID\tName\tOrigin\tDestination\tType\tNote\n==\t=====\t=======\t==========\t======\t========\n");
    while (!feof(p))
    {
        fscanf(
            p,
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            &display_ft.id, &display_ft.user_id, display_ft.traveler_name, display_ft.origin, display_ft.destination, &display_ft.flight_type, display_ft.note);
        if (user.user_id == display_ft.user_id && user.is_admin == 0)
        {
            printf(
                "%d\t%s\t%s\t%s\t%d\t%s\n",
                display_ft.id,
                display_ft.traveler_name,
                display_ft.origin,
                display_ft.destination,
                display_ft.flight_type,
                display_ft.note);
        }
        else if (user.is_admin == 1)
        {
            printf(
                "%d\t%s\t%s\t%s\t%d\t%s\n",
                display_ft.id,
                display_ft.traveler_name,
                display_ft.origin,
                display_ft.destination,
                display_ft.flight_type,
                display_ft.note);
        }
        }
    fclose(p);
};

void search_flight_ticket()
{
    struct FlightTicket searched_ft;
    int ft_id;
    FILE *p;
    p = fopen("database.txt", "r");
    printf("Enter Flight Ticket ID: ");
    scanf("%d", &ft_id);
    while (!feof(p))
    {
        fscanf(
            p,
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            &searched_ft.id, &searched_ft.user_id, searched_ft.traveler_name, searched_ft.origin, searched_ft.destination, &searched_ft.flight_type, searched_ft.note);
        if (ft_id == searched_ft.id)
        {
            printf("\nID\tUser's Name\tOrigin\tDestination\tType\tNote\n==\t=============\t=======\t==========\t======\t========\n");
            printf(
                "%d\t%s\t%s\t%s\t%d\t%s\n",
                searched_ft.id,
                searched_ft.traveler_name,
                searched_ft.origin,
                searched_ft.destination,
                searched_ft.flight_type,
                searched_ft.note
            );
            break;
        }
    }
    fclose(p);
};

void sort_flight_tickets()
{
    struct FlightTicket ft, temp_ft, ft_array[100];
    int sort_id, k = 0;
    FILE *p;
    p = fopen("database.txt", "r");
    while (!feof(p))
    {
        fscanf(
            p,
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            &ft.id, &ft.user_id, ft.traveler_name, ft.origin, ft.destination, &ft.flight_type, ft.note);
        ft_array[k] = ft;
        k = k + 1;
    }
    fclose(p);

    printf("Sort By: \n1.Id\t2.Type \nEnter choice: ");
    scanf("%d", &sort_id);
    for (int i = 0; i < k; i++)
    {
        int j = i; // Initiating j to compare the current value to values before it
        if (sort_id == 1)
        {
            // Sorting by ID
            while (j > 0 && ft_array[j - 1].id > ft_array[j].id)
            {
                temp_ft = ft_array[j - 1];
                ft_array[j - 1] = ft_array[j];
                ft_array[j] = temp_ft;
                j = j - 1;
            }
        }
        else
        {
            // Sorting by Type
            while (j > 0 && ft_array[j - 1].flight_type > ft_array[j].flight_type)
            {
                temp_ft = ft_array[j - 1];
                ft_array[j - 1] = ft_array[j];
                ft_array[j] = temp_ft;
                j = j - 1;
            }
        }
    }
    p = fopen("sorted_database.txt", "w");
    for (int i = 0; i < k; i++)
    {
        fprintf(
            p,
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            ft_array[i].id,
            ft_array[i].user_id,
            ft_array[i].traveler_name,
            ft_array[i].origin,
            ft_array[i].destination,
            ft_array[i].flight_type,
            ft_array[i].note);
    }
    fclose(p);
};

struct User authorization()
{
    int choice;
    char user_name[60];
    printf("Choose \n1. Sign in \n2. Register\n0. Exit \nEnter choice: ");
    scanf("%d", &choice);
    FILE *users_file;
    switch (choice)
    {
    case 1:
        printf("Enter username: ");
        scanf("%s", user_name);
        users_file = fopen("../src/users_database.txt", "r");
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
            printf("We do not have a user with username %s", user_name);
            authorization();
        }

        break;
    case 2:
        users_file = fopen("../src/users_database.txt", "a");
        printf("Enter Your Name: ");
        scanf("%s", user.name);
        printf("Choose username: ");
        scanf("%s", user.username);
        printf("Enter Your city: ");
        scanf("%s", user.city);
        user.user_id = generate_id(100000);
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

int main()
{
    int oper;
    printf("Welcome to my Auka Flights management \n");
    struct User current_user = authorization();
    do
    {
        if (current_user.is_admin == 0)
        {
            printf("\n \tMain Menu\n|---------------------------|\n");
            printf("1. Book Flight Ticket \n");
            printf("2. View Flight Tickets\n");
            printf("0. Exit\n");
            printf("\nChoose::: ");
            scanf("%d", &oper);
            switch (oper)
            {
            case 1:
                book_flight_ticket();
                break;
            case 2:
                display_flight_tickets();
                break;
            case 0:
                printf("\n ============ We are sad to see you go ============ \n");
                break;
            default:
                printf("\n Wrong choice\n");
            }
        }
        else
        {
            printf("\n \tMain Menu\n|---------------------------|\n");
            printf("1. View Flight Tickets\n");
            printf("2. Search Flight Ticket\n");
            printf("3. Sort List of Flight Tickets \n");
            printf("0. Exit\n");
            printf("\nChoose::: ");
            scanf("%d", &oper);

            switch (oper)
            {
            case 1:
                display_flight_tickets();
                break;
            case 2:
                search_flight_ticket();
                break;
            case 3:
                sort_flight_tickets();
                break;
            case 0:
                printf("\n ============ We are sad to see you go ============ \n");
                break;
            default:
                printf("\n Invalid choice\n");
            }
        }

    } while (oper != 0);
}