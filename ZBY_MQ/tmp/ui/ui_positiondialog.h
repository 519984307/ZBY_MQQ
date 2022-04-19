/********************************************************************************
** Form generated from reading UI file 'positiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONDIALOG_H
#define UI_POSITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PositionDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLineEdit *lineEdit_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QLineEdit *lineEdit_5;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_16;
    QLineEdit *lineEdit_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QLineEdit *lineEdit_8;
    QLabel *label_28;
    QLabel *label_29;
    QPushButton *pushButton;

    void setupUi(QDialog *PositionDialog)
    {
        if (PositionDialog->objectName().isEmpty())
            PositionDialog->setObjectName(QString::fromUtf8("PositionDialog"));
        PositionDialog->resize(1190, 560);
        PositionDialog->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8("ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        PositionDialog->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(PositionDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(PositionDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(50);
        label->setFont(font);
        label->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);
        comboBox_3->setFont(font);

        horizontalLayout->addWidget(comboBox_3);

        comboBox_4 = new QComboBox(groupBox);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(false);
        comboBox_4->setFont(font);

        horizontalLayout->addWidget(comboBox_4);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setFont(font);
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"color: rgb(255, 255, 0);"));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_3);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        gridLayout_2->addWidget(checkBox, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setWordWrap(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setFont(font);
        spinBox->setMinimum(1);
        spinBox->setMaximum(116);

        horizontalLayout_2->addWidget(spinBox);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);
        comboBox_2->setFont(font);

        horizontalLayout_2->addWidget(comboBox_2);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setFont(font);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"color: rgb(255, 255, 0);"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setClearButtonEnabled(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_2);


        gridLayout_2->addLayout(formLayout_2, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font);
        checkBox_2->setChecked(false);

        gridLayout_2->addWidget(checkBox_2, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setWordWrap(false);

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"color: rgb(255, 255, 0);"));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setClearButtonEnabled(true);

        horizontalLayout_3->addWidget(lineEdit);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font);
        checkBox_3->setIconSize(QSize(15, 15));
        checkBox_3->setChecked(false);
        checkBox_3->setTristate(false);

        gridLayout_2->addWidget(checkBox_3, 2, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setPointSize(20);
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        horizontalLayout_4->addWidget(label_13);

        lineEdit_6 = new QLineEdit(groupBox_4);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font1);

        horizontalLayout_4->addWidget(lineEdit_6);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        horizontalLayout_5->addWidget(label_14);

        lineEdit_5 = new QLineEdit(groupBox_4);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setFont(font1);

        horizontalLayout_5->addWidget(lineEdit_5);


        gridLayout->addLayout(horizontalLayout_5, 1, 1, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);

        gridLayout->addWidget(label_15, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);

        horizontalLayout_6->addWidget(label_16);

        lineEdit_7 = new QLineEdit(groupBox_4);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setFont(font1);

        horizontalLayout_6->addWidget(lineEdit_7);


        gridLayout->addLayout(horizontalLayout_6, 2, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font1);

        horizontalLayout_7->addWidget(label_17);

        lineEdit_8 = new QLineEdit(groupBox_4);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setFont(font1);

        horizontalLayout_7->addWidget(lineEdit_8);


        gridLayout->addLayout(horizontalLayout_7, 3, 1, 1, 1);

        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        QFont font2;
        font2.setPointSize(15);
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_28->setFrameShape(QFrame::WinPanel);
        label_28->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_28, 1, 0, 1, 1);

        label_29 = new QLabel(groupBox_4);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        label_29->setFrameShape(QFrame::WinPanel);
        label_29->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(label_29, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 0, 2, 3, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        pushButton = new QPushButton(PositionDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(PositionDialog);
        QObject::connect(checkBox, SIGNAL(clicked(bool)), comboBox_3, SLOT(setEnabled(bool)));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), comboBox_4, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), spinBox, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), comboBox_2, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_3, SIGNAL(clicked(bool)), lineEdit, SLOT(setEnabled(bool)));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), lineEdit_2, SLOT(setEnabled(bool)));
        QObject::connect(checkBox, SIGNAL(clicked(bool)), lineEdit_3, SLOT(setEnabled(bool)));

        comboBox_4->setCurrentIndex(2);
        comboBox_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(PositionDialog);
    } // setupUi

    void retranslateUi(QDialog *PositionDialog)
    {
        PositionDialog->setWindowTitle(QApplication::translate("PositionDialog", "Position", nullptr));
        groupBox->setTitle(QApplication::translate("PositionDialog", "Position setting", nullptr));
        label->setText(QApplication::translate("PositionDialog", "\345\260\217\350\275\246", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("PositionDialog", "H2", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("PositionDialog", "H1", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("PositionDialog", "Q1", nullptr));
        comboBox_3->setItemText(3, QApplication::translate("PositionDialog", "Q2", nullptr));
        comboBox_3->setItemText(4, QApplication::translate("PositionDialog", "P1", nullptr));
        comboBox_3->setItemText(5, QApplication::translate("PositionDialog", "P2", nullptr));
        comboBox_3->setItemText(6, QApplication::translate("PositionDialog", "J6", nullptr));
        comboBox_3->setItemText(7, QApplication::translate("PositionDialog", "J5", nullptr));
        comboBox_3->setItemText(8, QApplication::translate("PositionDialog", "J4", nullptr));
        comboBox_3->setItemText(9, QApplication::translate("PositionDialog", "J3", nullptr));
        comboBox_3->setItemText(10, QApplication::translate("PositionDialog", "J2", nullptr));
        comboBox_3->setItemText(11, QApplication::translate("PositionDialog", "J1", nullptr));

        comboBox_4->setItemText(0, QApplication::translate("PositionDialog", "1/6", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("PositionDialog", "2/6", nullptr));
        comboBox_4->setItemText(2, QApplication::translate("PositionDialog", "3/6", nullptr));
        comboBox_4->setItemText(3, QApplication::translate("PositionDialog", "4/6", nullptr));
        comboBox_4->setItemText(4, QApplication::translate("PositionDialog", "5/6", nullptr));

        lineEdit_3->setPlaceholderText(QApplication::translate("PositionDialog", "\345\215\225\344\275\215\357\274\232\347\261\263", nullptr));
        checkBox->setText(QApplication::translate("PositionDialog", "\350\256\276\345\256\232", nullptr));
        label_2->setText(QApplication::translate("PositionDialog", "\345\244\247\350\275\246", nullptr));
        spinBox->setSuffix(QApplication::translate("PositionDialog", "\344\275\215", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("PositionDialog", "1/6", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("PositionDialog", "2/6", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("PositionDialog", "3/6", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("PositionDialog", "4/6", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("PositionDialog", "5/6", nullptr));

        lineEdit_2->setPlaceholderText(QApplication::translate("PositionDialog", "\345\215\225\344\275\215\357\274\232\347\261\263", nullptr));
        checkBox_2->setText(QApplication::translate("PositionDialog", "\350\256\276\345\256\232", nullptr));
        label_3->setText(QApplication::translate("PositionDialog", "\345\220\212\345\205\267", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("PositionDialog", "\345\215\225\344\275\215\357\274\232\347\261\263", nullptr));
        checkBox_3->setText(QApplication::translate("PositionDialog", "\350\256\276\345\256\232", nullptr));
        groupBox_4->setTitle(QApplication::translate("PositionDialog", "\345\244\215\344\275\215\345\231\250", nullptr));
        label_5->setText(QApplication::translate("PositionDialog", "\345\244\247\350\275\246\357\274\232", nullptr));
        label_13->setText(QApplication::translate("PositionDialog", "\347\212\266\346\200\201", nullptr));
        label_14->setText(QApplication::translate("PositionDialog", "\346\254\241\346\225\260", nullptr));
        label_15->setText(QApplication::translate("PositionDialog", "\345\260\217\350\275\246\357\274\232", nullptr));
        label_16->setText(QApplication::translate("PositionDialog", "\347\212\266\346\200\201", nullptr));
        label_17->setText(QApplication::translate("PositionDialog", "\346\254\241\346\225\260", nullptr));
        label_28->setText(QApplication::translate("PositionDialog", "Status", nullptr));
        label_29->setText(QApplication::translate("PositionDialog", "Status", nullptr));
        pushButton->setText(QApplication::translate("PositionDialog", "\345\244\215\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PositionDialog: public Ui_PositionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONDIALOG_H
