#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void Method_1();
void Method_2();
void Method_1_3D();
void Method_2_3D();

// Структура определяющаяя координаты в плоскости
struct coord{
	double x;
	double y;

	//Задаем операцию вычитания для координат
	coord operator-(const coord& b) const { 
		coord res;
		res = { (*this).x - b.x,(*this).y - b.y };
		return res;
	}
	//Задаем операцию сложения для координат
	coord operator+(const coord& b) const {
		coord res;
		res = { (*this).x + b.x,(*this).y + b.y };
		return res;
	}
};

// Структура определяющая координаты в 3D
struct coord3D {  
	double x;
	double y;
	double z;

	//Задаем операцию вычитания для координат в 3D
	coord3D operator-(const coord3D& b) const {
		coord3D res;
		res = { (*this).x - b.x,(*this).y - b.y, (*this).z - b.z};
		return res;
	}
	//Задаем операцию сложения для координат d 3D
	coord3D operator+(const coord3D& b) const {
		coord3D res;
		res = { (*this).x + b.x,(*this).y + b.y, (*this).z + b.z };
		return res;
	}
};

// Метод №1 : Трассировка лучей

/* 

1. Из тестируемой точки выпускаем луч либо в заранее заданном, либо в произвольном направлении.
2. Считаем количество пересечений с многоугольником.
3. Если количество пересечений четное, мы находимся снаружи.Если количество пересечений нечетное, мы – внутри.

*/

int sign(double x);

bool met1(const coord& Point, const vector<coord>& Poligon, int n);

bool met1_3D(const coord3D& Point, const vector<coord3D>& Poligon, int n);



// Метод №2 : Суммирование углов

/*
1. обойти все вершины многоугольника и просуммировать все углы, которые образуются при переходе от одной вершины к другой, относительно исследуемой точке
2. Если поворот происходит против часовой стрелки, то будем считать, что знак угла положительный, в противоположном случае – отрицательный
3. Если точка лежит внутри многоугольника, то совершиться полный оборот вокруг исследуемой точки и сумма всех таких углов будет равна 2π или -2π, в зависимости от обхода многоугольника

*/

int met2Point(const coord& A, const coord& B, const coord& C);

bool met2(const coord& Point, const vector<coord>& Poligon, int n);

bool met2_3D(const coord3D& Point, const vector<coord3D>& Poligon, int n);


