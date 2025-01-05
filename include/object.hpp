#ifndef object_hpp_INCLUDED
#define object_hpp_INCLUDED

#include <unordered_map>

#include <glib-object.h>

#define OBJECT(obj) (reinterpret_cast<g::Object*>(obj))
#define CALLBACK(fn) (reinterpret_cast<g::DelegateType>(fn))

namespace g {

class Object;

typedef void (Object::* DelegateType)(gpointer);
struct DelegateInfo {
    Object* object;
    DelegateType member_func;
    gpointer data;
};

struct SignalInfo {
    const char* signal;
    Object *object;
};


class Object {
public:
    Object();
    Object(GObject*);
    Object(GType t);

    void connect(const char*, DelegateType, gpointer); //maps delegates
    void connect(const char* siganal, Object* d_w, DelegateType delegate, gpointer u_data); 
    DelegateInfo getDelegateInfo(const char*);
    GObject* getBase();
    ~Object();
protected:
    std::unordered_map<const char*, DelegateInfo> delegate_map;
    SignalInfo m_info;
    GObject* m_object;
};

extern "C" void call_callback(GObject*, gpointer);

};

#endif // object_hpp_INCLUDED
