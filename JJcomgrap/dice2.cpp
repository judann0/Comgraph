#include <GL/glut.h>

// 그리기 함수
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 화면과 깊이 버퍼 초기화

    // 카메라 설정 (카메라 위치를 z축 뒤로 이동)
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // 카메라 위치 (x, y, z)
        0.0, 0.0, 0.0,  // 카메라가 바라보는 지점 (x, y, z)
        0.0, 1.0, 0.0); // 업 벡터 (x, y, z)

    // 큐브를 그리기 시작
    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Back face
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Left face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Top face
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Bottom face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glutSwapBuffers(); // 더블 버퍼링을 사용하여 화면 갱신
}

// 윈도우 리사이즈 시 호출되는 함수
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // 새로운 윈도우 크기 설정

    glMatrixMode(GL_PROJECTION);      // 투영 행렬로 변경
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0); // 원근 투영 설정
    glMatrixMode(GL_MODELVIEW);       // 다시 모델뷰 행렬로 변경
}

// 메인 함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // 윈도우 크기 변경 시 호출되는 함수 설정

    glutMainLoop();

    return 0;
}
