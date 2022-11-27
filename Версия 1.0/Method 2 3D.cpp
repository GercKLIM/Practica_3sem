#include "Header.h"

void Method_2_3D() {

	int n, m;
	double x, y, z;
	ifstream F2("problem3D.txt", ios_base::in); // Открываем файл координат в пространстве
	F2 >> n; // Считываем количество исследуемых точек

	cout << "Дано: " << n << " исследуемых точек в пространстве." << endl;

	vector<coord3D> Test3D;

	// Считываем координаты в пространстве
	for (int i = 0; i < n; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		Test3D.push_back({ x,y,z });

	}

	F2 >> m; // Считываем количество вершин многоугольника в пространстве
	cout << "      " << m << "-угольник в пространстве." << endl << endl;

	vector<coord3D> TestPoligon3D;

	// Считываем координаты точек вершин многоугольника в пространстве
	for (int i = 0; i < m; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		TestPoligon3D.push_back({ x,y,z });
	}

	F2.close(); // Не забываем закраыть файл исходных данных

	// Запускаем Метод №2
	cout << "Метод суммирования в пространстве:" << endl;
	for (int i = 0; i < n; i++) {
		if (met2_3D(Test3D[i], TestPoligon3D, m))
			cout << Test3D[i].x << "  " << Test3D[i].y << "  " << Test3D[i].z << endl;
	}
	cout << endl;

	// Записываем результаты в соответствующий файл
	ofstream OF2("solutions3D.txt");
	vector<coord3D> res3D;

	for (int i = 0; i < n; i++) {
		if (met2_3D(Test3D[i], TestPoligon3D, m))
			res3D.push_back(Test3D[i]);
	}
	OF2 << res3D.size() << endl;
	for (int i = 0; i < res3D.size(); i++) {
		OF2 << setprecision(16) << res3D[i].x << " " << setprecision(15) << res3D[i].y << " " << setprecision(16) << res3D[i].z << endl;
	}
}

bool met2_3D(const coord3D& Point, const vector<coord3D>& Poligon, int n) {
	double A, B, C, D;
	coord3D V1, V2;
	V1 = { Poligon[1].x - Poligon[0].x ,Poligon[1].y - Poligon[0].y ,Poligon[1].z - Poligon[0].z };
	V2 = { Poligon[2].x - Poligon[0].x ,Poligon[2].y - Poligon[0].y ,Poligon[2].z - Poligon[0].z };
	A = (V1.y * V2.z) - (V1.z * V2.y);
	B = -((V1.x * V2.z) - (V1.z * V2.x));
	C = (V1.x * V2.y) - (V1.y * V2.x);
	D = -A * Poligon[0].x - B * Poligon[0].y - C * Poligon[0].z;

	if (abs(A * Point.x + B * Point.y + C * Point.z + D) > 1e-15)// Проверка принадлежности точки многоугольнику
		return 0;

	coord Projection_Point = { Point.x,Point.y };
	vector<coord> Projection_Polygon;
	for (int i = 0; i < n; i++)
		Projection_Polygon.push_back({ Poligon[i].x,Poligon[i].y });

	return met2(Projection_Point, Projection_Polygon, n);
}