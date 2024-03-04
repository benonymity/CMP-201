#include <iostream>

class Item {
  public:
    Item()
        : inventory_id(0), price(0) {
        std::cout << "Item constructed\n";
    }
    Item(int i, int p)
        : inventory_id(i), price(p) {
        std::cout << "Item constructed\n";
    }

    std::string to_string() const {
        std::string result;
        result = "Price: " + std::to_string(price) +
                 "\nInventory ID: " + std::to_string(inventory_id);
        if (might_explode) {
            result += "\nThis item might explode";
        }
        result += "\n";
        return result;
    }

  private:
    int price;
    int inventory_id;
    bool might_explode;
};

class Book : public Item {
  public:
    Book()
        : title("none"),
          isbn("none"),
          author("Tony"),
          pages(0),
          inventory_id(0) {
        std::cout << "Book constructed\n";
    }

    void set_isbn(std::string isbn) {
        this->isbn = isbn;
    }

    std::string get_isbn() const {
        return isbn;
    }

    std::string to_string() const {
        std::string result;
        result = "Price: $" + std::to_string(price) + "\nTitle: " + title +
                 "\nAuthor: " + author + "\nPages: " + std::to_string(pages) +
                 "\nISBN: " + isbn +
                 "\nYear Published: " + std::to_string(publish_year) +
                 "\nGenre: " + genre + "\nCourse: " + course +
                 "\nInventory ID: " + std::to_string(inventory_id) +
                 "\nText: " + text + "\n";
        return result;
    }

  private:
    int pages;
    int price;
    int publish_year;
    int inventory_id;
    std::string text;
    std::string isbn;
    std::string title;
    std::string genre;
    std::string author;
    std::string course;
};

class Pen : public Item {
  public:
    Pen()
        : width(0.0),
          ink_color("fuscia"),
          tip_type("ballpoint"),
          price(5.0),
          might_explode(true),
          inventory_id(0) {
        std::cout << "Pen constructed\n";
    }

    std::string to_string() {
        std::string result;
        result = "Price: $" + std::to_string(price) +
                 "\nWidth: " + std::to_string(width) +
                 "\nInventory ID: " + std::to_string(inventory_id) +
                 "\nManufacturer: " + manufacturer + "\n";
        return result;
    }

  private:
    int inventory_id;
    bool might_explode;
    int price;
    double width;
    std::string ink_color;
    std::string tip_type;
    std::string manufacturer;
};

int main() {
    Book book;
    std::cout << book.to_string() << "\n\n";

    Pen pen;
    std::cout << pen.to_string();

    // Item item;
    // std::cout << item.to_string() << "\n\n"
}