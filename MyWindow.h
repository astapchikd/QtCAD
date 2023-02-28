#ifndef MY_WINDOW_H
#define MY_WINDOW_H
#include "CodeEditor.h"
#include "Editor.h"
//������������ �����
#include <QtWidgets>
#include <QtCore>
#include <QtGui>
#include <iostream>


//����� ��� �������� �������� ����
class MyWindow : public QMainWindow {
	Q_OBJECT

private:
	//���� � ��������
	QMenu*		mFile;				//���� "File"
	QMenu* mProject;
	QMenu* mHelp;
	QAction* aAbout;
	QAction*		aOpen;			//�������� �������� ����� "Open"
	QAction*		aSave;
	QAction* aSaveAs;
	QAction*		aExit;			//�������� ������ �� ��������� "Exit"
	QAction* aClear;
	QAction* aRun;
	//������ ������������ (�������)
	QToolBar*	tbFile;				//������ "File"
	QProcess* process;
	QProcess* process2;
	//��������
	Editor*	editor;				//��������
	QDockWidget* consoleDock;
	Editor* console;
	QString filepath;

public:
	//������������
	MyWindow(QWidget* parent = NULL);

	//������ �������������
	void init();					//����� ����� �������������
	void initActions();				//������������� ��������
	void initMainMenu();			//������������� ����
	void initToolBars();			//������������� ��������
	void initStatusBar();			//������������� ��������� ������
	void initCentralWidget();		//������������� ������������ �������
	void initConsoleDock();
	void initProcess();
//�����
public slots:
	void slotOpen();				//���� �������� �����
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