ksenia@ksenia-VirtualBox:~/week11$ sudo mkdir -p lofsdisk/bin
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /bin/bash lofsdisk/bin
ksenia@ksenia-VirtualBox:~/week11$ ldd /bin/bash
ksenia@ksenia-VirtualBox:~/week11$ sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu
ksenia@ksenia-VirtualBox:~/week11$ sudo mkdir -p lofsdisk/lib64
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64
ksenia@ksenia-VirtualBox:~/week11$ ldd /bin/cat
ksenia@ksenia-VirtualBox:~/week11$ ldd /bin/ls
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu
ksenia@ksenia-VirtualBox:~/week11$ sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu
ksenia@ksenia-VirtualBox:~/week11$ ldd /bin/echo
ksenia@ksenia-VirtualBox:~/week11$ gcc ex2.c -static ex2.out
ksenia@ksenia-VirtualBox:~/week11$ sudo cp ex2.out lofsdisk
ksenia@ksenia-VirtualBox:~/week11$ sudo chroot lofsdisk
bash-5.1# ./ex2.out
bash-5.1# exit
ksenia@ksenia-VirtualBox:~/week11$ ./ex2.out >> ex2.txt

