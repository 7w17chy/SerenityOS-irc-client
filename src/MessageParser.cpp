#include "MessageParser.h"
#include <AK/Error.h>

ErrorOr<void> irc::MessageParser::check_grammar(AK::StringView)
{
    return {};
}

Optional<irc::AddressAndPort> irc::MessageParser::is_connect_message(AK::StringView)
{
    return {};
}