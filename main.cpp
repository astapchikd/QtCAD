#include "MyWindow.h"
#include<iostream>
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	QApplication a(argc, argv);

	MyWindow w;
	w.show();

	return a.exec();
}
