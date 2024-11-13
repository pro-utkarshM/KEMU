/* main.c */
#include <KEMU_utils.h>
#include <stdio.h>
#include <arpa/inet.h>

int main() {
    // Example usage of the utilities

    // Copy function example
    int8 src[] = {1, 2, 3, 4};
    int8 dst[4];
    copy(dst, src, 4);
    printf("Copied data: ");
    printhex(dst, 4, ' ');

    // Port conversion example
    int16 network_port = 0x1234;
    int16 host_port = nstoh(network_port);
    printf("Network port 0x%04x converted to host: 0x%04x\n", network_port, host_port);

    // Zeroing memory
    int8 memory[4];
    zero(memory, 4);
    printf("Memory after zeroing: ");
    printhex(memory, 4, ' ');

    // Convert IP to dotted format
    in_addr_t ip = inet_addr("192.168.1.1");
    printf("IP Address: %s\n", todotted(ip));

    return 0;
}
