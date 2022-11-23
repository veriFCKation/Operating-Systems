sudo mkdir -p lofsdisk/bin
sudo cp /bin/bash lofsdisk/bin
ldd /bin/bash
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo mkdir -p lofsdisk/lib64
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64
ldd /bin/cat
ldd /bin/ls
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu
ldd /bin/echo
gcc ex2.c -static ex2.out
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk
./ex2.out
exit
./ex2.out >> ex2.txt

