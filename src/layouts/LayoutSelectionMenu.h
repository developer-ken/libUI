#ifndef _H_LAYPUTSELECTIONMENU_
#define _H_LAYPUTSELECTIONMENU_
#include "Layout.h"
#include "Container.h"
#include <vector>

class LayoutSelectionMenu : public Layout
{
public:
    LayoutSelectionMenu(){};
    LayoutSelectionMenu(Ucglib *ucg, Box area)
        : Layout(ucg, area),
          A(ucg, Box{0, 0, area.w, area.h / 5}),
          B(ucg, Box{0, 1 * area.h / 5, area.w, area.h / 5}),
          C(ucg, Box{0, 2 * area.h / 5, area.w, area.h / 5}),
          D(ucg, Box{0, 3 * area.h / 5, area.w, area.h / 5}),
          E(ucg, Box{0, 4 * area.h / 5, area.w, area.h / 5})
    {
        A.Parent = this;
        B.Parent = this;
        C.Parent = this;
        D.Parent = this;
        E.Parent = this;
    };
    void Draw() override;
    void PartialDraw() override;
    void ReInit(Ucglib *han, Box drawable_area) override;
    void SetChilds(std::vector<Control *>);
    std::vector<Control *> Childs;
    Container A, B, C, D, E;
    uint32_t Page = 1;
};
#endif