#include <stdio.h>
#include "raylib.h"

// Estrutura para representar um botão
typedef struct {
    Rectangle rect;
    Color color;
    Color hoverColor;
    char* text;
    bool clicked;
} Button;

// Função para criar um botão com parâmetros dados
Button CreateButton(Rectangle rect, Color color, Color hoverColor, char* text) {
    Button button;
    button.rect = rect;
    button.color = color;
    button.hoverColor = hoverColor;
    button.text = text;
    button.clicked = false;
    return button;
}

// Função para desenhar um botão
void DrawButton(Button button, int borderWidth, Color borderColor) {
    Color buttonColor = button.color;

    if (CheckCollisionPointRec(GetMousePosition(), button.rect)) {
        buttonColor = button.hoverColor;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            button.clicked = true; // Define o botão como clicado
        }
    }

    DrawRectangleRec(button.rect, buttonColor);
    DrawRectangleLinesEx(button.rect, borderWidth, borderColor);

    float textX = button.rect.x + (button.rect.width - MeasureText(button.text, 26)) / 2;
    float textY = button.rect.y + (button.rect.height - 26) / 2;
    DrawText(button.text, textX, textY, 26, BLACK);
}


int main(void) {
    const int screenWidth = 1000;
    const int screenHeight = 980;

    int flagTela = 0;

    InitWindow(screenWidth, screenHeight, "Menu Example");

    // Definindo os botões do menu
    Rectangle startRect = { 1000 / 2 + 250, 980 / 2 - 175, 195, 65 };
    Button startButton = CreateButton(startRect, LIME, LIGHTGRAY, "Start");

    Rectangle instructionsRect = { 1000 / 2 + 250, 980 / 2 - 75, 195, 65 };
    Button instructionsButton = CreateButton(instructionsRect, LIME, LIGHTGRAY, "Instruções");

    Rectangle creditsRect = { 1000 / 2 + 250, 980 / 2 + 25, 195, 65 };
    Button creditsButton = CreateButton(creditsRect, LIME, LIGHTGRAY, "Créditos");

    Rectangle exitRect = { 1000 / 2 + 250, 980 / 2 + 125, 195, 65 };
    Button exitButton = CreateButton(exitRect, LIME, LIGHTGRAY, "Sair");

    Texture2D instructions = LoadTexture("./assets/instrucoesdefinitivo.png");
    Texture2D menuPrincipal = LoadTexture("./assets/MENU.png");
    Texture2D credits = LoadTexture("./assets/creditosdefinitivo.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Textura fundo do menu
        DrawTexture(menuPrincipal, 0, 0, WHITE);

        // Desenhando os botões
        DrawButton(startButton, 2, BLACK);
        DrawButton(instructionsButton, 2, BLACK);
        DrawButton(creditsButton, 2, BLACK);
        DrawButton(exitButton, 2, BLACK);

        // Verificando se o botão Start foi clicado
        if (CheckCollisionRecs(startButton.rect, (Rectangle){ GetMouseX(), GetMouseY(), 1, 1 })) {

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                //começar o jogo
                
            }
        }

        //botão de instruções
        else if (CheckCollisionRecs(instructionsButton.rect, (Rectangle){ GetMouseX(), GetMouseY(), 1, 1 })) {

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                flagTela = 1;
                while(flagTela) {
                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawTexture(instructions, 0, 0, WHITE);
                    if(IsKeyPressed(KEY_SPACE)) flagTela = 0;
                    EndDrawing();
                }
            }
        }
        
        //botão de créditos
        else if (CheckCollisionRecs(creditsButton.rect, (Rectangle){ GetMouseX(), GetMouseY(), 1, 1 })) {

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                flagTela = 1;
                while(flagTela) {
                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    DrawTexture(credits, 0, 0, WHITE);
                    if(IsKeyPressed(KEY_SPACE)) flagTela = 0;
                    EndDrawing();
                }
            }
        }

        //botão de exit
        else if (CheckCollisionRecs(exitButton.rect, (Rectangle){ GetMouseX(), GetMouseY(), 1, 1 })) {

            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                return 0;
            }
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
