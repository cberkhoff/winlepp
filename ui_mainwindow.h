/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue 23. Jun 15:41:11 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindowClass
{
public:
    QAction *action_Salir;
    QAction *actionCargar_Mesh;
    QAction *actionGuardar_Malla;
    QAction *actionAcerca_de;
    QAction *actionCriterios_de_Selecci_n;
    QAction *actionConcurrencia;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QWidget *mainPanel;
    QHBoxLayout *horizontalLayout;
    QWidget *modePanel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *consoleButton;
    QPushButton *uiButton;
    QFrame *line;
    QWidget *uiPanel;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *clearSelectionButton;
    QPushButton *selectAllButton;
    QPushButton *selectAngleButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *sceneScaleCombo;
    QWidget *consolePanel;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *selectionCriterionComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *refineButton;
    QTextEdit *textEdit;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menu_Archivo;
    QMenu *menuAyuda;
    QMenu *menuOpciones;

    void setupUi(QMainWindow *mainwindowClass)
    {
        if (mainwindowClass->objectName().isEmpty())
            mainwindowClass->setObjectName(QString::fromUtf8("mainwindowClass"));
        mainwindowClass->resize(778, 486);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/main_icon/logo.png")), QIcon::Normal, QIcon::On);
        mainwindowClass->setWindowIcon(icon);
        action_Salir = new QAction(mainwindowClass);
        action_Salir->setObjectName(QString::fromUtf8("action_Salir"));
        actionCargar_Mesh = new QAction(mainwindowClass);
        actionCargar_Mesh->setObjectName(QString::fromUtf8("actionCargar_Mesh"));
        actionGuardar_Malla = new QAction(mainwindowClass);
        actionGuardar_Malla->setObjectName(QString::fromUtf8("actionGuardar_Malla"));
        actionAcerca_de = new QAction(mainwindowClass);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        actionCriterios_de_Selecci_n = new QAction(mainwindowClass);
        actionCriterios_de_Selecci_n->setObjectName(QString::fromUtf8("actionCriterios_de_Selecci_n"));
        actionConcurrencia = new QAction(mainwindowClass);
        actionConcurrencia->setObjectName(QString::fromUtf8("actionConcurrencia"));
        centralwidget = new QWidget(mainwindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        mainPanel = new QWidget(centralwidget);
        mainPanel->setObjectName(QString::fromUtf8("mainPanel"));
        horizontalLayout = new QHBoxLayout(mainPanel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 9, 0);
        modePanel = new QWidget(mainPanel);
        modePanel->setObjectName(QString::fromUtf8("modePanel"));
        horizontalLayout_2 = new QHBoxLayout(modePanel);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 0, 9, 0);
        consoleButton = new QPushButton(modePanel);
        consoleButton->setObjectName(QString::fromUtf8("consoleButton"));
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8(":/mode/console.png")), QIcon::Normal, QIcon::Off);
        consoleButton->setIcon(icon1);
        consoleButton->setIconSize(QSize(32, 32));
        consoleButton->setFlat(false);

        horizontalLayout_2->addWidget(consoleButton);

        uiButton = new QPushButton(modePanel);
        uiButton->setObjectName(QString::fromUtf8("uiButton"));
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8(":/mode/meshscene.png")), QIcon::Normal, QIcon::Off);
        uiButton->setIcon(icon2);
        uiButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(uiButton);


        horizontalLayout->addWidget(modePanel);

        line = new QFrame(mainPanel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        uiPanel = new QWidget(mainPanel);
        uiPanel->setObjectName(QString::fromUtf8("uiPanel"));
        horizontalLayout_3 = new QHBoxLayout(uiPanel);
        horizontalLayout_3->setMargin(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(uiPanel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(9, 0, 9, 0);
        clearSelectionButton = new QPushButton(groupBox);
        clearSelectionButton->setObjectName(QString::fromUtf8("clearSelectionButton"));
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8(":/selection/select_none.png")), QIcon::Normal, QIcon::Off);
        clearSelectionButton->setIcon(icon3);

        horizontalLayout_5->addWidget(clearSelectionButton);

        selectAllButton = new QPushButton(groupBox);
        selectAllButton->setObjectName(QString::fromUtf8("selectAllButton"));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8(":/selection/select_all.png")), QIcon::Normal, QIcon::Off);
        selectAllButton->setIcon(icon4);

        horizontalLayout_5->addWidget(selectAllButton);

        selectAngleButton = new QPushButton(groupBox);
        selectAngleButton->setObjectName(QString::fromUtf8("selectAngleButton"));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8(":/selection/select_angle.png")), QIcon::Normal, QIcon::Off);
        selectAngleButton->setIcon(icon5);

        horizontalLayout_5->addWidget(selectAngleButton);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(uiPanel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(9, 0, 9, 0);
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        sceneScaleCombo = new QComboBox(groupBox_2);
        sceneScaleCombo->setObjectName(QString::fromUtf8("sceneScaleCombo"));

        horizontalLayout_6->addWidget(sceneScaleCombo);


        horizontalLayout_3->addWidget(groupBox_2);


        horizontalLayout->addWidget(uiPanel);

        consolePanel = new QWidget(mainPanel);
        consolePanel->setObjectName(QString::fromUtf8("consolePanel"));
        horizontalLayout_4 = new QHBoxLayout(consolePanel);
        horizontalLayout_4->setMargin(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(consolePanel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_7 = new QHBoxLayout(groupBox_3);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(9, 0, -1, 0);
        selectionCriterionComboBox = new QComboBox(groupBox_3);
        selectionCriterionComboBox->setObjectName(QString::fromUtf8("selectionCriterionComboBox"));

        horizontalLayout_7->addWidget(selectionCriterionComboBox);


        horizontalLayout_4->addWidget(groupBox_3);


        horizontalLayout->addWidget(consolePanel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        refineButton = new QPushButton(mainPanel);
        refineButton->setObjectName(QString::fromUtf8("refineButton"));
        QIcon icon6;
        icon6.addPixmap(QPixmap(QString::fromUtf8(":/main_icon/logo.png")), QIcon::Normal, QIcon::Off);
        refineButton->setIcon(icon6);
        refineButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(refineButton);


        verticalLayout_5->addWidget(mainPanel);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout_5->addWidget(textEdit);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_5->addWidget(graphicsView);

        mainwindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainwindowClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 778, 22));
        menu_Archivo = new QMenu(menubar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        menuOpciones = new QMenu(menubar);
        menuOpciones->setObjectName(QString::fromUtf8("menuOpciones"));
        mainwindowClass->setMenuBar(menubar);

        menubar->addAction(menu_Archivo->menuAction());
        menubar->addAction(menuOpciones->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menu_Archivo->addAction(actionCargar_Mesh);
        menu_Archivo->addAction(actionGuardar_Malla);
        menu_Archivo->addSeparator();
        menu_Archivo->addAction(action_Salir);
        menuAyuda->addAction(actionAcerca_de);
        menuOpciones->addAction(actionConcurrencia);

        retranslateUi(mainwindowClass);
        QObject::connect(action_Salir, SIGNAL(triggered()), mainwindowClass, SLOT(close()));

        sceneScaleCombo->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(mainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindowClass)
    {
        mainwindowClass->setWindowTitle(QApplication::translate("mainwindowClass", "WinLepp", 0, QApplication::UnicodeUTF8));
        action_Salir->setText(QApplication::translate("mainwindowClass", "&Salir", 0, QApplication::UnicodeUTF8));
        actionCargar_Mesh->setText(QApplication::translate("mainwindowClass", "Cargar Malla", 0, QApplication::UnicodeUTF8));
        actionGuardar_Malla->setText(QApplication::translate("mainwindowClass", "Guardar Malla", 0, QApplication::UnicodeUTF8));
        actionAcerca_de->setText(QApplication::translate("mainwindowClass", "Acerca de", 0, QApplication::UnicodeUTF8));
        actionCriterios_de_Selecci_n->setText(QApplication::translate("mainwindowClass", "Criterios de Selecci\303\263n", 0, QApplication::UnicodeUTF8));
        actionConcurrencia->setText(QApplication::translate("mainwindowClass", "Concurrencia", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        consoleButton->setToolTip(QApplication::translate("mainwindowClass", "Inicia la UI en modo consola (menos recursos)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        consoleButton->setText(QApplication::translate("mainwindowClass", "Consola", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        uiButton->setToolTip(QApplication::translate("mainwindowClass", "Inicia la UI y dibuja los triangulos en pantalla (m\303\241s recursos)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        uiButton->setText(QApplication::translate("mainwindowClass", "UI", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("mainwindowClass", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        clearSelectionButton->setToolTip(QApplication::translate("mainwindowClass", "Limpiar Selecci\303\263n", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        clearSelectionButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectAllButton->setToolTip(QApplication::translate("mainwindowClass", "Seleccionar Todos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectAllButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectAngleButton->setToolTip(QApplication::translate("mainwindowClass", "Slecci\303\263n basada en \303\241ngulos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        selectAngleButton->setText(QString());
        groupBox_2->setTitle(QApplication::translate("mainwindowClass", "Opciones", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mainwindowClass", "Zoom", 0, QApplication::UnicodeUTF8));
        sceneScaleCombo->clear();
        sceneScaleCombo->insertItems(0, QStringList()
         << QApplication::translate("mainwindowClass", "10%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "25%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "50%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "100%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "200%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "400%", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "1000%", 0, QApplication::UnicodeUTF8)
        );
        groupBox_3->setTitle(QApplication::translate("mainwindowClass", "Algoritmo de Selecci\303\263n", 0, QApplication::UnicodeUTF8));
        selectionCriterionComboBox->clear();
        selectionCriterionComboBox->insertItems(0, QStringList()
         << QApplication::translate("mainwindowClass", "Seleccionar todos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n basada en \303\241ngulos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n Aleatoria (50%)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n Aleatoria (10%)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n Aleatoria (5%)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n Aleatoria (3%)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("mainwindowClass", "Selecci\303\263n Aleatoria (1%)", 0, QApplication::UnicodeUTF8)
        );
        refineButton->setText(QApplication::translate("mainwindowClass", "Refinar", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("mainwindowClass", "&Archivo", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("mainwindowClass", "Ayuda", 0, QApplication::UnicodeUTF8));
        menuOpciones->setTitle(QApplication::translate("mainwindowClass", "Opciones", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainwindowClass: public Ui_mainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
