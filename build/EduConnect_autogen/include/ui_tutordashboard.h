/********************************************************************************
** Form generated from reading UI file 'tutordashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORDASHBOARD_H
#define UI_TUTORDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tutordashboard
{
public:
    QTextBrowser *top;
    QPushButton *logout_btn;
    QTabWidget *tabWidget;
    QWidget *RequestTab;
    QFrame *request;
    QVBoxLayout *verticalLayout;
    QTextBrowser *request_out;
    QGroupBox *request_input;
    QHBoxLayout *horizontalLayout;
    QLineEdit *req_in;
    QPushButton *acceptreq_btn;
    QWidget *RatingsTab;
    QGroupBox *Ratings;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *ratings_out;
    QWidget *SessionsTab;
    QFrame *sessions;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *sessions_out;
    QGroupBox *session_in;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *session_id;
    QPushButton *endsession_btn;
    QPushButton *refresh_btn;

    void setupUi(QDialog *tutordashboard)
    {
        if (tutordashboard->objectName().isEmpty())
            tutordashboard->setObjectName("tutordashboard");
        tutordashboard->resize(953, 691);
        tutordashboard->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        top = new QTextBrowser(tutordashboard);
        top->setObjectName("top");
        top->setGeometry(QRect(0, 0, 441, 192));
        top->setFrameShape(QFrame::Shape::NoFrame);
        top->setLineWidth(0);
        logout_btn = new QPushButton(tutordashboard);
        logout_btn->setObjectName("logout_btn");
        logout_btn->setGeometry(QRect(820, 10, 111, 41));
        tabWidget = new QTabWidget(tutordashboard);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 90, 931, 591));
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        RequestTab = new QWidget();
        RequestTab->setObjectName("RequestTab");
        RequestTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        request = new QFrame(RequestTab);
        request->setObjectName("request");
        request->setGeometry(QRect(10, 10, 901, 551));
        verticalLayout = new QVBoxLayout(request);
        verticalLayout->setObjectName("verticalLayout");
        request_out = new QTextBrowser(request);
        request_out->setObjectName("request_out");

        verticalLayout->addWidget(request_out);

        request_input = new QGroupBox(request);
        request_input->setObjectName("request_input");
        horizontalLayout = new QHBoxLayout(request_input);
        horizontalLayout->setObjectName("horizontalLayout");
        req_in = new QLineEdit(request_input);
        req_in->setObjectName("req_in");
        req_in->setMaximumSize(QSize(250, 16777215));
        req_in->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout->addWidget(req_in);

        acceptreq_btn = new QPushButton(request_input);
        acceptreq_btn->setObjectName("acceptreq_btn");
        acceptreq_btn->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(acceptreq_btn);


        verticalLayout->addWidget(request_input);

        tabWidget->addTab(RequestTab, QString());
        RatingsTab = new QWidget();
        RatingsTab->setObjectName("RatingsTab");
        RatingsTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        Ratings = new QGroupBox(RatingsTab);
        Ratings->setObjectName("Ratings");
        Ratings->setGeometry(QRect(10, 10, 901, 551));
        verticalLayout_3 = new QVBoxLayout(Ratings);
        verticalLayout_3->setObjectName("verticalLayout_3");
        ratings_out = new QTextBrowser(Ratings);
        ratings_out->setObjectName("ratings_out");

        verticalLayout_3->addWidget(ratings_out);

        tabWidget->addTab(RatingsTab, QString());
        SessionsTab = new QWidget();
        SessionsTab->setObjectName("SessionsTab");
        SessionsTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        sessions = new QFrame(SessionsTab);
        sessions->setObjectName("sessions");
        sessions->setGeometry(QRect(10, 10, 901, 551));
        verticalLayout_4 = new QVBoxLayout(sessions);
        verticalLayout_4->setObjectName("verticalLayout_4");
        sessions_out = new QTextBrowser(sessions);
        sessions_out->setObjectName("sessions_out");

        verticalLayout_4->addWidget(sessions_out);

        session_in = new QGroupBox(sessions);
        session_in->setObjectName("session_in");
        horizontalLayout_4 = new QHBoxLayout(session_in);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        session_id = new QLineEdit(session_in);
        session_id->setObjectName("session_id");
        session_id->setMaximumSize(QSize(250, 16777215));
        session_id->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        horizontalLayout_4->addWidget(session_id);

        endsession_btn = new QPushButton(session_in);
        endsession_btn->setObjectName("endsession_btn");
        endsession_btn->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(endsession_btn);


        verticalLayout_4->addWidget(session_in);

        tabWidget->addTab(SessionsTab, QString());
        refresh_btn = new QPushButton(tutordashboard);
        refresh_btn->setObjectName("refresh_btn");
        refresh_btn->setGeometry(QRect(680, 10, 111, 41));

        retranslateUi(tutordashboard);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(tutordashboard);
    } // setupUi

    void retranslateUi(QDialog *tutordashboard)
    {
        tutordashboard->setWindowTitle(QCoreApplication::translate("tutordashboard", "Dialog", nullptr));
        top->setHtml(QCoreApplication::translate("tutordashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#354680;\">Hello TUTOR</span></p></body></html>", nullptr));
        logout_btn->setText(QCoreApplication::translate("tutordashboard", "Logout", nullptr));
#if QT_CONFIG(tooltip)
        req_in->setToolTip(QCoreApplication::translate("tutordashboard", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        req_in->setPlaceholderText(QCoreApplication::translate("tutordashboard", "Request ID", nullptr));
        acceptreq_btn->setText(QCoreApplication::translate("tutordashboard", "Accept Request", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RequestTab), QCoreApplication::translate("tutordashboard", "Request", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RatingsTab), QCoreApplication::translate("tutordashboard", "Ratings", nullptr));
#if QT_CONFIG(tooltip)
        session_id->setToolTip(QCoreApplication::translate("tutordashboard", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        session_id->setPlaceholderText(QCoreApplication::translate("tutordashboard", "Session ID", nullptr));
        endsession_btn->setText(QCoreApplication::translate("tutordashboard", "End Session", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SessionsTab), QCoreApplication::translate("tutordashboard", "Sessions", nullptr));
        refresh_btn->setText(QCoreApplication::translate("tutordashboard", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tutordashboard: public Ui_tutordashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORDASHBOARD_H
