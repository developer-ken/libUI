#ifndef _H_PAGE_
#define _H_PAGE_
class Page
{
public:
    Page(){};
    virtual void Setup() = 0;
    virtual void Loop() = 0;
    virtual void BringToBack() = 0;
    virtual void BringToFront() = 0;
    bool IsSetedup = false;
};
#endif