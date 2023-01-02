#ifndef _H_LAYOUT_
#define _H_LAYOUT_
#include "Control.h"
#include "Ucglib.h"
class Layout : public Control
{
public:
    Layout(){};
    Layout(Ucglib *ucg, Box area) : Control(ucg, area){};
    virtual void PartialDraw() = 0;
};
#endif