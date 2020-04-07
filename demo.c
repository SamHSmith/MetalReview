#include "gtkwin/gtkwin.h"

int main(){

  gtk_init_gtk();
  gtk_create_window_and_show(640,480,"Even more sick title.");

  while(!is_close_button_pressed()){
    gtk_refresh_window();
  }
  gtk_refresh_window();
  gtk_set_title("HAHA you can not close me!");
  while(!is_close_button_pressed()){
    gtk_refresh_window();
  }
}
