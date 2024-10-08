#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>
#include <vector>
#include <filesystem>

// 정육면체를 초기화하는 함수
void InitMyMesh(pmp::SurfaceMesh& mesh) {
    // 크기 2인 정육면체의 절반 크기
    float halfSize = 1.0f; // 2의 반

    // 정육면체의 8개 정점 정의
    std::vector<pmp::Vertex> vertices(8);

    // pmp::Point를 사용하여 정점 추가
    vertices[0] = mesh.add_vertex(pmp::Point(-halfSize, -halfSize, -halfSize)); // 0
    vertices[1] = mesh.add_vertex(pmp::Point(halfSize, -halfSize, -halfSize));  // 1
    vertices[2] = mesh.add_vertex(pmp::Point(halfSize, halfSize, -halfSize));   // 2
    vertices[3] = mesh.add_vertex(pmp::Point(-halfSize, halfSize, -halfSize));  // 3
    vertices[4] = mesh.add_vertex(pmp::Point(-halfSize, -halfSize, halfSize));  // 4
    vertices[5] = mesh.add_vertex(pmp::Point(halfSize, -halfSize, halfSize));   // 5
    vertices[6] = mesh.add_vertex(pmp::Point(halfSize, halfSize, halfSize));    // 6
    vertices[7] = mesh.add_vertex(pmp::Point(-halfSize, halfSize, halfSize));   // 7

    // 정육면체의 6개 면 추가 (사각형 면을 두 개의 삼각형으로 나눔)
    // back face
    mesh.add_face({ vertices[0], vertices[1], vertices[2] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[0], vertices[2], vertices[3] }); // 두 번째 삼각형

    // front face
    mesh.add_face({ vertices[4], vertices[5], vertices[6] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[4], vertices[6], vertices[7] }); // 두 번째 삼각형

    // bottom face
    mesh.add_face({ vertices[0], vertices[1], vertices[5] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[0], vertices[5], vertices[4] }); // 두 번째 삼각형

    // top face
    mesh.add_face({ vertices[2], vertices[3], vertices[7] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[2], vertices[7], vertices[6] }); // 두 번째 삼각형

    // left face
    mesh.add_face({ vertices[0], vertices[3], vertices[7] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[0], vertices[7], vertices[4] }); // 두 번째 삼각형

    // right face
    mesh.add_face({ vertices[1], vertices[2], vertices[6] }); // 첫 번째 삼각형
    mesh.add_face({ vertices[1], vertices[6], vertices[5] }); // 두 번째 삼각형
}

int main() {
    // 메쉬 객체 생성
    pmp::SurfaceMesh mesh;


    // input.obj 파일에서 메쉬 읽기
    pmp::read(mesh, "input.obj");

    // 메쉬를 초기화하기 위해 InitMyMesh 함수 호출
    InitMyMesh(mesh);

    // 메쉬를 output.obj 파일로 저장
    pmp::write(mesh, "output.obj");

    //// 파일이 잘 저장되었는지 확인
    //if (std::filesystem::exists("output.obj")) {
    //    std::cout << "Mesh successfully written to output.obj" << std::endl;
    //}
    //else {
    //    std::cerr << "Error writing mesh to output.obj" << std::endl;
    //}

    return 0;


}
