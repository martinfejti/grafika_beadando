#include <stdbool.h>
#include "texture.h"

typedef struct HelpMenu { 
    bool shown;
    Texture texture;
} HelpMenu;

void initHelpMenu();
void helpmenuKeyboardSpecialButtonHandler(int key, int x, int y);
void renderHelpMenuIfVisible();
void renderHelpMenu();