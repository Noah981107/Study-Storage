#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

class Bomb {                                                                     // 클래스 Bomb 선언                                

	string progress[64];														 // 출력되는 그림을 담을 객체
	string answer;																 // 맞춰야하는 정답을 담을 객체
	string guessed;																 // 알파벳 추측을 위한 객체
	string question;															 // 단어장에서 가져올 문제를 위한 객체

	int nTries;																	 // 시도횟수
	const int maxTries = 6;														 // 몫숨(최대시도횟수)는 7회

	void load(const char* progName = "Bomb.txt") {                        		 // Bomb.txt에 저장되어있는 그림을 불러오는 메소드
		ifstream fs(progName);													 // 파일을 연다.
		if (fs) {
			getline(fs, progress[0]);											 // 첫줄은 주석
			for (int i = 0; i < 13; i++)
				getline(fs, progress[i]);										 // 한줄 씩 파일에서 progress에 담는다.
		}
	}

	void print() {																 // 보유하고있는 몫숨에 따라 출력하는 메소드
		system("cls");															 // 화면을 비움
		cout << "<Hangman Game>\n";
		for (int i = 0; i < 2; i++)
			cout << '\t' << progress[nTries * 2 + i] << endl;					 // 그림의 총 행이 13개 이고, 목숨은 6개 임으로 한개의 목숨당 2줄씩 출력
		cout << "\n\t" << answer;
		cout << "\n\n" << guessed;
	}

	int countMatched(char ch) {													 // 정답과 비교한 내용을 비교하는 메소드
		int nMatched = 0;														 // 맞은 숫자 초기값 0
		for (int pos = -1;;) {
			pos = question.find(ch, pos + 1);									 // 정답에서 입력한 문자를 찾는 .find 사용
			if (pos < 0)
				break;
			answer[pos] = ch;													 // 입력한 문자가 정답에 있다면 answer에서 그위치에 입력한 문자로 바꿈
			nMatched++;
		}
		return nMatched;
	}

	void guess() {                                                               // 알파벳이 나열되어있는 string  guessed에서 입력된 문자가 있는지 확인하는 메소드
		char ch = _getch();														 // 입력한 문자를 ch에 저장
		if (ch >= 'a' && ch <= 'z') {											 // 입력한 문자와 알파벳들을 비교함
			int pos = guessed.find(ch);
			if (pos < 0)
				guessed[ch - 'a'] = ch;
			if (countMatched(ch) == 0)
				nTries++;
		}
	}

	void choose_word()                                                           // 단어장에서 단어를 불러오는 메소드
	{
		int a = 0;																 // 난수를 받아드릴 변수 a 선언
		srand((unsigned)time(NULL));
		a = rand() % 100;
		ifstream in("word.txt");												 // word.txt를 연다.
		if (in)
		{
			for (int i = 0; i < 26; i++)
				getline(in, question);											 // 텍스트 파일의 내용을 question에 한줄씩 저장
		}
	}

public:

	void play() {                                                                // 실제 게임을 실행시키는 함수
		load();																	 // load 메소드 실행
		answer = string(question.length(), '-');								 // answer에 정답의 길이만큼 -로 출력되게 함
		guessed = string(24, '.');												 // guessed를 알파벳의 갯수만큼 .로 출력되게 함
		nTries = 0;																 // 시도횟수 0
		while (nTries < maxTries && answer != question) {						 // 반복문을 사용하여 위의 메소드 실행
			choose_word();
			print();
			guess();
		}
		print();
		cout << "\n\t" << ((nTries == maxTries) ? "실패" : "정답") << endl;
	}
};
