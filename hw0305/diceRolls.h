#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <vector>

int Description();
int PlayerInput();
int RandomGenerator(int face);
int DrawDice(int *diceNumber, int n);
int RollDice1();
int RollDice2();
int RollDice3();
int RollDice4();
int DeleteHighest(int *diceNumber, int diceQuantity);
int DeleteLowest(int *diceNumber, int diceQuantity);
int FalseInputReaction();

int actionType = -1;

int PlayerInput()
{
    srand(time(0));
    printf("Your action: ");
    scanf("%d", &actionType);
    switch (actionType)
    {
    case 0:
        return 0;
    case 1:
        RollDice1();
        break;
    case 2:
        RollDice2();
        break;
    case 3:
        RollDice3();
        break;
    case 4:
        RollDice4();
        break;
    default:
        FalseInputReaction();
        break;
    }
}
int RollDice1()
{
    int sum = 0;
    sum = RandomGenerator(6);
    printf("result: %d", sum);
    return 0;
}
int RollDice2()
{
    int diceQuantity, diceFaces, sum = 0;
    printf("Please enter A, X: ");
    scanf("%d %d", &diceQuantity, &diceFaces);
    int eachNumber[diceQuantity];
    for (int i = 0; i < diceQuantity; i++)
    {
        eachNumber[i] = RandomGenerator(diceFaces);
        sum += eachNumber[i];
    }
    DrawDice(eachNumber, diceQuantity);
    printf("result: %d", eachNumber[0]);
    for (int i = 1; i < diceQuantity; i++)
        printf(" + %d", eachNumber[i]);
    printf(" = %d", sum);
    return 0;
}
int RollDice3()
{
    int diceQuantity, diceFaces, preserveDiceQuantity, numberToAdd, sum = 0;
    printf("Please enter A, X, Y, B: ");
    scanf("%d %d %d %d", &diceQuantity, &diceFaces, &preserveDiceQuantity, &numberToAdd);
    int eachNumber[diceQuantity];
    for (int i = 0; i < diceQuantity; i++)
    {
        eachNumber[i] = RandomGenerator(diceFaces);
    }
    DrawDice(eachNumber, diceQuantity);

    printf("Please choose %d dice from above: ", preserveDiceQuantity);
    int temp[preserveDiceQuantity];
    int diceToBePreserved[preserveDiceQuantity];
    for (int i = 0; i < preserveDiceQuantity; i++)
    {
        do
        {
            scanf("%d", &diceToBePreserved[i]);
            temp[i] = eachNumber[diceToBePreserved[i] - 1];
            if (diceToBePreserved[i] > diceQuantity || diceToBePreserved[i] <= 0)
                FalseInputReaction();
        } while (diceToBePreserved[i] > diceQuantity || diceToBePreserved[i] <= 0);
    }
    DrawDice(temp, preserveDiceQuantity);

    for (int i = 0; i < preserveDiceQuantity; i++)
    {
        // auto elem_to_remove = eachNumber.begin() + diceToBePreserved[i] - 1;
        // eachNumber.erase(elem_to_remove);
        sum += eachNumber[diceToBePreserved[i] - 1];
    }
    sum += numberToAdd;

    printf("result: %d", eachNumber[diceToBePreserved[0] - 1]);
    for (int i = 1; i < preserveDiceQuantity; i++)
        printf(" + %d", eachNumber[diceToBePreserved[i] - 1]);
    if (numberToAdd >= 0) printf(" + %d", numberToAdd);
    else printf(" - %d", abs(numberToAdd));
    printf(" = %d", sum);
    return 0;
}
int RollDice4()
{
    int diceQuantity, diceFaces, Highest, Lowest, preserveDiceQuantity, numberToAdd, sum = 0;
    printf("Please enter A, X, H, L, C, B: ");
    scanf("%d %d %d %d %d %d", &diceQuantity, &diceFaces, &Highest, &Lowest, &preserveDiceQuantity, &numberToAdd);
    int eachNumber[diceQuantity];
    for (int i = 0; i < diceQuantity; i++)
    {
        eachNumber[i] = RandomGenerator(diceFaces);
    }
    DrawDice(eachNumber, diceQuantity);

    printf("Highest %d: \n", Highest);
    int temp_h[Highest];
    for (int i = 0; i < Highest; i++)
    {
        temp_h[i] = DeleteHighest(eachNumber, diceQuantity);
    }
    DrawDice(temp_h, Highest);

    printf("Lowest %d: \n", Lowest);
    int temp_l[Lowest];
    for (int i = 0; i < Lowest; i++)
    {
        temp_l[i] = DeleteLowest(eachNumber, diceQuantity);
    }
    DrawDice(temp_l, Lowest);

    printf("Choose %d: \n", preserveDiceQuantity);
    diceQuantity = diceQuantity - Highest - Lowest;
    int temp[diceQuantity], j = 0;
    for (int i = 0; i < (diceQuantity + Highest + Lowest); i++)
        if (eachNumber[i] > 0)
        {
            temp[j] = eachNumber[i];
            j++;
        }
    DrawDice(temp, diceQuantity);
    for (int i = 0; i < diceQuantity; i++)
        eachNumber[i] = temp[i];

    printf("Please choose %d dice from above: ", preserveDiceQuantity);
    int diceToBePreserved[preserveDiceQuantity];
    int temp_p[preserveDiceQuantity];
    for (int i = 0; i < preserveDiceQuantity; i++)
    {
        do
        {
            scanf("%d", &diceToBePreserved[i]);
            temp_p[i] = eachNumber[diceToBePreserved[i] - 1];
            if (diceToBePreserved[i] > diceQuantity || diceToBePreserved[i] <= 0)
                FalseInputReaction();
        } while (diceToBePreserved[i] > diceQuantity || diceToBePreserved[i] <= 0);
    }
    DrawDice(temp_p, preserveDiceQuantity);

    for (int i = 0; i < preserveDiceQuantity; i++)
    {
        sum += eachNumber[diceToBePreserved[i] - 1];
    }
    sum += numberToAdd;

    printf("result: %d", eachNumber[diceToBePreserved[0] - 1]);
    for (int i = 1; i < preserveDiceQuantity; i++)
        printf(" + %d", eachNumber[diceToBePreserved[i] - 1]);
    if (numberToAdd >= 0) printf(" + %d", numberToAdd);
    else printf(" - %d", abs(numberToAdd));
    printf(" = %d", sum);
    return 0;
}
int FalseInputReaction()
{
    printf("wrong input\n");
    return 0;
}
int RandomGenerator(int face)
{
    int x = rand() % face + 1;
    return x;
}
int DrawDice(int *diceNumber, int n)
{
    printf("  ");
    for (int i = 0; i < n; i++)
        printf("._____. ");
    printf("\n ");
    for (int i = 0; i < n; i++)
        printf("/     / ");
    if (n > 0) printf("|\n");
    for (int i = 0; i < n; i++)
        printf(".-----. ");
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("|  %-3d| ", diceNumber[i]);
    if (n > 0) printf("/\n");
    for (int i = 0; i < n; i++)
        printf(".-----. ");
    printf("\n");
    return 0;
}
int DeleteHighest(int *diceNumber, int n)
{
    int highest_n = 0;
    int highest = diceNumber[0];
    for (int i = 1; i < n; i++)
    {
        if (diceNumber[i] > highest)
        {
            highest = diceNumber[i];
            highest_n = i;
        }
    }
    diceNumber[highest_n] = 0;
    return highest;
}
int DeleteLowest(int *diceNumber, int n)
{
    int lowest_n = 0;
    int lowest = diceNumber[0];
    for (int i = 1; i < n; i++)
    {
        if (lowest == 0)
        {
            lowest = diceNumber[i];
        }
        if (diceNumber[i] < lowest && diceNumber[i] != 0)
        {
            lowest = diceNumber[i];
            lowest_n = i;
        }
    }
    diceNumber[lowest_n] = 0;
    return lowest;
}
int Description()
{
    printf("there are four function.\n1. roll 1 6 faces dice\n2. roll several same faces dices, you can choose the face numbers and the dice numbers\n");
    printf("3. besides the features in 2. You can chose several numbers of dice you want to left.\n");
    printf("4. besides the features in 3. You can remove the highest some dice numbers and the lowest some dice numbers.\n");
}
