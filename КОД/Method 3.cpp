#include "Header.h"

void Method_3() {

	vector<coord> Test;
	ifstream F("problem.txt", ios_base::in); 
	int n;
	F >> n;

	cout << "Дано: " << n << " исследуемых точек." << endl;

	// Считываем координаты в плоскости Oxy
	double x, y;
	for (int i = 0; i < n; i++) {
		F >> x;
		F >> y;
		Test.push_back({ x,y });
	}

	int m;
	F >> m; // Считываем кол-во вершин данного многоугольника
	cout << "      " << m << "-угольник." << endl << endl;

	// Считываем координаты вершин многоугольника в плоскости
	vector<coord> TestPoligon;
	for (int i = 0; i < m; i++) {
		F >> x;
		F >> y;
		TestPoligon.push_back({ x,y });
	}

	F.close(); // Не забываем закрыть файл :)


	// Запускаем метод №3
	cout << "Метод ближней точки и нормали: " << endl;
	for (int i = 0; i < n; i++) {
		if (met3(Test[i], TestPoligon, m))
			cout << Test[i].x << "  " << Test[i].y << endl;

	}
	cout << endl;

	// Записываем результаты в файл результатов
	ofstream OF("solutions.txt");
	vector<coord> res;

	for (int i = 0; i < n; i++) {
		if (met3(Test[i], TestPoligon, m))
			res.push_back(Test[i]);
	}
	OF << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		OF << setprecision(16) << res[i].x << " " << setprecision(16) << res[i].y << endl;
	}
}

bool met3(const coord& Point, const vector<coord>& Poligon, int n) {
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


