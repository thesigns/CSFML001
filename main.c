#include <stdio.h>
#include <stdlib.h>
#include <SFML\System.h>
#include <SFML\Window.h>
#include <SFML\Graphics.h>

int main()
{

    sfVideoMode desktopMode = sfVideoMode_getDesktopMode();
    sfContextSettings contextSettings = {0, 0, 8, 1, 1, 0, false};

    sfRenderWindow *window = sfRenderWindow_create(desktopMode, "CSFML001 Fun", sfDefaultStyle, &contextSettings);
    if (!window)
    {
        return EXIT_FAILURE;
    }

    while (sfRenderWindow_isOpen(window))
    {

        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed)
            {
                if (event.key.code == sfKeyEscape)
                {
                    sfRenderWindow_close(window);
                }
                printf("%i ", event.key.code);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);

    return EXIT_SUCCESS;
}
