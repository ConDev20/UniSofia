#include "../tag_factory.h"
#include "tag_map.h"
#include <iostream>
void print(std::list<double> const &list)
{
    std::cout << std::endl;
    for (auto const& i: list) {
        std::cout << i << " ";
    }
}
int main()
{
    Tag* tag = new Tag_map("MAP-INC",2);
    std::list<double> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    tag->appendList(a);
    print(tag->get_result());
    return 0;
}