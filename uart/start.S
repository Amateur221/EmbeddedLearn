.extern     main

.text
.global _start
_start:
/*分配内存*/
    ldr sp,=4096//nand启动

/*调用MAIN函数*/
    bl main
halt:
    b halt
