#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>

#include <iostream>

// ������ü�� �ʱ�ȭ�ϴ� �Լ�
void InitMyMesh(pmp::SurfaceMesh& mesh) {
    // ũ�� 2�� ������ü�� ���� ũ��
    float halfSize = 1.0f; // 2�� ��

    // ������ü�� 8�� ���� ����
    std::vector<pmp::SurfaceMesh::Vertex> vertices;
    vertices.push_back(mesh.add_vertex({ -halfSize, -halfSize, -halfSize })); // 0
    vertices.push_back(mesh.add_vertex({ halfSize, -halfSize, -halfSize })); // 1
    vertices.push_back(mesh.add_vertex({ halfSize,  halfSize, -halfSize })); // 2
    vertices.push_back(mesh.add_vertex({ -halfSize,  halfSize, -halfSize })); // 3
    vertices.push_back(mesh.add_vertex({ -halfSize, -halfSize,  halfSize })); // 4
    vertices.push_back(mesh.add_vertex({ halfSize, -halfSize,  halfSize })); // 5
    vertices.push_back(mesh.add_vertex({ halfSize,  halfSize,  halfSize })); // 6
    vertices.push_back(mesh.add_vertex({ -halfSize,  halfSize,  halfSize })); // 7

    // ������ü�� 6�� �� �߰�
    mesh.add_face(vertices[0], vertices[1], vertices[2], vertices[3]); // back face
    mesh.add_face(vertices[4], vertices[5], vertices[6], vertices[7]); // front face
    mesh.add_face(vertices[0], vertices[1], vertices[5], vertices[4]); // bottom face
    mesh.add_face(vertices[2], vertices[3], vertices[7], vertices[6]); // top face
    mesh.add_face(vertices[0], vertices[3], vertices[7], vertices[4]); // left face
    mesh.add_face(vertices[1], vertices[2], vertices[6], vertices[5]); // right face
}

int main() {
    // �޽� ��ü ����
    pmp::SurfaceMesh mesh;

    // InitMyMesh �Լ��� ������ü �ʱ�ȭ
    InitMyMesh(mesh);

    // �޽��� output.obj ���Ϸ� ����
    if (pmp::write(mesh, "output.obj")) {
        std::cout << "Mesh successfully written to output.obj" << std::endl;
    }
    else {
        std::cerr << "Error writing mesh to output.obj" << std::endl;
    }

    return 0;
}
