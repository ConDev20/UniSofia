#ifndef _TAG_MAP_H
#define _TAG_MAP_H
#include "base_tag.h"

class Tag_map : public Tag
{
    public:
    std::list<double> get_result();
    Tag_map(std::string type, double attribute);
    private:
    double numAttribute;
    std::list<double> calculate(std::string type);
};
#endif