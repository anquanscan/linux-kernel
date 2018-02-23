#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lambertfly");


static short  myshort = 1;
static int myint = 420;
static long  mylong  = 9999;
static char *mystring = "mystring";


module_param(myshort, short, S_IRGRP | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "This is a short integer");

module_param(myint, int, S_IRGRP | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myint, "This is a integer");

module_param(mylong, long, S_IRGRP | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(mylong, "This is long integer");

module_param(mystring, charp, S_IRGRP | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(mystring, "This is a string");


static int __init hello_5_init(void)
{
	printk(KERN_ALERT "Hello World 5 .\n");
	printk(KERN_ALERT "myshort is %hd\n",myshort);
	printk(KERN_ALERT "myint is %d\n",myint);
	printk(KERN_ALERT "mylong is %ld\n",mylong);
	printk(KERN_ALERT "mystring is %s\n",mystring);
	return 0;
}
static void __exit hello_5_exit(void)
{
	printk(KERN_ALERT "Bye 5.\n");
}


module_init(hello_5_init);
module_exit(hello_5_exit);










