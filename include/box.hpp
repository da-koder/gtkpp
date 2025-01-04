#ifndef box_hpp_INCLUDED
#define box_hpp_INCLUDED

#include "container.hpp"

namespace gtk {
class Box : public Container {
public:
    Box(Orientation, int);
};
};

#endif // box_hpp_INCLUDED
