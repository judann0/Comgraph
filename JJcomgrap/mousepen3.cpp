#include "GL/glut.h"
#include "cstdio"
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

// �Լ� ����
void display();
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void timer(int value);
void keyboard(unsigned char key, int x, int y);

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸� �� RGB ���
    glutInitWindowSize(800, 600); // ������ ũ�� ����
    glutCreateWindow("���콺 ��"); // ������ ����

    glutDisplayFunc(display); // ���÷��� �ݹ� �Լ� ���
    glutReshapeFunc(reshape); // ������ ũ�� ���� �ݹ� �Լ� ���
    glutMouseFunc(mouse);     // ���콺 Ŭ�� �ݹ� �Լ� ���
    glutMotionFunc(motion);   // ���콺 �̵� �ݹ� �Լ� ���
    glutKeyboardFunc(keyboard); // Ű���� �Է� �ݹ� �Լ� ���
    glutTimerFunc(100, timer, 0); // Ÿ�̸� �ݹ� ��� (100ms �ֱ�)

    glutMainLoop(); // ���� ���� ����
    return 0;
}

// ȭ���� �׸��� �Լ�
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // �ʱ� ȭ�� �� �����
    glClear(GL_COLOR_BUFFER_BIT); // ȭ�� �����

    glColor3f(0.0f, 0.0f, 0.0f); // �⺻ �� ���� (������)

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
        }
    }
}

// ���콺 �̵� �� ȣ��Ǵ� �Լ�
void motion(int x, int y) {
    printf("Mouse is moving at (%d, %d)\n", x, y);
    if (Drawing) {
        // ���콺 �̵� �� ���� �׸��� ����
        float endX = x;
        float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        lines.push_back({ startX, startY, endX, endY, penThickness });
        startX = endX;
        startY = endY;
    }
}

// Ÿ�̸� �ݹ� �Լ� (100ms���� ȣ��)
void timer(int value) {
    glutPostRedisplay(); // ȭ�� ����
    glutTimerFunc(100, timer, 0);  // �ٽ� Ÿ�̸� ���� (100ms �� �����)
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
        break;
    }
}
