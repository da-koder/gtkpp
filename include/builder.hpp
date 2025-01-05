#ifndef builder_hpp_INCLUDED
#define builder_hpp_INCLUDED

#include "object.hpp"

namespace gtk {

class Builder {
public:
    Builder();

    GError* addFromFile(const char*, );
    Object getObject(const char*);
protected:
    GtkBuilder* m_builder;
};
};

#endif // builder_hpp_INCLUDED
