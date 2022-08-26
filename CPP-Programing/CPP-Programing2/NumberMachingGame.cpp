// 번호맞히기 게임 확장판 프로그램
#include <cstdio>
#include <iostream>                                                              //std::cin을 사용하기 위함
#include <conio.h>                                                               //_getch()를 사용하기 위함
#include <math.h>                                                                //pow(,)를 사용하기 위함

void Up_down_game()                                                              //번호 맞히기 게임 함수
{
	int n, i, min = 1, input;                                                    //입력받을 자릿수의 n, 반복문을 위한 i, 범위에대한 초기값 min (1로 초기화), 문제를 맞추기 위한 값 input 변수 설정
	int answer = 0;                                                              //입력받은 숫자를 나타내는 변수 answer 초기값 0
	char question[10000];                                                        //임의의 자릿수에 대한 정답을 담아두는 배열 question[]선언

	printf("게임하고 싶은 임의의 자릿수를 입력하세요: ");                        
	std::cin >> n;                                                               //입력받은 임의의 자릿수를 n에 저장

	printf("숫자를 입력하세요: ");                                           
	for (i = 1; i <= n; i++)                                                     //입력한 숫자를 n번동안 배열의 한칸한칸에 넣기위한 반복문
	{
 		question[i] = _getch();                                                  //입력한 숫자를 문자열로 받아 배열의 한칸한칸에 넣는다.
		printf("♥");                                                            //화면에는 입력한 숫자가 나오지 않고 ♥ 출력
		if (i == n)                                                              //만약 입력한 자릿수만큼 입력이 다 되면 한 줄 내린다.
			printf("\n");
	}
	for (i = n; i > 0; i--)                                                      //각각의 배열에 저장되어있는 값들을 더하기 위한 반복문
	{
		answer += (question[i] - '0') * pow(10, (n - i));                        //입력한 숫자가 문자로 저장되어 있기 때문에 정수로 바꾸어 저장하기 위하여 (question[i] - '0') 실행, 그리고 저장한 숫자들을 십진법으로 나타내기 위하여
	}                                                                            //pow(10, (n - i))실행 한 후, 계산된 값들은 다 answer에 순차적으로 더 한다.
	int max = pow(10, n);                                                        //입력한 자릿수에 대한 최대값을 나타내는 변수 max를 설정한다. 이 max는 10^n을 나타낸다.
	for (i = 0; i < 10; i++)                                                     //10번의 기회동안 문제를 맞추는 반복문
	{
		printf("[%d번째] %2d ~ %2d 사이의 값 예측 ", i + 1, min, max);          
		std::cin >> input;                                                       //예측한 값을 변수 input에 저장

 		if (answer == input)                                                     //만약, 예측한 값과 정답이 같다면 이 반복문을 빠져나간다.
			break;

		else if (answer > input)                                                 //만약, 예측한 값이 정답보다 작을때
		{
			printf("더 큰 숫자 입니다.\n\n");
			min = input;                                                         //최솟값을 입력한 값으로 변경
		}
		else                                                                     //만약, 예측한 값이 정답보다 클때
		{
			printf("더 작은 숫자 입니다.\n\n");
			max = input;                                                         //최댓값을 입력한 값으로 변경
		}

	}
	printf("%s !!! 정답은 %d\n", (answer == input) ? "성공" : "실패", answer);   //정답 출력, 삼항연산자를 이용하여 성공or실패를 출력한다.
	printf("최종점수 = %d\n", 10 * (10 - i));                                    //점수 출력
}

void main()
{
	printf("<실습02_3번 문제>\n");                                                
	printf("<임의의 자릿수의 숫자 맞히기 게임>\n\n");

	Up_down_game();                                                              //번호 맞히기 게임 함수를 실행
}