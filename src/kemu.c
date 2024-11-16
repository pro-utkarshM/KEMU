#include "kemu.h"
#include <string.h>

VM *virtualMachine(Program *pr, int16 prog_size){
    VM *p;
    Program *pp;
    int16 size;

    assert((pr) &&(prog_size));

    size=sizeof(struct s_kemu_vm);
    p=(VM *)malloc($i size);
    if(!p){
        errno=ErrMem;
        return (VM *)0;
    }
    zero($1 p, size);
    pp=(Program *)malloc($i prog_size);
        if(!pp){
        free(p);
        errno=ErrMem;
        return (VM *)0;
    }
    copy(pp, pr, prog_size);
    return p;
}

void copy(void *dest, const void *src, size_t size) {
    memcpy(dest, src, size);
}

int main(int argc, char *argv[]) {
    printf("hello");
    return 0;
}