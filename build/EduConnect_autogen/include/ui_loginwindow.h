/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginwindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *usr_in;
    QLineEdit *pswd_in;
    QPushButton *login_btn;

    void setupUi(QMainWindow *loginwindow)
    {
        if (loginwindow->objectName().isEmpty())
            loginwindow->setObjectName("loginwindow");
        loginwindow->resize(1296, 828);
        loginwindow->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QWidget{background-color: rgb(218, 241, 255)}\n"
"QTextBrowser{background-color: rgb(218, 241, 255)}\n"
"QLineEdit{background-color: white}\n"
"QMainWindow{height: 700px; width: 700px;}\n"
"\n"
""));
        centralwidget = new QWidget(loginwindow);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(70, 20, 1141, 741));
        textBrowser->setMaximumSize(QSize(1161, 761));
        textBrowser->setStyleSheet(QString::fromUtf8(""));
        textBrowser->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser->setFrameShadow(QFrame::Shadow::Plain);
        textBrowser->setLineWidth(0);
        textBrowser->setCursorWidth(0);
        verticalGroupBox = new QGroupBox(centralwidget);
        verticalGroupBox->setObjectName("verticalGroupBox");
        verticalGroupBox->setGeometry(QRect(520, 320, 221, 121));
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setObjectName("verticalLayout");
        usr_in = new QLineEdit(verticalGroupBox);
        usr_in->setObjectName("usr_in");

        verticalLayout->addWidget(usr_in);

        pswd_in = new QLineEdit(verticalGroupBox);
        pswd_in->setObjectName("pswd_in");

        verticalLayout->addWidget(pswd_in);

        login_btn = new QPushButton(verticalGroupBox);
        login_btn->setObjectName("login_btn");

        verticalLayout->addWidget(login_btn);

        loginwindow->setCentralWidget(centralwidget);

        retranslateUi(loginwindow);

        QMetaObject::connectSlotsByName(loginwindow);
    } // setupUi

    void retranslateUi(QMainWindow *loginwindow)
    {
        loginwindow->setWindowTitle(QCoreApplication::translate("loginwindow", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("loginwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:64pt; font-weight:700; color:#2a48aa;\">Welcome to EduConnect!</span><br /></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /><span style=\" font-size:144pt;\">\360\237\220\237</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px;"
                        " margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; font-weight:700; vertical-align:super;\">EduConnect was Planned &amp; Developped by:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; "
                        "-qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; vertical-align:super;\">Ivailo Stoychev </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; vertical-align:super;\">Nicholas Merritt </span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt; vertical-align:super;\">Sarah Hill </span><span style=\" font-size:24pt;\"><br /></span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">If you are having issues please contact educonnect@support.com </span></p></body></html>", nullptr));
        usr_in->setPlaceholderText(QCoreApplication::translate("loginwindow", "Username", nullptr));
        pswd_in->setPlaceholderText(QCoreApplication::translate("loginwindow", "Password", nullptr));
        login_btn->setText(QCoreApplication::translate("loginwindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginwindow: public Ui_loginwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
