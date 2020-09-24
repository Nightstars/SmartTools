#include "smartTools.h"
using namespace std;

#pragma region 界面
SmartTools::SmartTools(QWidget *parent)
	: BaseWindow(parent)
{
#pragma endregion

#pragma region 全局配置
	ui.setupUi(this);
	// 设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

	QIcon icon(":/icons/Resources/icons/micon.png");
	setWindowIcon(icon);
	// 初始化标题栏;
	initTitleBar();
	//设置窗体大小
	resize(1200, 780);
	ui.main_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.plugin_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.disassem_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.net_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.mine_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.main_page->setCurrentIndex(0);
	FlatUI::setPushButtonQssLg(ui.pushButton_disassembly, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6",25);
	FlatUI::setPushButtonQss(ui.pushButton_selectdllfile, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
	FlatUI::setPushButtonQss(ui.pushButton_changedlloutputpath, 5, 8, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
	FlatUI::setLineEditQss(ui.dllfileselected_lineEdit, 5, 2, "#DCE4EC", "#1ABC9C");
	FlatUI::setLineEditQss(ui.lineEdit_dlloutputprojpath, 5, 2, "#DCE4EC", "#1ABC9C");
	ui.stackedWidget_2->setAttribute(Qt::WA_TranslucentBackground);
#pragma endregion

//#pragma region 设置圆角窗体
//		QBitmap bmp(this->size());
//		bmp.fill();
//		QPainter p(&bmp);
//		p.setRenderHint(QPainter::Antialiasing);
//		p.setPen(Qt::NoPen);
//		p.setBrush(Qt::black);
//		p.drawRoundedRect(bmp.rect(), 7, 7);
//		setMask(bmp);
//#pragma endregion

#pragma region 设置窗体背景
	this->setAttribute(Qt::WA_StyledBackground);
	//this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	//QPalette palette = this->palette();
	//palette.setBrush(backgroundRole(),
	//QBrush(QPixmap(":/skins/Resources/skins/skins11.png").scaled(// 缩放背景图.
	//		this->size(),
	//		Qt::IgnoreAspectRatio,
	//		Qt::SmoothTransformation)));             // 使用平滑的缩放方式
	//this->setPalette(palette);

#pragma endregion

#pragma region 初始化
	//初始化控件
	initControl();
	//初始化事件绑定
	initConnections();
#pragma endregion
}
#pragma region 初始化标题栏
void SmartTools::initTitleBar()
{
	// 设置标题栏跑马灯效果，可以不设置;
	//m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon(":/icons/Resources/icons/micon.png", {18,18});
	m_titleBar->setTitleContent(QStringLiteral("SmartTools"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}
#pragma endregion

#pragma region 初始化控件
void SmartTools::initControl()
{
	#pragma region 初始化主按钮
	myutils.setIcon(ui.mianlabel_icon, ":/imgs/Resources/imgs/apps_color.png", { 40,40 });
	myutils.setLabelContent(ui.mianlabel_txt, QStringLiteral("实用工具"));
	ui.mainframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.pluginlabel_icon, ":/imgs/Resources/imgs/appstore_color.png", { 40,40 });
	myutils.setLabelContent(ui.pluginlabel_txt, QStringLiteral("应用中心"));
	ui.pluginframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.disassemlabel_icon, ":/imgs/Resources/imgs/disassem_color.png", { 40,40 });
	myutils.setLabelContent(ui.disassemlabel_txt, QStringLiteral("反汇编"));
	ui.disassemframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.netlabel_icon, ":/imgs/Resources/imgs/net_color.png", { 40,40 });
	myutils.setLabelContent(ui.netlabel_txt, QStringLiteral("内网穿透"));
	ui.netframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.minelabel_icon, ":/imgs/Resources/imgs/mine_color.png", { 40,40 });
	myutils.setLabelContent(ui.minelabel_txt, QStringLiteral("我的"));
	ui.mineframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	#pragma endregion

	#pragma region 初始化样式表
	//加载样式表
	myutils.loadStyleSheet(this, "myapp");
	ui.dllfileaddr_label->setStyleSheet("background-color:transparent");
	ui.label_dllprojoutputpath->setStyleSheet("background-color:transparent");
	ui.main_page->setCurrentIndex(6);
	ui.myapps_page->setAttribute(Qt::WA_TranslucentBackground);
	ui.plugin_page->setAttribute(Qt::WA_TranslucentBackground);
	ui.disassem_page->setAttribute(Qt::WA_TranslucentBackground);
	ui.mine_page->setAttribute(Qt::WA_TranslucentBackground);
	ui.net_page->setAttribute(Qt::WA_TranslucentBackground);
	#pragma endregion

	#pragma region 初始化apps
		m_appWidget = new appWidget[20];
		
		for (int i = 0; i < 20; i++) {
			QImage* img;
			
			if (i == 0) {
				img = new QImage(":/imgs/Resources/imgs/txttool.png");
				(m_appWidget + i)->setAppName(QStringLiteral("文本工具"));
			}
			else {
				img = new QImage(":/imgs/Resources/imgs/commingsoon.png");
				(m_appWidget + i)->setAppName(QStringLiteral("敬请期待"));
			}		
			(m_appWidget + i)->setAppIcon(*img);
			(m_appWidget + i)->installEventFilter(this);    // 安装事件过滤器
		}

		m_qgdltLayout = new QGridLayout();		
		int cols(7), k(0);		
		int rows = 20 / cols == 0 ? 20 / cols : (20 / cols) + 1;
		for(int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (k >= 20) {
					break;
				}
				m_qgdltLayout->addWidget(&m_appWidget[k], i, j, 1, 1);
				k++;
			}
		}

		// 设置水平间距
		m_qgdltLayout->setHorizontalSpacing(10);
		// 设置垂直间距
		m_qgdltLayout->setVerticalSpacing(10);
		// 设置外间距
		m_qgdltLayout->setContentsMargins(10, 10, 10, 10);
		m_qvbltLayout = new QVBoxLayout();
		m_qvbltLayout->addLayout(m_qgdltLayout);
		m_qvbltLayout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Expanding));
		m_qscarScroll = new QScrollArea();
		m_qscarScroll->setAttribute(Qt::WA_TranslucentBackground);
		m_qscarScroll->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
		m_qscarScroll->setWidgetResizable(true);
		QWidget* widget = new QWidget(this);
		widget->setLayout(this->m_qvbltLayout);
		widget->setAttribute(Qt::WA_TranslucentBackground);
		this->m_qscarScroll->setWidget(widget);
		this->m_qscarScroll->setFrameShape(QFrame::NoFrame);
		this->m_qscarScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏横向滚动条
		this->m_qscarScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖向滚动条
		QVBoxLayout* mainLayout = new QVBoxLayout(this);
		mainLayout->addWidget(this->m_qscarScroll);
		ui.myapps_page->setLayout(mainLayout);
	#pragma endregion

}
#pragma endregion

