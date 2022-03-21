3 Puțină trigonometrie dezaburită 

Scopul este implementarea unei singure clase de la zero, în care vom include constructori, getteri, setteri, functii membre si operatori (nu sunt necesari, deoarece vom invata despre ei in laboratorul 4).
 

 
Unghiurile sunt folosit des în lumea reală - arhitectură, aranjamente florale, monitoare, pentru a nu aluneca laptopul de pe o masă înclinată, benzi de alergare etc). Precum majoritatea lucrurilor care au rezistat mult timp și măsurarea gradelor a trecut prin multe schimbări. Noi ne vom concentra pe două modalități clasice de a reprezenta unghiurile:
Grade sexazegimale, minute și secunde de arc. Sau mai simplu, componentele notației 15°6‘30“ (15 grade, 6 minute, 30 secunde)
Radiani (cel mai probabil mai ciudat definit.. Un radian este echivalent cu numărul de grade ale unui unghi care defineste un arc egal cu raza cercului:

 

 
Problema care apare odată cu notațiile multiple este că deși avem aplicații care fac calculele pentru noi, precum aplicații grafice diverse (CAD=Computer Aided Drawing, plotarea funcțiilor, crearea de animații) sau limbaje de programare diferite, notația poate să difere: de grad sexazegimal, ori notația de radiani, sau chiar notație centazimală (despre care nu discutăm. Este ciudat, dar unele persoane in design de drumuri folosesc 100 de grade la unghiul drept, 50 la unghi de 45 grade. Niciodata n-am inteles dramele astea :( ).
 
Clasa Angle va avea scopul ca, de îndată ce am implementat-o corect, aceste calcule și conversii să fie mult mai ușor de realizat.
 
 
Mai exact, clasa va putea fi folosită în aceste moduri:
 
Crearea de unghiuri
 
Angle a1 (23, 30, 10); // sexazegimal
Angle a2 (PI / 2); // unghi de 90 de grade, cu input in radiani
Angle a0; // exista si constructor default/neparametrizat

 
Hint: pe PI il puteti declara ca o constanta globala:
 
const double PI = 3.141592653589793; // sau acos(0) * 2;
 
Operatii pe unghiuri
 
Angle a3 = aduna(a1, a2); // unghiul a3 va avea 113 grade 30 minute 10 secunde
 
a3.print(); // afiseaza "113 30 10"
cout << a3.radians() << endl; // afiseaza aproximativ 1.9809971824 rad

 
Functii trigonometrice
 
cout << a2.cos() << endl; // va afisa 0

 
 
Indicii:
Scopul este ca instructiunile sa poate fi rulate iar afisarile sa coincida cu cele din comentariile de dupa fiecare instructiune in parte.
Important este sa luati pas cu pas fiecare instructiune.
Atentie ca puteti folosi functiile preimplementate in cmath pentru a calcula cos, dar ele au nevoie de radians ca input, deci va fi prima data nevoie de functia membra .radians() care calculeaza cati radiani are unghiul

Compunerea de clase
Vom crea o clasa Triunghi care va contine 3 unghiuri. Scopul vostru este sa creati o metoda simpla care primeste ca parametru lungimea celei mai mici dintre laturile triunghiului si răspunde la urmatoarele intrebari:

Care este unghiul opus celei mai mici laturi? (afișează valoarea unghiului)
Care sunt lungimile tuturor celor 3 laturi?
Care este aria triunghiului?
Triunghiul este ascutit unghic?

Inca o observatie. Suntem smart coders, daca vrem sa rezolvam asta vom crea cate o metoda pentru fiecare cerinta, ca in metoda care afiseaza toate aceste informatii sa le utilizam pe rand.
