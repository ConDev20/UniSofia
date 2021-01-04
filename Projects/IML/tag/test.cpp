#include <iostream>
using namespace std;
int mistery(int x)
{
    if (x == 0) return 0;
    if (x % 2) return 1+mistery(x-1);
    return 2*mistery(x/2);
}
int main()
    {

cout << mistery(17);
    return 0;
}
/*
    tag* tag_factory(string)
    {
        if(string = )
        {
            tag* tag = new tag();
        }
    }



    evaluate(tokenizer token)
    {
        Tokenizer::Token token = tokenizer.nextToken();
        assert(token.type == open_par);
        token = tokenizer.nextToken();
        assert(token.type == oper);
        tag* tag = new tag(token::type);
        token = tokenizer.nextToken();
        if(token. type == ")
        {
            token = tokenizer.nextToken();
            tag.attribute = token.attribute;
        }

        if(token == oper)
        {
            tag* tag = new tag(token::type);
        }

    }



*/