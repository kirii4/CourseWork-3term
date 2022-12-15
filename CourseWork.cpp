#include "User.h"
#include <windows.h>
#include <time.h>

int main() {
    SetConsoleCP(1251); //Кодировка для ввода из консоли и редактора кода
    SetConsoleOutputCP(1251); //Кодировка для вывода в консоль
    srand(time(NULL));

    int hello = User::welcome(); // Попытка входа в систему (0 - регистрация, 1 - вход в аккаунт)

    if (hello == 1) { // Вход в режим "Войти в аккаунт"
        std::string login;
        hello = User::sign_in(login);
        if (hello == 1) {
            system("cls");
            User::adminMenu(login);
        }
        else {
            User::userMenu(login);
        }
    }
}