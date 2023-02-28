#ifndef MY_WINDOW_H
#define MY_WINDOW_H
#include "CodeEditor.h"
#include "Editor.h"
//Заголовычные файлы
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <iostream>


//Класс для описания главного окна
class MyWindow : public QMainWindow {
	Q_OBJECT

private:
	//Меню и действия
	QMenu*		mFile;				//Меню "File"
	QMenu* mProject;
	QMenu* mHelp;
	QAction* aAbout;
	QAction*		aOpen;			//Действие открытия файла "Open"
	QAction*		aSave;
	QAction* aSaveAs;
	QAction*		aExit;			//Действие выхода из программы "Exit"
	QAction* aClear;
	QAction* aRun;
	//Панели инструментов (тулбары)
	QToolBar*	tbFile;				//Тулбар "File"
	QProcess* process;
	QProcess* process2;
	//Редактор
	Editor*	editor;				//Редактор
	QDockWidget* consoleDock;
	Editor* console;
	QString filepath;

public:
	//Конструкторы
	MyWindow(QWidget* parent = NULL);

	//Методы инициализации
	void init();					//Общий метод инициализации
	void initActions();				//Инициализация действий
	void initMainMenu();			//Инициализация меню
	void initToolBars();			//Инициализация тулбаров
	void initStatusBar();			//Инициализация статусной строки
	void initCentralWidget();		//Инициализация центрального виджета
	void initConsoleDock();
	void initProcess();
//Слоты
public slots:
	void slotOpen();				//Слот открытия файла
	void slotSaveAs();
	void slotClear();
	void slotRun();
	void slotProcessStarted();
	void slotProcessFinished(int exitCode,QProcess::ExitStatus exitStatus);
	void slotReadStandartOutput();
	void slotSave();
	void slotAbout();
};

#endif // MY_WINDOW_H