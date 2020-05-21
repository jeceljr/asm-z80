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
		ASSUME		CS:__TEXT,DS:NOTHING
		PUBLIC		_INICIA,_ABRE,_CRIA,_LEIA,_ESCREVA,_FECHA
		PUBLIC		_ACABA,_RESET

_INICIA		PROC		NEAR
		PUSH		DS
		PUSH		ES
		MOV		AX,3524H
		INT		21H
		MOV		AX,DATA1
		MOV		DS,AX
		MOV		AX,ES
		MOV		DS:[SALVA_ES],AX
		MOV		DS:[SALVA_BX],BX
		XOR		DX,DX
		MOV		AX,CODIGO
		MOV		DS,AX
		MOV		AX,2524H
		INT		21H
		POP		ES
		POP		DS
		RET
_INICIA		ENDP



_ACABA		PROC		NEAR
		PUSH		DS
		MOV		AX,DATA1
		MOV		DS,AX
		MOV		DX,DS:[SALVA_BX]
		MOV		AX,DS:[SALVA_ES]
		MOV		DS,AX
		MOV		AX,2524H
		INT		21H
		POP		DS
		MOV		AH,2
		XOR		BH,BH
		MOV		DX,1800H
		INT		10H
		RET
_ACABA		ENDP



_RESET		PROC		NEAR
		MOV		AH,0DH
		INT		21H
		RET
_RESET		ENDP



_ABRE		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		DS
		MOV		DX,[BP+primeiro]
		MOV		AX,[BP+segundo]
		MOV		DS,AX
		MOV		AX,3D02H
		INT		21H
		JNC		ABRE
		NEG		AX
ABRE:
		POP		DS
		POP		BP
		RET
_ABRE		ENDP





_CRIA		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		DS
		MOV		CX,20H
		MOV		DX,[BP+primeiro]
		MOV		AX,[BP+segundo]
		MOV		DS,AX
		MOV		AH,3CH
		INT		21H
		JNC		CRIA
		NEG		AX
CRIA:
		POP		DS
		POP		BP
		RET
_CRIA		ENDP



_LEIA		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		DS
		MOV		BX,[BP+primeiro]
		MOV		DX,[BP+segundo]
		MOV		AX,[BP+terceiro]
		MOV		CX,[BP+quarto]
		MOV		DS,AX
		MOV		AH,3FH
		INT		21H
		JNC		LEIA
		NEG		AX
LEIA:
		POP		DS
		POP		BP
		RET
_LEIA		ENDP



_ESCREVA	PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		PUSH		DS
		MOV		BX,[BP+primeiro]
		MOV		DX,[BP+segundo]
		MOV		AX,[BP+terceiro]
		MOV		DS,AX
		MOV		CX,[BP+quarto]
		MOV		AH,40H
		INT		21H
		JNC		ESCREVA
		NEG		AX
ESCREVA:
		POP		DS
		POP		BP
		RET
_ESCREVA	ENDP



_FECHA		PROC		NEAR
		PUSH		BP
		MOV		BP,SP
		MOV		BX,[BP+primeiro]
		MOV		AH,3EH
		INT		21H
		JC		FECHA
		XOR		AX,AX
FECHA:
		POP		BP
		RET
_FECHA		ENDP

__TEXT		ENDS





DATA1		SEGMENT		PARA PUBLIC 'DATA'

SALVA_ES	DW		?
SALVA_BX	DW		?

DATA1		ENDS





CODIGO		SEGMENT		PARA PUBLIC 'CODE'
		ASSUME		NOTHING

INT_24		PROC		FAR
		MOV		AL,3
		IRET
INT_24		ENDP

CODIGO		ENDS

		END
