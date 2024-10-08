// 정답 원 지우는 코드 추가
// bool drawing = false; // 그리기 여부 확인

#include "GL/glut.h"
#include <cmath>
#include <vector>

// 화면 크기와 중심 좌표
const int width = 800;
const int height = 600;
const float center_x = width / 2;
const float center_y = height / 2;

// 원을 그리기 위한 구조체와 벡터
struct circle {
    float x, y, radius;
    circle(float x, float y, float r) : x(x), y(y), radius(r) {}
};

std::vector<float> drawcircle; // 사용자가 그린 경로 저장
circle* correctcircle = nullptr; // 정답 원 저장
bool showcircle = false;  // 원을 표시할지 여부 확인

bool drawing = false; // 그리기 여부 확인
float startx, starty;   // 마우스 첫 클릭 좌표

// 화면을 그리는 함수
void display() {
    glclear(gl_color_buffer_bit);

    // 중심점 c를 그리기
    glcolor3f(0.0, 0.0, 0.0); // 검정색
    glpointsize(5.0);
    glbegin(gl_points);
    glvertex2f(center_x, center_y);
    glend();

    // 사용자가 그린 경로를 출력
    if (!drawcircle.empty()) {
        glcolor3f(0.0, 0.0, 1.0); // 파란색
        glbegin(gl_line_strip);
        for (size_t i = 0; i < drawcircle.size(); i += 2) {
            glvertex2f(drawcircle[i], drawcircle[i + 1]);
        }
        glend();
    }

    // 정답 원을 출력 (showcircle이 true일 때만 그리기)
    if (showcircle && correctcircle) {
        glcolor3f(1.0, 0.0, 0.0); // 빨간색
        glbegin(gl_line_loop);
        for (int i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            float x = correctcircle->x + cos(angle) * correctcircle->radius;
            float y = correctcircle->y + sin(angle) * correctcircle->radius;
            glvertex2f(x, y);
        }
        glend();
    }

    glutswapbuffers();
}

// 마우스 클릭 시 호출되는 함수
void mouse(int button, int state, int x, int y) {
    y = height - y; // 좌표계를 opengl 좌표로 변환

    if (button == glut_left_button) {
        if (state == glut_down && !drawing) {
            // 첫 클릭 시 시작 좌표 저장
            startx = x;
            starty = y;
            drawing = true;
            drawcircle.clear();
            showcircle = false;  // 새로운 드로잉이 시작되면 원을 숨김
        }
        else if (state == glut_up && drawing) {
            // 그리기 종료 시 정답 원을 계산
            drawing = false;
            float radius = sqrt(pow(startx - center_x, 2) + pow(starty - center_y, 2));
            correctcircle = new circle(center_x, center_y, radius);
            showcircle = true;  // 원을 그리도록 설정
            glutpostredisplay(); // 화면 갱신
        }
    }
}

// 마우스 이동 시 호출되는 함수
void motion(int x, int y) {
    if (drawing) {
        y = height - y; // 좌표계를 opengl 좌표로 변환
        drawcircle.push_back(x);
        drawcircle.push_back(y);
        glutpostredisplay(); // 화면 갱신
    }
}

// 화면 크기 변경 시 호출되는 함수
void reshape(int w, int h) {
    glviewport(0, 0, w, h);
    glmatrixmode(gl_projection);
    glloadidentity();
    gluortho2d(0.0, w, 0.0, h);
    glmatrixmode(gl_modelview);
}

// 메인 함수
int main(int argc, char** argv) {
    glutinit(&argc, argv);
    glutinitdisplaymode(glut_double | glut_rgb);
    glutinitwindowsize(width, height);
    glutcreatewindow("원 그리기 게임");

    glclearcolor(1.0, 1.0, 1.0, 1.0); // 배경 색상 설정
    glutdisplayfunc(display);  // 디스플레이 함수 등록
    glutreshapefunc(reshape);  // 윈도우 크기 변경 함수 등록
    glutmousefunc(mouse);      // 마우스 클릭 함수 등록
    glutmotionfunc(motion);    // 마우스 이동 함수 등록

    glutmainloop(); // 메인 루프 실행
    return 0;
}
