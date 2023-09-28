#include <iostream>  // Bibliothek die Funktionen für Ein- und Ausgabeoperationen bereitstellt.
#include <string>    // Bibliothek für die Nutzung von Zeichenketten (strings)

// Erlaubt den Zugriff auf die Standardbibliotheksfunktionen von C++ ohne deren Namensraum zu spezifizieren.
using namespace std;

int main() { // Hauptfunktion, von der die Ausführung des Programms beginnt.

    // Deklaration und Initialisierung der Variablen.
    string name = "Mia"; // string Variable für den Namen.
    int birth_year = 2000; // integer Variable für das Geburtsjahr.

    // Berechnung des Alters durch Subtraktion des Geburtsjahres von 2022.
    int age = 2022 - birth_year;

    // Ausgabe auf der Konsole.
    // "to_string()" wird zur Konvertierung des integer-Werts Alter in einen String verwendet, sodass er mit anderen Strings verbunden werden kann.
    cout << "Hallo " + name + ", wie geht es dir? Bist du ungefähr " + to_string(age) + " Jahre alt?";

    // Rückgabe von 0, um dem Betriebssystem mitzuteilen, dass das Programm erfolgreich ausgeführt wurde.
    return 0;
}