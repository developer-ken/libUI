#include "Container.h"
#include "Ucglib.h"
#include "logger.h"

void Container::Draw()
{
    LOG_DEBUG("Container::Draw() drawing children");
    if (Child == nullptr)
        return;
    if (CheckBoxValid(Child->GetDrawableArea(), GetDrawableArea()))
    {
        LOG_DEBUG("Prechek passed, draw...");
        Child->Draw();
    }
    else
    {
        Box newbox = Child->DrawableArea - Box{0, 0, DrawableArea.w, DrawableArea.h};
        if (newbox.IsValid())
        {
#ifdef DEBUG
            Box cbarea = Child->GetDrawableArea();
            LOG_DEBUG("Box invalid: " + String(cbarea.x) + ", " + String(cbarea.y) + ", " + String(cbarea.w) + ", " + String(cbarea.h));
            LOG_DEBUG("Corrected box, draw...");
#endif
            Child->DrawableArea = newbox;
            Child->Draw();
        }
    }
}

void Container::SetChild(Control *c)
{
    if (Child != c)
        Control::Clear();
    c->Parent = this;
    Child = c;
}

Box Container::GetDrawableArea()
{
    Box area = GetDrawableAreaNoPadding();
    return Box{area.x + (int32_t)PaddingLeft, area.y + (int32_t)PaddingTop, area.w - 2 * (int32_t)PaddingLeft, area.h - 2 * (int32_t)PaddingTop};
}

Box Container::GetDrawableAreaNoPadding()
{
    return Control::GetDrawableArea();
}

void Container::Clear()
{
    if (Child == nullptr)
    {
        Control::Clear();
    }
    Child->Clear();
}

void Container::ReInit(Ucglib *han, Box drawable_area)
{
    Child->ReInit(han, drawable_area);
    Control::ReInit(han, drawable_area);
}