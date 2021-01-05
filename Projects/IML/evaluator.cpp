#include "evaluator.h"
#include <assert.h>
//  Evaluator(std::list<Tokenizer::Token> tokens);
Evaluator::Evaluator(std::list<Tokenizer::Token> tokens)
{
    storage = tokens;
    iter = storage.begin();
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
void Evaluator::nextToken(Tokenizer::Token& token)
{
    token = *(++iter);
}
void Evaluator::prevToken(Tokenizer::Token& token)
{
    token = *(--iter);
}
/*
    expression := (Tag_expression|value),expression |  "" 
    Tag_expr := open_tag, [expression], close_tag
    value := number ;
    open_tag := "<", string, [attribute], ">";
    close_tag := "<", "/" ,string, ">";
    atribute := ' " ', value | string ,' " ';
*/
void Evaluator::readOpenTag(Tag* operand)
{
        Tokenizer::Token token = *iter;
        assert(token.type == Tokenizer::Token::openTag); // <
        nextToken(token);
        assert(token.type == Tokenizer::Token::oper);
        std::string operType = token.text;
        nextToken(token);
        
        if(token.type == Tokenizer::Token::doubleQuotes)
        {
            nextToken(token);
            if(token.type == Tokenizer::Token::string)
            {   
                operand = Factory_Tag::createAtrTag(operType,token.text);
            } else if(token.type == Tokenizer::Token::number) {
                operand = Factory_Tag::createNumAtrTag(operType,token.numval);
            } else { assert(false); } /// Problem with attribute input
            nextToken(token);
            assert(token.type == Tokenizer::Token::doubleQuotes);
        }else{
            prevToken(token);
            operand = Factory_Tag::createTag(operType);
        }
        nextToken(token);
        assert(token.type == Tokenizer::Token::closeTag);
}
std::list<double> Evaluator::evaluate()
{
    Tokenizer::Token token = *iter;
    std::list<double> values;
    /// Reading close tag
    if(iter == storage.end()) // Ne bi trqbvalo da vliza tuk
    {
        return values;
    }
    // Reading close tag
    if(token.type == Tokenizer::Token::openTag)
    {
        nextToken(token);
        if(token.type == Tokenizer::Token::Slash)
        {
            /// prevToken();
            /// return values;
            /// 
            nextToken(token);
            assert(token.type == Tokenizer::Token::oper);
            nextToken(token);
            assert(token.type == Tokenizer::Token::closeTag);
            return values;
        }else {
            prevToken(token);
        }
    }
    // End of reading close tag
    if(token.type == Tokenizer::Token::number)
    {
        values.push_back(token.numval);
        nextToken(token);
        for (double value : evaluate())
        {
            values.push_back(value);
        }
        return values;
    }
        /// Reading open tag
        Tag* operand;
        readOpenTag(operand);
        /// End of reading open tag
        nextToken(token);
        operand->appendList(evaluate()); // 
        values.splice(values.end(), operand->get_result());
        delete operand;
        return values;
}