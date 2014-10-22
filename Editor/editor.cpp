#include "editor.h"
#include "ui_editor.h"
#include <QDebug>

Editor::Editor(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Editor)
{
    ui->setupUi(this);

    Person_Editor p1{"Armen", "test","DU ÄR VÄRDELÖS!","Bisysslor?","hej1","hej2", 10, 10, 10, true};
    Person_Editor p2{"Granntant Åsa", "Åsa_test","Kakor?","Tack! Har du något skvaller?","hej3","hej4", 5, 5, 10, false};
    personer.push_back(p1);
    personer.push_back(p2);

    for (Person_Editor s : personer)
    {
        ui->list_npcs->addItem(s.name_);
    }
}


Editor::~Editor()
{
    delete ui;
}


void Editor::load_NPC(const Person_Editor p)
{
    ui->edit_name->setText(p.name_);
    ui->edit_description->setPlainText(p.description_);
    ui->edit_dialog->setPlainText(p.dialog_);
    ui->edit_recieved_dialog->setPlainText(p.recieved_item_dialog_);
    ui->edit_hair->setText(p.haircolour_);
    ui->edit_wants->setText(p.wanted_item_name_);
    ui->edit_weight->setValue(p.weight_);
    ui->edit_height->setValue(p.length_);
    ui->edit_width->setValue(p.width_);
    ui->checkbox_Merchant->setChecked(p.merchant_);
}

void Editor::on_list_npcs_doubleClicked(const QModelIndex &index)
{
    // Byt till personfliken
    if (ui->tabWidget->currentIndex() != 2)
        ui->tabWidget->setCurrentIndex(2);

    current_person_ = index.row();
    load_NPC(personer.at(index.row()));
}

void Editor::on_button_npc_clicked()
{
    Person_Editor temp{"Namnlös person", "","","","","", 0, 0, 0, false};
    personer.push_back(temp);
    ui->list_npcs->addItem(temp.name_);
}




// -- START: Funktioner som sparar värdena som användaren skriver in --
void Editor::on_edit_description_textChanged()
{
    personer.at(current_person_).description_ = ui->edit_description->toPlainText();
}

void Editor::on_edit_dialog_textChanged()
{
    personer.at(current_person_).dialog_ = ui->edit_dialog->toPlainText();
}

void Editor::on_edit_recieved_dialog_textChanged()
{
    personer.at(current_person_).recieved_item_dialog_ = ui->edit_recieved_dialog->toPlainText();
}

void Editor::on_edit_hair_textChanged(const QString &arg1)
{
    personer.at(current_person_).haircolour_ = arg1;
}

void Editor::on_edit_name_textChanged(const QString &arg1)
{
    ui->list_npcs->item(current_person_)->setText(arg1);
}


void Editor::on_edit_width_valueChanged(int arg1)
{
    personer.at(current_person_).width_ = arg1;
}

void Editor::on_edit_wants_textChanged(const QString &arg1)
{
    personer.at(current_person_).wanted_item_name_ = arg1;
}

void Editor::on_edit_weight_valueChanged(int arg1)
{
    personer.at(current_person_).weight_ = arg1;
}

void Editor::on_edit_height_valueChanged(int arg1)
{
    personer.at(current_person_).length_ = arg1;
}

void Editor::on_checkbox_Merchant_clicked()
{
    personer.at(current_person_).merchant_ = ui->checkbox_Merchant->checkState();
}

// -- SLUT: Funktioner som sparar värdena som användaren skriver in --

