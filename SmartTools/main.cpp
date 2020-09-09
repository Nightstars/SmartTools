#include "smartTools.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QIcon icon(":/icons/Resources/icons/micon.png");
	// 设置程序运行时任务栏的图标。不过该图标并不是程序图标
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
