#ifndef grid_hpp_INCLUDED
#define grid_hpp_INCLUDED

#include "container.hpp"


namespace gtk {

class Grid : public Container {
public:
    Grid();

    void attach(Widget*, int, int, int, int);
};

};

#endif // grid_hpp_INCLUDED
