#pragma once
#include <iostream>
#include <iomanip>
/// Структурa Date - съхранява дата 

/// Изполвам struct за да имам лесен и удобен достъп по всяко време до член данните
/// Типа на датата е във формат ISO 8601
struct Date
{
    int day;
    int month;
    int year;

    Date(int _year,int _month,int _day);
    Date();
    Date(const Date &other);
    /// Изписва датата
    void displayDate()const;

    ///Функция за записване на дата в подаден файл
    void write(std::ostream& file);
    ///Функция за четене дата от подаден файл
    void read(std::istream& file);

};
///предефиниране на оператор "==" с цел сравняване на тва обекта от тип struct
bool operator==(const Date &first, const Date &second);
///предефиниране на оператор "<<" за изход в поток, с цел печатане на обект от тип struct
std::ostream& operator << (std::ostream& stream, const Date& date);
///предефиниране на оператор "<" с цел сравняване на тва обекта от тип struct
bool operator < (const Date& str, const Date& str2);
///предефиниране на оператор "<" с цел сравняване на тва обекта от тип struct
bool operator > (const Date& str, const Date& str2);