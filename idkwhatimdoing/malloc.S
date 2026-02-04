.global my_malloc
.global my_free

.section .bss
heap_start:
    .quad 0
heap_end:
    .quad 0

.section .text


my_malloc:
    push %rbp
    mov %rsp, %rbp

    mov %rdi, %rsi        

    # initialize heap if needed
    movq heap_start(%rip), %rax
    test %rax, %rax
    jne scan_heap

    # brk(0)
    mov $12, %rax         
    xor %rdi, %rdi
    syscall

    movq %rax, heap_start(%rip)
    movq %rax, heap_end(%rip)

scan_heap:
    movq heap_start(%rip), %rbx

scan_loop:
    cmpq heap_end(%rip), %rbx
    je extend_heap

    movq (%rbx), %rcx     
    movq 8(%rbx), %rdx    

    test %rdx, %rdx
    jne next_block

    cmp %rcx, %rsi
    jl next_block

    # found free block
    movq $1, 8(%rbx)
    lea 16(%rbx), %rax
    pop %rbp
    ret

next_block:
    add $16, %rbx
    add %rcx, %rbx
    jmp scan_loop

extend_heap:
    movq heap_end(%rip), %rax
    mov %rax, %rdx          

    add $16, %rax
    add %rsi, %rax

    mov %rax, %rdi          
    mov $12, %rax
    syscall

    movq %rax, heap_end(%rip)

    # write header
    mov %rsi, (%rdx)        
    movq $1, 8(%rdx)        

    lea 16(%rdx), %rax     
    pop %rbp
    ret


my_free:
    push %rbp
    mov %rsp, %rbp

    test %rdi, %rdi
    je free_end

    sub $16, %rdi
    movq $0, 8(%rdi)

free_end:
    pop %rbp
    ret

.section .note.GNU-stack,"",@progbits