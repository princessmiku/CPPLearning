#include <iostream>    // Bibliothek für Ein- und Ausgabeoperationen
#include <string>      // Bibliothek für die Verwendung von Zeichenketten (strings)
#include <vector>      // Bibliothek für die Verwendung des Vektordatentyps
#include <fstream>     // Bibliothek für Dateioperationen
#include <iterator>    // Bibliothek für die Verwendung von Iteratoren

using namespace std; // Erlaubt den direkten Zugriff auf die Standardbibliotheksfunktionen ohne ihren Namensraum zu spezifizieren.

int main() { // Hauptfunktion, von der die Ausführung des Programms beginnt.

    vector<string> voc_german; // Vektor zum Speichern der deutschen Vokabeln.
    vector<string> voc_english; // Vektor zum Speichern der englischen Vokabeln.

    // Erstellen Sie Dateistreams, um Deutsche- und Englisch-Vokabeldateien zu lesen
    ifstream in_german("../voc_german.txt");
    ifstream in_english("../voc_english.txt");

    string str;
    // lesen Sie die Vokabeln aus der Datei und speichern Sie sie im Vektor
    while (getline(in_german, str)) {
        if (str.size() > 0) { voc_german.push_back(str); }
    };
    while (getline(in_english, str)) {
        if (str.size() > 0) { voc_english.push_back(str); }
    };

    // Interaktion mit dem Benutzer über die Konsole
    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) Neue Vokabel hinzufuegen\n";
    cout << "(2) Vokabeltest starten\n";

    string option;
    cin >> option;

    if (option == "1") { // Wenn der Benutzer "1" auswählt
        cout << "Welche Vokabel? (Deutsch)";
        string word_german;
        string word_english;
        cin >> word_german;
        cout << "Wie lautet die Uebersetzung?";
        cin >> word_english;

        // Hinzufügen neuer Vokabeln zu den entsprechenden Vektoren
        voc_german.push_back(word_german);
        voc_english.push_back(word_english);

        cout << "Vokabel wurde hinzugefuegt.\n";
        cout << "Hinzugefuegte Vokabeln: " + to_string(voc_german.size());

        // Speichern Sie die deutschen und englischen Vokabellisten in den entsprechenden Dateien
        ofstream output_file_german("../voc_german.txt");
        ostream_iterator<string> output_iterator_german(output_file_german, "\n");
        copy(voc_german.begin(), voc_german.end(), output_iterator_german);

        ofstream output_file_english("../voc_english.txt");
        ostream_iterator<string> output_iterator_english(output_file_english, "\n");
        copy(voc_english.begin(), voc_english.end(), output_iterator_english);
    } else if (option == "2") {  // Wenn der Benutzer "2" auswählt
        cout << "Vokabeltest wird gestartet...";
    }

    return 0; // Gibt 0 zurück, um dem Betriebssystem zu signalisieren, dass das Programm erfolgreich ausgeführt wurde.
}