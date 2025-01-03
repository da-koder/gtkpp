#include "application.hpp"
#include "window.hpp"
#include "button.hpp"

class myApp : public gtk::Application {
public:
    myApp(const char* id) : gtk::Application(id) { 
        connect("activate", WIDGET_CALLBACK(&myApp::activate));
    }
    
    void activate(gpointer udata) {
        gtk::Container* win = newWindow();
        win->showAll();
    }
};

int main(int argc, char* argv[]) {
    myApp app("org.lm7.example");
    return app.run(argc, argv);
}
