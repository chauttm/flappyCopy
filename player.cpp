#include "player.h"
#include "defs.h"

#include "SDL.h"

#define MAX_ANGLE 80.0
#define GRAVITY_ACCEL 5.0

Player::Player(SDL_Renderer* renderer, double x, double y)
    : texture{renderer}, isDead{false}, posX{x}, posY{y}, radius{0.0}, vertSpeed{0.0}, vertAccel{0.3}
{
    texture.loadFromFile(BIRD_IMAGE);
    radius = texture.getWidth() / 2;
}

void Player::make_jump()
{
    if (vertSpeed > 0) vertSpeed = -GRAVITY_ACCEL;
    else vertSpeed -= GRAVITY_ACCEL;
}

void Player::apply_forces()
{
    vertSpeed += vertAccel;
    posY += vertSpeed;
}

void Player::render()
{
    double angle = vertSpeed * 5.0;
    if (angle > MAX_ANGLE) angle = MAX_ANGLE;

    texture.render(static_cast<int>(posX - radius), static_cast<int>(posY - radius), nullptr, angle);
}
