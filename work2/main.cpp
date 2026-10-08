#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day = 1, month = 1, year = 2000;
};

struct Reader {
    string name;
    int ticketNumber = 0;
    Date registrationDate;
    vector<string> takenBooks;
};

struct Stats {
    int total = 0;
    int withBooks = 0;
    double averageBooks = 0.0;
};

Stats calcStats(const vector<Reader>& readers) {
    Stats stats;
    stats.total = readers.size();

    int totalBooks = 0;
    for (const auto& r : readers) {
        if (!r.takenBooks.empty()) {
            stats.withBooks++;
            totalBooks += r.takenBooks.size();
        }
    }

    if (stats.total > 0) {
        stats.averageBooks = totalBooks / stats.total;
    }

    return stats;
}

void printReadersBeforeRegistered(const vector<Reader>& readers, int year) {
    cout << "Читатели, зарегистрированные до " << year << " года:\n";
    for (const auto& r : readers) {
        if (r.registrationDate.year < year) {
            cout << "- " << r.name << " (билет номер" << r.ticketNumber << ")\n";
        }
    }
}

bool addBookToReader(vector<Reader>& readers, int ticketNumber, const string& bookTitle) {
    for (auto& r : readers) {
        if (r.ticketNumber == ticketNumber) {
            r.takenBooks.push_back(bookTitle);
            cout << "Книга \"" << bookTitle << "\" выдана читателю " << r.name << "\n";
            return true;
        }
    }
    cout << "Читатель с билетом номер" << ticketNumber << " не найден\n";
    return false;
}


void printReader(const Reader& r) {
    cout << "Имя: " << r.name
    << ", билет: " << r.ticketNumber
    << ", зарегистрирован: " 
    << r.registrationDate.day << "."
    << r.registrationDate.month << "."
    << r.registrationDate.year << "\n";
    if (r.takenBooks.empty()) {
        cout << "  Книг на руках: нет\n";
    } else {
        cout << "  Книги на руках:\n";
        for (const auto& book : r.takenBooks) {
            cout << "    - " << book << "\n";
        }
    }
}

int main() {
    vector<Reader> readers = {
        {"Никита Халюткин", 101, {15, 3, 2022}, {}},
        {"Максим Зябликов", 102, {10, 6, 2023}, {"Война и мир"}},
        {"Вячеслав Овчинников", 103, {1, 1, 2021}, {"Преступление и наказание"}},
        {"Вениамин Зуев", 104, {20, 12, 2020}, {"Идиот"}},
        {"Шаюпов Дамир", 105, {5, 5, 2024}, {"Анна Каренина"}}
    };

    cout << "Список читателей\n";
    for (const auto& r : readers) {
        printReader(r);
        cout << "\n";
    }

    Stats stats = calcStats(readers);
    cout << "Статистика по читателям\n";
    cout << "Всего читателей: " << stats.total << "\n";
    cout << "Читателей с книгами: " << stats.withBooks << "\n";
    cout << "Среднее книг на читателя: " << stats.averageBooks << "\n\n";

    printReadersBeforeRegistered(readers, 2023);

    addBookToReader(readers, 102, "Евгений Онегин");
    addBookToReader(readers, 202, "какая то книжка");

    for (const auto& r : readers) {
        if (r.ticketNumber == 102) {
            printReader(r);
        }
    }

    return 0;
}