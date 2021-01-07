#ifndef _TAG_AGG_H
#define _TAG_AGG_H
#include "base_tag.h"
class Tag_agg : public Tag
{
    public:
    std::list<double> get_result();
    Tag_agg(std::string type);
    private:
    std::list<double> calculate(std::string type);
};
#endif