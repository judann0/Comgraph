//#include "gl/glut.h"
//#include <pmp/surface_mesh.h>
//#include <pmp/io/io.h>
//#include <iostream>
//
//// ������ ũ��
//int width = 500, height = 500;
//
//// �޽� ��ü
//pmp::SurfaceMesh mesh;
//
//// ��� ���͸� �����ϴ� vertex normal�� face normal �Ӽ� ��������
//auto vnormals = mesh.vertex_property<pmp::Normal>("v:normal");
//auto fnormals = mesh.face_property<pmp::Normal>("f:normal");
//
//
//// InitMyMesh �Լ� ���� (ũ�Ⱑ 2�� ������ü ����, �� ���� �簢������ �߰�)
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
//    //mesh.add_quad(v0, v1, v2, v3); // �Ʒ��� ��
//    //mesh.add_quad(v4, v5, v6, v7); // ���� ��
//    //mesh.add_quad(v0, v4, v7, v3); // ���� ��
//    //mesh.add_quad(v1, v5, v6, v2); // ���� ��
//    //mesh.add_quad(v0, v1, v5, v4); // ���� ��
//    //mesh.add_quad(v3, v7, v6, v2); // ������ ��
//
//    mesh.add_quad(v4, v5, v6, v7);
//    mesh.add_quad(v0, v3, v2, v1);
//    mesh.add_quad(v0, v4, v7, v3);
//
//    // �޽� ���� ���
//    std::cout << "vertices: " << mesh.n_vertices() << std::endl;
//    std::cout << "edges: " << mesh.n_edges() << std::endl;
//    std::cout << "faces: " << mesh.n_faces() << std::endl;
//
//
//}
//
//
//// �޽� �׸��� �Լ�
//void DrawMesh() {
//    glBegin(GL_QUADS); // �簢������ �׸��� ����
//    for (auto f : mesh.faces()) {
//        glNormal3fv(&fnormals[f][0]); // ���� ��� ����
//        for (auto v : mesh.vertices(f)) {
//            glVertex3fv(&mesh.position(v)[0]); // ������ ��ǥ
//        }
//    }
//    glEnd();
//}
//
//
//// ���÷��� �ݹ� �Լ�
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//
//    // �޽� �׸���
//    DrawMesh();
//
//    glutSwapBuffers(); // ���� ��ü
//}
//
//// �ʱ�ȭ �Լ�
//void init() {
//    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ
//    glClearColor(0.0, 0.0, 0.0, 1.0); // ���� ����
//
//    // �޽� �ʱ�ȭ
//    InitMyMesh();
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    // GLUT �ʱ�ȭ
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(width, height);
//    glutCreateWindow("Cube Mesh");
//
//    // �ʱ�ȭ �Լ� ȣ��
//    init();
//
//    // ���÷��� �ݹ� ���
//    glutDisplayFunc(display);
//
//    // ���� ���� ����
//    glutMainLoop();
//
//    return 0;
//}
