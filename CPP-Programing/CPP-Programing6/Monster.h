#pragma once
#include "NHS_�ǽ�06_Canvas.h"
#define DIM 40

class Monster {
	string name, icon;            	// ���� �̸��� ȭ�� ��¿� ������
	int x, y, nItem, Energy;		// ���� ��ġ�� ���� ������ ��

	void clip(int maxx, int maxy) {  // ���Ͱ� ������ �迭 �ȿ����� ������ �� �ֵ��� �ϴ� �Լ�  
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int map[DIM][DIM]) {    // ���Ͱ� �������� �Դ� �Լ�
		if (map[y][x] == 1) {        // �迭�� ĭ�� 1�̸� ����
			map[y][x] = 0;           // �������� 1�̶�� �����ϸ�, �� �ڸ��� �ش��ϴ� �������� �Ծ����� 0���� ��ȯ
			nItem++;                 // �������� ���ڸ� 1����
			Energy = Energy + 8;     // �������� �Ծ��� ������ �������� 8 ����
		}
		else {                       // �������� ���� ĭ
			Energy = Energy - 1;     // �������� 1����
			if (Energy < 0)          // �������� 0���� �۾����ٸ�, �������� �ּڰ��� 0�̱� ������ 0���� ��ȯ
				Energy = 0;
		}
	}
public:
	Monster(string n = "������", string i = "��", int px = 0, int py = 0, int nEnergy = 0)  // �����ڸ� ���� ����Ʈ �Ű������� �̿��Ͽ� ������ ������ ����
		: name(n), icon(i), x(px), y(py), Energy(nEnergy), nItem(0) {}
	~Monster() { cout << "\t" << name << icon << " �������ϴ�~~~\n"; }                      // �Ҹ��ڸ� �̿��� ���� ���

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }							        // ����ȭ���� �׸��� �Լ� 
	void move(int map[DIM][DIM], int maxx, int maxy) {                                      // ���Ͱ� �����̴� �Լ�
		switch (rand() % 8) {                                                               // ��ġ�� ĭ�� �������� �� 8������ ����� ���� ������ �̵� ����
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << "\t" << "E :" << Energy << endl; } // ���ӿ��� ������ ������ ���
};