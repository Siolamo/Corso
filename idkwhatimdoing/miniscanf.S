.globl t_scanf

.section .bss
buffer:
    .skip 256

.section .text

t_scanf:
    pushq %rbp
    movq %rsp, %rbp

    pushq %rbx
    pushq %r12
    pushq %r13
    pushq %r14
    pushq %r15

    movq %rdi, %r12        # fmt
    leaq buffer(%rip), %r13   # buffer

    # read(0, buffer, 255)
    xorq %rax, %rax
    xorq %rdi, %rdi
    movq %r13, %rsi
    movq $255, %rdx
    syscall

    movb $0, (%r13,%rax,1)

    movq %r13, %r14        # input ptr
    leaq 16(%rbp), %r15    # args ptr

    xorq %rbx, %rbx        # count

fmt_loop:
    movb (%r12), %al
    testb %al, %al
    je end

    cmpb $'%', %al
    jne next_fmt

    incq %r12
    movb (%r12), %al

    call skip_spaces

    cmpb $'d', %al
    je scan_int

    cmpb $'s', %al
    je scan_str

    cmpb $'c', %al
    je scan_char

next_fmt:
    incq %r12
    jmp fmt_loop

# -----------------------

skip_spaces:
ss:
    movb (%r14), %al
    cmpb $' ', %al
    je ss_inc
    cmpb $10, %al
    jne ss_end
ss_inc:
    incq %r14
    jmp ss
ss_end:
    ret

# -----------------------

scan_int:
    movq (%r15), %rdi
    addq $8, %r15

    xorq %rax, %rax
    movq $1, %rcx

    movb (%r14), %bl
    cmpb $'-', %bl
    jne si_loop

    movq $-1, %rcx
    incq %r14

si_loop:
    movb (%r14), %bl
    cmpb $'0', %bl
    jl si_done
    cmpb $'9', %bl
    jg si_done

    imulq $10, %rax
    subb $'0', %bl
    addq %rbx, %rax

    incq %r14
    jmp si_loop

si_done:
    imulq %rcx, %rax
    movq %rax, (%rdi)

    incq %rbx
    incq %r12
    jmp fmt_loop

# -----------------------

scan_str:
    movq (%r15), %rdi
    addq $8, %r15

ss_loop:
    movb (%r14), %al
    testb %al, %al
    je ss_done

    cmpb $' ', %al
    je ss_done

    cmpb $10, %al
    je ss_done

    movb %al, (%rdi)
    incq %rdi
    incq %r14
    jmp ss_loop

ss_done:
    movb $0, (%rdi)

    incq %rbx
    incq %r12
    jmp fmt_loop

# -----------------------

scan_char:
    movq (%r15), %rdi
    addq $8, %r15

    movb (%r14), %al
    movb %al, (%rdi)
    incq %r14

    incq %rbx
    incq %r12
    jmp fmt_loop

# -----------------------

end:
    movq %rbx, %rax

    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rbx

    leave
    ret