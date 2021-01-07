#ifndef _TAG_A_H
#define _TAG_A_H
#include "base_tag.h"
class Tag_A : public Tag 
{
    protected:
    std::string attribute;
    double numAttribute;
    virtual void calculate(std::string type, double numAttribute, std::string attribute);
};
#endif