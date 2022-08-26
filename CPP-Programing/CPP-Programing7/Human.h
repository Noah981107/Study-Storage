#pragma once
#include "NHS_�ǽ�09_Monster.h"
#include <conio.h>                                                            // kbhit()�Լ��� ����ϱ� ����
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };                 // �ƽ�Ű�ڵ忡 �ش��ϴ� ����Ű�� ��

class Human : public Monster {                                                // Monster Ŭ������ ��ӵ� Human Ŭ����
public:
	Human(string n = "�̷��η�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }                                       // �Ҹ��ڿ� [Human  ] ���
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }              // �Էµ� Ű�� ȭ��ǥ�̸� ȭ��ǥ Ű ���� ��ȯ, �ƴϸ� 0 ��ȯ
	void move(int** map, int maxx, int maxy) {                                // �Էµ� Ű���� ���� �ش��ϴ� ������ ����
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

class Tuman : public Human {                                                  // Human Ŭ������ ��ӵ� Tuman Ŭ����
public:
	Tuman(string n = "�̷�����", string i = "��", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " [Tuman   ]"; }                                       // �Ҹ��ڿ� [Tuman  ] ���
	void move(int** map, int maxx, int maxy, char ch) {                       // Ű���� �Է¿� ���� ������ ���� �Ű����� ch�� Ű������ �� ����
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