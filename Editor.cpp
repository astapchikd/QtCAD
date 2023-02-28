#include "Editor.h"

Editor::Editor(bool isConsole, QWidget* parent) : CodeEditor(isConsole, parent){
	highlighter = new Highlighter(this->document());
}

Highlighter::Highlighter(QTextDocument* parent) : QSyntaxHighlighter(parent){
    QRegularExpression expr("\\b(warning)\\b", QRegularExpression::CaseInsensitiveOption);
    QTextCharFormat format;            //������� �������������� ������
    format.setForeground(              //������������� ���� ������
        QColor(Qt::yellow).lighter(130)
    );
    addHighlightningRule(expr, format);
    QRegularExpression expr1("\\b(R|L|C|X|D|V|I)\\d*\\b", QRegularExpression::CaseInsensitiveOption);// \\b(double|bool)\\b     ------------!!!!!(R|L|C|X|D|V|I)\w*
    QTextCharFormat format1;            //������� �������������� ������
    format1.setForeground(              //������������� ���� ������
        QColor(Qt::blue).lighter(130)
    );
    addHighlightningRule(expr1, format1);
    QRegularExpression expr2("\\B(\\.\\w*)");// \\b(double|bool)\\b
    QTextCharFormat format2;            //������� �������������� ������
    format2.setForeground(              //������������� ���� ������
        QColor(Qt::magenta).lighter(130)
    );
    addHighlightningRule(expr2, format2);
    /*QRegularExpression charExpr("\".*\"");
    QTextCharFormat charFormat;
    charFormat.setForeground(QColor(Qt::red));*/
    QRegularExpression commentExpr("\\*.*");
    QTextCharFormat commentFormat;
    commentFormat.setForeground(QColor(Qt::green));
    addHighlightningRule(commentExpr, commentFormat);
    QRegularExpression commentExpr1("\\b(OK)\\b", QRegularExpression::CaseInsensitiveOption);
    addHighlightningRule(commentExpr1, commentFormat);
    QRegularExpression expr3("\\b(error)\\b", QRegularExpression::CaseInsensitiveOption);
    QTextCharFormat format3;            //������� �������������� ������
    format3.setForeground(              //������������� ���� ������
        QColor(Qt::red).lighter(130)
    );
    addHighlightningRule(expr3, format3);
}
void Highlighter::addHighlightningRule(QRegularExpression pattern, QTextCharFormat format){
    rules.push_back(pattern);
    formats.push_back(format);
}
void Highlighter::highlightBlock(const QString &text){
    for (int i = 0; i < rules.size(); i++)
    {
        QRegularExpression expr = rules.at(i);
        QTextCharFormat format = formats.at(i);

        //QRegularExpression expr("\\b(int|void)\\b"); //��������� ��� ���� int � void
        //QRegularExpression expr1("\\b(double|bool)\\b");

        //QTextCharFormat format;            //������� �������������� ������
        //format.setForeground(              //������������� ���� ������
        //    QColor(Qt::blue).lighter(130)  //����� (lighter ���������� (>100) ���
        //);                                 //    ��������� (<100))
        {
            QRegularExpressionMatch match = expr.match(text); //���� ���������
            while (match.hasMatch()) {                          //���� ��������� ����
                setFormat(match.capturedStart(),              //������������� ������ ���
                    match.capturedLength(), format);    //    ���������� ��������� 
                match = expr.match(text, match.capturedEnd());//���� ��������� ���������
            }
        }
        //{
        //    QRegularExpressionMatch match = expr1.match(text); //���� ���������
        //    while (match.hasMatch()) {                          //���� ��������� ����
        //        setFormat(match.capturedStart(),              //������������� ������ ���
        //            match.capturedLength(), format);    //    ���������� ��������� 
        //        match = expr.match(text, match.capturedEnd());//���� ��������� ���������
        //    }
        //}
    }

}