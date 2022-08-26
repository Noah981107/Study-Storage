#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
	int rows, cols;		                                              // ��� ���� ũ��
	int** mat;	                                                      // ���� ��� ������
public:
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {      // �����ڸ� �̿��Ͽ�, ù����� ���� �����ϰ� �ι�°�� ���� ������
		mat = new int* [rows];
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];
	}
	~Matrix() {													      // �Ҹ��ڸ� �̿��Ͽ�, �޸� ���� �ǽ�
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i];
			delete[] mat;
		}
	}
	int& elem(int x, int y) { return mat[y][x]; }                     // ��� �迭�� ��ȯ�ϴ� �Լ�
	int Rows() { return rows; }										  // ���� ��ȯ�ϴ� �Լ�
	int Cols() { return cols; }										  // ���� ��ȯ�ϴ� �Լ�
	int** Data() { return mat; };                                     // ������ ����� ��ȯ�ϴ� �Լ�
	void print(const char* str = "Mat") {                             // ����� ����ϴ� �Լ�
		cout << str << " " << rows << "x" << cols << endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << setw(4) << mat[i][j];
			cout << "\n";
		}
	}
	void setRand(int val = 100) {                                      // ����� �� �ڸ����� ������ ���� �����ϴ� �Լ�
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mat[i][j] = (rand() % val);
		}
	}
};