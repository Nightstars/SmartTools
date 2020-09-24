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
	bool eventFilter(QObject* obj, QEvent* event);	// 添加事件过滤器声明
private:
	Ui::SmartCoderClass ui;
	void initTitleBar();
	 // 初始化控件;
	void initControl();
	utils myutils;
	//初始化信号与槽
	void initConnections();
	//apps 空间
    appWidget* m_appWidget;
	//apps 页面表格布局
    QGridLayout* m_qgdltLayout;
	//apps页面垂直布局
    QVBoxLayout* m_qvbltLayout;
	//apps 页面滚动区域
    QScrollArea* m_qscarScroll;
	//文本工具页面编辑器
	CodeEditor *m_codeEditor;
	//文本工具页面水平布局
	QHBoxLayout *m_qhblt_txttool;
	//文本工具右侧按钮栏
	QVBoxLayout* m_qvblt_txttool_btns;
	//文本工具右侧按钮栏简单处理按钮
	QPushButton* m_qphbtn_txttool_btns_easydone;
	//文本工具页面主布局
	QHBoxLayout* txttool_main_layout;
	//文本工具页面垂直滚动条
	QScrollBar* verticalScrollBar;
private slots:
	void onPushButton_disassemblyClicked();
	void onPushButton_selectdllfileClicked();
	void onPushButton_changedlloutputpathClicked();    
};
