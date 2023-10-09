#include "functions.h"
#include "login.h"

void choice(std::unordered_map<std::string, User>& users)
{
    char choice;
    while (true) {
        std::cout << "Выберите действие:\n 1 - зарегестрироваться.\t2 - авторизоваться.\t0 - выйти из программы.\n";
        std::cin >> choice;
        switch (choice)
        {
            case '1': {
                registration(users);
                break;
            }
            case '2': {
                log_in(users);
                break;
            }
            case '0': {
                exit(EXIT_SUCCESS);
            }
            default: {
                std::cout << "Пожалуйста, введите 1, 2 или 0.\n";
                break;
            }
        }
    }
}

void actions(User& ur)
{
    char choice;
    while (true) {
        std::cout << "Выберите действие:\n 1 - отобразить текущую почту и имя пользователя.\t2 - сменить имя пользователя.\t"
           "3 - сменить пароль.\t0 - выйти из пользователя.\n";
        std::cin >> choice;
        switch (choice)
        {
            case '1': {
                std::cout << "Почта: " << ur.get_email() << std::endl;
                std::cout << "Имя пользователя: " << ur.get_user_name() << std::endl;
                break;
            }
            case '2': {
                ur.change_user_name();
                break;
            }
            case '3': {
                ur.change_password();
                break;
            }
            case '0': {
                return;
            }
            default: {
                std::cout << "Пожалуйста, введите 1, 2, 3 или 0.\n";
                break;
            }
        }
    }
}

void registration(std::unordered_map<std::string, User>& users)
{
    std::string temp_email;
    std::string temp_password;
    std::string temp_user_name;
    std::cout << "Введите почту: ";
    std::cin >> temp_email;
    auto search = users.find(temp_email);
    if (search != users.end()){
        std::cout << "Данная почта занята.\n";
        return;
    }
    std::cout << "Введите пароль (минимум 8 символов с 1 заглавной буквой, 1 маленькой буквой, 1 цифрой и 1 спецсимволом): ";
    while (std::cin >> temp_password && !check_password_reqs(temp_password)) {
        std::cout << "Попробуйте еще раз.\n";
    }
    std::cout << "Введите имя пользователя: ";
    std::cin >> temp_user_name;
    users.insert({temp_email, User(temp_email, temp_password, temp_user_name)}); 
}

void log_in(std::unordered_map<std::string, User>& users)
{
    std::string temp_email;
    std::string temp_password;
    std::cout << "Введите почту: ";
    std::cin >> temp_email;
    std::cout << "Введите пароль: ";
    std::cin >> temp_password;
    auto search = users.find(temp_email);
    if (search != users.end()){
        if (search->second.verification(temp_email, temp_password)) {
            actions(search->second);
                return;
        }
    }
    std::cout << "Неверный логин или пароль.\n";
}

bool check_password_reqs(const std::string& pw)
{
    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_punct = false;
    bool reqs = false;

    int length = pw.length();
    if (length < 8) {
        std::cout << "Слишком короткий пароль.\n";
        return reqs;
    }
    for (size_t i = 0; i < length && !reqs; ++i) {
        has_lower |= islower(pw[i]);
        has_upper |= isupper(pw[i]);
        has_digit |= isdigit(pw[i]);
        has_punct |= ispunct(pw[i]);
        reqs |= (has_upper && has_lower && has_digit && has_punct);
    }
    if (!reqs) {
        if (!has_upper) {
            std::cout << "Пароль не имеет заглавной буквы.\n";
        }
        if (!has_lower) {
            std::cout << "Пароль не имеет маленькой буквы.\n";
        }
        if (!has_digit) {
            std::cout << "Пароль не имеет цифры.\n";
        }
        if (!has_punct) {
            std::cout << "Пароль не имеет спецсимвола.\n";
        }
    }
    return reqs;
}
