#pragma once

#include <LibGUI/TextBox.h>

namespace IRCClient {

class CommandBuffer : public GUI::TextEditor {
    C_OBJECT(CommandBuffer)

public:
    virtual ~CommandBuffer() = default;

protected:
    CommandBuffer()
        : GUI::TextEditor(GUI::TextEditor::Type::SingleLine)
    {}

private:
    void keydown_event(GUI::KeyEvent&) override;
};

}

REGISTER_WIDGET(IRCClient, CommandBuffer);