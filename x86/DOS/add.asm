; DOS program for summing hard-coded number of ints

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


prompt:    db "Gimme an int: $"

getInt:
           MOV  DX, prompt
           CALL printStr
           MOV  AH, 1
           INT  21h
           SUB  AL, '0'
           RET


addLoop:
           CALL getInt
           ADD  BL, AL
           MOV  DX, newline
           CALL printStr
           LOOP addLoop
           RET


i:         db 3
result:    db 0
resultMsg: db "N = $"

main:
           MOV  CX, [i]
           MOV  BL, 0
           CALL addLoop
           MOV  [result], BL

           MOV  DX, resultMsg
           CALL printStr

           MOV  CL, [result]
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
