#pragma once
#include <QtWidgets/QWidget>
#include <QLabel>
class utils
{
	public:
		//����Label�ı�����
		void setIcon(QLabel *qlabel, QString filePath, QSize IconSize);
		//����Label�ı�����
		void setLabelContent(QLabel* qlabel,QString labelContent, int labelFontSize = 9);
		// ������ʽ�ļ�;
		void loadStyleSheet(QWidget*obj,const QString& sheetName);
};

