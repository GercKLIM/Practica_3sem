#include "Header.h"

void Method_1_3D() {

	int n, m;
	double x, y, z;
	ifstream F2("problem3D.txt", ios_base::in); // Открываем файл координат в пространстве
	F2 >> n; // Считываем количество исследуемых точек

	cout << "Дано: " << n << " исследуемых точек в пространстве." << endl;

	vector<P_3D> Test3D;

	// Считываем координаты в пространстве
	for (int i = 0; i < n; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		Test3D.push_back({ x,y,z });

	}

	F2 >> m; // Считываем количество вершин многоугольника в пространстве
	cout << "      " << m << "-угольник в пространстве." << endl << endl;

	vector<P_3D> TestPoligon3D;

	// Считываем координаты точек вершин многоугольника в пространстве
	for (int i = 0; i < m; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		TestPoligon3D.push_back({ x,y,z });
	}

	F2.close(); // Не забываем закраыть файл исходных данных


	// Запускаем Метод №1
	cout << "Метод трассировки лучей в пространстве:" << endl;
	for (int i = 0; i < n; i++) {
		if (met1_3D(Test3D[i], TestPoligon3D, m))
			cout << Test3D[i].x << "  " << Test3D[i].y << "  " << Test3D[i].z << endl;
	}
	cout << endl;

	// Записываем результаты в соответствующий файл
	ofstream OF2("solutions3D.txt");
	vector<P_3D> res3D;

	for (int i = 0; i < n; i++) {
		if (met1_3D(Test3D[i], TestPoligon3D, m))
			res3D.push_back(Test3D[i]);
	}
	OF2 << res3D.size() << endl;
	for (int i = 0; i < res3D.size(); i++) {
		OF2 << setprecision(16) << res3D[i].x << " " << setprecision(15) << res3D[i].y << " " << setprecision(16) << res3D[i].z << endl;
	}
}