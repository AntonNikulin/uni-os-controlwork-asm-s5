ideal
p586
model flat
extrn ExitProcess:proc

dataseg
x dd 5,8,3,7
b dd 1,3,5,7
n dd (b-x)/4
S dd ?

codeseg

begin:
	mov ecx, [n]
	sub ebx, ebx; i=0
	mov esi, ebx; S=0
fori:   mov eax,[b+ebx*4]; bi
	mul [x+ecx*4-4]
	add esi, eax
	inc ebx
	dec ecx
	jnz fori

;	loop fori
	mov[S], esi
	push 0
	call ExitProcess
	end begin

