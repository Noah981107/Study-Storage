#pragma once
#include "NHS_�ǽ�08_Monster.h"

class Zombie : public Monster {                                           // Monster Ŭ������ ���� ��� Ŭ���� Zombie
public:																	  // �������� ���� ���Ϳ� �����ϴ�
	Zombie(string n = "��������", string i = "��", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }                                      
};

class Vampire : public Monster {										  // Monster Ŭ������ ���� ��� Ŭ���� Vampire										  
public: 
	Vampire(string n = "�����̾�", string i = "��", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {                            // move() �����Ƿ� ���� ���� �¿�θ� ������
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {                                            // Monster Ŭ������ ���� ��� Ŭ���� KGhost
public:
	KGhost(string n = "ó��ͽ�", string i = "��", int x = 0, int y = 0)   
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {                             // move() �����Ƿ� ���� ȭ�� ��𿡼��� ��Ÿ�� �� ����
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {                                          // Monster Ŭ������ ���� ��� Ŭ���� Jiangshi
	bool	bHori;														   // True, False�� ���� ������ �������� �޶���
public:
	Jiangshi(string n = "�������", string i = "��", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {                             // move() �����Ƿ� ���� ������ ������ 
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {                                            // Monster Ŭ������ ���� ��� Ŭ���� Smombi
public:
	Smombi(string n = "������", string i = "!", int x=0, int y=0) : Monster (n,i,x,y){}
	~Smombi() { cout << "Smombi"; }

	void move(int** map, int maxx, int maxy) {                             // move() �����Ƿ� ���� �밢�������� ������
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

class Siangshi : public Jiangshi {                                          // Jiangshi Ŭ������ ���� ��� Ŭ���� Siangshi                      
	bool	bHori;
public:
	Siangshi(string n = "���۰���", string i = "��", int x = 0, int y = 0, bool bH = true)
		: Jiangshi(n, i, x, y), bHori(bH) {}
	~Siangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {                              // Siangshi�� Jiangshi�� ���� ���� �ð��� �Ǹ� �����̴� ������ ��ȭ��
		int a = 0;                                                          // ���� �ð��� �������� ���� a
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) {
			x += ((dir == 0) ? -jump : jump);
			a++;                                                            // �ѹ� �����̰� a�� 1���� ��
			if ((a % 2) == 0)                                               // a�� ¦�� �϶�����, �������� ��ȭ��
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

class HyunSeung : public Monster {										     // ����ڰ� �缳���� HyunSeung ����
public:
	HyunSeung(string n = "����", string i = "?", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~HyunSeung() { cout << "HyunSeung"; }

	void move(int** map, int maxx, int maxy) {                               // move()�� ������ �Ͽ� �����¿� 2ĭ�� �����̵��� ��
		int dir = rand() % 4;
		if (dir == 0) x -= 2;
		else if (dir == 1) x += 2;
		else if (dir == 2) y -= 2;
		else y += 2;
		clip(maxx, maxy);
		eat(map);
	}
	
};