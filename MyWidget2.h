#pragma once
#include<QtWidgets>
#include<QtCore>
#include<QtGui>
#include<QPushButton>
class MyWidget : public QWidget
{
	Q_OBJECT

private:
	QLabel* pic;
	QLabel* picLabel;
	QLabel* label;
	
public:
	MyWidget(QWidget *parent=0);
	bool event(QEvent* e);
signals:
	void signalAppStarted();
	void signalAppClosed();
public slots:
	void slotAppStarted();
	void slotAppClosed();
};