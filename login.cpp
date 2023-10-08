#include "login.h"
#include "sha256.h"
#include "functions.h"
#include <cctype>

User::User(const std::string& em, const std::string& pw, const std::string& un) 
{
    user.email = em;
    user.password = SHA256::cifrar(pw + SHA256::cifrar(user.email));
    user.user_name = un;
}

void User::change_user_name()
{
    std::cout << "Введите пароль: ";
    std::string pw;
    std::cin >> pw;
    if (SHA256::cifrar(pw + SHA256::cifrar(user.email)) != this->user.password) {
        std::cout << "Неверный пароль.\n";
        return;
    }
    std::cout << "Введите новое имя пользователя: ";
    std::cin >> this->user.user_name;
    std::cout << "Имя пользователя было изменино на " << this->user.user_name << "." << std::endl;
}

void User::change_password()
{
    std::cout << "Введите текущий пароль: ";
    std::string pw;
    std::cin >> pw;
    if (SHA256::cifrar(pw + SHA256::cifrar(user.email)) != this->user.password) {
        std::cout << "Неверный пароль.\n";
        return;
    }
    std::cout << "Введите новый пароль (минимум 8 символов с 1 заглавной буквой, 1 маленькой буквой, 1 цифрой и 1 спецсимволом): ";
    while (std::cin >> this->user.password && !check_password_reqs(this->user.password)) {
        std::cout << "Попробуйте снова: ";
    }
    this->user.password = SHA256::cifrar(this->user.password + SHA256::cifrar(user.email));
    std::cout << "Пароль был изменен." << std::endl;
}

bool User::verification(const std::string& em, const std::string& pw)
{
    if (em == this->user.email && SHA256::cifrar(pw + SHA256::cifrar(this->user.email)) == this->user.password) {
        return true;
    }
    else {
        return false;
    }
}