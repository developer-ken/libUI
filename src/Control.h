#ifndef _H_CONTROL_
#define _H_CONTROL_
#include <cstdint>
#include "Ucglib.h"

struct Box
{
public:
    int32_t x;
    int32_t y;
    int32_t w;
    int32_t h;
    inline bool IsValid()
    {
        return w > 0 && h > 0;
    }
} typedef Box;

struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    bool Equals(Color c)
    {
        return (r == c.r) && (g == c.g) && (b == c.b);
    }
} typedef Color;

inline Box operator+(const Box, const Box);
Box operator-(const Box, const Box);
bool operator==(const Color, const Color);

class Control
{
public:
    Control() { DrawingHandler = nullptr; };
    Control(Ucglib *han, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
    Control(Ucglib *han, Box drawable_area);
    Box DrawableArea;
    virtual Box GetDrawableArea();
    Ucglib *GetDrawingHandler();
    virtual void Draw() = 0;
    virtual void Clear();
    Color MainColor = Color{255, 255, 255};
    Color BackColor = Color{0, 0, 0};
    bool CheckBoxValid(Box child, Box limit);
    Control *Parent;
    Ucglib *DrawingHandler;
    virtual void ReInit(Ucglib *han, Box drawable_area);
    static bool ColorReverse;

protected:
    Color _mainColor = Color{255, 255, 255};
    Color _backColor = Color{0, 0, 0};
};
#endif