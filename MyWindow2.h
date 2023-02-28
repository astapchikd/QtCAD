#pragma once
#include<QtWidgets>
#include<QtCore>
#include<QtGui>
class MyWindow :public QMainWindow
{
public:
	MyWindow(QWidget *parent=0);
	void init();
	void initActions();
	void initMainMenu();
private:
	QAction* actOpen;
	QAction* actSave;
	QAction* actQuit;
};