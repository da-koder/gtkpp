#include "builder.hpp"

namespace gtk {

Builder::Builder() : Object(G_OBJECT(gtk_builder_new())) {}

GError* Builder::addFromFile(const char* name) {
    GError* err = nullptr;
    return (gtk_builder_add_from_file(m_object, name, &err) == 0) ? err : nullptr;
}

Object Builder::getObject(const char* name) { return new Object(gtk_builder_get_object(m_object, name)); }

};
