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
    Tokenizer::Token token;
    void nextToken();
    void prevToken();
    Tag* readOpenTag();
    void readCloseTag(Tag* operand);
};
/*
    GRAMMAR
    expression := (Tag_expression|value), (expression |  "")
    Tag_expr := open_tag, [expression], close_tag
    value := number;
    open_tag := "<", string, [attribute], ">";
    close_tag := "<", "/" ,string, ">";
    atribute := ' " ', value | string ,' " ';
*/
#endif 