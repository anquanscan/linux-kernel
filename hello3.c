#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init hello_3_init(void)
{
	printk(KERN_ALERT "Hello3.\n");
	return 0;
}

static void  __exit hello_3_exit(void)
{
	printk(KERN_ALERT "Bye3\n");
}
module_init(hello_3_init);
module_exit(hello_3_exit);



