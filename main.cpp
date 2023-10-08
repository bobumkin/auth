#include "login.h"
#include "functions.h"
#include <iostream>

std::unordered_map<std::string, User> users;

int main()
{
    choice(users);
    return 0;
}