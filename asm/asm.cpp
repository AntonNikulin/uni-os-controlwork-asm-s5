// asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"

/* function declaration */
int sumArr (int arr[], int len);

// 6.	Найти сумму элементов массива, меньших 20
int _tmain(int argc, _TCHAR* argv[])
{
	int num[] = {9,10};	
/*	
__asm{
			lea ebx, num
			add ebx, 4
			mov eax,[ebx]
			mov ebx, 3

			mov ecx, 1 ;loop counter

lp:
			cmp eax, 12
;			jge l1
			add eax, 1
			loop lp

l1:

				inc ebx
				jmp lp

	}
	*/

	sumArr(num,2);	
		
	return 0;
}

int sumArr (int arr[], int len){
	int cnst = 20;
	int res = 0;

	__asm{
		mov ecx, len	;loop counter
		xor edx,edx
		mov ebx, arr


LP1:
		
		mov eax, [ebx]
		add ebx, 4		;next arr value

		cmp eax, cnst
		jl SUM		

SUM:
		add edx, eax
		dec ecx		
		cmp ecx, 0
		jg LP1

		mov res, edx
	}
	return res;
}