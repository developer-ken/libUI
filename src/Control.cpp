#include "Ucglib.h"
#include "Control.h"
#include "logger.h"

bool Control::ColorReverse = false;

Control::Control(Ucglib *han, uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
    DrawingHandler = han;
    DrawableArea.x = x;
    DrawableArea.y = y;
    DrawableArea.w = w;
    DrawableArea.h = h;
}

Control::Control(Ucglib *han, Box drawable_area)
{
    DrawingHandler = han;
    DrawableArea = drawable_area;
}

void Control::ReInit(Ucglib *han, Box drawable_area)
{
    DrawingHandler = han;
    DrawableArea = drawable_area;
}

/// @brief 获得ab区域相交的部分
/// @param a
/// @param b
/// @return 相交的区域
Box operator-(const Box a, const Box b)
{
    int32_t a_top = a.y,
            a_left = a.x,
            a_bottom = a.y + a.h,
            a_right = a.x + a.w;
    int32_t b_top = b.y,
            b_left = b.x,
            b_bottom = b.y + b.h,
            b_right = b.x + b.w;

    int32_t r_bottom = a_bottom < b_bottom ? a_bottom : b_bottom,
            r_right = a_right < b_right ? a_right : b_right;

    return Box{
        x : a_left < b_left ? b_left : a_left,
        y : a_top < b_top ? b_top : a_top,
        w : r_right - (a_left < b_left ? b_left : a_left),
        h : r_bottom - (a_top < b_top ? b_top : a_top)
    };
}

/// @brief 生成b区域放入a区域之后的绝对位置
/// @param a 父区域
/// @param b 子区域
/// @return 使用绝对位置信息的新区域
inline Box operator+(const Box a, const Box b)
{
    Box newArea = {
        x : a.x + b.x,
        y : a.y + b.y,
        w : b.w,
        h : b.h
    };
    return newArea - a;
}

inline bool operator==(const Color a, const Color b)
{
    return (a.r == b.r) && (a.g == b.g) && (a.b == b.b);
}

Box Control::GetDrawableArea()
{
    if (Parent != nullptr)
    {
        Box p = Parent->GetDrawableArea();
        return p + DrawableArea;
    }
    else
    {
        return DrawableArea;
    }
}

Ucglib *Control::GetDrawingHandler()
{
    Box area = this->GetDrawableArea();
    DrawingHandler->setClipRange(area.x, area.y, area.w + 1, area.h + 1);
    return DrawingHandler;
}

bool Control::CheckBoxValid(Box child, Box limit)
{
    return ((child.x >= limit.x) && (child.x <= limit.x + limit.w) && (child.y >= limit.y) && (child.y <= limit.y + limit.h));
}

void Control::Clear()
{
    Ucglib *pen = this->GetDrawingHandler();
    Box area = this->GetDrawableArea();
    LOG_DEBUG("Control::Clear() Clear the area: " + String(area.x) + ", " + String(area.y) + ", " + String(area.w) + ", " + String(area.h));
    if (ColorReverse)
        pen->setColor(255 - BackColor.r, 255 - BackColor.g, 255 - BackColor.b);
    else
        pen->setColor(BackColor.r, BackColor.g, BackColor.b);
    pen->drawBox(area.x, area.y, area.w, area.h);
}