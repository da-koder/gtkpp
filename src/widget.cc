#include "widget.hpp"

namespace gtk {
Widget::Widget() : m_widget(nullptr) {
}

Widget::Widget(GtkWidget* widget) : m_widget(widget) {
}

Widget::Widget(GType t) : m_widget(gtk_widget_new(t, nullptr)) {
}

extern "C" void call_callback(GtkWidget* widget,  gpointer user_data) {
    //g_print("CProxy Callback triggered.\n");
    //g_print("GtkWidget's address = %p\n", widget);
    auto* info = reinterpret_cast<SignalInfo*>(user_data);
    DelegateType delegate = info->widget->getDelegate(info->signal);
    //g_print("cb_activate's address = %p\n", delegate);
    (info->widget->*delegate)(user_data);
}

DelegateType Widget::getDelegate(const char* siganal) {
    return delegate_map[siganal];
}

void Widget::connect(const char* siganal, DelegateType delegate) {
    delegate_map[siganal] = delegate;
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    m_info = { siganal, this };
    g_signal_connect(m_widget, siganal, reinterpret_cast<GCallback>(&call_callback), &m_info);
}

void Widget::connect(Widget* w, const char* siganal, DelegateType delegate) {
    w->delegate_map[siganal] = delegate;
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    w->m_info = { siganal, w };
    g_signal_connect(w->m_widget, siganal, reinterpret_cast<GCallback>(&call_callback), &w->m_info);
}

GtkWidget* Widget::getBase() { return m_widget; }
void Widget::showAll() { gtk_widget_show_all(m_widget); }
};

