/**
This file (c) by : - Martin Hammerchmidt alias Imote

This file is licensed under a
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.

You should have received a copy of the license along with this
work. If not, see <http://creativecommons.org/licenses/by-nc-sa/4.0/>.

If you have contributed to this file, add your name to authors list.
*/

#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <fstream>

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QSystemTrayIcon>
#include <QClipboard>
#include <QIcon>
#include <QShortcut>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QFileInfo>
#include <QSound>
#include <QSoundEffect>
#include <QAudioOutput>
#include <QDesktopServices>
#include <QUrl>
#include <QVariant>
#include <QStandardPaths>
#include <QTimer>
#include <QDir>
#include <QGraphicsDropShadowEffect>
#include "shared.h"

#include "configuration/configurationwindows.h"
#include "filesendedsound.h"
#include "screenmanager.h"

#ifdef _WIN32
#include <shortcut/shortcutmanager_win.h>
#endif
#ifdef __linux__
#include <shortcut/shortcutmanager_linux.h>
#endif


class SystemTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTrayIcon(QObject *qobject = 0);
    ~SystemTrayIcon();

    void showNotification(QString const& title, QString const& message, bool twitter = true);

    QUrl lastUrl;
    QString receivedMessage;

protected:
    QSettings settings;

    ConfigurationWindows * configurationWindow;
    FileManager * screenManager;

    QMenu * systemTrayMenu;
    QAction * takeScreen;
    QAction * takeSelectedScreen;
    QAction * sendPaste;
    QAction * uploadFile;
    QAction * uploadClipboard;
    QAction * showConfiguration;
    QAction * quit;

    void setUpContextMenu();
    void firstStart();

    FileSendedSound fileSendedSound;

    ShortcutManager * takeFullScreenShortcut;
    ShortcutManager * takeSelectedAreaScreenShortcut;
    ShortcutManager * sendPasteShortcut;
    ShortcutManager * uploadFileShortcut;
    ShortcutManager * uploadClipboardShortcut;

    QKeySequence takeFullScreenKeySequence;
    QKeySequence takeSelectedAreaKeySequence;
    QKeySequence sendPasteKeySequence;
    QKeySequence uploadFileKeySequence;
    QKeySequence uploadClipboardKeySequence;

    QTimer * iconTimer;

    //Temp
    File fileInfo;
    bool actionBeing;

    bool lastUploadedFileSeparatorInserted;
    QAction * lastUploadedFileSeparator;
    short lastUploadedFileCounter;

    //shadow
    QGraphicsDropShadowEffect * shadow;
    QWidget * configurationWindowShadow;

signals:

public slots :
    void disableHotkeys();
    void enableHotkeys();

    void showWindowConfigurationTriggered();
    void takeFullScrenTriggered();
    void takeSelectedAreaScreenTriggered();
    void sendPasteTriggered();
    void uploadSelectedFileTriggered();
    void uploadClipboardTriggered();
    void fileSended(const File &file);
    void lastActionFinished();
    void newActionStarted();
    void setWaitingIcon();
    void addUploadedFileInContextMenu();

    void sendSelectedArea();

    void throwErrorAlert(const QString &text);
    void throwErrorAlert(Uplimg::ErrorList const error);
    void throwErrorAlert(Uplimg::FTPStatus const error);

    void enableEasterEgg();

    void iconActivated(QSystemTrayIcon::ActivationReason);

    void takeFullScreenShortcutChanged(QString);
    void takeSelectedAreaScreenShortcutChanged(QString);
    void sendPasteShortcutChanged(QString);
    void uploadFileShortcutChanged(QString);
    void uploadClipboardShortcutChanged(QString);

    void openLastUrl();
    void copyLastUrlToClipboard();
};

#endif // SYSTEMTRAYICON_H
