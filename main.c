#include <gtk/gtk.h>
#include <stdio.h>

gboolean button_pressed(GtkWidget *widget, GdkEvent *event, gpointer data) {
    printf("Button pressed\n");
    return FALSE;
}

gboolean button_released(GtkWidget *widget, GdkEvent *event, gpointer data) {
    printf("Button released\n");
    return FALSE;
}

int main(int argc, char* argv[]) {
    GtkWidget *window;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Touch Test Window" );
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 350);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_widget_add_events(GTK_WIDGET(window), GDK_BUTTON_PRESS_MASK);
    gtk_widget_add_events(GTK_WIDGET(window), GDK_BUTTON_RELEASE_MASK);
    g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(button_pressed), NULL);
    g_signal_connect(G_OBJECT(window), "button-release-event", G_CALLBACK(button_released), NULL);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(window);

    gtk_main();

    return 0;
}
