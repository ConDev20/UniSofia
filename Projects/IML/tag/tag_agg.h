#ifndef _TAG_AGG_
#define _TAG_AGG
#include "base_tag.h"
class Tag_agg : public Tag
{
    public:
    std::list<double> get_result();
    Tag_agg(std::string type);
    private:
    std::string type;
    std::list<double> calculate(std::string type);
};
#endif