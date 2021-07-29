#include "NHS_실습06_MonsterWorld.h"
#include <time.h>
void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);                                       // MonsterWorld 객체를 game으로 생성
	Monster m("몬스터", "※", rand() % w, rand() % h, 100);        // 각각의 몬스터 객체를 추가
	game.add(m);
	game.add(Monster("도깨비", "◎", rand() % w, rand() % h, 100));
	game.add(Monster("별그대", "★", rand() % w, rand() % h, 100));
	game.add(Monster("고스트", "♥", rand() % w, rand() % h, 100));
	game.play(500, 10);                                            // play()메소드 실행, 500,10을 인수로 전달
	printf("------게임 종료-------------------\n");
}