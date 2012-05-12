/********************************************************************************
** Form generated from reading ui file 'refinementdialog.ui'
**
** Created: Tue 23. Jun 15:41:11 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_REFINEMENTDIALOG_H
#define UI_REFINEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RefinementDialogClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *statusLabel;
    QProgressBar *progressBar;
    QLabel *triangleLabel;
    QLabel *timeLabel;
    QLabel *threadNumberLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *RefinementDialogClass)
    {
        if (RefinementDialogClass->objectName().isEmpty())
            RefinementDialogClass->setObjectName(QString::fromUtf8("RefinementDialogClass"));
        RefinementDialogClass->setWindowModality(Qt::WindowModal);
        RefinementDialogClass->resize(449, 173);
        verticalLayout = new QVBoxLayout(RefinementDialogClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        statusLabel = new QLabel(RefinementDialogClass);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        progressBar = new QProgressBar(RefinementDialogClass);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        triangleLabel = new QLabel(RefinementDialogClass);
        triangleLabel->setObjectName(QString::fromUtf8("triangleLabel"));

        verticalLayout->addWidget(triangleLabel);

        timeLabel = new QLabel(RefinementDialogClass);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        threadNumberLabel = new QLabel(RefinementDialogClass);
        threadNumberLabel->setObjectName(QString::fromUtf8("threadNumberLabel"));

        verticalLayout->addWidget(threadNumberLabel);

        verticalSpacer = new QSpacerItem(20, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(RefinementDialogClass);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setEnabled(false);

        horizontalLayout->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RefinementDialogClass);
        QObject::connect(okButton, SIGNAL(clicked()), RefinementDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(RefinementDialogClass);
    } // setupUi

    void retranslateUi(QDialog *RefinementDialogClass)
    {
        RefinementDialogClass->setWindowTitle(QApplication::translate("RefinementDialogClass", "Refinamiento", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("RefinementDialogClass", "Iniciando Refinamiento", 0, QApplication::UnicodeUTF8));
        triangleLabel->setText(QApplication::translate("RefinementDialogClass", "Tri\303\241ngulo:", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("RefinementDialogClass", "Tiempo Transcurrido:", 0, QApplication::UnicodeUTF8));
        threadNumberLabel->setText(QApplication::translate("RefinementDialogClass", "Threads Activos:", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("RefinementDialogClass", "Finalizar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(RefinementDialogClass);
    } // retranslateUi

};

namespace Ui {
    class RefinementDialogClass: public Ui_RefinementDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFINEMENTDIALOG_H
