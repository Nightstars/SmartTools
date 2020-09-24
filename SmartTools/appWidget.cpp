#include "appWidget.h"

appWidget::appWidget(QWidget *parent)
	: QWidget(parent)
{
	m_qbxltContainer = new QVBoxLayout();
	m_qimgAppicon = new QLabel();
	m_qimgAppicon->resize(50,50);
	m_qlbAppName = new QLabel();
	m_qimgAppicon->setAlignment(Qt::AlignCenter);
	m_qlbAppName->setAlignment(Qt::AlignCenter);
	m_qlbAppName->setStyleSheet("size:21px;color:green;font-weight:bold;");
	m_qbxltContainer->addWidget(m_qimgAppicon);
	m_qbxltContainer->addWidget(m_qlbAppName);
	this->setLayout(m_qbxltContainer);
	this->setFixedSize(70,70);
	this->setWindowFlags(Qt::FramelessWindowHint);//无窗体
	this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
}

appWidget::appWidget()
{
	m_qbxltContainer = new QVBoxLayout();
	m_qimgAppicon = new QLabel();
	m_qimgAppicon->resize(50, 50);
	m_qlbAppName = new QLabel();
	m_qimgAppicon->setAlignment(Qt::AlignCenter);
	m_qlbAppName->setAlignment(Qt::AlignCenter);
	m_qimgAppicon->setAttribute(Qt::WA_TranslucentBackground);
	m_qlbAppName->setAttribute(Qt::WA_TranslucentBackground);
	m_qlbAppName->setStyleSheet("size:21px;color:white;font-weight:bold;");
	m_qbxltContainer->addWidget(m_qimgAppicon);
	m_qbxltContainer->addWidget(m_qlbAppName);
	this->setLayout(m_qbxltContainer);
	this->setFixedSize(90, 90);
	//this->setStyleSheet("background:red;");
	setWindowFlags(Qt::FramelessWindowHint);//无窗体
	setAttribute(Qt::WA_TranslucentBackground);//背景透明
}
appWidget::appWidget(QString name, QString icon) {
	m_qbxltContainer = new QVBoxLayout();
	m_qimgAppicon = new QLabel();
	m_qimgAppicon->resize(50, 50);
	m_qlbAppName = new QLabel();
	m_qimgAppicon->setAlignment(Qt::AlignCenter);
	m_qlbAppName->setAlignment(Qt::AlignCenter);
	m_qlbAppName->setStyleSheet("size:21px;color:white;font-weight:bold;");
	m_qimgAppicon->setAttribute(Qt::WA_TranslucentBackground);
	m_qlbAppName->setAttribute(Qt::WA_TranslucentBackground);
	m_qbxltContainer->addWidget(m_qimgAppicon);
	m_qbxltContainer->addWidget(m_qlbAppName);
	this->setLayout(m_qbxltContainer);
	this->setFixedSize(90, 90);
	m_qlbAppName->setText(name);
	QImage* img = new QImage(icon);
	m_qimgAppicon->setPixmap(QPixmap::fromImage(img->scaled(64, 64)));
	//this->setStyleSheet("background:red;");
	setWindowFlags(Qt::FramelessWindowHint);//无窗体
	setAttribute(Qt::WA_TranslucentBackground);//背景透明

}
appWidget::~appWidget()
{
	delete m_qimgAppicon;
	m_qimgAppicon = NULL;
	delete m_qlbAppName;
	m_qlbAppName = NULL;
	delete m_qbxltContainer;
	m_qbxltContainer = NULL;
}
void appWidget::setAppName(const QString& iconName)
{
	m_qlbAppName->setText(iconName);
}
void appWidget::setAppIcon(const QImage& image)
{
	m_qimgAppicon->setPixmap(QPixmap::fromImage(image.scaled(64,64)));
}