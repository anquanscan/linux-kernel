#include <linux/module.h>
#include <linux/kernel.h>




int init_module(void)
{
	printk("<1>Hello World.\n");
	return 0;
}

void exit_module(void)
{
	printk(KERN_ALERT "GOOD Bye/\n");
	return;
}

