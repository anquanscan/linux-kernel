#obj-m += hello1.o
#obj-m += hello2.o
#obj-m += hello3.o
#obj-m += hello4.o
#obj-m += hello5.o
#obj-m += chardev.o
obj-m += procfs.o
#obj-m  += file_op.o
#KERNELDIR := /lib/modules/4.4.0-109-generic/build/
#KERNELDIR :=/usr/src/linux-headers-4.10.0-28-generic
#KERNELDIR := /usr/src/kernels/3.10.0-693.5.2.el7.x86_64
KERNELDIR := /usr/src/linux-headers-4.13.0-32-generic/
#KERNELDIR := /usr/src/kernels/2.6.32-642.el6.x86_64/
PWD := $(shell pwd) 
modules:
	make  -C $(KERNELDIR) M=$(PWD) modules
modules_install:
	make -C $(KERNELDIR) M=$(PWD) modules_install


clean:
	rm -rf *.ko *.o Module.symvers modules.order *.mod.c 
