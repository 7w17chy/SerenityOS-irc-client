#include "MessageBuffer.h"
#include "MainWidget.h"
#include <LibGUI/Application.h>

void IRCClient::MessageBuffer::keydown_event(GUI::KeyEvent& event)
{
   GUI::TextEditor::keydown_event(event);

   if (event.key() == Key_Return) {
       auto main_widget = GUI::Application::the()->find_child_of_type_named<MainWidget>("main");
       // FIXME: avoid copy, find a way to move the string
       if (auto maybe_err = main_widget->send(text()); maybe_err.is_error())
           dbgln("An error occurred while sending stuff");
       clear();
   }
}