#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "lambertfly"
#define DRIVER_DESC   "A Simple Driver"

static int __init hello_4_init(void)
{
	printk(KERN_ALERT "Hello4.\n");
	return 0;
}


static void  __exit hello_4_exit(void)
{
	printk(KERN_ALERT "Bye4\n");
}





module_init(hello_4_init);
module_exit(hello_4_exit);



MODULE_LICENSE("GPL");
MODULE_AUTHOR("lambertfly");
MODULE_DESCRIPTION("lambertfly test");
MODULE_SUPPORTED_DEVICE("testdevice");







