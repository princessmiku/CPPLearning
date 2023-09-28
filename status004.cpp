#include <iostream> //Für die Ein- und Ausgabe von Daten
#include <string> //Für die Verwendung von Zeichenketten
#include <vector> //Für die Verwendung von Vektoren
#include <fstream> //Für das Lesen und Schreiben in Dateien
#include <iterator> //Für die Verwendung von Iteratoren

using namespace std;

//Funktion, die das Menü in der Konsole ausgibt und die Nutzereingabe zurückgibt
string print_menu() {
    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) Neue Vokabel hinzufuegen\n";
    cout << "(2) Vokabeltest starten\n";
    string option;
    cin >> option; //Eingabe des Benutzers wird gelesen
    return option; //Eingabe des Benutzers wird zurückgegeben
}

//Funktion, die Vokabeln aus einer Textdatei lädt und in einem Vektor speichert
vector<string> load_voc_txt(string text_file) {
    string str; //Zeichenkette für den aktuellen Eintrag in der Datei
    ifstream in(text_file); //Dateistream für die Eingabedatei
    vector<string> voc_list; //Vektor für die Speicherung der Vokabeln aus der Datei
    //Liest jede Zeile der Datei
    while (getline(in, str)) {
        if (!str.empty()) {
            voc_list.push_back(str); //Fügt die gelesene Zeile zum Vektor hinzu, wenn sie nicht leer ist
        }
    };
    return voc_list; //Gibt den Vektor mit den Vokabeln zurück
}

// Funktion, die Vokabeln in eine Textdatei speichert
void save_voc(string text_file, vector<string> voc) {
    ofstream output_fil(text_file); //Dateistream für die Ausgabedatei
    ostream_iterator<string> output_iterator(output_fil, "\n"); //Iterator für die Ausgabe in der Datei
    copy(voc.begin(), voc.end(), output_iterator); //Kopiert alle Elemente aus dem Vokabularvektor in die Datei
}

// Funktion, die ein Wort abfragt und prüft, ob die Benutzereingabe korrekt ist
void ask_word(vector<string> voc_german, vector<string> voc_english) {
    cout << "Vokabeltest wird gestartet...\n";
    int random = rand() % voc_german.size(); //Generiert eine zufällige Zahl zwischen 0 und der Größe des deutschen Vokabelvektors
    string sel_elem_german = voc_german[random]; //Wählt das deutsche Wort an der zufällig generierten Position aus
    string sel_elem_english = voc_english[random]; //Wählt das englische Wort an der zufällig generierten Position aus
    cout << "Bitte uebersetze folgendes Wort: " + sel_elem_german + ": ";
    string userInput;
    cin >> userInput; //Liest die Benutzereingabe
    //Überprüft, ob die Benutzereingabe mit dem englischen Wort übereinstimmt
    if (userInput == sel_elem_english) {
        cout << "Das ist richtig!\n"; //Gibt aus, dass die Antwort richtig ist, wenn die Worte übereinstimmen
    } else {
        cout << "Das ist leider falsch...\n"; //Gibt aus, dass die Antwort falsch ist, wenn die Worte nicht übereinstimmen
    }
}


// Hauptfunktion
int main() {
    //Lädt die deutschen und englischen Vokabeln aus den Dateien in die Vokabelvektoren
    vector<string> voc_german = load_voc_txt("./voc_german.txt");
    vector<string> voc_english = load_voc_txt("./voc_english.txt");

    string option = print_menu(); //Ruft das Menü auf und speichert die Benutzereingabe

    if (option == "1") {
        //Option 1: Neue Vokabel hinzufügen
        cout << "Welche Vokabel? (Deutsch)";
        string word_german;
        string word_english;
        cin >> word_german; //Das neue deutsche Wort lesen
        cout << "Wie lautet die Uebersetzung?";
        cin >> word_english; //Die Übersetzung lesen

        //Fügt die neuen Worte zu den Vokabelvektoren hinzu
        voc_german.push_back(word_german);
        voc_english.push_back(word_english);

        //Speichert die aktualisierten Vektoren in den Dateien
        save_voc("./voc_german.txt", voc_german);
        save_voc("./voc_english.txt", voc_english);

        //Gibt aus, dass die Vokabel hinzugefügt wurde und wie viele Vokabeln jetzt vorhanden sind
        cout << "Vokabel wurde hinzugefuegt.\n";
        cout << "Hinzugefuegte Vokabeln: " + to_string(voc_german.size()) + "\n";

    } else {
        //Option 2: Vokabeltest starten
        int i = 0;
        while(i < 10) { //Stellt 10 Fragen
            ask_word(voc_german, voc_english); //Fragt ein Wort ab
            i++; //Zählt den Fragezähler hoch
        }
    }

    return 0; //Beendet das Programm
}