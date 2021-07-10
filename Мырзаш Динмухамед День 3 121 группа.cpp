#include <iostream>
#include <cmath>
#include <cstdlib>


const float g = 9.8;

struct Ball {
	float h = 100;
	float x = 0;
	float y = 0;
	float vx = 10;
	float vy = 0;
	float ax = 0;
	float ay = -g;
	float m = 0;

	Ball() {
	}
};

float time = 0;
float dtime = 0;

void move(Ball* ball, float dt) {

	dtime = dtime + dt;
	ball->vy += (ball->ay) * dtime;
	ball->y = ball->h + ball->ay * (dtime * dtime) / 2;
	ball->ax = 0;
	ball->x += ball->vx * dt;
	if (ball->y > 0)
		time = dtime;
	if (ball->y <= 0) {
		ball->y = 0;
		ball->vy = 0;
		ball->vx = 0;
	}
}

void show(Ball ball) {
	std::cout << "y = " << ball.y << " Vy = " << abs(ball.vy) << " ay = " << abs(ball.ay) << std::endl;
	std::cout << "x = " << ball.x << " Vx = " << abs(ball.vx) << " ax = " << abs(ball.ax) << std::endl;
}

int main() {
	float t = 0;
	Ball a;
	float deltaT = 1;
	for (int i = 0; i < 10; i++) {
		move(&a, deltaT);
		std::cout << t << std::endl;
		show(a);
		t = t + deltaT;         
	}
}