#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void onOpenImage();
    void onSaveImage();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void setupWorkspace();

    // 共用的 QAction（同時給 Menu、ToolBar 與 Shortcut 使用）
    QAction *actionOpen = nullptr;
    QAction *actionSave = nullptr;
    QAction *actionExit = nullptr;
    QAction *actionPlaceholderEdit = nullptr;

    // 中央影像工作區與狀態列
    QLabel *workspaceLabel = nullptr;
};

#endif // MAINWINDOW_H