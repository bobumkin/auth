#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <unordered_map>
#include <string>
#include "login.h"

void choice(std::unordered_map<std::string, User>& users);
void actions(User& ur);
void registration(std::unordered_map<std::string, User>& users);
void log_in(std::unordered_map<std::string, User>& users);
bool check_password_reqs(const std::string& pw);

#endif