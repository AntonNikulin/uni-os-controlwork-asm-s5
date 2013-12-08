ideal
p586
model flat
extrn ExitProcess: proc
dataseg
arr dd 1,2,3,4,20,21,111,0,4,1
len dd 10 ;arr number elem
cnst dd 20 ;compare to
res dd 0

codeseg			;init block
begin :   		mov ecx, [len]        ;loop counter
                xor edx,edx				;edx to 0
                mov ebx, offset arr		; move adress of the first element in array to ebx



				
LP1:			;main loop	
                
                mov eax, [ebx]  		;arr value to eax


                add ebx, 4                ;get next arr value                
                dec ecx                		;decrement loop counter


                cmp eax, [cnst]			;if array value 
                jl SUM					;less than variable cnst jump to SUM 
                jge LP1					;if value greater or equal: next loop iteration

				
SUM:			;sum array element less than cnst	
                add edx, eax			;in edx is arr sum, add netxt value to it 
                cmp ecx, 0				;if number of loop iteration 
                jg LP1					;greater than 0, start next loop iter


                mov [res], edx			;save result in variable res
		
		push 0
		call ExitProcess

end begin
