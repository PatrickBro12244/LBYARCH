;Kyle Patrick Roland M. Francisco
;SS1
section .data
    format_msg1 db "Assembly function stencil_1d is called", 10, 0
    format_msg2 db "n = %ld, X = %p, Y_asm = %p", 10, 0

section .text
bits 64
default rel
global stencil_1d
extern printf

stencil_1d:
    push rbp
    mov rbp, rsp
    and rsp, -16

    mov rcx, rdi    ; Load n

    ; Check if length is valid (greater than 6)
    cmp rcx, 6
    jle .end_loop   ; Exit if length is less than or equal to 6

.loop:
    movsd xmm0, [rsi + rcx * 8]   ; Load X[i]
    movsd xmm1, [rsi + (rcx + 1) * 8]   ; Load X[i+1]
    movsd xmm2, [rsi + (rcx + 2) * 8]   ; Load X[i+2]
    movsd xmm3, [rsi + (rcx + 3) * 8]   ; Load X[i+3]
    movsd xmm4, [rsi + (rcx - 1) * 8]   ; Load X[i-1]
    movsd xmm5, [rsi + (rcx - 2) * 8]   ; Load X[i-2]
    movsd xmm6, [rsi + (rcx - 3) * 8]   ; Load X[i-3]

    ; Perform necessary computations using scalar SIMD instructions
    addsd xmm0, xmm1
    addsd xmm0, xmm2
    addsd xmm0, xmm3
    addsd xmm0, xmm4
    addsd xmm0, xmm5
    addsd xmm0, xmm6

    ; Store the result in Y
    movsd [rdx + rcx * 8], xmm0

    ; Decrement loop counter
    sub rcx, 1
    jnz .loop

.end_loop:
    leave
    ret
