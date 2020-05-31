#include "ticket.h"
#include "hall.h"
#include <ctime>
Ticket::Ticket()
{
    ID ="";
}
Ticket::Ticket(int row,int seat, const Date& date,int hallN)
{
    ID = "";                                                  //3A04W1020200713D -> пример за Билет
    ID+=std::to_string(hallN);                                //съдържа в себе си номер на зала, ред, място, дата и произволно генерирани главни букви 
    ID+=RandomChar();
    if(singleNum(row)){ID+='0';}
    ID+=std::to_string(row);
    ID+=RandomChar();
    if(singleNum(seat)){ID+='0';}
    ID+=std::to_string(seat);
    ID+=std::to_string(date.year);
    if(singleNum(date.month)){ID+='0';}
    ID+=std::to_string(date.month);
    if(singleNum(date.day)){ID+='0';}
    ID+=std::to_string(date.day);
    ID+=RandomChar();
}
char Ticket::RandomChar()
{
    // Използва се за да допринесе достоверност към номера на билета
    char random;
    char a[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int r = (rand() % 26) +1;
    random = a[r-1];
    return random;
}
bool Ticket::singleNum(int number)const
{
    if(number <10)
    {
        return true;
    }
    return false;
}
void Ticket::displayTicket()const
{
    std::cout <<ID;
}
std::string Ticket::getID()
{
    return ID;
}
void Ticket::show_row_and_seat(std::string id)const
{
    id.erase(0,2); 
    std::string helper = id.substr(0,2);
    int rowHelper = stoi(helper);
    id.erase(0,3);
    helper = id.substr(0,2);
    int seatHelper = stoi(helper);
    std::cout <<"Row "<<rowHelper<<" Seat "<<seatHelper<<"\n";
}
void Ticket::write(std::ostream& f)
{
    f.write(ID.c_str(), ID.length()+1);
}
void Ticket::read(std::istream& f)
{
    std::getline(f, ID, '\0');
}