#ifndef AUTH_H
#define AUTH_H

struct User
{
    int user_id;
    char name[200];
    char username[60];
    char city[200];
    int is_admin;
} user;

struct User authorization();

#endif
