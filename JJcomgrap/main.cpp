#include "cstdio"
#include "GL/glut.h"


/* Callback function prototypes. */
void display();
void keyboard(unsigned char key, int x, int y); 
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void special(int key, int x, int y);
void entry(int state);
void idle();
void timer(int value);

/* Main function. */
int main(int argc, char** argv)
{
    /* GLUT initializations. */
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("AIE305 Computer Graphics");

    /* Call back functions. */
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutSpecialFunc(special);
    glutEntryFunc(entry);
    //glutIdleFunc(idle);
    glutTimerFunc(1000, timer, 0);


    /* Main loop. */
    glutMainLoop();

    return 0;
}

/* Callback functions. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 초기 화면 다 지우기
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 1.0f); // 0.0 ~ 1.0, Red, Green, Blue

    glBegin(GL_POLYGON); // GL_POLYGON, GL_TRIANGLES, GL_QUADS, GL_LINES
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    //glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFinish();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ESC
        exit(0);
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        printf("Mouse left button is pressed at (%d, %d)\n", x, y);
    }

}

void motion(int x, int y)
{
    printf("Mouse is moving at (%d, %d)\n", x, y);
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_F1)
        printf("F1 key is pressed at (%d, %d)\n", x, y);
}

void entry(int state)
{
    if (state == GLUT_ENTERED)
        printf("Mouse entered the window\n");
    else if (state == GLUT_LEFT)
        printf("Mouse left the window\n");
}

void idle()
{
    printf("Idle function is called\n");
}

void timer(int value)
{
    printf("Timer function is called\n");
    glutTimerFunc(1000, timer, 0);
}
