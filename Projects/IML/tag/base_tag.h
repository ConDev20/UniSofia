#ifndef _BASE_TAG_H
#define _BASE_TAG_H
#include <list>
#include <assert.h>
#include <string>
class Tag {

    public:
    virtual std::list<double> get_result() = 0;
    virtual std::list<double> calculate(std::string type) = 0;
    void appendList(std::list<double> tmp)
    {
        values.splice(values.end(), tmp);
    }
    std::string getType(){ return type; }
    protected:
    std::list<double> values;
    std::string type;
};
#endif