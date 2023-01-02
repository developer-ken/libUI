#include "PageManager.h"
#include "Page.h"

Page *PageManager::currentPage = nullptr;

void PageManager::Loop()
{
    if (currentPage != nullptr)
    {
        currentPage->Loop();
    }
}

void PageManager::ShowPage(Page *page)
{
    if (currentPage != nullptr)
    {
        currentPage->BringToBack();
    }
    currentPage = page;
    if (!currentPage->IsSetedup)
        currentPage->Setup();
    currentPage->BringToFront();
}