#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <KEMU_utils.h>

#define ErrMem  0x01

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

// 16 bit VM --> 65536 Bytes of memory
// AX, BX, CX, DX --> General Purpose registers
// SP and IP
// - Serial COM port
// - Floppy drive

typedef unsigned short int Reg; 

struct s_registers{
    Reg ax;
    Reg bx;
    Reg cx;
    Reg dx;
    Reg sp;
    Reg ip;
};
typedef struct s_registers Registers; 


struct s_cpu{
    Registers r;
};
typedef struct s_cpu CPU; 

/*
Opcode and Args
mov ax, 0x05 
    // 0000 0011 =mov
    // 0000 0000
    // 0000 0101 =0x05
*/

enum e_opcode{
    mov = 0x01,
    nop = 0x02,
    // mov = 0x01,
    // mov = 0x01,
};
typedef enum e_opcode Opcode;

struct s_instrMap{
    Opcode o;
    int8 size;
};
typedef struct s_instrMap IM;

// Define argument structure
typedef int8 Args;
struct s_instruction{
    Opcode o;
    Args a[]; //0 to 2 bytes
};
typedef struct s_instruction Instruction;

typedef int8 Stack[(unsigned int)(-1)];
typedef Instruction Program;

struct s_kemu_vm{
    CPU c;
    Stack s;
    Program *p;
};
typedef struct s_kemu_vm VM; 

static IM instrMap[]={
    { mov, 0x03},
    { nop, 0x01},
    // { Opcode.mov, 0x03},
};

VM *virtualMachine(Program *, int16);
int main(int,char**);