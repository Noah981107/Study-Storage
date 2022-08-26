#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

class Bomb {                                                                     // Ŭ���� Bomb ����                                

	string progress[64];														 // ��µǴ� �׸��� ���� ��ü
	string answer;																 // ������ϴ� ������ ���� ��ü
	string guessed;																 // ���ĺ� ������ ���� ��ü
	string question;															 // �ܾ��忡�� ������ ������ ���� ��ü

	int nTries;																	 // �õ�Ƚ��
	const int maxTries = 6;														 // ���(�ִ�õ�Ƚ��)�� 7ȸ

	void load(const char* progName = "Bomb.txt") {                        		 // Bomb.txt�� ����Ǿ��ִ� �׸��� �ҷ����� �޼ҵ�
		ifstream fs(progName);													 // ������ ����.
		if (fs) {
			getline(fs, progress[0]);											 // ù���� �ּ�
			for (int i = 0; i < 13; i++)
				getline(fs, progress[i]);										 // ���� �� ���Ͽ��� progress�� ��´�.
		}
	}

	void print() {																 // �����ϰ��ִ� ����� ���� ����ϴ� �޼ҵ�
		system("cls");															 // ȭ���� ���
		cout << "<Hangman Game>\n";
		for (int i = 0; i < 2; i++)
			cout << '\t' << progress[nTries * 2 + i] << endl;					 // �׸��� �� ���� 13�� �̰�, ����� 6�� ������ �Ѱ��� ����� 2�پ� ���
		cout << "\n\t" << answer;
		cout << "\n\n" << guessed;
	}

	int countMatched(char ch) {													 // ����� ���� ������ ���ϴ� �޼ҵ�
		int nMatched = 0;														 // ���� ���� �ʱⰪ 0
		for (int pos = -1;;) {
			pos = question.find(ch, pos + 1);									 // ���信�� �Է��� ���ڸ� ã�� .find ���
			if (pos < 0)
				break;
			answer[pos] = ch;													 // �Է��� ���ڰ� ���信 �ִٸ� answer���� ����ġ�� �Է��� ���ڷ� �ٲ�
			nMatched++;
		}
		return nMatched;
	}

	void guess() {                                                               // ���ĺ��� �����Ǿ��ִ� string  guessed���� �Էµ� ���ڰ� �ִ��� Ȯ���ϴ� �޼ҵ�
		char ch = _getch();														 // �Է��� ���ڸ� ch�� ����
		if (ch >= 'a' && ch <= 'z') {											 // �Է��� ���ڿ� ���ĺ����� ����
			int pos = guessed.find(ch);
			if (pos < 0)
				guessed[ch - 'a'] = ch;
			if (countMatched(ch) == 0)
				nTries++;
		}
	}

	void choose_word()                                                           // �ܾ��忡�� �ܾ �ҷ����� �޼ҵ�
	{
		int a = 0;																 // ������ �޾Ƶ帱 ���� a ����
		srand((unsigned)time(NULL));
		a = rand() % 100;
		ifstream in("word.txt");												 // word.txt�� ����.
		if (in)
		{
			for (int i = 0; i < 26; i++)
				getline(in, question);											 // �ؽ�Ʈ ������ ������ question�� ���پ� ����
		}
	}

public:

	void play() {                                                                // ���� ������ �����Ű�� �Լ�
		load();																	 // load �޼ҵ� ����
		answer = string(question.length(), '-');								 // answer�� ������ ���̸�ŭ -�� ��µǰ� ��
		guessed = string(24, '.');												 // guessed�� ���ĺ��� ������ŭ .�� ��µǰ� ��
		nTries = 0;																 // �õ�Ƚ�� 0
		while (nTries < maxTries && answer != question) {						 // �ݺ����� ����Ͽ� ���� �޼ҵ� ����
			choose_word();
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "����" : "����") << endl;
	}
};
