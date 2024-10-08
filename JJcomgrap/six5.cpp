#include "gl/glut.h"
#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>

// 윈도우 크기
int width = 500, height = 500;

// 메쉬 객체
pmp::SurfaceMesh mesh;

// InitMyMesh 함수 정의 (크기가 2인 정육면체 생성, 각 면을 두 개의 삼각형으로 나눔)
void InitMyMesh() {
    // 정육면체 꼭짓점 추가
    auto v0 = mesh.add_vertex(pmp::Point(-1, -1, -1));
    auto v1 = mesh.add_vertex(pmp::Point(1, -1, -1));
    auto v2 = mesh.add_vertex(pmp::Point(1, 1, -1));
    auto v3 = mesh.add_vertex(pmp::Point(-1, 1, -1));
    auto v4 = mesh.add_vertex(pmp::Point(-1, -1, 1));
    auto v5 = mesh.add_vertex(pmp::Point(1, -1, 1));
    auto v6 = mesh.add_vertex(pmp::Point(1, 1, 1));
    auto v7 = mesh.add_vertex(pmp::Point(-1, 1, 1));

    try {
        // 정육면체의 각 면을 두 개의 삼각형으로 나누어 추가
        mesh.add_triangle(v0, v1, v2); // 아래 면 첫 번째 삼각형
        mesh.add_triangle(v0, v2, v3); // 아래 면 두 번째 삼각형

        mesh.add_triangle(v4, v5, v6); // 위 면 첫 번째 삼각형
        mesh.add_triangle(v4, v6, v7); // 위 면 두 번째 삼각형

        mesh.add_triangle(v0, v1, v5); // 앞 면 첫 번째 삼각형
        mesh.add_triangle(v0, v5, v4); // 앞 면 두 번째 삼각형

        mesh.add_triangle(v2, v3, v7); // 뒤 면 첫 번째 삼각형
        mesh.add_triangle(v2, v7, v6); // 뒤 면 두 번째 삼각형

        mesh.add_triangle(v0, v3, v7); // 왼쪽 면 첫 번째 삼각형
        mesh.add_triangle(v0, v7, v4); // 왼쪽 면 두 번째 삼각형

        mesh.add_triangle(v1, v2, v6); // 오른쪽 면 첫 번째 삼각형
        mesh.add_triangle(v1, v6, v5); // 오른쪽 면 두 번째 삼각형

        // 메쉬를 파일로 저장 (output.obj)
        pmp::write(mesh, "output.obj");
        std::cout << "OBJ 파일이 'output.obj'로 저장되었습니다.\n";
    }
    catch (const pmp::TopologyException& e) {
        std::cerr << "TopologyException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "예외 발생: " << e.what() << std::endl;
    }
}

// 디스플레이 콜백 함수
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();
    glutSwapBuffers();
}

// 윈도우 크기 조정 콜백 함수
void reshape(int w, int h) {
    if (h == 0)
        h = 1;
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
}

// 메인 함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Cube OBJ Export");

    // InitMyMesh() 함수 호출하여 정육면체 생성 및 OBJ 파일로 저장
    InitMyMesh();

    // GLUT 콜백 함수 등록
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // GLUT 메인 루프 시작
    glutMainLoop();

    return 0;
}
