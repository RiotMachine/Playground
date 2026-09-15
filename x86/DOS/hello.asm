org 100h

JMP start

msg:    db "Hello, world!", 0Dh, 0Ah, '$'

start:  MOV    DX, msg
        MOV    AH, 09h
        INT    21h

        MOV    AH, 0
        INT    16h

RET


; INT = interrupt, not 'int'
; h == 0x
; ';' is comment in Intel syntax
; "MOV" is a mnemonic representing an opcode
; syntax is INSTRUCTION destination, source
; INT provides a vector pointing to some particular interrupt

; instructions get converted into hex/bits beginning with opcode followed
;     by address or immediate value which will be operated on
; one clock cycle is limited by word size, even if that limitation
;     on modern computers is more about bus wires than about word width
