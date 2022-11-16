#include "MainWidget.h"
#include "IRCMainWindowGML.h"

namespace IRCClient {

MainWidget::MainWidget() {
    load_from_gml(irc_main_window_gml);
}

}