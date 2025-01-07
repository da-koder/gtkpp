#ifndef builder_hpp_INCLUDED
#define builder_hpp_INCLUDED

#include <gtk/gtk.h>

#include "object.hpp"

namespace gtk {

class Builder : public g::Object {
public:
    Builder();

    GError* addFromFile(const char*);
    g::Object* getObject(const char*);
protected:
    GtkBuilder* m_builder;
};
};

#endif // builder_hpp_INCLUDED
