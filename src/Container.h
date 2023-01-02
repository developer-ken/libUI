#ifndef _H_CONTAINER_
#define _H_CONTAINER_
#include "Control.h"
#include "Ucglib.h"
class Container : public Control
{
public:
    Container(){};
    Container(Ucglib *ucg, Box area) : Control(ucg, area){};
    void Draw();
    void SetChild(Control *c);
    Control *Child;
    uint32_t PaddingLeft = 2, PaddingTop = 2;
    Box GetDrawableArea() override;
    void Clear() override;
    Box GetDrawableAreaNoPadding();
    void ReInit(Ucglib *han, Box drawable_area) override;
};
#endif