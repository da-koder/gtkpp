#ifndef Application_hpp_INCLUDED
#define Application_hpp_INCLUDED

//#include "pch.h"
#include <gtk/gtk.h>

#include "object.hpp"
#include "window.hpp"


namespace gtk {
class Application : public g::Object {
public:
    Application(const char* id, GApplicationFlags flag = G_APPLICATION_DEFAULT_FLAGS);
    Window* newWindow();
    int run(int&, char**&);
};
};

#endif // Application_hpp_INCLUDED
