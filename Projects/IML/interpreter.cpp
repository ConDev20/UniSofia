#include "interpreter.h"
Interpreter::Interpreter(std::string input, std::string output) 
{
    file_input  = input;
    file_output = output;
}
void Interpreter::interpretate()
{
    std::ifstream my_file;
    my_file.open(file_input);
    if (!my_file) {
		std::cout << "File not created!";
	}
    Tokenizer tokenizer(my_file);
    while (tokenizer.moreTokens())
    {
        tokenizer.nextToken();
    }
    Evaluator something(tokenizer.getTokens());
    my_file.close();
    std::ofstream myfile;
    myfile.open(file_output);
    if (!myfile) {
		std::cout << "File not created!";
	}
    try
    {
        printToFile(something.evaluate(), myfile);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    myfile.close();

}
void Interpreter::printToFile(std::list<double> const &list, std::ofstream& myfile) const
{
    for (auto const& i: list) {
        myfile << i << " ";
    }
}