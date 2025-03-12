# Proiect Simulare ATM

## Prezentare Generală
Acest proiect este o **simulare ATM în C++**, care permite utilizatorilor să retragă bani, să gestioneze tranzacții și să mențină o colecție de denominații disponibile. Utilizează **principii de programare orientată pe obiecte (OOP)**, cum ar fi clasele, moștenirea și gestionarea excepțiilor.

## Funcționalități
- **Retragere de bani**: Utilizatorii introduc suma dorită, iar sistemul sugerează opțiuni de plată valide.
- **Gestionarea tranzacțiilor**: Păstrează un istoric al tranzacțiilor efectuate.
- **Managementul colecției de monede**: Adaugă, elimină și urmărește monedele disponibile.
- **Gestionarea erorilor**: Utilizează excepții personalizate pentru a trata intrările invalide.

## Tehnologii
- **C++**
- **Structuri de date**

## Componente Principale
- **Atm.h / Atm.cpp**: Logica principală a ATM-ului, gestionarea retragerilor și a tranzacțiilor.
- **Collection.h / Collection.cpp**: Administrează monedele disponibile.
- **Tranzactie.h / Tranzactie.cpp**: Păstrează detaliile tranzacțiilor.
- **Vector.h / Vector.cpp**: Implementare a unei structuri dinamice de tip vector.
- **Pair.h / Pair.cpp**: Clasă ajutătoare pentru stocarea denominațiilor.
- **main.cpp**: Punctul de intrare al programului, gestionează interfața cu utilizatorul.
- **Tests.h / Tests.cpp**: Conține teste pentru sistem.
- **Except.h**: Clasă pentru gestionarea excepțiilor.

## Utilizare
1. **Rulează programul**.
2. **Alege o opțiune** din meniu:
   - `1` Retrage bani
   - `2` Afișează monedele disponibile
   - `3` Afișează istoricul tranzacțiilor
   - `0` Ieșire
3. **Urmează instrucțiunile de pe ecran** pentru a finaliza acțiunile.
