dd if=/dev/zero of=lofs.img bs=60MB count=1
sudo losetup -f lofs.img
sudo mkfs.ext4 /dev/loop14
sudo mkfs.ext4 /dev/loop14
sudo mount /dev/loop14 ~/lofsdisk

