@GUI::Frame {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        margins: [0]
    }
    @GUI::ScrollableContainerWidget {
        content_widget: @GUI::TextBox {
            mode: "DisplayOnly"
            type: "MultiLine"
        }
    }
    @GUI::TextBox {
        mode: "Editable"
        type: "SingleLine"
    }
}