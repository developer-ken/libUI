#ifndef _H_LABELBUTTON_
#define _H_LABELBUTTON_
#include "Button.h"
#include "basics/Label.h"
#include "Ucglib.h"

class LabelButton : public Button, public Label
{
public:
    LabelButton() : Button(this), Label(){};
    LabelButton(Ucglib *ucg, Box area) : Button(this), Label(ucg, area){};
    void Draw() override { Label::Draw(); };
};
#endif