#include <iostream>
#include <vector>

class Item {
  public:
    Item()
        : inventory_id(0), price(5) {
        std::cout << "Item constructed\n";
    }
    Item(int i, int p)
        : inventory_id(i), price(p) {
        std::cout << "Item constructed\n";
    }

    int get_price() const {
        return price;
    }

    virtual std::string to_string() const {
        std::string result;
        result = "Price: " + std::to_string(price) +
                 "\nInventory ID: " + std::to_string(inventory_id);
        if (might_explode) {
            result += "\nThis item might explode";
        }
        result += "\n";
        return result;
    }

//   private:
  protected: // Anything that's a subclass can access the data members
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
          inventory_id(0),
          price(400) {
        std::cout << "Book constructed\n";
    }

    void set_isbn(std::string isbn) {
        this->isbn = isbn;
    }

    std::string get_isbn() const {
        return isbn;
    }

    int get_price() const {
        // return Item::get_price(); // if you don't want to use the protected keyword in the Item class
        return Item::price;
    }

    std::string to_string() const override {
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
          might_explode(true),
          manufacturer("---"),
        //   price(5.0),
        //   inventory_id(0),
          Item(1, 10) {
        std::cout << "Pen constructed\n";
    }

    std::string to_string() const override {
        std::string result;
        result = "Price: $" + std::to_string(price) +
                 "\nWidth: " + std::to_string(width) +
                 " mm\nInventory ID: " + std::to_string(inventory_id) +
                 "\nManufacturer: " + manufacturer + "\n";
        return result;
    }

    bool is_metal{true};
  private:
    // int price;
    int width;
    // int inventory_id;
    bool might_explode;
    std::string tip_type;
    std::string ink_color;
    std::string manufacturer;
};

int main() {
    Book book;
    std::cout << book.to_string() << "\n";

    std::cout << book.get_price() << "\n";
    std::cout << book.Item::get_price() << "\n\n";

    Pen pen;
    std::cout << pen.to_string() << "\n";
    std::cout << pen.get_price() << "\n";
    std::cout << pen.is_metal << "\n";

    Item item;
    // item = pen;
    std::cout << item.to_string() << "\n";
    std::cout << item.get_price() << "\n";
    // Doesn't work:
    // std::cout << item.is_metal << "\n";

    Item item2;

    // Incomplete implementatino that loses attributes
    std::vector<Item> inventory;
    inventory.push_back(book);
    inventory.push_back(pen);

    for (Item item : inventory) {
        std::cout << item.to_string() << "\n";
    }

    std::vector<Item*> realinventory;
    realinventory.push_back(&book);
    realinventory.push_back(&pen);
    realinventory.push_back(&item2);

    for (Item* item : realinventory) {
        std::cout << item->to_string() << "\n";
    }
}