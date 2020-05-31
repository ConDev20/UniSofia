#pragma once
#include "date.h"
#include "hall.h"
#include "ticket.h"
/// class Event - Съдържа данни относно дадено представление.
/// Съдържа в себе си Date, Hall и Ticket

/**
 * @class Event
 * .
 * @param name Поменливата съдържа името на представлението
 * @param date променлива от тип Date, съдържа датата на представлението
 * @param hall Променливата от тип Hall, съдържа данни за залата в която ще се провежда представлението
 * @param tickets Вектор съдържащ променливи от тип Ticket. Съдържа всички купени билети за даденото представление
 * @param notes Вектор съдържащ променливи от тип стринг. Съдържа бележки за запазени места
 */
class Event
{
    public:
    std::string name;
    Date date;
    Hall hall;
    std::vector<Ticket> tickets;
    std::vector<std::string> notes;// date i ime
    public:
    Event();
    Event(const Date& _date,const Hall& _hall, const std::string& _name);
    ///Сравнява два обекта от тип Event по техните дати
    bool operator < (Event const &other) const  
    { 
        if (date < other.date)
            return true;
        if (date > other.date)
            return false;
        return (hall.getHallN() < other.hall.getHallN());
    }
    /// Записва данните на Event в подаден файл
    void write(std::ostream& f);

    void clear()
    {
        tickets.clear();
        notes.clear();
    }
    
    /// Чете данни от файл и ги съхранява в обект от тип Event
    void read(std::istream& f);
};