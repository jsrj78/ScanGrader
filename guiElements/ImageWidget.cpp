#include "ImageWidget.hpp"

//Constructor
ImageWidget::ImageWidget(QWidget *parent) {
	//Set layout to GridLayout
	layout = new QGridLayout();
	layout->setVerticalSpacing(0);
	setLayout(layout);

	fileLabel = new QLabel("Image Path");
	fileLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	configLabel = new QLabel("Configuration File");
	configLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	answerLabel = new QLabel("Answer Key");
	answerLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	layout->addWidget(fileLabel, 1, 0);
	layout->addWidget(configLabel, 1, 1);
	layout->addWidget(answerLabel, 1, 2);

	//Create add button
	add = new QPushButton("Add Scan Image");
	add->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	//Connect add button
	QPushButton::connect(add, SIGNAL(released()), this, SLOT(addScanFileWidget()));

	//Add add button to layout
	layout->addWidget(add, 0, 0);

	//Create calculate button
	calculate = new QPushButton("Calculate Score(s)");
	calculate->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	//Connect calculate
	//connect(calculate, SIGNAL(released()), parent, SLOT(calculate()));

	//Add calculate button to layout
	layout->addWidget(calculate, 0, 1);

	//Create status
	status = new QLabel("Status: IDLE");
	status->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

	//Add status label to layout
	layout->addWidget(status, 0, 2);

	//Add empty widget to take up size
	QWidget *empty1 = new QWidget();
	empty1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->addWidget(empty1, 999, 0);
	QWidget *empty2 = new QWidget();
	empty2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->addWidget(empty2, 999, 1);
	QWidget *empty3 = new QWidget();
	empty3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->addWidget(empty3, 999, 2);
	QWidget *empty4 = new QWidget();
	empty4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	layout->addWidget(empty4, 999, 3);

	//Refresh
	refresh();
}

//Destructor
ImageWidget::~ImageWidget() {
	delete layout;
	delete add;
}

//**********Public Slots**********

//Refresh UI
void ImageWidget::refresh() {
	layout->update();
	update();
}

//**********Private Slots**********

//Add ScanFileWidget
void ImageWidget::addScanFileWidget() {
	scanFiles.push_back(new ScanFileWidget(layout, scanFiles.size() + 2));
	scanFiles.at(scanFiles.size() - 1)->updatePath("SAMPLE #" + std::to_string(scanFiles.size()));
	initButtons();
	layout->addWidget(buttons.at(buttons.size() - 1), buttons.size() + 1, 3);

	refresh();
}

//**********Private Functions**********

//Initialize Buttons
void ImageWidget::initButtons() {
	//Initialize button widget
	buttons.push_back(new QWidget());

	//Initialize button layout
	buttonLayout.push_back(new QBoxLayout(QBoxLayout::LeftToRight));

	//Initialize remove button
	removeButton.push_back(new QPushButton("Remove"));

	//Add buttons to layout
	buttonLayout.at(buttonLayout.size() - 1)->addWidget(removeButton.at(removeButton.size() - 1));

	//Set Layout
	buttons.at(buttons.size() - 1)->setLayout(buttonLayout.at(buttonLayout.size() - 1));

	//Connect buttons
	connect(removeButton.at(removeButton.size() - 1), SIGNAL(released()), scanFiles.at(scanFiles.size() - 1), SLOT(deleteLater()));
	connect(removeButton.at(removeButton.size() - 1), SIGNAL(released()), buttons.at(buttons.size() - 1), SLOT(deleteLater()));

	//Connect all buttons to refresh
	connect(removeButton.at(removeButton.size() - 1), SIGNAL(released()), this, SLOT(refresh()));
}
