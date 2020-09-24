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
#include "CodeEditor.h"
#include <QScrollBar>

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
	//apps �ռ�
    appWidget* m_appWidget;
	//apps ҳ���񲼾�
    QGridLayout* m_qgdltLayout;
	//appsҳ�洹ֱ����
    QVBoxLayout* m_qvbltLayout;
	//apps ҳ���������
    QScrollArea* m_qscarScroll;
	//�ı�����ҳ��༭��
	CodeEditor *m_codeEditor;
	//�ı�����ҳ��ˮƽ����
	QHBoxLayout *m_qhblt_txttool;
	//�ı������Ҳఴť��
	QVBoxLayout* m_qvblt_txttool_btns;
	//�ı������Ҳఴť���򵥴���ť
	QPushButton* m_qphbtn_txttool_btns_easydone;
	//�ı�����ҳ��������
	QHBoxLayout* txttool_main_layout;
	//�ı�����ҳ�洹ֱ������
	QScrollBar* verticalScrollBar;
private slots:
	void onPushButton_disassemblyClicked();
	void onPushButton_selectdllfileClicked();
	void onPushButton_changedlloutputpathClicked();    
};
