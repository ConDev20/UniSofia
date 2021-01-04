#include "tag_map.h"

std::list<double> Tag_map::get_result()
{
    return values;
}
void Tag_map::appendList(std::list<double>& tmp)
{
    values.splice(values.end(), tmp);
}
Tag_map::Tag_map(Type type, double attribute)
{
    std::list<double>::iterator iter;
    if(type == MAP_INC)
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter += attribute;
        }
        
    }else if(type == MAP_MLT)
    {
        for (iter = values.begin(); iter != values.end(); ++iter)
        {
            *iter *= attribute;
        }
    }
}