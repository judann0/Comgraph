#include "GL/glut.h"
#include <cmath>
#include <vector>

// 화면 크기와 중심 좌표
const int width = 800;
const int height = 600;
const float center_x = width / 2;
const float center_y = height / 2;

// 원을 그리기 위한 구조체와 벡터
struct Circle {
    float x, y, radius;
    Circle(float x, float y, float r) : x(x), y(y), radius(r) {}
};

std::vector<float> drawCircle; // 사용자가 그린 경로 저장
Circle* correctCircle = nullptr; // 정답 원 저장
bool showCircle = false;  // 원을 표시할지 여부 확인

bool drawing = false; // 그리기 여부 확인
float startX, startY;   // 마우스 첫 클릭 좌표

// 화면을 그리는 함수
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 중심점 C를 그리기
    glColor3f(0.0, 0.0, 0.0); // 검정색
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(center_x, center_y);
    glEnd();

    // 사용자가 그린 경로를 출력
    if (!drawCircle.empty()) {
        glColor3f(0.0, 0.0, 1.0); // 파란색
        glBegin(GL_LINE_STRIP);
        for (size_t i = 0; i < drawCircle.size(); i += 2) {
            glVertex2f(drawCircle[i], drawCircle[i + 1]);
        }
        glEnd();
    }

    // 정답 원을 출력 (showCircle이 true일 때만 그리기)
    if (showCircle && correctCircle) {
        glColor3f(1.0, 0.0, 0.0); // 빨간색
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

// 마우스 클릭 시 호출되는 함수
void mouse(int button, int state, int x, int y) {
    y = height - y; // 좌표계를 OpenGL 좌표로 변환

    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN && !drawing) {
            // 첫 클릭 시 시작 좌표 저장
            startX = x;
            startY = y;
            drawing = true;
            drawCircle.clear();
            showCircle = false;  // 새로운 드로잉이 시작되면 원을 숨김
        }
        else if (state == GLUT_UP && drawing) {
            // 그리기 종료 시 정답 원을 계산
            drawing = false;
            float radius = sqrt(pow(startX - center_x, 2) + pow(startY - center_y, 2));
            correctCircle = new Circle(center_x, center_y, radius);
            showCircle = true;  // 원을 그리도록 설정
            glutPostRedisplay(); // 화면 갱신
        }
    }
}

// 마우스 이동 시 호출되는 함수
void motion(int x, int y) {
    if (drawing) {
        y = height - y; // 좌표계를 OpenGL 좌표로 변환
        drawCircle.push_back(x);
        drawCircle.push_back(y);
        glutPostRedisplay(); // 화면 갱신
    }
}

// 화면 크기 변경 시 호출되는 함수
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h);
    glMatrixMode(GL_MODELVIEW);
}

// 메인 함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("원 그리기 게임");

    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경 색상 설정
    glutDisplayFunc(display);  // 디스플레이 함수 등록
    glutReshapeFunc(reshape);  // 윈도우 크기 변경 함수 등록
    glutMouseFunc(mouse);      // 마우스 클릭 함수 등록
    glutMotionFunc(motion);    // 마우스 이동 함수 등록

    glutMainLoop(); // 메인 루프 실행
    return 0;
}
