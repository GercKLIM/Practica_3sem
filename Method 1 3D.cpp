#include "Header.h"

void Method_1_3D() {

	int n, m;
	double x, y, z;
	ifstream F2("problem3D.txt", ios_base::in); // ��������� ���� ��������� � ������������
	F2 >> n; // ��������� ���������� ����������� �����

	cout << "����: " << n << " ����������� ����� � ������������." << endl;

	vector<P_3D> Test3D;

	// ��������� ���������� � ������������
	for (int i = 0; i < n; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		Test3D.push_back({ x,y,z });

	}

	F2 >> m; // ��������� ���������� ������ �������������� � ������������
	cout << "      " << m << "-�������� � ������������." << endl << endl;

	vector<P_3D> TestPoligon3D;

	// ��������� ���������� ����� ������ �������������� � ������������
	for (int i = 0; i < m; i++) {
		F2 >> x;
		F2 >> y;
		F2 >> z;
		TestPoligon3D.push_back({ x,y,z });
	}

	F2.close(); // �� �������� �������� ���� �������� ������


	// ��������� ����� �1
	cout << "����� ����������� ����� � ������������:" << endl;
	for (int i = 0; i < n; i++) {
		if (met1_3D(Test3D[i], TestPoligon3D, m))
			cout << Test3D[i].x << "  " << Test3D[i].y << "  " << Test3D[i].z << endl;
	}
	cout << endl;

	// ���������� ���������� � ��������������� ����
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