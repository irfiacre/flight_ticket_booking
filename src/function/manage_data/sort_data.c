#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ft_ticket.h"

FILE *data_file;

void sort_flight_tickets()
{
    struct FlightTicket ft, temp_ft, ft_array[100];
    int sort_id, k = 0;
    FILE *data_file;
    data_file = fopen("data/database.txt", "r");
    while (!feof(data_file))
    {
        fscanf(
            data_file,
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            &ft.id, &ft.user_id, ft.traveler_name, ft.origin, ft.destination, &ft.flight_type, ft.note);
        ft_array[k] = ft;
        k = k + 1;
    }
    fclose(data_file);
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
    for (int i = 0; i < k; i++)
    {
        printf(
            "%d\t%d\t%s\t%s\t%s\t%d\t%s\n",
            ft_array[i].id,
            ft_array[i].user_id,
            ft_array[i].traveler_name,
            ft_array[i].origin,
            ft_array[i].destination,
            ft_array[i].flight_type,
            ft_array[i].note);
    }
};
