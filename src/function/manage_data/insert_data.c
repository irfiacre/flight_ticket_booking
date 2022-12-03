#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ft_ticket.h"

FILE *data_file;

void book_flight_ticket()
{
    struct FlightTicket ft;
    data_file = fopen("data/database.txt", "a");
    ft.id = generate_random_nbr(9000000);
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
        data_file,
        "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
        ft.id, ft.user_id, ft.traveler_name, ft.origin, ft.destination, ft.flight_type, ft.note);
    fclose(data_file);
    printf("\n ✅ Flick Ticket Booked \n");
};
