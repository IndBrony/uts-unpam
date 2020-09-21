#include <iostream>
#include <iomanip>
#include <tuple>
#include <math.h>
#include <stdlib.h>
using namespace std;

void calculateArea();
void calculatePerimeter();
void calculateDiagonal();
tuple<int, int> getSidesLength();
int main() {
	bool running = true;
	while (running) {
		unsigned short operation;
		cout << "==========================================" << endl;
		cout << "MENU EMPAT PERSEGI PANJANG" << endl;
		cout << "\t1. Hitung Luas" << endl;
		cout << "\t2. Hitung Keliling" << endl;
		cout << "\t3. Hitung Panjang Diagonal" << endl;
		cout << "\t4. Keluar Program" << endl;
		cout << "==========================================" << endl;
		cout << "Pilih Nomor: ";
		cin >> operation;

		switch (operation)
		{
		case 1:
			calculateArea();
			break;
		case 2:
			calculatePerimeter();
			break;
		case 3:
			calculateDiagonal();
			break;
		default:
			running = false;
			break;
		}
		if (running) {
			char answer;
			cout << "Lagi [y/N]?";
			cin >> answer;
			running = answer == 'y';
		}
	}

}

tuple<int, int> getSidesLength()
{
	int firstSide, secondSide;
	cout << "Masukkan panjang sisi pertama : ";
	cin >> firstSide;
	cout << "Masukkan panjang sisi kedua : ";
	cin >> secondSide;
	return tuple<int, int>(firstSide, secondSide);
}
void calculateArea(){
	tuple<int, int> sides = getSidesLength();
	int area = get<0>(sides) * get<1>(sides);
	cout << "Luas: " << area << endl;
	cout << endl;
}

void calculatePerimeter()
{
	tuple<int, int> sides = getSidesLength();
	int perimeter = 2 * (get<0>(sides) + get<1>(sides));
	cout << "Keliling: " << perimeter << endl;
	cout << endl;
}

void calculateDiagonal()
{
	tuple<int, int> sides = getSidesLength();
	double diagonal = sqrt( pow(get<0>(sides), 2) + pow(get<1>(sides), 2) );
	cout << "Panjang Diagonal: " << diagonal << endl;
	cout << endl;
}