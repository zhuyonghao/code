#include "widget.h"
// 绘图需要使用的类
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap> // 保存图片
#include <QCursor> // 光标类
#include <QMetaEnum> // 枚举


// 构造函数更新
Widget::Widget(QWidget *parent)
    : QWidget(parent),
    timer(new QTimer(this)), //这样做可以确保当 Widget 对象被销毁时，timer 对象也会被自动销毁，避免内存泄漏
    menu(new QMenu(this)) // 创建菜单对象
{
    this->setWindowFlag(Qt::FramelessWindowHint); // 取出窗口边框
    this->setAttribute(Qt::WA_TranslucentBackground); // 背景透明

    this->installEventFilter(new DragFilter);

    connect(timer, &QTimer::timeout,[this](){
        static int index = 0; // 记录显示动作的当前图片索引
        auto paths = this->action_map.value(this->cur_role_act);
        this->cur_role_pix = paths[index++ % paths.size()]; // 防止图片范围越界
        this->update(); // 重新绘制
    });

    initMenu(); // 调用函数初始化

    loadRoleActRes(); // 加载资源更新对象

    showActAnimation(RoleAct::Dance1);
}

Widget::~Widget() {}

// 播放动画
void Widget::showActAnimation(RoleAct k)
{
    timer->stop(); // 定时器关闭

    this->cur_role_act = k; // 状态更新

    timer->start(150); //定时器打开
}

void Widget::onMenuTriggered(QAction *action)
{
    QMetaEnum me = QMetaEnum::fromType<RoleAct>();

    bool ok;
    int k = me.keyToValue(action->text().toStdString().c_str(), &ok);

    if (!ok)
        return;

    showActAnimation(static_cast<RoleAct>(k));
}

// 添加定义实现功能
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(this->cur_role_pix.toLocalFile());

    // 按比例缩小图片到原始尺寸的25%
    QSize targetSize = pix.size() * 0.25; // 缩小到原始尺寸的25%
    QPixmap scaledPix = pix.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 居中绘制缩小后的图片
    int x = (this->width() - scaledPix.width()) / 2;
    int y = (this->height() - scaledPix.height()) / 2;

    painter.drawPixmap(x, y, scaledPix);
}


void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    this->menu->popup(QCursor::pos());
}

void Widget::loadRoleActRes()
{
    // lambda表达式[捕获列表](参数列表)
    auto addRes = [this](RoleAct k, QString path, int count)
    {
        QList<QUrl> paths; //将路径中的值存放在列表中
        char buf[260]; // 路径
        for (int i = 0; i < count; ++i)
        {
            memset(buf, 0, sizeof(buf));
            sprintf_s(buf, path.toStdString().c_str(), i);
            paths.append(QUrl::fromLocalFile(buf));
        }
        action_map.insert(k, paths);
    };

    addRes(RoleAct::Dance1, ":/dance1/img/dance1/%d.png", 19);
    addRes(RoleAct::Dance2, ":/dance2/img/dance2/%d.png", 5);
    addRes(RoleAct::Dance3, ":/dance3/img/dance3/%d.png", 8);
}

void Widget::initMenu()
{
    menu->addAction("Dance1");
    menu->addAction("Dance2");
    menu->addAction("Dance3");

    QAction* act = new QAction("Hide"); // 隐藏

    connect(act, &QAction::triggered, [this]()
            {
        this->setVisible(false);
    });// 绑定信号与槽

    menu->addAction(act);

    connect(this->menu, &QMenu::triggered, this, &Widget::onMenuTriggered);
}
