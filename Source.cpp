#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Wear {
protected:
	string type;
	string country;
public:
	Wear() {};
	string getType() {
		return type;
	}
	string getCountry() {
		return country;
	}
	void changeType(string ptr) {
		type = ptr;
	}
	void changeCountry(string ptr) {
		country = ptr;
	}
	void show() {
		cout << "��� ������: " << type << endl;
		cout << "������ �������������: " << country << endl;
	}
};

class Feature :virtual public Wear {
protected:
	int size;
	string color;
public:
	Feature() {};
	string getColor() {
		return color;
	}
	int getSize() {
		return size;
	}
	void changeColor(string ptr) {
		color = ptr;
	}
	void changeSize(int ptr) {
		size = ptr;
	}
	void show() {
		cout << "������: " << size << endl;
		cout << "����: " << color << endl;
	}
};

class Charc :virtual public Wear {
protected:
	string structure;
	int high;
public:
	Charc() {};
	string getStructure() {
		return structure;
	}
	int getHigh() {
		return high;
	}
	void changeHigh(int ptr) {
		high = ptr;
	}
	void changeStructure(string ptr) {
		structure = ptr;
	}
	void show() {
		cout << "����: " << high << endl;
		cout << "������: " << structure << endl;
	}
};

class Staff :public Feature, public Charc {
private:
	int price;
	int vote;
public:
	Staff() {};
	int getPrice() {
		return price;
	}
	int getVote() {
		return vote;
	}
	void changePrice(int ptr) {
		price = ptr;
	}
	void changeVote(int ptr) {
		vote = ptr;
	}
	void showAll() {
		Wear::show();
		Feature::show();
		Charc::show();
		cout << "����: " << price << endl;
		cout << "������: " << vote << endl;
	}
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(Staff*&, int);
int chooseWhatRed(Staff*&, int);

int main() {
	setlocale(0, "rus");
	int nStaffs = 0;
	Staff* staffs = new Staff[nStaffs];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nStaffs != 0) {
				while (true) {
					int choose1 = chooseWhoRed(staffs, nStaffs);
					if (choose1 == nStaffs) break;
					while (true) {
						int choose2 = chooseWhatRed(staffs, choose1);
						if (choose2 == 8) break;
						string ptr1; int ptr;
						if (choose2 == 0) {
							cout << "������� ��� ������: ";
							ptr1 = writeWords();
							staffs[choose1].changeType(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "������� ������: ";
								ptr1 = writeWords();
								staffs[choose1].changeCountry(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "������� ������: ";
									ptr = writeNumbers();
									staffs[choose1].changeSize(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "������� ����: ";
										ptr1 = writeWords();
										staffs[choose1].changeColor(ptr1);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "������� ������: ";
											ptr1 = writeWords();
											staffs[choose1].changeStructure(ptr1);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "������� ����: ";
												ptr = writeNumbers();
												staffs[choose1].changeHigh(ptr);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "������� ����: ";
													ptr = writeNumbers();
													staffs[choose1].changePrice(ptr);
													system("cls");
												}
												else
													if (choose2 == 7) {
														cout << "������� ������: ";
														ptr = writeNumbers();
														staffs[choose1].changeVote(ptr);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "�� ��� �� �������� �������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Staff p;
				string ptr1; int ptr;
				cout << "������� ��� ������: ";
				ptr1 = writeWords();
				p.changeType(ptr1);
				system("cls");
				cout << "������� ������: ";
				ptr1 = writeWords();
				p.changeCountry(ptr1);
				system("cls");
				cout << "������� ������: ";
				ptr = writeNumbers();
				p.changeSize(ptr);
				system("cls");
				cout << "������� ����: ";
				ptr1 = writeWords();
				p.changeColor(ptr1);
				system("cls");
				cout << "������� ������: ";
				ptr1 = writeWords();
				p.changeStructure(ptr1);
				system("cls");
				cout << "������� ����: ";
				ptr = writeNumbers();
				p.changeHigh(ptr);
				system("cls");
				cout << "������� ����: ";
				ptr = writeNumbers();
				p.changePrice(ptr);
				system("cls");
				cout << "������� ������: ";
				ptr = writeNumbers();
				p.changeVote(ptr);
				system("cls");
				nStaffs++;
				Staff* ptrr = new Staff[nStaffs];
				for (int i = 0; i < nStaffs - 1; i++)
					ptrr[i] = staffs[i];
				staffs = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				staffs[nStaffs - 1] = p;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nStaffs; i++) {
						staffs[i].showAll();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
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
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
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
		cout << "����������� ����� � ���� �������� ����� ����: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> �������� ������" << endl; }
		else { cout << " �������� ������" << endl; }

		if (choose_menu == 1) { cout << " -> ������������� ������" << endl; }
		else { cout << " ������������� ������" << endl; }

		if (choose_menu == 2) { cout << " -> �������� ������" << endl; }
		else { cout << " �������� ������" << endl; }

		if (choose_menu == 3) { cout << " -> ��������� ���������" << endl; }
		else { cout << " ��������� ���������" << endl; }

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

int chooseWhoRed(Staff*& staffs, int nStaffs) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + (nStaffs + 1)) % (nStaffs + 1);

		for (int i = 0; i < nStaffs; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << staffs[i].getType() << endl; }
			else { cout << " " << i + 1 << " - " << staffs[i].getType() << endl; }

		if (choose_menu == nStaffs) { cout << " -> ����� � ������ ������" << endl; }
		else cout << " ����� � ������ ������" << endl;

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

int chooseWhatRed(Staff*& staffs, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> ��� ������: " << staffs[choose].getType() << endl; }
		else cout << " ��� ������: " << staffs[choose].getType() << endl;

		if (choose_menu == 1) { cout << " -> ������: " << staffs[choose].getCountry() << endl; }
		else cout << " ������: " << staffs[choose].getCountry() << endl;

		if (choose_menu == 2) { cout << " -> ������: " << staffs[choose].getSize() << endl; }
		else cout << " ������: " << staffs[choose].getSize() << endl;

		if (choose_menu == 3) { cout << " -> ����: " << staffs[choose].getColor() << endl; }
		else cout << " ����: " << staffs[choose].getColor() << endl;

		if (choose_menu == 4) { cout << " -> ������: " << staffs[choose].getStructure() << endl; }
		else cout << " ������: " << staffs[choose].getStructure() << endl;

		if (choose_menu == 5) { cout << " -> ����: " << staffs[choose].getHigh() << endl; }
		else cout << " ����: " << staffs[choose].getHigh() << endl;

		if (choose_menu == 6) { cout << " -> ����: " << staffs[choose].getPrice() << endl; }
		else cout << " ����: " << staffs[choose].getPrice() << endl;

		if (choose_menu == 7) { cout << " -> ������: " << staffs[choose].getVote() << endl; }
		else cout << " ������: " << staffs[choose].getVote() << endl;

		if (choose_menu == 8) { cout << " -> ����� � ���� ������ " << endl; }
		else cout << " ����� � ���� ������ " << endl;


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
