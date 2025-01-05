#include "container.hpp"


namespace gtk {
Container::Container(GtkWidget* widget) : Widget(widget) {}

void Container::setBorderWidth(int width) { gtk_container_set_border_width(GTK_CONTAINER(m_object), width); }

void Container::add(Widget* w) { gtk_container_add(GTK_CONTAINER(m_object), GTK_WIDGET(w->getBase())); }
};
