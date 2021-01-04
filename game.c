// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on January 2020
// This program shows a Sprite

#include <gb/gb.h>
#include <stdio.h>
#include "logo_data.c"
#include "logo_map.c"
#include "titlescreen_data.c"
#include "titlescreen_map.c"
#include "ValerioCharacter.c"
#include "ValerioSprites.c"
UINT8 i;

struct ValerioCharacter valerio;
UBYTE spritesize = 8;

void performantdelay(UINT8 numloops) {
    UINT8 ii;
    for (ii = 0; ii < numloops; ii++) {
        wait_vbl_done();
    }
}

void fadeout() {
    for (i=0; i < 4; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xE4;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xFE;
                break;
            case 3:
                BGP_REG = 0xFF;
                break;
        }
        performantdelay(5);
    }
}

void fadein() {
    for (i=0; i < 3; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xFE;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xE4;
                break;
        }
        performantdelay(5);
    }
}


void movegamecharacter(struct ValerioCharacter* character, UINT8 x, UINT8 y) {
    move_sprite(character->spritids[0], x, y);
    move_sprite(character->spritids[1], x + spritesize, y);
    move_sprite(character->spritids[2], x, y + spritesize);
    move_sprite(character->spritids[3], x + spritesize, y + spritesize);
}

void setupvalerio() {
    valerio.x = 80;
    valerio.y = 130;
    valerio.width = 16;
    valerio.height = 16;

    // load sprites for valerio
    set_sprite_tile(0, 0);
    valerio.spritids[0] = 0;
    set_sprite_tile(1, 1);
    valerio.spritids[1] = 1;
    set_sprite_tile(2, 2);
    valerio.spritids[2] = 2;
    set_sprite_tile(3, 3);
    valerio.spritids[3] = 3;

    movegamecharacter(&valerio, valerio.x, valerio.y);
}

int valeriofront(int downpress) {
    // change sprites for valerio
    if (downpress > 0) {
        set_sprite_tile(0, 1);
        set_sprite_prop(0, S_FLIPX);
        set_sprite_tile(1, 0);
        set_sprite_prop(1, S_FLIPX);
        set_sprite_tile(2, 3);
        set_sprite_prop(2, S_FLIPX);
        set_sprite_tile(3, 2);
        set_sprite_prop(3, S_FLIPX);
        if (downpress == 2) {
            downpress = 0;
        } else {
            downpress += 1;
        }
    } else {
        set_sprite_tile(0, 0);
        set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
        set_sprite_tile(1, 1);
        set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
        set_sprite_tile(2, 2);
        set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
        set_sprite_tile(3, 3);
        set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
        if (downpress == -1) {
            downpress = 1;
        } else {
            downpress -= 1;
        }
    }
    return downpress;
}

int valerioback(int uppress) {
    // change sprites for valerio
    if (uppress > 0) {
        set_sprite_tile(0, 5);
        set_sprite_prop(0, S_FLIPX);
        set_sprite_tile(1, 4);
        set_sprite_prop(1, S_FLIPX);
        set_sprite_tile(2, 7);
        set_sprite_prop(2, S_FLIPX);
        set_sprite_tile(3, 6);
        set_sprite_prop(3, S_FLIPX);
        if (uppress == 2) {
            uppress = 0;
        } else {
            uppress += 1;
        }
    } else {
        set_sprite_tile(0, 4);
        set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
        set_sprite_tile(1, 5);
        set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
        set_sprite_tile(2, 6);
        set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
        set_sprite_tile(3, 7);
        set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
        if (uppress == -1) {
            uppress = 1;
        } else {
            uppress -= 1;
        }
    }
    return uppress;
}

int valerioleft(int leftpress) {
    // change sprites for valerio
    if (leftpress > 0) {
        set_sprite_tile(0, 9);
        set_sprite_prop(0, S_FLIPX);
        set_sprite_tile(1, 8);
        set_sprite_prop(1, S_FLIPX);
        set_sprite_tile(2, 11);
        set_sprite_prop(2, S_FLIPX);
        set_sprite_tile(3, 10);
        set_sprite_prop(3, S_FLIPX);
        if (leftpress == 2) {
            leftpress = 0;
        } else {
            leftpress += 1;
        }
    } else {
        set_sprite_tile(0, 9);
        set_sprite_prop(0, S_FLIPX);
        set_sprite_tile(1, 8);
        set_sprite_prop(1, S_FLIPX);
        set_sprite_tile(2, 13);
        set_sprite_prop(2, S_FLIPX);
        set_sprite_tile(3, 12);
        set_sprite_prop(3, S_FLIPX);
        if (leftpress == -1) {
            leftpress = 1;
        } else {
            leftpress -= 1;
        }
    }
    return leftpress;
}

int valerioright(int rightpress) {
    // change sprites for valerio
    if (rightpress > 0) {
        set_sprite_tile(0, 8);
        set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
        set_sprite_tile(1, 9);
        set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
        set_sprite_tile(2, 10);
        set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
        set_sprite_tile(3, 11);
        set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
        if (rightpress == 2) {
            rightpress = 0;
        } else {
            rightpress += 1;
        }
    } else {
        set_sprite_tile(0, 8);
        set_sprite_prop(0, get_sprite_prop(0) & ~S_FLIPX);
        set_sprite_tile(1, 9);
        set_sprite_prop(1, get_sprite_prop(1) & ~S_FLIPX);
        set_sprite_tile(2, 12);
        set_sprite_prop(2, get_sprite_prop(2) & ~S_FLIPX);
        set_sprite_tile(3, 13);
        set_sprite_prop(3, get_sprite_prop(3) & ~S_FLIPX);
        if (rightpress == -1) {
            rightpress = 1;
        } else {
            rightpress -= 1;
        }
    }
    return rightpress;
}

void start() {
    set_bkg_data(0, 114, logo_data);
    set_bkg_tiles(0, 0, 20, 18, logo_map);

    SHOW_BKG;
    DISPLAY_ON;

    performantdelay(30);

    fadeout();

    set_bkg_data(0, 114, titlescreen_data);
    set_bkg_tiles(0, 0, 20, 18, titlescreen_map);

    fadein();

    waitpad(J_START);

    printf("LOBBY SCREEN");  // Placeholder for the Moment
}

void main() {
    int leftpress = 1;
    int rightpress = 1;
    int uppress = 1;
    int downpress = 1;

    start();

    set_sprite_data(0, 14, ValerioSprites);
    setupvalerio();

    SHOW_SPRITES;
    DISPLAY_ON;

    while (1) {
       if (joypad() & J_LEFT) {
           valerio.x -= 2;
           leftpress = valerioleft(leftpress);
           movegamecharacter(&valerio, valerio.x, valerio.y);
       } else if (joypad() & J_RIGHT) {
           valerio.x += 2;
           rightpress = valerioright(rightpress);
           movegamecharacter(&valerio, valerio.x, valerio.y);
       } else if (joypad() & J_UP) {
           valerio.y -= 2;
           uppress = valerioback(uppress);
           movegamecharacter(&valerio, valerio.x, valerio.y);
       } else if (joypad() & J_DOWN) {
           valerio.y += 2;
           downpress = valeriofront(downpress);
           movegamecharacter(&valerio, valerio.x, valerio.y);
       }

       performantdelay(5);
    }
}
