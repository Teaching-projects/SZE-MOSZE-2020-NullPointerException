# SZE-MOSZE-2020-NullPointerException

## NullPointerException RPG Game
### Alapinformációk
Ez a program a *Modern Szoftverfejlesztési Eszközök* című tantárgyhoz készült. A játék lényege, hogy két ellenség, a felhasználó által megadott paraméterekkel fog harcolni egymással. A játékban a hősök felváltva sebzik egymást. A játék győztese az, aki a sebzésével képes a másik hős életerejét 0-ra csökkenti. Minden karakternek van egy neve, életereje és támadási ereje. A játék folyamatosan fejlesztés alatt áll.
Programozási nyelv a C++ és Objektum orientált.

A csapattagok:
- Tóth Gergő
- Kovács Martin
- Hegedűs Róbert

------------


### Futtatása
A játékot először le kell fordítani egy c++ fordítóval. Az alábbi egy fordítási példa:<br>
    `g++ -std=c++17 main.cpp Hero.cpp` <br>
A karaktereket, két JSON típusú fájlból beolvasva inicializálja.
Példa a két karakter betöltéséhez:
`./a.out hulk.json ironman.json`
A JSON fájlból kinyert karakter nevet, életerőt és sebzést, a program elkezdi a két karakter közötti harc szimulációját.

Github-pages link:
[https://teaching-projects.github.io/SZE-MOSZE-2020-NullPointerException/](https://teaching-projects.github.io/SZE-MOSZE-2020-NullPointerException/)
