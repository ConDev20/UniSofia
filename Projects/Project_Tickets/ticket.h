#pragma once
#include "hall.h"
#include "date.h"
#include <string>
/// class Ticket - Съдържа данни относно закупени билети.

/**
 * @class Ticket
 * .
 * @param ID Поменливата съдържа уникален номер на закупения билет
 */
class Ticket
{
    private:
    std::string ID;
    public:
    Ticket();

    ///Конструктор генериращ уникалния номер за закупения билет
    Ticket(int row,int seat, const Date& date,int hallN);

    ///Връща случайно генерирана променлива[A-Z] от тип char
    char RandomChar();

    /// Принтира на стандартния изход идентификатора на билета
    void displayTicket()const;

    /// Проверява дали едно число е цифра
    bool singleNum(int number)const;

    /// От уникалния номер на билета извлича данни за място и ред
    void show_row_and_seat(std::string id)const;

    /// Гет фунцкия за принтиране на билетния номер
    std::string getID();

    ///Фунцкията записва Уникалния код на билета в подаден файл
    void write(std::ostream& f);

    ///Фунцкията чете Уникалния код на билета от подаден файл
    void read(std::istream& f);
};

