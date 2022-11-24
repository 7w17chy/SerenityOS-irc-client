#pragma once

#include <AK/String.h>
#include <AK/Error.h>
#include <AK/Vector.h>

namespace irc {

struct ConnectInformation {
    String address;
    u16 port;
};

class Message {
private:
    Message(String&& message, Optional<StringView> prefix, StringView command, Vector<StringView> command_parameters)
        : m_message(message)
        , m_prefix(prefix)
        , m_command(command)
        , m_command_parameters(command_parameters)
    {}

    String m_message;
    Optional<StringView> m_prefix;
    StringView m_command;
    Vector<StringView> m_command_parameters;

    static Optional<StringView> has_prefix(StringView);

public:
    static ErrorOr<Message> parse(String&&);
    Optional<ConnectInformation> is_connect_message(String);
};

}