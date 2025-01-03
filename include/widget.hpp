#ifndef widget_hpp_INCLUDED
#define widget_hpp_INCLUDED

#include <unordered_map>

//#include "pch.h"
#include <gtk/gtk.h>

namespace gtk {
#define WIDGET_CALLBACK(fn) (reinterpret_cast<gtk::DelegateType>(fn))
#define GLIB_CALLBACK(fn) (reinterpret_cast<GCallback>(fn))
//#define CONNECT(klass_name, func_name) connect(this, #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))
//#define WIDGET_CONNECT(widget,klass_name, func_name) signalConnect(reinterpret_cast<Widget*>(widget), #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))

class Widget;
typedef void (Widget::* DelegateType)(gpointer user_data);

struct SignalInfo {
    const char* signal;
    Widget *widget;
};

class Widget {
public:
    Widget();
    Widget(GtkWidget*);
    Widget(GType t);
    static void connect(Widget*, const char*, DelegateType);
    void connect(const char*, DelegateType); //maps delegates
    DelegateType getDelegate(const char*);
    GtkWidget* getBase();

    void showAll();
protected:
    std::unordered_map<const char*, DelegateType> delegate_map;
    SignalInfo m_info;
    GtkWidget* m_widget;
};

extern "C" void call_callback(GtkWidget* widget, gpointer user_data);
};
#endif // widget_hpp_INCLUDED
