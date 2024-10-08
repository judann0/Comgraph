#include "GL/glut.h"
#include <vector>

// 펜 두께 초기값
int penThickness = 1;

// 그려진 선분을 저장할 구조체와 벡터
struct Line {
    float x1, y1, x2, y2;
    int thickness;
};

std::vector<Line> lines;
bool Drawing = false;
float startX, startY;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 그려진 선분을 화면에 출력
    for (const auto& line : lines) {
        glLineWidth(line.thickness);
        glBegin(GL_LINES);
        glVertex2f(line.x1, line.y1);
        glVertex2f(line.x2, line.y2);
        glEnd();
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            Drawing = true;
            startX = x;
            startY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        }
        else if (state == GLUT_UP) {
            Drawing = false;
            float endX = x;
            float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
            lines.push_back({ startX, startY, endX, endY, penThickness });
            glutPostRedisplay();
        }
    }
}

void motion(int x, int y) {
    if (Drawing) {
        float endX = x;
        float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        lines.push_back({ startX, startY, endX, endY, penThickness });
        startX = endX;
        startY = endY;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': case '2': case '3': case '4': case '5':
        penThickness = key - '0';
        break;
    case 'R':
    case 'r':
        lines.clear();
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GLUT Drawing Application");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
