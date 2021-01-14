#include "NHS_실습08_MonsterWorld.h"
#include "NHS_실습08_VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("허접한좀비", "◎", rand() % w, rand() % h));                 // 새로운 몬스터들에 대한 정보를 동적 할당
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.add(new Smombi("스몸비", "!", rand() % w, rand() % h));
	game.add(new Siangshi("수퍼코로나강시", "@", rand() % w, rand() % h, true));
	game.add(new Siangshi("수퍼우한강시", "#", rand() % w, rand() % h, false));
	game.add(new HyunSeung("현승", "&", rand() % w, rand() % h));
	
	game.play(500, 10);
	printf("------게임 종료-------------------\n");
}