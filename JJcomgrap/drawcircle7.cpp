#include "GL/glut.h"
#include <cmath>
#include <vector>

// ȭ�� ũ��� �߽� ��ǥ
int windowWidth = 800;
int windowHeight = 600;
float center_x = windowWidth / 2;
float center_y = windowHeight / 2;

// ���� �׸��� ���� ����ü�� ����
struct Circle {
    float x, y, radius;
    Circle(float x, float y, float r) : x(x), y(y), radius(r) {}
};

std::vector<float> drawCircle; // ����ڰ� �׸� ��� ����
Circle* correctCircle = nullptr; // ���� �� ����
bool showCircle = false;  // ���� ǥ������ ���� Ȯ��

bool drawing = false; // �׸��� ���� Ȯ��
float startX, startY;   // ���콺 ù Ŭ�� ��ǥ

// �Լ� ����
void display();
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void reshape(int w, int h);

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("�� �׸��� ����");

    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ����
    glutDisplayFunc(display);  // ���÷��� �Լ� ���
    glutReshapeFunc(reshape);  // ������ ũ�� ���� �Լ� ���
    glutMouseFunc(mouse);      // ���콺 Ŭ�� �Լ� ���
    glutMotionFunc(motion);    // ���콺 �̵� �Լ� ���

    glutMainLoop(); // ���� ���� ����
    return 0;
}

// ȭ���� �׸��� �Լ�
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // �߽��� C�� �׸���
    glColor3f(0.0, 0.0, 0.0); // ������
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(center_x, center_y);
    glEnd();

    // ����ڰ� �׸� ��θ� ���
    if (!drawCircle.empty()) {
        glColor3f(0.0, 0.0, 1.0); // �Ķ���
        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < drawCircle.size(); i += 2) {
            glVertex2f(drawCircle[i], drawCircle[i + 1]);
        }
        glEnd();
    }

    // ���� ���� ��� (showCircle�� true�� ���� �׸���)
    if (showCircle && correctCircle) {
        glColor3f(1.0, 0.0, 0.0); // ������
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
    y = windowHeight - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN && !drawing) {
            // ù Ŭ�� �� ���� ��ǥ ����
            startX = x;
            startY = y;
            drawing = true;
            drawCircle.clear();
            showCircle = false;  // ���ο� ������� ���۵Ǹ� ���� ����
        }
        else if (state == GLUT_UP && drawing) {
            // �׸��� ���� �� ���� ���� ���
            drawing = false;
            float radius = sqrt(pow(startX - center_x, 2) + pow(startY - center_y, 2));
            correctCircle = new Circle(center_x, center_y, radius);
            showCircle = true;  // ���� �׸����� ����
            glutPostRedisplay(); // ȭ�� ����
        }
    }
}

// ���콺 �̵� �� ȣ��Ǵ� �Լ�
void motion(int x, int y) {
    if (drawing) {
        y = windowHeight - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ
        drawCircle.push_back(x);
        drawCircle.push_back(y);
        glutPostRedisplay(); // ȭ�� ����
    }
}

// ȭ�� ũ�� ���� �� ȣ��Ǵ� �Լ�
void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;
    center_x = windowWidth / 2;
    center_y = windowHeight / 2;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
}
