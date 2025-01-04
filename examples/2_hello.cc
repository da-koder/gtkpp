#include "application.hpp"
#include "window.hpp"
#include "button.hpp"

class myApp : public gtk::Application {
public:
    myApp(const char* id) : gtk::Application(id) { 
        connect("activate", WIDGET_CALLBACK(&myApp::activate), nullptr);
    }

    void clicked(gpointer udata) {
        g_print("Hello world\n");
    }
    
    void activate(gpointer udata) {
        gtk::Container* win = newWindow();
        gtk::Widget* btn = new gtk::Button("say hello");
        btn->connect("clicked", this, WIDGET_CALLBACK(&myApp::clicked), nullptr);
        win->setBorderWidth(10);
        win->add(btn);
        win->showAll();
    }
};

int main(int argc, char* argv[]) {
    myApp app("org.lm7.example");
    return app.run(argc, argv);
}
