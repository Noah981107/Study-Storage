#include "NHS_실습11_MonsterWorld.h"
#include "NHS_실습11_Human.h"
#include "NHS_실습11_RankingBoard.h"
#include <time.h>

void main()
{
	RankingBoard rank;                                 // 랭킹 객체 rank 생성
	char str[80];                                      // 입력한 비밀번호를 저장할 배열
	string passwd, correct = "123456";                 // 파일 비밀번호
	try {
		rank.load("MonsterWorld.rnk");                 // 랭킹 파일 로드
	} 
	catch (FileException e) {                          // 예외 발생시 실행
		cout << "관리자 비밀번호를 입력하세요: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		if (passwd != correct) {
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
	}
	rank.print("[게임 랭킹: 시작]");

	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);
	game.add(new Zombie("허접한좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));

	Human* human = new Human("미래의인류", "♀", rand() % w, rand() % h);
	game.add(human);
	game.play(500, 10);
	printf("------게임 종료-------------------\n");

	rank.add(human->nItem, human->nItem / human->total);
	rank.print("[게임 랭킹: 종료]");
	try {
		rank.store("MonsterWorld.rnk");              // 랭킹 파일 저장
	}
	catch (FileException e) {						 // 예외 발생시 실행
		cout << "관리자 비밀번호를 입력하세요: ";
		for (int i = 0;; i++) {
			str[i] = _getch();
			putchar('*');
			if (str[i] == '\r') {
				str[i] = '\0';
				passwd = str;
				cout << "\n";
				break;
			}
		}
		if (passwd != correct) {
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
			exit(0);
		}
		rank.store("MonsterWorld_new.rnk");       // 파일이 읽기전용으로 설정되어있어 쓰기가 안될때 새로운 파일을 만들어서 랭킹 저장
	}
}