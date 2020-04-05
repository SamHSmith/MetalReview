#include <gtk/gtk.h>
#include <gdk/gdkwayland.h>
#include <gdk/wayland/gdkwaylandwindow.h>
#include <wayland-client.h>

GtkWindow *window;


char* title = "Sick title";
int width = 640; int height = 480;
int close_pressed = FALSE;

struct wl_surface *gtk_wayland_surface(){
  GdkWindow *gdk_window = gtk_widget_get_window(GTK_WIDGET(window));
  struct wl_surface *surface = gdk_wayland_window_get_wl_surface(gdk_window);
  return surface;
}

void update_window(){
  gtk_window_set_decorated(window,TRUE);
  gtk_window_set_title(window, title);
  gtk_window_resize(window, width, height);
}

void gtk_set_title(char* t){
  title = t;
  update_window();
}

void gtk_set_size(int w, int h){
  width=w;
  height=h;
  update_window();
}

void close_button_pressed(){
  close_pressed=TRUE;
}

int is_close_button_pressed(){
  return close_pressed;
}

void gtk_refresh_window(){
  gtk_window_get_size(window, &width, &height);
  close_pressed=FALSE;
  gtk_main_iteration_do(FALSE);
}

void gtk_show_window(){
  gtk_widget_show((GtkWidget *)window);
}

void gtk_hide_window(){
  gtk_widget_hide((GtkWidget *)window);
}

void gtk_create_window(){
  window = (GtkWindow*)gtk_window_new(GTK_WINDOW_TOPLEVEL);

  g_signal_connect(G_OBJECT(window), 
                   "delete-event", G_CALLBACK(close_button_pressed), NULL);
}

void gtk_create_window_and_show(int w, int h, char* t){
  gtk_create_window();
  gtk_set_title(t);
  gtk_set_size(w,h);
  gtk_show_window();
}

void gtk_init_gtk(){
  gtk_init(0,NULL);
}

