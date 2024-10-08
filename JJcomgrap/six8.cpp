//#include <pmp/surface_mesh.h>
//#include <pmp/io/io.h>
//#include <iostream>
//#include <vector>
//#include <filesystem>
//#include "gl/glut.h"
//
//
//// �޽� ��ü
//pmp::SurfaceMesh mesh;
//
//// ��� ���͸� �����ϴ� vertex normal�� face normal �Ӽ� ��������
//auto vnormals = mesh.vertex_property<pmp::Normal>("v:normal");
//auto fnormals = mesh.face_property<pmp::Normal>("f:normal");
//
//
//// ������ü�� �ʱ�ȭ�ϴ� �Լ�
//void InitMyMesh() {
//    // ������ü�� ũ��
//    const float cubeSize = 2.0f;
//
//    // ������ü ������ �߰�
//    const auto v0 = mesh.add_vertex(pmp::Point(0, 0, 0));
//    const auto v1 = mesh.add_vertex(pmp::Point(cubeSize, 0, 0));
//    const auto v2 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, 0));
//    const auto v3 = mesh.add_vertex(pmp::Point(0, cubeSize, 0));
//    const auto v4 = mesh.add_vertex(pmp::Point(0, 0, cubeSize));
//    const auto v5 = mesh.add_vertex(pmp::Point(cubeSize, 0, cubeSize));
//    const auto v6 = mesh.add_vertex(pmp::Point(cubeSize, cubeSize, cubeSize));
//    const auto v7 = mesh.add_vertex(pmp::Point(0, cubeSize, cubeSize));
//
//    // ������ü�� �� ��(�簢��)�� ���� (6���� ��)
//    mesh.add_quad(v4, v5, v6, v7);
//    mesh.add_quad(v0, v3, v2, v1);
//    mesh.add_quad(v0, v4, v7, v3);
//
//    // �޽� ���� ���
//    std::cout << "vertices: " << mesh.n_vertices() << std::endl;
//    std::cout << "edges: " << mesh.n_edges() << std::endl;
//    std::cout << "faces: " << mesh.n_faces() << std::endl;
//
//}
//
//int main() {
//    // �޽� ��ü ����
//    pmp::SurfaceMesh mesh;
//
//
//    // input.obj ���Ͽ��� �޽� �б�
//    //pmp::read(mesh, "input.obj");
//
//    // �޽��� �ʱ�ȭ�ϱ� ���� InitMyMesh �Լ� ȣ��
//    InitMyMesh(mesh);
//
//    // �޽��� output.obj ���Ϸ� ����
//    pmp::write(mesh, "output.obj");
//
//    //// ������ �� ����Ǿ����� Ȯ��
//    //if (std::filesystem::exists("output.obj")) {
//    //    std::cout << "Mesh successfully written to output.obj" << std::endl;
//    //}
//    //else {
//    //    std::cerr << "Error writing mesh to output.obj" << std::endl;
//    //}
//
//    return 0;
//
//
//}
