#include "positiondialog.h"
#include "ui_positiondialog.h"

PositionDialog::PositionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionDialog)
{
    ui->setupUi(this);

    ui->groupBox_4->setHidden(true);

    QSettings set(QDir::toNativeSeparators("Sys.ini"),QSettings::IniFormat);
    set.setIniCodec("UTF-8");

    set.beginGroup("Position");

    H2_X2 = set.value("H2_X2",-1229).toInt();
    H2_X1 = set.value("H2_X1",-829).toInt();
    H1_X2 = set.value("H1_X2",-828).toInt();
    H1_X1 = set.value("H1_X1",-428).toInt();

    Q1_X1 = set.value("Q1_X1",-60).toInt();
    Q1_X2 = set.value("Q1_X2",389).toInt();
    Q2_X1 = set.value("Q2_X1",390).toInt();
    Q2_X2 = set.value("Q2_X2",838).toInt();

    P1_X1 = set.value("P1_X1",839).toInt();
    P1_X2 = set.value("P1_X2",1350).toInt();
    P2_X1 = set.value("P2_X1",1351).toInt();
    P2_X2 = set.value("P2_X2",1973).toInt();

    J6_X1 = set.value("J6_X1",1974).toInt();
    J6_X2 = set.value("J6_X2",2398).toInt();
    J5_X1 = set.value("J5_X1",2399).toInt();
    J5_X2 = set.value("J5_X2",2674).toInt();
    J4_X1 = set.value("J4_X1",2675).toInt();
    J4_X2 = set.value("J4_X2",3034).toInt();
    J3_X1 = set.value("J3_X1",3035).toInt();
    J3_X2 = set.value("J3_X2",3424).toInt();
    J2_X1 = set.value("J2_X1",3425).toInt();
    J2_X2 = set.value("J2_X2",3733).toInt();
    J1_X1 = set.value("J1_X1",3734).toInt();
    J1_X2 = set.value("J1_X2",4123).toInt();

    set.endGroup();

    set.beginGroup("Position");
    set.setValue("H2_X2",H2_X2);
    set.setValue("H2_X1",H2_X1);
    set.setValue("H1_X2",H1_X2);
    set.setValue("H1_X1",H1_X1);

    set.setValue("Q1_X1",Q1_X1);
    set.setValue("Q1_X2",Q1_X2);
    set.setValue("Q2_X1",Q2_X1);
    set.setValue("Q2_X2",Q2_X2);

    set.setValue("P1_X1",P1_X1);
    set.setValue("P1_X2",P1_X2);
    set.setValue("P2_X1",P2_X1);
    set.setValue("P2_X2",P2_X2);

    set.setValue("J6_X1",J6_X1);
    set.setValue("J6_X2",J6_X2);
    set.setValue("J5_X1",J5_X1);
    set.setValue("J5_X2",J5_X2);
    set.setValue("J4_X1",J4_X1);
    set.setValue("J4_X2",J4_X2);
    set.setValue("J3_X1",J3_X1);
    set.setValue("J3_X2",J3_X2);
    set.setValue("J2_X1",J2_X1);
    set.setValue("J2_X2",J2_X2);
    set.setValue("J1_X1",J1_X1);
    set.setValue("J1_X2",J1_X2);
    set.endGroup();
}

PositionDialog::~PositionDialog()
{
    delete ui;
}

void PositionDialog::on_pushButton_clicked()
{
    float x=0,y=0,z=0;
    float tmpX=0,tmpY=0;

    if(ui->lineEdit_3->text().isEmpty()){
        switch (ui->comboBox_3->currentIndex()) {
        case 0:
            tmpX=H2_X2-H2_X1;
            break;
        case 1:
            tmpX=H1_X2-H1_X1;
            break;
        case 2:
            tmpX=Q1_X2-Q1_X1;
            break;
        case 3:
            tmpX=Q2_X2-Q2_X1;
            break;
        case 4:
            tmpX=P1_X2-P1_X1;
            break;
        case 5:
            tmpX=P2_X2-P2_X1;
            break;
        case 6:
            tmpX=J6_X2-J6_X1;
            break;
        case 7:
            tmpX=J5_X2-J5_X1;
            break;
        case 8:
            tmpX=J4_X2-J4_X1;
            break;
        case 9:
            tmpX=J3_X2-J3_X1;
            break;
        case 10:
            tmpX=J2_X2-J2_X1;
            break;
        case 11:
            tmpX=J1_X2-J1_X1;
            break;
        }

        switch (ui->comboBox_4->currentIndex()) {
        case 0:
            tmpX=tmpX*(1.0/6.0);
            break;
        case 1:
            tmpX=tmpX*(2.0/6.0);
            break;
        case 2:
            tmpX=tmpX*(3.0/6.0);
            break;
        case 3:
            tmpX=tmpX*(4.0/6.0);
            break;
        case 4:
            tmpX=tmpX*(5.0/6.0);
            break;
        }

        switch (ui->comboBox_3->currentIndex()) {
        case 0:
            x=(tmpX+H2_X1)/100.0;
            break;
        case 1:
            x=(tmpX+H1_X1)/100.0;
            break;
        case 2:
            x=(tmpX+Q1_X1)/100.0;
            break;
        case 3:
            x=(tmpX+Q2_X1)/100.0;
            break;
        case 4:
            x=(tmpX+P1_X1)/100.0;
            break;
        case 5:
            x=(tmpX+P2_X1)/100.0;
            break;
        case 6:
            x=(tmpX+J6_X1)/100.0;
            break;
        case 7:
            x=(tmpX+J5_X1)/100.0;
            break;
        case 8:
            x=(tmpX+J4_X1)/100.0;
            break;
        case 9:
            x=(tmpX+J3_X1)/100.0;
            break;
        case 10:
            x=(tmpX+J2_X1)/100.0;
            break;
        case 11:
            x=(tmpX+J1_X1)/100.0;
            break;
        }
    }
    else {
        x=ui->lineEdit_3->text().toFloat();
    }

    if(ui->lineEdit_2->text().isEmpty()){
        tmpY=6.625*(ui->spinBox->value()-1);
        switch (ui->comboBox_2->currentIndex()) {
        case 0:
            y=tmpY+6.625*(1.0/6.0);
            break;
        case 1:
            y=tmpY+6.625*(2.0/6.0);
            break;
        case 2:
            y=tmpY+6.625*(3.0/6.0);
            break;
        case 3:
            y=tmpY+6.625*(4.0/6.0);
            break;
        case 4:
            y=tmpY+6.625*(5.0/6.0);
            break;
        }
    }
    else {
        y=ui->lineEdit_2->text().toFloat();
    }

    z=ui->lineEdit->text().toFloat();

    if(ui->checkBox->checkState()==Qt::Unchecked){
        x=-1;
    }
    if(ui->checkBox_2->checkState()==Qt::Unchecked){
        y=-1;
    }
    if(ui->checkBox_3->checkState()==Qt::Unchecked){
        z=-1;
    }
    emit updateModbusSignal(z,x,y);
}
