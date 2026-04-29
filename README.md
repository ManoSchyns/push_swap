*This activity has been created as part of the 42 curriculum by mschyns, dle-gall*

# EN - push_swap

## Description

Push_swap is an algorithmic project whose goal is to sort a list of integers 
using two stacks (`a` and `b`) and a restricted set of operations, while 
minimizing the number of moves performed.

At startup, stack `a` contains the integers passed as arguments (with no 
duplicates) and stack `b` is empty. The goal is to sort stack `a` in 
ascending order using only the eleven authorized operations: `sa`, `sb`, 
`ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`. The program does 
not perform the sort itself: it computes and prints to standard output the 
sequence of operations needed to sort the stack.

This project emphasizes **algorithmic complexity**. Four sorting strategies 
are implemented, each belonging to a different complexity class measured in 
the number of Push_swap operations generated:

- **Simple** — O(n²): selection sort by minimum — locates the minimum of `a`, rotates it to the top, then pushes it onto `b`, repeats n times; then transfers everything back to `a` via `pa`.
- **Medium** — O(n√n): bucket sort — assigns a rank to each integer, distributes the n elements into √n buckets of size √n, transfers them group by group into `b` according to this rank, then retrieves successive maxima back to `a`.
- **Complex** — O(n log n): LSD radix sort — assigns a rank to each integer, performs log₂(n) bit-by-bit passes from least to most significant; on each pass, pushes elements whose bit is 0 onto `b`, then brings them back to `a`.
- **Adaptive** — dynamically selects the method based on the **disorder** of the stack (ratio of inversions over total pairs): **Simple** if disorder < 0.2, **Medium** if < 0.5, **Complex** otherwise. This is the default strategy.

The strategy can be forced at launch via the `--simple`, `--medium`, 
`--complex` or `--adaptive` options. A `--bench` mode additionally prints 
detailed metrics to standard error (disorder, chosen strategy, total 
operations, and breakdown by operation type).

Target performance objectives are:
- 100 integers: fewer than 700 operations for excellent performance.
- 500 integers: fewer than 5500 operations for excellent performance.

## Instructions

### Compilation

```bash
make        # compiles push_swap
make clean  # removes object files
make fclean # removes object files and the executable
make re     # recompiles from scratch
```

### Usage

```bash
./push_swap [options] <integers>
```

Integers can be provided as separate arguments or as a single string:

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

### Options

| Option | Effect |
|---|---|
| `--simple` | Forces the O(n²) algorithm |
| `--medium` | Forces the O(n√n) bucket sort |
| `--complex` | Forces the O(n log n) radix sort |
| `--adaptive` | Automatic selection based on disorder *(default)* |
| `--bench` | Prints metrics to stderr (disorder, strategy, total operations) |

### Checking the result

The output is a sequence of operations readable by the official checkers located in the `checker/` directory.

```bash
ARG="5 3 1 4 2" && ./push_swap $ARG | ./checker/fedora_checker $ARG
```

## Resources

**Bit manipulation**
- [Bit manipulation](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/) — introduction to the `&`, `|`, `^`, `~`, `<<`, `>>` operations
- Isolating the n-th bit of an integer: `(value >> n) & 1` — shifts the bits n positions to the right, then isolates the last bit with a `& 1` mask
- Counting the number of bits needed to represent n values: `floor(log₂(n)) + 1`, or via a loop `while (n >>= 1) bits++`

## Artificial Intelligence

AI (Claude) was used solely to help write this README.
No line of code in the project was generated or modified by AI.

---

# FR - push_swap

## Description

Push_swap est un projet d'algorithmie dont l'objectif est de trier une liste 
d'entiers en utilisant deux piles (`a` et `b`) et un ensemble restreint 
d'opérations, tout en minimisant le nombre de mouvements effectués.

Au démarrage, la pile `a` contient les entiers passés en arguments (sans 
doublon) et la pile `b` est vide. Le but est de trier la pile `a` par ordre 
croissant en n'utilisant que les onze opérations autorisées : `sa`, `sb`, 
`ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`. Le programme 
n'effectue pas le tri à proprement parler : il calcule et affiche sur la 
sortie standard la séquence d'opérations permettant de trier la pile.

Ce projet met l'accent sur la **complexité algorithmique**. Quatre stratégies 
de tri sont implémentées, chacune relevant d'une classe de complexité 
différente mesurée en nombre d'opérations Push_swap générées :

- **Simple** — O(n²) : selection sort par minimum — localise le minimum de `a`, le remonte en tête par rotations et le pousse dans `b`, répète n fois ; puis retransfère tout dans `a` via `pa`.
- **Medium** — O(n√n) : bucket sort — assigne un rang à chaque entier, répartit les n éléments en √n seaux de taille √n, transfère par groupe dans `b` selon ce rang, puis récupère les maxima successifs vers `a`.
- **Complex** — O(n log n) : radix sort LSD — assigne un rang à chaque entier, effectue log₂(n) passes bit par bit du moins significatif au plus significatif ; à chaque passe, pousse dans `b` les éléments dont le bit vaut 0, puis les rapatrie dans `a`.
- **Adaptive** — sélectionne dynamiquement la méthode selon le **désordre** de la pile (ratio d'inversions sur le total de paires) : **Simple** si désordre < 0.2, **Medium** si < 0.5, **Complex** sinon. C'est la stratégie par défaut.

La stratégie peut être forcée au lancement via les options `--simple`, 
`--medium`, `--complex` ou `--adaptive`. Un mode `--bench` permet en outre 
d'afficher sur la sortie d'erreur des métriques détaillées (désordre, 
stratégie choisie, total d'opérations et décompte par type d'opération).

Les objectifs de performance visés sont :
- 100 entiers : moins de 700 opérations pour une performance excellente.
- 500 entiers : moins de 5500 opérations pour une performance excellente.

## Instructions

### Compilation

```bash
make        # compile push_swap
make clean  # supprime les fichiers objets
make fclean # supprime les fichiers objets et l'exécutable
make re     # recompile de zéro
```

### Utilisation

```bash
./push_swap [options] <entiers>
```

Les entiers peuvent être fournis en arguments séparés ou en une seule chaîne :

```bash
./push_swap 5 3 1 4 2
./push_swap "5 3 1 4 2"
```

### Options

| Option | Effet |
|---|---|
| `--simple` | Force l'algorithme O(n²) |
| `--medium` | Force le bucket sort O(n√n) |
| `--complex` | Force le radix sort O(n log n) |
| `--adaptive` | Sélection automatique selon le désordre *(défaut)* |
| `--bench` | Affiche les métriques sur stderr (désordre, stratégie, total d'opérations) |

### Vérifier le résultat

La sortie est une séquence d'opérations lisible par les checkers officiels situés dans le dossier `checker/`. 

```bash
ARG="5 3 1 4 2" && ./push_swap $ARG | ./checker/fedora_checker $ARG
```

## Resources

**Manipulation de bits**
- [Manipulation des bits](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/) — introduction aux opérations `&`, `|`, `^`, `~`, `<<`, `>>`
- Isoler le bit n d'un entier : `(valeur >> n) & 1` — décale les bits de n positions vers la droite, puis isole le dernier bit avec un masque `& 1`
- Compter le nombre de bits nécessaires pour représenter n valeurs : `floor(log₂(n)) + 1`, ou par boucle `while (n >>= 1) bits++`

## Intelligence Artificielle

L'IA (Claude) a été utilisée uniquement pour aider à la rédaction et à la 
traduction de ce README.
Aucune ligne de code du projet n'a été générée ou modifiée par l'IA.