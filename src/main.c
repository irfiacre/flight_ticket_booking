#include <stdio.h>

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
    printf("This is emmy's work");
};
void sort_flight_tickets()
{
    printf("Sort flight ticket");
};

int main()
{
    int oper;
    printf("Welcome to my Auka Flights management \n");
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