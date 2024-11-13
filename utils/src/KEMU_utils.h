/* birchutils.h */
#pragma once

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

/* C: Memory Manipulation */
void copy(int8*, int8*, int16);       // Copy memory
void zero(int8*, int16);              // Set memory to zero

/* Network: Convert Network to Host */
int16 nstoh(int16);                   // Convert port from network to host byte order

/* Print: Hexadecimal format */
void printhex(int8*, int16, int8);    // Print a buffer in hex format

/* IP: Convert to dotted-decimal string */
int8* todotted(in_addr_t);            // Convert IP to dotted decimal format
