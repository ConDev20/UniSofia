#include "tokenizer.h"
#include <cassert>
Tokenizer::Tokenizer(std::istream &_in):in(_in){}
void Tokenizer::nextToken()
{   
    Tokenizer::Token result({Tokenizer::Token::TokenType::unknown,-1.00,"NULL"});
    clearWhiteSpace();
    
    if(in.eof() )
    {
        return;
    }
    char c = in.peek();
    
    if(std::isdigit(c) || c == '-')
    {
        result.type = Tokenizer::Token::number;
        in>>result.numval;
    }
    else if(c == '<')
    {
        result.type = Tokenizer::Token::openTag;
        result.text = in.get();
    }else if(c == '>')
    {
        result.type = Tokenizer::Token::closeTag;
        result.text = in.get();//in >> result.c;
    }else if (c == '/')
    {
        result.type = Tokenizer::Token::Slash;
        result.text = in.get();//in >> result.c;
    }else if(c >= 65 && c <=90)
    {
        if(isString) {
            result.type = Tokenizer::Token::string;
        } else {
            result.type = Tokenizer::Token::oper;
        }
        result.text = "";
        while ((c >= 65 && c <=90) || c == '-')
        {
            result.text += in.get();
            c = in.peek();
        }
    }else if(c == '"')
    {
        result.type = Tokenizer::Token::doubleQuotes;
        result.text = in.get();//in >> result.c;
        isString == false ? isString = true : isString = false;
    }else {
        assert(false);
    }
    storage.push_back(result);
}
bool Tokenizer::moreTokens()
{
    return !in.eof();
}
void Tokenizer::clearWhiteSpace()
{
    while (!in.eof() && in.peek() <= 32)
    {
        in.get();
    }
}
std::list<Tokenizer::Token> Tokenizer::getTokens() const
{
    return storage;
}
std::ostream& operator<<(std::ostream& os, const Tokenizer::Token& result)
{
    os << result.type << " ,";
    os << result.numval<< " ,";
    os << result.text<< " ,";
    // os << result.num_attribute<< " ,";

    return os;
}
// Tokenizer& operator>>(Tokenizer& tokenizer, Tokenizer::Token& result)
// {
//     result = tokenizer.nextToken();
//     return tokenizer;
// }
void Tokenizer::displayStorage() const
{
    auto iter = storage.begin();
    for (iter ; iter != storage.end(); ++iter)
    {
        std::cout <<"[ " << *iter << " ] ";
        std::cout << std::endl;
    }
}