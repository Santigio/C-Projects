

/**
 * Write a C program that reads the content of a file, and prints out all unique words from the file and their number of occurrences. Your program should use fork() , 
 * divide relevant tasks between parent and child/children(ren) and combine the contents together for processing. You can create as many forks as you want 
 * as long as you have more than one process including the parent process. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXI_WORDS   1000



int main()
{
    FILE *file_path;
    char path[100];
    int i, len, index, specialWrd;

    // Listing down all distinct words
    char words[MAXI_WORDS][50];
    char word[50];

    // We then count all the distinct words
    int  count[MAXI_WORDS];


    /* We then ask users to input a file path */
    printf("PLease enter a file path: ");
    scanf("%s", path);


    /* We then open file path user enter*/
    file_path = fopen(path, "r");

    /* However, if file path is incorrect or missing, quit program */
    if (file_path == NULL)
    {
        printf("This type of file can't be open.\n");
        printf("Please check all requirements and try again\n");

        exit(EXIT_FAILURE);
    }

    // We Begin words count to 0
    for (i=0; i<MAXI_WORDS; i++)
        count[i] = 0;





    index = 0;
    
    while (fscanf(file_path, "%s", word) != EOF)
    {
        // We then convert word to lowercase
        strlen(word);

        // This code removes the last punctuation character
        len = strlen(word);
        if (punct(word[len - 1]))
            word[len - 1] = '\0';


        // THis code check if word exits in list of all distinct words
        specialWrd = 1;
        for (i=0; i<index && specialWrd; i++)
        {
            if (strcmp(words[i], word) == 0)
                specialWrd = 0;
        }

        // We add(first check if word is unique) unique word to distinct words
    
        if (specialWrd) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    // We then close our file
    fclose(file_path);


    /*
     * Print repetition of all words in user file. 
     */
    printf("\nHow many times did all unique words in file repeat: \n");
    for (i=0; i<index; i++)
    {
        printf("%-15s => %d\n", words[i], count[i]);
    }    
    

    return 0;
}