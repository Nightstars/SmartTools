#pragma once
#include <qwidget.h>
#include <QSize>
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor* editor) : QWidget(editor) {
        codeEditor = editor;
        setAttribute(Qt::WA_TranslucentBackground);
    }

    //返回合适的窗体大小
    QSize sizeHint() const override {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    //重写绘制函数，调用CodeEditor的方法
    void paintEvent(QPaintEvent* event) override {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor* codeEditor;
};