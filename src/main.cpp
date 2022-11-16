#include <LibGUI/Application.h>
#include <LibGUI/Window.h>
#include <LibMain/Main.h>

ErrorOr<int> serenity_main(Main::Arguments arguments)
{
    auto app = TRY(GUI::Application::try_create(arguments));
    auto window = TRY(GUI::Window::try_create());
    auto widget = TRY(window->try_set_main_widget<GUI::Widget>());

    window->set_title("IRC Client");
    window->resize(640, 400);
    window->show();

    return app->exec();
}