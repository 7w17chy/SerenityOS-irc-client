#pragma once

#include <AK/Types.h>
#include <AK/HashMap.h>
#include <AK/WeakPtr.h>
#include "IRCServer.h"
#include "Backlog.h"

namespace irc {

// TODO: this class will receive an event when a socket in an IRCServer object becomes ready to read
class Session {
public:
    Session() = default;

    ErrorOr<void> send_to_focused_server(String&&);
    ErrorOr<void> connect_to_server(StringView, u16);

protected:
    ErrorOr<void> add_server(StringView, NonnullOwnPtr<IRCServer>&&);
    void make_focused_server(StringView);

private:
    WeakPtr<IRCServer> m_focused_server;
    WeakPtr<Backlog> m_focused_backlog;

    HashMap<StringView, NonnullOwnPtr<IRCServer>> m_servers;
    HashMap<StringView, Backlog> m_chat_backlogs;
};

}