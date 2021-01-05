#ifndef _BASE_TAG
#define _BASE_TAG
#include <list>
#include <assert.h>
#include "types.h"
#include <string>
class Tag {

    public:
    virtual std::list<double> get_result() = 0;
    void appendList(std::list<double> tmp)
    {
        values.splice(values.end(), tmp);
    }
    //values.splice(values.end(), tmp);
    protected:
    std::list<double> values;
};
#endif