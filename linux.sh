cd gtkwin
./buildlib.sh

cd ..
LD_LIBRARY_PATH=libs:$LD_LIBRARY_PATH: LIBRARY_PATH=libs:$LIBRARY_PATH: cargo run
