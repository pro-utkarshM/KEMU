/* birchutils.c v1.3 */
#include <KEMU_utils.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

void copy(int8 *dst, int8 *src, int16 size) {
    memcpy(dst, src, size);  // Standard memcpy for simplicity and performance
}

int16 nstoh(int16 srcport) {
    return ntohs(srcport);  // Standard function for network-to-host conversion
}

void zero(int8 *str, int16 size) {
    memset(str, 0, size);  // Use memset for clearing memory
}

void printhex(int8 *str, int16 size, int8 delim) {
    int8 *p;
    int16 n;

    for (p = str, n = size; n; n--, p++) {
        printf("%.02x", *p);
        if (delim) {
            printf("%c", delim);
        }
    }
    printf("\n");
    fflush(stdout);  // Flush once after printing the whole string
}

int8* todotted(in_addr_t ip) {
    static int8 buf[16];  // Be cautious with static buffers in multi-threaded environments
    int8 a, b, c, d;

    d = ((ip & 0xff000000) >> 24);
    c = ((ip & 0xff0000) >> 16);
    b = ((ip & 0xff00) >> 8);
    a = ((ip & 0xff));

    zero(buf, 16);
    snprintf((char *)buf, 15, "%d.%d.%d.%d", a, b, c, d);

    return buf;
}
