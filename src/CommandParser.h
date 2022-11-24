#pragma once

#include <AK/StringView.h>
#include <AK/String.h>

namespace irc {

struct AddressAndPort {
    String address;
    u16 port;
};

class CommandParser {
public:
    static ErrorOr<void> check_grammar(StringView);
    static Optional<AddressAndPort> is_connect_command(StringView);
};

}