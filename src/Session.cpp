#include "Session.h"
#include "IRCServer.h"
#include <AK/HashTable.h>

ErrorOr<void> irc::Session::send_to_focused_server(String&& string)
{
    return {};
}

ErrorOr<void> irc::Session::add_server(StringView address, NonnullOwnPtr<irc::IRCServer>&& new_server)
{
    switch (auto new_server_added = TRY(m_servers.try_set(address, move(new_server)));
            new_server_added) {
    case AK::HashSetResult::InsertedNewEntry: {
        dbgln("Connected to server {}", address);
    } break;
    case AK::HashSetResult::KeptExistingEntry: {
        dbgln("Attempted to connect to already connected server {}", address);
    } break;
    case AK::HashSetResult::ReplacedExistingEntry: {
        dbgln("Reconnected to already connected server {}", address);
    }
    }
    return {};
}

void irc::Session::make_focused_server(StringView address)
{
    if(auto server = m_servers.get(address); server.has_value())
        m_focused_server = server.value()->make_weak_ptr();
    if (auto backlog = m_chat_backlogs.get(address); backlog.has_value())
        m_focused_backlog = backlog.value().make_weak_ptr();
}

ErrorOr<void> irc::Session::connect_to_server(AK::StringView address, u16 port)
{
    if (port >= 6665 && port <= 6667) {
        auto new_server = TRY(IRCServer::connect_plaintext(address, port));
        TRY(add_server(address, move(new_server)));
    } else {
        auto new_server = TRY(IRCServer::connect_tls(address, port));
        TRY(add_server(address, move(new_server)));
    }
    make_focused_server(address);
}
