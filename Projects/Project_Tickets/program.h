#pragma once
#include <algorithm>
#include <fstream>
#include "hall.h"
#include "date.h"
#include "ticket.h"
#include "event.h"

/**
 * @class Event
 * .
 * @param events Вектор съдържащ обекти от тип Event.
 * @param halls Вектор съдържащ обекти от тип Hall.
 */
/// class Program - Изпълнава желаните от потребителя функции и обработва данните.

/// Съдържа в себе си Date, Hall, Ticket, Event.
class Program
{
    std::vector<Event> events; 
    std::vector<Hall> halls; 
    public:
    ///Дефолтен контрукотр инициалициращ залите, където може да се провеждат представления.
    Program(); 

    // Помощни функции за обработването на първоначално зададените данни.
    //-----------------------------------------------------//
    void Extract(std::string& a,int b);    
    std::string Extract(std::string &a,char b); 
    std::string Extract1(std::string a,char b); 
    std::string Extract2(std::string& a,int b); 
    std::string Extract3(std::string a,int b);  
    //-----------------------------------------------------//

    /// Изтрива стринга от елемент 0 до обозначения символ.
    void Cut (std::string &a,char b);

    ///Изтрива стринга от a[0] до a[число b] .
    void Cut (std::string &a,int b); 

    ///Замества срещането на един символ с друг в даден string.
    std::string replace(std::string str,char to_be_replaced, char replacement);

    ///Iзразява първият намерен под-стринг от главния string
    void eraseSubStr(std::string& mainStr, const std::string& strToErase);

    ///Ако е въведено разстояние в string-a (който се създава при въвеждане на директория на файла), го замества с '\'. Също така връща името на файла.
    /// Потребителят има възможност да запише директорията на файла по различен начин.
    /// Ако въведе само име на файл, той ще се създаде в директорията на програмата.
    /// Друга възможност е като запише нова/съществуваща директория на файла.
    std::string filePath_converter(std::string& path);


    void showBookingsNotes(std::vector<std::string> notes);

    ///Проверява дали подадената дата е валидна.
    bool checkDate(int year,int month,int day)const;

    ///Проверява дали подадената дата под формата на стринг е правилно въведена.
    bool  isDateValid(std::string date);

    ///Проверява дали един файл е празен.
    bool is_empty(std::fstream& pFile);

    ///Трансформира дата под формата на string в обект от тип Date
    void stringToDate(std::string date, Date &tmp);

    ///Проверява дали даден номер на зала съществува в зададените първоначално зали.
    bool isHallvalid(int hallNumebr)const;

    ///Проверява дали дадено място е валидно.
    bool isPlaceValid(int row1, int seat1, int hall1)const;

    ///Функция трансформираща char елемент в променлива от тип Int.
    int charToint(char a);

    ///Трансформира стринг (съдържащ ред или място) в число.
    int rowSeatToInt(std::string something);

    ///Главна фунцкия обединяваща използването на функции и обекти.
    void main();
};