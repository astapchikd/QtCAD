#ifndef EDITOR_H
#define EDITOR_H

#include "CodeEditor.h"



class Highlighter;



//����� ����������������� ���������
class Editor : public CodeEditor
{
	Q_OBJECT

	Highlighter* highlighter = NULL; //������ ������ ���������

public:
	Editor(bool isConsole = 0, QWidget* parent = NULL); //�����������
	Highlighter* getHightlighter() { return highlighter; }

};



//����� ��������� ����������
class Highlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	Highlighter(QTextDocument* parent = 0); //�����������
	QList<QRegularExpression> rules;
	QList<QTextCharFormat> formats;

	void addHighlightningRule(QRegularExpression pattern, QTextCharFormat format); //����� ���������� ������ ���������
	void highlightBlock(const QString &text); //����� ��� ���������� ��������� ���������� �����

};

#endif //EDITOR_H