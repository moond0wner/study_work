#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double price = 0.0;
};

int main()
{

    vector<Book> books {
        {"War and Peace", "Лев Толстой", 1869, 500.0},
        {"Idiot", "Ф. Достоевский", 1869, 510.0},
        {"Dead Souls", "Н. Гоголь", 1842, 510.0}
    };
    sort(books.begin(), books.end(),
              [](const auto& a, const auto& b) { return a.price < b.price; });

    for (const auto& b : books)
        cout << b.title << " (" << b.author << ")" << " - " << b.price << "\n";
}

Book inputBook() {
    Book b;
    cout << "Введите название: ";
    getline(cin, b.title);   
    cout << "Введите автора: ";
    getline(cin, b.author);
    cout << "Введите год: ";
    cin >> b.year;
    cout << "Введите цену: ";
    cin >> b.price;
    
    return b;
}

void printBook(const Book& b) {
    cout << "Название: " << b.title << "\n"
              << "Автор: " << b.author << "\n"
              << "Год: " << b.year << "\n"
              << "Цена: " << b.price << " руб.\n";
}

void applyDiscount(Book& b, double percent) {
    if (percent < 0 || percent > 100) {
        cout << "процент должен быть от 0 до 100\n";
        return;
    }
    b.price *= (1 - percent / 100.0);
}