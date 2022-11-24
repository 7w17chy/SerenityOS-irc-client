#pragma once

#include <LibGUI/TextBox.h>

namespace IRCClient {

class MessageBuffer : public GUI::TextEditor {
    C_OBJECT(MessageBuffer)

public:
    virtual ~MessageBuffer() = default;

protected:
    MessageBuffer()
        : GUI::TextEditor(GUI::TextEditor::Type::SingleLine)
    {}

private:
    void keydown_event(GUI::KeyEvent&) override;
};

}

REGISTER_WIDGET(IRCClient, MessageBuffer);