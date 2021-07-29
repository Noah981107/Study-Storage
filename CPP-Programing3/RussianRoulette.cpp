//러시안 룰렛 게임 실제 게임 실행 파일
#include "NHS_실습03_1.h"

extern int nguns;                                                                //메인파일에서 선언하였던 nguns변수를 외부참조

void playgame(int nplayers, int nbullets)										 //실제 게임을 진행하는 함수 playgame
{
	srand((unsigned)time(NULL));												 //난수가 계속 변화하도록 함

	int start = rand() % nplayers;												 //시작하는 사람을 무작위로 정함
	int count = 0;																 //총에 맞는 사람의 수를 새기위한 변수 count선언 초기값은 0
	printf("게임을 시작하겠습니다. %d번째 부터 시작합니다.\n\n", start + 1);

	for (int i = 0; i < nguns; i++)												 //몇발 권총인지에 따른 게임 순서를 위한 반복문
	{
		int death = rand() % nguns;												 //무작위로 총알이 장전될 탄창 선정
		printf("[%d번째 사람]\t탄알을 장전했습니다.\n", start+1);
		printf("\t\t엔터를 누르면 격발됩니다!\n");
		getchar();
		if (death < nbullets)                                                    //총에 맞은 사람을 표시해줄 조건문
		{
			printf("\t\t%d번째 사람이 총에 맞았습니다.\n\n", start + 1);
			count++;															 //총에 맞은 사람의 숫자를 증가시켜줌
		}
		else
			printf("\t\t살았습니다.\n\n");
		
		if (nbullets == count)													 //총에 맞은 사람의 수와 총알의 갯수가 일치하면 반복문을 빠져나온다.
			break;

		start = (start + 1) % nplayers;											 //다음 순서를 다음 사람에게 넘긴다.
	}
	printf("\n\t\t게임을 종료합니다\n");
}