#include <cstdio>

struct PlayInfo {
	char	name[200];	                          // ������ �̸��� ������ ��� name[200]
	int	nMove;		                              // ���� ������ ������ Ƚ�� ��� nMove
	double	tElapsed;	                          // ��� �ð� ��� tElapsed
};
extern void loadRanking(char* filename);          //��ŷ ���� ����
extern void storeRanking(char* filename);         //���Ͽ� ��ŷ ����
extern void printRanking();                       //��ŷ ���
extern int addRanking(int nMove, double tElap);   //������ŷ�� ���ο� ������ ����