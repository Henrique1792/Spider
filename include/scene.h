#ifndef SCENE_H
#define SCENE_H

#define WIDTH 800
#define HEIGHT 450

void drawLoop();
void drawScene();
void move();
void reshape (int width, int height) ;
void on_mouseClick(int button, int click_state, int x_mouse_position, int y_mouse_position);
void update(int value);
#endif