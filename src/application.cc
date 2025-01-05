#include "application.hpp"

namespace gtk {
Application::Application(const char* id, GApplicationFlags flag) : Object(G_OBJECT(gtk_application_new(id, flag))) {
}

int Application::run(int& argc, char**& argv) {
    //gtk_application_add_window(reinterpret_cast<GtkApplication*>(m_object), reinterpret_cast<GtkWindow*>(win->getBase()));
    return g_application_run(reinterpret_cast<GApplication*>(m_object), argc, argv);
}

Window* Application::newWindow() {
    return new Window(gtk_application_window_new(GTK_APPLICATION(m_object)));
}
};
