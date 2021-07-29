//구구단을 절차적, 구조적, 객체지향적으로 프로그래밍하기
#include <stdio.h>

void printGugudan_procedural()						      //구구단을 절차적 프로그래밍 하는 함수
{
	int i;												  //단에 곱해야하는 변수
	int dan = 2;										  //단을 지정하는 변수, 초기값 2											
	printf("[절차적 프로그래밍]\n");  					  //절차적 프로그래밍을 알리는 출력
	printf("[구구단 2-9단]\n");       					  //2-9단까지 출력할것이라고 알리는 출력
loop1:                                					  //2-9단까지 변경되는 루프
	if (dan <= 9)                     					  //9단까지 진행
	{
		i = 1;                        					  //변수i의 초기값 지정
	loop2:                               				  //dan값에 대하여 곱해지는 i가 변경되는 루프
		if (i <= 9)                   					  //9까지 곱함
		{
			printf("%d x %d = %-3d\n",dan, i, dan * i);   //구구단을 출력
			i++;                                          //한번 진행후 i의 값 1증가
			goto loop2;									  //loop2로 돌아감
		}
		dan = dan+1;                                      //1-9까지의 i를 곱했으면 dan을 1증가
		printf("\n");                                     //구구단끼리의 구별이 쉽게 한칸 추가 
		goto loop1;                                       //loop1으로 돌아감
	}
}

void printGugudan_structural()                            //구구단을 구조적 프로그래밍 하는 함수
{
	int i, dan;										      //단에 곱해야하는 변수와, 단을 지정해야하는 변수 지정
	printf("[구조적 프로그래밍]\n");                      //구조적프로그래밍을 알리는 출력
	printf("[구구단 2-9단]\n");                           //2-9단까지 출력할것이라고 알리는 출력
	for (i = 1; i <= 9; i++)                              //단에 곱해야하는 i의 값이 1-9까지
	{ 
		for (dan=2; dan <= 5; dan++)				      //먼저, 2-5단까지 실행(가독성을 높이기 위하여 6-9단은 나중에 진행
			printf("%d x %d = %-4d", dan, i, dan * i);    //구구단을 출력
		printf("\n");                                     //한칸 내림
	}
	printf("\n");                                         //한칸 내림
	for (i = 1; i <= 9; i++)						      //단에 곱해야하는 i의 값이 1-9까지
	{
		for (dan = 6; dan <= 9; dan++)                    //앞에서 2-5단을 진행하였기에, 나머지 6-9단 진행
			printf("%d x %d = %-4d", dan, i, dan * i);    //구구단을 출력
		printf("\n");                                     //한칸 내림
	}
}

class Gugudan										     //구구단을 객체지향적 프로그래밍 하는 클래스를 지정(가독성을 높이기 위하여 2-5, 6-9단을 나누어서 클래스를 구성)
{
private:
	int times;                                           //클래스 안에서의 변수 times 지정
	int number;										     //클래스 안에서의 변수 number 지정
public:
	Gugudan() { set(2, 5); }                               //구구단을 2-5단까지 먼저 진행(셋팅실시)
	~Gugudan() {}

	void set(int t, int n) { times = t; number = n; }    //변수 times,number를 set의 변수로 받는다.

	void play(int dan)                                   //구구단을 출력하는 함수                                     
	{
		for (int i = times; i <= number; i++)            //구구단을 가로로출력하기 위하여 i값을 받아 실행
			printf("%d x %d = %-4d", i, dan, dan * i);   //구구단을 가로로 출력
		printf("\n");                                    //한칸 내림
	}
};
class Gugudan1											 //구구단을 객체지향적 프로그래밍 하는 클래스를 지정 (6-9단을 곱하는 클래스를 구성)
{
private:
	int times;											 //클래스 안에서의 변수 times 지정
	int number;											 //클래스 안에서의 변수 number 지정
public:
	Gugudan1() { set(6, 9); }							   //구구단을 6-9단까지 먼저 진행(셋팅실시)
	~Gugudan1() {}

	void set(int t, int n) { times = t; number = n; }	 //변수 times,number를 set의 변수로 받는다.

	void play(int dan)									 //구구단을 출력하는 함수                                     
	{
		for (int i = times; i <= number; i++)			 //구구단을 가로로출력하기 위하여 i값을 받아 실행
			printf("%d x %d = %-4d", i, dan, dan * i);	 //구구단을 가로로 출력
		printf("\n");									 //한칸 내림
	}
};

int main(void)                                           //각각의 함수를 실행하기위한 메인함수
{
	int k,j;                                             //객체지향적 구구단을 실행시키기위한 변수 지정
	printGugudan_procedural();                           //절차적 구구단 함수 실행 
	printf("\n");									     //한칸내림
	printGugudan_structural();							 //구조적 구구단 함수 실행
	printf("\n");									     //한칸내림
	printf("[객체지향 프로그래밍]\n");                   //객체지향 프로그래밍 구구단을 출력하겠다고 알림
	printf("[구구단 2-9단]\n");                          //구구단을 2-9까지 진행한다고 출력
	Gugudan mygame;                                      //2-5단까지의 구구단 클래스
	{
		for (k = 1; k <= 9; k++)                         //몇단을 실행하는지에 대한 k의 값을 변환-> 클래스의 dan값을 변환
			mygame.play(k);                              //바뀌는 k의 값에 대한 Gugudan 클래스의 play 실행
	}
	printf("\n");
	Gugudan1 mygame1;                                    //6-9단까지의 구구단 클래스
	{
		for (k = 1; k <= 9; k++)                         //몇단을 실행하는지에 대한 k의 값을 변환-> 클래스의 dan값을 변환
			mygame1.play(k);							 //바뀌는 k의 값에 대한 Gugudan 클래스의 play 실행
	}
}