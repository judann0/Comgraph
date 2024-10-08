//// ���� �� ����� �ڵ� �߰�, reshape âũ������ �ڵ� ����, �ʱ�ȭ �� ���� ����ȭ
//// bool showCircle = false;  // ���� ǥ������ ���� Ȯ��
//
//#include "GL/glut.h"
//#include <cmath>
//#include <vector>
//
//// ȭ�� ũ��� �߽� ��ǥ
//const int WIDTH = 800, HEIGHT = 600;
//const float CENTER_X = WIDTH / 2, CENTER_Y = HEIGHT / 2;
//
//// �� ����ü
//struct Circle {
//    float x, y, radius;
//};
//
//std::vector<float> drawCircle;   // ����ڰ� �׸� ���
//Circle correctCircle;           // ���� ��
//bool showCircle = false, Drawing = false;
//float startX, startY;           // ���콺 ù Ŭ�� ��ǥ
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // �߽��� C
//    glColor3f(0, 0, 0);
//    glPointSize(5.0);
//    glBegin(GL_POINTS);
//    glVertex2f(CENTER_X, CENTER_Y);
//    glEnd();
//
//    // �׸� ���
//    if (!drawCircle.empty()) {
//        glColor3f(0, 0, 1);
//        glBegin(GL_LINE_STRIP);
//        for (size_t i = 0; i < drawCircle.size(); i += 2)
//            glVertex2f(drawCircle[i], drawCircle[i + 1]);
//        glEnd();
//    }
//
//    // ���� ��
//    if (showCircle) {
//        glColor3f(1, 0, 0);
//        glBegin(GL_LINE_LOOP);
//        for (int i = 0; i <= 360; i++) {
//            float angle = i * 3.14159 / 180.0;
//            glVertex2f(correctCircle.x + cos(angle) * correctCircle.radius,
//                correctCircle.y + sin(angle) * correctCircle.radius);
//        }
//        glEnd();
//    }
//
//    glutSwapBuffers();
//}
//
//void mouse(int button, int state, int x, int y) {
//    y = HEIGHT - y;
//    if (button == GLUT_LEFT_BUTTON) {
//        if (state == GLUT_DOWN && !Drawing) {
//            startX = x;
//            startY = y;
//            Drawing = true;
//            drawCircle.clear();
//            showCircle = false;
//        }
//        else if (state == GLUT_UP && Drawing) {
//            Drawing = false;
//            correctCircle = { CENTER_X, CENTER_Y, sqrt(pow(startX - CENTER_X, 2) + pow(startY - CENTER_Y, 2)) };
//            showCircle = true;
//            glutPostRedisplay();
//        }
//    }
//}
//
//void motion(int x, int y) {
//    if (Drawing) {
//        y = HEIGHT - y;
//        drawCircle.push_back(x);
//        drawCircle.push_back(y);
//        glutPostRedisplay();
//    }
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutCreateWindow("�� �׸��� ����");
//
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glutDisplayFunc(display);
//    glutMouseFunc(mouse);
//    glutMotionFunc(motion);
//
//    glutMainLoop();
//    return 0;
//}
