#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <regex>

using namespace std;

// структура NOTE
struct NOTE
{
    int id;
    string name;
    string phone;
    short date[3];

    NOTE(
        int id,
        string &name,
        string &phone,
        const short day,
        const short month,
        const short year) : id(id), name(name), phone(phone), date{day, month, year} {}

    short day() const { return date[0]; }
    short month() const { return date[1]; }
    short year() const { return date[2]; }

    // перегрузка операторов сравнения,
    // чтобы структуры сравнивались по дате
    friend bool operator<(const NOTE &a, const NOTE &b)
    {
        int a_days = a.year() * 365 + a.month() * 31 + a.day();
        int b_days = b.year() * 365 + b.month() * 31 + b.day();

        return a_days < b_days;
    }

    friend bool operator>(const NOTE &a, const NOTE &b)
    {
        int a_days = a.year() * 365 + a.month() * 31 + a.day();
        int b_days = b.year() * 365 + b.month() * 31 + b.day();

        return a_days > b_days;
    }

    // перегрузка оператора вывода, чтобы печтать информацию о структуре
    friend ostream &operator<<(ostream &out, const NOTE &note)
    {
        out << "ID: " << note.id << "\n";
        out << "Name: " << note.name << "\n";
        out << "Phone number: " << note.phone << "\n";
        out << "Birthday: " << note.day() << "/" << note.month() << "/" << note.year() << "\n";

        return out;
    }
};

// функция чтение структер из фала
vector<NOTE> read_NOTES_from_file(string filePath)
{
    ifstream in(filePath);
    string line;
    const regex rdelim{","};
    vector<NOTE> notes;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            // формат записи "id,name,phone,day,month,year"
            // разбиваем строку по символам запятой
            vector<string> params{
                sregex_token_iterator(line.begin(), line.end(), rdelim, -1),
                sregex_token_iterator()};

            NOTE note = NOTE(
                stoi(params[0]),
                params[1],
                params[2],
                stoi(params[3]),
                stoi(params[4]),
                stoi(params[5]));

            notes.push_back(note);
        }
    }

    in.close();

    return notes;
}

// создание структуры пользователем через ввод из консоли
NOTE create_NOTE()
{
    cout << "Name: ";
    string name;
    getline(cin, name);
    cout << "Phone number: ";
    string phone;
    getline(cin, phone);
    cout << "Day: ";
    short day;
    cin >> day;
    cout << "Month: ";
    short month;
    cin >> month;
    cout << "Year: ";
    short year;
    cin >> year;
    cout << "ID: ";
    int id;
    cin >> id;
    NOTE note = NOTE(id, name, phone, day, month, year);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout.put('\n');

    return note;
}

// открывает файл и сохрнаяет данные о структурах в него
void save_NOTES_to_file(string filePath, vector<NOTE> &notes)
{
    // сортировка по дате
    std::sort(notes.begin(), notes.end());

    std::ofstream out;
    out.open(filePath);

    if (out.is_open())
    {
        for (NOTE note : notes)
        {
            out << note.id << "," << note.name << "," << note.phone << ','
                << note.day() << "," << note.month() << "," << note.year() << endl;
        }
    }
}

// функция нахождения NOTE по ID
void edit_NOTE_by_ID(vector<NOTE> &notes, int id)
{
    for (int i = 0; i < notes.size(); i++)
    {
        if (notes[i].id == id)
        {
            // выводим старую версию
            cout << "Old version.\n";
            cout << notes[i];

            // создаем новую версию
            cout << "New version.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // добавляем ее
            notes.push_back(create_NOTE());
            // удаляем старую
            notes.erase(notes.begin() + i);
            return;
        }
    }
}

// функция поиска по номеру телефона
void find_NOTE_by_phone(vector<NOTE> &notes, string phone)
{
    for (int i = 0; i < notes.size(); i++)
    {
        if (notes[i].phone == phone)
        {
            cout << "Find!\n";
            cout << notes[i];
            return;
        }
    }

    cout << "Not find.";
}

// функция отображения всех элементов
void show_NOTES(vector<NOTE> &notes)
{
    for (NOTE note : notes)
    {
        cout << note;
    }
}

int main()
{
    // создаем вектор и читаем из файла все элементы
    vector<NOTE> notes = read_NOTES_from_file("D:\\text.txt");

    // предлагаем пользователю выбор
    cout << "Select action:\n"
         << "[1] - Add new NOTE to file\n"
         << "[2] - Show all NOTES from file\n"
         << "[3] - Correct NOTE by ID\n"
         << "[4] - Find NOTE by phone\n";

    int select;
    cin >> select;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // исходя из его выбора, выполняем нужное действие
    switch (select)
    {
    case 1:
        notes.push_back(create_NOTE());
        break;
    case 2:
        show_NOTES(notes);
        break;
    case 3:
        cout << "ID: \n";
        int id;
        cin >> id;
        edit_NOTE_by_ID(notes, id);
        break;
    case 4:
        cout << "Phone: \n";
        string phone;
        getline(cin, phone);
        find_NOTE_by_phone(notes, phone);
    }

    // сохраняем все изменения в файл
    save_NOTES_to_file("D:\\text.txt", notes);
    return 0;
}
