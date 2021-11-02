rm lofs.img
sudo losetup -d /dev/loop10
sudo umount lofsdisk
rm -r lofsdisk

dd if=/dev/zero of=lofs.img bs=1M count=50
sudo losetup /dev/loop10 lofs.img
sudo mkfs -t ext3 -m 1 -v /dev/loop10

mkdir lofsdisk
sudo mount -t ext3 /dev/loop10 lofsdisk

