#include "window.hpp"

namespace gtk {
Window::Window(Type t) : Container(gtk_window_new(t)) {
}

Window::Window(Type t, const char* title) : Container(gtk_window_new(t)) {
    gtk_window_set_title(reinterpret_cast<GtkWindow*>(m_widget), title);
}

Window::Window(GtkWidget* w) : Container(w) {
}
};

