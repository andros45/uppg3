#include <iostream>
#include <vector>

using namespace std;

void lasPoang(string amnen [], int poang [], int n){

    // Metoden tar med sig arrayerna ämnen och string
    int poangen;

    for (int i = 0; i < n; i++){
        cout << "Mata in po\x84ngen mellan 0-100 f\x94r " << amnen[i] << ": ";
        cin >> poangen;
        poang[i] = poangen;
    }
}

// Metod för att omvandla sifferbetyg till bokstavsbetyg enligt följande regler
// 90 < poäng <= 100 = 'A'
// 80 < poäng <= 90 = 'B'
// 70 < poäng <= 80 = 'C'
// 60 < poäng <= 70 = 'D'
// 50 <= poäng <= 60 = 'E'
// poäng <= 50 = 'F'

void omvandlaBetyg(string amnen [], int poang [], int n, char betyg []) {

    // Gå igenom vektorn med poäng och skapa motsvarande betyg i en ny vektor
    for (int i = 0; i < n; i++){
        if (poang[i] > 90) {
            betyg[i] = 'A';
        } else if (poang[i] > 80) {
            betyg[i] = 'B';
        } else if (poang[i] > 70) {
            betyg[i] = 'C';
        } else if (poang[i] > 60) {
            betyg[i] = 'D';
        } else if (poang[i] > 50) {
            betyg[i] = 'E';
        } else {
            betyg[i] = 'F';
        }
    }
}

void skrivUtBetyg(string amnen [], int poang [], int n, char betyg []) {
    
    // Skriv ut betygen vi har lagrat i våra arrayer
    for (int i = 0; i < n; i++){
        cout << "\n" << betyg[i] << " - " << poang[i] << " i " << amnen[i];
    }    
    cout << "\n";
}

void Statistik(string amnen [], int poang [], int n, char betyg []) {
    // Räkna ihop alla bokstavsbetyg för varje bokstav
    // Alltså hur många A, hur många B, hur många C osv
    // Vi skapar en array där vi kan lagra detta
    int betygAntal[5];

    // Skapa en variabel där vi räknar ihop totala betygspoängen
    int totBetyg = 0;

    // Nollställ alla värden i arrayen
    for (int i = 0; i < n+1; i++){
        betygAntal[i] = 0;
    }

    for (int i = 0; i < n; i++){
        switch (betyg[i]) {
            case 'A':
                betygAntal[0]++;
                break;
            case 'B':
                betygAntal[1]++;
                break;
            case 'C':
                betygAntal[2]++;
                break;
            case 'D':
                betygAntal[3]++;
                break;
            case 'E':
                betygAntal[4]++;
                break;
            case 'F':
                betygAntal[5]++;
                break;
            default:
                cout << "Felaktigt betyg hittat i arrayen! Avbryter...";
                break;
        }
    }

    // Skriv ut antalet av alla betyg
    cout << "\nAntal betyg 'A': " << betygAntal[0];
    cout << "\nAntal betyg 'B': " << betygAntal[1];
    cout << "\nAntal betyg 'C': " << betygAntal[2];
    cout << "\nAntal betyg 'D': " << betygAntal[3];
    cout << "\nAntal betyg 'E': " << betygAntal[4];
    cout << "\nAntal betyg 'F': " << betygAntal[5];

    // Räkna ihop alla betygspoäng
    for (int i = 0; i < n; i++){
        totBetyg = totBetyg + poang[i];
    }

    // Skriv ut totala betygspoängen
    cout << "\n\nDen totala betygspo\x84ngen \x84r: " << totBetyg << " po\x84ng.\n\n";

    // Skriv ut medelbetyget
    cout << "Medelbetyget \x84r: " << (totBetyg / n) << " po\x84ng.\n\n";

    // Skriv ut en kommentar beroende på hur bra medelbatyget är
    if(totBetyg / n > 90) {
        cout << "Riktigt bra betyg!!! Ett framtida geni?";
    } else if (totBetyg / n > 75) {
        cout << "Ojd\x86! Det var inga d\x86liga betyg!";
    } else if (totBetyg / n > 50) {
        cout << "Bra betyg! \x99ver medel!";
    } else if (totBetyg / n > 30) {
        cout << "Nja... Lite b\x84ttre borde det kunna vara. K\x84mpa p\x86!";
    } else {
        cout << "Hmm... Inga h\x94jdarbetyg direkt. Ryck upp dig!!!";
    }

    cout << "\n\n";

}


int main(void){

    string amnen [5] = {"Matematik","Svenska","Engelska","Historia","Fysik"};
    int poang [5];
    char betyg[6];

    int antal = 0;

    // Ta reda på storleken på array 'amnen'
    for(string s: amnen)
        antal++;
    
	// Rensa skärmen
	cout << "\033[2J\033[1;1H";

    // Skriv ut ett välkomstmeddelande
	cout << "\n\nHej och v\x84lkommen till BetygStatistik!\n\n";

	// Läs in poängen
    lasPoang(amnen, poang, antal);

    // Skapa en array med omvandlade betyg
    omvandlaBetyg(amnen, poang, antal, betyg);

    // Skriv ut alla betyg
    skrivUtBetyg(amnen, poang, antal, betyg);

    // Skriv ut statistik för alla betyg
    Statistik(amnen, poang, antal, betyg);

	return 0;
}