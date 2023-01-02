#include "Button.h"

Button::Button(Control* bound){
    Bound = bound;
}

void Button::Select()
{
    if (OnSelect != nullptr)
    {
        OnSelect(Bound);
    }
}

void Button::UnSelect()
{
    if (OnUnSelect != nullptr)
    {
        OnUnSelect(Bound);
    }
}

void Button::Click()
{
    if (OnClick != nullptr)
    {
        OnClick(Bound);
    }
}