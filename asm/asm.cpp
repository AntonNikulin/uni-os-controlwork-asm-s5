// asm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include <sstream>

using namespace std;

/* function declaration */
int sumArr (int arr[], int len);


///////////////////////////////////////////////////
//
// 6.	Найти сумму элементов массива, меньших 20
//
/////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{	
	int num[] = {1,2,3,4,20,21,111,55,0,-4, 1}; //test array

	//out
	std::stringstream ss;
	int size = sizeof(num)/sizeof(*num);
	for (int i=0; i<size;i++){
		ss<<num[i]<<" ";
	}
	
	cout<<"Test array input: "<<ss.str()<<"\t| "<<to_string(size)<<"\nOutput:";
	cout<<to_string(sumArr(num,size));
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