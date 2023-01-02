#ifndef _H_LABLE_
#define _H_LABLE_
#include "Control.h"
#include "Ucglib.h"

struct LabelFont
{
    const unsigned char *font;
    uint8_t height;
    uint8_t width;
} typedef LabelFont;

class Label : public Control
{
public:
    Label() : Control(){};
    Label(Ucglib *ucg, Box area) : Control(ucg, area){};
    void Draw() override;
    void Clear() override;
    void SetFont(LabelFont);
    String Text, LastText;
    uint8_t FontHeight = 16, FontWidth = 11 - 1;
    const unsigned char *Font = ucg_font_courB10_tr;
};

class Fonts
{
    public:
    Fonts(){};
    LabelFont FontB08 = {ucg_font_courB08_tr, 11, 8};
    LabelFont FontB10 = {ucg_font_courB10_tr, 16, 11};
    LabelFont FontB12 = {ucg_font_courB12_tr, 17, 12};
    LabelFont FontB14 = {ucg_font_courB14_tr, 20, 12};
    LabelFont FontB18 = {ucg_font_courB18_tr, 26, 17};
    LabelFont FontB24 = {ucg_font_courB24_tr, 33, 22};
};
#endif