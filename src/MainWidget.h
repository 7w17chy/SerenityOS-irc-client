#pragma once

#include <LibGUI/Widget.h>
#include "IRCServer.h"
#include "Session.h"

namespace irc {

class MainWidget final : public GUI::Widget {
    C_OBJECT(MainWidget);

public:
    virtual ~MainWidget() override = default;
    ErrorOr<void> send(String);

private:
    MainWidget();
    irc::Session m_session;
};

}