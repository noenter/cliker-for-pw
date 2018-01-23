#include <iostream>
#include <Windows.h>

using namespace std;

void start_clicker()
{
    POINT CurPos;

    int screenX = GetSystemMetrics( SM_CXVIRTUALSCREEN );
    int screenY = GetSystemMetrics( SM_CYVIRTUALSCREEN );
    double cx = 65535.0 / screenX;
    double cy = 65535.0 / screenY;

    GetCursorPos(&CurPos);
    int x = (int)CurPos.x;
    int y = (int)CurPos.y;
    int a = x - 542;
    int b = y + 115;

    cout << "base cursor pos x = " << x << ", y = " << y << endl;

    for (int col = 0; col < 8; col++){

        y = (int)CurPos.y;

        for (int row = 0; row < 8; row++){

            // normolize absoulute coord
            DWORD mouse_x = (DWORD)(x * cx);
            DWORD mouse_y = (DWORD)(y * cy);
            // move mouse to section (absolute coord)
            mouse_event( MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE,
                         mouse_x,
                         mouse_y,
                         0,
                         NULL
                         );

            cout << "right clik " << x << "," << y << endl;

            // right click
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            Sleep(100);
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            y = y + 38;

            Sleep(1000);

            // normolize absoulute coord
            mouse_x = DWORD(a * cx);
            mouse_y = DWORD(a * cy);

            // move mouse to button (absolute coord)
            mouse_event( MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE,
                         mouse_x,
                         mouse_y,
                         0,
                         NULL
                         );
            cout << "left clik " << a << "," << b << endl;
            // left click
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(100);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(7000);
        }

        x = x + 38;
    }
}

int main()
{
    system("color 0a");

    char answer;

    do {

        cout << "Begin in " << endl;
        for (int i=5; i>=1; i --) {
            cout << i << endl;
            Sleep(1000);
        }

        start_clicker();

        cout << "Again? or quit(y/n) ";
        cin >> answer;

    } while ( answer  == 'y');

    system("Pause");
    return 0;
}
