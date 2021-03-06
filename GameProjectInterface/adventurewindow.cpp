#include "adventurewindow.h"
#include "ui_adventurewindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>



AdventureWindow::AdventureWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdventureWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();

    /// Actions för att rensa för att få hjälp
    QAction *clearAction = ui->menuBar->addAction("Rensa");
    QAction *helpAction = ui->menuBar->addAction("Hjälp");
    connect(helpAction, SIGNAL(triggered()), this, SLOT(help()));
    connect(clearAction, SIGNAL(triggered()), this, SLOT(clear()));

    QFile file("help.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    G_.set_help(in.readAll());
}

AdventureWindow::~AdventureWindow()
{
    delete ui;
}

void AdventureWindow::help()
{
    ui->text_box->setText(G_.get_help());
}

void AdventureWindow::clear()
{
    ui->text_box->clear();
}

void AdventureWindow::on_menu_load_triggered()
{
    QFileDialog dialog;
    QString oj {""};    //fult, men måste skicka med en QString& till look
    dialog.setDefaultSuffix(".bisys");
    QString filename = dialog.getOpenFileName(this, tr("Öppna fil"), "~/", tr("Textäventyrsredigerarfiler (*.bisys *.bisysslor)"));
    G_.read_file(filename);
    ui->lineEdit->setReadOnly(false);
    ui->text_box->setText(P_.look(oj, G_));
    ui->menu_load->setEnabled(false);
}

void AdventureWindow::on_lineEdit_returnPressed()
{
    QString input {ui->lineEdit->text()};
    ui->text_box->append(P_.read_input(input,G_)); //Go down the path of the player.
    ui->lineEdit->clear();
    ui->inventory_list->clear();
    ui->inventory_list->addItem("Kosing: " + QString::number(P_.get_money()));
    for (Item i : P_.get_inventory())
    {
        ui->inventory_list->addItem(i.get_name());
    }
}

void AdventureWindow::on_inventory_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString oj {item->text().toUpper()};
        ui->text_box->append(P_.look(oj, G_));
}
