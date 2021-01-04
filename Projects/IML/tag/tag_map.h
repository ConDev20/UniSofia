#include "base_tag.h"

class Tag_map : private Tag
{
    public:
    std::list<double> get_result(); // imashe tova vutre ? Type type
    void appendList(std::list<double>& tmp);
    private:
    Tag_map(Type type, double attribute);
    Tag_map() = delete; /// na random e slojeno
};