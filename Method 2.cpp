#include "Header.h"


int met2Point(const P& A, const P& B, const P& C) {

	if (((A.y >= B.y) && (A.y <= C.y)) || ((A.y <= B.y) && (A.y >= C.y))) {

		if ((A.y == B.y) && (B.y == C.y)) // Луч совпадает с отрезком
		{
			if (((B.x <= A.x) && (A.x <= C.x)) || ((C.x <= A.x) && (A.x <= B.x))) // Точка лежит на совпадающем отрезке
				return 0;
			return 1; // Если луч проходит через сторону
		}

		if (A.x < (A.y - B.y) / (B.y - C.y) * (B.x - C.x) + B.x) // Точка лежит слева от стороны и  луч пересекает сторону
			return -1;

		if ((A.y == B.y) && (A.x == B.x)) // Точка лежит на вершине
			return 0;
		// Если точка проходит через вершину

		if ((C.y == A.y) && (C.y > B.y))
			return 1;
		if ((B.y == A.y) && (B.y > C.y))
			return 1;
		if ((C.y == A.y) && (B.y > C.y))
			return -1;
		if ((B.y == A.y) && (C.y > B.y))
			return -1;
	}
	return 1;
};

bool met2(const P& Point, const vector<P>& Poligon, int n) {
	int s = 1;
	for (int i = 0, j; i < n; i++) {
		j = i == n - 1 ? 0 : i + 1;
		s *= met2Point(Point, Poligon[i], Poligon[j]);

	};

	if (s == -1) {
		return true;
	}
	return false;

};



bool met2_3D(const P_3D& Point, const vector<P_3D>& Poligon, int n) {
	double A, B, C, D;
	P_3D V1, V2;
	V1 = { Poligon[1].x - Poligon[0].x ,Poligon[1].y - Poligon[0].y ,Poligon[1].z - Poligon[0].z };
	V2 = { Poligon[2].x - Poligon[0].x ,Poligon[2].y - Poligon[0].y ,Poligon[2].z - Poligon[0].z };
	A = (V1.y * V2.z) - (V1.z * V2.y);
	B = -((V1.x * V2.z) - (V1.z * V2.x));
	C = (V1.x * V2.y) - (V1.y * V2.x);
	D = -A * Poligon[0].x - B * Poligon[0].y - C * Poligon[0].z;

	if (abs(A * Point.x + B * Point.y + C * Point.z + D) > 1e-15)// Проверка принадлежности точки многоугольнику
		return 0;

	P Projection_Point = { Point.x,Point.y };
	vector<P> Projection_Polygon;
	for (int i = 0; i < n; i++)
		Projection_Polygon.push_back({ Poligon[i].x,Poligon[i].y });

	return met2(Projection_Point, Projection_Polygon, n);
}

void Method_2() {

	vector<P> Test;
	ifstream F("problem.txt", ios_base::in); // Открываем файл с координатами в плоскости
	int n;
	F >> n; // Cчитываем кол-во исследуемых точек

	cout << "Дано: " << n << " исследуемых точек." << endl;

	// Считываем координаты в плоскости Oxy
	double x, y, z;
	for (int i = 0; i < n; i++) {
		F >> x;
		F >> y;
		Test.push_back({ x,y });
	}

	int m;
	F >> m; // Считываем кол-во вершин данного многоугольника
	cout << "      " << m << "-угольник." << endl << endl;

	// Считываем координаты вершин многоугольника в плоскости
	vector<P> TestPoligon;
	for (int i = 0; i < m; i++) {
		F >> x;
		F >> y;
		TestPoligon.push_back({ x,y });
	}

	F.close(); // Не забываем закрыть файл :)

	// Запускаем метод №2
	cout << "Метод суммирования углов: " << endl;
	for (int i = 0; i < n; i++) {
		if (met2(Test[i], TestPoligon, m))
			cout << Test[i].x << "  " << Test[i].y << endl;
	}
	cout << endl;

	// Записываем результаты в файл результатов
	ofstream OF("solutions.txt");
	vector<P> res;

	for (int i = 0; i < n; i++) {
		if (met1(Test[i], TestPoligon, m))
			res.push_back(Test[i]);
	}
	OF << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		OF << std::setprecision(16) << res[i].x << " " << std::setprecision(16) << res[i].y << endl;
	}
}
