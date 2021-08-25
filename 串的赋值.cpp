#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct sstring
{
	char ch[max];
	int length;

}sstring;
//数组存储

typedef struct hstring
{
	char * ch;
	int length;

}hstring;
//堆（动态数组）存储

bool inithstring (hstring &L)
{
	L.ch = (char*)malloc(max*sizeof(char));
	L.length = 0;
	return true;
}
//堆初始化

void main ()
//赋值用strcpy（&L（指针），"chars"）;进行，直接=“chars”的话，会改变L指针的地址，是错误的赋值方式。
//strcpy赋值后，length+，下一次的赋值要l.ch+length的地址下（能直接＋是因为malloc申请的是连续的char地址）
{
	hstring L;
	inithstring (L);
	printf("%p\n",L);//L分配的堆地址
	strcpy (L.ch ,"abcdefg");
	printf("%s\n", L.ch);
	strcpy(L.ch+5,"aaaa" );
	printf("%s\n", L.ch);//正确的赋值方式
	printf("%p\n",L);//L分配的堆地址不变
	L.ch = "aaaa";//错误的赋值方式
	printf("%s\n",L.ch);//L的指向地址不是malloc分配到堆空间了,故值错误只有aaaa
	printf("%p\n",L);//L指向的地址发生改变

	return;

}

