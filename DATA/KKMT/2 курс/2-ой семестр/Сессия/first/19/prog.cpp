#include <iostream>

struct DateForUser
{
    int day;
    int month;
    int year;
};
struct UserData
{
    long unsigned int idUsers;
    std::string fio;
    std::string mail;
    long unsigned int mobile;
    long unsigned int NumberSnils;
    DateForUser birthday;
};

int main()
{
    struct UserData Data;
    while (true){
        scanf("%lici %s %s %%lici %lici", &(Data.idUsers), &(Data.fio), &(Data.mail), &(Data.mobile), &(Data.NumberSnils), &(Data.birthday));
    }
    return 0;
}

