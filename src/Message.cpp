#include "Message.h"

Optional<StringView> irc::Message::has_prefix(AK::StringView message)
{
    if (!message.starts_with(':'))
        return {};
    auto prefix_end = message.find(' ').value_or(message.length()) - 1;
    auto prefix = message.substring_view(1, prefix_end);
    return prefix;
}

// FIXME: also parse the <trailing> part (RFC 1459, section 2.3.1)
ErrorOr<irc::Message> irc::Message::parse(String&& input)
{
    String message = input;
    auto splitted = message.split_view(' ');

    if (splitted.size() < 2)
        return Error::from_string_view("trying to parse non-valid message"sv);
    auto prefix = has_prefix(splitted[0]);
    auto command = splitted[1];

    // FIXME: find a better way to achieve the same result
    Vector<StringView> command_parameters; // can be empty, there are commands without params
    for (size_t i = 2; i < splitted.size(); ++i)
        command_parameters.append(splitted.take(i));

    return Message(move(input), prefix, command, command_parameters);
}

Optional<irc::ConnectInformation> irc::Message::is_connect_message(String)
{
    return {};
}
