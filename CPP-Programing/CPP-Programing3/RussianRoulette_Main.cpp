//���þ� �귿 ���� V2 ���� ����
#include "NHS_�ǽ�03_1.h"

int nguns;                                              //����ڷ� ���� �Է¹��� ��߱��������� �Է¹޴� ���� ���� nguns ����

void main()
{
	int nplayers, nbullets;                             //���,����� �Է¹޴� ���� ����

	printf("���¥�� ���� ���ðڽ��ϱ�? : ");
	scanf_s("%d", &nguns);
	printf("����̼� �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &nplayers);
	printf("�Ѿ��� ��� �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &nbullets);

	playgame(nplayers, nbullets);                       //���� ���� �Լ� ����                      
}