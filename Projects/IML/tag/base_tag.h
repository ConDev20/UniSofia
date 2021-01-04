#ifndef _BASE_TAG
#define _BASE_TAG
#include <list>
#include "types.h"
class Tag {

    public:
    virtual std::list<double> get_result() = 0;
    virtual void appendList(std::list<double> tmp) = 0;
    protected:
    std::list<double> values;
};
#endif