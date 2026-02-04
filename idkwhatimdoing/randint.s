.section .data
    .align 8
seed:
    .long 1
    .long 0          # padding 

.section .text

.globl my_srand
.type my_srand, @function
my_srand:

    # ABI: primo argomento -> %edi (unsigned int)
    mov %edi, seed(%rip)
    ret


.globl my_rand
.type my_rand, @function
my_rand:

    mov seed(%rip), %eax        # eax = seed

    imull $1103515245, %eax     # eax *= a
    addl  $12345, %eax          # eax += c

    mov %eax, seed(%rip)        # salva nuovo seed

    ret
