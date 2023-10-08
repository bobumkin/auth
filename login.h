#ifndef LOGIN_H_
#define LOGIN_H_

#include <string>
#include <unordered_map>
#include <iostream>

struct user_data
{
    std::string email;
    std::string user_name;
    std::string password;
};

class User
{
public:
    User(const std::string& em, const std::string& pw, const std::string& un);

    void change_user_name();
    void change_password();

    bool verification(const std::string& em, const std::string& pw);

    std::string get_email() const {return user.email;}
    std::string get_user_name() const {return user.user_name;}
protected:
    std::string get_hash_password() const {return user.password;}
private:
    user_data user;
};

#endif