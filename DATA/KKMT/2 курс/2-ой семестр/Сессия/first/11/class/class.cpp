#include <iostream>
 
class DateClass{ // члены класса являются закрытыми по умолчанию
    int m_day; // закрыто по умолчанию, доступ имеют только другие члены класса
    int m_month; // закрыто по умолчанию, доступ имеют только другие члены класса
    int m_year; // закрыто по умолчанию, доступ имеют только другие члены класса
 
public:
    void setDate(int day, int month, int year){ // открыто, доступ имеет любой объект
        m_day = day;
        m_month = month;
        m_year = year;
    }
 
    void print(){ // открыто, доступ имеет любой объект
        std::cout << m_day << "/" << m_month << "/" << m_year << '\n';
    }
};
 
int main(){
    DateClass date;
    date.setDate(12, 11, 2018); // ок, так как setDate() имеет спецификатор доступа public
    date.print(); // ок, так как print() имеет спецификатор доступа public
 
    return 0;
}
