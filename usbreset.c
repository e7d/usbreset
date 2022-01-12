#include <errno.h>
#include <fcntl.h>
#include <linux/usbdevice_fs.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

/*
 * usbreset -- send a USB port reset to a USB device
 * Original idea by Alan Stern:
 * https://marc.info/?l=linux-usb&m=121459435621262&w=2
 */
int main(int argc, char **argv)
{
    char filename[20];
    int fd;
    int rc;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: usbreset <Bus> <Device>\n");
        fprintf(stderr, "\n");
        fprintf(stderr, "Available USB devices:\n");
        execlp("lsusb", NULL);
        return 1;
    }

    strcat(filename, "/dev/bus/usb/");
    strcat(filename, argv[1]);
    strcat(filename, "/");
    strcat(filename, argv[2]);
    fd = open(filename, O_WRONLY);
    if (fd < 0)
    {
        perror("Error opening output file");
        return 1;
    }

    printf("Resetting USB device %s\n", filename);
    rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0)
    {
        perror("Error in ioctl");
        return 1;
    }
    printf("Reset successful\n");

    close(fd);
    return 0;
}
