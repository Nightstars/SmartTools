#include "smartTools.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QPropertyAnimation>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QIcon icon(":/icons/Resources/icons/micon.png");
	// ���ó�������ʱ��������ͼ�ꡣ������ͼ�겢���ǳ���ͼ��
	/*QFont f("����Ҵ����");
	a.setFont(f);*/
	QFontDatabase::addApplicationFont(":/fonts/Resources/fonts/pingfang.ttf");
	QFont font;
	font.setFamily("pingfang");
	a.setFont(font);
	a.setWindowIcon(icon);
	QSplashScreen* splash = new QSplashScreen;
	splash->setPixmap(QPixmap(":/icons/Resources/icons/micon.png"));
	splash->show();
	SmartTools w;
	QPropertyAnimation* animation = new QPropertyAnimation(&w, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	w.show();
	splash->finish(&w);
	delete splash;

	return a.exec();
}
