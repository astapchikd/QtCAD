#include "MyWindow.h"

MyWindow::MyWindow(QWidget* parent) : QMainWindow(parent) {
	
	init();

	resize(400, 400);
	setWindowTitle("EE - Epic Editor");

}

void MyWindow::init(){
	initActions();
	initProcess();
	initMainMenu();
	initToolBars();
	initStatusBar();
	initCentralWidget();
	initConsoleDock();
	

}
void MyWindow::slotProcessStarted()
{
	aRun->setEnabled(0);
	console->appendPlainText("");
	console->appendPlainText("ProcessStarted");
	console->appendPlainText("");
	//console->appendPlainText(process->arguments());

}
void MyWindow::slotProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{

	aRun->setEnabled(1);
	console->appendPlainText("");
	console->appendPlainText("ProcessFinsished");
	if(exitCode==0)
		console->appendPlainText("OK");
	else 
		console->appendPlainText("error");
	console->appendPlainText("");

}
void MyWindow::slotReadStandartOutput()
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
	QString out = QString::fromLocal8Bit(process->readAllStandardOutput());
	console->appendPlainText(out.trimmed());
	console->verticalScrollBar()->setValue(console->verticalScrollBar()->maximum());
}
void MyWindow::initActions(){
	//Инициализируем действия
	aExit = new QAction(QPixmap("Resources/Exit.png"), "Exit", this);
	aOpen = new QAction(QPixmap("Resources/Open.png"), "Open", this);
	aSave = new QAction(QPixmap("Resources/Save.png"), "Save", this);
	aSaveAs = new QAction(QPixmap("Resources/SaveAs.png"), "SaveAs", this);
	aClear= new QAction(QPixmap("Resources/Clear.png"), "Clear", this);
	aRun= new QAction(QPixmap("Resources/Run.png"), "Run", this);
	aAbout = new QAction(QPixmap("Resources/Font.png"), "About", this);
	//Соединяем действия со слотами
	connect(aExit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(aOpen, SIGNAL(triggered()), SLOT(slotOpen()));
	connect(aSaveAs, SIGNAL(triggered()), SLOT(slotSaveAs()));
	connect(aSave, SIGNAL(triggered()), SLOT(slotSave()));
	connect(aClear, SIGNAL(triggered()), SLOT(slotClear()));
	connect(aAbout, SIGNAL(triggered()), SLOT(slotAbout()));
	QObject::connect(aRun, SIGNAL(triggered()), SLOT(slotRun()));

}

void MyWindow::initMainMenu(){
	//Инициализируем меню
	mFile = new QMenu("File", this);
	mProject = new QMenu("Project", this);
	mHelp = new QMenu("Help", this);
	//Заполняем меню
	mFile->addAction(aOpen);
	//mFile->addAction(aSave);
	mFile->addSeparator();
	mFile->addAction(aSave);
	mFile->addAction(aSaveAs);
	mFile->addAction(aClear);
	mFile->addAction(aExit);
	mProject->addAction(aRun);
	mHelp->addAction(aAbout);
	//Добавляем меню в панель меню
	menuBar()->addMenu(mFile);
	menuBar()->addMenu(mProject);
	menuBar()->addMenu(mHelp);

}

void MyWindow::initToolBars(){
	//Инициализируем тулбары
	tbFile = new QToolBar(this);

	//Заполняем тулбар
	tbFile->addAction(aOpen);
	tbFile->addSeparator();
	tbFile->addAction(aSave);
	tbFile->addAction(aSaveAs);
	tbFile->addAction(aClear);
	tbFile->addAction(aRun);
	tbFile->addAction(aExit);
	tbFile->addAction(aAbout);

	//Добавляем тулбар в панель тулбаров
	addToolBar(Qt::TopToolBarArea, tbFile);

}

void MyWindow::initCentralWidget(){
	//Инициализируем редактор
	editor = new Editor(0,this);

	//Устанавливаем в качестве центрального виджета
	setCentralWidget(editor);

}

void MyWindow::initStatusBar(){
	//Инициализируем статусную строку
	QStatusBar* bar = new QStatusBar(this);

	//Задаем начальное сообщение
	if (filepath.isEmpty())
	{
		bar->showMessage("Ready to work!");
	}
	else
	{
		bar->showMessage(filepath);
	}

	//Добавляем статусную строку
	setStatusBar(bar);

}
void MyWindow::initConsoleDock()
{
	consoleDock = new QDockWidget("Console", this);
	consoleDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
	consoleDock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
	addDockWidget(Qt::LeftDockWidgetArea,consoleDock);
	console = new Editor(1, consoleDock);
	consoleDock->setWidget(console);

}
void MyWindow::initProcess()
{
	process = new QProcess(this);
	
	process2 = new QProcess(this);
	//process->setProcessChannelMode(QProcess::MergedChannels);
	QObject::connect(process,SIGNAL(started()),this,SLOT(slotProcessStarted()));
	QObject::connect(process,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slotProcessFinished(int,QProcess::ExitStatus)));
	QObject::connect(process2, SIGNAL(started()), this, SLOT(slotProcessStarted()));
	QObject::connect(process2, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(slotProcessFinished(int, QProcess::ExitStatus)));
	//QObject::connect(process2, SIGNAL(started()), this, SLOT(slotProcessStarted()));
	//QObject::connect(process2, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(slotProcessFinished(int, QProcess::ExitStatus)));
	//connect(process, //Если процесс
	//	SIGNAL(readyReadStandardOutput()), //готов к считыванию стандартного вывода,
	//	this, //то у этого окна
	//	SLOT(slotReadSatndartOutput())); //выполнить указанный слот
}
void MyWindow::slotOpen(){
	QString filename = QFileDialog::getOpenFileName(
		this,
		"Select",
		"",
		"All (*);; SPICE (*.sp)"
	);
	if (filename.isEmpty())
	{
		return;
	}
	filepath = filename;
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	editor->clear();
	editor->setPlainText(file.readAll());
	file.close();
	QStatusBar* bar = new QStatusBar(this);
	bar->showMessage(filepath);
	setStatusBar(bar);
}
void MyWindow::slotSaveAs()
{
	QString filename;
	filename = QFileDialog::getSaveFileName();
	if (filename.isEmpty()) return;
	QFile file;
	file.setFileName(filename);
	if (!file.open(QIODevice::WriteOnly)) return;
	QTextStream out(&file);
	out << editor->toPlainText();
	file.close();
}
void MyWindow::slotSave()
{
	if (filepath.isEmpty())
	{
		QString filename;
		filename = QFileDialog::getSaveFileName();
		if (filename.isEmpty()) return;
		QFile file;
		file.setFileName(filename);
		if (!file.open(QIODevice::WriteOnly)) return;
		QTextStream out(&file);
		out << editor->toPlainText();
		file.close();
		filepath = filename;
	}
	else
	{
		QFile file;
		file.setFileName(filepath);
		if (!file.open(QIODevice::WriteOnly)) return;
		QTextStream out(&file);
		out << editor->toPlainText();
		file.close();

	}
}
void MyWindow::slotClear()
{
	editor->clear();
	
}
void MyWindow::slotRun()
{
	QStringList args;
	QStringList args1;
	args << "--input"<<filepath;
	//args << filepath;"D:\KRPO_Lab_0x03_hometask\KRPO_Simulator\bin\KRPO_Simulator.exe"
	//process->start("KRPO_Simulator.exe", args);
	//args1 << "netlists/lab_3.sp.psf";
	process->start("KRPO_Simulator.exe", args);
	
	process->arguments().clear();
	args1 << filepath + ".psf";
	//process->setArguments(args1);
	process2->start("wxproj.exe",args1);
	//process->waitForStarted(-1);
	//args1 << filepath + ".psf";
	//process->start("D:/wxproj/wxproj/x64/Debug/wxproj.exe",args);
	process->setProcessChannelMode(QProcess::MergedChannels);
	process2->setProcessChannelMode(QProcess::MergedChannels);
	//process2->setProcessChannelMode(QProcess::MergedChannels);
	QObject::connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadStandartOutput()));
	QObject::connect(process2, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadStandartOutput()));
	//QObject::connect(process2, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadStandartOutput()));

}
void MyWindow::slotAbout()
{
	QMessageBox msgBox;
	msgBox.setText("This programm using for modeling SPICE");
	msgBox.setInformativeText("developed by PKIMS");
	msgBox.setIconPixmap(QPixmap("Resources/Russian.png"));
	msgBox.setDefaultButton(QMessageBox::Ok);
	int res = msgBox.exec();
	if (res == QMessageBox::Ok)
		msgBox.close();
}
//void MyWindow::slotProcessStarted()
//{
//	aRun->setEnabled(0);
//	console->appendPlainText("");
//	console->appendPlainText("ProcessStarted");
//	console->appendPlainText("");
//
//}
//void MyWindow::slotProcessFinished(int exitCode,QProcess::ExitStatus exitStatus)
//{
//
//	aRun->setEnabled(1);
//	console->appendPlainText("");
//	console->appendPlainText("ProcessFinsished");
//	console->appendPlainText(QString("Exit code: %1").arg(exitCode));
//	console->appendPlainText("");
//
//}
//void MyWindow::slotReadStandartOutput()
//{
//	QString out = process->readAllStandardOutput();
//	console->appendPlainText(out.trimmed());
//	console->verticalScrollBar()->setValue(console->verticalScrollBar()->maximum());
//}
