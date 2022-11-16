#pragma once

#include <LibGUI/Widget.h>

class MainWidget final : public GUI::Widget {
    C_OBJECT(MainWidget);
public:
    virtual ~MainWidget() override = default;
private:
    MainWidget();
};