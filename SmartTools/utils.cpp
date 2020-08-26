#include "utils.h"
#include <QFile>
void utils::setIcon(QLabel* qlabel, QString filePath, QSize IconSize)
{
	QPixmap labelIcon(filePath);
	qlabel->setPixmap(labelIcon.scaled(IconSize));
}
//����Label����
void utils::setLabelContent(QLabel* qlabel, QString labelContent, int contentFontSize)
{
        // ���ñ��������С;
        QFont font = qlabel->font();
        font.setPointSize(contentFontSize);
        qlabel->setFont(font);
        // ���ñ�������;
        qlabel->setText(labelContent);
}

void utils::loadStyleSheet(QWidget*obj,const QString& sheetName)
{
    QFile file(":/qss/Resources/qss/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet =obj->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        obj->setStyleSheet(styleSheet);
    }
}
