#include "CommandParser.h"
#include <AK/Error.h>

ErrorOr<void> irc::CommandParser::check_grammar(AK::StringView)
{
    return {};
}

Optional<irc::AddressAndPort> irc::CommandParser::is_connect_command(AK::StringView)
{
    return {};
}