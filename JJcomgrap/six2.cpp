#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>

#include <iostream>

// 정육면체를 초기화하는 함수
void InitMyMesh(pmp::SurfaceMesh& mesh) {
    // 크기 2인 정육면체의 절반 크기
    float halfSize = 1.0f; // 2의 반

    // 정육면체의 8개 정점 정의
    std::vector<pmp::SurfaceMesh::Vertex> vertices;
    vertices.push_back(mesh.add_vertex({ -halfSize, -halfSize, -halfSize })); // 0
    vertices.push_back(mesh.add_vertex({ halfSize, -halfSize, -halfSize })); // 1
    vertices.push_back(mesh.add_vertex({ halfSize,  halfSize, -halfSize })); // 2
    vertices.push_back(mesh.add_vertex({ -halfSize,  halfSize, -halfSize })); // 3
    vertices.push_back(mesh.add_vertex({ -halfSize, -halfSize,  halfSize })); // 4
    vertices.push_back(mesh.add_vertex({ halfSize, -halfSize,  halfSize })); // 5
    vertices.push_back(mesh.add_vertex({ halfSize,  halfSize,  halfSize })); // 6
    vertices.push_back(mesh.add_vertex({ -halfSize,  halfSize,  halfSize })); // 7

    // 정육면체의 6개 면 추가
    mesh.add_face(vertices[0], vertices[1], vertices[2], vertices[3]); // back face
    mesh.add_face(vertices[4], vertices[5], vertices[6], vertices[7]); // front face
    mesh.add_face(vertices[0], vertices[1], vertices[5], vertices[4]); // bottom face
    mesh.add_face(vertices[2], vertices[3], vertices[7], vertices[6]); // top face
    mesh.add_face(vertices[0], vertices[3], vertices[7], vertices[4]); // left face
    mesh.add_face(vertices[1], vertices[2], vertices[6], vertices[5]); // right face
}

int main() {
    // 메쉬 객체 생성
    pmp::SurfaceMesh mesh;

    // InitMyMesh 함수로 정육면체 초기화
    InitMyMesh(mesh);

    // 메쉬를 output.obj 파일로 저장
    if (pmp::write(mesh, "output.obj")) {
        std::cout << "Mesh successfully written to output.obj" << std::endl;
    }
    else {
        std::cerr << "Error writing mesh to output.obj" << std::endl;
    }

    return 0;
}
