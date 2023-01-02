#ifndef _H_MAINLAYOUT_
#define _H_MAINLAYOUT_
#include "Layout.h"
#include "Container.h"
class LayoutSplit3 : public Layout
{
public:
    LayoutSplit3(Ucglib *han, Box drawable_area, double vscale = 0.5, double hscale = 0.5)
        : Layout(han, drawable_area),
          Upper(han, Box{0, 0, drawable_area.w, (int32_t)(drawable_area.h * vscale - 1)}),
          LowerLeft(han, Box{0, (int32_t)(drawable_area.h * vscale + 1),
                             (int32_t)(drawable_area.w * (1 - hscale) - 1), (int32_t)(drawable_area.h * (1 - vscale) - 1)}),
          LowerRight(han, Box{(int32_t)(drawable_area.w * hscale + 1), (int32_t)(drawable_area.h * vscale + 1),
                              (int32_t)(drawable_area.w * (1 - hscale) - 1), (int32_t)(drawable_area.h * (1 - vscale) - 1)})
    {
        Upper.PaddingLeft =
            Upper.PaddingTop =
                LowerLeft.PaddingLeft =
                    LowerLeft.PaddingTop =
                        LowerRight.PaddingLeft =
                            LowerRight.PaddingTop = 4;
        Upper.Parent = this;
        LowerLeft.Parent = this;
        LowerRight.Parent = this;
        _vscale = vscale;
        _hscale = hscale;
    };
    void Draw() override;
    void PartialDraw() override;
    void ReInit(Ucglib *han, Box drawable_area) override;

    Container Upper, LowerLeft, LowerRight;
    double _vscale, _hscale;
};
#endif