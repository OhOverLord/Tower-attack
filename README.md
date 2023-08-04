Téma semestrální práce: **Tower attack**

Ve hře, kterou chci napsat hráč se snaží posílat vlny nepřátel do bludiště s cílem vyhnout se (příp. zničit) co největšímu počtu obraných věží nepřítele a dobýt jeho bázi.
Funkcionalita, kterou budu implementovat:
1.  Interakci věže vs útočníci (př. zničení útočníka, proběhnutí, zničení věže, …)
	1.  Alespoň 3 různé efekty pro věže (př. útok na nejbližší jednotku, na nejsilnější, zpomalení všech v okolí, …),
	2.  Alespoň 3 různé efekty pro útočníky (př. neviditelnost, létání, vyšší odolnost, …),
	3.  jedna věž může mít více efektů, jeden útočník může mít více efektů.
2.  Počítadlo skóre a detekci vítězství.
3.  AI řídící rozmisťování věží.
4.  Hra musí být konfigurovatelná ze souboru:
	1.  definice útočníků (př. název, cena, životy, rychlost, útok, odolnost, efekty, …),
	2.  definice věží (př. životy, dosah, útok, odolnost, efekty, …),
	3.  jednotlivé mapy (př. zdi, místa na stavění věží, …).
5.  Hra umožňuje ukládat a načítat rozehrané hry.

Kde budu používat polymorfismus:
-   efekty útočníků -  efekty budou mít společnou metodu použití
-   uživatelské rozhraní - různé obrazovky budou mít společnou metodu zobrazení obrazovek