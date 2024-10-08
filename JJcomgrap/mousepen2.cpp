#include "GL/glut.h"
#include <vector>

// 펜 두께 초기값
int penThickness = 1;

// 그려진 선분을 저장할 구조체와 벡터
struct Line {
    float x1, y1, x2, y2;
    int thickness;
};

std::vector<Line> lines; // 그려진 선들을 저장하는 벡터
bool Drawing = false;  // 현재 그리는 중인지 확인하는 플래그
float startX, startY;    // 선 그리기 시작 위치

// 화면을 그리는 함수
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 초기 화면 다 지우기
    glClear(GL_COLOR_BUFFER_BIT); // 화면 지우기

    glColor3f(0.0f, 0.0f, 0.0f); // 0.0 ~ 1.0, Red, Green, Blue

    // 저장된 선들을 화면에 그리기
    for (const auto& line : lines) {
        glLineWidth(line.thickness); // 펜 두께 설정
        glBegin(GL_LINES);
        glVertex2f(line.x1, line.y1);
        glVertex2f(line.x2, line.y2);
        glEnd();
    }

    glutSwapBuffers(); // 화면에 출력
}

// 화면 크기 조정 시 호출되는 함수
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, w, 0.0, h); // 2D 좌표계 설정
    glMatrixMode(GL_MODELVIEW);
}

// 마우스 버튼 클릭 시 호출되는 함수
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            // 그리기 시작 위치 저장
            Drawing = true;
            startX = x;
            startY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        }
        else if (state == GLUT_UP) {
            // 그리기 종료 후 선 저장
            Drawing = false;
            float endX = x;
            float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
            lines.push_back({ startX, startY, endX, endY, penThickness });
            glutPostRedisplay(); // 화면 갱신
        }
    }
}

// 마우스 이동 시 호출되는 함수
void motion(int x, int y) {
    if (Drawing) {
        // 마우스 이동 중 선을 그리며 저장
        float endX = x;
        float endY = glutGet(GLUT_WINDOW_HEIGHT) - y;
        lines.push_back({ startX, startY, endX, endY, penThickness });
        startX = endX;
        startY = endY;
        glutPostRedisplay(); // 화면 갱신
    }
}

// 키보드 입력 처리 함수
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': case '2': case '3': case '4': case '5':
        penThickness = key - '0'; // 펜 두께 변경
        break;
    case 'R':
    case 'r':
        lines.clear(); // 모든 선 지우기
        glutPostRedisplay(); // 화면 갱신
        break;
    }
}

// 메인 함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링 및 RGB 모드
    glutInitWindowSize(800, 600); // 윈도우 크기 설정
    glutCreateWindow("GLUT Drawing Application"); // 윈도우 생성

    glutDisplayFunc(display); // 디스플레이 콜백 함수 등록
    glutReshapeFunc(reshape); // 윈도우 크기 변경 콜백 함수 등록
    glutMouseFunc(mouse);     // 마우스 클릭 콜백 함수 등록
    glutMotionFunc(motion);   // 마우스 이동 콜백 함수 등록
    glutKeyboardFunc(keyboard); // 키보드 입력 콜백 함수 등록

    glutMainLoop(); // 메인 루프 실행
    return 0;
}
