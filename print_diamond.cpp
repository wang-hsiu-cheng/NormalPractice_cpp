#include <iostream>
#define SUCCESS 0
#define RED "\x1B[1;31m"
#define GREEN "\x1B[0;32m"
#define BLUE "\x1B[1;34m"
#define RESET "\x1B[0m"

using namespace std;

int maxLayer = 1;
int edgeLength = 1;
void Input();
void DrawCube(int _color);
void DrawLine();
void DrawBlank();

int main()
{
    Input();
    // print up layers
    for (int i = 0; i < maxLayer; i += 1)
    {
        // print line
        for (int j = 0; j < maxLayer - (i + 1); j++)
            DrawBlank();
        for (int j = 0; j < i * 2 + 1; j++)
            DrawLine();
        cout << "+";
        for (int j = 0; j < maxLayer - (i + 1); j++)
            DrawBlank();
        cout << endl;
        // repeat edgeLength tiems
        for (int k = 0; k < edgeLength; k++)
        {
            // print blocks
            for (int j = 0; j < maxLayer - (i + 1); j++)
                DrawBlank();
            for (int j = 0; j < i * 2 + 1; j++)
            {
                // choose color
                int color;
                if (j < i + 1)
                    color = j % 3;
                else
                    color = ((i * 2 + 1) - j - 1) % 3;
                DrawCube(color);
            }
            cout << "|";
            for (int j = 0; j < maxLayer - (i + 1); j++)
                DrawBlank();
            cout << endl;
        }
    }
    // print down first line;
    for (int j = 0; j < maxLayer * 2 - 1; j++)
        DrawLine();
    cout << "+" << endl;
    // print down layers
    for (int i = maxLayer - 2; i >= 0; i--)
    {
        // repeat edgeLength tiems
        for (int k = 0; k < edgeLength; k++)
        {
            // print blocks
            for (int j = 0; j < maxLayer - (i + 1); j++)
                DrawBlank();
            for (int j = 0; j < i * 2 + 1; j++)
            {
                // choose color
                int color;
                if (j < i + 1)
                    color = j % 3;
                else
                    color = ((i * 2 + 1) - j - 1) % 3;
                DrawCube(color);
            }
            cout << "|";
            for (int j = 0; j < maxLayer - (i + 1); j++)
                DrawBlank();
            cout << endl;
        }
        // print line
        for (int j = 0; j < maxLayer - (i + 1); j++)
            DrawBlank();
        for (int j = 0; j < i * 2 + 1; j++)
            DrawLine();
        cout << "+";
        for (int j = 0; j < maxLayer - (i + 1); j++)
            DrawBlank();
        cout << endl;
    }
    return SUCCESS;
}
void Input()
{
    cout << "Please enter n: ";
    cin >> maxLayer;
    cout << "Please enter the edge length: ";
    cin >> edgeLength;
}
void DrawLine()
{
    cout << "+";
    for (int i = 0; i < edgeLength; i++)
        cout << "--";
}
void DrawBlank()
{
    for (int i = 0; i < edgeLength * 2 + 1; i++)
        cout << " ";
}
void DrawCube(int _color)
{
    cout << "|";
    switch (_color)
    {
    case 0:
    {
        for (int i = 0; i < edgeLength; i++)
            printf(RED "██" RESET);
        break;
    }
    case 1:
    {
        for (int i = 0; i < edgeLength; i++)
            printf(GREEN "██" RESET);
        break;
    }
    case 2:
    {
        for (int i = 0; i < edgeLength; i++)
            printf(BLUE "██" RESET);
        break;
    }
    default:
    {
        printf(RESET);
        break;
    }
    }
}