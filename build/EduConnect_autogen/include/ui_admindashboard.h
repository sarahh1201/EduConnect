/********************************************************************************
** Form generated from reading UI file 'admindashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDASHBOARD_H
#define UI_ADMINDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admindashboard
{
public:
    QTextBrowser *textBrowser;
    QPushButton *logout_btn;
    QPushButton *refresh_btn;
    QTabWidget *tabWidget;
    QWidget *Sessions_Tab;
    QFrame *sessionframe;
    QVBoxLayout *verticalLayout_6;
    QTextBrowser *sessions;
    QWidget *Requests_Tab;
    QFrame *requestframe;
    QVBoxLayout *verticalLayout_7;
    QTextBrowser *requests;
    QWidget *Tutors_Tab;
    QFrame *tutorframe;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *tutors;
    QWidget *Students_Tab;
    QFrame *studentframe;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *students;

    void setupUi(QDialog *admindashboard)
    {
        if (admindashboard->objectName().isEmpty())
            admindashboard->setObjectName("admindashboard");
        admindashboard->resize(985, 700);
        admindashboard->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        textBrowser = new QTextBrowser(admindashboard);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 0, 251, 61));
        textBrowser->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        textBrowser->setFrameShape(QFrame::Shape::NoFrame);
        textBrowser->setLineWidth(0);
        logout_btn = new QPushButton(admindashboard);
        logout_btn->setObjectName("logout_btn");
        logout_btn->setGeometry(QRect(860, 10, 111, 41));
        logout_btn->setStyleSheet(QString::fromUtf8(""));
        refresh_btn = new QPushButton(admindashboard);
        refresh_btn->setObjectName("refresh_btn");
        refresh_btn->setGeometry(QRect(720, 10, 111, 41));
        tabWidget = new QTabWidget(admindashboard);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 70, 961, 621));
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        Sessions_Tab = new QWidget();
        Sessions_Tab->setObjectName("Sessions_Tab");
        Sessions_Tab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        sessionframe = new QFrame(Sessions_Tab);
        sessionframe->setObjectName("sessionframe");
        sessionframe->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_6 = new QVBoxLayout(sessionframe);
        verticalLayout_6->setObjectName("verticalLayout_6");
        sessions = new QTextBrowser(sessionframe);
        sessions->setObjectName("sessions");

        verticalLayout_6->addWidget(sessions);

        tabWidget->addTab(Sessions_Tab, QString());
        Requests_Tab = new QWidget();
        Requests_Tab->setObjectName("Requests_Tab");
        requestframe = new QFrame(Requests_Tab);
        requestframe->setObjectName("requestframe");
        requestframe->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_7 = new QVBoxLayout(requestframe);
        verticalLayout_7->setObjectName("verticalLayout_7");
        requests = new QTextBrowser(requestframe);
        requests->setObjectName("requests");

        verticalLayout_7->addWidget(requests);

        tabWidget->addTab(Requests_Tab, QString());
        Tutors_Tab = new QWidget();
        Tutors_Tab->setObjectName("Tutors_Tab");
        Tutors_Tab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        tutorframe = new QFrame(Tutors_Tab);
        tutorframe->setObjectName("tutorframe");
        tutorframe->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_4 = new QVBoxLayout(tutorframe);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tutors = new QTextBrowser(tutorframe);
        tutors->setObjectName("tutors");

        verticalLayout_4->addWidget(tutors);

        tabWidget->addTab(Tutors_Tab, QString());
        Students_Tab = new QWidget();
        Students_Tab->setObjectName("Students_Tab");
        Students_Tab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        studentframe = new QFrame(Students_Tab);
        studentframe->setObjectName("studentframe");
        studentframe->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_5 = new QVBoxLayout(studentframe);
        verticalLayout_5->setObjectName("verticalLayout_5");
        students = new QTextBrowser(studentframe);
        students->setObjectName("students");

        verticalLayout_5->addWidget(students);

        tabWidget->addTab(Students_Tab, QString());

        retranslateUi(admindashboard);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(admindashboard);
    } // setupUi

    void retranslateUi(QDialog *admindashboard)
    {
        admindashboard->setWindowTitle(QCoreApplication::translate("admindashboard", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("admindashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#354680;\">Hello ADMIN</span></p></body></html>", nullptr));
        logout_btn->setText(QCoreApplication::translate("admindashboard", "Logout", nullptr));
        refresh_btn->setText(QCoreApplication::translate("admindashboard", "Refresh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Sessions_Tab), QCoreApplication::translate("admindashboard", "Session History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Requests_Tab), QCoreApplication::translate("admindashboard", "Reuqests", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tutors_Tab), QCoreApplication::translate("admindashboard", "Tutors", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Students_Tab), QCoreApplication::translate("admindashboard", "Students", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admindashboard: public Ui_admindashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDASHBOARD_H
