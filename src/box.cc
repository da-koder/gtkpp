#include "box.hpp"

Box::Box(Orientation o, int spacing) : Containter(gtk_box_new(o, spacing)) {
}
    
