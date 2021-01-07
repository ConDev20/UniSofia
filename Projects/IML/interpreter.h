#ifndef _INTERPRETER_H
#define _INTERPRETER_H
#include "tokenizer.h"
#include "evaluator.h"
class Interpreter
{
    public:
    Interpreter(std::string input, std::string output);
    void interpretate();
    private:
    std::string file_input;
    std::string file_output;
    void printToFile(std::list<double> const &list, std::ofstream& myfile) const;
};
#endif