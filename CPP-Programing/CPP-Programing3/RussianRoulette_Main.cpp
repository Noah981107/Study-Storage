//러시안 룰렛 게임 V2 메인 파일
#include "NHS_실습03_1.h"

int nguns;                                              //사용자로 부터 입력받을 몇발권총인지를 입력받는 전역 변수 nguns 선언

void main()
{
	int nplayers, nbullets;                             //몇명,몇발을 입력받는 변수 선언

	printf("몇발짜리 총을 쓰시겠습니까? : ");
	scanf_s("%d", &nguns);
	printf("몇명이서 하시겠습니까? : ");
	scanf_s("%d", &nplayers);
	printf("총알은 몇발 하시겠습니까? : ");
	scanf_s("%d", &nbullets);

	playgame(nplayers, nbullets);                       //게임 시작 함수 실행                      
}