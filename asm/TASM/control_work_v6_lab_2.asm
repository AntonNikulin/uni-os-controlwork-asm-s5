ideal
p586
model flat
extrn ExitProcess: proc
dataseg
arr dd 1,2,3,4,20,21,111,0,4,1
len dd 10 ;arr number elem
cnst dd 20 ;compare to
res dd 0

codeseg			;init block  	начальные значения регистров
begin :   		mov ecx, [len]        ;loop counter	 счетчик циклов
                xor edx,edx				;edx to 0	обнулим 
                mov ebx, offset arr		; get addres of the first element in array and save it, получить адрес первого эл. массива и записать его



				
LP1:			;main loop	главный цикл
                
                mov eax, [ebx]  		;arr value to eax получить значение хранящяеся по адрессу


                add ebx, 4                ;get next arr value   следующий элемент массива
                dec ecx                		;decrement loop counter уменьшить счетчик цикла

		;condition проверка УСЛОВИЯ
                cmp eax, [cnst]			;if array value				если текущее значения массива 
                jl SUM				;less than variable cnst jump to SUM 	меньше переменной cnst перейти сумированию
                jge LP1				;if value greater or equal: next loop iteration	если больше: следующий проход цикла

				
SUM:		;sum array element less than cnst	сумировать элементы меньше 20 (cnst)
                add edx, eax			;in edx is arr sum, add netxt value to it прибавить текущее значение массива к общему результату в edx
                cmp ecx, 0			;if number of loop iteration если это не последний проход цикла
                jg LP1				;greater than 0, start next loop iter продолжить обход массива


                mov [res], edx			;save result in variable res сохранить результат сумирования в res
		
		push 0
		call ExitProcess

end begin
