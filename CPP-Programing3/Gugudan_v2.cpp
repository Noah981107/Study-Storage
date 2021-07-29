//구구단 게임 V2 실행 파일
#include "NHS_실습03_2.h"

static int Numgames = 0;                                            //실행 게임수 Numgames 선언, 초기값 0
static int Numwins = 0;                                             //맞춘 문제 게임수 Numwins 선언, 초기값 0 
static double Score = 0;                                            //환산된 점수 Score 선언, 초기값 0
double tElapsed = 0;                                                //게임 소요 시간 tElapsed 선언, 초기값 0
extern int menu;                                                    //메인 파일에서 입력받은 menu를 외부참조

static bool Gugudan()                                               //1. 구구단 게임 실행
{
	int a = rand() % 8 + 2;                                         //곱할 수 a를 난수를 이용하여 선언 (2~9까지)
	int b = rand() % 8 + 2;                                         //곱할 수 b를 난수를 이용하여 선언 (2~9까지)
	int result;                                                     //정답 result 선언

	Numgames++;                                                     //실행 게임수 증가
	printf("[문제%d번]: %2d x %2d = ", Numgames, a, b);                
	scanf_s("%d", &result);
	if (result == a * b)                                            //정답과 문제를 푼 답이 같으면 맞춘 문제수를 1증가
		Numwins++;                   
	return (result == a * b);                                       //정답의 값을 반환
} 

static bool Gugudan2()                                              //2. 두자리 수 곱셈 게임 실행
{
	int a = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				//곱할 수 a를 난수를 이용하여 선언 (11~99까지)
	int b = ((rand() % 8 + 1) * 10) + (rand() % 8 + 1);				//곱할 수 b를 난수를 이용하여 선언 (11~99까지)
	int result;														//정답 result 선언

	Numgames++;														//실행 게임수 증가
	printf("[문제%d번]: %2d x %2d = ", Numgames, a, b);
	scanf_s("%d", &result);
	if (result == a * b)											//정답과 문제를 푼 답이 같으면 맞춘 문제수를 1증가
		Numwins++;
	return (result == a * b);										//정답의 값을 반환
}

static bool plusgame()                                              //3. 입력받은 자리수에 대한 덧셈 게임 실행
{
	int answer1 = 0, answer2 = 0, result;						    //문제를 위한 난수의 초기값 answer1,answer2 와 결과값 result 선언
	for (int i = 0; i < menu; i++)								    //메인파일에서 받은 menu 만큼 자리수의 수 만들기
	{																
		answer1 += (rand() % 8 + 1) * pow(10, i);                   //pow()함수를 이용하여 더해야할 숫자를 입력받은 자릿수 만큼 만들기
		answer2 += (rand() % 8 + 1) * pow(10, i);					//pow()함수를 이용하여 더해야할 숫자를 입력받은 자릿수 만큼 만들기  
	}
	Numgames++;                                                     //실행 게임수 증가
	printf("[문제%d번]: %2d + %2d = ", Numgames, answer1, answer2);
	scanf_s("%d", &result);
	if (result == answer1 + answer2)								//정답과 문제를 푼 답이 같으면 맞춘 문제수를 1증가
		Numwins++;
	return (result == answer1 + answer2);							//정답의 값을 반환
}

double speedcheck()                                                 //문제 소요시간을 확인하는 함수
{
	clock_t t0 = clock();                                           //문제 처음 시간 체크
		switch(menu)                                                //메인파일에서 받은 menu에 따라 게임실행 값 변경
		{
			case 1:                                                 //1. 구구단 게임 
				for (int i = 0; i < 10; i++)                        //문제는 총 10문제이기 때문에 10번 반복
				{
					if (Gugudan() == false)                         //문제의 답이 틀리면 틀렸습니다 출력
						printf("\t틀렸습니다.\n");
				}
				break;
			case 2:                                                 //2. 두자리수 곱셈 게임 
				for (int i = 0; i < 10; i++)						//문제는 총 10문제이기 때문에 10번 반복
				{
					if (Gugudan2() == false)						//문제의 답이 틀리면 틀렸습니다 출력
						printf("\t틀렸습니다.\n");
				}
				break;
			default:                                                //3. 입력받은 자리수에 대한 덧셈 게임 실행
				for (int i = 0; i < 10; i++)						//문제는 총 10문제이기 때문에 10번 반복
				{
					if (plusgame() == false)						//문제의 답이 틀리면 틀렸습니다 출력
						printf("\t틀렸습니다.\n");
				}
				break;
		}
	clock_t t1 = clock();                                                                       //문제 끝날때의 시간 체크
	tElapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;                                              //전체 소요 시간 
	Score = (Numgames< Numwins) ? 0.0 : 100 * (5.0 * Numgames - tElapsed) / (5.0 * Numgames);   // 점수 환산
	return Score;                                                                               //점수를 반환한다
}