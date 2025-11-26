/********************************************************************************
** Form generated from reading UI file 'studentdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDASHBOARD_H
#define UI_STUDENTDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentdashboard
{
public:
    QTextBrowser *toptext;
    QPushButton *logout_btn;
    QTabWidget *tabWidget;
    QWidget *RequestTab;
    QTextBrowser *title;
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *sub_label;
    QComboBox *subjects;
    QLabel *urg_label;
    QSpinBox *urgency;
    QLabel *desc_label;
    QLineEdit *desc;
    QLabel *req_status;
    QPushButton *createreq_btn;
    QWidget *SearchTab;
    QFrame *search_2;
    QVBoxLayout *verticalLayout_4;
    QTextBrowser *search_out;
    QGroupBox *searchbar;
    QHBoxLayout *search;
    QComboBox *searchoptions;
    QLineEdit *search_in;
    QPushButton *searchtutor_btn;
    QWidget *SessionsTab;
    QFrame *session;
    QVBoxLayout *verticalLayout_5;
    QTextBrowser *sessions_out;
    QGroupBox *inputbar;
    QHBoxLayout *horizontalLayout;
    QSpinBox *rating_in;
    QLineEdit *tutor_user;
    QLineEdit *comments;
    QPushButton *ratetutor_btn;
    QGroupBox *session_in;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *session_id;
    QPushButton *endsession_btn;
    QPushButton *refresh_btn;

    void setupUi(QDialog *studentdashboard)
    {
        if (studentdashboard->objectName().isEmpty())
            studentdashboard->setObjectName("studentdashboard");
        studentdashboard->resize(985, 711);
        studentdashboard->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        studentdashboard->setSizeGripEnabled(false);
        toptext = new QTextBrowser(studentdashboard);
        toptext->setObjectName("toptext");
        toptext->setGeometry(QRect(10, 10, 341, 51));
        toptext->setFrameShape(QFrame::Shape::NoFrame);
        toptext->setLineWidth(0);
        logout_btn = new QPushButton(studentdashboard);
        logout_btn->setObjectName("logout_btn");
        logout_btn->setGeometry(QRect(860, 10, 111, 41));
        tabWidget = new QTabWidget(studentdashboard);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 80, 961, 621));
        tabWidget->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        RequestTab = new QWidget();
        RequestTab->setObjectName("RequestTab");
        RequestTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        title = new QTextBrowser(RequestTab);
        title->setObjectName("title");
        title->setGeometry(QRect(260, 10, 431, 81));
        title->setFrameShape(QFrame::Shape::NoFrame);
        title->setLineWidth(0);
        formGroupBox = new QGroupBox(RequestTab);
        formGroupBox->setObjectName("formGroupBox");
        formGroupBox->setGeometry(QRect(260, 140, 431, 171));
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName("formLayout");
        sub_label = new QLabel(formGroupBox);
        sub_label->setObjectName("sub_label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, sub_label);

        subjects = new QComboBox(formGroupBox);
        subjects->setObjectName("subjects");
        subjects->setMinimumSize(QSize(325, 0));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, subjects);

        urg_label = new QLabel(formGroupBox);
        urg_label->setObjectName("urg_label");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, urg_label);

        urgency = new QSpinBox(formGroupBox);
        urgency->setObjectName("urgency");
        urgency->setMinimumSize(QSize(325, 0));
        urgency->setMaximum(5);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, urgency);

        desc_label = new QLabel(formGroupBox);
        desc_label->setObjectName("desc_label");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, desc_label);

        desc = new QLineEdit(formGroupBox);
        desc->setObjectName("desc");
        desc->setMinimumSize(QSize(325, 0));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, desc);

        req_status = new QLabel(RequestTab);
        req_status->setObjectName("req_status");
        req_status->setGeometry(QRect(260, 390, 431, 65));
        createreq_btn = new QPushButton(RequestTab);
        createreq_btn->setObjectName("createreq_btn");
        createreq_btn->setGeometry(QRect(260, 330, 431, 32));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createreq_btn->sizePolicy().hasHeightForWidth());
        createreq_btn->setSizePolicy(sizePolicy);
        createreq_btn->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->addTab(RequestTab, QString());
        SearchTab = new QWidget();
        SearchTab->setObjectName("SearchTab");
        SearchTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        search_2 = new QFrame(SearchTab);
        search_2->setObjectName("search_2");
        search_2->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_4 = new QVBoxLayout(search_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        search_out = new QTextBrowser(search_2);
        search_out->setObjectName("search_out");

        verticalLayout_4->addWidget(search_out);

        searchbar = new QGroupBox(search_2);
        searchbar->setObjectName("searchbar");
        search = new QHBoxLayout(searchbar);
        search->setObjectName("search");
        searchoptions = new QComboBox(searchbar);
        searchoptions->setObjectName("searchoptions");
        searchoptions->setMaximumSize(QSize(200, 16777215));

        search->addWidget(searchoptions);

        search_in = new QLineEdit(searchbar);
        search_in->setObjectName("search_in");
        search_in->setMaximumSize(QSize(500, 16777215));

        search->addWidget(search_in);

        searchtutor_btn = new QPushButton(searchbar);
        searchtutor_btn->setObjectName("searchtutor_btn");
        searchtutor_btn->setMaximumSize(QSize(200, 16777215));

        search->addWidget(searchtutor_btn);


        verticalLayout_4->addWidget(searchbar);

        tabWidget->addTab(SearchTab, QString());
        SessionsTab = new QWidget();
        SessionsTab->setObjectName("SessionsTab");
        SessionsTab->setStyleSheet(QString::fromUtf8("QPushButton { color: rgb(32, 72, 175); background-color: rgb(176, 230, 255)}\n"
"QDialog{background-color: rgb(218, 241, 255)}QTextBrowser{background-color: rgb(218, 241, 255)}QLineEdit{background-color: white}"));
        session = new QFrame(SessionsTab);
        session->setObjectName("session");
        session->setGeometry(QRect(20, 20, 901, 551));
        verticalLayout_5 = new QVBoxLayout(session);
        verticalLayout_5->setObjectName("verticalLayout_5");
        sessions_out = new QTextBrowser(session);
        sessions_out->setObjectName("sessions_out");

        verticalLayout_5->addWidget(sessions_out);

        inputbar = new QGroupBox(session);
        inputbar->setObjectName("inputbar");
        horizontalLayout = new QHBoxLayout(inputbar);
        horizontalLayout->setObjectName("horizontalLayout");
        rating_in = new QSpinBox(inputbar);
        rating_in->setObjectName("rating_in");
        rating_in->setMaximum(5);
        rating_in->setSingleStep(1);

        horizontalLayout->addWidget(rating_in);

        tutor_user = new QLineEdit(inputbar);
        tutor_user->setObjectName("tutor_user");

        horizontalLayout->addWidget(tutor_user);

        comments = new QLineEdit(inputbar);
        comments->setObjectName("comments");

        horizontalLayout->addWidget(comments);

        ratetutor_btn = new QPushButton(inputbar);
        ratetutor_btn->setObjectName("ratetutor_btn");

        horizontalLayout->addWidget(ratetutor_btn);

        session_in = new QGroupBox(inputbar);
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


        horizontalLayout->addWidget(session_in);


        verticalLayout_5->addWidget(inputbar);

        tabWidget->addTab(SessionsTab, QString());
        refresh_btn = new QPushButton(studentdashboard);
        refresh_btn->setObjectName("refresh_btn");
        refresh_btn->setGeometry(QRect(720, 10, 111, 41));

        retranslateUi(studentdashboard);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(studentdashboard);
    } // setupUi

    void retranslateUi(QDialog *studentdashboard)
    {
        studentdashboard->setWindowTitle(QCoreApplication::translate("studentdashboard", "Dialog", nullptr));
        toptext->setHtml(QCoreApplication::translate("studentdashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#354680;\">Hello STUDENT</span></p></body></html>", nullptr));
        logout_btn->setText(QCoreApplication::translate("studentdashboard", "Logout", nullptr));
        title->setHtml(QCoreApplication::translate("studentdashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; color:#354680;\">Create a new Request \360\237\220\263</span></p></body></html>", nullptr));
        sub_label->setText(QCoreApplication::translate("studentdashboard", "Subject:", nullptr));
        urg_label->setText(QCoreApplication::translate("studentdashboard", "Urgency:", nullptr));
        desc_label->setText(QCoreApplication::translate("studentdashboard", "Description:", nullptr));
        desc->setPlaceholderText(QCoreApplication::translate("studentdashboard", "Description", nullptr));
        req_status->setText(QString());
        createreq_btn->setText(QCoreApplication::translate("studentdashboard", "Create Request", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(RequestTab), QCoreApplication::translate("studentdashboard", "Request", nullptr));
        searchtutor_btn->setText(QCoreApplication::translate("studentdashboard", "Search Tutor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SearchTab), QCoreApplication::translate("studentdashboard", "Search", nullptr));
        tutor_user->setPlaceholderText(QCoreApplication::translate("studentdashboard", "Tutor Username", nullptr));
        comments->setPlaceholderText(QCoreApplication::translate("studentdashboard", "Comments", nullptr));
        ratetutor_btn->setText(QCoreApplication::translate("studentdashboard", "Rate Tutor", nullptr));
#if QT_CONFIG(tooltip)
        session_id->setToolTip(QCoreApplication::translate("studentdashboard", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        session_id->setPlaceholderText(QCoreApplication::translate("studentdashboard", "Session ID", nullptr));
        endsession_btn->setText(QCoreApplication::translate("studentdashboard", "End Session", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SessionsTab), QCoreApplication::translate("studentdashboard", "Sessions", nullptr));
        refresh_btn->setText(QCoreApplication::translate("studentdashboard", "Refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentdashboard: public Ui_studentdashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDASHBOARD_H
