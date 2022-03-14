#include "InputManager.h"

InputManager* InputManager::m_instance = NULL;

InputManager::InputManager() : m_window(NULL) { ClearInput(); };

InputManager::~InputManager() {};

InputManager* InputManager::GetInstance() {
		if (m_instance == NULL) {
				m_instance = new InputManager();
		}
		return m_instance;
}

void InputManager::ClearInput() {
		for (int i = 0; i < LAST_NO_USE; i++) {
				m_keyPressed[i] = false;
				m_keyDown[i] = false;
				m_keyReleased[i] = false;
		}
}

void InputManager::UpdateEvents() {
		if (m_window == NULL) { return; }
		for (int i = 0; i < LAST_NO_USE; i++) {
				m_keyPressed[i] = false;
				m_keyReleased[i] = false;
		}

		sf::Event event;
		while (m_window->pollEvent(event)) {
				switch (event.type)
				{
				default: break;
				case sf::Event::Closed:
						m_window->close();
						break;
				case sf::Event::KeyPressed:
						KeyPressedEvent(event.key.code);
						break;
				case sf::Event::KeyReleased:
						KeyReleasedEvent(event.key.code);
						break;
				}
		}
}

void InputManager::KeyPressedEvent(sf::Keyboard::Key p_key) {
		InputManager::KeyboardKeys key = GetKeyCode(p_key);
		if (key != LAST_NO_USE) {
				if (!m_keyDown[key]) { m_keyPressed[key] = true; }
				m_keyDown[key] = true;
				m_keyReleased[key] = false;
		}
}
void InputManager::KeyReleasedEvent(sf::Keyboard::Key p_key) {
		InputManager::KeyboardKeys key = GetKeyCode(p_key);
		if (key != LAST_NO_USE) {
				m_keyPressed[key] = false;
				m_keyDown[key] = false;
				m_keyReleased[key] = true;
		}
}

InputManager::KeyboardKeys InputManager::GetKeyCode(sf::Keyboard::Key key) {
		KeyboardKeys ret_key = LAST_NO_USE;
		switch (key) {
		default: break;
		case sf::Keyboard::Q: ret_key = KEY_Q; break;
		case sf::Keyboard::W: ret_key = KEY_W; break;
		case sf::Keyboard::E: ret_key = KEY_E; break;
		case sf::Keyboard::R: ret_key = KEY_R; break;
		case sf::Keyboard::T: ret_key = KEY_T; break;
		case sf::Keyboard::Y: ret_key = KEY_Y; break;
		case sf::Keyboard::U: ret_key = KEY_U; break;
		case sf::Keyboard::I: ret_key = KEY_I; break;
		case sf::Keyboard::O: ret_key = KEY_O; break;
		case sf::Keyboard::P: ret_key = KEY_P; break;
		case sf::Keyboard::A: ret_key = KEY_A; break;
		case sf::Keyboard::S: ret_key = KEY_S; break;
		case sf::Keyboard::D: ret_key = KEY_D; break;
		case sf::Keyboard::F: ret_key = KEY_F; break;
		case sf::Keyboard::G: ret_key = KEY_G; break;
		case sf::Keyboard::H: ret_key = KEY_H; break;
		case sf::Keyboard::J: ret_key = KEY_J; break;
		case sf::Keyboard::K: ret_key = KEY_K; break;
		case sf::Keyboard::L: ret_key = KEY_L; break;
		case sf::Keyboard::Z: ret_key = KEY_Z; break;
		case sf::Keyboard::X: ret_key = KEY_X; break;
		case sf::Keyboard::C: ret_key = KEY_C; break;
		case sf::Keyboard::V: ret_key = KEY_V; break;
		case sf::Keyboard::B: ret_key = KEY_B; break;
		case sf::Keyboard::N: ret_key = KEY_N; break;
		case sf::Keyboard::M: ret_key = KEY_M; break;
		case sf::Keyboard::Num0: ret_key = KEY_0; break;
		case sf::Keyboard::Num1: ret_key = KEY_1; break;
		case sf::Keyboard::Num2: ret_key = KEY_2; break;
		case sf::Keyboard::Num3: ret_key = KEY_3; break;
		case sf::Keyboard::Num4: ret_key = KEY_4; break;
		case sf::Keyboard::Num5: ret_key = KEY_5; break;
		case sf::Keyboard::Num6: ret_key = KEY_6; break;
		case sf::Keyboard::Num7: ret_key = KEY_7; break;
		case sf::Keyboard::Num8: ret_key = KEY_8; break;
		case sf::Keyboard::Num9: ret_key = KEY_9; break;
		case sf::Keyboard::Numpad0: ret_key = NUMPAD0; break;
		case sf::Keyboard::Numpad1: ret_key = NUMPAD1; break;
		case sf::Keyboard::Numpad2: ret_key = NUMPAD2; break;
		case sf::Keyboard::Numpad3: ret_key = NUMPAD3; break;
		case sf::Keyboard::Numpad4: ret_key = NUMPAD4; break;
		case sf::Keyboard::Numpad5: ret_key = NUMPAD5; break;
		case sf::Keyboard::Numpad6: ret_key = NUMPAD6; break;
		case sf::Keyboard::Numpad7: ret_key = NUMPAD7; break;
		case sf::Keyboard::Numpad8: ret_key = NUMPAD8; break;
		case sf::Keyboard::Numpad9: ret_key = NUMPAD9; break;
		case sf::Keyboard::Space:		ret_key = SPACE; break;
		case sf::Keyboard::BackSpace:	ret_key = BACKSPACE; break;
		case sf::Keyboard::Enter:		ret_key = ENTER; break;
		case sf::Keyboard::LShift:
		case sf::Keyboard::RShift:
				ret_key = SHIFT; break;
		case sf::Keyboard::RControl:
		case sf::Keyboard::LControl:
				ret_key = CONTROL; break;
		case sf::Keyboard::LAlt:
		case sf::Keyboard::RAlt:
				ret_key = ALT; break;
		case sf::Keyboard::Tab:			ret_key = TAB; break;
		case sf::Keyboard::Escape:		ret_key = ESCAPE; break;
		}
		return ret_key;
}

bool InputManager::IsKeyPressed(KeyboardKeys p_key) {
		if (p_key < 0 || p_key >= LAST_NO_USE) { return false; }
		return m_keyPressed[p_key];
}

bool InputManager::IsKeyDown(KeyboardKeys p_key) {
		if (p_key < 0 || p_key >= LAST_NO_USE) { return false; }
		return m_keyDown[p_key];
}

bool InputManager::IsKeyReleased(KeyboardKeys p_key) {
		if (p_key < 0 || p_key >= LAST_NO_USE) { return false; }
		return m_keyReleased[p_key];
}