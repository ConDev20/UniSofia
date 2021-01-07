#ifndef _TAG_FACTORY_H
#define _TAG_FACTORY_H
#include "tag/tag_agg.h"
#include "tag/tag_map.h"
#include "tag/tag_srt.h"
#include "tokenizer.h"
#include <cassert>
class Factory_Tag
{
    public:
    static Tag* createTag(std::string oper)
    {
        Tag* tag = nullptr;
        std::string firstThree = oper.substr(0, 3);
        if(firstThree == "SRT")
        {
            tag = new Tag_srt(oper,-1);  /// FIX THIS
        } else if (firstThree == "AGG")
        {
            tag = new Tag_agg(oper);
        }
        return tag;
    }
    static Tag* createAtrTag(std::string oper,std::string attribute)
    {
        Tag* tag = new Tag_srt(oper,attribute);
        return tag;
    }
    static Tag* createNumAtrTag(std::string oper, double attribute)
    {
        Tag *tag = nullptr;
        std::string firstThree = oper.substr(0, 3);
        if(firstThree == "SRT")
        {
            tag = new Tag_srt (oper,attribute);
        } else if (firstThree == "MAP")
        {
            tag = new Tag_map(oper, attribute);
        }
        return tag;
    }
};
#endif