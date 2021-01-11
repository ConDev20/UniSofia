#include "../headers/tag/tag_map.h"

std::list<double> Tag_map::get_result()
{
    return calculate(type);
}
Tag_map::Tag_map(std::string type, double attribute)
{
    this->type = type;
    numAttribute = attribute;
}
std::list<double> Tag_map::calculate(std::string type)
{
    std::list<double>::iterator iter;
    if(type == "MAP-INC")
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter += numAttribute;
        }
        
    }else if(type == "MAP-MLT")
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter *= numAttribute;
        }
    }else
    {
        throw std::runtime_error("Unknown operation for class Map");
    }
    
    return values;
}