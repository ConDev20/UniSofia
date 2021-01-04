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
void Evaluator::nextToken()
{
    // if(iter == storage.end())
    // {
    //     return;
    // }
    ++iter;
}
void Evaluator::prevToken()
{
    --iter;
}
/*
    expression := (Tag_expression|value),expression |  "" 
    Tag_expr := open_tag, [expression], close_tag
    value := number ;
    open_tag := "<", string, [attribute], ">";
    close_tag := "<", "/" ,string, ">";
    atribute := ' " ', value | string ,' " ';
*/
std::list<double> Evaluator::evaluate ()
{
    Tokenizer::Token token = *iter;
    std::list<double> values;
    /// Reading close tag
    if(token.type == Tokenizer::Token::openTag)
    {
        nextToken();
        if(token.type == Tokenizer::Token::Slash)
        {
            nextToken();
            assert(token.type == Tokenizer::Token::oper);
            nextToken();
            assert(token.type == Tokenizer::Token::closeTag);
            return values;
        }else {
            prevToken();
        }
    }
    
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
        /// Reading open tag
        assert(token.type == Tokenizer::Token::openTag); // <
        nextToken();
        assert(token.type == Tokenizer::Token::oper);
        std::string operType = token.text;
        nextToken();
        Tag* operand;
        if(token.type == Tokenizer::Token::doubleQuotes)
        {
            if(token.type == Tokenizer::Token::string)
            {   
                operand = // Suzday tag s factory podavayki string i string
            } else if(token.type == Tokenizer::Token::number) {
                operand = // Suzday tag s factory podavayji string i number
            }else{ assert(false); } /// Problem with attribute input
        }else{
            /// suzday tag samo sus string ?
        }
        nextToken();
        assert(token.type == Tokenizer::Token::closeTag);
        nextToken();
        operand->appendList(evaluate()); // 
        values.splice(values.end(), evaluate()); // 
        /// 
        // Трябва да проверя дали това работи само за nested tags. 
        // Ако 
        return operand->get_result();
        /// Ако са числа, push_back в листа на тага и след това append към values
        /// Ако е '<' и следващия елемент не е '/' => evaluate()
        /// Ako e letx, ще го мислим
        /// Ако е </ => четене на close tag и вкарване в стек
}
// }