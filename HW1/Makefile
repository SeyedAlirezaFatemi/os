obj-m+=first_module.o

compile:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
install:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules_install
add:
	sudo insmod first_module.ko
	sudo depmod
	sudo modprobe first_module
remove:
	sudo rmmod first_module
	sudo modprobe -r first_module
	sudo rm -f /etc/modules-load.d/reboot.conf
	sudo rm -f /lib/modules/$(shell uname -r)/kernel/drivers/pci/pcie/first_module.ko
test:
	sudo dmesg -C
	sudo insmod first_module.ko
	sudo rmmod first_module.ko
	dmesg
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm -rf   Module.symvers modules.order
