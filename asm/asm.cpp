// asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "string"

using namespace std;

/* function declaration */
int sumArr (int arr[], int len);
string int_array_to_string(int int_array[], int size_of_array);

// 6.	Найти сумму элементов массива, меньших 20
int _tmain(int argc, _TCHAR* argv[])
{
	int num[] = {1,2,3,4,20,21,111,55,0,-4};
	cout<<"Input: 1 2 3 4 20 21 111 55 0 -4\nOutput:";
	cout<<to_string(sumArr(num,10));
	cin.ignore();

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
		dec ecx		

		cmp eax, cnst
		jl SUM
		jge LP1

SUM:
		add edx, eax
		cmp ecx, 0
		jg LP1

		mov res, edx
	}
	return res;
}