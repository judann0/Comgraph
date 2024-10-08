//#include "gl/glut.h"
//#include <pmp/surface_mesh.h>
//#include <pmp/io/io.h>
//#include <iostream>
//
//// 윈도우 크기
//int width = 500, height = 500;
//
//// 메쉬 객체
//pmp::SurfaceMesh mesh;
//
//// 노멀 벡터를 저장하는 vertex normal과 face normal 속성 가져오기
//auto vnormals = mesh.vertex_property<pmp::Normal>("v:normal");
//auto fnormals = mesh.face_property<pmp::Normal>("f:normal");
//
//
//// InitMyMesh 함수 정의 (크기가 2인 정육면체 생성, 각 면을 사각형으로 추가)
//void InitMyMesh() {
//    // 정육면체의 크기
//    const float cubeSize = 2.0f;
//
//    // 정육면체 꼭짓점 추가
//    const auto v0 = mesh.add_vertex(pmp::Point(0, 0, 0));
//    const auto v1 = mesh.add_vertex(pmp::Point(cubeSize, 0, 0));
//    const auto v2 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, 0));
//    const auto v3 = mesh.add_vertex(pmp::Point(0, cubeSize, 0));
//    const auto v4 = mesh.add_vertex(pmp::Point(0, 0, cubeSize));
//    const auto v5 = mesh.add_vertex(pmp::Point(cubeSize, 0, cubeSize));
//    const auto v6 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, cubeSize));
//    const auto v7 = mesh.add_vertex(pmp::Point(0, cubeSize, cubeSize));
//
//    // 정육면체의 각 면(사각형)을 정의 (6개의 면)
//    //mesh.add_quad(v0, v1, v2, v3); // 아래쪽 면
//    //mesh.add_quad(v4, v5, v6, v7); // 위쪽 면
//    //mesh.add_quad(v0, v4, v7, v3); // 앞쪽 면
//    //mesh.add_quad(v1, v5, v6, v2); // 뒤쪽 면
//    //mesh.add_quad(v0, v1, v5, v4); // 왼쪽 면
//    //mesh.add_quad(v3, v7, v6, v2); // 오른쪽 면
//
//    mesh.add_quad(v4, v5, v6, v7);
//    mesh.add_quad(v0, v3, v2, v1);
//    mesh.add_quad(v0, v4, v7, v3);
//
//    // 메쉬 정보 출력
//    std::cout << "vertices: " << mesh.n_vertices() << std::endl;
//    std::cout << "edges: " << mesh.n_edges() << std::endl;
//    std::cout << "faces: " << mesh.n_faces() << std::endl;
//
//
//}
//
//
//// 메쉬 그리기 함수
//void DrawMesh() {
//    glBegin(GL_QUADS); // 사각형으로 그리기 시작
//    for (auto f : mesh.faces()) {
//        glNormal3fv(&fnormals[f][0]); // 면의 노멀 벡터
//        for (auto v : mesh.vertices(f)) {
//            glVertex3fv(&mesh.position(v)[0]); // 꼭짓점 좌표
//        }
//    }
//    glEnd();
//}
//
//
//// 디스플레이 콜백 함수
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    // 메쉬 그리기
//    DrawMesh();
//
//    glutSwapBuffers(); // 버퍼 교체
//}
//
//// 초기화 함수
//void init() {
//    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화
//    glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색 설정
//
//    // 메쉬 초기화
//    InitMyMesh();
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    // GLUT 초기화
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(width, height);
//    glutCreateWindow("Cube Mesh");
//
//    // 초기화 함수 호출
//    init();
//
//    // 디스플레이 콜백 등록
//    glutDisplayFunc(display);
//
//    // 메인 루프 실행
//    glutMainLoop();
//
//    return 0;
//}
