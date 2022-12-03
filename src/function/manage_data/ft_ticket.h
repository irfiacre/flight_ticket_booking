#ifndef FT_TICKET_H
#define FT_TICKET_H

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

void book_flight_ticket();
void display_flight_tickets();
void search_flight_ticket();

#endif
