#ifndef window_hpp_INCLUDED
#define window_hpp_INCLUDED

//#include "pch.h"
#include <gtk/gtk.h>

#include "container.hpp"

namespace gtk {
typedef GtkWindowType Type;

class Window : public Container {
public:
    Window(Type);
    Window(GtkWidget* w);
    Window(Type, const char*);

    void setTitle(const char*);
};
};

#endif // window_hpp_INCLUDED
