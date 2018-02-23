#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define filename  "/root/test"



static  int  __init myinit(void)
{
	static struct file * myfilp = NULL;
	mm_segment_t fs;
	ssize_t nwrite= 0;
	const char *data = "Hello World\n";
	myfilp = filp_open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	if(IS_ERR(myfilp))
	{
		return -1;
	}
	
	fs = get_fs();
	set_fs(KERNEL_DS);

	printk(KERN_INFO "myfilp->f_pos = %ld\n",myfilp->f_pos);
	nwrite = vfs_write(myfilp, data, strlen(data), &myfilp->f_pos);
	printk(KERN_INFO "myfilp->f_pos = %ld\n",myfilp->f_pos);


	printk(KERN_INFO "write to file %ld\n",nwrite);

	nwrite = vfs_write(myfilp, data, strlen(data), &myfilp->f_pos);
	printk(KERN_INFO "myfilp->f_pos = %ld\n",myfilp->f_pos);
	printk(KERN_INFO "write to file %ld\n",nwrite);

	filp_close(myfilp,0);
	
	return 0;
}


static void __exit myexit(void)
{
	static struct file* myfilp = NULL;
	mm_segment_t fs;
	ssize_t nread = 0;
	char data[200] = {};


	fs = get_fs();
	set_fs(KERNEL_DS);

	myfilp = filp_open(filename,O_RDONLY,0);
	if(IS_ERR(myfilp))
	{
		printk("Open %s error!!!\n",filename);
		return;
	}

	nread = vfs_read(myfilp, data, 200, &myfilp->f_pos);

	printk("read %ld\n",nread);


	
	filp_close(myfilp, 0);
}





module_init(myinit);
module_exit(myexit);