#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <linux/init.h>	  /* Needed for the macros */
#include <linux/time.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Seyed Alireza Fatemi Jahromi");
MODULE_DESCRIPTION("Prints system's date and time");
MODULE_VERSION("0.1");

static int __init init(void)
{
	unsigned long time_sec;
	int sec, hr, min, tmp1, tmp2;
	struct timeval time;
	struct tm time_tm;

	do_gettimeofday(&time);
	time_sec = time.tv_sec;
	sec = time_sec % 60;
	tmp1 = time_sec / 60;
	min = tmp1 % 60;
	tmp2 = tmp1 / 60;
	hr = (tmp2 % 24) - 4;
	time_to_tm(time_sec, 0, &time_tm);
	printk(KERN_INFO "Time:  %d:%d:%d\n", hr, min, sec);
	/* Add years since 1900. */
	printk(KERN_INFO "Date: %d/%d/%d\n", time_tm.tm_year + 1900, time_tm.tm_mon + 1, time_tm.tm_mday);
	return 0;
}

static void __exit exit(void)
{
	printk(KERN_INFO "Goodbye!\n");
}

module_init(init);
module_exit(exit);
