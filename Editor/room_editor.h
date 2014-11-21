#ifndef ROOM_EDITOR_H
#define ROOM_EDITOR_H

#include <vector>
#include <QString>
#include "person_editor.h"
#include "item_editor.h"

class Room_Editor
{
public:
    Room_Editor(QString name = "", QString description= "", int n = 0, int s = 0, int w = 0, int e = 0)
        : name_{name}, description_{description}, north_{n}, south_{s}, west_{w}, east_{e} {}

    void add_person(const Person_Editor & person) {persons_.push_back(person);}
    Person_Editor& get_person(size_t index) {return persons_.at(index);}

    void add_item(Item_Editor item) {items_.push_back(item);}
    void delete_item(size_t index) {items_.erase(items_.begin() + index);}
    void delete_person(size_t index) {persons_.erase(persons_.begin() + index);}
    Item_Editor& get_item(size_t index) {return items_.at(index);}
    Item_Editor& get_back_item() {return items_.back();}
    void pop_back_item() {items_.pop_back();}
    void pop_back_person() {persons_.pop_back();}

    std::vector<Person_Editor> get_persons() {return persons_;}
    std::vector<Item_Editor> get_items() {return items_;}
    QString get_description() const {return description_;}

    void set_name(QString name) {name_ = name;}
    void set_description(QString description) {description_ = description;}
    void set_directions(int n, int s, int w, int e) {north_ = n; south_ = s; west_ = w; east_ = e;}
    QString get_name() const {return name_;}

    void set_north(int n) {north_ = n;}
    void set_south(int s) {south_ = s;}
    void set_east(int e) {east_ = e;}
    void set_west(int w) {west_ = w;}

    int get_north() const {return north_;}
    int get_south() const {return south_;}
    int get_east() const {return east_;}
    int get_west() const {return west_;}

private:
    std::vector<Person_Editor> persons_;
    std::vector<Item_Editor> items_;
    QString name_, description_;
    int north_, south_, west_, east_;

};

#endif // ROOM_EDITOR_H
