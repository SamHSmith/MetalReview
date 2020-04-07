gcc -fPIC -c gtkwin.c -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0`

gcc -shared gtkwin.o -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0` -o ../libs/libgtkwin.so
