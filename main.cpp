#include <QApplication>
// #include <QSplashScreen>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // QApplication app(argc, argv);

    // QSplashScreen *splash = new QSplashScreen;
    // splash->setPixmap(QPixmap(":/images/splash.png"));
    // splash->show();

    // Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    // splash->showMessage(QObject::tr("setting up the main window..."),
    //                     topRight, Qt::white);
    // MainWindow *mainWin = new MainWindow;

//     splash->showMessage(QObject::tr("loading modules..."),
//                         topRight, Qt::white);
//  //   loadModules();

//     splash->showMessage(QObject::tr("Establishing connections..."),
//             topRight, Qt::white);
//     establishConnections();

    // mainWin->show();
    // splash->finish(&mainwin);
    // delete splash;
    
    // return app.exec();
    // QApplication app(argc, argv);
    // MainWindow mainWin;
    // mainWin.show();
    // return app.exec();

    QApplication app(argc, argv);
    MainWindow *mainWin = new MainWindow;
    mainWin->show();
    return app.exec();
}