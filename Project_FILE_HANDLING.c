#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    float weight;
    float height;
    float bmi;
    float vo2max;
    int age;
} Fitness;


void BMI(Fitness *fitness)
{
    system("cls");
    float weight, height;
    int method;

    printf("\n\nPlease choose an input method:\n");
    printf("1-kg/m\n");
    printf("2-lbs/inch\n");
    printf("Enter your choice (1 or 2): ");
    xyz:
    scanf("%d", &method);
    for(int i=1;i>=1;i++)
    {
        if (method != 1 && method != 2)
        {
            printf("Invalid input. Please enter 1 or 2.\n");
            goto xyz;   
        }
        else
        {
            break;
        }
    }
    switch (method) {
        case 1:
            printf("Enter your weight in kg: ");
            scanf("%f", &fitness->weight);
            printf("Enter your height in meters: ");
            scanf("%f", &fitness->height);
            break;
        case 2:
            printf("Enter your weight in pounds: ");
            scanf("%f", &fitness->weight);
            printf("Enter your height in inches: ");
            scanf("%f", &fitness->height);
            weight *= 0.453592;
            height *= 0.0254; 
            break;
    }
    
    fitness->bmi = weight / (height * height);
    
    printf("Your BMI is: %.2f\n", fitness->bmi);

    
    if (fitness->bmi < 18.4) 
    {
        printf("You are underweight.\n");
    } 
    else if (fitness->bmi < 24.9)
    {
        printf("Your weight is normal.\n");
    }
    else if (fitness->bmi < 29.9)
    {
        printf("You are overweight.\n");
    }
    else if (fitness->bmi < 34.9)
    {
        printf("You are obese(I).\n");
    }
    else if (fitness->bmi < 39.9) 
    {
        printf("You are obese(II).\n");
    }
    else
    {
        printf("You are obese(III)\n");
    }
    printf("\n\n<=====Successfully saved your BMI information. Please select 'ENTER' key to go back to the main menu=====>");
}

void VO2(Fitness *fitness)
{
    system("cls");
    float weight, age, heart_rate, vo2max;
    int gender;

     printf("<=================VO2 CALCULATOR=================>\n\n");
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("\nEnter your age in years: ");
    scanf("%f", &age);

    printf("\nEnter your heart rate in beats per minute: ");
    scanf("%f", &heart_rate);

    while (1) {
        printf("\nEnter your gender (1 for male, 2 for female): ");
        vo2:{
        scanf("%d", &gender);
        }

        if (gender == 1) {
            vo2max = ((-55.0969 + (0.6309 * heart_rate) + (0.1988 * weight) + (0.2017 * age)) / 3.5)/0.4472;
            fitness->vo2max = vo2max;
            break;
        } else if (gender == 2) {
            vo2max = ((-20.4022 + (0.4472 * heart_rate) - (0.1263 * weight) + (0.074 * age)) / 3.5)/0.369;
            fitness->vo2max = vo2max;
            break;
        } else {
            printf("\nInvalid gender. Please enter 1 for male or 2 for female.\n");
            goto vo2;
            
        }
    }

    printf("Your VO2max is: %.2f ml/kg/min\n", vo2max);
    printf("\n<=====Please select 'ENTER' key to go back to the main menu=====>");
}

int registration(Fitness*fitness)
{
    int gender;
    system("cls");
    printf("\nEnter your name: ");
    scanf("%s", &fitness->name);
    printf("Enter you age: ");
    scanf("%d",&fitness->age);
//For Gender
    printf("\n\nGender:\n1) Male\n2) Female");
    printf("\nEnter your choice (1 or 2): ");
    abc:
    scanf("%d",& gender);
     for(int i=1;i>=1;i++)
    {
        if (gender!= 1 && gender!= 2)
        {
            printf("Invalid input. Please enter 1 or 2.\n");
            goto abc;   
        }
        else
        {
            printf("\n<=====Successfully saved your gender information. Please select 'ENTER' key to go back to the main menu=====>");
            break;
        }
        return 0;
    }
}

void save_fitness_data(Fitness *fitness, int count) {
    FILE *fp = fopen("fitness_data.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    fprintf(fp, "%s,\t%.2f,\t%.2f,\t%.2f,\t%.2f\n", fitness->name, fitness->weight, fitness->height, fitness->bmi, fitness->vo2max);
    fclose(fp);
}

void View() {
    system("cls");
    FILE *fp = fopen("fitness_data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    printf("<=========Fitness Data:=========>\n\n");
    printf("Name\tWeight\tHeight\tBMI\tVO2 Max\n");
    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

int main()
{int input, count;
Fitness fitness;

    main:
    system("cls");
    printf("<===Fitness Calculator===>\n");
    printf("1) Registeration\n");
    printf("2) Calculate your BMI\n");
    printf("3) Calculate your VO2\n");
    printf("4) View your Information\n");
    printf("Enter your choice: ");
    scanf("%d",&input);
    for(int i=1;i>=1;i++)
     {
    if (input!= 1 && input!= 2 && input!= 3 && input!= 4)
        {
            printf("\n<=====Invalid input. Please enter the options gievn above only. Press 'ENTER' key to start over!=====>");
            getch();
            goto main;   
        }
        else
        {
            break;
        }
     }
    switch (input)
    {
    case 1:
        registration(&fitness);
        save_fitness_data(&fitness, count++);
        getch();
        goto main;
        break;

    case 2:
        BMI(&fitness);
        save_fitness_data(&fitness, count++);
        getch();
        goto main;
        break;

    case 3:
        VO2(&fitness);
        save_fitness_data(&fitness, count++);
        getch();
        goto main;
        break;
    case 4:
        View();
        getch();
        goto main;
        break;

    default:
        break;
    }
}