#pragma once
#include "NHS_실습08_Monster.h"

class Zombie : public Monster {                                           // Monster 클래스에 대한 상속 클래스 Zombie
public:																	  // 움직임은 기존 몬스터와 동일하다
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }                                      
};

class Vampire : public Monster {										  // Monster 클래스에 대한 상속 클래스 Vampire										  
public: 
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {                            // move() 재정의로 인한 상하 좌우로만 움직임
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {                                            // Monster 클래스에 대한 상속 클래스 KGhost
public:
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0)   
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {                             // move() 재정의로 인한 화면 어디에서든 나타날 수 있음
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {                                          // Monster 클래스에 대한 상속 클래스 Jiangshi
	bool	bHori;														   // True, False에 따라 강시의 움직임이 달라짐
public:
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {                             // move() 재정의로 인한 강시의 움직임 
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {                                            // Monster 클래스에 대한 상속 클래스 Smombi
public:
	Smombi(string n = "스몸비", string i = "!", int x=0, int y=0) : Monster (n,i,x,y){}
	~Smombi() { cout << "Smombi"; }

	void move(int** map, int maxx, int maxy) {                             // move() 재정의로 인한 대각선으로의 움직임
		int dir = rand() % 2;
		if (dir == 0)
		{
			x--;
			y++;
		}
		else
		{
			x++;
			y--;
		}
		clip(maxx, maxy);
		eat(map);
	}
};

class Siangshi : public Jiangshi {                                          // Jiangshi 클래스에 대한 상속 클래스 Siangshi                      
	bool	bHori;
public:
	Siangshi(string n = "수퍼강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Jiangshi(n, i, x, y), bHori(bH) {}
	~Siangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {                              // Siangshi는 Jiangshi에 비해 일정 시간이 되면 움직이는 방향이 변화함
		int a = 0;                                                          // 일정 시간을 측정해줄 변수 a
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) {
			x += ((dir == 0) ? -jump : jump);
			a++;                                                            // 한번 움직이고 a를 1증가 함
			if ((a % 2) == 0)                                               // a가 짝수 일때마다, 움직임이 변화함
				y += ((dir == 0) ? -jump : jump);
		}
		else {
			y += ((dir == 0) ? -jump : jump);
			a++;
			if((a%2) == 0)
				x += ((dir == 0) ? -jump : jump);
		}
		clip(maxx, maxy);
		eat(map);
	}
};

class HyunSeung : public Monster {										     // 사용자가 재설정한 HyunSeung 몬스터
public:
	HyunSeung(string n = "현승", string i = "?", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~HyunSeung() { cout << "HyunSeung"; }

	void move(int** map, int maxx, int maxy) {                               // move()를 재정의 하여 상하좌우 2칸씩 움직이도록 함
		int dir = rand() % 4;
		if (dir == 0) x -= 2;
		else if (dir == 1) x += 2;
		else if (dir == 2) y -= 2;
		else y += 2;
		clip(maxx, maxy);
		eat(map);
	}
	
};