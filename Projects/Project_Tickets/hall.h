#pragma once
#include <iostream>
#include <vector>

/// class Hall - Съдържа данни относно залата(брой места, запазени места, закупени места, свободни места).


/**
 * @class Hall
 * .
 * @param hallN Поменливата съдъжа номерана на залата за текущия Event
 * @param rows Променливата съдъжа броя на редовете в залата
 * @param seats Променливата съдъжа броя на местата на всеки ред в залата
 * @param freeseats Променливата съдъжа броя свободните места в залата
 * @param ticketsBought Променливата съдъжа броя на местата, които за закупени в залата
 * @param board 2D vector от int-ове с размер rows*seats. Всяко място има свои статус { 0 - свободно, 1 - запазено, 2 - заето}
 */

class  Hall
{
    private:
    int hallN,rows,seats,freeSeats,ticketsBought;
    std::vector <std::vector<int> > board;
    public:
    ///Дефолтен конструктор
    Hall();
    Hall(const Hall &other);
    Hall(int _hallN,int _rows, int _seats);
    ///Приема int стойност отговаряща на номера на залата. Конструира зала със редове и места, отговарящи на номера на залата, като създава и board
    Hall(int hallN);

    ///Гет функция за номер на зала 
    int getHallN()const;

    ///Гет функция за брой редове в залата 
    int getRows()const;

    ///Гет функция за брой места на един ред в залата 
    int getSeats()const;

    ///Гет функция за брой закупени билети в залата 
    int getBoughtTickets()const;

    ///Сет функция за поставяне на номер на залата 
    void setHallNumber(int number);

    ///Функция променяща стойнота на зададеното ред и място в board на 1{запазено}
    void book(int rows,int seats);

    ///Функция променяща стойноста на запазено място обозначено с row и seat от 1{запазено} на 0{свободно}
    void unbook(int rows,int seats);

    ///Функция променяща стойнота на зададеното ред и място в board на 1{закупено}
    void buy(int rows,int seats);

    ///Функция инициализираща 2D вктор board по зададени редове и колони
    void setBoard(std::vector <std::vector<int> > &Matrix,int rows,int seats);

    ///Функция изписваща запазените места
    void showBoard()const;

    ///Функция изписваща местата които са заети (закупени/запазени)
    void showOccupiedSeats()const;

    ///Функция показваща кои места са свободни
    void showFreeSeats()const;

    /// Функция показваща състоянието на дадено място
    int seatStatus(int row, int seat)const;

    ///Функция връщаща променлива от тип int на броя свободни места
    int GetFreeSeats()const;

    ///Функция изчисляваща посещението на дадено представление в % и връщаща това число
    double statistics()const;

    ///Фунцкия за записване на Hall в подаден файл
    void write(std::ostream& file);
    ///Функция за четене на данни за класс Hall от подаден файл
    void read(std::istream& file);
};