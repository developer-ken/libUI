#ifndef _H_PAGEMANAGER_
#define _H_PAGEMANAGER_

#include "Page.h"
class PageManager
{
public:
    static void Loop();
    static void ShowPage(Page *page);

private:
    static Page *currentPage;
};

#endif