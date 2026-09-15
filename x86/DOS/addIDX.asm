; DOS program for total-summing a decrementing index

org 100h

JMP main
newline:   db   0Dh, 0Ah, '$'


printChar:
           MOV  AH, 2
           INT  21h
           RET

printStr:
           MOV  AH, 9
           INT  21h
           RET


prompt:    db "Gimme an index: $"

getInt:
           MOV  DX, prompt
           CALL printStr
           MOV  AH, 1
           INT  21h
           SUB  AL, '0'
           RET


total:     db 0

addLoop:
           CALL getInt
           XOR  CH, CH
           MOV  CL, AL
           XOR  BX, BX
           addIDX:
           ADD  BL, CL
           LOOP addIDX
           MOV  [total], BL
           RET


totalMsg: db "IDX sum = $"

main:
           CALL addLoop
           MOV  DX, newline
           CALL printStr

           MOV  DX, totalMsg
           CALL printStr

           MOV  CL, [total]
           CMP  CL, 10
           JL   printSingle

           MOV  AL, CL
           XOR  AH, AH
           MOV  BL, 10
           DIV  BL
           MOV  CL, AH
           ADD  AL, '0'
           MOV  DL, AL
           CALL printChar

           printSingle:
           ADD  CL, '0'
           MOV  DL, CL
           CALL printChar

RET
