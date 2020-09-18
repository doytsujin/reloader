#ifndef _SYS_SYSCALL_H_
#define _SYS_SYSCALL_H_

#include <sys/size_t.h>
#include <sys/arch/syscallnums.h>

typedef size_t syscall_result_t;

// TODO: should I return an unsigned short? only need 16 bits
static inline unsigned syscall_errno(syscall_result_t result) {
  return (result > (size_t)-4096UL) ? (unsigned)-result : 0;
}

syscall_result_t asm_syscall0(size_t num);
syscall_result_t asm_syscall1(size_t a, size_t num);
syscall_result_t asm_syscall2(size_t a, size_t b, size_t num);
syscall_result_t asm_syscall3(size_t a, size_t b, size_t c, size_t num);

#define syscall0(num)       asm_syscall0(num)
#define syscall1(num,a)     asm_syscall1(a,num)
#define syscall2(num,a,b)   asm_syscall2(a,b,num)
#define syscall3(num,a,b,c) asm_syscall3(a,b,c,num)

#endif
