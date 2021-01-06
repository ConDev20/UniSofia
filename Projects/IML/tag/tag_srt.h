#ifndef _TAG_SRT
#define _TAG_SRT
#include "base_tag.h"
class Tag_srt : public Tag
{
    public:
    std::list<double> get_result();
    Tag_srt(std::string type, double attribute);
    Tag_srt(std::string type, std::string attribute);
    private:
    double numAttribute;
    std::string strAttribute;
    std::list<double> calculate(std::string type, double numAttribute, std::string strAttribute);
};

#endif