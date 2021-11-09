#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evval[2] = {
    "RELEASED",
    "PRESSED "
};

int main(void)
{
    /*
     * open the input device
     */
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }
    
    /*
     * read keyboard events from the device
     */
    while (1) {
        n = read(fd, &ev, sizeof ev);
        if (n == (ssize_t)-1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else
        if (n != sizeof ev) {
            errno = EIO;
            continue;
        }
	if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 1)
            printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);

    }
    /*
     * finish the program
     */
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
    return EXIT_FAILURE;
}
        




