#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "function/helpers.c"
#include "function/auth/auth.c"
#include "function/manage_data/insert_data.c"
#include "function/manage_data/read_data.c"
#include "function/manage_data/sort_data.c"

int main()
{
    int oper;
    load_default_users();
    printf("\n----------------------------------------------------------------\n");
    printf(" *********| WELCOME TO AUKA FLIGHT TICKET MANAGEMENT |*********\n");
    printf("----------------------------------------------------------------\n");
    struct User current_user = authorization();
    do
    {
        if (current_user.is_admin == 0)
        {
            printf("\n \tMain Menu\n|---------------------------|\n");
            printf("1. Book Flight Ticket \n");
            printf("2. View Flight Tickets\n");
            printf("0. Exit\n");
            printf("\nEnter choice: ");
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
                printf("\n===============================\n Good Bye, See you Next!!! \n===============================\n");
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
            printf("\nEnter choice: ");
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
                printf("\n===============================\n Good Bye, See you Next!!! \n===============================\n");
                break;
            default:
                printf("\n Invalid choice\n");
            }
        }

    } while (oper != 0);
}