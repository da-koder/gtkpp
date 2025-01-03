#include "container.hpp"

namespace gtk {
Container::Container(GtkWidget* widget) : Widget(widget) {}

void Container::setBorderWidth(int width) { gtk_container_set_border_width(reinterpret_cast<GtkContainer*>(m_widget), width); }

void Container::add(Widget* w) { gtk_container_add(reinterpret_cast<GtkContainer*>(m_widget), w->getBase()); }
};
