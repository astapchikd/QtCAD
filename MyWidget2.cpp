#include "MyWidget.h"
MyWidget::MyWidget(QWidget* parent) :QWidget(parent)
{
	QVBoxLayout* layout = new QVBoxLayout();
	pic = new QLabel();
	pic->setPixmap(QPixmap("crom.jpg"));
	pic->setAlignment(Qt::AlignCenter);
	picLabel = new QLabel("<font color = \"green\"><b>PKIMS</b>!</font>");
	picLabel->setAlignment(Qt::AlignCenter);
	label = new QLabel("<font color = \"blue\">The cool<b>SICK</b>!</font>");
	label->setAlignment(Qt::AlignCenter);
	QPushButton* button = new QPushButton("Click me");
	connect(button, SIGNAL(clicked()), SLOT(slotAppClosed()));
	connect(button,SIGNAL(clicked()),SLOT(close()));
	connect(this,SIGNAL(signalAppStarted()),this,SLOT(slotAppStarted()));
	connect(this, SIGNAL(signalAppClosed()), this, SLOT(slotAppClosed()));
	layout->addWidget(pic);
	layout->addWidget(picLabel);
	layout->addWidget(label);
	layout->addWidget(button);
	setLayout(layout);
}
bool MyWidget::event(QEvent* e)
{
	if (e->type() == QEvent::MouseButtonPress)
		picLabel->setText("pressed");
	else if (e->type() == QEvent::MouseButtonRelease)
		picLabel->setText("unpressed");
	else if (e->type() == QEvent::Enter)
		label->setText("Hi");
	else if (e->type() == QEvent::Leave)
		label->setText("Bye");
	else if (e->type() == QEvent::Show)
		emit signalAppStarted();
	/*else if (e->type() == QEvent::Close)
		emit signalAppClosed();*/
	return QWidget::event(e);
}
void MyWidget::slotAppStarted()
{
	QMessageBox::information(this,"Info","Application started!");
}
void MyWidget::slotAppClosed()
{
	QMessageBox::information(this, "Info", "Exit?");
}