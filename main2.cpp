#include "MyWindow.h"
#include<QApplication>//#include <QApplication>
#include<QPushButton>//#include <QPushButton>
#include<QtWidgets>
#include<QtCore>
#include<QtGui>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MyWindow w;
	w.show();
	w.init();
	/*MyWidget w;
	w.setWindowTitle("PKIMS");
	w.resize(400, 300);
	w.move(0, 0);
	w.setWindowIcon(QPixmap("crom.jpg"));*/
	/////////////////
	/*QVBoxLayout* layout = new QVBoxLayout();
	QLabel* pic = new QLabel();
	pic->setPixmap(QPixmap("crom.jpg"));
	pic->setAlignment(Qt::AlignCenter); 
	QLabel* picLabel = new QLabel("<font color = \"green\"><b>PKIMS</b>!</font>");
	picLabel->setAlignment(Qt::AlignCenter);
	QLabel* label = new QLabel("<font color = \"blue\">The cool<b>SICK</b>!</font>");
	label->setAlignment(Qt::AlignCenter);
	layout->addWidget(pic);
	layout->addWidget(picLabel);
	layout->addWidget(label);
	w.setLayout(layout);*/
	//////////////
	/*w.show();*/

	/*QPushButton button("Hello world !");
	button.show();*/
	//////////////
	return app.exec();
}