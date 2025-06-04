# ArduinoPR4t
Automatització i modernització del centre

Objectius:
El nostre objectiu és juntament amb el redisseny estètic de les aules, modernitzar i automatitzar certs aspectes de l'espai educatiu. 

Accessos amb targeta, portes automàtiques, persianes automàtiques, nou equipament digital i la unificació del ja existent són opcions viables pel centre.

Idees mecàniques:
Idees possibles a escala física, és a dir, accionaments i coses amb les quals s’interactua de forma física poden ser:
Portes automàtiques amb accés amb targeta per professorat
Llums automàtiques i regulables (Llum o presència)

Idees digitals:
Idees possibles a l'àmbit digital del centre, coses que amb equipament o només programari es poden aconseguir:
Unificació de sistemes
Identificació única per cada alumne i professor (DNI o Usuari únic / Contrasenya)
Nivells d’accés per exemple
Nivell 1 (Alumne): Webs aprovades, aplicatius limitats, etc
Nivell 2 (Professors): Qualsevol web, aplicatius limitats, etc
Nivell 0 (Administradors): Accés complert
Millores a la infraestructura digital de certes aules

Finalment, farem el sistema de portes automàtiques juntament amb la Identificació Única i comuna a tot el centre, ja que són canvis poc costosos, útils i reproduïbles fàcilment a petita escala.

Com ho farem?
Sistema de portes automàtiques
El sistema de portes automàtiques consistirà en un accés amb targetes NFC, el protocol més típic en aquest tipus d’ús, ja que es pot xifrar la targeta per un plus de seguretat. 

Aquesta tecnologia també permet poder donar accés via telèfon mòbil, ja que és la mateixa tecnologia que utilitzen els pagaments “contactless” amb els que estem ja familiaritzats.
Quan el sistema detecti una targeta vàlida, aquest activarà un servomotor que obrirà la porta automàticament.

Per la maqueta a petita escala, com no disposem de lectors NFC i targetes, utilitzarem un sensor de proximitat per poder simular la lectura de la targeta. En una placa Arduino, farem un programari que, en detectar una targeta, aquest obrirà la porta movent un servomotor 90°:


El codi per fer-ho es bastant senzill:

*En l’inici del codi, comencem definint totes les variables, és a dir, donar valor o nom a certes dades que necessitarem després.
     
*La funció void loop() indica un bucle, codi que s’executarà indefinidament mentre la placa tingui corrent a la velocitat del seu microprocessador (16 mHz). Aquí tenim un condicional if, dins d'un altre, aquest dictamina que si l'estat del servo motor ha canviat, fer l’acció contrària, és a dir, si l'estat del servo motor és “obert” que faci l’acció de tancar i viceversa. Si això és complex, mira sí que té la targeta a prop, només un cop.

*Després, el programa senzillament fa que el servo canvi de posició.


