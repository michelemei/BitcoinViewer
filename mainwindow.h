#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

namespace Ui {
class MainWindow;
}

class BitcoinWatcher;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ctrlButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    std::unique_ptr<BitcoinWatcher> worker; //!< Bitcoin working thread

    //! manage working thread and update items status
    void manageWorker();
};

#endif // MAINWINDOW_H
