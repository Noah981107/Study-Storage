#include "NHS_�ǽ�06_MonsterWorld.h"
#include <time.h>
void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);                                       // MonsterWorld ��ü�� game���� ����
	Monster m("����", "��", rand() % w, rand() % h, 100);        // ������ ���� ��ü�� �߰�
	game.add(m);
	game.add(Monster("������", "��", rand() % w, rand() % h, 100));
	game.add(Monster("���״�", "��", rand() % w, rand() % h, 100));
	game.add(Monster("��Ʈ", "��", rand() % w, rand() % h, 100));
	game.play(500, 10);                                            // play()�޼ҵ� ����, 500,10�� �μ��� ����
	printf("------���� ����-------------------\n");
}