#pragma region 事件绑定
void SmartTools::initConnections()
{
	connect(ui.pushButton_disassembly, SIGNAL(clicked()), this, SLOT(onPushButton_disassemblyClicked()));
	connect(ui.pushButton_selectdllfile, SIGNAL(clicked()), this, SLOT(onPushButton_selectdllfileClicked()));
	connect(ui.pushButton_changedlloutputpath, SIGNAL(clicked()), this, SLOT(onPushButton_changedlloutputpathClicked()));
}
#pragma endregion

#pragma region 主功能按钮点击事件
//反汇编
void SmartTools::onPushButton_disassemblyClicked() {
	typedef int(*EXECMEFUNC)(char* cmd, char* result);
	HINSTANCE hDllInst;
	hDllInst = LoadLibrary(L"./common/3676d55f84497cbeadfc614c1b1b62fc/commander.dll");
	if (NULL == hDllInst)
	{
		FreeLibrary(hDllInst);
		//cout << "LoadLibrary() error!" << endl;
	}
	EXECMEFUNC execmd_hide = (EXECMEFUNC)GetProcAddress(hDllInst, "execmd_hide");
	if (!execmd_hide)
	{
		//cout << "GetProcAddress() error!" << endl;
	}
	char result[1024 * 10] = "";                   //定义存放结果的字符串数组 
	QString filepath_JustDecompile=QCoreApplication::applicationDirPath();
	string filepath_endfix = "/plugins/6c595d99813d8c33abd181a4196f88ce/";
	string file_endfix = "JustDecompile.SmartCoder";
	string file_endfixNew = "JustDecompile.exe";
	string command_endfix = " /lang:csharp /vs:2017 /net4.5";
	string command_target = "/target:";
	string command_target_file = this->ui.dllfileselected_lineEdit->text().toStdString();
	string command_out = " /out:";
	string command_out_file = this->ui.lineEdit_dlloutputprojpath->text().toStdString();;
	vector<string> vec = { filepath_JustDecompile.toStdString(),filepath_endfix,file_endfixNew," ",command_target, command_target_file,command_out,command_out_file,command_endfix };
	vector<string> vec_corefilename = { filepath_JustDecompile.toStdString(),filepath_endfix,file_endfix };
	vector<string> vec_corefilenameNew = { filepath_JustDecompile.toStdString(),filepath_endfix,file_endfixNew };
	string corefilename;
	corefilename = accumulate(vec_corefilename.begin(), vec_corefilename.end(), corefilename);
	string corefilename_new;
	corefilename_new = accumulate(vec_corefilenameNew.begin(), vec_corefilenameNew.end(), corefilename_new);
	int rename_flag=rename(corefilename.c_str(), corefilename_new.c_str());
	string command;
	command = accumulate(vec.begin(), vec.end(), command);
	if (1 == execmd_hide(const_cast<char*>(command.c_str()), result)) {
		ui.textEdit_assemblyConsole->append(QString::fromLocal8Bit(result));
		this->ui.textEdit_assemblyConsole->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
	}
	FreeLibrary(hDllInst);
	int rename_flag_end = rename(corefilename_new.c_str(), corefilename.c_str());
}
//选择dll文件
void SmartTools::onPushButton_selectdllfileClicked() {
	QString fileName = QFileDialog::getOpenFileName(
		this, QStringLiteral("SmartTools-选择文件"), "C:\\", QStringLiteral("Image files(*.dll *.exe);All files (*.*)"));
	if (fileName.isEmpty())
	{
		QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("打开文件失败!"));
		return;
	}
	else
	{
		int nCount = fileName.count();
		for (int i = 0; i < nCount; i++)
		{
			QChar char1 = fileName.at(i);
			ushort uNum = char1.unicode();
			if (uNum >= 0x4E00 && uNum <= 0x9FA5)
			{
				QMessageBox::warning(this, QStringLiteral("警告"), fileName + "\n\"" + char1 + "\"\t" + QStringLiteral("文件路径不合法"));
				return;
			}
		}
		QFileInfo fileInfo(fileName);
		this->ui.dllfileselected_lineEdit->setText(fileName);
		this->ui.lineEdit_dlloutputprojpath->setText(fileInfo.path());
	}
}
//修改反汇编输出文件夹
void SmartTools::onPushButton_changedlloutputpathClicked() {
	QString file_path = QFileDialog::getExistingDirectory(this, QStringLiteral("请选择保存路径"), "c:\\");
	if (file_path.isEmpty())
	{
		QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("未选择任何路径!"));
		return;
	}
	else
	{
		int nCount = file_path.count();
		for (int i = 0; i < nCount; i++)
		{
			QChar char1 = file_path.at(i);
			ushort uNum = char1.unicode();
			if (uNum >= 0x4E00 && uNum <= 0x9FA5)
			{
				QMessageBox::warning(this, QStringLiteral("警告"), file_path + "\n\"" + char1 + "\"\t" + QStringLiteral("路径不合法"));
				return;
			}
		}
		this->ui.lineEdit_dlloutputprojpath->setText(file_path);
	}
	/*this->ui.console->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
	this->ui.console->insertPlainText(QStringLiteral("SmartPR>正在保存识别结果...\n"));*/
}
#pragma endregion

#pragma region 事件过滤器
bool SmartTools::eventFilter(QObject* obj, QEvent* event)
{
	if (obj == ui.main_label_widget)//指定某个QLabel
	{
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.main_page->setCurrentIndex(6);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.plugin_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.main_page->setCurrentIndex(1);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.disassem_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.main_page->setCurrentIndex(2);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.net_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.main_page->setCurrentIndex(3);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.mine_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.main_page->setCurrentIndex(4);
				return true;
			}
			else
			{
				return false;
			}
		}
		else 
		{
			return false;
		}
	}
	else if (obj == (m_appWidget+0))//指定某个QLabel
	{
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_page->setCurrentIndex(1);
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		// pass the event on to the parent class
		return QWidget::eventFilter(obj, event);
	}
}
#pragma endregion
