.section .text
.globl my_sqrt
.type my_sqrt, @function

my_sqrt:

    sqrtsd %xmm0, %xmm0   
    ret