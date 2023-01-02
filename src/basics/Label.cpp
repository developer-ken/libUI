#include "Label.h"
#include "Ucglib.h"
#include "Control.h"
#include "logger.h"

void Label::Draw()
{
    if (LastText.equals(Text) && BackColor.Equals(_backColor) && MainColor.Equals(_mainColor))
    {
        LOG_DEBUG("Label::Draw() no need to redraw");
        return;
    }
    LOG_DEBUG("Label::Draw() Drawing...");
    Ucglib *pen = GetDrawingHandler();
    Box area = GetDrawableArea();
    int llen = LastText.length(),
        nlen = Text.length();
    if (ColorReverse)
        pen->setColor(255 - BackColor.r, 255 - BackColor.g, 255 - BackColor.b);
    else
        pen->setColor(BackColor.r, BackColor.g, BackColor.b);
    if (llen > nlen)
    {
        uint16_t startpos = nlen * FontWidth + area.x,
                 w = (llen - nlen) * FontWidth,
                 h = FontHeight + (3.5 / 16.0) * FontHeight;

        pen->drawBox(startpos, area.y, w, h);
    }
    String ttdraw = Text;
    for (int i = 0; i < Text.length(); i++)
    {
        if (LastText[i] != Text[i])
            pen->drawBox(area.x + i * FontWidth, area.y, FontWidth, FontHeight + (3.5 / 16.0) * FontHeight);
        else
            ttdraw[i] = ' ';
    }
    LastText = Text;
    _backColor = BackColor;
    _mainColor = MainColor;
    LOG_DEBUG("Drawing in the area: " + String(area.x) + ", " + String(area.y) + ", " + String(area.w) + ", " + String(area.h));
    LOG_DEBUG("Text: " + ttdraw);
    if (ColorReverse)
        pen->setColor(255 - MainColor.r, 255 - MainColor.g, 255 - MainColor.b);
    else
        pen->setColor(MainColor.r, MainColor.g, MainColor.b);
    pen->setFont(Font);
    for (int i = 0; i < Text.length(); i++)
    {
        if (ttdraw[i] != ' ')
            pen->drawGlyph(area.x + i * FontWidth, area.y + FontHeight, 0, ttdraw[i]);
    }
}

void Label::Clear()
{
    Box area = Control::GetDrawableArea();
    int llen = LastText.length(),
        tlen = Text.length();
    area.h = FontHeight + (3.5 / 16.0) * FontHeight;
    area.w = (llen > tlen ? llen : tlen) * FontWidth;
    Ucglib *pen = GetDrawingHandler();
    if (ColorReverse)
        pen->setColor(255 - BackColor.r, 255 - BackColor.g, 255 - BackColor.b);
    else
        pen->setColor(BackColor.r, BackColor.g, BackColor.b);
    pen->drawBox(area.x, area.y, area.w, area.h);
}

void Label::SetFont(LabelFont font)
{
    Font = font.font;
    FontWidth = font.width;
    FontHeight = font.height;
}