#include "NHS_실습04_Ranking.h"
extern int three_three_Puzzle();                          // 3x3퍼즐 게임
extern int four_four_Puzzle();                            // 4x4퍼즐 게임
extern int five_five_Puzzle();                            // 5x5퍼즐 게임

void main()
{ 
	int menu;
	printf("<퍼즐게임>\n");
	printf("1. 3x3 퍼즐\n2. 4x4 퍼즐\n3. 5x5 퍼즐\n");
	printf("메뉴를 선택하세요 : ");
	scanf_s("%d", &menu);
	
	switch(menu)                                          //선택한 메뉴에 따라 게임 시작
	{
		case 1:										      //3x3퍼즐 게임
		{												  
			loadRanking("ranking3.txt");                  //3x3 게임을 이진파일로 열기 
			int rank3 = three_three_Puzzle();             //3x3 게임 시작
			printRanking();                               //랭킹 출력 
			storeRanking("ranking3.txt");                 //랭킹을 이진파일로 저장
			break;
		}
		case 2:                                           //4x4퍼즐 게임
		{
			loadRanking("ranking4.txt");				  //4x4 게임을 이진파일로 열기
			int rank4 = four_four_Puzzle();				  //4x4 게임 시작
			printRanking();								  //랭킹 출력 
			storeRanking("ranking4.txt");				  //랭킹을 이진파일로 저장
			break;
		}
		
		case 3:                                           //5x5퍼즐 게임
		{
			loadRanking("ranking5.txt");				  //5x5 게임을 이진파일로 열기
			int rank5 = five_five_Puzzle();				  //5x5 게임 시작
			printRanking();								  //랭킹 출력 
			storeRanking("ranking5.txt");				  //랭킹을 이진파일로 저장
			break;
		}
	}
}