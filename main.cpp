#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <iomanip>

#ifdef _WIN32
    #include <windows.h>
    void set_utf8_console() {
        SetConsoleOutputCP(CP_UTF8);
    }
#else
    void set_utf8_console() {
        // nothing to do, console is already in utf-8
    }
#endif

using namespace std;

vector<string> load_voc_txt(string text_file) {
    string str;
    ifstream in(text_file);
    vector<string> voc_list;
    while (getline(in, str)) {
        if (!str.empty()) { voc_list.push_back(str); }
    };
    return voc_list;
}

vector<string> voc_german = load_voc_txt("./voc_german.txt");
vector<string> voc_english = load_voc_txt("./voc_english.txt");

string print_menu() {
    cout << "Vokabeltrainer" << endl;
    cout << "Bitte treffe eine Auswahl:" << endl;
    cout << "(1) Neue Vokabel hinzufügen" << endl;
    cout << "(2) Vokabeltest starten" << endl;
    cout << "(3) Vokabeln anzeigen" << endl;
    string option;
    cin >> option;
    return option;
}

void save_voc(string text_file, vector<string> voc) {
    ofstream output_fil(text_file);
    ostream_iterator<string> output_iterator(output_fil, "\n");
    copy(voc.begin(), voc.end(), output_iterator);
}

void ask_word() {
    cout << "Vokabeltest wird gestartet..." << endl;
    int random = rand() % voc_german.size();
    string sel_elem_german = voc_german[random];
    string sel_elem_english = voc_english[random];
    cout << "Bitte übersetze folgendes Wort: " + sel_elem_german << endl;
    string userInput;
    cin >> userInput;
    if (userInput == sel_elem_english) {
        cout << "Das ist richtig!" << endl;
    } else {
        cout << "Das ist leider falsch..." << endl;
    }
}

void list_words() {
    cout << "Es gibt insgesamt " + to_string(voc_german.size()) + " Wörter." << endl;
    for (size_t i = 0; i < voc_german.size(); i++) {
        cout << left << setw(12) << voc_german[i] << " - " << setw(12) << voc_english[i] << endl;
    }
}
int main() {
    set_utf8_console();

    string option = print_menu();

    if (option == "1") {
        cout << "Welche Vokabel? (Deutsch)" << endl;
        string word_german;
        string word_english;
        cin >> word_german;
        cout << "Wie lautet die Übersetzung?" << endl;
        cin >> word_english;

        voc_german.push_back(word_german);
        voc_english.push_back(word_english);

        save_voc("./voc_german.txt", voc_german);
        save_voc("./voc_english.txt", voc_english);

        cout << "Vokabel wurde hinzugefügt." << endl;
        cout << "Hinzugefügte Vokabeln: " + to_string(voc_german.size()) << endl;

    } else if (option == "2") {

        int i = 0;
        while(i < 10) {
            ask_word();
            i++;
        }
    } else {
        list_words();
    }

    return 0;
}
