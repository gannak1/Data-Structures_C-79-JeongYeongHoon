.section .data
msg:
    .string "Hello World!\n"

.section .text
.globl main

main:
    mov $msg, %rdi      
    call puts           

    mov $0, %eax
    ret