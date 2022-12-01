#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct FlightTicket
{
    int id;
    char traveler_name[60];
    char origin[100];
    char destination[100];
    int flight_type;
    char departure_date[30];
    char payment_method[40];
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

void book_flight_ticket()
{
    struct FlightTicket ft;
    FILE *ptr;
    ptr = fopen("../src/database.txt", "a");
    ft.id = rand();
    printf("\nEnter Your Name: ");
    scanf("%s", ft.traveler_name);
    printf("\nEnter Origin and Destination: ");
    scanf("%s%s", ft.origin, ft.destination);
    printf("\nChoose flight Type \n 1.Business \t2. Economic \n: ");
    scanf("%d", &ft.flight_type);
    printf("\nChoose Departure time: ");
    scanf("%s", ft.departure_date);
    printf("\nEnter Payment method: ");
    scanf("%s", ft.payment_method);
    printf("\nAnything we should be aware of: ");
    scanf("%s", ft.note);

    fprintf(
        ptr,
        "%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\n",
        ft.id, ft.traveler_name, ft.origin, ft.destination, ft.flight_type, ft.departure_date, ft.payment_method, ft.note);
    fclose(ptr);
};

void display_flight_tickets()
{
    printf("Display flights");
};
void search_flight_ticket()
{
    printf("Search flight ticket");
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
            "%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\n",
            &ft.id, ft.traveler_name, ft.origin, ft.destination, &ft.flight_type, ft.departure_date, ft.payment_method, ft.note);
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
            "%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\n",
            ft_array[i].id,
            ft_array[i].traveler_name,
            ft_array[i].origin,
            ft_array[i].destination,
            ft_array[i].flight_type,
            ft_array[i].departure_date,
            ft_array[i].payment_method,
            ft_array[i].note);
    }
    fclose(p);
};

int generate_id()
{
    int lower = 1, upper = 700, count = 1;
    srand(time(0));
    return 100000 + ((rand() % (upper - lower + 1)) + lower);
}

struct User authorization()
{
    int choice;
    char user_name[60];
    printf("Choose \n1. Sign in \n2. Register\nEnter choice: ");
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
        user.user_id = generate_id();
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
    struct User new_user = authorization();
    printf("%d\t%s\t%s\t%s\t%d\n", new_user.user_id, new_user.name, new_user.username, new_user.city, new_user.is_admin);
    do
    {
        if (new_user.is_admin == 0)
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
            printf("1. Book Flight Ticket \n");
            printf("2. View Flight Tickets\n");
            printf("3. Search Flight Ticket\n");
            printf("4. Sort List of Flight Tickets \n");
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
            case 3:
                search_flight_ticket();
                break;
            case 4:
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