#include "NHS_�ǽ�08_MonsterWorld.h"
#include "NHS_�ǽ�08_VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("����������", "��", rand() % w, rand() % h));                 // ���ο� ���͵鿡 ���� ������ ���� �Ҵ�
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));
	game.add(new Smombi("������", "!", rand() % w, rand() % h));
	game.add(new Siangshi("�����ڷγ�����", "@", rand() % w, rand() % h, true));
	game.add(new Siangshi("���ۿ��Ѱ���", "#", rand() % w, rand() % h, false));
	game.add(new HyunSeung("����", "&", rand() % w, rand() % h));
	
	game.play(500, 10);
	printf("------���� ����-------------------\n");
}