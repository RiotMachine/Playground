; 32-bit Linux for doubling an int

section .bss
  usr_input resb 1
  digit     resw 1

section .data
  prompt:     db "Gimme an int 0-9: "
  promptLen:  equ $-prompt
  result:     db "Its double: "
  resultLen   equ $-result


section .text
  global _start

flushBuf:
  CALL  getChar
  CMP   byte[usr_input], 0Ah
  JNE   flushBuf
  RET

getChar:
  MOV   EAX, 3
  MOV   EBX, 0
  MOV   ECX, usr_input
  MOV   EDX, 1
  INT   80h
  RET

getInt:
  MOV   ECX, prompt
  MOV   EDX, promptLen
  CALL  printStr
  CALL  getChar
  MOVZX AX, byte[usr_input]
  SUB   AL, '0'
  RET

printStr:
  MOV   EAX, 4
  MOV   EBX, 1
  INT   80h
  RET

printDigit:
  MOV  ECX, digit
  MOV  EDX, 1
  CALL printStr
  RET


_start:
    CALL  getInt
    ADD   AX, AX
    XOR   EDI, EDI
    MOV   DI, AX

    MOV   ECX, result
    MOV   EDX, resultLen
    CALL  printStr
    CMP   DI, 10
    JL    printSingle

    MOV   EAX, EDI
    XOR   EDX, EDX
    MOV   DI, 10
    DIV   EDI
    MOV   DI, DX
    ADD   AX, '0'
    MOV   [digit], AX
    CALL  printDigit

    printSingle:
    ADD   DI, '0'
    MOV   [digit], DI
    CALL  printDigit

    CALL  flushBuf
    MOV   byte[digit], 0Ah
    CALL  printDigit
    MOV   EAX, 1
    MOV   EBX, 0            ; Exit with return "code" of 0 (no error)
    INT   80h
