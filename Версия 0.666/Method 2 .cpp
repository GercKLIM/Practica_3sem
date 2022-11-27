#include "Header.h"

void Method_2() {

	vector<coord> Test;
	ifstream F("problem.txt", ios_base::in); // ��������� ���� � ������������ � ���������
	int n;
	F >> n; // C�������� ���-�� ����������� �����

	cout << "����: " << n << " ����������� �����." << endl;

	// ��������� ���������� � ��������� Oxy
	double x, y, z;
	for (int i = 0; i < n; i++) {
		F >> x;
		F >> y;
		Test.push_back({ x,y });
	}

	int m;
	F >> m; // ��������� ���-�� ������ ������� ��������������
	cout << "      " << m << "-��������." << endl << endl;

	// ��������� ���������� ������ �������������� � ���������
	vector<coord> TestPoligon;
	for (int i = 0; i < m; i++) {
		F >> x;
		F >> y;
		TestPoligon.push_back({ x,y });
	}

	F.close(); // �� �������� ������� ���� :)

	// ��������� ����� �2
	cout << "����� ������������ �����: " << endl;
	for (int i = 0; i < n; i++) {
		if (met2(Test[i], TestPoligon, m))
			cout << Test[i].x << "  " << Test[i].y << endl;
	}
	cout << endl;

	// ���������� ���������� � ���� �����������
	ofstream OF("solutions.txt");
	vector<coord> res;

	for (int i = 0; i < n; i++) {
		if (met2(Test[i], TestPoligon, m))
			res.push_back(Test[i]);
	}
	OF << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		OF << std::setprecision(16) << res[i].x << " " << std::setprecision(16) << res[i].y << endl;
	}
}

int met2Point(const coord& A, const coord& B, const coord& C) {

	if (((A.y >= B.y) && (A.y <= C.y)) || ((A.y <= B.y) && (A.y >= C.y))) {

		if ((A.y == B.y) && (B.y == C.y)) // ��� ��������� � ��������
		{
			if (((B.x <= A.x) && (A.x <= C.x)) || ((C.x <= A.x) && (A.x <= B.x))) // ����� ����� �� ����������� �������
				return 0;
			return 1; // ���� ��� �������� ����� �������
		}

		if (A.x < (A.y - B.y) / (B.y - C.y) * (B.x - C.x) + B.x) // ����� ����� ����� �� ������� �  ��� ���������� �������
			return -1;

		if ((A.y == B.y) && (A.x == B.x)) // ����� ����� �� �������
			return 0;
		// ���� ����� �������� ����� �������

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

bool met2(const coord& Point, const vector<coord>& Poligon, int n) {
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
