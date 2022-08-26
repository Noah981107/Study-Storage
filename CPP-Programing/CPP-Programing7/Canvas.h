#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
<<<<<<< HEAD
	string line[MAXLINES];												// ȭ�� ����� ���� ���ڿ�
	int xMax, yMax;														// ���� ũ��
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {				// ����Ʈ �Ű����� nx,ny�� �̿��Ͽ� �ʱ�ȭ 
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');						    // ��µǴ� ĭ�� 2bit�� ũ�⸦ ������ ����
	}
	void draw(int x, int y, string val) {                               // ȭ���� ������ ��ġ�� ���� �Լ� 
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void clear(string val = ". ") {		                                // ĵ������ ������ val�� ����
=======
	string line[MAXLINES];	                                         // ȭ�� ����� ���� ���ڿ�
	int xMax, yMax;		                                             // ���� ũ��
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {          // ���Ͱ� ������ ĵ������ ����Ʈ �Ű������� �̿��� �ʱ�ȭ
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {                            // ���Ͱ� ������ ȭ���� �׸��� �Լ�
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);
	}
	void clear(string val = ". ") {	                                 // ���� ������ ȭ���� �ʱ�ȭ �ϴ� �Լ�
>>>>>>> cp7/main
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
<<<<<<< HEAD
	void print(const char* title = "<My Canvas>") {                     // ����ȭ���� ����ϴ� �Լ�
=======
	void print(const char* title = "<My Canvas>") {                  // ���Ͱ� ������ ��ü ���� ȭ���� ����ϴ� �Լ�
>>>>>>> cp7/main
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};