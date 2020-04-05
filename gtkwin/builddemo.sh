./buildlib.sh
gcc -c demo.c -o demo.o
gcc -o demo demo.o libgtkwin.a -lwayland-client `pkg-config --cflags gtk+-wayland-3.0` `pkg-config --libs gtk+-wayland-3.0`
