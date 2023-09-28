#include <iostream>  // Bibliothek für Ein- und Ausgabeoperationen
#include <string>    // Bibliothek für die Nutzung von Zeichenketten (strings)
#include <vector>    // Bibliothek für die Nutzung des vector Datentyps

using namespace std; // Erlaubt den Zugriff auf die Standardbibliotheksfunktionen von C++ ohne deren Namensraum zu spezifizieren

int main() { // Hauptfunktion, von der die Ausführung des Programms beginnt.

    vector<string> voc_german; // Vector zum Speichern der deutschen Vokabeln
    vector<string> voc_english; // Vector zum Speichern der englischen Vokabeln

    // Interaktion mit dem Benutzer über die Konsole
    cout << "Vokabeltrainer\n";
    cout << "Bitte treffe eine Auswahl:\n";
    cout << "(1) Neue Vokabel hinzufuegen\n";
    cout << "(2) Vokabeltest starten\n";

    string option; // String der die Benutzereingabe speichert
    cin >> option; // Eingabe des Benutzers wird in 'option' gespeichert

    // Überprüfung der Auswahl des Benutzers
    if (option == "1") { // Wenn der Benutzer "1" auswählt
        // Eingabeaufforderungen und Speichern der Vokabeln
        cout << "Welche Vokabel? (Deutsch)";
        string word_german;
        string word_english;
        cin >> word_german;
        cout << "Wie lautet die Uebersetzung?";
        cin >> word_english;
        //Bestätigungsnachricht zur erfolgreichen Hinzufügung
        cout << "Vokabel wurde hinzugefuegt.\n";
        cout << "Hinzugefuegte Vokabeln: " + to_string(voc_german.size());

        // Speicherung der neuen Vokabeln in den entsprechenden Vektoren
        voc_german.push_back(word_german);
        voc_english.push_back(word_english);

    } else if (option == "2") { // Wenn der Benutzer "2" auswählt
        // Nachricht zur Initialisierung des Tests
        cout << "Vokabeltest wird gestartet...";
    }

    // Das Programm wird beendet und gibt den Wert 0 zurück, was eine erfolgreiche Ausführung des Programms kennzeichnet.
    return 0;
}