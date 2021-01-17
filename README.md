# Hello-Module
A simple Hello World linux kernel module to begin my journey of linux kernel development.

Before compiling, update your linux package:
```
dylan@laptop:~/kernelModule$ sudo apt-get install build-essential linux-headers-$(uname -r)
```

Once you have the .c file and Makefile in a folder you can compile the module:
```
dylan@laptop:~/kernelModule$ make
```

Load the kernel object:
```
dylan@laptop:~/kernelModule$ sudo insmod helloWorld.ko
```

Check the log to see your messages!
```
dylan@laptop:~/kernelModule$ tail /var/log/kern.log
```

You can also view name/description etc:
```
dylan@laptop:~/kernelModule$ modinfo helloWorld.ko
```
