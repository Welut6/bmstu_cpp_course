#include "int2str.h"
#include <assert.h>
#include "stdio.h"

char* int2str(int number)
{
	char* str;
	char* strt;
	int z=0, i=0;

	if (number==0) { //проверка на 0
		str = "0";
		return str;	
	}
	if (number<0 && number!=0) { //проверка на знак
		number=-number;
		z=1;
	}
	do{ //цикл с пост условием
		str[i++]=number%10+'0';
		// +'0' нужен что бы отображаласть именно цифра, дело в табл. ASCII там 0 на 48 месте, например number=5 +0 это будет 53 как раз номер 5-ки в ASCII
		number/=10;
	}while(number>0);
	//разворачиваем строку
	for (int j=0; j<i; j++){
		strt[j] = str[i-j-1];
	} 
	return strt;
}
