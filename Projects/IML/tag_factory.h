#include "tag/base_tag.h" 
#include "tokenizer.h"
#include <cassert>
class Factory_Tag
{
    public:
    Tag* createTag(std::string oper)
    {
        if(oper == "MAP-INC" || oper == "MAP-MLT")
        {
            // Tag* tag = new Tag_map(oper)
        }

        
        
        
    }
}