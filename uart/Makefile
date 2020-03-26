all:
	arm-linux-gcc -c -o clock.o clock.c
	arm-linux-gcc -c -o uart.o uart.c
	arm-linux-gcc -c -o main.o main.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-ld -Ttext 0 start.o main.o clock.o uart.o  -o uart.elf
	arm-linux-objcopy -O binary -S uart.elf uart.bin

clean:
	rm *.o *.elf