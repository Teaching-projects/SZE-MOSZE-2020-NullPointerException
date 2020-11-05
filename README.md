# SZE-MOSZE-2020-NullPointerException

## NullPointerException RPG Game
### Alapinformációk
Ez a program a *Modern Szoftverfejlesztési Eszközök* című tantárgyhoz készült. A játék lényege, hogy két ellenség, a felhasználó által megadott paraméterekkel fog harcolni egymással. A játékban a hősök felváltva sebzik egymást. A játék győztese az, aki a sebzésével képes a másik hős életerejét 0-ra csökkenti. Minden karakternek van egy neve, életereje és támadási ereje. A játék folyamatosan fejlesztés alatt áll.
Programozási nyelv: C++ és Objektum orientált.

A csapattagok:
- Tóth Gergő
- Kovács Martin
- Hegedűs Róbert
    
------------
### Scenario file
    
A program egy `scenario` paramétert vár, ami tartalmazza a hős és a szörny(ek) paramétereit.<br><br>
`pelda_scenario.json`<br><br>
``` 
{
"hero" : "hos_neve.json",
"monsters" : " szorny1.json szorny2.json szorny3.json "
}
``` 
<br>
Ezt beolvasva a program inicializálja a hős adatait és a szörny(ek) tulajdonságait.<br>

### Hős file
A `hero` fájlnak az alábbiként kell kinézzen:<br><br>
`hos_neve.json`
``` 
{
"name" : "Hősnév",
"base_health_points" : 30,
"base_damage" : 3,
"base_attack_cooldown" : 1.1,
"experience_per_level" : 20,
"health_point_bonus_per_level" : 5,
"damage_bonus_per_level" : 1,
"cooldown_multiplier_per_level": 0.9
}
``` 
<br>
A `hero` képes szintet lépni, és XP-t gyűjteni. Ennek a vonzata, hogy megnő az életereje, a sebzése és az ütési sebessége szintenként. Ezek pontos paramétereit be lehet állítani az adott hős JSON fájljában.<br>

### Monster file
A `monsters` fájl(ok)nak az alábbiként kell kinézzen: <br><br>
`szorny1.json`<br><br>
``` 
{
"lore" : "Rövid leírás a szörnyről.",
"name" : "Monster",
"health_points" : 10, 
"damage" : 1, 
"attack_cooldown" : 2.8,
"race" : "undead"
}
``` 
<br>
A `monsters` a `hero` hoz képest nem képes a szintlépésre és az XP gyűjtésre, ezáltal nem tudja növelni a tulajdonságait.Egyszerűbb targetek a hősöknek.<br>

------------

### Futtatása és egyéb tulajdonságok
A játékot először le kell fordítani egy c++ fordítóval.<br>
`g++-10 -std=c++17 *.cpp -lstdc++fs` <br>
Példa a két karakter betöltéséhez:
`./a.out scenario1.json`
A JSON fileból kinyert hőst és szörny(ek)et a program betölti, inicializálja a tulajdonságait, majd megkezdi a harcot.

Github-pages link:
[https://teaching-projects.github.io/SZE-MOSZE-2020-NullPointerException/](https://teaching-projects.github.io/SZE-MOSZE-2020-NullPointerException/)
