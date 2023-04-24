#include <stdio.h>

int main(){

    /*int marks1 = 98;
    int marks2 = 46;
    int marks3 = 88;*/

    int marks[3];
    printf("Maks in Phy; ");
    scanf("%d",&marks[0]);
     printf("Maks in Chem; ");
     scanf("%d",&marks[1]);
      printf("Maks in Mth; ");
      scanf("%d",&marks[2]);
      printf("Phy = %d, Chem =%d, Mth =%d",marks[0],marks[1],marks[2]);
      return 0;
}