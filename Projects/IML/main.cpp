#include "tokenizer.h"
#include "evaluator.h"
#include <iostream>
#include <vector>
// Opravi go da e po hubavo
void print(std::list<double> const &list)
{
    std::cout << std::endl;
    for (auto const& i: list) {
        std::cout << i << " ";
    }
}
int main()
{
    std::ifstream my_file;
    my_file.open("input.txt");
    if (!my_file) {
		std::cout << "File not created!";
	}
    Tokenizer tokenizer(my_file);
    while (tokenizer.moreTokens())
    {
        tokenizer.nextToken();
    }
    Evaluator something(tokenizer.getTokens());
    print(something.evaluate());
    my_file.close();
    return 0;
}