#pragma once
#include "NHS_�ǽ�06_Canvas.h"
#include "NHS_�ǽ�06_Monster.h"
#include <windows.h>
#define DIM  40
#define MAXMONS 5

class MonsterWorld {
	int map[DIM][DIM];                            //���� �󿡼� ���Ͱ� ������ �ʵ�
	int xMax, yMax, nMon, nMove;
	Monster mon[MAXMONS];
	Canvas	canvas;

	int& Map(int x, int y) { return map[y][x]; }  // �����Ͱ� ������ �ʵ�
	bool isDone() { return countItems() == 0; }   // ������ ���������� �Ǵ��ϴ� �Լ�
	int countItems() {                            // �������� ���ڸ� �ľ��ϴ� �Լ�
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {                                // ���Ӽӿ��� ���Ͱ� ������ �ʵ带 ����ϴ� �Լ�
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "��");
		for (int i = 0; i < nMon; i++)
			mon[i].draw(canvas);
		canvas.print("[ Monster World (���͵��� ����) ]");

		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			mon[i].print();
	}
public:
	MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() { }
	void add(Monster m) {                                       // ������ ������ �߰��ϴ� �Լ�
		if (nMon < MAXMONS) mon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {                          // �������� ������ �����Ű�� �Լ�
		print();
		cerr << " ���͸� ��������...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				mon[k].move(map, xMax, yMax);
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};