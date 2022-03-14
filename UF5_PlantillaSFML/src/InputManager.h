#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "includes.h"
#include <SFML/Graphics.hpp>

class InputManager {
public:
    enum KeyboardKeys {
        KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P,
        KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L,
        KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M,
        KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
        NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5,
        NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, NUMPAD0,
        SPACE, ENTER, BACKSPACE, SHIFT, TAB, CONTROL, ALT, ESCAPE,
        ARROW_UP, ARROW_DOWN, ARROW_LEFT, ARROW_RIGHT,
        LAST_NO_USE
    };

    ~InputManager();
    static InputManager* GetInstance();

    void UpdateEvents();
    void ClearInput();

    bool IsKeyPressed(KeyboardKeys p_key);
    bool IsKeyDown(KeyboardKeys p_key);
    bool IsKeyReleased(KeyboardKeys p_key);

    void SetWindow(sf::RenderWindow* p_window) { m_window = p_window; }

private:
    InputManager();
    static InputManager* m_instance;
    sf::RenderWindow* m_window;

    //! Translates from SFML key codes enum to our enum (KeyBoardKeys)
    InputManager::KeyboardKeys GetKeyCode(sf::Keyboard::Key p_key);
    void KeyPressedEvent(sf::Keyboard::Key p_key);
    void KeyReleasedEvent(sf::Keyboard::Key p_key);

    bool m_keyPressed[LAST_NO_USE];
    bool m_keyDown[LAST_NO_USE];
    bool m_keyReleased[LAST_NO_USE];
};

#endif // !INPUT_MANAGER_H
