#include <widget.hpp>
#include <builder.hpp>
#include <window.hpp>
#include <button.hpp>

#define GTKWIDGET(obj) (reinterpret_cast<GtkWidget*>(obj))
#define GTKBUTTON(obj) (reinterpret_cast<GtkButton*>(obj))

void hello(GtkWidget* obj, gpointer udata) { g_print("Hello world\n"); }

int main(int argc, char* argv[]) {
    gtk_init(&argc, &argv);

    auto builder = new gtk::Builder();
    auto err = builder->addFromFile("examples/builder.ui");
    if(err != nullptr) {
        g_print("Error loading %s.", err->message);
        return 1;
    }

    gtk::Widget win = builder->getObject("window");
    win.connect("destroy", G_CALLBACK(&gtk_main_quit), nullptr);

    gtk::Widget btn = builder->getObject("button1");
    btn.connect("clicked", G_CALLBACK(hello), nullptr);

    btn = builder->getObject("button2");
    btn.connect("clicked", G_CALLBACK(hello), nullptr);

    btn = builder->getObject("quit");
    btn.connect("clicked", &win, CALLBACK(&gtk::Widget::destroy), nullptr);

    gtk_main();
    return 0;
}
