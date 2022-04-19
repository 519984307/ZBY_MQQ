/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QCheckBox *checkBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QSpinBox *spinBox_4;
    QLabel *label_13;
    QLabel *label_5;
    QSpinBox *spinBox_5;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_3;
    QLabel *label_12;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label_14;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QLabel *label_10;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_3;
    QLabel *label_17;
    QLabel *label_15;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1113, 586);
        QIcon icon;
        icon.addFile(QString::fromUtf8("ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label->setFrameShape(QFrame::WinPanel);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(50, 0));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label_8->setScaledContents(true);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_8, 0, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label_3->setFrameShape(QFrame::WinPanel);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        label_3->setOpenExternalLinks(false);

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(50, 0));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label_9->setFrameShape(QFrame::WinPanel);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_9, 1, 0, 1, 2);

        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);"));
        label_16->setFrameShape(QFrame::WinPanel);
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_16, 1, 2, 1, 2);


        gridLayout_4->addLayout(gridLayout_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(62, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 35));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        pushButton->setCheckable(false);
        pushButton->setAutoRepeat(false);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(pushButton_3);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setIconSize(QSize(0, 16));
        checkBox->setChecked(true);

        verticalLayout->addWidget(checkBox);


        gridLayout_4->addLayout(verticalLayout, 1, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 6, 1, 1);

        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(12);
        spinBox_4->setFont(font);
        spinBox_4->setAlignment(Qt::AlignCenter);
        spinBox_4->setReadOnly(true);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_4->setMinimum(-10000);
        spinBox_4->setMaximum(1000000);

        gridLayout->addWidget(spinBox_4, 0, 7, 1, 1);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        spinBox_5 = new QSpinBox(centralwidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimumSize(QSize(0, 0));
        spinBox_5->setAlignment(Qt::AlignCenter);
        spinBox_5->setReadOnly(true);
        spinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_5->setMinimum(-1000000);
        spinBox_5->setMaximum(1000000);

        gridLayout->addWidget(spinBox_5, 1, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 4, 1, 1);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimumSize(QSize(0, 0));
        spinBox_2->setFont(font);
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setReadOnly(true);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_2->setMinimum(-100000);
        spinBox_2->setMaximum(1000000);
        spinBox_2->setValue(0);

        gridLayout->addWidget(spinBox_2, 0, 3, 1, 1);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_3, 2, 5, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 1, 4, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 7, 2, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 0));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 2, 1, 1, 1);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_14, 2, 2, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_2, 2, 3, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 1, 2, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        spinBox_6 = new QSpinBox(centralwidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMinimumSize(QSize(0, 0));
        spinBox_6->setAlignment(Qt::AlignCenter);
        spinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_6->setMinimum(-1000000);
        spinBox_6->setMaximum(1000000);

        gridLayout->addWidget(spinBox_6, 1, 3, 1, 1);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimumSize(QSize(0, 0));
        spinBox->setBaseSize(QSize(0, 0));
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setReadOnly(true);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMaximum(100000);
        spinBox->setValue(0);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        spinBox_7 = new QSpinBox(centralwidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setMinimumSize(QSize(0, 0));
        spinBox_7->setAlignment(Qt::AlignCenter);
        spinBox_7->setReadOnly(true);
        spinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_7->setMinimum(-1000000);
        spinBox_7->setMaximum(1000000);

        gridLayout->addWidget(spinBox_7, 1, 5, 1, 1);

        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMinimumSize(QSize(0, 0));
        spinBox_3->setFont(font);
        spinBox_3->setAlignment(Qt::AlignCenter);
        spinBox_3->setReadOnly(true);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_3->setMinimum(-10000);
        spinBox_3->setMaximum(1000000);

        gridLayout->addWidget(spinBox_3, 0, 5, 1, 1);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 1, 6, 2, 1);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);color: rgb(0, 85, 0);"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 2, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout_3->addWidget(plainTextEdit, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ZBY_MQ", nullptr));
        label->setText(QApplication::translate("MainWindow", "TCP", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "MQ", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "COM+", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Action", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "ModbusMster", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "ModbusSlave", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "Log", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\351\207\215\351\207\217\357\274\232", nullptr));
        spinBox_4->setSuffix(QApplication::translate("MainWindow", "(kg)", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\345\220\212\345\205\267\346\250\241\345\274\217\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "X\350\275\264\345\201\217\350\275\275\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Y\350\275\264\345\201\217\345\277\203\357\274\232", nullptr));
        spinBox_2->setSuffix(QApplication::translate("MainWindow", "(kg)", nullptr));
        spinBox_2->setPrefix(QString());
        label_12->setText(QApplication::translate("MainWindow", "\345\220\212\345\205\267\351\253\230\345\272\246\357\274\232", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\345\274\200\351\227\255\351\224\201\357\274\232", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\345\244\247\350\275\246\344\275\215\347\275\256\357\274\232", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\345\260\217\350\275\246\344\275\215\347\275\256\357\274\232", nullptr));
        spinBox->setSuffix(QApplication::translate("MainWindow", "(pcs)", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\211\271\346\254\241\357\274\232", nullptr));
        spinBox_3->setSuffix(QApplication::translate("MainWindow", "(mm)", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "\347\235\200\347\256\261\357\274\232", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
