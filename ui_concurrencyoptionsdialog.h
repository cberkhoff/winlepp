/********************************************************************************
** Form generated from reading ui file 'concurrencyoptionsdialog.ui'
**
** Created: Tue 23. Jun 15:41:11 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONCURRENCYOPTIONSDIALOG_H
#define UI_CONCURRENCYOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConcurrencyOptionsDialogClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *concurrencyCheckBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *threadNumberSpinBox;
    QLabel *label_3;
    QLineEdit *idealThreadNumberLineEdit;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *acceptButton;

    void setupUi(QDialog *ConcurrencyOptionsDialogClass)
    {
        if (ConcurrencyOptionsDialogClass->objectName().isEmpty())
            ConcurrencyOptionsDialogClass->setObjectName(QString::fromUtf8("ConcurrencyOptionsDialogClass"));
        ConcurrencyOptionsDialogClass->resize(270, 315);
        verticalLayout_2 = new QVBoxLayout(ConcurrencyOptionsDialogClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(ConcurrencyOptionsDialogClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        concurrencyCheckBox = new QCheckBox(groupBox);
        concurrencyCheckBox->setObjectName(QString::fromUtf8("concurrencyCheckBox"));
        concurrencyCheckBox->setChecked(true);

        verticalLayout->addWidget(concurrencyCheckBox);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ConcurrencyOptionsDialogClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setWordWrap(true);

        verticalLayout_3->addWidget(label_4);

        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        threadNumberSpinBox = new QSpinBox(widget);
        threadNumberSpinBox->setObjectName(QString::fromUtf8("threadNumberSpinBox"));

        horizontalLayout->addWidget(threadNumberSpinBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);

        idealThreadNumberLineEdit = new QLineEdit(widget);
        idealThreadNumberLineEdit->setObjectName(QString::fromUtf8("idealThreadNumberLineEdit"));
        idealThreadNumberLineEdit->setEnabled(false);

        horizontalLayout->addWidget(idealThreadNumberLineEdit);


        verticalLayout_3->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setMargin(11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(widget_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        acceptButton = new QPushButton(widget_2);
        acceptButton->setObjectName(QString::fromUtf8("acceptButton"));

        horizontalLayout_2->addWidget(acceptButton);


        verticalLayout_3->addWidget(widget_2);


        verticalLayout_2->addWidget(groupBox_2);


        retranslateUi(ConcurrencyOptionsDialogClass);
        QObject::connect(acceptButton, SIGNAL(clicked()), ConcurrencyOptionsDialogClass, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ConcurrencyOptionsDialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConcurrencyOptionsDialogClass);
    } // setupUi

    void retranslateUi(QDialog *ConcurrencyOptionsDialogClass)
    {
        ConcurrencyOptionsDialogClass->setWindowTitle(QApplication::translate("ConcurrencyOptionsDialogClass", "Opciones de Concurrencia", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConcurrencyOptionsDialogClass", "Uso de los m\303\272ltiples n\303\272cleos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "Marque la siguiente opci\303\263n si desea hacer uso de los m\303\272ltiples n\303\272cleos de su procesador", 0, QApplication::UnicodeUTF8));
        concurrencyCheckBox->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "Usar Concurrencia", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ConcurrencyOptionsDialogClass", "N\303\272mero de Threads", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "Seleccione el n\303\272mero m\303\241ximo de threads que podr\303\241 utilizar WinLepp simultaneamente. Se anexa el n\303\272mero ideal  de threads a utilizar (depende de su computadora)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "N\303\272mero de Threads", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "/ ", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "Cancelar", 0, QApplication::UnicodeUTF8));
        acceptButton->setText(QApplication::translate("ConcurrencyOptionsDialogClass", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ConcurrencyOptionsDialogClass);
    } // retranslateUi

};

namespace Ui {
    class ConcurrencyOptionsDialogClass: public Ui_ConcurrencyOptionsDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONCURRENCYOPTIONSDIALOG_H
