#include <pmp/surface_mesh.h>
#include <pmp/io/io.h>
#include <iostream>
#include <vector>
#include <filesystem>

// ������ü�� �ʱ�ȭ�ϴ� �Լ�
void InitMyMesh(pmp::SurfaceMesh& mesh) {
    // ũ�� 2�� ������ü�� ���� ũ��
    float halfSize = 1.0f; // 2�� ��

    // ������ü�� 8�� ���� ����
    std::vector<pmp::Vertex> vertices(8);

    // pmp::Point�� ����Ͽ� ���� �߰�
    vertices[0] = mesh.add_vertex(pmp::Point(-halfSize, -halfSize, -halfSize)); // 0
    vertices[1] = mesh.add_vertex(pmp::Point(halfSize, -halfSize, -halfSize));  // 1
    vertices[2] = mesh.add_vertex(pmp::Point(halfSize, halfSize, -halfSize));   // 2
    vertices[3] = mesh.add_vertex(pmp::Point(-halfSize, halfSize, -halfSize));  // 3
    vertices[4] = mesh.add_vertex(pmp::Point(-halfSize, -halfSize, halfSize));  // 4
    vertices[5] = mesh.add_vertex(pmp::Point(halfSize, -halfSize, halfSize));   // 5
    vertices[6] = mesh.add_vertex(pmp::Point(halfSize, halfSize, halfSize));    // 6
    vertices[7] = mesh.add_vertex(pmp::Point(-halfSize, halfSize, halfSize));   // 7

    // ������ü�� 6�� �� �߰� (�簢�� ���� �� ���� �ﰢ������ ����)
    // back face
    mesh.add_face({ vertices[0], vertices[1], vertices[2] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[0], vertices[2], vertices[3] }); // �� ��° �ﰢ��

    // front face
    mesh.add_face({ vertices[4], vertices[5], vertices[6] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[4], vertices[6], vertices[7] }); // �� ��° �ﰢ��

    // bottom face
    mesh.add_face({ vertices[0], vertices[1], vertices[5] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[0], vertices[5], vertices[4] }); // �� ��° �ﰢ��

    // top face
    mesh.add_face({ vertices[2], vertices[3], vertices[7] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[2], vertices[7], vertices[6] }); // �� ��° �ﰢ��

    // left face
    mesh.add_face({ vertices[0], vertices[3], vertices[7] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[0], vertices[7], vertices[4] }); // �� ��° �ﰢ��

    // right face
    mesh.add_face({ vertices[1], vertices[2], vertices[6] }); // ù ��° �ﰢ��
    mesh.add_face({ vertices[1], vertices[6], vertices[5] }); // �� ��° �ﰢ��
}

int main() {
    // �޽� ��ü ����
    pmp::SurfaceMesh mesh;


    // input.obj ���Ͽ��� �޽� �б�
    pmp::read(mesh, "input.obj");

    // �޽��� �ʱ�ȭ�ϱ� ���� InitMyMesh �Լ� ȣ��
    InitMyMesh(mesh);

    // �޽��� output.obj ���Ϸ� ����
    pmp::write(mesh, "output.obj");

    //// ������ �� ����Ǿ����� Ȯ��
    //if (std::filesystem::exists("output.obj")) {
    //    std::cout << "Mesh successfully written to output.obj" << std::endl;
    //}
    //else {
    //    std::cerr << "Error writing mesh to output.obj" << std::endl;
    //}

    return 0;


}
