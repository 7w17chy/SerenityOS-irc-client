#include <LibGUI/Application.h>
#include <LibGUI/Window.h>
#include <LibMain/Main.h>
#include <IRCMainWindowGML.h>

ErrorOr<int> serenity_main(Main::Arguments arguments)
{
    auto app = TRY(GUI::Application::try_create(arguments));
    auto window = TRY(GUI::Window::try_create());
    auto widget = TRY(window->try_set_main_widget<GUI::Widget>());

    widget->load_from_gml(irc_main_window_gml);
    window->set_title("IRC Client");
    window->resize(200, 100);
    window->show();

    return app->exec();
}