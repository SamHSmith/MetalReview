gcc -c gtkwin.c -o gtkwin.o -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0`
ar rcs libgtkwin.a gtkwin.o
