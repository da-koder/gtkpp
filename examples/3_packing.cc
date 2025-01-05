#include <application.hpp>
#include <window.hpp>
#include <grid.hpp>
#include <button.hpp>

class myApp: public gtk::Application {
public:
    myApp(const char* id) : gtk::Application(id) {
        connect("activate", CALLBACK(&myApp::activate), nullptr);
    }

    void activate(gpointer data) {
        gtk::Window* win = newWindow();
        win->setTitle("Grid Packing");
        win->setBorderWidth(10);

        gtk::Grid* grid = new gtk::Grid();

        gtk::Widget* btn = new gtk::Button("Button 1");
        btn->connect("clicked", this, CALLBACK(&myApp::hello), nullptr);
        grid->attach(btn, 0,0, 1, 1);

        btn = new gtk::Button("Button 2");
        btn->connect("clicked", this, CALLBACK(&myApp::hello), nullptr);
        grid->attach(btn, 1,0, 1, 1);

        btn = new gtk::Button("Quit");
        btn->connect("clicked", win, CALLBACK(&gtk::Widget::destroy), nullptr);
        grid->attach(btn, 0,1, 2, 1);

        win->add(WIDGET(grid));

        win->showAll();
        
    }

    void hello(gpointer data) {
        g_print("Hello world.\n");
    }

};

int main(int argc, char* argv[]) {
    myApp app("org.gtk.example3");
    return app.run(argc, argv);
}
