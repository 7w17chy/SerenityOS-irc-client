#include "MainWidget.h"
#include "IRCMainWindowGML.h"
#include "CommandParser.h"
#include <AK/Format.h>

irc::MainWidget::MainWidget()
{
    load_from_gml(irc_main_window_gml);
}

ErrorOr<void> irc::MainWidget::send(String command)
{
    dbgln("Attempting to send text: `{}`", command);
    TRY(CommandParser::check_grammar(command));

    if (auto address_and_port = CommandParser::is_connect_command(command);
        address_and_port.has_value()) {
        auto server = address_and_port.value();
        return m_session.connect_to_server(server.address, server.port);
    }

    TRY(m_session.send_to_focused_server(move(command)));
}
