gcc -fPIC -c gtkwin.c -lvulkan -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0`

gcc -shared gtkwin.o -lvulkan -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0` -o ../libs/libgtkwin.so
