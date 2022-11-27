#include "Header.h"

int sign(double x) {
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	else
		return 0;
}

bool met1(const P& Point, const vector<P>& Poligon, int n) {
	double s = 0;
	double skal;
	double len1, len2;
	for (int i = 0, j; i < n; i++) {
		j = i == n - 1 ? 0 : i + 1;

		skal = (Poligon[i].x - Point.x) * (Poligon[j].x - Point.x) + (Poligon[i].y - Point.y) * (Poligon[j].y - Point.y);
		len1 = sqrt((Poligon[i].x - Point.x) * (Poligon[i].x - Point.x) + (Poligon[i].y - Point.y) * (Poligon[i].y - Point.y));
		len2 = sqrt((Poligon[j].x - Point.x) * (Poligon[j].x - Point.x) + (Poligon[j].y - Point.y) * (Poligon[j].y - Point.y));

		s += acos(skal / (len1 * len2)) * sign((Poligon[i].x - Point.x) * (Poligon[j].y - Point.y) - (Poligon[i].y - Point.y) * (Poligon[j].x - Point.x));

	}

	if (abs(s) < (2 * acos(-1) + 0.001) && (abs(s) > (2 * acos(-1) - 0.001)))
		return true;
	return false;
}





bool met1_3D(const P_3D& Point, const vector<P_3D>& Poligon, int n) {
	double A, B, C, D;
	P_3D V1, V2;
	V1 = { Poligon[1].x - Poligon[0].x ,Poligon[1].y - Poligon[0].y ,Poligon[1].z - Poligon[0].z };
	V2 = { Poligon[2].x - Poligon[0].x ,Poligon[2].y - Poligon[0].y ,Poligon[2].z - Poligon[0].z };
	A = (V1.y * V2.z) - (V1.z * V2.y);
	B = -((V1.x * V2.z) - (V1.z * V2.x));
	C = (V1.x * V2.y) - (V1.y * V2.x);
	D = -A * Poligon[0].x - B * Poligon[0].y - C * Poligon[0].z;

	if (abs(A * Point.x + B * Point.y + C * Point.z + D) > 1e-15) //Проверка принадлежности точки плоскости
		return 0;
	P Project_Point = { Point.x,Point.y };
	vector<P> Projection_Polygon;
	for (int i = 0; i < n; i++)
		Projection_Polygon.push_back({ Poligon[i].x,Poligon[i].y });

	return  met1(Project_Point, Projection_Polygon, n);;


}

void Method_1() {

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


	// Запускаем метод №1
	cout << "Метод трассировки лучей:" << endl;
	for (int i = 0; i < n; i++) {
		if (met1(Test[i], TestPoligon, m))
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
		OF << setprecision(16) << res[i].x << " " << setprecision(16) << res[i].y << endl;
	}
}


