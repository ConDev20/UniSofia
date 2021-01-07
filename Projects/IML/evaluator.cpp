#include "evaluator.h"
#include <assert.h>
Evaluator::Evaluator(std::list<Tokenizer::Token> tokens)
{
    storage = tokens;
    iter = storage.begin();
    token = *iter;
}
void Evaluator::displayStorage()
{
    auto iter = storage.begin();
    for (iter ; iter != storage.end(); ++iter)
    {
        std::cout <<"[ " << *iter << " ] ";
        std::cout << std::endl;
    }
}
void Evaluator::nextToken()
{
    if(iter == storage.end()){return;}
    iter++;
    if(iter == storage.end()){return;}
    token = *(iter);
}
void Evaluator::prevToken()
{
    token = *(--iter);
}
std::list<double> Evaluator::evaluate()
{ 
    std::list<double> values;
    /// Base case
    if(iter == storage.end())
    {
        return values;
    }
    /// Base case
    if(token.type == Tokenizer::Token::openTag)
    {
        nextToken();
        if(token.type == Tokenizer::Token::Slash)
        {
            prevToken();
            return values;
        }
        prevToken();
    }
    /// Reading numbers
    if(token.type == Tokenizer::Token::number)
    {
        values.push_back(token.numval);
        nextToken();
        for (double value : evaluate())
        {
            values.push_back(value);
        }
        return values;
    }
    Tag* operand = readOpenTag();
    operand->appendList(evaluate());
    readCloseTag(operand);
    values.splice(values.end(), operand->get_result());
    delete operand;
    values.splice(values.end(), evaluate());
    return values;
}
Tag* Evaluator::readOpenTag()
{
    Tag* operand;
    assert(token.type == Tokenizer::Token::openTag);
    nextToken();
    assert(token.type == Tokenizer::Token::oper);
    std::string operType = token.text;
    nextToken();
    
    if(token.type == Tokenizer::Token::doubleQuotes)
    {
        nextToken();
        if(token.type == Tokenizer::Token::string)
        {   
            operand = Factory_Tag::createAtrTag(operType,token.text);
        } else if(token.type == Tokenizer::Token::number) {
            operand = Factory_Tag::createNumAtrTag(operType,token.numval);
        } else { assert(false); } /// Problem with attribute input
        nextToken();
        assert(token.type == Tokenizer::Token::doubleQuotes);
    }else{
        prevToken();
        operand = Factory_Tag::createTag(operType);
    }
    nextToken();
    assert(token.type == Tokenizer::Token::closeTag);
    nextToken();
    return operand;
}
void Evaluator::readCloseTag(Tag* operand)
{   
    assert(token.type == Tokenizer::Token::openTag);
    nextToken();
    assert(token.type == Tokenizer::Token::Slash);
    nextToken();
    if(token.text != operand->getType()) throw std::runtime_error("Close tag doesn't correspond to Open tag");
    nextToken();
    assert(token.type == Tokenizer::Token::closeTag);
    nextToken();
}