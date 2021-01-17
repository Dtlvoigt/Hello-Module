// A simple kernel module
#include <linux/module.h>
#include <linux/kernel.h>

int hello_init(void)
{
  printk(KERN_INFO "Hello World!!\n");

  return 0;
}

void goodbye_module(void)
{
  printk(KERN_INFO "Exiting module\n");
}
