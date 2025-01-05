#include "widget.hpp"

namespace gtk {

Widget::Widget(GtkWidget* widget) : g::Object(G_OBJECT(widget)) {
}

void Widget::showAll() { gtk_widget_show_all(GTK_WIDGET(m_object)); }
void Widget::destroy() { gtk_widget_destroy(GTK_WIDGET(m_object)); }

};

