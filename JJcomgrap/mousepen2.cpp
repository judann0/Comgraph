#include "GL/glut.h"
#include <vector>

// �� �β� �ʱⰪ
int penThickness = 1;

// �׷��� ������ ������ ����ü�� ����
struct Line {
    float x1, y1, x2, y2;
    int thickness;
};

std::vector<Line> lines; // �׷��� ������ �����ϴ� ����
bool Drawing = false;  // ���� �׸��� ������ Ȯ���ϴ� �÷���
float startX, startY;    // �� �׸��� ���� ��ġ

// ȭ���� �׸��� �Լ�
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �ʱ� ȭ�� �� �����
    glClear(GL_COLOR_BUFFER_BIT); // ȭ�� �����

    glColor3f(0.0f, 0.0f, 0.0f); // 0.0 ~ 1.0, Red, Green, Blue

    // ����� ������ ȭ�鿡 �׸���
    for (const auto& line : lines) {
        glLineWidth(line.thickness); // �� �β� ����
        glBegin(GL_LINES);
        glVertex2f(line.x1, line.y1);
        glVertex2f(line.x2, line.y2);
        glEnd();
    }

    glutSwapBuffers(); // ȭ�鿡 ���
}

// ȭ�� ũ�� ���� �� ȣ��Ǵ� �Լ�
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h); // 2D ��ǥ�� ����
    glMatrixMode(GL_MODELVIEW);
}

// ���콺 ��ư Ŭ�� �� ȣ��Ǵ� �Լ�
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // �׸��� ���� ��ġ ����
            Drawing = true;
            startX = x;
            startY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        }
        else if (state == GLUT_UP) {
            // �׸��� ���� �� �� ����
            Drawing = false;
            float endX = x;
            float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
            lines.push_back({ startX, startY, endX, endY, penThickness });
            glutPostRedisplay(); // ȭ�� ����
        }
    }
}

// ���콺 �̵� �� ȣ��Ǵ� �Լ�
void motion(int x, int y) {
    if (Drawing) {
        // ���콺 �̵� �� ���� �׸��� ����
        float endX = x;
        float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        lines.push_back({ startX, startY, endX, endY, penThickness });
        startX = endX;
        startY = endY;
        glutPostRedisplay(); // ȭ�� ����
    }
}

// Ű���� �Է� ó�� �Լ�
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': case '2': case '3': case '4': case '5':
        penThickness = key - '0'; // �� �β� ����
        break;
    case 'R':
    case 'r':
        lines.clear(); // ��� �� �����
        glutPostRedisplay(); // ȭ�� ����
        break;
    }
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸� �� RGB ���
    glutInitWindowSize(800, 600); // ������ ũ�� ����
    glutCreateWindow("GLUT Drawing Application"); // ������ ����

    glutDisplayFunc(display); // ���÷��� �ݹ� �Լ� ���
    glutReshapeFunc(reshape); // ������ ũ�� ���� �ݹ� �Լ� ���
    glutMouseFunc(mouse);     // ���콺 Ŭ�� �ݹ� �Լ� ���
    glutMotionFunc(motion);   // ���콺 �̵� �ݹ� �Լ� ���
    glutKeyboardFunc(keyboard); // Ű���� �Է� �ݹ� �Լ� ���

    glutMainLoop(); // ���� ���� ����
    return 0;
}
