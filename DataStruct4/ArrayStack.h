#pragma once
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE	100

inline void error( char* str ) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

class ArrayStack
{
	int		data[MAX_STACK_SIZE];
	int		top;

public:
	ArrayStack() { top = -1; }
	~ArrayStack(){}			
	bool isEmpty() { return top == -1; }
	bool isFull()  { return top == MAX_STACK_SIZE-1; }

	void push ( int e ) {	
		if( isFull() ) error ("스택 포화 에러");
		data[++top] = e;
	}

	int pop ( ) {	
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top--];
	}

	int peek ( ){	
		if( isEmpty() ) error ("스택 공백 에러");
		return data[top];
	}

	void display ( ) {
		printf("[스택 항목의 수 = %2d] ==> ", top+1) ;
		for (int i=0 ; i<=top ; i++ )
			printf("<%2d>", data[i]);
		printf("\n");
	}
};

