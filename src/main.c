#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct FlightTicket
{
    int id;
    char owner_name[60];
    char traveler_email[100];
    char origin[100];
    char destination[100];
    char flight_type[10];
    char departure_date[30];
    char payment_method[40];
    char note[];
};
struct User
{
    int user_id;
    char name[200];
    char username[60];
    char city[200];
} user;

void book_flight_ticket()
{
    printf("Booking a flight");
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
    printf("Sort flight ticket");
};

int generate_id()
{
    int lower = 1, upper = 700, count = 1;
    srand(time(0));
    return 100000 + ((rand() % (upper - lower + 1)) + lower);
}

void authorization()
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
        while (!feof(users_file))
        {
            fscanf(users_file, "%d\t%s\t%s\t%s\n", &user.user_id, user.name, user.username, user.city);
            if (user.username == user_name)
            {
                username_found = 1;
            }
        }
        fclose(users_file);
        if (username_found == 1)
        {
            printf("---------------We have the user");
        }
        else
        {
            printf("We do not have a user with username %s", user_name);
        }

        break;
    case 2:
        users_file = fopen("../src/users_database.txt", "a");
        printf("Enter Your Name: ");
        scanf("%s", user.name);
        printf("\nChoose username: ");
        scanf("%s", user.username);
        printf("Enter Your city: ");
        scanf("%s", user.city);
        user.user_id = generate_id();
        fprintf(users_file, "%d\t%s\t%s\t%s\n", user.user_id, user.name, user.username, user.city);
        fclose(users_file);
        printf("\n==== User successfully Registered ======\n");
        authorization();
        break;
    default:
        printf("\n Wrong choice\n");
        break;
    }
}

int main()
{
    int oper;
    printf("Welcome to my Auka Flights management \n");
    authorization();
    do
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
            printf("\n Wrong choice\n");
        }
    } while (oper != 0);
}