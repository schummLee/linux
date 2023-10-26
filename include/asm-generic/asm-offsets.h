#ifndef ASM_OFFSET_H
#define ASM_OFFSET_H

#ifdef __cplusplus
extern "C" {
#endif

#include <generated/asm-offsets.h>
#include <stdint.h>

#define GET_OFFSET(var, offset_ptr) \
    __asm__ ("lea (%1), %0" : "=r"(offset_ptr) : "r"(&(var)))

static inline uintptr_t get_offset(void* var) {
    uintptr_t address;
    __asm__ ("lea (%1), %0" : "=r"(address) : "r"(var));
    return address;
}

#ifdef __cplusplus
}
#endif

#endif
