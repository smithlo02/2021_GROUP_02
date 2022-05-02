#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>


/// This is the MainWindow class that inherits QMainWindow
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT


public:
    ///The default Constructor of the MainWindow class
    ///@param parent A Pointer to a QWidget object
    ///@note By default The pointer will set to NULL
    explicit MainWindow(QWidget *parent = nullptr);

    ///The Destructor of the MainWindow class
    ~MainWindow();

private:
    ///This method is used for loading .stl and .mod file
	void FileLoadingEvent();

    ///This method is used for setting up a good GUI appearance
	void UISetUp();

	///This method is used for initialize the OpenGl widget
	void InitOpenGLWindow();

	///This method is used for setting up signal and slot connection
	void SignalAndSlotSetUp();


private slots:
    ///This method is used for getting the current camera position
	void GetCameraPosition();

    ///This method is used for getting the model statistic
	void ModelStatistics();

	///This method is used for loading the texture file
	void ApplyTexture();

private:
	Ui::MainWindow* ui;

};

#endif // MAINWINDOW_H
