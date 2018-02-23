#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>





static int __init proc_init(void)
{

	struct proc_dir_entry *proc = NULL;
	proc = proc_create("abc",0644,NULL,NULL);


	return 0;
}


static void __exit proc_exit(void)
{
	remove_proc_entry("abc",NULL);
}









module_init(proc_init);
module_exit(proc_exit);



