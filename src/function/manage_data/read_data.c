#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ft_ticket.h"

FILE *data_file;

void display_flight_tickets()
{
    struct FlightTicket display_ft;
    data_file = fopen("data/database.txt", "r");
    if (user.is_admin == 1)
    {
        printf(
            "\nID\tFirst Name\tLast Name\tOrigin  \tDestination\tType\tNote\n===\t===========\t===========\t======= \t============\t======\t========\n");
    }
    else
    {
        printf(
            "\nID\tOrigin  \tDestination\tType\tNote\n===\t======= \t============\t======\t========\n");
    }

    while (!feof(data_file))
    {
        fscanf(
            data_file,
            "%d\t%d\t%s\t%s\t%s\t%s\t%d\t%s\n",
            &display_ft.id,
            &display_ft.user_id,
            display_ft.user_fname,
            display_ft.user_lname,
            display_ft.origin,
            display_ft.destination,
            &display_ft.flight_type,
            display_ft.note);
        if (user.user_id == display_ft.user_id && user.is_admin == 0)
        {
            printf(
                "%d\t%-8s\t%-8s\t%d\t%-15s\n",
                display_ft.id,
                display_ft.origin,
                display_ft.destination,
                display_ft.flight_type,
                display_ft.note);
        }
        else if (user.is_admin == 1)
        {
            printf(
                "%d\t%-8s\t%-8s\t%-8s\t%-8s\t%d\t%-15s\n",
                display_ft.id,
                display_ft.user_fname,
                display_ft.user_lname,
                display_ft.origin,
                display_ft.destination,
                display_ft.flight_type,
                display_ft.note);
        }
    }
    fclose(data_file);
};

void search_flight_ticket()
{
    struct FlightTicket searched_ft;
    int ft_id;
    data_file = fopen("data/database.txt", "r");
    printf("Enter Flight Ticket ID: ");
    scanf("%d", &ft_id);
    while (!feof(data_file))
    {
        fscanf(
            data_file,
            "%d\t%d\t%s\t%s\t%s\t%s\t%d\t%s\n",
            &searched_ft.id,
            &searched_ft.user_id,
            searched_ft.user_fname,
            searched_ft.user_lname,
            searched_ft.origin,
            searched_ft.destination,
            &searched_ft.flight_type,
            searched_ft.note);
        if (ft_id == searched_ft.id)
        {
            printf(
                "\nID\tFirst Name\tLast Name\tOrigin  \tDestination\tType\tNote\n===\t===========\t===========\t======= \t============\t======\t========\n");
            printf(
                "%d\t%-8s\t%-8s\t%-8s\t%-8s\t%d\t%-15s\n",
                searched_ft.id,
                searched_ft.user_fname,
                searched_ft.user_lname,
                searched_ft.origin,
                searched_ft.destination,
                searched_ft.flight_type,
                searched_ft.note);
            break;
        }
    }
    fclose(data_file);
};
