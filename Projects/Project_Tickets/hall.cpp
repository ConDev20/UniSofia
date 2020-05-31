#include "hall.h"

    Hall::Hall(int _hallN,int _rows, int _seats)
    {
        hallN = _hallN;
        rows = _rows;
        seats = _seats;
        freeSeats = rows*seats;
        ticketsBought = 0;
        setBoard(board,rows,seats);
    }

    Hall::Hall()
    {
        hallN = 0;
        rows = 0;
        seats = 0;
        freeSeats = 0;
        ticketsBought = 0;
        setBoard(board,0,0);
    }
    Hall::Hall(const Hall &other)
    {
        hallN = other.hallN;
        rows = other.rows;
        seats = other.seats;
        freeSeats = other.freeSeats;
        ticketsBought = other.ticketsBought;
        board = other.board;
    }
    int Hall::getHallN() const
    {
        return hallN;
    }
    int Hall::getRows() const
    {
        return rows;
    }
    int Hall::getSeats() const
    {
        return seats;
    }
    void Hall::setHallNumber(int number)
    {
        hallN = number;
    }
    int Hall::getBoughtTickets()const
    {
        return ticketsBought;
    }
    int Hall::GetFreeSeats() const
    {
        return freeSeats;
    }
    void Hall::setBoard(std::vector <std::vector<int> > &Matrix,int rows,int seats)
    {

        ///Итерира през всички редове и колони, като задава първоначална стойност 0{свободно}
        for(int i = 0; i <rows; ++i)
        {
            std::vector<int>tmp;
            for(int j = 0; j <seats;++j)
            {
                tmp.push_back(0);
            }
            Matrix.push_back(tmp);
        }
    }
    void Hall::book(int rows,int seats)
    {
        ///Проверява дали подаденото място е свободно, ако да променяма стойноста му на 1{запазено}
        if(board[rows-1][seats-1]==0) 
        {
            board[rows-1][seats-1] = 1;
            freeSeats--;
            std::cout <<"You booked seat "<<seats<<" on row "<<rows<<".\n";
        }
    }
    void Hall::unbook(int rows,int seats)
    {
        ///Проверява дали подаденото място е със стойност 1{запазено}, ако да променяма стойноста му на 0{свободно}
        if(board[rows-1][seats-1] == 1) 
        {
            board[rows-1][seats-1] = 0;
            freeSeats++;
            std::cout <<"You unbooked seat "<<seats<<" on row "<<rows<<".\n";
        }
    }
    void Hall::buy(int rows,int seats)
    {
        ///Проверява дали подаденото място е свободно, ако да променяма стойноста му на 2{закупено}
        if(board[rows-1][seats-1]==0) 
        {
            board[rows-1][seats-1] = 2;
            freeSeats--;
            ticketsBought++;
            std::cout <<"You bought a ticket for seat "<<seats<<" on row "<<rows<<".\n";
        }
    }
    void Hall::showBoard()const
    {  
        ///Итерира през всички редове и колони, като проверява дали мастото е 1{запазено}, ако да изписва го
        int counter = 1;
        for(int i = 0; i <rows; ++i)
        {
            for(int j = 0; j <seats;++j)
            {
                if(board[i][j] == 1)
                {
                    if(counter%5 == 0 && counter!= 0)
                    {std::cout <<"\n";}
                    std::cout <<"("<<i+1<<","<<j+1<<")  ";
                    counter++;
                }
            }
        }
        std::cout <<"\n";
    }
    void Hall::showFreeSeats()const
    {
        int counter = 1;
        for(int i = 0; i <rows; ++i)
        {
            for(int j = 0; j <seats;++j)
            {
                if(board[i][j] == 0)
                {
                    if(counter%5 == 0 && counter!= 0)
                    {std::cout <<"\n";}
                    std::cout <<"F("<<i+1<<","<<j+1<<")  ";
                    counter++;
                }
            }
        }
        std::cout <<"\n";
    }
    void Hall::showOccupiedSeats()const
    {
        ///Итерира през всички места в board като проверява дали мястото е заето, като изписва дали е запазено или закупено
        std::cout <<"R - Reserved  | B - Bought\n";
        int counter = 0;
        for(int i = 0; i <rows; ++i)
        {
            for(int j = 0; j <seats;++j)
            {
                if(board[i][j] == 1)
                {
                    if(counter%5 == 0 && counter!= 0)
                    {std::cout <<"\n";}
                    std::cout <<"R("<<i+1<<","<<j+1<<")  ";
                    counter++;
                }else if (board[i][j] == 2)
                {
                    if(counter%5 == 0 && counter!=0)
                    {std::cout <<"\n";}
                    std::cout <<"B("<<i+1<<","<<j+1<<")  ";
                    counter++;
                }
            }
        }
        //Ако функцията statistics()const върне число по малко от 10, изписва самото число
        if(statistics()<10.00)
        {
            std::cout <<"Attendance for this event: "<<statistics()<<"%\n";
        }
        std::cout <<"\n";
    }
    int Hall::seatStatus(int _row, int _seat)const
    {
        if((_row < 1 || _row >rows) || (_seat < 1 || _seat >seats ))
        {
            return 4;
        }
        return board[_row-1][_seat-1];
    }
    double Hall::statistics()const
    {
        return double(getBoughtTickets()/double(rows*seats))*100.00;
    }
    void Hall::write(std::ostream& file)
    {
        file.write( (char*)&hallN, sizeof(hallN));
        file.write( (char*)&rows, sizeof(rows));
        file.write( (char*)&seats, sizeof(seats));
        file.write( (char*)&freeSeats, sizeof(freeSeats));
        file.write( (char*)&ticketsBought, sizeof(ticketsBought));
        for (int i = 0; i <rows; ++i)
        {
            for (int j = 0; j<seats; ++j)
            {
                file.write ((char*)(&board[i][j]), sizeof(int));
            }
        } 
    }
    void Hall::read(std::istream& file)
    {
        file.read( (char*)&hallN, sizeof(hallN));
        file.read( (char*)&rows, sizeof(rows));
        file.read( (char*)&seats, sizeof(seats));
        file.read( (char*)&freeSeats, sizeof(freeSeats));
        file.read( (char*)&ticketsBought, sizeof(ticketsBought));
        setBoard(board,rows,seats);
        for (int i = 0; i <rows; ++i)
        {
            for (int j = 0; j<seats; ++j)
            {
                file.read((char*)(&board[i][j]), sizeof(int));
            }
        } 
    }