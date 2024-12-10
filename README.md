# get-next-line
get_next_line

## Description

Le projet `get_next_line` implémente une fonction en C qui lit une ligne à partir d'un fichier ou de l'entrée standard. Cette fonction permet de récupérer les lignes d'un fichier, une par une, en gérant correctement la mémoire et les fichiers ouverts.

## Fonctionnalités

- Lire une ligne complète à chaque appel de `get_next_line()`.
- Supporte plusieurs fichiers ouverts simultanément.
- La ligne est retournée sous forme de chaîne de caractères, sans le caractère de nouvelle ligne (`\n`).
- Gère correctement la mémoire allouée pour chaque ligne lue.

## Installation

### Prérequis

- Un compilateur C (par exemple, GCC).
- Le projet utilise les bibliothèques standard de C.

### Compilation

Pour compiler le projet, exécutez la commande suivante dans le terminal :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c -g   
