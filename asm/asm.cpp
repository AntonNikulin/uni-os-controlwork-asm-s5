// asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"

// 6.	Найти сумму элементов массива, меньших 20
int _tmain(int argc, _TCHAR* argv[])
{
	
	int num[] = {9,10};
		__asm{
			lea ebx, num
			add ebx, 4
			mov eax,[ebx]
			mov ebx, 3

			mov ecx, 4

lp:
			cmp eax, 12
			jge l1
			add eax, 1
			loop lp
			mov num, eax

l1:

				inc ebx
				jmp lp

	}
		/*std::cout<<num;
		std::cin>>num;*/
	return 0;
}

