# Project-PCP

#https://online.visual-paradigm.com/w/zugwtwny/diagrams/#diagram:workspace=zugwtwny&proj=0&id=2

#Hra bude strategie ve stylu SimCity, Travian, Transport Tycoon atp. Může byýt real-time nebo tahově založená. Základem bude herní plocha o velikosti MxN polí. Na každém poli může stát budova a/nebo jednotka. Hráč bude mít určité množství surovin a dalších zdrojů, které mu umožní vytvářet budovy a jednotky. Budovy i jednotky je možné vylepšovat (lepší vlastnostnosti, vybavení atp.) Jednotky mohou nést předměty, které zlepšují jejich schopnosti. Smyslem hry je s omezenými zdroji postavit co největší město, železniční síť atp. Pro logování chyb a problémů bude použita speciální třída, která bude obsahovat unikátní seznam všech chyb a bude umožňovat jejich vypsání atp. Hru bude možné uložit do souboru a načíst ze souboru.
 
#Hra bude celá grafická. To znamená, že bude ve finále pomocí QML vykreslena herní deska na kterou bude užovatel klikat a uvidí informace o jednotkách, bude je přesunovat atp. Celý "backend" hry tedy musí být událostně řízený. To znamená, že nemá smysl pro "textovou" část hry psát nějaké herní smyčky atp. Je potřeba si nachystat třídy, které budou umět reagovat na prosté příkazy typu vytvoř novou jednotku, vrat seznam jednotek atp.
 
#Hra bude dělána ve trojcích (ne, nemůžete to dělat sami). Hra bude průběžně ukládána do Gitu, nebudou přijmuty projekty, které se zmaterializovali během několika málo commitů. Takové projekty, které mají commity pouze/převážně od jednoho studenta. Tomuto studentu pak budou přiřazeny veškeré body za projekt. Musíte tedy pracovat na projektu separátně a oba kód do Git commitovat za sebe. Pokud při práci narazíte na problém s kolegy, který si nebudete schopni sami vyřešit, kontaktujte mě!
 
#Hra bude průběžně obhajovaná. První obhajoba bude nad základem GUI v QML a metodami na backendu, které umožní herní plochu načíst ze souboru a uložit do něj. (10 bodů) Tato obhajobu bude v posledních dvou týdnech semestru. Druhá bude finální obhajoba celého projektu ve zkouškovém období. (15 bodů)


