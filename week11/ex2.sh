sudo rm -r lofsdisk

sh ex1.sh

echo Egor > file1
echo Stroganov > file2

sudo mv file1 lofsdisk
sudo mv file2 lofsdisk

gcc -o ex2.out ex2.c
sudo mv ex2.out lofsdisk

mkdir lofsdisk/bin
mkdir lofsdisk/lib64

sudo cp /bin/bash lofsdisk/bin
sudo cp /bin/cat lofsdisk/bin
sudo cp /bin/echo lofsdisk/bin
sudo cp /bin/ls lofsdisk/bin

sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib64
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib64
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib64
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64

sudo chroot lofsdisk ex2.out > ex2.txt
