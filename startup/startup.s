    .syntax unified
    .cpu cortex-m3
    .thumb

    .section .isr_vector,"a",%progbits
    .type g_pfnVectors, %object
    .word _estack
    .word Reset_Handler
    .word NMI_Handler
    .word HardFault_Handler
    .word Default_Handler
    .word Default_Handler
    .word Default_Handler
    .word Default_Handler
    .word Default_Handler
    .word Default_Handler
    .word Default_Handler
    .word SVC_Handler
    .word Default_Handler
    .word Default_Handler
    .word PendSV_Handler
    .word SysTick_Handler

    .size g_pfnVectors, .-g_pfnVectors

    .section .text
.weak Reset_Handler
.weak NMI_Handler
.weak HardFault_Handler
.weak SVC_Handler
.weak PendSV_Handler
.weak SysTick_Handler
.weak Default_Handler

Reset_Handler:
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata
    b copy_data

copy_bss:
    ldr r0, =_sbss
    ldr r1, =_ebss
    movs r2, #0
    cmp r0, r1
    beq data_done
zero_loop:
    str r2, [r0], #4
    cmp r0, r1
    bcc zero_loop
    b data_done

copy_data:
    cmp r1, r2
    beq copy_bss
    ldr r3, [r0], #4
    str r3, [r1], #4
    b copy_data

data_done:
    bl SystemInit
    bl main
    b .

NMI_Handler:
    b Default_Handler

HardFault_Handler:
    b Default_Handler

SVC_Handler:
    b Default_Handler

PendSV_Handler:
    b Default_Handler

SysTick_Handler:
    b SysTick_Handler

Default_Handler:
    b .
