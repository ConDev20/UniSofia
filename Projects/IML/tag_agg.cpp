#include "tag/tag_agg.h"
std::list<double> Tag_agg::get_result()
{
    return calculate(type);
}
Tag_agg::Tag_agg(std::string type)
{
    this->type = type;
}
std::list<double> Tag_agg::calculate(std::string type)
{
    double result = 0;
    if(type == "AGG-SUM") {
        for (double num : values)
        {
            result += num;
        }
    } else if(type == "AGG-PRO") {
        result += 1;
        for (double num : values)
        {
            result *= num;
        }
    } else if(type == "AGG-AVG") {
        int counter = 0;
        for (double num : values)
        {
            counter++;
            result += num;
        }
        result /= counter;
    } else if(type == "AGG-FST") {
        result = values.front();
    } else if(type == "AGG-LST") {
        result = values.back();
    } else {
        assert(false);
    }
    std::list<double> list(1,result); // CHECK IF GOOD
    return list;
}