#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

typedef struct sstring
{
	char ch[max];
	int length;

}sstring;
//����洢

typedef struct hstring
{
	char * ch;
	int length;

}hstring;
//�ѣ���̬���飩�洢

bool inithstring (hstring &L)
{
	L.ch = (char*)malloc(max*sizeof(char));
	L.length = 0;
	return true;
}
//�ѳ�ʼ��

void main ()
//��ֵ��strcpy��&L��ָ�룩��"chars"��;���У�ֱ��=��chars���Ļ�����ı�Lָ��ĵ�ַ���Ǵ���ĸ�ֵ��ʽ��
//strcpy��ֵ��length+����һ�εĸ�ֵҪl.ch+length�ĵ�ַ�£���ֱ�ӣ�����Ϊmalloc�������������char��ַ��
{
	hstring L;
	inithstring (L);
	printf("%p\n",L);//L����Ķѵ�ַ
	strcpy (L.ch ,"abcdefg");
	printf("%s\n", L.ch);
	strcpy(L.ch+5,"aaaa" );
	printf("%s\n", L.ch);//��ȷ�ĸ�ֵ��ʽ
	printf("%p\n",L);//L����Ķѵ�ַ����
	L.ch = "aaaa";//����ĸ�ֵ��ʽ
	printf("%s\n",L.ch);//L��ָ���ַ����malloc���䵽�ѿռ���,��ֵ����ֻ��aaaa
	printf("%p\n",L);//Lָ��ĵ�ַ�����ı�

	return;

}

