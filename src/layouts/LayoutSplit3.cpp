#include "LayoutSplit3.h"
#include "Ucglib.h"
#include "logger.h"

void LayoutSplit3::Draw()
{
    LOG_DEBUG("LayoutSplit3::Draw() drawing frames");
    Clear();
    Ucglib *pen = GetDrawingHandler();
    Box area = GetDrawableArea();

    LOG_DEBUG("Drawable area: " + String(area.x) + ", " + String(area.y) + ", " + String(area.w) + ", " + String(area.h));
    if (ColorReverse)
        pen->setColor(255 - MainColor.r, 255 - MainColor.g, 255 - MainColor.b);
    else
        pen->setColor(MainColor.r, MainColor.g, MainColor.b);
    pen->drawHLine(area.x, LowerLeft.GetDrawableAreaNoPadding().y, DrawableArea.w);
    pen->drawVLine(LowerRight.GetDrawableAreaNoPadding().x, LowerRight.GetDrawableAreaNoPadding().y, LowerRight.GetDrawableAreaNoPadding().h);
    PartialDraw();
}

void LayoutSplit3::PartialDraw()
{
    LOG_DEBUG("LayoutSplit3::PartialDraw() drawing children");
    Upper.Draw();
    LowerLeft.Draw();
    LowerRight.Draw();
}

void LayoutSplit3::ReInit(Ucglib *han, Box drawable_area)
{
    Upper.ReInit(han, Box{0, 0, drawable_area.w, (int32_t)(drawable_area.h * _vscale - 1)});
    LowerLeft.ReInit(han, Box{0, (int32_t)(drawable_area.h * _vscale + 1),
                              (int32_t)(drawable_area.w * (1 - _hscale) - 1), (int32_t)(drawable_area.h * (1 - _vscale) - 1)});
    LowerRight.ReInit(han, Box{(int32_t)(drawable_area.w * _hscale + 1), (int32_t)(drawable_area.h * _vscale + 1),
                               (int32_t)(drawable_area.w * (1 - _hscale) - 1), (int32_t)(drawable_area.h * (1 - _vscale) - 1)});
    Control::ReInit(han, drawable_area);
}