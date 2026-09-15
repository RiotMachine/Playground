; DOS program for doubling user-inputted int

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


double:
           CALL getInt
           ADD  AL, AL
           RET


totalMsg:  db "Int doubled = $"

main:
           CALL double
           MOV  CL, AL
           MOV  DX, newline
           CALL printStr

           MOV  DX, totalMsg
           CALL printStr
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
