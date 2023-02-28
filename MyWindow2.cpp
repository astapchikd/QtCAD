#include "MyWindow.h"
MyWindow::MyWindow(QWidget* parent)
{
	setWindowTitle("EE-Epic Editor");
	resize(400,200);
}

void MyWindow::init()
{
	QTextEdit* text = new QTextEdit();
	QStatusBar* status = new QStatusBar(this);
	setStatusBar(status);
	status->showMessage("OK");
	status->setStatusTip("Status bar");
	text->setPlainText("Some Text\nCool");
	setCentralWidget(text);
	
	initActions();
	initMainMenu();


}
void MyWindow::initActions()
{
	actOpen = new QAction("Open", this);
	actSave = new QAction("Save", this);
	actQuit = new QAction("Quit", this);
}
void MyWindow::initMainMenu()
{
	QMenu* menuFile = new QMenu("File");
	menuFile->addAction(actOpen);
	menuFile->addAction(actSave);
	menuFile->addSeparator();
	menuFile->addAction(actQuit);
	menuBar()->addMenu(menuFile);
}
