#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMap>  // 对文件和动作映射
#include <QList> // 存放动作的文件
#include <QUrl>  // 链接文件
#include <QTimer> // 定时器
#include <QEvent>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>

// QPaintEvent声明
class QPaintEvent;

namespace Act {
    Q_NAMESPACE // 将整个命名空间暴露给 Qt 的元对象系统

enum RoleAct{
    Dance1,
    Dance2,
    Dance3
}; // 定义了一组命名常量
Q_ENUM_NS(RoleAct) // 将枚举类型 RoleAct 注册到 Qt 的元对象系统中
}

using namespace Act; // 使用命名空间

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void showActAnimation(RoleAct k);

public slots:
    void onMenuTriggered(QAction* action);

protected:
    void paintEvent(QPaintEvent* event) override; // 用来实现绘制事件的虚函数
    void contextMenuEvent(QContextMenuEvent* event);

private:
    void loadRoleActRes(); // 加载任务动作资源到map容器中
    void initMenu();

private:
    QMap<RoleAct, QList<QUrl>> action_map; // 对动作映射
    QTimer* timer; // 用来控制播放间断
    RoleAct cur_role_act; // 当前角色动作
    QUrl cur_role_pix; // 当前使用的图片
    QMenu* menu; // 创建菜单
};

class DragFilter : public QObject
{
public:
    bool eventFilter(QObject* obj, QEvent* event)
    {
        auto w = dynamic_cast<QWidget*>(obj);
        if (!w)
            return false;

        if (event->type() == QEvent::MouseButtonPress)
        {
            auto e = dynamic_cast<QMouseEvent*>(event);
            if (e)
            {
                pos = e->pos();
            }
        }
        else if (event->type() == QEvent::MouseMove)
        {
            auto e = dynamic_cast<QMouseEvent*>(event);
            if (e)
            {
                if (e->buttons() & Qt::MouseButton::LeftButton)
                {
                    w->move(e->globalPosition().toPoint() - pos);
                }
            }
        }
        return QObject::eventFilter(obj, event);
    }

private:
    QPoint pos;
};

#endif // WIDGET_H
