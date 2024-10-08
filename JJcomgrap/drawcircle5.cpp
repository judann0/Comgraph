//// 정답 원 지우는 코드 추가, reshape 창크기조정 코드 삭제, 초기화 및 선언 간결화
//// bool showCircle = false;  // 원을 표시할지 여부 확인
//
//#include "GL/glut.h"
//#include <cmath>
//#include <vector>
//
//// 화면 크기와 중심 좌표
//const int WIDTH = 800, HEIGHT = 600;
//const float CENTER_X = WIDTH / 2, CENTER_Y = HEIGHT / 2;
//
//// 원 구조체
//struct Circle {
//    float x, y, radius;
//};
//
//std::vector<float> drawCircle;   // 사용자가 그린 경로
//Circle correctCircle;           // 정답 원
//bool showCircle = false, Drawing = false;
//float startX, startY;           // 마우스 첫 클릭 좌표
//
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 중심점 C
//    glColor3f(0, 0, 0);
//    glPointSize(5.0);
//    glBegin(GL_POINTS);
//    glVertex2f(CENTER_X, CENTER_Y);
//    glEnd();
//
//    // 그린 경로
//    if (!drawCircle.empty()) {
//        glColor3f(0, 0, 1);
//        glBegin(GL_LINE_STRIP);
//        for (size_t i = 0; i < drawCircle.size(); i += 2)
//            glVertex2f(drawCircle[i], drawCircle[i + 1]);
//        glEnd();
//    }
//
//    // 정답 원
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
//    glutCreateWindow("원 그리기 게임");
//
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glutDisplayFunc(display);
//    glutMouseFunc(mouse);
//    glutMotionFunc(motion);
//
//    glutMainLoop();
//    return 0;
//}
