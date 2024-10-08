//// ���� �� ����� �ڵ� �߰�, reshape âũ������ �ڵ� ����
//// bool showCircle = false;  // ���� ǥ������ ���� Ȯ��
//
//#include "GL/glut.h"
//#include <cmath>
//#include <vector>
//
//// ȭ�� ũ��� �߽� ��ǥ
//const int WIDTH = 800;
//const int HEIGHT = 600;
//const float CENTER_X = WIDTH / 2;
//const float CENTER_Y = HEIGHT / 2;
//
//// ���� �׸��� ���� ����ü�� ����
//struct Circle {
//    float x, y, radius;
//    Circle(float x, float y, float r) : x(x), y(y), radius(r) {}
//};
//
//std::vector<float> drawCircle; // ����ڰ� �׸� ��� ����
//Circle* correctCircle = nullptr; // ���� �� ����
//bool showCircle = false;  // ���� ǥ������ ���� Ȯ��
//
//bool Drawing = false; // �׸��� ���� Ȯ��
//float startX, startY;   // ���콺 ù Ŭ�� ��ǥ
//
//// ȭ���� �׸��� �Լ�
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // �߽��� C�� �׸���
//    glColor3f(0.0, 0.0, 0.0); // ������
//    glPointSize(5.0);
//    glBegin(GL_POINTS);
//    glVertex2f(CENTER_X, CENTER_Y);
//    glEnd();
//
//    // ����ڰ� �׸� ��θ� ���
//    if (!drawCircle.empty()) {
//        glColor3f(0.0, 0.0, 1.0); // �Ķ���
//        glBegin(GL_LINE_STRIP);
//        for (size_t i = 0; i < drawCircle.size(); i += 2) {
//            glVertex2f(drawCircle[i], drawCircle[i + 1]);
//        }
//        glEnd();
//    }
//
//    // ���� ���� ��� (showCircle�� true�� ���� �׸���)
//    if (showCircle && correctCircle) {
//        glColor3f(1.0, 0.0, 0.0); // ������
//        glBegin(GL_LINE_LOOP);
//        for (int i = 0; i <= 360; i++) {
//            float angle = i * 3.14159 / 180.0;
//            float x = correctCircle->x + cos(angle) * correctCircle->radius;
//            float y = correctCircle->y + sin(angle) * correctCircle->radius;
//            glVertex2f(x, y);
//        }
//        glEnd();
//    }
//
//    glutSwapBuffers();
//}
//
//// ���콺 Ŭ�� �� ȣ��Ǵ� �Լ�
//void mouse(int button, int state, int x, int y) {
//    y = HEIGHT - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ
//
//    if (button == GLUT_LEFT_BUTTON) {
//        if (state == GLUT_DOWN && !Drawing) {
//            // ù Ŭ�� �� ���� ��ǥ ����
//            startX = x;
//            startY = y;
//            Drawing = true;
//            drawCircle.clear();
//            showCircle = false;  // ���ο� ������� ���۵Ǹ� ���� ����
//        }
//        else if (state == GLUT_UP && Drawing) {
//            // �׸��� ���� �� ���� ���� ���
//            Drawing = false;
//            float radius = sqrt(pow(startX - CENTER_X, 2) + pow(startY - CENTER_Y, 2));
//            correctCircle = new Circle(CENTER_X, CENTER_Y, radius);
//            showCircle = true;  // ���� �׸����� ����
//            glutPostRedisplay(); // ȭ�� ����
//        }
//    }
//}
//
//// ���콺 �̵� �� ȣ��Ǵ� �Լ�
//void motion(int x, int y) {
//    if (Drawing) {
//        y = HEIGHT - y; // ��ǥ�踦 OpenGL ��ǥ�� ��ȯ
//        drawCircle.push_back(x);
//        drawCircle.push_back(y);
//        glutPostRedisplay(); // ȭ�� ����
//    }
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutCreateWindow("�� �׸��� ����");
//
//    glClearColor(1.0, 1.0, 1.0, 1.0); // ��� ���� ����
//    glutDisplayFunc(display);  // ���÷��� �Լ� ���
//    glutMouseFunc(mouse);      // ���콺 Ŭ�� �Լ� ���
//    glutMotionFunc(motion);    // ���콺 �̵� �Լ� ���
//
//    glutMainLoop(); // ���� ���� ����
//    return 0;
//}
