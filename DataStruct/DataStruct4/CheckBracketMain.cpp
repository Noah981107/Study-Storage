#include "ArrayStack.h"
{2
bool CheckMatching( char* filename ) {
	FILE *fp = fopen( filename, "r" );
	if( fp == NULL )
		error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;		
	int nChar = 0;		
	ArrayStack stack;	
	while ( (ch = getc(fp)) != EOF ) {
		if( ch == '\n' ) nLine++;
		nChar++;
		if( ch == '[' || ch == '(' || ch == '{' )
			stack.push(ch);
		else if( ch == ']' || ch == ')' || ch == '}' ) {
			int prev = stack.pop();
			if( ( ch == ']' && prev != '[' )
				||  ( ch == ')' && prev != '(' )
				||  ( ch == '}' && prev != '{' ) ) break;
		}
	}
	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename );
	if( !stack.isEmpty() )
		printf("  Error: �����߰�! (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar );
	else 
		printf("  OK: ��ȣ�ݱ����� (���μ�=%d, ���ڼ�=%d)\n\n", nLine,nChar);
	return stack.isEmpty();
}

// �� �Լ�
void main()
{
	CheckMatching("ArrayStack.h");
	CheckMatching("03��-CheckBracketMain.cpp");
}