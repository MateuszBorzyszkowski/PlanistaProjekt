# PlanistaProjekt
##Opis projektu: 
Jednym z zadań systemu operacyjnego jest przydział czasu procesora poszczególnym procesom. Napisz program realizujący prostego planistę.

Czas procesora powinien być przydzielany według następujących zasad:

- każdy proces może mieć wysoki, normalny lub niski priorytet,
- procesy i niższym priorytecie nie będą otrzymywały procesora, jeżeli istnieją procesy o priorytecie wyższym,
- procesy o takim samym priorytecie wykonywane są na przemian, w kolejności ich utworzenia,
- procesy można tworzyć, usuwać i zmieniać im priorytet,
- jeżeli w systemie nie ma żadnego procesu, wykonywany jest specjalny proces o nazwie idle.

Każdy proces jest jednoznacznie identyfikowany przez swój numer (dodatnia liczba całkowita, nie większa niż 231-1).

Jeżeli w systemie są 3 procesy (1, 2, 3) o normalnym priorytecie, to będą one wykonywane w kolejności 1, 2, 3, 1, 2, 3, ... . Jeżeli dodamy w tym momencie proces 4 o priorytecie wysokim, to kolejnymi wykonywanymi procesami będą: 4, 4, 4, ... .

Rozwiązanie wykorzystujące dynamiczne struktury danych (lista, lista cykliczna).
