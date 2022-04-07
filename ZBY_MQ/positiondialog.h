#ifndef POSITIONDIALOG_H
#define POSITIONDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QDir>
#include <QDebug>

namespace Ui {
class PositionDialog;
}

class PositionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositionDialog(QWidget *parent = nullptr);
    ~PositionDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PositionDialog *ui;

    int
    Q1_X1,Q1_X2,
    Q2_X1,Q2_X2,
    H1_X1,H1_X2,
    H2_X1,H2_X2,
    P1_X1,P1_X2,
    P2_X1,P2_X2,
    J1_X1,J1_X2,
    J2_X1,J2_X2,
    J3_X1,J3_X2,
    J4_X1,J4_X2,
    J5_X1,J5_X2,
    J6_X1,J6_X2;

signals:
    ///
    /// \brief setWeightToSignal 写入重量数据到MQ
    /// \param x
    /// \param y
    /// \param w
    ///
    void updateModbusSignal(float x, float y ,float w);
};

#endif // POSITIONDIALOG_H
