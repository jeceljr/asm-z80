primeiro	EQU		4	; 6 para modelo HUGE, 4 para COMPACT
segundo		EQU		6	; 8 para modelo HUGE, 6 para COMPACT
terceiro	EQU		8	; 10 para modelo HUGE, 8 para COMPACT
quarto		EQU		10	; 12 para modelo HUGE, 10 para COMPACT
;
;
; NAO ESQUECA DE TROCAR OS TIPOS DAS ROTINAS -> modelo HUGE    : FAR
;                                               modelo COMPACT : NEAR
;
;

__TEXT		SEGMENT		BYTE PUBLIC 'CODE'
		ASSUME		CS:__TEXT
		PUBLIC		_LECAR,_CURSOR,_CLS,_IMPCAR,_REVERSO
		PUBLIC		_PAGINA_PRINT,_WRITE



_LECAR		PROC		NEAR
LECAR_1:
		MOV		AH,1
		INT		16H
		JZ		LECAR_2
		MOV		AH,0
		INT		16H
		JMP		LECAR_1
LECAR_2:
		MOV		AH,1
		INT		16H
		JNZ		LECAR_2
		MOV		AH,0
		INT		16H
		RET
_LECAR		ENDP



_CURSOR		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		MOV		AH,[BP+primeiro]
		CMP		AH,1
		JNZ		CURSOR_1
		MOV		CH,[BP+segundo]
		MOV		CL,[BP+terceiro]
		JMP		CURSOR_3
CURSOR_1:
		XOR		BX,BX
		CMP		AH,2
		JNZ		CURSOR_2
		MOV		DL,[BP+segundo]
		MOV		DH,[BP+terceiro]
		JMP		CURSOR_3
CURSOR_2:
		MOV		AH,3
CURSOR_3:
		INT		10H
		POP		BP
		RET
_CURSOR		ENDP



_IMPCAR		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		MOV		AH,9
		MOV		BH,0
		MOV		CX,[BP+primeiro]
		MOV		AL,[BP+segundo]
		MOV		BL,[BP+terceiro]
		INT		10H
		POP		BP
		RET
_IMPCAR		ENDP



_REVERSO	PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		MOV		DL,[BP+primeiro]
		MOV		DH,[BP+segundo]
		MOV		CX,[BP+terceiro]
		MOV		BL,[BP+quarto]
		MOV		BH,0
REVERSO_1:
		MOV		AH,2
		INT		10H
		MOV		AH,8
		INT		10H
		PUSH		CX
		MOV		CX,1
		MOV		AH,9
		INT		10H
		POP		CX
		INC		DL
		LOOP		REVERSO_1
		MOV		DX,1900H
		MOV		AH,2
		INT		10H
		POP		BP
		RET
_REVERSO	ENDP



_PAGINA_PRINT	PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		DS
		PUSH		SI
		MOV		SI,[BP+primeiro]
		MOV		AX,[BP+segundo]
		MOV		DS,AX
		MOV		BX,[BP+terceiro]
		MOV		CX,1920
		XOR		DX,DX
PAGINA_1:
		MOV		AH,2
		INT		10H
		PUSH		CX
		MOV		CX,1
		MOV		AH,9
		MOV		AL,[SI]
		INT		10H
		POP		CX
		INC		SI
		INC		DL
		CMP		DL,80
		JL		PAGINA_2
		INC		DH
		XOR		DL,DL
PAGINA_2:
		LOOP		PAGINA_1
		INC		DH
		MOV		AH,2
		INT		10H
		POP		SI
		POP		DS
		POP		BP
		RET
_PAGINA_PRINT	ENDP



_WRITE		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		ES
		PUSH		SI
		MOV		SI,[BP+primeiro]
		MOV		AX,[BP+segundo]
		MOV		ES,AX
		MOV		AH,03H
		XOR		BH,BH
		INT		10H
		MOV		AH,08H
		INT		10H
		MOV		BL,AH
WRITE_1:
		MOV		AL,ES:[SI]
		CMP		AL,0
		JZ		WRITE_2
		MOV		AH,09H
		MOV		CX,1
		INT		10H
		INC		DL
		MOV		AH,02H
		INT		10H
		INC		SI
		JMP		WRITE_1
WRITE_2:
		POP		SI
		POP		ES
		POP		BP
		RET
_WRITE		ENDP



_CLS		PROC		NEAR
;		MOV		AX,3
;		INT		10H
		mov		cx,25
		xor		dx,dx
		mov		bx,0fh
cls_1:
		mov		ah,2
		int		10h
		push		cx
		mov		ax,0920h
		mov		cx,80
		int		10h
		pop		cx
		inc		dh
		loop		cls_1

		RET
_CLS		ENDP

__TEXT		ENDS
		END
