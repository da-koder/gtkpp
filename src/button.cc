#include "button.hpp"

namespace gtk {
Button::Button() : Widget(gtk_button_new()) {
}

Button::Button(GtkWidget* widget) : Widget(widget) {
}
/*Button::Button(GtkButton* widget) : Widget(widget) {
}*/

Button::Button(const char* lbl): Widget(gtk_button_new_with_label(lbl)) {
}
};

