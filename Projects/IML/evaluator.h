#ifndef _EVALUATOR_H
#define _EVALUATOR_H
#include "tokenizer.h"
#include "tag/base_tag.h"
class Evaluator
{
    public:
    Evaluator(std::list<Tokenizer::Token> tokens);
    void displayStorage();
    private:
    std::list<Tokenizer::Token> storage;
    std::list<Tokenizer::Token>::iterator iter;
    std::list<double> evaluate();
    void nextToken();
    void prevToken();
};

#endif 