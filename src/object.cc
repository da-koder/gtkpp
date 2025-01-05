#include "object.hpp"

namespace g {

Object::Object() : m_object(nullptr) {
}

Object::Object(GObject* object) : m_object(object) {
}

Object::Object(GType t) : m_object(G_OBJECT(g_object_new(t, nullptr))) {
}


Object::~Object() { g_object_unref(m_object); }

extern "C" void call_callback(GObject* object,  gpointer udata) {
    auto* info = reinterpret_cast<SignalInfo*>(udata);
    DelegateInfo d_i = info->object->getDelegateInfo(info->signal);
    DelegateType delegate = d_i.member_func;
    //printf("Signal: %s, Delegate obj: %p, func: %p.\n", info->signal, info->object, delegate);
    (d_i.object->*delegate)(d_i.data);
}

DelegateInfo Object::getDelegateInfo(const char* siganal) {
    return delegate_map[siganal];
}

void Object::connect(const char* siganal, DelegateType delegate, gpointer u_data) {
    delegate_map[siganal] = { this, delegate, u_data };
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    m_info = { siganal, this };
    g_signal_connect(m_object, siganal, reinterpret_cast<GCallback>(&call_callback), &m_info);
}
void Object::connect(const char* siganal, Object* d_w, DelegateType delegate, gpointer u_data) {
    delegate_map[siganal] = { d_w, delegate, u_data };
    //printf("Setting call back: %p, for signal %s.\n", delegate, siganal);
    m_info = { siganal, this };
    g_signal_connect(m_object, siganal, reinterpret_cast<GCallback>(&call_callback), &m_info);
}

/*void Object::connect(Object* w, const char* siganal, Object* d_w, DelegateType delegate, gpointer user_data) {
    w->delegate_map[siganal] = { d_w, delegate, user_data };
    //printf("Signal clicked for object: %p, to object %p, delegate %p.\n", w, d_w, delegate);
    w->m_info = { siganal, w };
    g_signal_connect(w->m_object, siganal, reinterpret_cast<GCallback>(&call_callback), &w->m_info);
}*/


GObject* Object::getBase() { return m_object; }

};
