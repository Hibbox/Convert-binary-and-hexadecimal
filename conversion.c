#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char hex_lookup[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//combien de "0" il faut ajouter en vérifiant la longueur actuelle de la chaîne ("bin")
void pad_bin_string(char *bin)
{
    int len = strlen(bin);
    int padding = 4 - (len % 4); // formule pour déterminer combien il manque de 0 pour arriver à une longueur qui est un multiple de 4.;
    if (padding == 4)
        return;
    int i = len-1;
    while (i >= 0) // but de déplacer les caractères de la chaîne vers la droite pour créer de l'espace vide à gauche de la chaîne.
    {
        bin[padding+i] = bin[i];
        i--;
    }
    i = 0;
    while(i < padding) //ajouter autant de "0" à gauche de la chaîne jusqu'à ce que la longueur voulue soit atteinte.
    {
        bin[i] = '0';
        i++;
    }
    len += padding;
    bin[len] = '\0';
}

void bin_to_hexa(char *bin)
{
    
    pad_bin_string(bin);
    int i, j;
    char *newvar = (char*)calloc((strlen(bin) / 4 ) + 1, sizeof(char));
    char *hex = (char *)calloc((strlen(bin) / 4) + 1, sizeof(char));
    strcpy(newvar, hex);
    if (newvar == NULL) 
    {// calloc a échoué, gérer cet échec ici
        fprintf(stderr, "calloc a échoué, il n'y a pas suffisamment de mémoire disponible.\n");
        exit(1); 
    }

    for (i = 0, j = 0; i < strlen(bin); i += 4, j++) {
        int val = 0;
        int k;
        for (k = 0; k < 4; k++) {
            val = val << 1;
            if (bin[i + k] == '1')
                val++;
        }
        newvar[j] = hex_lookup[val];
    }
    newvar[j+1] = '\0';
    printf("0x%s\n",  newvar);
    free(newvar);
}


void hex_to_bin(const char *hex)
{
    int len = strlen(hex);
    int size = len * 4;
    unsigned char *bin = (unsigned char*)calloc((size + 1), sizeof(unsigned char));
    const char *constbin = (unsigned char*)calloc((size + 1), sizeof(unsigned char));
    strcpy(bin, constbin);

   if (bin == NULL)
   {
    fprintf(stderr,"echec");
    exit(EXIT_FAILURE);
   }
   int i = 0;
   while( i < len)
   {
    switch (hex[i])
    {
    case '0':
        strcat(bin,"0000");
        break;
    case '1':
        strcat(bin,"0001");
        break;
    case '2':
        strcat(bin,"0010");
        break;
    case '3':
        strcat(bin,"0011");
        break;
    case '4':
        strcat(bin,"0100");
        break;
    case '5':
        strcat(bin,"0101");
        break;
    case '6':
        strcat(bin,"0110");
        break;
    case '7':
        strcat(bin,"0111");
        break;
    case '8':
        strcat(bin,"1000");
        break;
    case '9':
        strcat(bin,"1001");
        break;
    case 'A':
        strcat(bin,"1010");
        break;
    case 'B':
        strcat(bin,"1011");
        break;
    case 'C':
        strcat(bin,"1100");
        break;
    case 'D':
        strcat(bin,"1101");
        break;
    case 'E':
        strcat(bin,"1110");
        break;
    case 'F':
        strcat(bin,"1111");
        break;
    default:

        break;
    }
    i++;
   }
   bin[size] = '\0';
   printf("%s\n", bin);
}
/* Affiche des données binaires en string hexadécimale 
(terminée par un charactère de fin de chaine) */
void bin_to_hexa2(unsigned char *bin, char *hex, int size) {
    if(size % 8 != 0) {
        printf("Taille binaire non valide. La taille doit être un multiple de 8.\n");
        return;
    }
    int i;
    for (i = 0; i < size; i++) {
        sprintf(&hex[i*2], "%02X", bin[i]);
    }
}
//octet par octet
void hex_to_bin2(char data_hex[], unsigned char data_binary[], int size_data_binary[])
{
    char octet_hexa_temporaire[3];
    int i = 0;
    while( i < size_data_binary)
    {
        memcpy(octet_hexa_temporaire, &donnees_hexa[i*2], 2);
        octet_hexa_temporaire[2] = '\0';
        donnees_binaires[i] = (unsigned char) strtol(octet_hexa_temporaire, NULL, 16);
    }
}
int main()
{
    bin_to_hexa("0011110110111110");
    hex_to_bin("3DBE");
    bin_to_hexa2("001111011");
    return 0;
}
