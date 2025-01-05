#include "application.hpp"
#include "window.hpp"
#include "button.hpp"

class myApp : public gtk::Application {
public:
    myApp(const char* id) : gtk::Application(id) { 
        connect("activate", CALLBACK(&myApp::activate), nullptr);
    }
    
    void activate(gpointer udata) {
        gtk::Widget* win = newWindow();
        win->showAll();
    }
};

int main(int argc, char* argv[]) {
    myApp app("org.lm7.example");
    return app.run(argc, argv);
}
