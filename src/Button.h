#ifndef _H_BUTTON_
#define _H_BUTTON_
#include "Control.h"
class Button
{
public:
    Button(Control *);
    void Click();
    void Select();
    void UnSelect();
    void (*OnClick)(Control *);
    void (*OnSelect)(Control *);
    void (*OnUnSelect)(Control *);
    Control *Bound;
};
#endif