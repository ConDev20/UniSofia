#ifndef _TAG_MAP_
#define _TAG_MAP_
#include "base_tag.h"

class Tag_map : public Tag
{
    public:
    std::list<double> get_result();
    Tag_map(std::string type, double attribute);
    private:
    std::string type;
    double attribute;
    void calculate(std::string type, double attribute);
};
#endif