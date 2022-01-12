# usbreset

A simple, yet efficient, program to reset any Linux USB device.

Original idea by [Alan Stern](https://marc.info/?l=linux-usb&m=121459435621262&w=2).

## How-To

1. Compile:
```
$ cc usbreset.c -o usbreset
```
2. Ensure the compiled program is executable:
```
$ chmod +x usbreset
```
3. Execute the program to find the Bus and Device ID of the USB device you want to reset:
```
$ ./usbreset
Usage: usbreset <Bus> <Device>

Available USB devices:
Bus 001 Device 014: ID 0fd9:006c Elgato Systems GmbH Stream Deck XL  
```
4. Execute the program again, this time passing the found Bus and Device as parameter:
```
$ sudo ./usbreset 001 014
Resetting USB device /dev/bus/usb/001/014
Reset successful
```
