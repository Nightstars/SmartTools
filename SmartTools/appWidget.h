#pragma once

#include <QObject>
#include <qlabel.h>
#include <qboxlayout.h>

class appWidget : public QWidget
{
	Q_OBJECT

public:
	appWidget(QWidget*parent);
	appWidget();
	appWidget(QString name, QString icon);
	~appWidget();
	void setAppIcon(const QImage& image);
	void setAppName(const QString& iconName);
private:
	QLabel *m_qimgAppicon;
	QLabel *m_qlbAppName;
	QVBoxLayout *m_qbxltContainer;
};
