#include "program.h"

Program::Program()
{   
    Hall A(1,5,5);
    Hall B(2,10,10);
    Hall C(3,15,15);
    Hall D(4,20,20);
    
    halls = {A,B,C,D};    
}
 std::string Program::Extract(std::string &a,char b)
{
    std::string helper;
    helper = a.substr(0,a.find(b));
    return helper;
}
std::string Program::Extract1(std::string a,char b)
{
    a = a.substr(0,a.find(b)+1);
    return a;
}
void Program::Extract(std::string& a,int b)
{    
    a = a.substr(0,b);
}
std::string Program::Extract2(std::string& a,int b)
{
    a = a.substr(0,b);
    return a;
}
std::string Program::Extract3(std::string a,int b)
{
    a = a.substr(0,b);
    return a;
}
void Program::Cut (std::string &a,char b)
{
    a.erase(0, a.find(b) + 1);
}
void Program::Cut (std::string &a,int b)
{
    a.erase(0, b);
}
bool Program::checkDate(int year,int month,int day)const
{
    if(year<2020 || year >2050)
    {
        return false;
    } else if (month ==1 || month ==3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
    {
        if(day>=1 && day<=31 )
        {
            return true;
        }
    } else if(month == 4 || month ==6 || month == 9 || month == 11 )
    { 
        if(day>=1 && day<=30 )
        {
            return true;
        }
    } else if(month ==2)
    {
        if(year%400==0 || (year%100!=0 && year%4==0))
        {
            if(day>=1 && day <=29)
            {
                return true;
            }
        } else
        {
          if(day>=1 && day <=28)
            {
                return true;
            }
        } 
    }
    return false;
}
bool Program::is_empty(std::fstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
std::string Program::filePath_converter(std::string& path) 
{

    std::string helper = path;
    int counter = -1;
    for(int i = 0; i < path.length(); ++i)
    {
        if(path[i]=='\\')
        {
            counter = i;
        }else if(path[i] == ' ')
        {
            path[i] = '\\';
            counter = i;
        }
    }
    Cut(helper,counter+1); // Helper сега съдържа името на файла.
    return helper;
}

bool  Program::isDateValid(std::string date)
{

    std::string helper = Extract(date,'-');
    int year,month,day;
    /// За да се предодврати спиране на програмта при неправилно въведена дата.
    try{ year = std::stoi(helper); }
    catch(const std::exception& e){}
    Cut(date,'-');
    helper = Extract(date,'-');
    if(helper.length()<2)
    {
        return false;
    }
    try{ month = std::stoi(helper); }
    catch(const std::exception& e){}
    Cut(date,'-');
    helper = Extract(date,'-');
    if(helper.length()<2)
    {
        return false;
    }
    try{ day = std::stoi(helper); }
    catch(const std::exception& e){}
    if(checkDate(year,month,day))
    {
        return true;
    }
    return false;
}
std::string Program::replace(std::string str,char to_be_replaced, char replacement)
{
    for(int i = 0; i <str.length();++i)
    {
        if (str[i] == to_be_replaced)
        {
            str[i] = replacement;
        }
    }
    return str;
}
void Program::stringToDate(std::string date, Date &tmp)
{
    std::string helper = Extract(date,'-');
    int year = std::stoi(helper);
    Cut(date,'-');
    helper = Extract(date,'-');
    int month = std::stoi(helper);
    Cut(date,'-');
    helper = Extract(date,'-');
    int day = std::stoi(helper);
    tmp.day = day;
    tmp.month = month;
    tmp.year = year;
}
bool Program::isHallvalid(int hallNumber)const
{
    for(int i = 0; i < halls.size();++i)
        {
            if(hallNumber == halls[i].getHallN())
            {
                return true;
            }
        }  
    return false;
}
bool Program::isPlaceValid(int row1, int seat1, int hall1)const
{   
    for(int i = 0; i<halls.size();++i)
    {
        if(halls[i].getHallN()== hall1)
        {
            if(row1<=halls[i].getRows() && seat1 <= halls[i].getSeats())
            {
                return true;
            }
            return false;
        }
    }
    return false;
}
void Program::showBookingsNotes(std::vector<std::string> notes)
{
    std::string input;
    if(notes.size()>0)
    {
        std::cout <<"Do you want to see the notes for the bookings? Y/N\n";
        std::cin>>input;
        if(input == "N")
        {
            return;
        }else if(input == "Y")
        {
            std::string row,seat,note;
            for(int i = 0; i <notes.size();++i)
            {
                if(notes[i] == " "){continue;}
                row = (Extract(notes[i],' '));
                Cut(notes[i],' ');
                seat = (Extract(notes[i],' '));
                Cut(notes[i],' ');
                note = notes[i];
                std::cout <<"("<<row<<","<<seat<<") - "<<note<<"\n";
            }
        }else
        {
            std::cout <<"Wrong input\n";
            return;
        }
    }
    
}
void Program::eraseSubStr(std::string& mainStr, const std::string& strToErase)
{
	size_t position = mainStr.find(strToErase);
	if (position != std::string::npos)
	{
		mainStr.erase(position, strToErase.length());
	}
}
int Program::charToint(char a)
{
    char *p = &a;
    int k = atoi(p);
    return k;
}
int Program::rowSeatToInt(std::string something)
{
    int number;
    try
    {
        number = std::stoi(something);
    }
    catch(const std::exception& e)
    {
        return 0;
    }
    return number;
}
void Program::main()
{
    std::string input;  
    std::fstream MyFile;
    std::string FileName;
    std::string FilePath;
    bool opened = false;
    
    while(true)
    {   
        std::getline(std::cin,input);
        std::string inputSave = input;
        std::string firstWord = Extract(input,' ');
        ///Проверява каква е първата дума от командата и изпълнява изскванията за нея.
        /// Изпълнява се серия от изваждане на пъроначлно въведената информация и проверка на информацията
        /// чрез обхождане на вектори. След като данните биват "одобрени", те биват записвани в контейнера към когото принадлежат.
        /// При отваряне на файл, данните от него се извличат, посредством функции, специфични за всеки отделен клас.
        /// При запазването на файл, всички данни се записват в новосъздаден или празен файл, посредством функции на всеки отделен клас.
        if(firstWord == "addevent")
        {
            
            Cut(input,' ');
            std::string date = Extract(input,' ');
            if(!isDateValid(date))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d1;
            stringToDate(date,d1);
            Cut(input,' ');
            int hallNumber = 0;
            try
            {
                hallNumber = std::stoi((input));
            }
            catch(const std::exception& e)
            {
                std::cout<< "Wrong hall input! \n";
                continue;
            }
            if(!isHallvalid(hallNumber))
            {
                std::cout <<"Wrong input!No such hall found!\n";
                continue;
            }
            input.erase(0, 1);
            if(input[0] != ' ')
            {
                std::cout <<"Wrong input!/No name for event!\n";
                continue;
            } 
            input.erase(0, 1);
            if(input.length()==0)
            {
                 std::cout <<"Wrong input!/No name for event!\n";
                 continue;
            }
            bool exit = 0;
            // Проверка дали съществува Event на същата дата със същото име/зала.
            for (int i = 0; i <events.size();++i)
            {
                if(events[i].date==d1)
                {
                    if(events[i].hall.getHallN() == hallNumber)
                    {   
                        std::cout <<"There cant be 2 events in the same hall in one day!\n";
                        exit = 1;
                        break;
                    }
                    if(events[i].name == input)
                    {
                        std::cout <<"There cant be 2 events with the same name in one day!\n";
                        exit = 1;
                        break;
                    }
                }
            }
            if (exit){exit = 0;continue;}
            //Ако всичко е наред, прибавя представлението към вектора с представления.
            Event tmp(d1,halls[hallNumber-1],input);
            events.push_back(tmp);
            std::cout <<"Event added successfully!\n";
            continue;
        }else if(firstWord == "book" || firstWord == "unbook" || firstWord == "buy")
        {
            //Тъй като и при трите функции извадката на данните е еднотипна, съм ги съчетал в един случай.
            // Данните се извличат посредством функци.
            if(events.size() == 0)
            {
                std::cout <<"There are no events\n";
                continue;
            }
            
            Cut(input,' ');
            std::string rowStr = Extract(input,' ');
            int row = rowSeatToInt(rowStr);           //Запазване на реда като стринг с цел по лесно запазване на Бележки вбъдеще.
            Cut(input,' ');
            std::string seatStr = Extract(input,' '); //Запазване на мястото като стринг с цел по лесно запазване на Бележки вбъдеще.
            int seat = rowSeatToInt(seatStr);             
            Cut(input,' ');
            std::string date = Extract(input,' ');
            //Проверява дали датата е валидна преди създаването на обект от тип Date.
            if(!isDateValid(date))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d1;
            stringToDate(date,d1);
            Cut(input,' ');
            std::string name = Extract(input,' ');
            if(firstWord == "book")
            {
                eraseSubStr(input,name); //Символът ' ' не се изтрива с цел по лесно запазване на Бележки вбъдеще.
                std::string note = input; 
                bool booked = 0;
                /*
                    Итерира през всички представления и проверява дали същестува такова със същото име и дата.
                    Ако да, дали желаното място е заето или не.
                */
                for (int i = 0; i <events.size();++i)
                {
                    if(events[i].date == d1)
                    {
                        if(events[i].name == name)
                        {
                            if(events[i].hall.seatStatus(row,seat) == 0)
                            {
                                if(!isPlaceValid(row,seat,events[i].hall.getHallN()))
                                {std::cout <<"Wrong seat/row input \n";break;}
                                events[i].hall.book(row,seat);
                                booked = 1;                                          //Индикатор за запазване на мястото.
                                if(note!="" && note!=" ")                           // Проверява дали има оставена бележка.   
                                {                                                   // Ако да, запазва я в отделен контейнер.
                                    events[i].notes.push_back(rowStr+' '+seatStr+note);
                                }
                                break;
                            } else std::cout <<"Seat is already taken! "; 
                            {
                                break;
                            }
                        }
                    }
                }
                if(!booked)
                {
                    std::cout <<"Couldn't book the seat\n";
                }else
                {
                    booked = 0; // Индикатора се слага обратно на false за бъдещи използвания на функцията.
                }
                continue;
            }else if(firstWord == "unbook")
            {
                bool unbooked = 0;
                for (int i = 0; i <events.size();++i)
                {
                    if(events[i].date == d1)
                    {
                        if(events[i].name == name)
                        {
                            if(events[i].hall.seatStatus(row,seat) == 1)
                            {
                                events[i].hall.unbook(row,seat);
                                unbooked = 1;
                                for(int j = 0; j <events[i].notes.size();++j)
                                {
                                    std::string helper = rowStr+' '+seatStr+' ';
                                    if(Extract3(events[i].notes[j],helper.length())==helper)
                                    {
                                        events[i].notes.erase(events[i].notes.begin()+j);
                                        break;
                                    }
                                    continue;
                                }
                                break;
                            }
                        }
                    }
                    if(unbooked)
                    {
                        break;
                    }
                }
                if(!unbooked)
                {
                    std::cout <<"Couldn't unbook the seat\n";
                }else
                {
                    unbooked = 0;
                }
                continue;
            }else if (firstWord == "buy")
            {
                bool bought = 0;
                for (int i = 0; i <events.size();++i)
                {
                    if(events[i].date == d1)
                    {
                        if(events[i].name == name)
                        {
                            if(events[i].hall.seatStatus(row,seat) == 0)
                            {
                                events[i].hall.buy(row,seat);
                                bought = 1;
                                Ticket tmp(row,seat,d1,events[i].hall.getHallN());
                                std::cout <<"Your ticket number is: | ";
                                tmp.displayTicket();
                                std::cout <<" | It is unique and will be required for entering the event!\n";
                                events[i].tickets.push_back(tmp);
                                break;
                            } else std::cout <<"Seat is already taken / Wrong input";
                        }
                    }
                }
                if(!bought)
                {
                    std::cout <<"Couldn't buy the ticket!\n";
                }else
                {
                    bought = 0;
                }
                continue;
            }
        }else if (firstWord == "bookings")
        {
            if(events.size() == 0)
            {
                std::cout <<"There are no events\n";
                continue;
            }
            Cut(input,' ');
            std::string date = Extract(input,' ');  
            std::string name = "";
            
            if(isDateValid(date))
            {
                Date d1;
                stringToDate(date,d1);
                Cut(input,(int)date.length());
                //Ако дължината на input е по малка от 1 (след премахването на date), то име не е написано.
                if(input.length()<1)
                {
                    int counter = 0;
                    /* 
                        Итерира през всички представления и проверява дали има такова на същата дата.
                        Ако да, показва запазените места, както и всички записани бележки(ако има такива).
                     */
                    for(int i = 0; i<events.size();++i)
                    {
                        if(events[i].date == d1)
                        {
                            std::cout <<"On date ";
                            d1.displayDate();
                            std::cout <<" ,"<<events[i].name<<" event has theese bookings:\n";
                            events[i].hall.showBoard();
                            showBookingsNotes(events[i].notes);
                        }else{counter++;}
                    }
                    if(counter == events.size())
                    std::cout <<"There are no events on this date\n";
                    continue;
                }else  // В този слуай потребителят е подал и име.
                {
                    Cut(input,1);
                    name = input;
                    int counter = 0;
                    /* Итерира през всички представления и проверява дали има такова на същата дата и име.
                        Ако да, показва запазените места, както и всички записани бележки(ако има такива). */
                    for(int i = 0; i<events.size();++i)
                    {
                        if(events[i].date == d1)
                        {
                            if(events[i].name == name)
                            {
                                std::cout <<"On date ";
                                d1.displayDate();
                                std::cout <<" ,"<<replace(events[i].name,'.',' ')<<" event has theese bookings:\n";
                                events[i].hall.showBoard();
                                showBookingsNotes(events[i].notes);
                                std::cout <<"\n";
                            }else {counter++;}
                        }else{counter++;}
                    }
                    if(counter == events.size())
                    std::cout <<"There is no such event on this date\n";
                    continue;
                }
            }else if(date!="")
            {
                name = date;
                int counter = 0;
                /* Итерира през всички представления и проверява дали има такова на същото име.
                        Ако да, показва запазените места, както и всички записани бележки(ако има такива). */
                for(int i = 0; i<events.size();++i)
                {
                    if(events[i].name == name)
                    {
                        std::cout <<"On date ";
                        events[i].date.displayDate();
                        std::cout <<", "<<name<<" event has theese bookings:\n";
                        events[i].hall.showBoard();
                        showBookingsNotes(events[i].notes);
                    } else {counter++;}
                }
                if(counter == events.size())
                std::cout <<"There is no event with this name\n";
            }else {std::cout <<"Invalid input!\n";}
            
        }else if (firstWord == "freeseats")
        {
            Cut(input,' ');
            std::string date = Extract(input,' ');
            // Проверявам дали датата е валидна преди създаването на обект.
            if(!isDateValid(date))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d1;
            stringToDate(date,d1);
            Cut(input,' ');
            std::string name = input;
            bool check = 0; 
            /*
                Итерира през всички представления и проверява дали има такова на същата дата със същото име.
                Ако да, показва броя на свободните места.
            */
            for (int i = 0; i <events.size();++i)
            {
                if(events[i].date == d1)
                {
                    std::cout <<events[i].name <<"\n";
                    if(events[i].name == name)
                    {
                        std::cout <<"The number of free seats is: "<<events[i].hall.GetFreeSeats()<<"\n";
                        events[i].hall.showFreeSeats();
                        check = 1;
                        break;
                    }
                }
            }
            if(!check)
            {
                check = 0;
                std::cout <<"Couldn't find the event\n";
            }
            continue;
        }else if (firstWord == "check") // Провеярва дали номера на билета е правилен.
        {
            Cut(input,' ');
            bool valid = 0;
            /* Итерира през всички билети(от вектора tickets) и проверява дали има съвпадение с номера на билета.
                Ако да, показва ред и място.
             */
            for(int i = 0; i <events.size();++i)
            {
                for(int j = 0; j <events[i].tickets.size(); ++j)
                {
                    if (input == events[i].tickets[j].getID())
                    {
                        std::cout <<"Your ticket number is valid!\n";
                        events[i].tickets[j].show_row_and_seat(events[i].tickets[j].getID()); //Отпечатва ред и място, извлечено от билета.
                        valid = 1;
                        break;
                    }
                }
                if(valid){break;}
            }
            if (!valid)
            {
                std::cout <<"Your ticket number isn't valid\n";
                continue;
            }else{ valid = 0; }
            
            continue;
        }
        else if(firstWord == "report")
        {  
            std::sort(events.begin(), events.end()); // Сортира вектора от представления.
            Cut(input,' ');
            std::string date = Extract(input,' ');
            if(!isDateValid(date))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d1;
            stringToDate(date,d1);
            Cut(input,' ');
            std::string date2 = Extract(input,' ');
            if(!isDateValid(date2))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d2;
            stringToDate(date2,d2);
            Cut(input,(int)date2.length());
            if(input.length()<2) // Ако дължината на input е по малка от 1, номера на залата не е включен.
            {
                /* 
                    Итерира през всички дати на представленията и проверява дали те са в желания период.
                    Ако да, показва боря на закупените билети и заетите места.
                */
                for(int i = 0; i <events.size();++i)
                    {
                        if(events[i].date==d1 || events[i].date==d2)
                        {
                            std::cout <<"\nFor "<<replace(events[i].name,'.',' ')<<" event(";
                            events[i].date.displayDate();
                            std::cout<<") the number of tickets bought is: ";
                            std::cout << events[i].hall.getBoughtTickets()<<"\n";
                            events[i].hall.showOccupiedSeats();
                        }else if(events[i].date > d1 && events[i].date < d2)
                        {
                            std::cout <<"\nFor "<<replace(events[i].name,'.',' ')<<" event (";
                            events[i].date.displayDate();
                            std::cout<<"), the number of tickets bought is: ";
                            std::cout << events[i].hall.getBoughtTickets()<<"\n";
                            events[i].hall.showOccupiedSeats();
                        }
                    }
                    continue;
            }else // Случай в който залата е включена.
            {
                Cut(input,1);
                int hallNum = charToint(input[0]);
                if(isHallvalid(hallNum))
                {
                    /* Итерира през всички дати като тябва залата да съвпада и проверява датата е в желания период.
                    Ако да, показва боря на закупените билети и заетите места.
                    */
                    for(int i = 0; i <events.size();++i)
                    {
                        if(events[i].hall.getHallN() == hallNum)
                        {
                            if(events[i].date==d1 || events[i].date==d2)
                            {
                                std::cout <<"\nFor "<<replace(events[i].name,'.',' ')<<" event(";
                                events[i].date.displayDate();
                                std::cout<<") the number of tickets bought is: ";
                                std::cout << events[i].hall.getBoughtTickets()<<"\n";
                                events[i].hall.showOccupiedSeats();
                            }else if(events[i].date > d1 && events[i].date < d2)
                            {
                                std::cout <<"\nFor "<<replace(events[i].name,'.',' ')<<" event(";
                                events[i].date.displayDate();
                                std::cout<<") the number of tickets bought is: ";
                                std::cout << events[i].hall.getBoughtTickets()<<"\n";
                                events[i].hall.showOccupiedSeats();
                            }
                        }
                    }
                }

            }
            
            continue;
        }else if(firstWord == "delete")
        {
            Cut(input,' ');
            std::string date = Extract(input,' ');
            if(!isDateValid(date))
            {
                std::cout <<"Wrong date!\n";
                continue;
            }
            Date d1;
            stringToDate(date,d1);
            Cut(input,' ');
            std::string name = input;
            bool flag = false;
            for (int i = 0 ; i < events.size(); ++i)
            {
                if(d1 == events[i].date)
                {
                    if(name == events[i].name)
                    {
                        events.erase(events.begin()+i);
                        flag = true;
                        std::cout <<"Event "<<name<<"("<<d1<<") has been successfully deleted\n";
                    }
                }
            }
            if (flag)
            {
                flag = false;
            }else {std::cout <<"Event on that date with this name does not exist\n";}
            continue;
        }
        else if(inputSave == "help") // Принтира възможните команди,които програмата поддържа.
        {
            std::cout <<"Theese are the available commands:\n"
            <<"addevent <date> <hall> <name>\n"
            <<"freeseats <date> <name>\n"
            <<"book <row> <seat> <date> <name> <note>\n"
            <<"unbook <row> <seat> <date> <name>\n"
            <<"buy <row> <seat> <date> <name>\n"
            <<"bookings [<date>] [<name>]\n"
            <<"check <code>\n"
            <<"report <from> <to> [<hall>]\n"
            <<"open |" " close |" " save |" " save as |" " help |" " exit\n"
            <<"Reminder: The dates should be in ISO 8601 format\n";
            continue;
        }else if(inputSave == "open")
        {
            std::cout <<"Type the name of the file you want to open \n";
            
            std::getline(std::cin,FilePath);
            FileName = filePath_converter(FilePath);
            //Ако такъв файл не съществува, създава нов

            
                
            MyFile.open(FilePath, std::ios::binary | std::ios::in);
            if (!MyFile.good())
            {
                MyFile.close();
                MyFile.open(FilePath, std::ios::binary | std::ios::out);
            }
            
            if(is_empty(MyFile))  // Проверяваме дали файлът е празен, за да не допуснем записването на нули(размери на вектори).
            {
                std::cout <<"File opened successfully\n";
                opened = true;
                MyFile.close();

                continue;
            }
            int size;
            MyFile.read((char*)&size, sizeof(int));
            Event a;
            for(int i = 0; i <size;++i)
            {
                a.read(MyFile);
                events.push_back(a);
                a.clear();
            }
            opened = true;
            std::cout <<"File opened successfully\n";
            MyFile.close(); 
            continue; 
        }else if(inputSave == "save") 
        { 
            if(opened) 
            { 
                MyFile.open(FilePath, std::ios::binary | std::ios::out | std::ios::trunc);
                if(!MyFile.is_open())
                {
                    std::cerr<<"Error/There is no file opened\n";
                    continue;
                }
                int size = events.size();
                if(size!=0)
                {
                    MyFile.write((char*)&size,sizeof(int));
                }
                for(int i = 0; i <size;++i)
                {
                    events[i].write(MyFile);
                }
                MyFile.close();
                std::cout <<"File saved successfully!\n";
                continue;
            }else
            {
                std::cout <<"You haven't opened a file\n";
                continue;
            }
            
        }else if(inputSave == "save as")
        {
            if(!opened)
            {
                std::cout <<"You haven't opened a file\n";
                continue;
            }
            std::fstream MyFile2;            
            std::cout <<"Type the file name, you want your file to be saved as:\n";
            std::getline(std::cin,FilePath);
            std::string FileName2 = filePath_converter(FilePath);
            
            MyFile2.open(FilePath, std::ios::binary | std::ios::out | std::ios::trunc);   
            
            if(!MyFile2)
            {
                std::cerr<<"File error <"<<FileName2<<">\n";
                continue;
            }
            int size = events.size(); 
            if(size != 0) 
            {
                MyFile2.write((char*)&size,sizeof(int));
                for(int i = 0; i <size;++i)
                {
                    events[i].write(MyFile2);
                }
            }
            MyFile2.close();
            std::cout <<"File successfully saved as: "<<FileName2<<"\n";
        }else if(inputSave == "close")
        {
            if(!opened)
            {
                std::cout <<"You haven't opened a file\n";
                continue;
            }
            opened = false;
            MyFile.close();
            FileName = "";
            FilePath = "";
            events.clear();
            std::cout <<"File successfully closed\n";

        }else if (inputSave == "exit")
        {
            if(MyFile.is_open())
            {
                std::cerr<<"Are you sure you want to exit, your file is still opened!  yes/no\n";
                std::string answer;
                do
                {
                    std::cin >>answer;
                } while (answer !="yes" || answer !="no");
                if(answer == "yes")
                {
                    std::cout <<"Successfully exited the program\n";
                    break;
                }else if (answer == "no")
                {
                    continue;
                }
            }else
            {
                std::cout <<"Successfully exited the program\n";
                break;
            }
        }
    }
}

