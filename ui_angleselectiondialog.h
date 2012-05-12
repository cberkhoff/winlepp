/********************************************************************************
** Form generated from reading ui file 'angleselectiondialog.ui'
**
** Created: Tue 23. Jun 15:41:11 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ANGLESELECTIONDIALOG_H
#define UI_ANGLESELECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AngleSelectionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *distanceSlider;
    QLabel *distanceLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *AngleSelectionDialog)
    {
        if (AngleSelectionDialog->objectName().isEmpty())
            AngleSelectionDialog->setObjectName(QString::fromUtf8("AngleSelectionDialog"));
        AngleSelectionDialog->resize(286, 76);
        AngleSelectionDialog->setMaximumSize(QSize(286, 76));
        AngleSelectionDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AngleSelectionDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(AngleSelectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        distanceSlider = new QSlider(AngleSelectionDialog);
        distanceSlider->setObjectName(QString::fromUtf8("distanceSlider"));
        distanceSlider->setMaximum(119);
        distanceSlider->setValue(50);
        distanceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(distanceSlider);

        distanceLabel = new QLabel(AngleSelectionDialog);
        distanceLabel->setObjectName(QString::fromUtf8("distanceLabel"));

        horizontalLayout->addWidget(distanceLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelButton = new QPushButton(AngleSelectionDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        okButton = new QPushButton(AngleSelectionDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AngleSelectionDialog);
        QObject::connect(distanceSlider, SIGNAL(valueChanged(int)), distanceLabel, SLOT(setNum(int)));
        QObject::connect(okButton, SIGNAL(clicked()), AngleSelectionDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), AngleSelectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AngleSelectionDialog);
    } // setupUi

    void retranslateUi(QDialog *AngleSelectionDialog)
    {
        AngleSelectionDialog->setWindowTitle(QApplication::translate("AngleSelectionDialog", "Seleccione \303\241ngulos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        AngleSelectionDialog->setWhatsThis(QApplication::translate("AngleSelectionDialog", "Este criterio seleccionar\303\241 los triangulos que tengan un \303\241ngulo cuya distancia a los 60\302\260 sea mayor a lo aqui indicado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("AngleSelectionDialog", "Distancia de 60\302\260", 0, QApplication::UnicodeUTF8));
        distanceLabel->setText(QApplication::translate("AngleSelectionDialog", "50", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("AngleSelectionDialog", "Cancelar", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("AngleSelectionDialog", "Aceptar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AngleSelectionDialog);
    } // retranslateUi

};

namespace Ui {
    class AngleSelectionDialog: public Ui_AngleSelectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANGLESELECTIONDIALOG_H
