# Get Next Line — explications du projet

Ce document se base sur le sujet fourni, version 14.3. Il explique les exigences sans fournir le code de la solution.

## Objectif

Écrire `char *get_next_line(int fd);` : chaque appel renvoie la prochaine ligne lue depuis le descripteur `fd`.

La fonction doit fonctionner avec un fichier et avec l’entrée standard. Le projet fait travailler `read`, les chaînes C, la mémoire dynamique et les variables statiques.

## Descripteur de fichier

Un descripteur est un entier identifiant une ressource ouverte dans le processus. Ce n’est ni le nom du fichier ni son contenu.

`0` correspond à l’entrée standard, `1` à la sortie standard et `2` à la sortie d’erreur standard. Le descripteur `0` doit donc être accepté. Un entier positif ne garantit pas qu’un descripteur est valide ou lisible.

## Valeurs de retour de GNL

| Retour | Signification |
|---|---|
| Pointeur vers une chaîne | Une ligne a été obtenue |
| `NULL` | Plus rien à lire, ou erreur |

Le `\n` doit être inclus lorsqu’il existe. La dernière ligne doit aussi être retournée si le fichier se termine sans `\n`.

| Contenu du fichier | Retours successifs |
|---|---|
| Fichier vide | `NULL` |
| `Bonjour` | `"Bonjour"`, puis `NULL` |
| `Bonjour\n` | `"Bonjour\n"`, puis `NULL` |
| `Bonjour\n42\nFin` | `"Bonjour\n"`, `"42\n"`, `"Fin"`, puis `NULL` |
| `\n` | `"\n"`, puis `NULL` |
| `\n\n` | `"\n"`, `"\n"`, puis `NULL` |

Une ligne vide est `"\n"`, pas `NULL`. Un saut de ligne final ne crée pas une ligne supplémentaire.

Une chaîne C se termine par `\0`. Ce terminateur est différent de `\n`, qui représente un caractère du texte.

La ligne retournée doit rester valide après le retour de la fonction. Le programme appelant doit libérer chaque ligne allouée après utilisation. L’interface ne permet pas à elle seule de distinguer une erreur de la fin du fichier.

## Fonctions externes autorisées

| Fonction | Rôle | Retour |
|---|---|---|
| `read` | Lire des octets | Nombre d’octets lus, `0` ou `-1` |
| `malloc` | Allouer de la mémoire | Adresse obtenue ou `NULL` |
| `free` | Libérer une allocation | Aucun retour |

Tu peux écrire tes propres fonctions auxiliaires. Tu ne peux pas appeler directement `strlen`, `strchr`, `realloc`, `calloc` ou `memcpy`, par exemple.

Le sujet interdit la libft, `lseek` et les variables globales. Une variable statique locale à une fonction est autorisée ; une variable au niveau du fichier reste interdite ici, même déclarée `static`.

Un programme de test séparé peut utiliser `open`, `close` ou `printf`. Cela ne les rend pas autorisés dans l’implémentation de GNL.

## Bien comprendre `read`

| Retour de `read` | Signification |
|---|---|
| Positif | Nombre d’octets réellement lus |
| `0` | Fin de lecture |
| `-1` | Erreur |

Le retour est de type `ssize_t`, un type signé capable de représenter `-1`.

`read` ne connaît pas les lignes : une lecture peut récupérer une partie de ligne ou plusieurs lignes. Il n’ajoute pas de `\0`. Une lecture positive plus courte que la quantité demandée ne prouve pas que la fin est atteinte.

La lecture avance la position du descripteur. Les données déjà lues ne seront pas automatiquement relues à l’appel suivant.

## `BUFFER_SIZE`

`BUFFER_SIZE` détermine la taille du tampon de lecture, pas la taille maximale d’une ligne.

Une ligne peut demander plusieurs lectures. Une lecture peut contenir plusieurs lignes.

Le sujet donne cette forme de compilation, où `<files>.c` représente les fichiers à compiler :

```text
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

Le projet doit aussi compiler sans `-D BUFFER_SIZE=...` : il faut une valeur par défaut remplaçable à la compilation.

Le sujet cite les valeurs `1`, `9999` et `10000000`. Le résultat doit rester identique malgré les différences de coût et de mémoire.

Une valeur nulle ou négative est un cas de robustesse à anticiper, notamment pour éviter une boucle infinie ou une allocation incohérente.

## Pourquoi conserver un état ?

Si une lecture récupère `Bonjour\nSalut\n`, le premier appel ne doit renvoyer que `Bonjour\n`. Pourtant, `Salut\n` a déjà été lu. Il faut le conserver pour le prochain appel.

Une variable locale ordinaire ne conserve pas sa valeur entre deux appels. Une variable locale `static` conserve son état pendant l’exécution et n’est initialisée qu’une fois.

Attention : la durée de vie d’un pointeur est différente de celle de la mémoire pointée. Un pointeur statique peut contenir une adresse devenue invalide après un `free`.

La question centrale est : quels octets ont été lus mais pas encore retournés ?

## Lire seulement ce qui est nécessaire

Le sujet demande de renvoyer une ligne dès qu’elle est disponible, sans continuer inutilement les lectures. Il ne faut pas lire tout le fichier avant de commencer à retourner les lignes.

Il est normal qu’une lecture dépasse un `\n`, puisque `read` travaille par blocs. Le surplus doit être conservé. Si ce surplus contient déjà une ligne complète, il n’est pas nécessaire de lire davantage pour l’obtenir.

## Pièges importants

- **Dernière ligne sans `\n` :** même si `read` renvoie `0`, du texte déjà lu peut encore être à retourner.
- **Plusieurs lignes par lecture :** ne perdre ni dupliquer aucun caractère du surplus.
- **Ligne longue :** la fin du tampon ne marque pas la fin de la ligne.
- **Frontières :** tester un `\n` juste avant, sur et après une frontière de lecture.
- **Terminateur :** prévoir la place du `\0` en plus des caractères du texte.
- **Mémoire :** savoir qui possède chaque allocation et qui la libère.
- **Erreurs :** gérer les échecs de lecture et d’allocation, même après d’autres allocations.
- **Descripteur `0` :** ne pas rejeter l’entrée standard.
- **Performances :** recopier tout le texte accumulé à chaque lecture peut devenir très coûteux avec une longue ligne et un petit tampon.

Les fuites, doubles libérations, accès après libération et dépassements mémoire sont à éviter sur tous les chemins d’exécution.

Le sujet indique un comportement indéfini pour la lecture de fichiers binaires et si le fichier est modifié entre les appels alors que `read` n’a pas encore atteint sa fin.

## Livrables obligatoires

À la racine du dépôt :

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
README.md
```

Le header doit contenir au minimum le prototype de GNL. Les fonctions auxiliaires doivent être placées dans `get_next_line_utils.c`.

Il faut respecter la Norm et compiler avec `-Wall -Wextra -Werror`. Les plantages et les fuites mémoire ne sont pas acceptés.

La liste spécifique des livrables de GNL n’impose pas explicitement de Makefile. Les règles générales sur les Makefiles s’appliquent lorsqu’un Makefile est requis.

Ce document explicatif ne remplace pas le README demandé.

## README exigé dans cette version

Il doit contenir :

- La première ligne imposée, en italique, adaptée à ton login : « This project has been created as part of the 42 curriculum by <login1>[, <login2>[, <login3>[...]]]. »
- Une section `Description` présentant le projet.
- Une section `Instructions` pour la compilation et l’utilisation.
- Une section `Resources` donnant les références et précisant pour quelles tâches et parties du projet l’IA a été utilisée.
- Une explication détaillée et une justification de l’algorithme retenu.

L’anglais est recommandé ; la langue principale du campus est également acceptée.

## Bonus

Les bonus exigent une seule variable statique et la gestion de plusieurs descripteurs en alternance, chacun avec son état indépendant.

Lire depuis le descripteur 3, puis 4, puis à nouveau 3 doit reprendre au bon endroit sans mélanger les lignes.

Fichiers supplémentaires à la racine :

```text
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
```

Les bonus ne sont évalués que si la partie obligatoire est entièrement fonctionnelle.

## Tests à préparer

| Cas | Vérification |
|---|---|
| Fichier vide | `NULL` immédiat |
| Un caractère sans `\n` | Dernière ligne conservée |
| Un seul `\n` | Ligne vide |
| Plusieurs `\n` consécutifs | Aucune ligne perdue |
| Fin avec et sans `\n` | Traitement de la dernière ligne |
| Ligne beaucoup plus longue que le tampon | Lectures multiples |
| Plusieurs lignes dans le tampon | Conservation du surplus |
| `\n` aux frontières du tampon | Calcul des limites |
| Appels répétés après la fin | Retour `NULL` stable |
| Descripteur invalide | Gestion d’erreur |
| Entrée standard | Prise en charge de `0` |
| Compilation sans définition de `BUFFER_SIZE` | Valeur par défaut |
| Tampons de tailles très différentes | Indépendance du résultat |
| Grande ligne avec petit tampon | Performances et mémoire |
| Alternance entre descripteurs pour le bonus | Indépendance des états |

Vérifie le contenu exact, les `\n`, la terminaison des chaînes et la mémoire. Un affichage correct ne prouve pas l’absence de fuite ou de dépassement.

## Comprendre pour l’évaluation

Tu dois pouvoir expliquer la différence entre une lecture et une ligne, les retours de `read`, les rôles de `\n`, `\0` et `NULL`, les données conservées entre les appels, la propriété de chaque allocation et la gestion des erreurs.

Le sujet précise qu’une petite modification peut être demandée à l’évaluation pour vérifier ta compréhension.

Le point de départ : **`read` récupère des blocs d’octets ; GNL fournit des lignes. Ces deux découpages ne coïncident pas forcément.**
