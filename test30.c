#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chance = 6;
char word[] = "assembly";
char wordToFind[sizeof(word)];

void select()
{
    int length = strlen(word);
    
    for (int i = 0; i < length; i++)
    {
        if(i == 0 || i == length - 1)
        {
            wordToFind[i] = word[i];
            printf("%c", wordToFind[i]);
        }
        else
        {
            wordToFind[i] = '*';
            printf("*");
        }
    }

    wordToFind[length] = '\0';
    printf("\nword to find: %s\n", wordToFind);
}

char choose()
{
    char letter;
    printf("Choisissez une lettre : ");
    scanf(" %c", &letter);
    return letter;
}

void compare(char chosenLetter)
{
    int length = strlen(wordToFind);
    int letterFound = 0;

    for (int i = 0; i < length; i++)
    {
        if (chosenLetter == word[i])
        {
            wordToFind[i] = chosenLetter;
            letterFound = 1;
        }
    }

    if (!letterFound)
    {
        chance--;
    }

    printf("Il vous reste %d tentative(s)!\n", chance);
    printf("word to find : %s\n", wordToFind);
    if (letterFound == strlen(word) )
    {
        retry();
    }
}

int retry()
{
    char option;
    char closer;
    printf("Voulez vous redémarrer une partie Y/N");
    scanf(" %c", &option);
    if(&option == "Y")
    {
        select();
    }
    else  if(&option == "Y")
    {
        printf("Merci d'avoir joue, à bientot! appuyer sur Q pour quitter le programme");
        scanf("%c", &closer );
        if(&closer == "Q");
        exit(0);
    }
}

int main()
{
    select();

    while (chance > 0)
    {
        char chosenLetter = choose();
        compare(chosenLetter);

        if (strcmp(word, wordToFind) == 0)
        {
            printf("Félicitations, vous avez trouvé le mot !\n");
            break;
        }
    }

    if (chance == 0)
    {
         printf("------\n |   |\n O   |\n/|\\  |\n/ \\  |\n     |\n     |\n     |\n--------\nGAME OVER");
        printf("Vous avez épuisé toutes vos chances. Le mot à trouver était %s\n", word);
        scanf("ok");
        retry();
    }

    return 0;
}
