# Hello-Module
A simple Hello World linux kernel module to begin my journey of linux kernel development.

Before compiling, update your linux package:
```
dylan@laptop:~/kernelModule$ sudo apt-get install build-essential linux-headers-$(uname -r)
```

Once the .c file and Makefile are in a folder compile the module:
```
dylan@laptop:~/kernelModule$ make
make -C /lib/modules/4.15.0-132-generic/build/ M=/home/dylan/Documents/kernelModule modules
make[1]: Entering directory '/usr/src/linux-headers-4.15.0-132-generic'
  CC [M]  /home/dylan/Documents/kernelModule/helloWorld.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/dylan/Documents/kernelModule/helloWorld.mod.o
  LD [M]  /home/dylan/Documents/kernelModule/helloWorld.ko
make[1]: Leaving directory '/usr/src/linux-headers-4.15.0-132-generic'
```

Load the kernel object:
```
dylan@laptop:~/kernelModule$ sudo insmod helloWorld.ko
```

Check the log to see the message!
```
dylan@laptop:~/kernelModule$ tail /var/log/kern.log
.....
Jan 17 11:33:32 dylansLaptop kernel: [10006.483577] Hello World!!
```

Don't forget to unload the module:
```
dylan@laptop:~/kernelModule$ sudo rmmod helloWorld
```

And check the log again to see the exit message:
```
dylan@laptop:~/kernelModule$ tail /var/log/kern.log
.....
Jan 17 11:33:32 dylansLaptop kernel: [10006.483577] Hello World!!
Jan 17 11:34:41 dylansLaptop kernel: [10075.300810] Exiting module
```

View name/description etc at any time:
```
dylan@laptop:~/kernelModule$ modinfo helloWorld.ko
filename:       /home/dylan/Documents/kernelModule/helloWorld.ko
description:    My first linux kernel module!
license:        GPL
author:         Dylan Voigt
srcversion:     FFD8A9188A5CD51D22EA45B
depends:        
retpoline:      Y
name:           helloWorld
vermagic:       4.15.0-132-generic SMP mod_unload 
```
