#include "widget.hpp"

namespace gtk {
Widget::Widget() : m_widget(nullptr) {
}

Widget::Widget(GtkWidget* widget) : m_widget(widget) {
}

Widget::Widget(GType t) : m_widget(gtk_widget_new(t, nullptr)) {
}

Widget::~Widget() { g_object_unref(m_widget); }


extern "C" void call_callback(GtkWidget* widget,  gpointer udata) {
    auto* info = reinterpret_cast<SignalInfo*>(udata);
    DelegateInfo d_i = info->widget->getDelegateInfo(info->signal);
    DelegateType delegate = d_i.member_func;
    //printf("Signal: %s, Delegate obj: %p, func: %p.\n", info->signal, info->widget, delegate);
    (d_i.widget->*delegate)(d_i.data);
}

DelegateInfo Widget::getDelegateInfo(const char* siganal) {
    return delegate_map[siganal];
}

void Widget::connect(const char* siganal, DelegateType delegate, gpointer u_data) {
    delegate_map[siganal] = { this, delegate, u_data };
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    m_info = { siganal, this };
    g_signal_connect(m_widget, siganal, reinterpret_cast<GCallback>(&call_callback), &m_info);
}
void Widget::connect(const char* siganal, Widget* d_w, DelegateType delegate, gpointer u_data) {
    delegate_map[siganal] = { d_w, delegate, u_data };
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    m_info = { siganal, this };
    g_signal_connect(m_widget, siganal, reinterpret_cast<GCallback>(&call_callback), &m_info);
}

/*void Widget::connect(Widget* w, const char* siganal, Widget* d_w, DelegateType delegate, gpointer user_data) {
    w->delegate_map[siganal] = { d_w, delegate, user_data };
    //printf("Signal clicked for widget: %p, to widget %p, delegate %p.\n", w, d_w, delegate);
    w->m_info = { siganal, w };
    g_signal_connect(w->m_widget, siganal, reinterpret_cast<GCallback>(&call_callback), &w->m_info);
}*/


GtkWidget* Widget::getBase() { return m_widget; }
void Widget::showAll() { gtk_widget_show_all(m_widget); }
void Widget::destroy() { gtk_widget_destroy(m_widget); }
};

