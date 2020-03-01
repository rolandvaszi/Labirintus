# Labirintus

Ebben a backtracking problémában a főszereplőnk egy egér, aki a legrövidebb úton szeretné elérni a sajtot a labirintusban.
Az egér kezdeti helyzete a bal felső sarok. 
A feladat megoldásához két fajta módszert alkalmaztunk: 
- két irányú bejárás (le és balra), ahol egy üres labirintusban menti az útvonalat
- négy irányú bejárás (balra, jobbra, fel és le), itt ugyanaz a labirintus formálódik, vagyis a rossz útvonalak eltünnek

A feladat opciói: 
- első argumentum a txt fájl ami a labirintus méretét és magát a labirintust tartalmazza
- a második argumentum a módszer kiválasztása (1 - két irányú, 2 - négy irányú)
Példa meghívás MinGW kompilátor esetében: .\Labirintus.exe be2.txt 1

Mindkét esetben számolódnak a lépések és az eredmény egy mátrix, amely az optimális útvonalat jelöli. 

Készítették: Gábor-Lukács Zoltán, Vaszi Imre-Roland
