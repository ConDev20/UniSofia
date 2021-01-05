#ifndef _EVALUATOR_H
#define _EVALUATOR_H
#include "tag_factory.h"
#include "tokenizer.h"
#include "tag/base_tag.h"
class Evaluator
{
    public:
    Evaluator(std::list<Tokenizer::Token> tokens);
    void displayStorage();
    std::list<double> evaluate();

    private:
    std::list<Tokenizer::Token> storage;
    std::list<Tokenizer::Token>::iterator iter;
    void nextToken(Tokenizer::Token& token);
    void prevToken(Tokenizer::Token& token);
    void readOpenTag(Tag* operand);
};

#endif 