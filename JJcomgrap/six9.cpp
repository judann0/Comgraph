#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include "gl/glut.h"

// 메쉬 객체
pmp::SurfaceMesh mesh;

// 정육면체를 초기화하는 함수
void InitMyMesh(pmp::SurfaceMesh& mesh) {
    // 정육면체의 크기
    const float cubeSize = 2.0f;

    // 정육면체 꼭짓점 추가
    const auto v0 = mesh.add_vertex(pmp::Point(0, 0, 0));
    const auto v1 = mesh.add_vertex(pmp::Point(cubeSize, 0, 0));
    const auto v2 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, 0));
    const auto v3 = mesh.add_vertex(pmp::Point(0, cubeSize, 0));
    const auto v4 = mesh.add_vertex(pmp::Point(0, 0, cubeSize));
    const auto v5 = mesh.add_vertex(pmp::Point(cubeSize, 0, cubeSize));
    const auto v6 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, cubeSize));
    const auto v7 = mesh.add_vertex(pmp::Point(0, cubeSize, cubeSize));

    // 정육면체의 각 면(사각형)을 정의 (6개의 면)
    mesh.add_quad(v4, v5, v6, v7);
    mesh.add_quad(v0, v3, v2, v1);
    mesh.add_quad(v0, v4, v7, v3);
    mesh.add_quad(v1, v5, v4, v0);
    mesh.add_quad(v1, v2, v6, v5);
    mesh.add_quad(v3, v7, v6, v2);

    // 메쉬 정보 출력
    std::cout << "vertices: " << mesh.n_vertices() << std::endl;
    std::cout << "edges: " << mesh.n_edges() << std::endl;
    std::cout << "faces: " << mesh.n_faces() << std::endl;
}

int main() {
    // 메쉬를 초기화하기 위해 InitMyMesh 함수 호출
    InitMyMesh(mesh);

    // 메쉬를 output.obj 파일로 저장
    pmp::write(mesh, "output.obj");
   
    // 파일이 잘 저장되었는지 확인
    if (std::filesystem::exists("output.obj")) {
        std::cout << "Mesh successfully written to output.obj" << std::endl;
    }
    else {
        std::cerr << "Error writing mesh to output.obj" << std::endl;
    }

    // 프로그램이 종료되기 전에 사용자 입력 대기
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.ignore(); // Enter 키를 기다림

    return 0;
}
