#include "key.h"

typedef struct sKey {
    uint16 debounce;
    uint8 event;
    uint8 press;
    uint8 value;
} TKey;

typedef struct sKeyValue {
    uint8 press;
    uint8 not_press;
} TKeyValue;

volatile TKeyValue key_value[] = {
    {KEY_CIMA_VALUE_NOT_PRESS    , KEY_CIMA_VALUE_PRESS},
    {KEY_BAIXO_VALUE_NOT_PRESS    , KEY_BAIXO_VALUE_PRESS},
    {KEY_ENTRAR_VALUE_NOT_PRESS, KEY_ENTRAR_VALUE_PRESS},
    {KEY_SAIR_VALUE_NOT_PRESS, KEY_SAIR_VALUE_PRESS},
};

TKey key[KEY_NUM];

static uint8 Key_Port(uint8 i) {
    uint8 port = 0;
    switch (i) {
        case KEY_CIMA:     port = KEY_CIMA_PIN; break;
        case KEY_BAIXO:     port = KEY_BAIXO_PIN; break;
        case KEY_ENTRAR: port = KEY_ENTRAR_PIN; break;
        case KEY_SAIR: port = KEY_SAIR_PIN; break;
    }
    return port;
}
static void Key_Check(uint8 key_i) {
    if (key[key_i].debounce == 0) {
        key[key_i].event = 1;
        key[key_i].press = Key_Port(key_i);
        if (Key_Press(key_i) == KEY_PRESS) {
            key[key_i].value = key_value[key_i].press;
        } else {
            key[key_i].value = key_value[key_i].not_press;
        }
    }
    if (key[key_i].press == Key_Port(key_i)) {
        key[key_i].debounce = KEY_DEBOUNCE;
    } else {
        key[key_i].debounce -= (key[key_i].debounce != 0);
    }
}
static uint8 Key_Event(uint8 key_i) {
    Key_Check(key_i);
    if (key[key_i].event == 1) {
        key[key_i].event = 0;
        return 1;
    }
    return 0;
}

void Key_Init(void) {
    uint8 i;
//    DIGITAL_SELECT = 7;
    KEY_CIMA_TRIS = 1;
    KEY_BAIXO_TRIS = 1;
    KEY_ENTRAR_TRIS = 1;
    KEY_SAIR_TRIS = 1;
    for (i = 0; i < KEY_NUM; i++) {
        key[i].debounce = KEY_DEBOUNCE;
        key[i].event = 0;
        key[i].press = KEY_NOT_PRESS;
        key[i].value = key_value[i].not_press;
    }
}

int8 Key_AnyEvent(void) {
    uint8 i;
    for (i = 0; i < KEY_NUM; i++) {
        if (Key_Event(i) != 0) {
            return i;
        }
    }
    return -1;
}

uint8 Key_Press(uint8 key_i) {
    return key[key_i].press;
}

uint8 Key_Value(uint8 key_i) {
    uint8 enable;
    switch (key_i) {
        case KEY_ENTRAR: enable = 1; break;
        case KEY_SAIR: enable = 1; break;
        case KEY_BAIXO: enable = 1; break;
        case KEY_CIMA: enable = 1; break;
    }
    if (enable != 0) {
        return key[key_i].value;
    } else {
        return key_value[key_i].not_press;
    }
}
