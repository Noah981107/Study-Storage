#pragma once
#include "NHS_실습09_Monster.h"
#include <conio.h>                                                            // kbhit()함수를 사용하기 위함
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };                 // 아스키코드에 해당하는 방향키의 값

class Human : public Monster {                                                // Monster 클래스에 상속된 Human 클래스
public:
	Human(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }                                       // 소멸자에 [Human  ] 출력
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }              // 입력된 키가 화살표이면 화살표 키 값을 반환, 아니면 0 반환
	void move(int** map, int maxx, int maxy) {                                // 입력된 키보드 값에 해당하는 움직임 실행
		if (_kbhit()) { 
			char ch = getDirKey();
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {                                                  // Human 클래스에 상속된 Tuman 클래스
public:
	Tuman(string n = "미래투맨", string i = "♀", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " [Tuman   ]"; }                                       // 소멸자에 [Tuman  ] 출력
	void move(int** map, int maxx, int maxy, char ch) {                       // 키보드 입력에 대한 움직임 실행 매개변수 ch로 키보드의 값 실행
			if (ch == 'a') x--;
			else if (ch == 'd') x++;
			else if (ch == 's') y++;
			else if (ch == 'w') y--;
			else if(ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
};