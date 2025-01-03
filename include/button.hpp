#ifndef button_hpp_INCLUDED
#define button_hpp_INCLUDED
//#include "pch.h"
#include <gtk/gtk.h>

#include "widget.hpp"

namespace gtk {
class Button : public Widget {
public:
    Button();
    Button(const char*);
};
};

#endif 
