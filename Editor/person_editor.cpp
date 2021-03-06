#include "person_editor.h"

QString Person_Editor::print_person()
{
    QString output;
    if (merchant_)
    {
        // Skriv ut merchant
        output.append("\n\tMerchant:\n\t{\n");
    }
    else
    {
        output.append("\n\tPerson:\n\t{\n");
    }

    output.append("\t\tName: " + name_ + "\n");

    output.append("\t\tDescription: " + description_.replace("\n", "\\n") + "\n");
    output.append("\t\tDialog: " + dialog_.replace("\n", "\\n") + "\n");
    output.append("\t\tRecieved item dialog: " + recieved_item_dialog_.replace("\n", "\\n") + "\n");
    output.append("\t\tHair: " + haircolour_ + "\n");
    output.append("\t\tHeight: " + QString::number(length_) + "\n");
    output.append("\t\tWidth: " + QString::number(width_) + "\n");
    output.append("\t\tWeight: " + QString::number(weight_) + "\n");
    output.append("\t\tWants: " + wanted_item_name_ + "\n");
    for (Item_Editor s : items_)
    {
        output.append(s.print_item());
    }

    output.append("\t}\n");

    return output;
}
