@GUI::Frame {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        margins: [4]
    }

    @GUI::HorizontalSplitter {
        layout: @GUI::HorizontalBoxLayout {
            spacing: 4
        }
        @GUI::TreeView {
            preferred_width: 200
            title: "servers"
            name: "sever_view"
        }
        @GUI::TextBox {
            mode: "DisplayOnly"
            type: "MultiLine"
            name: "chat_window"
            preferred_width: "grow"
            preferred_height: "grow"
        }
    }

    @IRCClient::CommandBuffer {
        mode: "Editable"
        type: "SingleLine"
        preferred_height: 25
        name: "command_buffer"
    }
}