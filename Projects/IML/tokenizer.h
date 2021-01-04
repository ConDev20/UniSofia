#ifndef _TOKENIZER_H
#define _TOKENIZER_H
// #include "evaluator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
class Tokenizer
{
    public:
    struct Token
    {
        enum TokenType 
        {
            openTag,
            closeTag,
            number,
            oper,
            Slash,
            doubleQuotes,
            string,
            unknown
        };
        TokenType type;
        double numval;
        std::string text;
    };
    Tokenizer(std::istream&);
    void nextToken();
    bool moreTokens();
    void displayStorage() const;
    std::list<Tokenizer::Token> getTokens() const;
    private:
    std::list<Tokenizer::Token> storage;
    std::istream &in;
    void clearWhiteSpace();
};
Tokenizer& operator>>(Tokenizer&, Tokenizer::Token&);
std::ostream& operator<<(std::ostream& os,const Tokenizer::Token& result);
#endif