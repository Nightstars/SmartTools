#pragma once

#include <QtWidgets/QWidget>
#include "ui_smarttools.h"
#include "basewindow.h"
#include "utils.h"
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <Windows.h>
#include <QMessageBox>
#include <QFileDialog>
#include <numeric> // for std::accumulate
#include <string>  // for std::string
#include <vector>  // for std::vector
#include <iostream>
#include "flatui.h"
#include "appWidget.h"
#include <QScrollArea>

class SmartTools : public BaseWindow
{
	Q_OBJECT

public:
	SmartTools(QWidget *parent = Q_NULLPTR);
	bool eventFilter(QObject* obj, QEvent* event);	// ����¼�����������
private:
	Ui::SmartCoderClass ui;
	void initTitleBar();
	 // ��ʼ���ؼ�;
	void initControl();
	utils myutils;
	//��ʼ���ź����
	void initConnections();
    appWidget* m_appWidget;
    QGridLayout* m_qgdltLayout;
    QVBoxLayout* m_qvbltLayout;
    QScrollArea* m_qscarScroll;
private slots:
	void onPushButton_disassemblyClicked();
	void onPushButton_selectdllfileClicked();
	void onPushButton_changedlloutputpathClicked();    
};
