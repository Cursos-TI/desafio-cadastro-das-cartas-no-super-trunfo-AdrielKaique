    #include <stdio.h>

    int main(){
        int idade, matricula;
        float altura;
        chat nome[50];

        printf("digite sua idade: /n");
        scanf("%d", &idade);

        printf("digite sua altura: /n");
        scanf("%f", &altura);

        printf("digite seu nome: /n");
        scanf("%s", &nome);

        printf("digite sua matricula: /n");
        scanf("%d", &matricula);

        printf("Nome do aluno: %s - Matricula: %d", nome, matricula);
        printf("Idade: %d - Altura: %f");

        return 0;
    }
