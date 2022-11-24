#include "IRCServer.h"
#include <LibTLS/TLSv12.h>
#include <AK/Forward.h>
#include <LibCore/EventLoop.h>
#include <LibGUI/Application.h>

using namespace irc;

IRCServer::IRCServer(NonnullOwnPtr<Core::Stream::Socket> socket)
    : m_socket(move(socket))
{
    m_socket->on_ready_to_read = [&]() {
        auto maybe_error = read_from_socket();
        if (maybe_error.is_error())
            dbgln("Received error during socket read: {}", maybe_error.error());

        // fire event that tells the gui that a new message has arrived
        auto& gui_event_loop = GUI::Application::the()->event_loop();
        gui_event_loop.post_event(*GUI::Application::the(),
            make<Core::CustomEvent>(static_cast<int>(IRCEventType::MessageReceived)));
    };
}

ErrorOr<void> irc::IRCServer::read_from_socket()
{
    if (!TRY(m_socket->can_read_without_blocking()))
        return {};

    auto n_ready_bytes = TRY(m_socket->pending_bytes());
    auto read_buffer = TRY(m_buffer.get_bytes_for_writing(n_ready_bytes));
    TRY(m_socket->read(read_buffer));
    return {};
}

ErrorOr<NonnullOwnPtr<IRCServer>> irc::IRCServer::connect_plaintext(AK::StringView address, u16 port)
{
    auto socket = TRY(Core::Stream::TCPSocket::connect(address, port));
    dbgln("Successfully connected to {}:{}", address, port);
    return adopt_nonnull_own_or_enomem(new (nothrow) IRCServer(move(socket)));
}

ErrorOr<NonnullOwnPtr<IRCServer>> irc::IRCServer::connect_tls(AK::StringView address, u16 port)
{
    auto tls_socket = TRY(TLS::TLSv12::connect(address, port));
    dbgln("Successfully created TLS connection to {}:{}", address, port);
    return adopt_nonnull_own_or_enomem(new (nothrow) IRCServer(move(tls_socket)));
}