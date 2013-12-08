ideal
p586
model flat
extrn ExitProcess: proc
dataseg
arr dd 1,2,3,4,20,21,111,0,4,1
len dd 10 ;arr number elem
cnst dd 20 ;compare to
res dd 0

codeseg
begin :   		mov ecx, [len]        ;loop counter
                xor edx,edx
                mov ebx, offset arr




LP1:
                
                mov eax, [ebx]  ;arr value to eax


                add ebx, 4                ;next arr value                
                dec ecx                


                cmp eax, [cnst]
                jl SUM
                jge LP1


SUM:
                add edx, eax
                cmp ecx, 0
                jg LP1


                mov [res], edx
		
		push 0
		call ExitProcess

end begin
