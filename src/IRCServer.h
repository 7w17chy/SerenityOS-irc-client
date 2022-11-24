#pragma once

#include <LibCore/Stream.h>

namespace irc {

class IRCServer : public Weakable<IRCServer>
{
    AK_MAKE_NONCOPYABLE(IRCServer);
public:
    static ErrorOr<NonnullOwnPtr<IRCServer>> connect_plaintext(StringView, u16);
    static ErrorOr<NonnullOwnPtr<IRCServer>> connect_tls(StringView, u16);

private:
    ErrorOr<void> read_from_socket();
    explicit IRCServer(NonnullOwnPtr<Core::Stream::Socket> socket);

protected:
    enum class IRCEventType : u32 {
        MessageReceived
    };

private:
    NonnullOwnPtr<Core::Stream::Socket> m_socket;
    ByteBuffer m_buffer;
};

}