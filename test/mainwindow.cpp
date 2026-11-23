#include "mainwindow.h"

#include <QAction>
#include <QKeySequence>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QStyle>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Image Studio - V1");
    resize(800, 600);

    createActions();
    createMenus();
    createToolBars();
    setupWorkspace();

    statusBar()->showMessage("Ready | 0 x 0 px");
}

void MainWindow::createActions()
{
    // Open Action：設定圖示、快捷鍵與 slot
    actionOpen = new QAction(style()->standardIcon(QStyle::SP_DialogOpenButton), "Open Image", this);
    actionOpen->setShortcut(QKeySequence::Open); // Ctrl+O
    actionOpen->setStatusTip("開啟本機影像檔案");
    connect(actionOpen, &QAction::triggered, this, &MainWindow::onOpenImage);

    // Save Action：設定圖示、快捷鍵 (Ctrl+S) 與 slot
    actionSave = new QAction(style()->standardIcon(QStyle::SP_DialogSaveButton), "Save", this);
    actionSave->setShortcut(QKeySequence::Save); // Ctrl+S
    actionSave->setStatusTip("儲存目前影像");
    connect(actionSave, &QAction::triggered, this, &MainWindow::onSaveImage);

    // Exit Action：關閉主視窗
    actionExit = new QAction(style()->standardIcon(QStyle::SP_DialogCloseButton), "Exit", this);
    actionExit->setShortcut(QKeySequence::Quit); // Ctrl+Q
    actionExit->setStatusTip("結束應用程式");
    connect(actionExit, &QAction::triggered, this, &QMainWindow::close);

    // Image / Edit 選單的預留項目（第一版先停用，留給後續版本）
    actionPlaceholderEdit = new QAction("Rotate / Filter (V2 預留)", this);
    actionPlaceholderEdit->setEnabled(false);
}

void MainWindow::createMenus()
{
    // File 選單
    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addSeparator();
    fileMenu->addAction(actionExit);

    // Edit 選單
    QMenu *editMenu = menuBar()->addMenu("&Edit");
    QAction *actionUndo = new QAction("Undo (V2 預留)", this);
    actionUndo->setEnabled(false);
    editMenu->addAction(actionUndo);

    // Image 選單
    QMenu *imageMenu = menuBar()->addMenu("&Image");
    imageMenu->addAction(actionPlaceholderEdit);
}

void MainWindow::createToolBars()
{
    // ToolBar 直接掛載同一個 actionOpen 與 actionSave，不重複建立
    QToolBar *mainToolBar = addToolBar("Main ToolBar");
    mainToolBar->setMovable(false);
    mainToolBar->addAction(actionOpen);
    mainToolBar->addAction(actionSave);
}

void MainWindow::setupWorkspace()
{
    // centralWidget 作為未來影像工作區，隨視窗縮放自動調整大小
    workspaceLabel = new QLabel("IMAGE WORKSPACE", this);
    workspaceLabel->setAlignment(Qt::AlignCenter);
    workspaceLabel->setStyleSheet(
        "QLabel {"
        "  background-color: #222624;"
        "  color: #9aa59f;"
        "  font-size: 24px;"
        "  font-weight: bold;"
        "}"
        );
    setCentralWidget(workspaceLabel);
}

void MainWindow::onOpenImage()
{
    statusBar()->showMessage("觸發 Open 功能（由 Menu / ToolBar / Ctrl+O 共用）", 3000);
    QMessageBox::information(this, "Open Image", "已進入 onOpenImage() 處理流程！");
}

void MainWindow::onSaveImage()
{
    statusBar()->showMessage("觸發 Save 功能（由 Menu / ToolBar / Ctrl+S 共用）", 3000);
    QMessageBox::information(this, "Save Image", "已進入 onSaveImage() 處理流程！");
}