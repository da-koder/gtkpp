#ifndef widget_hpp_INCLUDED
#define widget_hpp_INCLUDED

#include <unordered_map>

//#include "pch.h"
#include <gtk/gtk.h>

#define WIDGET(obj) (reinterpret_cast<gtk::Widget*>(obj))

namespace gtk {
#define WIDGET_CALLBACK(fn) (reinterpret_cast<gtk::DelegateType>(fn))
#define GLIB_CALLBACK(fn) (reinterpret_cast<GCallback>(fn))
//#define CONNECT(klass_name, func_name) connect(this, #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))
//#define WIDGET_CONNECT(widget,klass_name, func_name) signalConnect(reinterpret_cast<Widget*>(widget), #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))

class Widget;

typedef void (Widget::* DelegateType)(gpointer);
struct DelegateInfo {
    Widget* widget;
    DelegateType member_func;
    gpointer data;
};

struct SignalInfo {
    const char* signal;
    Widget *widget;
};

class Widget {
public:
    Widget();
    Widget(GtkWidget*);
    Widget(GType t);
    void connect(const char*, DelegateType, gpointer); //maps delegates
    void connect(const char* siganal, Widget* d_w, DelegateType delegate, gpointer u_data); 
    DelegateInfo getDelegateInfo(const char*);
    GtkWidget* getBase();

    void showAll();
    void destroy();
    ~Widget();
protected:
    std::unordered_map<const char*, DelegateInfo> delegate_map;
    SignalInfo m_info;
    GtkWidget* m_widget;
};

extern "C" void call_callback(GtkWidget*, gpointer);
};
#endif // widget_hpp_INCLUDED
