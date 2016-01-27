//Configs widget
//Contains Configs for ZopperScan

#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QtWidgets\QWidget>
#include <QtWidgets\QGridLayout>
#include <QtWidgets\QLabel>
#include "headers\ImageTemplate.hpp"
#include "ConfigFileWidget.hpp"

class ConfigWidget : public QWidget
{
	Q_OBJECT

public:
	//Constructor
	ConfigWidget(QWidget *parent = 0);

	//Destructor
	~ConfigWidget();

	//Get file names
	std::vector<std::string> getFileNames();

	//Get file URL from file name
	QUrl getFileUrl(std::string name);

public slots:
	//Refresh
	void refresh();

private slots :

	//Add files
	void addFiles();

private:

	//Main Layout
	QGridLayout *layout;

	//Header Labels
	QLabel *name;
	QLabel *path;

	//Push button
	QPushButton *addConfig;

	//QWidgets for each file
	std::vector<ConfigFileWidget *> configFiles;
	
};

#endif