#include "NHS_�ǽ�04_Ranking.h"
extern int three_three_Puzzle();                          // 3x3���� ����
extern int four_four_Puzzle();                            // 4x4���� ����
extern int five_five_Puzzle();                            // 5x5���� ����

void main()
{ 
	int menu;
	printf("<�������>\n");
	printf("1. 3x3 ����\n2. 4x4 ����\n3. 5x5 ����\n");
	printf("�޴��� �����ϼ��� : ");
	scanf_s("%d", &menu);
	
	switch(menu)                                          //������ �޴��� ���� ���� ����
	{
		case 1:										      //3x3���� ����
		{												  
			loadRanking("ranking3.txt");                  //3x3 ������ �������Ϸ� ���� 
			int rank3 = three_three_Puzzle();             //3x3 ���� ����
			printRanking();                               //��ŷ ��� 
			storeRanking("ranking3.txt");                 //��ŷ�� �������Ϸ� ����
			break;
		}
		case 2:                                           //4x4���� ����
		{
			loadRanking("ranking4.txt");				  //4x4 ������ �������Ϸ� ����
			int rank4 = four_four_Puzzle();				  //4x4 ���� ����
			printRanking();								  //��ŷ ��� 
			storeRanking("ranking4.txt");				  //��ŷ�� �������Ϸ� ����
			break;
		}
		
		case 3:                                           //5x5���� ����
		{
			loadRanking("ranking5.txt");				  //5x5 ������ �������Ϸ� ����
			int rank5 = five_five_Puzzle();				  //5x5 ���� ����
			printRanking();								  //��ŷ ��� 
			storeRanking("ranking5.txt");				  //��ŷ�� �������Ϸ� ����
			break;
		}
	}
}