// A simple kernel module
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

//author name
MODULE_AUTHOR("Dylan Voigt");

//description
MODULE_DESCRIPTION("My first linux kernel module!");

//modules must include a initialization function
static int __init helloWorld(void)
{
  printk(KERN_INFO "Hello World!!\n");
  return 0;
}

//modules must include a cleanup function
static void __exit goodbyeWorld(void)
{
  printk(KERN_INFO "Exiting module\n");
}

module_init(helloWorld);
module_exit(goodbyeWorld);
