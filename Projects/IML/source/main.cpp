#include "../headers/interpreter.h"
int main()
{
    Interpreter program("../IO files/input.txt","../IO files/output.txt");
    program.interpretate();
    return 0;
}