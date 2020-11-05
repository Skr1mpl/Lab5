#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;


class History {
protected:
	string whoAttac;
	string whoDefens;
public:
	History(string w, string w1) {
		whoAttac = w;
		whoDefens = w1;
	}
	virtual void showData() = 0;
};

class BelarusHistory:public History {
private:
	int yearOfWarInBel;
	int yearOfEndWarInBel;
	string capital;
public:
	BelarusHistory(string w, string w1, int yo, int yo1, string c) :History(w, w1) {
		yearOfWarInBel = yo;
		yearOfEndWarInBel = yo1;
		capital = c;
	}
	void showData();
};

class RussianHistory :public History {
private:
	int yearOfWarInRus;
	int yearOfEndWarInRus;
	string town;
public:
	RussianHistory(string w, string w1, int yo, int yo1, string t) :History(w, w1) {
		yearOfWarInRus = yo;
		yearOfEndWarInRus = yo1;
		town = t;
	}
	void showData();
};

class UkrainHistory :public History {
private:
	int yearOfWarInUk;
	int yearOfEndWarInUk;
	string president;
public:
	UkrainHistory(string w, string w1, int yo, int yo1, string p) :History(w, w1) {
		yearOfWarInUk = yo;
		yearOfEndWarInUk = yo1;
		president = p;
	}
	void showData();
};

void BelarusHistory::showData() {
	cout << "		История Беларуси: " << endl;
	cout << "Агрессор: " << whoAttac << endl;
	cout << "Обороняющийся: " << whoDefens << endl;
	cout << "Дата начало войны в Беларуси: " << yearOfWarInBel << endl;
	cout << "Дата окнчания войны в Беларуси: " << yearOfEndWarInBel << endl;
	cout << "Столица Беларуси: " << capital << endl;
}

void RussianHistory::showData() {
	cout << "		История России: " << endl;
	cout << "Агрессор: " << whoAttac << endl;
	cout << "Обороняющийся: " << whoDefens << endl;
	cout << "Дата начало войны в России: " << yearOfWarInRus << endl;
	cout << "Дата окнчания войны в России: " << yearOfEndWarInRus << endl;
	cout << "Город на который напили - " << town << endl;
}

void UkrainHistory::showData() {
	cout << "		История Украины: " << endl;
	cout << "Агрессор: " << whoAttac << endl;
	cout << "Обороняющийся: " << whoDefens << endl;
	cout << "Дата начало войны в Украине: " << yearOfWarInUk << endl;
	cout << "Дата окнчания войны в Украине: " << yearOfEndWarInUk << endl;
	cout << "Президент - " << president << endl;
}

void Bel(int&, int&, string&, string&, string&);
void Rus(int&, int&, string&, string&, string&);
void Uk(int&, int&, string&, string&, string&);
int chooseMenu();
string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	int n = 1;
	History** mas = new History * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			int y2, y3;
			string Attack, Defense, Capital;
			Bel(y2, y3, Attack, Defense, Capital);
			mas[n] = new BelarusHistory(Attack, Defense, y2, y3, Capital);
			mas[n]->showData();
			n++;
			n++;
			History** ptr = new History * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) { 
				int y2, y3;
				string Attack, Defense, Town;
				Rus(y2, y3, Attack, Defense, Town);
				mas[n] = new RussianHistory(Attack, Defense, y2, y3, Town);
				mas[n]->showData();
				n++;
				n++;
				History** ptr = new History * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) { 
					int y2, y3;
					string Attack, Defense, President;
					Uk(y2, y3, Attack, Defense, President);
					mas[n] = new UkrainHistory(Attack, Defense, y2, y3, President);
					mas[n]->showData();
					n++;
					n++;
					History** ptr = new History * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else 
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->showData();
						system("pause");
						system("cls");
					}
					else break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> История Беларуси" << endl; }
		else { cout << " История Беларуси" << endl; }

		if (choose_menu == 1) { cout << " -> История России" << endl; }
		else { cout << " История России" << endl; }

		if (choose_menu == 2) { cout << " -> История Украины" << endl; }
		else { cout << " История Украины" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

void Bel(int& y2, int& y3, string& Attack, string& Defense, string& Capital) {
	cout << "	История Беларуси" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в Беларуси - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в Беларуси - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите столицу Беларуси - ";
	Capital = writeWords();
	system("cls");
}

void Rus(int& y2, int& y3, string& Attack, string& Defense, string& Town) {
	cout << "	История России" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в России - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в России - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите город на который напали - ";
	Town = writeWords();
	system("cls");
}

void Uk(int& y2, int& y3, string& Attack, string& Defense, string& President) {
	cout << "	История Украины" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в Украине - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в Украине - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите фамилию президента - ";
	President = writeWords();
	system("cls");
}