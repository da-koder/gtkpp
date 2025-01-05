#ifndef widget_hpp_INCLUDED
#define widget_hpp_INCLUDED


//#include "pch.h"
#include <gtk/gtk.h>

#include "object.hpp"

#define WIDGET(obj) (static_cast<gtk::Widget*>(obj))

namespace gtk {
#define WIDGET_CALLBACK(fn) (reinterpret_cast<g::DelegateType>(fn))
#define GLIB_CALLBACK(fn) (reinterpret_cast<GCallback>(fn))
//#define CONNECT(klass_name, func_name) connect(this, #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))
//#define WIDGET_CONNECT(widget,klass_name, func_name) signalConnect(reinterpret_cast<Widget*>(widget), #func_name, reinterpret_cast<DelegateType>(&klass_name::func_name))


class Widget : public g::Object {
public:
    Widget(GtkWidget*);

    void showAll();
    void destroy();
};

};
#endif // widget_hpp_INCLUDED
