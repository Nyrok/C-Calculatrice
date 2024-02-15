#include <stdio.h>

int main () {
  int taille = 100;
  int numbers[taille];
  char operators[taille - 1];
  char temp_operator, answer;
  int temp_number, result, i = 1;
  printf("Donner un 1 er nombre:\n");
  scanf("%i", &temp_number);
  numbers[0] = temp_number;
  result = numbers[0];
  
  while(i < taille){
    printf("Donner un opérateur:\n");
    scanf(" %c", &temp_operator);
    if(!(temp_operator == '+' || temp_operator == '-' || temp_operator == 'x' || temp_operator == '/')){
      	printf("Opérateur invalide ! Liste des opérateurs valides: + - x /");
	    continue;
    }
    operators[i - 1] = temp_operator;
    printf("Donner un %i ième nombre:\n", i + 1);
    scanf("%i", &temp_number);
    numbers[i] = temp_number;
    if(++i >= taille) break;
    printf("Souhaitez-vous ajouter un nombre ?:\n");
    scanf(" %c", &answer);
    if(answer == 'o') continue;
    else break;
  }
 
  for (int j = 1; j < i; j++){
  	 if(operators[j - 1] == '+'){
     	result += numbers[j];
     }
     else if(operators[j - 1] == '-'){
     	result -= numbers[j];
     }
     else if(operators[j - 1] == 'x'){
        result *= numbers[j];
     }
     else if(operators[j - 1] == '/'){
        if(numbers[j] == 0){
           result = NULL;
           printf("Division par 0..\n");
        }
        else {
           result /= numbers[j];
        }
     } else {
        result = NULL;
     }
     if(result == NULL && result != 0){
        printf("Il y a eu une erreur :/");
       	break;
     }
  }
  printf("Résultat final: %i", result);
}