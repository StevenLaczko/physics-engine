// main.cpp
// This is a physics engine in c++
// Ballz bro, gotta appreciate em

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "gui.h"
#include "circle.h"

#define PIXELS_PER_METER 30
#define G 9.81

int HandleEvents(SDL_Event& event, bool& quit) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Circle Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1200, 900, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    bool quit = false;

    double deltaTime = 0.0;
    Uint64 prevFrameTime = SDL_GetPerformanceCounter();

    int mouseX, mouseY, y=0, x=0, radius=10;
    Uint32 mouseState;

    // Make Circles
    int numCircles = 3;
    Circle circles[] = {
        Circle(3, 3, 10),
        Circle(5, 3, 10),
        Circle(7, 3, 10)
    };

    // Main loop
    while (!quit) {
        HandleEvents(event, quit);

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        radius = 10;
        if (mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            radius=50;
            std::cout << "Mouse Position: X=" << mouseX << ", Y=" << mouseY << std::endl;
        }

        // Draw circles
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i=0; i<numCircles; i++) {
            Circle* c = &circles[i];
            c->setAccY(G);
            DrawCircle(renderer, 
                    c->getPosX()*PIXELS_PER_METER, 
                    c->getPosY()*PIXELS_PER_METER, 
                    c->getRadius());
        }

        x = mouseX;
        y = mouseY;
        DrawCircle(renderer, x, y, radius);

        // Update the screen
        SDL_RenderPresent(renderer);

        for (int i=0; i<numCircles; i++) {
            circles[i].physStep(deltaTime);
        }


        // Calculate delta time
        Uint64 currentFrameTime = SDL_GetPerformanceCounter();
        deltaTime = static_cast<double>(currentFrameTime - prevFrameTime) / SDL_GetPerformanceFrequency();
        prevFrameTime = currentFrameTime;

    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
