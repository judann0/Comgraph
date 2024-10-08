#include "GL/glut.h"
#include <cmath>
#include <vector>

// ȭ�� ũ��� �߽� ��ǥ
const int WIDTH = 800;
const int HEIGHT = 600;
const float CENTER_X = WIDTH / 2;
const float CENTER_Y = HEIGHT / 2;

// ���� �׸��� ���� ����ü�� ����
struct Circle {
    float x, y, radius;
    Circle(float x, float y, float r) : x(x), y(y), radius(r) {}
};

std::vector<float> drawnPath; // ����ڰ� �׸� ��� ����
Circle* correctCircle = nullptr; // ���� �� ����

bool isDrawing = false; // �׸��� ���� Ȯ��
float startX, startY;   // ���콺 ù Ŭ�� ��ǥ

// ȭ���� �׸��� �Լ�
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // �߽��� C�� �׸���
    glColor3f(1.0, 0.0, 0.0); // ������
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(CENTER_X, CENTER_Y);
    glEnd();

    // ����ڰ� �׸� ��θ� ���
    if (!drawnPath.empty()) {
        glColor3f(0.0, 0.0, 1.0); // �Ķ���
        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < drawnPath.size(); i += 2) {
            glVertex2f(drawnPath[i], drawnPath[i + 1]);
        }
        glEnd();
    }

    // ���� ���� ���
    if (correctCircle) {
        glColor3f(0.0, 1.0, 0.0); // �ʷϻ�
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            float x = correctCircle->x + cos(angle) * correctCircle->radius;
            float y = correctCircle->y + sin(angle) * correctCircle->radius;
            glVertex2f(x, y);
        }
        glEnd();
    }

    glutSwapBuffers();
}

// ���콺 Ŭ�� �� ȣ��Ǵ� �Լ�
void mouse(int button, int state, int x, int y) {
    y = HEIGHT - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN && !isDrawing) {
            // ù Ŭ�� �� ���� ��ǥ ����
            startX = x;
            startY = y;
            isDrawing = true;
            drawnPath.clear();
        }
        else if (state == GLUT_UP && isDrawing) {
            // �׸��� ���� �� ���� ���� ���
            isDrawing = false;
            float radius = sqrt(pow(startX - CENTER_X, 2) + pow(startY - CENTER_Y, 2));
            correctCircle = new Circle(CENTER_X, CENTER_Y, radius);
            glutPostRedisplay(); // ȭ�� ����
        }
    }
}

// ���콺 �̵� �� ȣ��Ǵ� �Լ�
void motion(int x, int y) {
    if (isDrawing) {
        y = HEIGHT - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ
        drawnPath.push_back(x);
        drawnPath.push_back(y);
        glutPostRedisplay(); // ȭ�� ����
    }
}

// ȭ�� ũ�� ���� �� ȣ��Ǵ� �Լ�
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("�� �׸��� ����");

    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ����
    glutDisplayFunc(display);  // ���÷��� �Լ� ���
    glutReshapeFunc(reshape);  // ������ ũ�� ���� �Լ� ���
    glutMouseFunc(mouse);      // ���콺 Ŭ�� �Լ� ���
    glutMotionFunc(motion);    // ���콺 �̵� �Լ� ���

    glutMainLoop(); // ���� ���� ����
    return 0;
}
