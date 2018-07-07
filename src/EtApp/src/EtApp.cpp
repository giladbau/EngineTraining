#include <iostream>
#include <string>
#include "GL/glew.h"
#include "SDL2/SDL.h"

void CheckSDLError(int line = -1);
void RunEngineLoop();

SDL_Window *g_mainWindow;
SDL_GLContext g_glContext;

bool InitGraphics()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to init SDL\n";
        return false;
    }

    //Create the window
    g_mainWindow = SDL_CreateWindow(
        "Engine Test",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_OPENGL);

    if (!g_mainWindow)
    {
        std::cout << "Unable to create window\n";
        CheckSDLError(__LINE__);
        return false;
    }

    // Create OpenGL context and attach it to the window
    g_glContext = SDL_GL_CreateContext(g_mainWindow);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // This makes our buffer swap syncronized with the monitor's vertical refresh
    SDL_GL_SetSwapInterval(1);

    // Init GLEW
    // Apparently, this is needed for Apple.
    #ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
    #endif

      
    return true;
}

void cleanup()
{
    SDL_GL_DeleteContext(g_glContext);
    SDL_DestroyWindow(g_mainWindow);
    SDL_Quit();
}

int main(int argc, char** argv)
{
    bool res = 0;
    
    res = InitGraphics();
    if (!res)
    {
        return 1;
    }
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(g_mainWindow);

    RunEngineLoop();

    cleanup();
    return 0;
}

void CheckSDLError(int line)
{
    std::string error = SDL_GetError();

    if (error != "")
    {
        std::cout << "SLD Error : " << error << std::endl;

        if (line != -1)
            std::cout << "\nLine : " << line << std::endl;

        SDL_ClearError();
    }
}

void RunEngineLoop()
{
    bool isRunning = true;
    while (isRunning)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    isRunning = false;
                }
            }
        }
    }
}
