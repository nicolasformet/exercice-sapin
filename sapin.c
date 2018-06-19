#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c)
{
   write(1,&c,1);
}

int base(int size);int nb_espace(int base);int pair(int size)
{
   int pair;
   
   if (size%2 == 0)
    pair = 0;
   
   else
    pair = 1;
   return pair;
}

int nb_ligne(int size)
{
   int i = size;
   int nb_ligne = 0;
   while (i > 0)
   {
       nb_ligne = nb_ligne + (i + 3);
       i--;
   }
   return nb_ligne;
}

int etoile(int size)
{
    int i = 0;  // compteur d'étages
    int j = 4;  // compteur de niveaux par étage
    int k = 1;  // nombre d'étoiles à afficher par étage
    int l = 0;
    int etoiles = 0;
    int soustraire_etoiles = 0;

    while (i < size)   // nombre d'étages totaux
    {
        if (i > 1 && i%2 == 0)    // si on est à un étage impair
           soustraire_etoiles+=2; // s'incrémente de 1 à chaque étage impair (modulo inverse à cause de i qui commence à 0)

        while (l < j+i)     // nombre de niveaux par étage
        {
            while (etoiles < k)    // nombre d'étoiles
            etoiles++;
            k+=2;   // 2 étoiles supplémentaires par niveau
            l++;
        }

        k=k-soustraire_etoiles-4;
        l = 0;
        i++;
    }
    etoiles += 1;
    return (etoiles);
}

void pied(int size)
{
   int base = etoile(size);
   int nb_espace = ((base-size)/2 -1);
   int i = 0;
   int j;
   int l;
   
   while (i < size)
   {
   j = 0;
   l = 0;

   while (l < nb_espace)
   {
       my_putchar(' ');
       l++;
   }

   while (j < size)
   {
       my_putchar('|');
       j++;
   }
   
   my_putchar('\n');
   i++;
   }
}

void sapin(int size)
{
   int nbl = nb_ligne(size);
   int j = 0;
   int nbe = 1;
   int base = etoile(size);
   int nb_espace = ((base/2) -1);
   int etage = 1;
   int decal = 0;
   
       while (j < nbl)
   {        
       int k = 0;
       int l = 0;
       
   while (l < nb_espace)
   {
       my_putchar(' ');
       l++;
       
   }
  
   while (k < nbe)
   {
       my_putchar('*');
       k++;
   }
       
   my_putchar('\n');
   nbe = nbe +2;
   nb_espace = nb_espace -(1);
   j++;

   if(j == nb_ligne(etage))
   {
       if(pair(etage) == 1)
       decal++;
       nbe = nbe - 2*(decal+1);
       nb_espace = nb_espace + (1+decal);
       etage++;
       
   }
   }
   pied(size);
}




/*

void my_putchar(char c)
{
  write(1, &c,  1);
}

void sapin (int size)
{
 int nbl = size * 4;
   int j = 0;
   int nbe = 1;
   int base = 7;
   int nb_espace = (base -1)/2;
   while (j < nbl)
   {
       int k = 0;
       int l = 0;
       while (l < nb_espace)
           {
               my_putchar(' ');
               l++;
           }
       while (k < nbe)
           {
               my_putchar('*');
               k++;
           }
       my_putchar('\n');
       nbe = nbe + 2;
       nb_espace = nb_espace - 1;
       j++;
   }
}
*/
int main(int argc, char **argv)

{
  /*
  sapin(7);
  return 0;*/
  
  if (argc < 2)

  {

    printf("Need a size in argument.\n");

    return (0);

  }

  sapin(atoi(argv[1]));

  return (0);
  

}
