#define _CRT_SECURE_NO_WARNINGS                           //fopen���� �ڲ� ������ �߻��Ͽ��� ����
#include "NHS_�ǽ�04_Ranking.h"              
#define NUM_MVP 10                                        // ��� 10�� NUM_MVP�� ����
static PlayInfo MVP[NUM_MVP];	                          // ��ŷ �迭
static int nMVP = NUM_MVP;	                              // ��ŷ �迭�� ����

static void initRanking() {                               //��ŷ �ʱ�ȭ �Լ�       
	PlayInfo noname = { "C++���ƿ�", 1000, 1000.0 };      //�ʱ�ȭ ��ų ����
	for (int i = 0; i < nMVP; i++)                        //�迭�� ���̸�ŭ ����
		MVP[i] = noname;
}

void loadRanking(char* filename) {                        //��ŷ�� ������ ���� ����
	FILE* fp = fopen(filename, "r");                      //�б���� ������ ����.
	if (fp == NULL)                                       //������ ���ٸ�
		initRanking();                                    //�ʱ�ȭ �Լ� ����
	else {                                              
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);       //��ŷ ������ ���� �б�
		fclose(fp);                                       //������ �ݴ´�
	}
}
void storeRanking(char* filename) {                       //��ŷ�� �����ϴ� �Լ�
	FILE* fp = fopen(filename, "w");					  //������ ������� ����.
	if (fp == NULL) return;								  //������ ���ٸ� ��ȯ�� ����
	fwrite(&MVP[0], sizeof(PlayInfo), nMVP, fp);		  //���Ͽ� ��ŷ�� �����Ѵ�.
	fclose(fp);										      //������ �ݴ´�
 }														  
														  
void printRanking() {                                                               //��ŷ�� ����� �Լ�
	printf("  [����] �̵�Ƚ�� �̸�            �ɸ��ð�   ����\n");                 
	for (int i = 0; i < nMVP; i++) {                                                //��ŷ�� ��ϵǾ��ִ� ������ ���� ���
		double score = 1000 -  MVP[i].tElapsed;
		printf("  [%2d��]  %4d    %-16s  %5.1f   %5.1f\n", i + 1, MVP[i].nMove,        
			MVP[i].name, MVP[i].tElapsed, score);
	}
		
}
int addRanking(int nMove, double tElap) {                                           // ���� ����� ��ŷ�� �߰� ����
	if (nMove < MVP[nMVP - 1].nMove) {                                              // ������ ����� ������ ���� ������Ƚ�� Ȯ��
		int pos = nMVP - 1;                                                         
		for (; pos > 0; pos--) {                                                   
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;                                                     //���ο� ������ ���� �迭�� �ε����� ���� 
		MVP[pos].tElapsed = tElap;
		printf(" %d���Դϴ�. �̸��� �Է��ϼ���: ", pos + 1);
		scanf("%s", MVP[pos].name);
		return pos + 1;
	}
	return 0;
}