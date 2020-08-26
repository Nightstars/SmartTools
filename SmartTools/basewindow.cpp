#include "basewindow.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <QFile>

BaseWindow::BaseWindow(QWidget* parent)
    : QWidget(parent)
{
    // FramelessWindowHint�������ô���ȥ���߿�;
    // WindowMinimizeButtonHint ���������ڴ�����С��ʱ��������������ڿ�����ʾ��ԭ����;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    // ���ô��ڱ���͸��;
   // setAttribute(Qt::WA_TranslucentBackground);
    // ע�⣡��������������ڲ�Ҫ����WA_DeleteOnClose����;
    // �رմ���ʱ�ͷ���Դ;
    setAttribute(Qt::WA_DeleteOnClose);
    // ��ʼ��������;
    initTitleBar();
}

BaseWindow::~BaseWindow()
{

}

void BaseWindow::initTitleBar()
{
    m_titleBar = new MyTitleBar(this);
    m_titleBar->move(0, 0);

    connect(m_titleBar, SIGNAL(signalButtonMinClicked()), this, SLOT(onButtonMinClicked()));
    connect(m_titleBar, SIGNAL(signalButtonRestoreClicked()), this, SLOT(onButtonRestoreClicked()));
    connect(m_titleBar, SIGNAL(signalButtonMaxClicked()), this, SLOT(onButtonMaxClicked()));
    connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

//void BaseWindow::paintEvent(QPaintEvent* event)
//{
//    //���ñ���ɫ;
//    QPainter painter(this);
//    QPainterPath pathBack;
//    pathBack.setFillRule(Qt::WindingFill);
//    pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
//    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
//    painter.fillPath(pathBack, QBrush(QColor(238, 223, 204)));
//
//    return QWidget::paintEvent(event);
//}

void BaseWindow::loadStyleSheet(const QString& sheetName)
{
    QFile file(":/Resources/" + sheetName + ".css");
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
    }
}

void BaseWindow::onButtonMinClicked()
{
    showMinimized();
}

void BaseWindow::onButtonRestoreClicked()
{
    QPoint windowPos;
    QSize windowSize;
    m_titleBar->getRestoreInfo(windowPos, windowSize);
    this->setGeometry(QRect(windowPos, windowSize));
    #pragma region ���ô��屳��
    this->setAutoFillBackground(true); // ���Ҫ����, ���������ʾ��������ͼ.
    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(),
        QBrush(QPixmap(":/skins/Resources/skins/skins11.png").scaled(// ���ű���ͼ.
            this->size(),
            Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation)));             // ʹ��ƽ�������ŷ�ʽ
    this->setPalette(palette);
    #pragma endregion
}

void BaseWindow::onButtonMaxClicked()
{
    m_titleBar->saveRestoreInfo(this->pos(), QSize(this->width(), this->height()));
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QRect FactRect = QRect(desktopRect.x() - 3, desktopRect.y() - 3, desktopRect.width() + 6, desktopRect.height() + 6);
    setGeometry(FactRect);
    #pragma region ���ô��屳��
    this->setAutoFillBackground(true); // ���Ҫ����, ���������ʾ��������ͼ.
    QPalette palette = this->palette();
    palette.setBrush(backgroundRole(),
        QBrush(QPixmap(":/skins/Resources/skins/skins11.png").scaled(// ���ű���ͼ.
            this->size(),
            Qt::IgnoreAspectRatio,
            Qt::FastTransformation)));             // ʹ��ƽ�������ŷ�ʽ
    this->setPalette(palette);
    #pragma endregion
}

void BaseWindow::onButtonCloseClicked()
{
    close();
}