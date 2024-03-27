// #include <>
#include "raylib.h"

int main()
{
    int width{1000};
    int height{900};
    InitWindow(width, height, "Game Window");

    // circle coordinates
    int circle_X{width / 2};
    int circle_Y{height / 2};
    int circle_radius{25};

    // circle edges
    int l_circle_x{circle_X - circle_radius};
    int r_circle_x{circle_X + circle_radius};
    int u_circle_y{circle_Y - circle_radius};
    int b_circle_y{circle_Y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{400};
    int axe_length{50};

    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    bool collision_with_axe =
        (b_axe_y >= u_circle_y) &&
        (u_axe_y <= b_circle_y) &&
        (r_axe_x >= l_circle_x) &&
        (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        if (collision_with_axe)
        {
            DrawText("Game Over", width / 2, height / 2 - 30, 40, RED);
        }
        else
        {
            // Game Logic begins

            // update the edges
            l_circle_x = circle_X - circle_radius;
            r_circle_x = circle_X + circle_radius;
            u_circle_y = circle_Y - circle_radius;
            b_circle_y = circle_Y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            // update collison with axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);

            DrawCircle(circle_X, circle_Y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            // axe movement
            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {
                direction *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_X < width)
            {
                circle_X += 10;
            }
            if (IsKeyDown(KEY_A) && circle_X > 0)
            {
                circle_X -= 10;
            }

            // Game logic Ends
        }
        EndDrawing();
    }
}