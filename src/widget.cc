#include "widget.hpp"

namespace gtk {

Widget::Widget(GtkWidget* widget) : g::Object(G_OBJECT(widget)) {
}
Widget::Widget(g::Object* object) : Widget(reinterpret_cast<GtkWidget*>(object->getBase())) {
}

void Widget::showAll() { gtk_widget_show_all(GTK_WIDGET(m_object)); }
void Widget::destroy() { gtk_widget_destroy(GTK_WIDGET(m_object)); }

};

