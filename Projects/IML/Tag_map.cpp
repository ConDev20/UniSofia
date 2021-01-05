#include "tag/tag_map.h"

std::list<double> Tag_map::get_result()
{
    calculate(type,attribute);
    return values;
}
Tag_map::Tag_map(std::string type, double attribute)
{
    this->type = type;
    this->attribute = attribute;
}
void Tag_map::calculate(std::string type, double attribute)
{
    std::list<double>::iterator iter;
    if(type == "MAP-INC")
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter += attribute;
        }
        
    }else if(type == "MAP-MLT")
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter *= attribute;
        }
    }
}