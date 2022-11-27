#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus"); // Корректное отображение Кириллицы

	// Метод трасссировки лучей
	Method_1(); 
	Method_1_3D();
	
	// Метод суммирования углов
	Method_2();
	Method_2_3D();

	// Метод №3 ???

	cout << "Конец выполнения программы." << endl;
	
}
