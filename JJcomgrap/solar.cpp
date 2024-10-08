#include "cstdio"
#include "cmath"
#include "gl/glut.h"

/* Global variables */
int timeIdx = 0;
bool isAnimation = false;

/* Structures */
struct Point {
    float x, y;
};

struct Circle {
    Point center;
    float radius;
};

/* Function prototypes */
void DrawCircle(Circle c, bool isFill);
void F11();
void display();
void keyboard(unsigned char key, int x, int y);
void timer(int value);

/* Main function */
int main(int argc, char** argv)
{
    /* GLUT initializations */
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Solar System Simulation");

    /* Call back functions */
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    /* Main loop */
    glutMainLoop();

    return 0;
}

/* Function implementations */
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-25, 25, -25, 25, -10, 10);   // 직교투영

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /* Draw the solar system */
    F11();

    glFinish();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ESC
        exit(0);
    else if (key == 'a') {
        isAnimation = !isAnimation;
        glutTimerFunc(10, timer, 0);
    }
}

void timer(int value)
{
    if (isAnimation) {
        glutTimerFunc(10, timer, 0);
        timeIdx += 1;
        glutPostRedisplay();
    }
}

void DrawCircle(Circle c, bool isFill)
{
    if (isFill)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 360; i++) {
        float angle = i * 3.141592 / 180.0;
        float x = c.center.x + c.radius * cos(angle);
        float y = c.center.y + c.radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void F11() /* Solar system simulation */
{
    // 태양
    glPushMatrix();
    glColor3f(1, 0, 0);
    DrawCircle({ {0, 0}, 2.0 }, true);

    // 지구
    glPushMatrix();
    glRotated(timeIdx / 365.0 * 360.0, 0, 0, 1);
    glTranslated(7, 0.0, 0.0);
    glColor3f(0, 0, 1);
    DrawCircle({ {0, 0}, 1.0 }, true);

    // 달	
    glPushMatrix();
    glRotated(timeIdx / 27.0 * 360.0, 0, 0, 1);
    glTranslated(1.5, 0.0, 0.0);
    glColor3f(1, 0, 1);
    DrawCircle({ {0, 0}, 0.2 }, true);

    glPopMatrix(); // for Moon
    glPopMatrix(); // for Earth

    // 화성
    glPushMatrix();
    glRotated(timeIdx / 687.0 * 360.0, 0, 0, 1); // 화성의 공전
    glTranslated(10, 0.0, 0.0);  // 태양으로부터의 거리
    glColor3f(1, 0.5, 0); // 주황색
    DrawCircle({ {0, 0}, 0.5 }, true);  // 화성의 크기: 반지름 0.5
    glPopMatrix(); // for Mars

    // 목성
    glPushMatrix();
    glRotated(timeIdx / 4333.0 * 360.0, 0, 0, 1); // 목성의 공전
    glTranslated(15, 0.0, 0.0);  // 태양으로부터의 거리
    glColor3f(0, 1, 0); // 초록색
    DrawCircle({ {0, 0}, 2.0 }, true);  // 목성의 크기: 반지름 2.0
    glPopMatrix(); // for Jupiter

    // 토성
    glPushMatrix();
    glRotated(timeIdx / (29.0 * 365.0) * 360.0, 0, 0, 1);  // 토성의 공전 (29년 주기)
    glTranslated(20, 0.0, 0.0);  // 태양으로부터의 거리
    glColor3f(1, 1, 0); // 노란색
    DrawCircle({ {0, 0}, 1.0 }, true);  // 토성의 크기: 반지름 1.0

    // 타이탄 (토성의 위성)
    glPushMatrix();
    glRotated(timeIdx / 16.0 * 360.0, 0, 0, 1);  // 타이탄의 공전 (16일 주기)
    glTranslated(0.0, 2.0, 0.0);  // 타이탄의 토성으로부터의 거리
    glColor3f(0.5, 0, 0.5); // 보라색
    DrawCircle({ {0, 0}, 0.3 }, true);  // 타이탄의 크기: 반지름 0.3

    glPopMatrix(); // for Titan  타이탄 변환 복원
    glPopMatrix(); // for Saturn  토성 변환 복원


    glPopMatrix(); // for Sun
}
