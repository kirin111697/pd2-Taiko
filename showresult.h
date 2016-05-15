#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>

namespace Ui {
class showResult;
}

class showResult : public QDialog
{
    Q_OBJECT

public:
    explicit showResult(QWidget *parent = 0);
    void result(int);
    ~showResult();

private:
    Ui::showResult *ui;
};

#endif // SHOWRESULT_H
