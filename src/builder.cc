#include "builder.hpp"

namespace gtk {

Builder::Builder() : g::Object(G_OBJECT(gtk_builder_new())) {}

GError* Builder::addFromFile(const char* name) {
    GError* err = nullptr;
    return (gtk_builder_add_from_file(GTK_BUILDER(m_object), name, &err) == 0) ? err : nullptr;
}

g::Object* Builder::getObject(const char* name) { 
    return new g::Object(gtk_builder_get_object(GTK_BUILDER(m_object), name));
}

};
