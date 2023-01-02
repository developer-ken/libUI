#include "LayoutSelectionMenu.h"

void LayoutSelectionMenu::Draw()
{
    PartialDraw();
}

void LayoutSelectionMenu::PartialDraw()
{
    int offset = (Page - 1) * 5;
    A.SetChild(Childs[offset]);
    B.SetChild(Childs[offset + 1]);
    C.SetChild(Childs[offset + 2]);
    D.SetChild(Childs[offset + 3]);
    E.SetChild(Childs[offset + 4]);
    
    A.Draw();
    B.Draw();
    C.Draw();
    D.Draw();
    E.Draw();
}

void LayoutSelectionMenu::ReInit(Ucglib *han, Box drawable_area){
    A.ReInit(han, Box{0, 0, drawable_area.w, drawable_area.h / 5});
    B.ReInit(han, Box{0, 1 * drawable_area.h / 5, drawable_area.w, drawable_area.h / 5});
    C.ReInit(han, Box{0, 2 * drawable_area.h / 5, drawable_area.w, drawable_area.h / 5});
    D.ReInit(han, Box{0, 3 * drawable_area.h / 5, drawable_area.w, drawable_area.h / 5});
    E.ReInit(han, Box{0, 4 * drawable_area.h / 5, drawable_area.w, drawable_area.h / 5});
    Control::ReInit(han, drawable_area);
}