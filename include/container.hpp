#ifndef container_hpp_INCLUDED
#define container_hpp_INCLUDED

#include "widget.hpp"
#include <gtk/gtk.h>


namespace gtk {
class Container : public Widget {
public:
    Container(GtkWidget*);
    void add(Widget*);
    void setBorderWidth(int);
};
};

#endif // container_hpp_INCLUDED
