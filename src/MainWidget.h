#pragma once

#include <LibGUI/Widget.h>

namespace IRCClient {

class MainWidget final : public GUI::Widget {
C_OBJECT(MainWidget);
public:
    virtual ~MainWidget() override = default;

private:
    MainWidget();
};

}