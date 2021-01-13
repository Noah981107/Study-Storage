#pragma once
#include "NHS_실습11_Monster.h"

class Zombie : public Monster {                                                // Monster 클래스에 대한 상속 클래스 Zombie
public:																		   // 움직임은 기존 몬스터와 동일하다
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {											   // Monster 클래스에 대한 상속 클래스 Vampire			
public:
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {								   // move() 재정의로 인한 상하 좌우로만 움직임
		if (!isSleep()) {
			int dir = rand() % 4;
			if (dir == 0) p[0]--;
			else if (dir == 1) p[0]++;
			else if (dir == 2) p[1]--;
			else p[1]++;
			clip(maxx, maxy);
			eat(map);
		}
	}
};																			    

class KGhost : public Monster {                                               // Monster 클래스에 대한 상속 클래스 KGhost
public:
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {								  // move() 재정의로 인한 화면 어디에서든 나타날 수 있음
		if (!isSleep()) {
			p = Point(rand() % maxx, rand() % maxy);
			clip(maxx, maxy);
			eat(map);
		}
	}																		    
};																			    

class Jiangshi : public Monster {                                                               // Monster 클래스에 대한 상속 클래스 Jiangshi
	bool	bHori;																				// True, False에 따라 강시의 움직임이 달라짐
public:
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {                                // move() 재정의로 인한 강시의 움직임
		if (!isSleep()) {
			int dir = rand() % 2;
			int jump = rand() % 2 + 1;
			if (bHori)
				p[0] += ((dir == 0) ? -jump : jump);
			else
				p[1] += ((dir == 0) ? -jump : jump);
			clip(maxx, maxy);
			eat(map);
		}
	}
};