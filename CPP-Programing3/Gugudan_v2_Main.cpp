//구구단 게임 V2 메인 파일
#include "NHS_실습03_2.h"

int menu;                                                                                      //선택할 메뉴를 입력받을 전역변수 menu 선언

void main()
{
	srand((unsigned)time(NULL));                                                               //난수가 계속 변화하도록 함
	printf("[메뉴]\n");
	printf("1. 구구단\n2.두 자리 수 곱셈\n3-9. 3-9자리 수 덧셈 문제\n\n");
	printf("하고싶은게임을 선택하세요 : ");
	scanf_s("%d", &menu);

	switch (menu)                                                                              //사용자가 선택한 메뉴에 따라 실행하는 게임이 다름
	{
		case 1:                                                                                //구구단 게임
		{
			printf("[스피드 구구단 게임]\n\n");
			printf("당신의 구구단 실력을 테스트하세요, 기회는 10번입니다.\n\n");
			getchar();
			double score = speedcheck();                                                       //구구단 게임 실행
			printf("\n점수 = %4.1f점 (총 %4.1f초)\n", score, tElapsed);                        //점수 출력
			break;                       
		}
		case 2:                                                                                //두자리 수 곱셈 게임
		{
			printf("[스피드 두자리수 곱셈 게임]\n\n");
			printf("당신의 두자리수 곱셈 실력을 테스트하세요, 기회는 10번입니다.\n\n");
			getchar();
			double score = speedcheck();													   //두자리 수 곱셈 게임 실행
			printf("\n점수 = %4.1f점 (총 %4.1f초)\n", score, tElapsed);						   //점수 출력
			break;
		}
		default:                                                                               //n자리수 덧셈 게임
		{
			printf("[스피드 %d자리수 게임]\n\n", menu);
			printf("당신의 덧셈 실력을 테스트하세요, 기회는 10번입니다.\n\n");
			getchar();
			double score = speedcheck();													   //n자리수 덧셈 게임 실행
			printf("\n점수 = %4.1f점 (총 %4.1f초)\n", score, tElapsed);						   //점수 출력
			break;
		}
	}
}