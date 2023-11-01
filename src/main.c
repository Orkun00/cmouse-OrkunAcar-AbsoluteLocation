#include <stdio.h>
#include <X11/Xlib.h>

int main() {
    Display *display = XOpenDisplay(NULL);

    if (display == NULL) {
        fprintf(stderr, "Failed to open X display\n");
        return 1;
    }

    Window root = DefaultRootWindow(display);
    int rootX, rootY, winX, winY;
    unsigned int mask;

    while (1) {
        if (XQueryPointer(display, root, &root, &root, &rootX, &rootY, &winX, &winY, &mask)) {
            printf("Absolute Mouse position: X=%d, Y=%d\n", rootX, rootY);
        }
        // Adjust the sleep duration as needed (e.g., 1 second).
        usleep(1000000); // Sleep for 1 second
    }

    XCloseDisplay(display);
    return 0;
}

