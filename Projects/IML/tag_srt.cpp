#include "tag/tag_srt.h"
#include <set>
std::list<double> Tag_srt::get_result()
{
    return calculate(type);
}
Tag_srt::Tag_srt(std::string type, double attribute)
{
    this->type = type;
    numAttribute = attribute;
    strAttribute = "";
}
Tag_srt::Tag_srt(std::string type, std::string attribute)
{
    this->type = type;
    numAttribute = -1;
    strAttribute = attribute;
}
std::list<double> Tag_srt::calculate(std::string type)
{
    if(type == "SRT-REV")
    {
        values.reverse();
    } else if(type == "SRT-ORD")
    {   
        if(strAttribute == "ASC")
        {
            values.sort();
        } else if(strAttribute == "DSC")
        {
            values.sort();
            values.reverse();
        } else { assert (false); }
    } else if (type == "SRT-SLC")
    {
        std::list<double>::iterator iter = values.begin();
        assert(numAttribute >=0);
        for (size_t i = 0; i < numAttribute; ++i) {
            iter++;
        }
        values.erase(values.begin(),iter);
    } else if (type == "SRT-DST")
    {   
        std::list<double>::iterator iter = values.begin();
        std::set<double> elements;
        while (iter != values.end()) {
            if (elements.find(*iter) != elements.end())
                iter = values.erase(iter);
            else {
                elements.insert(*iter);
                ++iter;
            }
        }
    }
    return values;
}