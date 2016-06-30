#include <QApplication>
#include "MainWindowContainer.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
	 
	//set style of ui window as "WindowsXP" style
	app.setStyle("WindowsXP"); 
	 
	// create the instance of class what will be works with Facebook API
    MainWindowContainer mainWindowContainer;
    //show window
	mainWindowContainer.show();
	 
	//end of program when Exit button clicked
    return app.exec();
}
