#ifndef CONFIGURATIONWINDOWS_H
#define CONFIGURATIONWINDOWS_H

#include <QApplication>
#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QSettings>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QCloseEvent>
#include <QTranslator>
#include <QLabel>
#include <QSizePolicy>
#include <QTextEdit>
#include <QListWidget>
#include <QListWidgetItem>

#include <iostream>

#include "ftpconfiguration.h"
#include "HTTPConfiguration.h"

class SystemTrayIcon;

class ConfigurationWindows : public QWidget
{
    Q_OBJECT
public:
    explicit ConfigurationWindows(SystemTrayIcon * parent, QWidget *qwidget = 0);
    ~ConfigurationWindows();

protected:
    SystemTrayIcon * parent;
    const QString windowTitle;
    QSettings settings;

    /* Settings name */
    const QString runOnStartupSettingName;
    const QString showNotificationsSettingName;
    const QString playSoundSettingName;
    const QString copyToClipboardSettingName;
    const QString langSettingName;
    const QString FTPMethodSettingName;
    const QString choosedMethodSettingName;

    QVBoxLayout * mainLayout;
    QTabWidget * windowContent;

    /* General */
    QWidget * generalSection;
    QFormLayout * formGeneral;
    QVBoxLayout * generalLayout;
    //Main Form
    QCheckBox * runOnStartup;
    QCheckBox * showNotifications;
    QCheckBox * playSound;
    QCheckBox * copyToClipboard;
    QComboBox * lang;
    //Online Services
    QGroupBox * onlineServices;
    QVBoxLayout * onlineServicesLayout;

    QRadioButton * FTPMethod;
    QPushButton * configureFTPButton;
    QHBoxLayout * FTPLayout;
    FTPConfiguration * FTPConf;

    QRadioButton * HTTPMethod;
    QLabel * HTTPWarning;
    QPushButton * configureHTTPButton;
    QHBoxLayout * HTTPLayoutForRadioAndPushButton;
    QVBoxLayout * HTTPLayout;
    HTTPConfiguration * HTTPConf;

    /* HotKeys */
    QWidget * hotkeysSection;

    /* Credits */
    QWidget * creditSection;
    QVBoxLayout * creditLayout;
    //Header
    QLabel * openSourceText;
    //Made with
    QHBoxLayout * madeWithLayout;
    QPushButton * madeWithQt;
    QPushButton * madeWithSFML;
    QTextEdit * SFMLLicence;
    //Contributors
    QLabel * leadDevelopper;
    QHBoxLayout * allContributorsLayout;
    QListWidget * allContributorsOne;
    QListWidget * allContributorsTwo;

    /* To close window */
    QHBoxLayout * validateLayout;
    QPushButton * validate;


    //Fonctions
    void setUpUI();
    void setUpGeneralSectionUI();
    void setUpHotkeysSectionUI();
    void setUpCreditsSectionUI();

    virtual void closeEvent(QCloseEvent *event);
    virtual void keyPressEvent(QKeyEvent *);

signals:
    void easterEgg();

public slots :
    void runOnStartupSettingModified(bool);
    void showNotificationSettingModified(bool);
    void playSoundSettingModified(bool);
    void copyToClipboardSettingModified(bool);
    void langSettingModified(QString);
    void FTPMethodSettingModified(bool);
    void HTTPMethodSettingModified(bool);

    void configureFTP();
    void configureHTTP();


};

#endif // CONFIGURATIONWINDOWS_H
